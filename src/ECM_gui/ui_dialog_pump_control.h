/********************************************************************************
** Form generated from reading UI file 'dialog_pump_control.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_PUMP_CONTROL_H
#define UI_DIALOG_PUMP_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "LED.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog_PumpControl
{
public:
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QLabel *label_Electrolyte;
    QLineEdit *lineEdit_Electrolyte;
    QGridLayout *gridLayout_3;
    QLabel *label_pH;
    QLineEdit *lineEdit_pH;
    QGridLayout *gridLayout_2;
    QLabel *label_Conductivity;
    QLineEdit *lineEdit_Conuctivity;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_PumpRunning;
    QLabel *label_OnTime;
    QLineEdit *lineEdit_OnTime;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    LED *widget_PumpOn;
    QSpacerItem *horizontalSpacer_2;
    LED *widget_PumpConnected;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBox_flowRate;
    QLabel *label_Flowrate;
    QDoubleSpinBox *doubleSpinBox_delayTime;
    QLabel *label_delayTim;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog_PumpControl)
    {
        if (Dialog_PumpControl->objectName().isEmpty())
            Dialog_PumpControl->setObjectName(QStringLiteral("Dialog_PumpControl"));
        Dialog_PumpControl->resize(444, 278);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog_PumpControl->sizePolicy().hasHeightForWidth());
        Dialog_PumpControl->setSizePolicy(sizePolicy);
        Dialog_PumpControl->setStyleSheet(QLatin1String("QMainWindow{\n"
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
"border-radius:1px solid red;\n"
"background-color:#c4c4c4;\n"
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
        gridLayout_6 = new QGridLayout(Dialog_PumpControl);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_Electrolyte = new QLabel(Dialog_PumpControl);
        label_Electrolyte->setObjectName(QStringLiteral("label_Electrolyte"));
        sizePolicy.setHeightForWidth(label_Electrolyte->sizePolicy().hasHeightForWidth());
        label_Electrolyte->setSizePolicy(sizePolicy);
        label_Electrolyte->setMinimumSize(QSize(170, 20));
        label_Electrolyte->setMaximumSize(QSize(170, 20));
        QFont font;
        font.setPointSize(10);
        label_Electrolyte->setFont(font);
        label_Electrolyte->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_Electrolyte, 0, 0, 1, 1);

        lineEdit_Electrolyte = new QLineEdit(Dialog_PumpControl);
        lineEdit_Electrolyte->setObjectName(QStringLiteral("lineEdit_Electrolyte"));
        lineEdit_Electrolyte->setMinimumSize(QSize(170, 20));
        lineEdit_Electrolyte->setMaximumSize(QSize(170, 20));
        lineEdit_Electrolyte->setFont(font);

        gridLayout_4->addWidget(lineEdit_Electrolyte, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_pH = new QLabel(Dialog_PumpControl);
        label_pH->setObjectName(QStringLiteral("label_pH"));
        sizePolicy.setHeightForWidth(label_pH->sizePolicy().hasHeightForWidth());
        label_pH->setSizePolicy(sizePolicy);
        label_pH->setMinimumSize(QSize(170, 20));
        label_pH->setMaximumSize(QSize(170, 20));
        label_pH->setFont(font);
        label_pH->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_pH, 0, 0, 1, 1);

        lineEdit_pH = new QLineEdit(Dialog_PumpControl);
        lineEdit_pH->setObjectName(QStringLiteral("lineEdit_pH"));
        lineEdit_pH->setMinimumSize(QSize(170, 20));
        lineEdit_pH->setMaximumSize(QSize(170, 20));
        lineEdit_pH->setFont(font);

        gridLayout_3->addWidget(lineEdit_pH, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_Conductivity = new QLabel(Dialog_PumpControl);
        label_Conductivity->setObjectName(QStringLiteral("label_Conductivity"));
        sizePolicy.setHeightForWidth(label_Conductivity->sizePolicy().hasHeightForWidth());
        label_Conductivity->setSizePolicy(sizePolicy);
        label_Conductivity->setMinimumSize(QSize(170, 20));
        label_Conductivity->setMaximumSize(QSize(170, 20));
        label_Conductivity->setFont(font);
        label_Conductivity->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_Conductivity, 0, 0, 1, 1);

        lineEdit_Conuctivity = new QLineEdit(Dialog_PumpControl);
        lineEdit_Conuctivity->setObjectName(QStringLiteral("lineEdit_Conuctivity"));
        lineEdit_Conuctivity->setMinimumSize(QSize(170, 20));
        lineEdit_Conuctivity->setMaximumSize(QSize(170, 20));
        lineEdit_Conuctivity->setFont(font);
        lineEdit_Conuctivity->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:1px solid red;\n"
"}"));

        gridLayout_2->addWidget(lineEdit_Conuctivity, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 2, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_PumpRunning = new QPushButton(Dialog_PumpControl);
        pushButton_PumpRunning->setObjectName(QStringLiteral("pushButton_PumpRunning"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_PumpRunning->sizePolicy().hasHeightForWidth());
        pushButton_PumpRunning->setSizePolicy(sizePolicy1);
        pushButton_PumpRunning->setMinimumSize(QSize(140, 40));
        pushButton_PumpRunning->setMaximumSize(QSize(16777215, 40));
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

        verticalLayout->addWidget(pushButton_PumpRunning);

        label_OnTime = new QLabel(Dialog_PumpControl);
        label_OnTime->setObjectName(QStringLiteral("label_OnTime"));
        sizePolicy1.setHeightForWidth(label_OnTime->sizePolicy().hasHeightForWidth());
        label_OnTime->setSizePolicy(sizePolicy1);
        label_OnTime->setMinimumSize(QSize(140, 20));
        QFont font2;
        font2.setPointSize(12);
        label_OnTime->setFont(font2);
        label_OnTime->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_OnTime);

        lineEdit_OnTime = new QLineEdit(Dialog_PumpControl);
        lineEdit_OnTime->setObjectName(QStringLiteral("lineEdit_OnTime"));
        lineEdit_OnTime->setEnabled(true);
        sizePolicy1.setHeightForWidth(lineEdit_OnTime->sizePolicy().hasHeightForWidth());
        lineEdit_OnTime->setSizePolicy(sizePolicy1);
        lineEdit_OnTime->setMinimumSize(QSize(140, 20));
        QFont font3;
        font3.setPointSize(13);
        lineEdit_OnTime->setFont(font3);
        lineEdit_OnTime->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_OnTime);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget_PumpOn = new LED(Dialog_PumpControl);
        widget_PumpOn->setObjectName(QStringLiteral("widget_PumpOn"));
        sizePolicy.setHeightForWidth(widget_PumpOn->sizePolicy().hasHeightForWidth());
        widget_PumpOn->setSizePolicy(sizePolicy);
        widget_PumpOn->setMinimumSize(QSize(80, 80));

        horizontalLayout->addWidget(widget_PumpOn);

        horizontalSpacer_2 = new QSpacerItem(40, 50, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        widget_PumpConnected = new LED(Dialog_PumpControl);
        widget_PumpConnected->setObjectName(QStringLiteral("widget_PumpConnected"));
        sizePolicy.setHeightForWidth(widget_PumpConnected->sizePolicy().hasHeightForWidth());
        widget_PumpConnected->setSizePolicy(sizePolicy);
        widget_PumpConnected->setMinimumSize(QSize(80, 80));

        horizontalLayout->addWidget(widget_PumpConnected);


        verticalLayout_2->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        doubleSpinBox_flowRate = new QDoubleSpinBox(Dialog_PumpControl);
        doubleSpinBox_flowRate->setObjectName(QStringLiteral("doubleSpinBox_flowRate"));
        doubleSpinBox_flowRate->setMinimumSize(QSize(100, 0));
        doubleSpinBox_flowRate->setFont(font);
        doubleSpinBox_flowRate->setAlignment(Qt::AlignCenter);
        doubleSpinBox_flowRate->setDecimals(0);
        doubleSpinBox_flowRate->setValue(0);

        gridLayout->addWidget(doubleSpinBox_flowRate, 0, 1, 1, 1);

        label_Flowrate = new QLabel(Dialog_PumpControl);
        label_Flowrate->setObjectName(QStringLiteral("label_Flowrate"));
        label_Flowrate->setFont(font);

        gridLayout->addWidget(label_Flowrate, 1, 0, 1, 1);

        doubleSpinBox_delayTime = new QDoubleSpinBox(Dialog_PumpControl);
        doubleSpinBox_delayTime->setObjectName(QStringLiteral("doubleSpinBox_delayTime"));
        doubleSpinBox_delayTime->setMinimumSize(QSize(100, 0));
        doubleSpinBox_delayTime->setFont(font);
        doubleSpinBox_delayTime->setAlignment(Qt::AlignCenter);
        doubleSpinBox_delayTime->setDecimals(2);

        gridLayout->addWidget(doubleSpinBox_delayTime, 1, 1, 1, 1);

        label_delayTim = new QLabel(Dialog_PumpControl);
        label_delayTim->setObjectName(QStringLiteral("label_delayTim"));
        label_delayTim->setFont(font);

        gridLayout->addWidget(label_delayTim, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        gridLayout_6->addLayout(verticalLayout_2, 0, 1, 2, 1);

        pushButton = new QPushButton(Dialog_PumpControl);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(100, 40));
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QLatin1String("QMainWindow{\n"
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

        gridLayout_6->addWidget(pushButton, 1, 0, 1, 1);


        retranslateUi(Dialog_PumpControl);

        QMetaObject::connectSlotsByName(Dialog_PumpControl);
    } // setupUi

    void retranslateUi(QDialog *Dialog_PumpControl)
    {
        Dialog_PumpControl->setWindowTitle(QApplication::translate("Dialog_PumpControl", "Dialog", nullptr));
        label_Electrolyte->setText(QApplication::translate("Dialog_PumpControl", "Electrolyte Type:", nullptr));
        label_pH->setText(QApplication::translate("Dialog_PumpControl", "Electrolyte pH:", nullptr));
        label_Conductivity->setText(QApplication::translate("Dialog_PumpControl", "Conductivity (mS/cm):", nullptr));
        pushButton_PumpRunning->setText(QApplication::translate("Dialog_PumpControl", "ON", nullptr));
        label_OnTime->setText(QApplication::translate("Dialog_PumpControl", "On Time:", nullptr));
        label_Flowrate->setText(QApplication::translate("Dialog_PumpControl", "Flowrate Setpoint (lpm)", nullptr));
        label_delayTim->setText(QApplication::translate("Dialog_PumpControl", "Delay Time (sec)", nullptr));
        pushButton->setText(QApplication::translate("Dialog_PumpControl", "DONE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_PumpControl: public Ui_Dialog_PumpControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_PUMP_CONTROL_H
