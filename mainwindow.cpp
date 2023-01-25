#include "mainwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QSqlQuery>
#include <QSqlError>
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    // Создаю вертикальный макет для размещения ячеек, среднего поля и кнопок
    QVBoxLayout *layout = new QVBoxLayout(this);

    //Создаю горизонтальный макет для размещения ячеек
    QHBoxLayout *cellsLayout = new QHBoxLayout();

    // Создаю ячейки для ввода данных
    for (int i = 0; i < 5; i++)
    {
        cells[i] = new QLineEdit();
    cellsLayout->addWidget(cells[i]);
    }

    layout->addLayout(cellsLayout);

    // Создаю горизонтальный макет для размещения среднего поля и метки
    QHBoxLayout *averageLayout = new QHBoxLayout();

    QLabel *averageL = new QLabel("Среднее значение чисел:");
    averageLayout->addWidget(averageL);

    averageField = new QLineEdit();
    averageField->setReadOnly(true);
    averageLayout->addWidget(averageField);

    layout->addLayout(averageLayout);

    // Создаю горизонтальный макет для размещения кнопок
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    // Создаю кнопку для вычисления среднего значения
    QPushButton *averageButton = new QPushButton("Вычислить");
    connect(averageButton, &QPushButton::clicked, this, &MainWindow::calculateAverage);
    buttonLayout->addWidget(averageButton);

    // Создаю кнопки для взаимодействия с базой данных
    QPushButton *openButton = new QPushButton("Прочитать сохраненные данные из БД");
    connect(openButton, &QPushButton::clicked, this, &MainWindow::openData);
    buttonLayout->addWidget(openButton);

    QPushButton *saveButton = new QPushButton("Записать данные в БД");
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveData);
    buttonLayout->addWidget(saveButton);

    QPushButton *deleteButton = new QPushButton("Удалить данные из БД");
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::deleteData);
    buttonLayout->addWidget(deleteButton);

    //Создаю кнопку для очистки всех полей
    QPushButton *clearButton = new QPushButton("Очистить все поля");
    connect(clearButton, &QPushButton::clicked, this, &MainWindow::clearFields);
    buttonLayout->addWidget(clearButton);

    layout->addLayout(buttonLayout);

    // Устанавливаю макет на центральном виджете
    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Подключаюсь к базе данных
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    db.open();
}

MainWindow::~MainWindow()
{
}
//Вычисление среднего значения введенных в поля ввода чисел
void MainWindow::calculateAverage()
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
    sum += cells[i]->text().toInt();
    }
    double average = static_cast<double>(sum) / 5;
    averageField->setText(QString::number(average));
    }
//Обращение к БД
void MainWindow::openData()
{
    QSqlQuery query("SELECT cell1, cell2, cell3, cell4, cell5 FROM data");
    while (query.next())
    {
        for (int i = 0; i < 5; i++)
        {
            cells[i]->setText(query.value(i).toString());
        }
    }
}
//Создание и сохранение данных в таблицу БД
void MainWindow::saveData()
{
    QSqlQuery query;
    query.exec("CREATE TABLE data (id INTEGER PRIMARY KEY AUTOINCREMENT, cell1 INTEGER, cell2 INTEGER, cell3 INTEGER, cell4 INTEGER, cell5 INTEGER)");
    query.prepare("INSERT INTO data (cell1, cell2, cell3, cell4, cell5) VALUES (?,?,?,?,?)");
    for (int i = 0; i < 5; i++)
    {
        query.addBindValue(cells[i]->text().toInt());
    }
    if (!query.exec()){
         qDebug() << query.lastError();
    }
    db.commit();
}
//Очистка полей ввода/вывода
void MainWindow::clearFields()
{
    for (int i = 0; i < 5; i++)
    {
        cells[i]->clear();
        averageField->clear();
    }
}
//Удаление данных из таблицы БД
void MainWindow::deleteData()
{
    QSqlQuery query("DELETE FROM data");
    query.exec();
    for (int i = 0; i < 5; i++)
    {
    cells[i]->clear();
    }
}
