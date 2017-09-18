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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "plot_handler.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_GenerateInvalid;
    QPushButton *pushButton_ConfigureSerialPort;
    QPushButton *pushButton_ConnectSerialPort;
    QPushButton *pushButton_GenerateValid;
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
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    graphing::PlotHandler *timeDataGraph;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *timeDataLayout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(446, 345);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_2->addWidget(comboBox, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        pushButton_GenerateInvalid = new QPushButton(centralWidget);
        pushButton_GenerateInvalid->setObjectName(QStringLiteral("pushButton_GenerateInvalid"));

        gridLayout_2->addWidget(pushButton_GenerateInvalid, 0, 2, 1, 1);

        pushButton_ConfigureSerialPort = new QPushButton(centralWidget);
        pushButton_ConfigureSerialPort->setObjectName(QStringLiteral("pushButton_ConfigureSerialPort"));

        gridLayout_2->addWidget(pushButton_ConfigureSerialPort, 1, 0, 1, 1);

        pushButton_ConnectSerialPort = new QPushButton(centralWidget);
        pushButton_ConnectSerialPort->setObjectName(QStringLiteral("pushButton_ConnectSerialPort"));

        gridLayout_2->addWidget(pushButton_ConnectSerialPort, 1, 1, 1, 1);

        pushButton_GenerateValid = new QPushButton(centralWidget);
        pushButton_GenerateValid->setObjectName(QStringLiteral("pushButton_GenerateValid"));

        gridLayout_2->addWidget(pushButton_GenerateValid, 1, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_SendRevI = new QPushButton(centralWidget);
        pushButton_SendRevI->setObjectName(QStringLiteral("pushButton_SendRevI"));

        gridLayout->addWidget(pushButton_SendRevI, 0, 0, 1, 1);

        dataRI = new QLineEdit(centralWidget);
        dataRI->setObjectName(QStringLiteral("dataRI"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dataRI->sizePolicy().hasHeightForWidth());
        dataRI->setSizePolicy(sizePolicy);

        gridLayout->addWidget(dataRI, 0, 1, 1, 1);

        pushButton_SendFI = new QPushButton(centralWidget);
        pushButton_SendFI->setObjectName(QStringLiteral("pushButton_SendFI"));

        gridLayout->addWidget(pushButton_SendFI, 1, 0, 1, 1);

        dataFI = new QLineEdit(centralWidget);
        dataFI->setObjectName(QStringLiteral("dataFI"));
        sizePolicy.setHeightForWidth(dataFI->sizePolicy().hasHeightForWidth());
        dataFI->setSizePolicy(sizePolicy);

        gridLayout->addWidget(dataFI, 1, 1, 2, 1);

        pushButton_SendRV = new QPushButton(centralWidget);
        pushButton_SendRV->setObjectName(QStringLiteral("pushButton_SendRV"));

        gridLayout->addWidget(pushButton_SendRV, 2, 0, 2, 1);

        dataRV = new QLineEdit(centralWidget);
        dataRV->setObjectName(QStringLiteral("dataRV"));
        sizePolicy.setHeightForWidth(dataRV->sizePolicy().hasHeightForWidth());
        dataRV->setSizePolicy(sizePolicy);

        gridLayout->addWidget(dataRV, 3, 1, 1, 1);

        pushButton_SendFV = new QPushButton(centralWidget);
        pushButton_SendFV->setObjectName(QStringLiteral("pushButton_SendFV"));

        gridLayout->addWidget(pushButton_SendFV, 4, 0, 1, 1);

        dataFV = new QLineEdit(centralWidget);
        dataFV->setObjectName(QStringLiteral("dataFV"));
        sizePolicy.setHeightForWidth(dataFV->sizePolicy().hasHeightForWidth());
        dataFV->setSizePolicy(sizePolicy);

        gridLayout->addWidget(dataFV, 4, 1, 1, 1);

        pushButton_SendData = new QPushButton(centralWidget);
        pushButton_SendData->setObjectName(QStringLiteral("pushButton_SendData"));

        gridLayout->addWidget(pushButton_SendData, 5, 0, 1, 1);

        dataFull = new QLineEdit(centralWidget);
        dataFull->setObjectName(QStringLiteral("dataFull"));
        sizePolicy.setHeightForWidth(dataFull->sizePolicy().hasHeightForWidth());
        dataFull->setSizePolicy(sizePolicy);

        gridLayout->addWidget(dataFull, 5, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        timeDataGraph = new graphing::PlotHandler(centralWidget);
        timeDataGraph->setObjectName(QStringLiteral("timeDataGraph"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(timeDataGraph->sizePolicy().hasHeightForWidth());
        timeDataGraph->setSizePolicy(sizePolicy1);
        timeDataGraph->setMinimumSize(QSize(10, 10));

        verticalLayout->addWidget(timeDataGraph);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        timeDataLayout = new QHBoxLayout();
        timeDataLayout->setSpacing(6);
        timeDataLayout->setObjectName(QStringLiteral("timeDataLayout"));

        verticalLayout->addLayout(timeDataLayout);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 446, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton_GenerateInvalid->setText(QApplication::translate("MainWindow", "Gen Invalid", Q_NULLPTR));
        pushButton_ConfigureSerialPort->setText(QApplication::translate("MainWindow", "Configure", Q_NULLPTR));
        pushButton_ConnectSerialPort->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        pushButton_GenerateValid->setText(QApplication::translate("MainWindow", "Gen Valid", Q_NULLPTR));
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
