#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void calculateAverage();
    void openData();
    void saveData();
    void deleteData();
    void clearFields();

private:
    QLineEdit *cells[5];
    QLineEdit *averageField;
    QSqlDatabase db;
};
#endif // MAINWINDOW_H
