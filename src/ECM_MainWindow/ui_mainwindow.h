/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QComboBox *comboBox;
    QPushButton *pushButton_ConnectSerialPort;
    QPushButton *pushButton_SendValid;
    QPushButton *pushButton_SendValid_2;
    QPushButton *pushButton_ConfigureSerialPort;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 10, 121, 22));
        pushButton_ConnectSerialPort = new QPushButton(centralWidget);
        pushButton_ConnectSerialPort->setObjectName(QStringLiteral("pushButton_ConnectSerialPort"));
        pushButton_ConnectSerialPort->setGeometry(QRect(10, 80, 75, 23));
        pushButton_SendValid = new QPushButton(centralWidget);
        pushButton_SendValid->setObjectName(QStringLiteral("pushButton_SendValid"));
        pushButton_SendValid->setGeometry(QRect(100, 60, 75, 23));
        pushButton_SendValid_2 = new QPushButton(centralWidget);
        pushButton_SendValid_2->setObjectName(QStringLiteral("pushButton_SendValid_2"));
        pushButton_SendValid_2->setGeometry(QRect(190, 60, 75, 23));
        pushButton_ConfigureSerialPort = new QPushButton(centralWidget);
        pushButton_ConfigureSerialPort->setObjectName(QStringLiteral("pushButton_ConfigureSerialPort"));
        pushButton_ConfigureSerialPort->setGeometry(QRect(10, 50, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton_ConnectSerialPort->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        pushButton_SendValid->setText(QApplication::translate("MainWindow", "Send Valid", Q_NULLPTR));
        pushButton_SendValid_2->setText(QApplication::translate("MainWindow", "Send Invalid", Q_NULLPTR));
        pushButton_ConfigureSerialPort->setText(QApplication::translate("MainWindow", "Configure", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
