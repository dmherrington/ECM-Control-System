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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
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
    QPushButton *pushButton_GenerateValid;
    QPushButton *pushButton_GenerateInvalid;
    QPushButton *pushButton_ConfigureSerialPort;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_SendRevI;
    QLineEdit *dataRI;
    QPushButton *pushButton_SendFI;
    QLineEdit *dataFI;
    QPushButton *pushButton_SendRV;
    QLineEdit *dataRV;
    QPushButton *pushButton_SendFV;
    QLineEdit *dataFV;
    QPushButton *pushButton_SendData;
    QLineEdit *dataFull;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(595, 349);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 10, 121, 22));
        pushButton_ConnectSerialPort = new QPushButton(centralWidget);
        pushButton_ConnectSerialPort->setObjectName(QStringLiteral("pushButton_ConnectSerialPort"));
        pushButton_ConnectSerialPort->setGeometry(QRect(10, 80, 75, 23));
        pushButton_GenerateValid = new QPushButton(centralWidget);
        pushButton_GenerateValid->setObjectName(QStringLiteral("pushButton_GenerateValid"));
        pushButton_GenerateValid->setGeometry(QRect(100, 60, 75, 23));
        pushButton_GenerateInvalid = new QPushButton(centralWidget);
        pushButton_GenerateInvalid->setObjectName(QStringLiteral("pushButton_GenerateInvalid"));
        pushButton_GenerateInvalid->setGeometry(QRect(190, 60, 75, 23));
        pushButton_ConfigureSerialPort = new QPushButton(centralWidget);
        pushButton_ConfigureSerialPort->setObjectName(QStringLiteral("pushButton_ConfigureSerialPort"));
        pushButton_ConfigureSerialPort->setGeometry(QRect(10, 50, 75, 23));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 140, 216, 144));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_SendRevI = new QPushButton(layoutWidget);
        pushButton_SendRevI->setObjectName(QStringLiteral("pushButton_SendRevI"));

        gridLayout->addWidget(pushButton_SendRevI, 0, 0, 1, 1);

        dataRI = new QLineEdit(layoutWidget);
        dataRI->setObjectName(QStringLiteral("dataRI"));

        gridLayout->addWidget(dataRI, 0, 1, 1, 1);

        pushButton_SendFI = new QPushButton(layoutWidget);
        pushButton_SendFI->setObjectName(QStringLiteral("pushButton_SendFI"));

        gridLayout->addWidget(pushButton_SendFI, 1, 0, 1, 1);

        dataFI = new QLineEdit(layoutWidget);
        dataFI->setObjectName(QStringLiteral("dataFI"));

        gridLayout->addWidget(dataFI, 1, 1, 2, 1);

        pushButton_SendRV = new QPushButton(layoutWidget);
        pushButton_SendRV->setObjectName(QStringLiteral("pushButton_SendRV"));

        gridLayout->addWidget(pushButton_SendRV, 2, 0, 2, 1);

        dataRV = new QLineEdit(layoutWidget);
        dataRV->setObjectName(QStringLiteral("dataRV"));

        gridLayout->addWidget(dataRV, 3, 1, 1, 1);

        pushButton_SendFV = new QPushButton(layoutWidget);
        pushButton_SendFV->setObjectName(QStringLiteral("pushButton_SendFV"));

        gridLayout->addWidget(pushButton_SendFV, 4, 0, 1, 1);

        dataFV = new QLineEdit(layoutWidget);
        dataFV->setObjectName(QStringLiteral("dataFV"));

        gridLayout->addWidget(dataFV, 4, 1, 1, 1);

        pushButton_SendData = new QPushButton(layoutWidget);
        pushButton_SendData->setObjectName(QStringLiteral("pushButton_SendData"));

        gridLayout->addWidget(pushButton_SendData, 5, 0, 1, 1);

        dataFull = new QLineEdit(layoutWidget);
        dataFull->setObjectName(QStringLiteral("dataFull"));

        gridLayout->addWidget(dataFull, 5, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 595, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton_ConnectSerialPort->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        pushButton_GenerateValid->setText(QApplication::translate("MainWindow", "Gen Valid", Q_NULLPTR));
        pushButton_GenerateInvalid->setText(QApplication::translate("MainWindow", "Gen Invalid", Q_NULLPTR));
        pushButton_ConfigureSerialPort->setText(QApplication::translate("MainWindow", "Configure", Q_NULLPTR));
        pushButton_SendRevI->setText(QApplication::translate("MainWindow", "Send RI", Q_NULLPTR));
        pushButton_SendFI->setText(QApplication::translate("MainWindow", "Send FI", Q_NULLPTR));
        pushButton_SendRV->setText(QApplication::translate("MainWindow", "Send RV", Q_NULLPTR));
        pushButton_SendFV->setText(QApplication::translate("MainWindow", "Send FV", Q_NULLPTR));
        pushButton_SendData->setText(QApplication::translate("MainWindow", "Send Data", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
