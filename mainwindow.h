#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calculateButton_clicked();
    void on_saveButton_clicked();
    void on_openButton_clicked();
    void on_clearButton_clicked();
    void on_deleteButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
