/********************************************************************************
** Form generated from reading UI file 'window_device_connections.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_DEVICE_CONNECTIONS_H
#define UI_WINDOW_DEVICE_CONNECTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "LED.h"

QT_BEGIN_NAMESPACE

class Ui_Window_DeviceConnections
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionClose;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    LED *widget_GalilConnection;
    QLabel *label_GalilConnection;
    QPushButton *pushButton_connectGalil;
    QHBoxLayout *horizontalLayout_5;
    LED *widget_WestinghouseConnection;
    QLabel *label_WestinghouseConnection;
    QPushButton *pushButton_connectPump;
    QHBoxLayout *horizontalLayout_2;
    LED *widget_MunkConnection;
    QLabel *label_MunkConnection;
    QPushButton *pushButton_connectMunk;
    QHBoxLayout *horizontalLayout_3;
    LED *widget_RigolConnection;
    QLabel *label_RigolConnection;
    QPushButton *pushButton_connect_Rigol;
    QHBoxLayout *horizontalLayout_4;
    LED *widget_SensorayConnection;
    QLabel *label_SensorayConnection;
    QPushButton *pushButton_connectSensoray;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_ConnectAll;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Close;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_DeviceConnections)
    {
        if (Window_DeviceConnections->objectName().isEmpty())
            Window_DeviceConnections->setObjectName(QStringLiteral("Window_DeviceConnections"));
        Window_DeviceConnections->resize(339, 302);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Window_DeviceConnections->sizePolicy().hasHeightForWidth());
        Window_DeviceConnections->setSizePolicy(sizePolicy);
        Window_DeviceConnections->setMaximumSize(QSize(350, 350));
        Window_DeviceConnections->setStyleSheet(QLatin1String("QMenuBar{\n"
"background-color:#1d1d1d;\n"
"padding:5px;\n"
"	font: 12pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
"QMenuBar::item{\n"
"background-color:#1d1d1d;\n"
"color:#fff;\n"
"padding:5px;\n"
"\n"
"}\n"
"\n"
"QMenu{\n"
"color:#fff;\n"
"padding:0;\n"
"}\n"
"\n"
"QMenu::item:selected{\n"
"color:#fff;\n"
"background-color:#00aba9;\n"
"}\n"
"\n"
"QTableWidget{\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"  selection-background-color: #da532c;\n"
"border:solid;\n"
"border-width:3px;\n"
"border-color:#da532c;\n"
"}\n"
"QHeaderView::section{\n"
"background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"border:none;\n"
"border-top-style:solid;\n"
"border-width:1px;\n"
"border-top-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"color:#fff;\n"
"\n"
"}\n"
"QHeaderView{\n"
"background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, "
                        "217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"\n"
"border:none;\n"
"border-top-style:solid;\n"
"border-width:1px;\n"
"border-top-color:#149ED9;\n"
"color:#fff;\n"
"	font: 75 12pt \"Calibri\";\n"
"}\n"
"\n"
"QTableCornerButton::section{\n"
"border:none;\n"
"background-color:#149ED9;\n"
"}\n"
"\n"
"QListWidget{\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"}\n"
"\n"
"QMenu{\n"
"background-color:#3d3d3d;\n"
"}\n"
"QStatusBar{\n"
"background-color:#7e3878;\n"
"color:#fff;\n"
"}\n"
"\n"
"QPushButton{\n"
"border-style:solid;\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"background-color: rgb(204, 0, 0);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"color:#ccc;\n"
"	background-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(45, 45, 45, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));\n"
"	border-color:#2d89ef;\n"
"border-width:2px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color: qlineargrad"
                        "ient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(29, 29, 29, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));\n"
"}\n"
"\n"
"\n"
"QTabWidget::tab{\n"
"background-color:#3d3d3d;\n"
"}\n"
"\n"
"QLineEdit{\n"
"border-radius:0;\n"
"}\n"
"\n"
"QProgressBar{\n"
"border-radius:0;\n"
"text-align:center;\n"
"color:#fff;\n"
"background-color:transparent;\n"
"border: 2px solid #e3a21a;\n"
"border-radius:7px;\n"
"	font: 75 12pt \"Open Sans\";\n"
"\n"
"}\n"
"\n"
"QProgressBar::chunk{\n"
"background-color:#2d89ef;\n"
"width:20px;\n"
"}"));
        actionOpen = new QAction(Window_DeviceConnections);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(Window_DeviceConnections);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(Window_DeviceConnections);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionClose = new QAction(Window_DeviceConnections);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        centralwidget = new QWidget(Window_DeviceConnections);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget_GalilConnection = new LED(centralwidget);
        widget_GalilConnection->setObjectName(QStringLiteral("widget_GalilConnection"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_GalilConnection->sizePolicy().hasHeightForWidth());
        widget_GalilConnection->setSizePolicy(sizePolicy1);
        widget_GalilConnection->setMinimumSize(QSize(30, 30));
        widget_GalilConnection->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(widget_GalilConnection);

        label_GalilConnection = new QLabel(centralwidget);
        label_GalilConnection->setObjectName(QStringLiteral("label_GalilConnection"));
        sizePolicy1.setHeightForWidth(label_GalilConnection->sizePolicy().hasHeightForWidth());
        label_GalilConnection->setSizePolicy(sizePolicy1);
        label_GalilConnection->setMinimumSize(QSize(200, 30));
        label_GalilConnection->setMaximumSize(QSize(200, 30));
        QFont font;
        font.setPointSize(10);
        label_GalilConnection->setFont(font);

        horizontalLayout->addWidget(label_GalilConnection);

        pushButton_connectGalil = new QPushButton(centralwidget);
        pushButton_connectGalil->setObjectName(QStringLiteral("pushButton_connectGalil"));
        pushButton_connectGalil->setMinimumSize(QSize(75, 25));
        pushButton_connectGalil->setMaximumSize(QSize(75, 25));

        horizontalLayout->addWidget(pushButton_connectGalil);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        widget_WestinghouseConnection = new LED(centralwidget);
        widget_WestinghouseConnection->setObjectName(QStringLiteral("widget_WestinghouseConnection"));
        sizePolicy1.setHeightForWidth(widget_WestinghouseConnection->sizePolicy().hasHeightForWidth());
        widget_WestinghouseConnection->setSizePolicy(sizePolicy1);
        widget_WestinghouseConnection->setMinimumSize(QSize(30, 30));
        widget_WestinghouseConnection->setMaximumSize(QSize(30, 30));

        horizontalLayout_5->addWidget(widget_WestinghouseConnection);

        label_WestinghouseConnection = new QLabel(centralwidget);
        label_WestinghouseConnection->setObjectName(QStringLiteral("label_WestinghouseConnection"));
        sizePolicy1.setHeightForWidth(label_WestinghouseConnection->sizePolicy().hasHeightForWidth());
        label_WestinghouseConnection->setSizePolicy(sizePolicy1);
        label_WestinghouseConnection->setMinimumSize(QSize(200, 30));
        label_WestinghouseConnection->setMaximumSize(QSize(200, 30));
        label_WestinghouseConnection->setFont(font);

        horizontalLayout_5->addWidget(label_WestinghouseConnection);

        pushButton_connectPump = new QPushButton(centralwidget);
        pushButton_connectPump->setObjectName(QStringLiteral("pushButton_connectPump"));
        pushButton_connectPump->setMinimumSize(QSize(75, 25));
        pushButton_connectPump->setMaximumSize(QSize(75, 25));

        horizontalLayout_5->addWidget(pushButton_connectPump);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widget_MunkConnection = new LED(centralwidget);
        widget_MunkConnection->setObjectName(QStringLiteral("widget_MunkConnection"));
        sizePolicy1.setHeightForWidth(widget_MunkConnection->sizePolicy().hasHeightForWidth());
        widget_MunkConnection->setSizePolicy(sizePolicy1);
        widget_MunkConnection->setMinimumSize(QSize(30, 30));
        widget_MunkConnection->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(widget_MunkConnection);

        label_MunkConnection = new QLabel(centralwidget);
        label_MunkConnection->setObjectName(QStringLiteral("label_MunkConnection"));
        sizePolicy1.setHeightForWidth(label_MunkConnection->sizePolicy().hasHeightForWidth());
        label_MunkConnection->setSizePolicy(sizePolicy1);
        label_MunkConnection->setMinimumSize(QSize(200, 30));
        label_MunkConnection->setMaximumSize(QSize(200, 30));
        label_MunkConnection->setFont(font);

        horizontalLayout_2->addWidget(label_MunkConnection);

        pushButton_connectMunk = new QPushButton(centralwidget);
        pushButton_connectMunk->setObjectName(QStringLiteral("pushButton_connectMunk"));
        pushButton_connectMunk->setMinimumSize(QSize(75, 25));
        pushButton_connectMunk->setMaximumSize(QSize(75, 25));

        horizontalLayout_2->addWidget(pushButton_connectMunk);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        widget_RigolConnection = new LED(centralwidget);
        widget_RigolConnection->setObjectName(QStringLiteral("widget_RigolConnection"));
        sizePolicy1.setHeightForWidth(widget_RigolConnection->sizePolicy().hasHeightForWidth());
        widget_RigolConnection->setSizePolicy(sizePolicy1);
        widget_RigolConnection->setMinimumSize(QSize(30, 30));
        widget_RigolConnection->setMaximumSize(QSize(30, 30));

        horizontalLayout_3->addWidget(widget_RigolConnection);

        label_RigolConnection = new QLabel(centralwidget);
        label_RigolConnection->setObjectName(QStringLiteral("label_RigolConnection"));
        sizePolicy1.setHeightForWidth(label_RigolConnection->sizePolicy().hasHeightForWidth());
        label_RigolConnection->setSizePolicy(sizePolicy1);
        label_RigolConnection->setMinimumSize(QSize(200, 30));
        label_RigolConnection->setMaximumSize(QSize(200, 30));
        label_RigolConnection->setFont(font);

        horizontalLayout_3->addWidget(label_RigolConnection);

        pushButton_connect_Rigol = new QPushButton(centralwidget);
        pushButton_connect_Rigol->setObjectName(QStringLiteral("pushButton_connect_Rigol"));
        pushButton_connect_Rigol->setMinimumSize(QSize(75, 25));
        pushButton_connect_Rigol->setMaximumSize(QSize(75, 25));

        horizontalLayout_3->addWidget(pushButton_connect_Rigol);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        widget_SensorayConnection = new LED(centralwidget);
        widget_SensorayConnection->setObjectName(QStringLiteral("widget_SensorayConnection"));
        sizePolicy1.setHeightForWidth(widget_SensorayConnection->sizePolicy().hasHeightForWidth());
        widget_SensorayConnection->setSizePolicy(sizePolicy1);
        widget_SensorayConnection->setMinimumSize(QSize(30, 30));
        widget_SensorayConnection->setMaximumSize(QSize(30, 30));

        horizontalLayout_4->addWidget(widget_SensorayConnection);

        label_SensorayConnection = new QLabel(centralwidget);
        label_SensorayConnection->setObjectName(QStringLiteral("label_SensorayConnection"));
        sizePolicy1.setHeightForWidth(label_SensorayConnection->sizePolicy().hasHeightForWidth());
        label_SensorayConnection->setSizePolicy(sizePolicy1);
        label_SensorayConnection->setMinimumSize(QSize(200, 30));
        label_SensorayConnection->setMaximumSize(QSize(200, 30));
        label_SensorayConnection->setFont(font);

        horizontalLayout_4->addWidget(label_SensorayConnection);

        pushButton_connectSensoray = new QPushButton(centralwidget);
        pushButton_connectSensoray->setObjectName(QStringLiteral("pushButton_connectSensoray"));
        pushButton_connectSensoray->setMinimumSize(QSize(75, 25));
        pushButton_connectSensoray->setMaximumSize(QSize(75, 25));

        horizontalLayout_4->addWidget(pushButton_connectSensoray);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButton_ConnectAll = new QPushButton(centralwidget);
        pushButton_ConnectAll->setObjectName(QStringLiteral("pushButton_ConnectAll"));
        pushButton_ConnectAll->setMinimumSize(QSize(120, 30));
        pushButton_ConnectAll->setMaximumSize(QSize(100, 30));
        QFont font1;
        font1.setPointSize(12);
        pushButton_ConnectAll->setFont(font1);

        horizontalLayout_6->addWidget(pushButton_ConnectAll);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        pushButton_Close = new QPushButton(centralwidget);
        pushButton_Close->setObjectName(QStringLiteral("pushButton_Close"));
        pushButton_Close->setMinimumSize(QSize(100, 30));
        pushButton_Close->setMaximumSize(QSize(100, 30));
        pushButton_Close->setFont(font1);

        horizontalLayout_6->addWidget(pushButton_Close);


        gridLayout->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        Window_DeviceConnections->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_DeviceConnections);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 339, 40));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        Window_DeviceConnections->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_DeviceConnections);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Window_DeviceConnections->setStatusBar(statusbar);
        QWidget::setTabOrder(pushButton_ConnectAll, pushButton_connectGalil);
        QWidget::setTabOrder(pushButton_connectGalil, pushButton_connectPump);
        QWidget::setTabOrder(pushButton_connectPump, pushButton_connectMunk);
        QWidget::setTabOrder(pushButton_connectMunk, pushButton_connect_Rigol);
        QWidget::setTabOrder(pushButton_connect_Rigol, pushButton_connectSensoray);
        QWidget::setTabOrder(pushButton_connectSensoray, pushButton_Close);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);

        retranslateUi(Window_DeviceConnections);

        QMetaObject::connectSlotsByName(Window_DeviceConnections);
    } // setupUi

    void retranslateUi(QMainWindow *Window_DeviceConnections)
    {
        Window_DeviceConnections->setWindowTitle(QApplication::translate("Window_DeviceConnections", "MainWindow", nullptr));
        actionOpen->setText(QApplication::translate("Window_DeviceConnections", "Open", nullptr));
        actionSave->setText(QApplication::translate("Window_DeviceConnections", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("Window_DeviceConnections", "Save As", nullptr));
        actionClose->setText(QApplication::translate("Window_DeviceConnections", "Close", nullptr));
        label_GalilConnection->setText(QApplication::translate("Window_DeviceConnections", "Connection Galil Motion Controller", nullptr));
        pushButton_connectGalil->setText(QApplication::translate("Window_DeviceConnections", "Connect", nullptr));
        label_WestinghouseConnection->setText(QApplication::translate("Window_DeviceConnections", "Connection Westinghouse Pump", nullptr));
        pushButton_connectPump->setText(QApplication::translate("Window_DeviceConnections", "Connect", nullptr));
        label_MunkConnection->setText(QApplication::translate("Window_DeviceConnections", "Connection Munk Power Supply", nullptr));
        pushButton_connectMunk->setText(QApplication::translate("Window_DeviceConnections", "Connect", nullptr));
        label_RigolConnection->setText(QApplication::translate("Window_DeviceConnections", "Connection Rigol Oscilliscope", nullptr));
        pushButton_connect_Rigol->setText(QApplication::translate("Window_DeviceConnections", "Connect", nullptr));
        label_SensorayConnection->setText(QApplication::translate("Window_DeviceConnections", "Connection Sensoray ", nullptr));
        pushButton_connectSensoray->setText(QApplication::translate("Window_DeviceConnections", "Connect", nullptr));
        pushButton_ConnectAll->setText(QApplication::translate("Window_DeviceConnections", "CONNECT ALL", nullptr));
        pushButton_Close->setText(QApplication::translate("Window_DeviceConnections", "CLOSE", nullptr));
        menuFile->setTitle(QApplication::translate("Window_DeviceConnections", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("Window_DeviceConnections", "Edit", nullptr));
        menuTools->setTitle(QApplication::translate("Window_DeviceConnections", "Tools", nullptr));
        menuHelp->setTitle(QApplication::translate("Window_DeviceConnections", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_DeviceConnections: public Ui_Window_DeviceConnections {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_DEVICE_CONNECTIONS_H
