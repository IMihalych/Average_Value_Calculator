/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QLineEdit *resultLineEdit;
    QLabel *labelResult;
    QPushButton *calculateButton;
    QPushButton *clearButton;
    QPushButton *saveButton;
    QPushButton *deleteButton;
    QPushButton *openButton;
    QSplitter *splitter;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
    QLineEdit *lineEdit4;
    QLineEdit *lineEdit5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(756, 725);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(75);
        sizePolicy.setVerticalStretch(35);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(756, 362));
        MainWindow->setMaximumSize(QSize(2024, 2048));
        MainWindow->setSizeIncrement(QSize(758, 362));
        MainWindow->setBaseSize(QSize(752, 362));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(17, 141, 711, 441));
        tableView->setMinimumSize(QSize(711, 192));
        resultLineEdit = new QLineEdit(centralwidget);
        resultLineEdit->setObjectName("resultLineEdit");
        resultLineEdit->setGeometry(QRect(156, 64, 151, 22));
        labelResult = new QLabel(centralwidget);
        labelResult->setObjectName("labelResult");
        labelResult->setGeometry(QRect(17, 64, 134, 16));
        calculateButton = new QPushButton(centralwidget);
        calculateButton->setObjectName("calculateButton");
        calculateButton->setGeometry(QRect(18, 111, 75, 24));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(261, 111, 75, 24));
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(99, 111, 75, 24));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(342, 111, 75, 24));
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName("openButton");
        openButton->setGeometry(QRect(180, 111, 75, 24));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(20, 20, 711, 22));
        splitter->setOrientation(Qt::Horizontal);
        lineEdit1 = new QLineEdit(splitter);
        lineEdit1->setObjectName("lineEdit1");
        lineEdit1->setMaxLength(82767);
        lineEdit1->setCursorPosition(0);
        splitter->addWidget(lineEdit1);
        lineEdit2 = new QLineEdit(splitter);
        lineEdit2->setObjectName("lineEdit2");
        lineEdit2->setMaxLength(82767);
        splitter->addWidget(lineEdit2);
        lineEdit3 = new QLineEdit(splitter);
        lineEdit3->setObjectName("lineEdit3");
        lineEdit3->setMaxLength(82767);
        splitter->addWidget(lineEdit3);
        lineEdit4 = new QLineEdit(splitter);
        lineEdit4->setObjectName("lineEdit4");
        lineEdit4->setMaxLength(82767);
        splitter->addWidget(lineEdit4);
        lineEdit5 = new QLineEdit(splitter);
        lineEdit5->setObjectName("lineEdit5");
        lineEdit5->setMaxLength(82767);
        splitter->addWidget(lineEdit5);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 756, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200 \321\201\321\200\320\265\320\264\320\275\320\265\320\263\320\276 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", nullptr));
        labelResult->setText(QCoreApplication::translate("MainWindow", " \320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \320\262\321\213\321\207\320\270\321\201\320\273\320\265\320\275\320\270\320\271 :", nullptr));
        calculateButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        lineEdit1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
