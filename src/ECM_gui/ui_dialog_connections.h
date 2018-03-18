/********************************************************************************
** Form generated from reading UI file 'dialog_connections.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_CONNECTIONS_H
#define UI_DIALOG_CONNECTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include "LED.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog_Connections
{
public:
    QGridLayout *gridLayout;
    LED *widget_GalilConnection;
    QLabel *label_GalilConnection;
    QPushButton *pushButton_connectGalil;
    LED *widget_MunkConnection;
    QLabel *label_MunkConnection;
    QPushButton *pushButton_connectMunk;
    LED *widget_RigolConnection;
    QLabel *label_RigolConnection;
    QPushButton *pushButton_connect_Rigol;
    LED *widget_SensorayConnection;
    QLabel *label_SensorayConnection;
    QPushButton *pushButton_connectSensoray;
    LED *widget_WestinghouseConnection;
    QLabel *label_WestinghouseConnection;
    QPushButton *pushButton_connectPump;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Done;

    void setupUi(QDialog *Dialog_Connections)
    {
        if (Dialog_Connections->objectName().isEmpty())
            Dialog_Connections->setObjectName(QStringLiteral("Dialog_Connections"));
        Dialog_Connections->resize(335, 236);
        Dialog_Connections->setStyleSheet(QLatin1String("QMainWindow{\n"
"background-color:#1d1d1d;\n"
"}\n"
"\n"
"QMenuBar{\n"
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
"background-color:qlineargradient"
                        "(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));\n"
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
""
                        "QPushButton:pressed{\n"
"background-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(29, 29, 29, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));\n"
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
        gridLayout = new QGridLayout(Dialog_Connections);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget_GalilConnection = new LED(Dialog_Connections);
        widget_GalilConnection->setObjectName(QStringLiteral("widget_GalilConnection"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_GalilConnection->sizePolicy().hasHeightForWidth());
        widget_GalilConnection->setSizePolicy(sizePolicy);
        widget_GalilConnection->setMinimumSize(QSize(30, 30));
        widget_GalilConnection->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(widget_GalilConnection, 0, 0, 1, 1);

        label_GalilConnection = new QLabel(Dialog_Connections);
        label_GalilConnection->setObjectName(QStringLiteral("label_GalilConnection"));
        sizePolicy.setHeightForWidth(label_GalilConnection->sizePolicy().hasHeightForWidth());
        label_GalilConnection->setSizePolicy(sizePolicy);
        label_GalilConnection->setMinimumSize(QSize(200, 30));
        label_GalilConnection->setMaximumSize(QSize(200, 30));
        QFont font;
        font.setPointSize(10);
        label_GalilConnection->setFont(font);

        gridLayout->addWidget(label_GalilConnection, 0, 1, 1, 2);

        pushButton_connectGalil = new QPushButton(Dialog_Connections);
        pushButton_connectGalil->setObjectName(QStringLiteral("pushButton_connectGalil"));
        pushButton_connectGalil->setMinimumSize(QSize(75, 25));
        pushButton_connectGalil->setMaximumSize(QSize(75, 25));

        gridLayout->addWidget(pushButton_connectGalil, 0, 3, 1, 1);

        widget_MunkConnection = new LED(Dialog_Connections);
        widget_MunkConnection->setObjectName(QStringLiteral("widget_MunkConnection"));
        sizePolicy.setHeightForWidth(widget_MunkConnection->sizePolicy().hasHeightForWidth());
        widget_MunkConnection->setSizePolicy(sizePolicy);
        widget_MunkConnection->setMinimumSize(QSize(30, 30));
        widget_MunkConnection->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(widget_MunkConnection, 1, 0, 1, 1);

        label_MunkConnection = new QLabel(Dialog_Connections);
        label_MunkConnection->setObjectName(QStringLiteral("label_MunkConnection"));
        sizePolicy.setHeightForWidth(label_MunkConnection->sizePolicy().hasHeightForWidth());
        label_MunkConnection->setSizePolicy(sizePolicy);
        label_MunkConnection->setMinimumSize(QSize(200, 30));
        label_MunkConnection->setMaximumSize(QSize(200, 30));
        label_MunkConnection->setFont(font);

        gridLayout->addWidget(label_MunkConnection, 1, 1, 1, 2);

        pushButton_connectMunk = new QPushButton(Dialog_Connections);
        pushButton_connectMunk->setObjectName(QStringLiteral("pushButton_connectMunk"));
        pushButton_connectMunk->setMinimumSize(QSize(75, 25));
        pushButton_connectMunk->setMaximumSize(QSize(75, 25));

        gridLayout->addWidget(pushButton_connectMunk, 1, 3, 1, 1);

        widget_RigolConnection = new LED(Dialog_Connections);
        widget_RigolConnection->setObjectName(QStringLiteral("widget_RigolConnection"));
        sizePolicy.setHeightForWidth(widget_RigolConnection->sizePolicy().hasHeightForWidth());
        widget_RigolConnection->setSizePolicy(sizePolicy);
        widget_RigolConnection->setMinimumSize(QSize(30, 30));
        widget_RigolConnection->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(widget_RigolConnection, 2, 0, 1, 1);

        label_RigolConnection = new QLabel(Dialog_Connections);
        label_RigolConnection->setObjectName(QStringLiteral("label_RigolConnection"));
        sizePolicy.setHeightForWidth(label_RigolConnection->sizePolicy().hasHeightForWidth());
        label_RigolConnection->setSizePolicy(sizePolicy);
        label_RigolConnection->setMinimumSize(QSize(200, 30));
        label_RigolConnection->setMaximumSize(QSize(200, 30));
        label_RigolConnection->setFont(font);

        gridLayout->addWidget(label_RigolConnection, 2, 1, 1, 2);

        pushButton_connect_Rigol = new QPushButton(Dialog_Connections);
        pushButton_connect_Rigol->setObjectName(QStringLiteral("pushButton_connect_Rigol"));
        pushButton_connect_Rigol->setMinimumSize(QSize(75, 25));
        pushButton_connect_Rigol->setMaximumSize(QSize(75, 25));

        gridLayout->addWidget(pushButton_connect_Rigol, 2, 3, 1, 1);

        widget_SensorayConnection = new LED(Dialog_Connections);
        widget_SensorayConnection->setObjectName(QStringLiteral("widget_SensorayConnection"));
        sizePolicy.setHeightForWidth(widget_SensorayConnection->sizePolicy().hasHeightForWidth());
        widget_SensorayConnection->setSizePolicy(sizePolicy);
        widget_SensorayConnection->setMinimumSize(QSize(30, 30));
        widget_SensorayConnection->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(widget_SensorayConnection, 3, 0, 1, 1);

        label_SensorayConnection = new QLabel(Dialog_Connections);
        label_SensorayConnection->setObjectName(QStringLiteral("label_SensorayConnection"));
        sizePolicy.setHeightForWidth(label_SensorayConnection->sizePolicy().hasHeightForWidth());
        label_SensorayConnection->setSizePolicy(sizePolicy);
        label_SensorayConnection->setMinimumSize(QSize(200, 30));
        label_SensorayConnection->setMaximumSize(QSize(200, 30));
        label_SensorayConnection->setFont(font);

        gridLayout->addWidget(label_SensorayConnection, 3, 1, 1, 2);

        pushButton_connectSensoray = new QPushButton(Dialog_Connections);
        pushButton_connectSensoray->setObjectName(QStringLiteral("pushButton_connectSensoray"));
        pushButton_connectSensoray->setMinimumSize(QSize(75, 25));
        pushButton_connectSensoray->setMaximumSize(QSize(75, 25));

        gridLayout->addWidget(pushButton_connectSensoray, 3, 3, 1, 1);

        widget_WestinghouseConnection = new LED(Dialog_Connections);
        widget_WestinghouseConnection->setObjectName(QStringLiteral("widget_WestinghouseConnection"));
        sizePolicy.setHeightForWidth(widget_WestinghouseConnection->sizePolicy().hasHeightForWidth());
        widget_WestinghouseConnection->setSizePolicy(sizePolicy);
        widget_WestinghouseConnection->setMinimumSize(QSize(30, 30));
        widget_WestinghouseConnection->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(widget_WestinghouseConnection, 4, 0, 1, 1);

        label_WestinghouseConnection = new QLabel(Dialog_Connections);
        label_WestinghouseConnection->setObjectName(QStringLiteral("label_WestinghouseConnection"));
        sizePolicy.setHeightForWidth(label_WestinghouseConnection->sizePolicy().hasHeightForWidth());
        label_WestinghouseConnection->setSizePolicy(sizePolicy);
        label_WestinghouseConnection->setMinimumSize(QSize(200, 30));
        label_WestinghouseConnection->setMaximumSize(QSize(200, 30));
        label_WestinghouseConnection->setFont(font);

        gridLayout->addWidget(label_WestinghouseConnection, 4, 1, 1, 2);

        pushButton_connectPump = new QPushButton(Dialog_Connections);
        pushButton_connectPump->setObjectName(QStringLiteral("pushButton_connectPump"));
        pushButton_connectPump->setMinimumSize(QSize(75, 25));
        pushButton_connectPump->setMaximumSize(QSize(75, 25));

        gridLayout->addWidget(pushButton_connectPump, 4, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(142, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 0, 1, 2);

        pushButton_Done = new QPushButton(Dialog_Connections);
        pushButton_Done->setObjectName(QStringLiteral("pushButton_Done"));
        pushButton_Done->setMinimumSize(QSize(100, 30));
        pushButton_Done->setMaximumSize(QSize(100, 30));
        QFont font1;
        font1.setPointSize(12);
        pushButton_Done->setFont(font1);

        gridLayout->addWidget(pushButton_Done, 5, 2, 1, 2);


        retranslateUi(Dialog_Connections);

        QMetaObject::connectSlotsByName(Dialog_Connections);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Connections)
    {
        Dialog_Connections->setWindowTitle(QApplication::translate("Dialog_Connections", "Dialog", nullptr));
        label_GalilConnection->setText(QApplication::translate("Dialog_Connections", "Conncetion Galil Motion Controller", nullptr));
        pushButton_connectGalil->setText(QApplication::translate("Dialog_Connections", "Connect", nullptr));
        label_MunkConnection->setText(QApplication::translate("Dialog_Connections", "Conncetion Munk Power Supply", nullptr));
        pushButton_connectMunk->setText(QApplication::translate("Dialog_Connections", "Connect", nullptr));
        label_RigolConnection->setText(QApplication::translate("Dialog_Connections", "Conncetion Rigol Oscilliscope", nullptr));
        pushButton_connect_Rigol->setText(QApplication::translate("Dialog_Connections", "Connect", nullptr));
        label_SensorayConnection->setText(QApplication::translate("Dialog_Connections", "Conncetion Sensoray ", nullptr));
        pushButton_connectSensoray->setText(QApplication::translate("Dialog_Connections", "Connect", nullptr));
        label_WestinghouseConnection->setText(QApplication::translate("Dialog_Connections", "Conncetion Westinghouse Pump", nullptr));
        pushButton_connectPump->setText(QApplication::translate("Dialog_Connections", "Connect", nullptr));
        pushButton_Done->setText(QApplication::translate("Dialog_Connections", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Connections: public Ui_Dialog_Connections {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_CONNECTIONS_H
