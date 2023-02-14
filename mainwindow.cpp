#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("data.db");
            if (!db.open()) {
                QMessageBox::critical(this, "Error", "Failed to connect to the database");
                    return;
            }
// Создание таблицы БД
            QSqlQuery query(db);
            query.exec("CREATE TABLE IF NOT EXISTS data (id INTEGER PRIMARY KEY AUTOINCREMENT, num1 INTEGER, num2 INTEGER, num3 INTEGER, num4 INTEGER, num5 INTEGER, average INTEGER)");

            model = new QSqlTableModel(this, db);
            model->setTable("data");
            model->select();

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculateButton_clicked()
{
            bool ok1, ok2, ok3, ok4, ok5;
            double num1 = ui->lineEdit1->text().toDouble(&ok1);
            double num2 = ui->lineEdit2->text().toDouble(&ok2);
            double num3 = ui->lineEdit3->text().toDouble(&ok3);
            double num4 = ui->lineEdit4->text().toDouble(&ok4);
            double num5 = ui->lineEdit5->text().toDouble(&ok5);

            if (!ok1 || !ok2 || !ok3 || !ok4 || !ok5) {
                   QMessageBox::warning(this, "Внимание!", "Введены некорректные значения или не все поля заполнены!");
                   return;
               }
               double average = (num1 + num2 + num3 + num4 + num5) / 5;
               ui->resultLineEdit->setText(QString::number(average));
}

void MainWindow::on_saveButton_clicked()
{
    QSqlRecord record = model->record();
    record.setValue("num1", ui->lineEdit1->text().toDouble());
    record.setValue("num2", ui->lineEdit2->text().toDouble());
    record.setValue("num3", ui->lineEdit3->text().toDouble());
    record.setValue("num4", ui->lineEdit4->text().toDouble());
    record.setValue("num5", ui->lineEdit5->text().toDouble());
    record.setValue("average", ui->resultLineEdit->text().toDouble());

    model->insertRecord(-1, record);
    model->submitAll();

        QTimer::singleShot(100, this, [this]{
            model->select();
            ui->tableView->reset();
          //Можно и так:
            /*    model->insertRecord(-1, record);
                  model->submitAll();
                  model->select();*/
       });
}

void MainWindow::on_openButton_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    if (selectedRows.empty()) {
        QMessageBox::warning(this, "Внимание!", "Не выделена ни одна строка!");
        return;
    }
    if (selectedRows.size() > 1) {
        QMessageBox::warning(this, "Внимание!", "Можно выбрать только одну строку!");
        return;
    }

    double row = selectedRows.at(0).row();
    double num1 = model->data(model->index(row, 1)).toDouble();
    double num2 = model->data(model->index(row, 2)).toDouble();
    double num3 = model->data(model->index(row, 3)).toDouble();
    double num4 = model->data(model->index(row, 4)).toDouble();
    double num5 = model->data(model->index(row, 5)).toDouble();
    double average = model->data(model->index(row, 6)).toDouble();

    ui->lineEdit1->setText(QString::number(num1));
    ui->lineEdit2->setText(QString::number(num2));
    ui->lineEdit3->setText(QString::number(num3));
    ui->lineEdit4->setText(QString::number(num4));
    ui->lineEdit5->setText(QString::number(num5));
    ui->resultLineEdit->setText(QString::number(average));
}

void MainWindow::on_clearButton_clicked()
{
    ui->lineEdit1->clear();
    ui->lineEdit2->clear();
    ui->lineEdit3->clear();
    ui->lineEdit4->clear();
    ui->lineEdit5->clear();
    ui->resultLineEdit->clear();
}

void MainWindow::on_deleteButton_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    if (selectedIndexes.empty()) {
        QMessageBox::warning(this, "Предупреждение!", "Пожалуйста, выберите строку/строки из таблицы для удаления");
        return;
    }

    int ret = QMessageBox::warning(this, "Удаление", "Вы уверены, что хотите удалить выбранные строки?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        for (int i = selectedIndexes.count() - 1; i >= 0; i--) {
            int row = selectedIndexes.at(i).row();
            model->removeRow(row);
        }
        model->submitAll();
        model->select();
    }
}
