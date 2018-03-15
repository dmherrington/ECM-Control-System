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
#include <QtWidgets/QFormLayout>
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
    QFormLayout *formLayout;
    LED *widget_GalilConnection;
    QLabel *label_GalilConnection;
    LED *widget_MunkConnection;
    QLabel *label_MunkConnection;
    LED *widget_RigolConnection;
    QLabel *label_RigolConnection;
    LED *widget_SensorayConnection;
    QLabel *label_SensorayConnection;
    LED *widget_WestinhouseConnection;
    QLabel *label_WestinghouseConnection;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog_Connections)
    {
        if (Dialog_Connections->objectName().isEmpty())
            Dialog_Connections->setObjectName(QStringLiteral("Dialog_Connections"));
        Dialog_Connections->resize(269, 236);
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
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        widget_GalilConnection = new LED(Dialog_Connections);
        widget_GalilConnection->setObjectName(QStringLiteral("widget_GalilConnection"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_GalilConnection->sizePolicy().hasHeightForWidth());
        widget_GalilConnection->setSizePolicy(sizePolicy);
        widget_GalilConnection->setMinimumSize(QSize(30, 30));
        widget_GalilConnection->setMaximumSize(QSize(30, 30));

        formLayout->setWidget(0, QFormLayout::LabelRole, widget_GalilConnection);

        label_GalilConnection = new QLabel(Dialog_Connections);
        label_GalilConnection->setObjectName(QStringLiteral("label_GalilConnection"));
        sizePolicy.setHeightForWidth(label_GalilConnection->sizePolicy().hasHeightForWidth());
        label_GalilConnection->setSizePolicy(sizePolicy);
        label_GalilConnection->setMinimumSize(QSize(200, 30));
        label_GalilConnection->setMaximumSize(QSize(200, 30));
        QFont font;
        font.setPointSize(10);
        label_GalilConnection->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, label_GalilConnection);

        widget_MunkConnection = new LED(Dialog_Connections);
        widget_MunkConnection->setObjectName(QStringLiteral("widget_MunkConnection"));
        sizePolicy.setHeightForWidth(widget_MunkConnection->sizePolicy().hasHeightForWidth());
        widget_MunkConnection->setSizePolicy(sizePolicy);
        widget_MunkConnection->setMinimumSize(QSize(30, 30));
        widget_MunkConnection->setMaximumSize(QSize(30, 30));

        formLayout->setWidget(1, QFormLayout::LabelRole, widget_MunkConnection);

        label_MunkConnection = new QLabel(Dialog_Connections);
        label_MunkConnection->setObjectName(QStringLiteral("label_MunkConnection"));
        sizePolicy.setHeightForWidth(label_MunkConnection->sizePolicy().hasHeightForWidth());
        label_MunkConnection->setSizePolicy(sizePolicy);
        label_MunkConnection->setMinimumSize(QSize(200, 30));
        label_MunkConnection->setMaximumSize(QSize(200, 30));
        label_MunkConnection->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, label_MunkConnection);

        widget_RigolConnection = new LED(Dialog_Connections);
        widget_RigolConnection->setObjectName(QStringLiteral("widget_RigolConnection"));
        sizePolicy.setHeightForWidth(widget_RigolConnection->sizePolicy().hasHeightForWidth());
        widget_RigolConnection->setSizePolicy(sizePolicy);
        widget_RigolConnection->setMinimumSize(QSize(30, 30));
        widget_RigolConnection->setMaximumSize(QSize(30, 30));

        formLayout->setWidget(2, QFormLayout::LabelRole, widget_RigolConnection);

        label_RigolConnection = new QLabel(Dialog_Connections);
        label_RigolConnection->setObjectName(QStringLiteral("label_RigolConnection"));
        sizePolicy.setHeightForWidth(label_RigolConnection->sizePolicy().hasHeightForWidth());
        label_RigolConnection->setSizePolicy(sizePolicy);
        label_RigolConnection->setMinimumSize(QSize(200, 30));
        label_RigolConnection->setMaximumSize(QSize(200, 30));
        label_RigolConnection->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, label_RigolConnection);

        widget_SensorayConnection = new LED(Dialog_Connections);
        widget_SensorayConnection->setObjectName(QStringLiteral("widget_SensorayConnection"));
        sizePolicy.setHeightForWidth(widget_SensorayConnection->sizePolicy().hasHeightForWidth());
        widget_SensorayConnection->setSizePolicy(sizePolicy);
        widget_SensorayConnection->setMinimumSize(QSize(30, 30));
        widget_SensorayConnection->setMaximumSize(QSize(30, 30));

        formLayout->setWidget(3, QFormLayout::LabelRole, widget_SensorayConnection);

        label_SensorayConnection = new QLabel(Dialog_Connections);
        label_SensorayConnection->setObjectName(QStringLiteral("label_SensorayConnection"));
        sizePolicy.setHeightForWidth(label_SensorayConnection->sizePolicy().hasHeightForWidth());
        label_SensorayConnection->setSizePolicy(sizePolicy);
        label_SensorayConnection->setMinimumSize(QSize(200, 30));
        label_SensorayConnection->setMaximumSize(QSize(200, 30));
        label_SensorayConnection->setFont(font);

        formLayout->setWidget(3, QFormLayout::FieldRole, label_SensorayConnection);

        widget_WestinhouseConnection = new LED(Dialog_Connections);
        widget_WestinhouseConnection->setObjectName(QStringLiteral("widget_WestinhouseConnection"));
        sizePolicy.setHeightForWidth(widget_WestinhouseConnection->sizePolicy().hasHeightForWidth());
        widget_WestinhouseConnection->setSizePolicy(sizePolicy);
        widget_WestinhouseConnection->setMinimumSize(QSize(30, 30));
        widget_WestinhouseConnection->setMaximumSize(QSize(30, 30));

        formLayout->setWidget(4, QFormLayout::LabelRole, widget_WestinhouseConnection);

        label_WestinghouseConnection = new QLabel(Dialog_Connections);
        label_WestinghouseConnection->setObjectName(QStringLiteral("label_WestinghouseConnection"));
        sizePolicy.setHeightForWidth(label_WestinghouseConnection->sizePolicy().hasHeightForWidth());
        label_WestinghouseConnection->setSizePolicy(sizePolicy);
        label_WestinghouseConnection->setMinimumSize(QSize(200, 30));
        label_WestinghouseConnection->setMaximumSize(QSize(200, 30));
        label_WestinghouseConnection->setFont(font);

        formLayout->setWidget(4, QFormLayout::FieldRole, label_WestinghouseConnection);


        gridLayout->addLayout(formLayout, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(142, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton = new QPushButton(Dialog_Connections);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(100, 30));
        pushButton->setMaximumSize(QSize(100, 30));
        QFont font1;
        font1.setPointSize(12);
        pushButton->setFont(font1);

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);


        retranslateUi(Dialog_Connections);

        QMetaObject::connectSlotsByName(Dialog_Connections);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Connections)
    {
        Dialog_Connections->setWindowTitle(QApplication::translate("Dialog_Connections", "Dialog", nullptr));
        label_GalilConnection->setText(QApplication::translate("Dialog_Connections", "Conncetion Galil Motion Controller", nullptr));
        label_MunkConnection->setText(QApplication::translate("Dialog_Connections", "Conncetion Munk Power Supply", nullptr));
        label_RigolConnection->setText(QApplication::translate("Dialog_Connections", "Conncetion Rigol Oscilliscope", nullptr));
        label_SensorayConnection->setText(QApplication::translate("Dialog_Connections", "Conncetion Sensoray ", nullptr));
        label_WestinghouseConnection->setText(QApplication::translate("Dialog_Connections", "Conncetion Westinghouse Pump", nullptr));
        pushButton->setText(QApplication::translate("Dialog_Connections", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Connections: public Ui_Dialog_Connections {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_CONNECTIONS_H
