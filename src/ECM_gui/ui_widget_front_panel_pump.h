/********************************************************************************
** Form generated from reading UI file 'widget_front_panel_pump.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_FRONT_PANEL_PUMP_H
#define UI_WIDGET_FRONT_PANEL_PUMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "LED.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetFrontPanel_Pump
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_8;
    QLabel *label_Running_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    LED *widget_PumpRunning;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_7;
    QLabel *label_Running;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    LED *widget_PumpInitialized;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_PumpRunning;
    QSpacerItem *horizontalSpacer_10;
    QGridLayout *gridLayout_2;
    QLabel *label_conductivity;
    QLCDNumber *lcdNumber_pH;
    QLCDNumber *lcdNumber_Conductivity;
    QLabel *label_ph;
    QGridLayout *gridLayout;
    QLabel *label_delayTim;
    QDoubleSpinBox *doubleSpinBox_delayTime;
    QLabel *label_Flowrate;
    QDoubleSpinBox *doubleSpinBox_flowRate;

    void setupUi(QWidget *WidgetFrontPanel_Pump)
    {
        if (WidgetFrontPanel_Pump->objectName().isEmpty())
            WidgetFrontPanel_Pump->setObjectName(QStringLiteral("WidgetFrontPanel_Pump"));
        WidgetFrontPanel_Pump->resize(375, 180);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetFrontPanel_Pump->sizePolicy().hasHeightForWidth());
        WidgetFrontPanel_Pump->setSizePolicy(sizePolicy);
        WidgetFrontPanel_Pump->setMinimumSize(QSize(375, 180));
        WidgetFrontPanel_Pump->setMaximumSize(QSize(375, 180));
        gridLayout_3 = new QGridLayout(WidgetFrontPanel_Pump);
        gridLayout_3->setSpacing(2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(3, 3, 3, 3);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(1, 1, 1, 1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setHorizontalSpacing(1);
        label_Running_2 = new QLabel(WidgetFrontPanel_Pump);
        label_Running_2->setObjectName(QStringLiteral("label_Running_2"));
        sizePolicy.setHeightForWidth(label_Running_2->sizePolicy().hasHeightForWidth());
        label_Running_2->setSizePolicy(sizePolicy);
        label_Running_2->setMinimumSize(QSize(65, 18));
        label_Running_2->setMaximumSize(QSize(65, 18));
        QFont font;
        font.setPointSize(10);
        label_Running_2->setFont(font);
        label_Running_2->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_Running_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(1, 1, 1, 1);
        horizontalSpacer_6 = new QSpacerItem(1, 50, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        widget_PumpRunning = new LED(WidgetFrontPanel_Pump);
        widget_PumpRunning->setObjectName(QStringLiteral("widget_PumpRunning"));
        sizePolicy.setHeightForWidth(widget_PumpRunning->sizePolicy().hasHeightForWidth());
        widget_PumpRunning->setSizePolicy(sizePolicy);
        widget_PumpRunning->setMinimumSize(QSize(40, 40));
        widget_PumpRunning->setMaximumSize(QSize(40, 40));

        horizontalLayout_3->addWidget(widget_PumpRunning);

        horizontalSpacer_7 = new QSpacerItem(1, 50, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        gridLayout_8->addLayout(horizontalLayout_3, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_8);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(1);
        label_Running = new QLabel(WidgetFrontPanel_Pump);
        label_Running->setObjectName(QStringLiteral("label_Running"));
        sizePolicy.setHeightForWidth(label_Running->sizePolicy().hasHeightForWidth());
        label_Running->setSizePolicy(sizePolicy);
        label_Running->setMinimumSize(QSize(65, 18));
        label_Running->setMaximumSize(QSize(65, 18));
        label_Running->setFont(font);
        label_Running->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_Running, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(1, 1, 1, 1);
        horizontalSpacer_5 = new QSpacerItem(1, 50, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        widget_PumpInitialized = new LED(WidgetFrontPanel_Pump);
        widget_PumpInitialized->setObjectName(QStringLiteral("widget_PumpInitialized"));
        sizePolicy.setHeightForWidth(widget_PumpInitialized->sizePolicy().hasHeightForWidth());
        widget_PumpInitialized->setSizePolicy(sizePolicy);
        widget_PumpInitialized->setMinimumSize(QSize(40, 40));
        widget_PumpInitialized->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(widget_PumpInitialized);

        horizontalSpacer_4 = new QSpacerItem(1, 50, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout_7->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_7);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_9 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        pushButton_PumpRunning = new QPushButton(WidgetFrontPanel_Pump);
        pushButton_PumpRunning->setObjectName(QStringLiteral("pushButton_PumpRunning"));
        sizePolicy.setHeightForWidth(pushButton_PumpRunning->sizePolicy().hasHeightForWidth());
        pushButton_PumpRunning->setSizePolicy(sizePolicy);
        pushButton_PumpRunning->setMinimumSize(QSize(100, 75));
        pushButton_PumpRunning->setMaximumSize(QSize(16777215, 75));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(75);
        pushButton_PumpRunning->setFont(font1);
        pushButton_PumpRunning->setStyleSheet(QLatin1String("QMainWindow{\n"
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

        horizontalLayout_4->addWidget(pushButton_PumpRunning);

        horizontalSpacer_10 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        gridLayout_3->addLayout(horizontalLayout_5, 0, 0, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_conductivity = new QLabel(WidgetFrontPanel_Pump);
        label_conductivity->setObjectName(QStringLiteral("label_conductivity"));
        sizePolicy.setHeightForWidth(label_conductivity->sizePolicy().hasHeightForWidth());
        label_conductivity->setSizePolicy(sizePolicy);
        label_conductivity->setMinimumSize(QSize(80, 20));
        label_conductivity->setMaximumSize(QSize(80, 20));
        label_conductivity->setFont(font);

        gridLayout_2->addWidget(label_conductivity, 1, 0, 1, 1);

        lcdNumber_pH = new QLCDNumber(WidgetFrontPanel_Pump);
        lcdNumber_pH->setObjectName(QStringLiteral("lcdNumber_pH"));
        lcdNumber_pH->setMinimumSize(QSize(80, 30));
        lcdNumber_pH->setMaximumSize(QSize(80, 30));
        lcdNumber_pH->setDigitCount(4);

        gridLayout_2->addWidget(lcdNumber_pH, 0, 1, 1, 1);

        lcdNumber_Conductivity = new QLCDNumber(WidgetFrontPanel_Pump);
        lcdNumber_Conductivity->setObjectName(QStringLiteral("lcdNumber_Conductivity"));
        lcdNumber_Conductivity->setMinimumSize(QSize(80, 30));
        lcdNumber_Conductivity->setMaximumSize(QSize(80, 30));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        lcdNumber_Conductivity->setFont(font2);
        lcdNumber_Conductivity->setLineWidth(1);
        lcdNumber_Conductivity->setMidLineWidth(0);
        lcdNumber_Conductivity->setDigitCount(4);

        gridLayout_2->addWidget(lcdNumber_Conductivity, 1, 1, 1, 1);

        label_ph = new QLabel(WidgetFrontPanel_Pump);
        label_ph->setObjectName(QStringLiteral("label_ph"));
        sizePolicy.setHeightForWidth(label_ph->sizePolicy().hasHeightForWidth());
        label_ph->setSizePolicy(sizePolicy);
        label_ph->setMinimumSize(QSize(80, 20));
        label_ph->setMaximumSize(QSize(80, 20));
        label_ph->setFont(font);

        gridLayout_2->addWidget(label_ph, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_delayTim = new QLabel(WidgetFrontPanel_Pump);
        label_delayTim->setObjectName(QStringLiteral("label_delayTim"));
        sizePolicy.setHeightForWidth(label_delayTim->sizePolicy().hasHeightForWidth());
        label_delayTim->setSizePolicy(sizePolicy);
        label_delayTim->setMinimumSize(QSize(85, 20));
        label_delayTim->setMaximumSize(QSize(16777215, 20));
        label_delayTim->setFont(font);

        gridLayout->addWidget(label_delayTim, 0, 0, 1, 1);

        doubleSpinBox_delayTime = new QDoubleSpinBox(WidgetFrontPanel_Pump);
        doubleSpinBox_delayTime->setObjectName(QStringLiteral("doubleSpinBox_delayTime"));
        sizePolicy.setHeightForWidth(doubleSpinBox_delayTime->sizePolicy().hasHeightForWidth());
        doubleSpinBox_delayTime->setSizePolicy(sizePolicy);
        doubleSpinBox_delayTime->setMinimumSize(QSize(80, 20));
        doubleSpinBox_delayTime->setMaximumSize(QSize(80, 20));
        doubleSpinBox_delayTime->setFont(font);
        doubleSpinBox_delayTime->setAlignment(Qt::AlignCenter);
        doubleSpinBox_delayTime->setDecimals(0);
        doubleSpinBox_delayTime->setValue(0);

        gridLayout->addWidget(doubleSpinBox_delayTime, 0, 1, 1, 1);

        label_Flowrate = new QLabel(WidgetFrontPanel_Pump);
        label_Flowrate->setObjectName(QStringLiteral("label_Flowrate"));
        sizePolicy.setHeightForWidth(label_Flowrate->sizePolicy().hasHeightForWidth());
        label_Flowrate->setSizePolicy(sizePolicy);
        label_Flowrate->setMinimumSize(QSize(85, 20));
        label_Flowrate->setMaximumSize(QSize(85, 20));
        label_Flowrate->setFont(font);

        gridLayout->addWidget(label_Flowrate, 1, 0, 1, 1);

        doubleSpinBox_flowRate = new QDoubleSpinBox(WidgetFrontPanel_Pump);
        doubleSpinBox_flowRate->setObjectName(QStringLiteral("doubleSpinBox_flowRate"));
        sizePolicy.setHeightForWidth(doubleSpinBox_flowRate->sizePolicy().hasHeightForWidth());
        doubleSpinBox_flowRate->setSizePolicy(sizePolicy);
        doubleSpinBox_flowRate->setMinimumSize(QSize(80, 20));
        doubleSpinBox_flowRate->setMaximumSize(QSize(80, 20));
        doubleSpinBox_flowRate->setFont(font);
        doubleSpinBox_flowRate->setAlignment(Qt::AlignCenter);
        doubleSpinBox_flowRate->setDecimals(2);

        gridLayout->addWidget(doubleSpinBox_flowRate, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 1, 1, 1);


        retranslateUi(WidgetFrontPanel_Pump);

        QMetaObject::connectSlotsByName(WidgetFrontPanel_Pump);
    } // setupUi

    void retranslateUi(QWidget *WidgetFrontPanel_Pump)
    {
        WidgetFrontPanel_Pump->setWindowTitle(QApplication::translate("WidgetFrontPanel_Pump", "Form", nullptr));
        label_Running_2->setText(QApplication::translate("WidgetFrontPanel_Pump", "Running:", nullptr));
        label_Running->setText(QApplication::translate("WidgetFrontPanel_Pump", "Initialized:", nullptr));
        pushButton_PumpRunning->setText(QApplication::translate("WidgetFrontPanel_Pump", "ON", nullptr));
        label_conductivity->setText(QApplication::translate("WidgetFrontPanel_Pump", "Conductivity", nullptr));
        label_ph->setText(QApplication::translate("WidgetFrontPanel_Pump", "pH", nullptr));
        label_delayTim->setText(QApplication::translate("WidgetFrontPanel_Pump", "Delay (sec)", nullptr));
        label_Flowrate->setText(QApplication::translate("WidgetFrontPanel_Pump", "Flowrate (lpm)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetFrontPanel_Pump: public Ui_WidgetFrontPanel_Pump {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_FRONT_PANEL_PUMP_H
