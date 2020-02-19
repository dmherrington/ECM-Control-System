/********************************************************************************
** Form generated from reading UI file 'window_pump_control.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_PUMP_CONTROL_H
#define UI_WINDOW_PUMP_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "LED.h"

QT_BEGIN_NAMESPACE

class Ui_Window_PumpControl
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionClose;
    QWidget *centralwidget;
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
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBox_delayTime;
    QLabel *label_Flowrate;
    QDoubleSpinBox *doubleSpinBox_flowRate;
    QLabel *label_delayTim;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_PumpRunning;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_PumpControl)
    {
        if (Window_PumpControl->objectName().isEmpty())
            Window_PumpControl->setObjectName(QString::fromUtf8("Window_PumpControl"));
        Window_PumpControl->resize(442, 258);
        Window_PumpControl->setMinimumSize(QSize(442, 258));
        Window_PumpControl->setMaximumSize(QSize(442, 258));
        Window_PumpControl->setStyleSheet(QString::fromUtf8("QMenuBar{\n"
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
        actionOpen = new QAction(Window_PumpControl);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(Window_PumpControl);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(Window_PumpControl);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionClose = new QAction(Window_PumpControl);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        centralwidget = new QWidget(Window_PumpControl);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_6 = new QGridLayout(centralwidget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_Electrolyte = new QLabel(centralwidget);
        label_Electrolyte->setObjectName(QString::fromUtf8("label_Electrolyte"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_Electrolyte->sizePolicy().hasHeightForWidth());
        label_Electrolyte->setSizePolicy(sizePolicy);
        label_Electrolyte->setMinimumSize(QSize(170, 20));
        label_Electrolyte->setMaximumSize(QSize(170, 20));
        QFont font;
        font.setPointSize(10);
        label_Electrolyte->setFont(font);
        label_Electrolyte->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_Electrolyte, 0, 0, 1, 1);

        lineEdit_Electrolyte = new QLineEdit(centralwidget);
        lineEdit_Electrolyte->setObjectName(QString::fromUtf8("lineEdit_Electrolyte"));
        lineEdit_Electrolyte->setMinimumSize(QSize(170, 20));
        lineEdit_Electrolyte->setMaximumSize(QSize(170, 20));
        lineEdit_Electrolyte->setFont(font);
        lineEdit_Electrolyte->setAlignment(Qt::AlignCenter);
        lineEdit_Electrolyte->setReadOnly(true);

        gridLayout_4->addWidget(lineEdit_Electrolyte, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_pH = new QLabel(centralwidget);
        label_pH->setObjectName(QString::fromUtf8("label_pH"));
        sizePolicy.setHeightForWidth(label_pH->sizePolicy().hasHeightForWidth());
        label_pH->setSizePolicy(sizePolicy);
        label_pH->setMinimumSize(QSize(170, 20));
        label_pH->setMaximumSize(QSize(170, 20));
        label_pH->setFont(font);
        label_pH->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_pH, 0, 0, 1, 1);

        lineEdit_pH = new QLineEdit(centralwidget);
        lineEdit_pH->setObjectName(QString::fromUtf8("lineEdit_pH"));
        lineEdit_pH->setMinimumSize(QSize(170, 20));
        lineEdit_pH->setMaximumSize(QSize(170, 20));
        lineEdit_pH->setFont(font);
        lineEdit_pH->setAlignment(Qt::AlignCenter);
        lineEdit_pH->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_pH, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_Conductivity = new QLabel(centralwidget);
        label_Conductivity->setObjectName(QString::fromUtf8("label_Conductivity"));
        sizePolicy.setHeightForWidth(label_Conductivity->sizePolicy().hasHeightForWidth());
        label_Conductivity->setSizePolicy(sizePolicy);
        label_Conductivity->setMinimumSize(QSize(170, 20));
        label_Conductivity->setMaximumSize(QSize(170, 20));
        label_Conductivity->setFont(font);
        label_Conductivity->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_Conductivity, 0, 0, 1, 1);

        lineEdit_Conuctivity = new QLineEdit(centralwidget);
        lineEdit_Conuctivity->setObjectName(QString::fromUtf8("lineEdit_Conuctivity"));
        lineEdit_Conuctivity->setMinimumSize(QSize(170, 20));
        lineEdit_Conuctivity->setMaximumSize(QSize(170, 20));
        lineEdit_Conuctivity->setFont(font);
        lineEdit_Conuctivity->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border-radius:1px solid red;\n"
"}"));
        lineEdit_Conuctivity->setAlignment(Qt::AlignCenter);
        lineEdit_Conuctivity->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_Conuctivity, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 2, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 3, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setHorizontalSpacing(1);
        label_Running_2 = new QLabel(centralwidget);
        label_Running_2->setObjectName(QString::fromUtf8("label_Running_2"));
        sizePolicy.setHeightForWidth(label_Running_2->sizePolicy().hasHeightForWidth());
        label_Running_2->setSizePolicy(sizePolicy);
        label_Running_2->setMinimumSize(QSize(65, 18));
        label_Running_2->setMaximumSize(QSize(65, 18));
        label_Running_2->setFont(font);
        label_Running_2->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_Running_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(1, 50, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        widget_PumpRunning = new LED(centralwidget);
        widget_PumpRunning->setObjectName(QString::fromUtf8("widget_PumpRunning"));
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
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(1);
        label_Running = new QLabel(centralwidget);
        label_Running->setObjectName(QString::fromUtf8("label_Running"));
        sizePolicy.setHeightForWidth(label_Running->sizePolicy().hasHeightForWidth());
        label_Running->setSizePolicy(sizePolicy);
        label_Running->setMinimumSize(QSize(65, 18));
        label_Running->setMaximumSize(QSize(65, 18));
        label_Running->setFont(font);
        label_Running->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_Running, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(1, 50, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        widget_PumpInitialized = new LED(centralwidget);
        widget_PumpInitialized->setObjectName(QString::fromUtf8("widget_PumpInitialized"));
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


        gridLayout_6->addLayout(horizontalLayout, 0, 1, 1, 2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        doubleSpinBox_delayTime = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_delayTime->setObjectName(QString::fromUtf8("doubleSpinBox_delayTime"));
        sizePolicy.setHeightForWidth(doubleSpinBox_delayTime->sizePolicy().hasHeightForWidth());
        doubleSpinBox_delayTime->setSizePolicy(sizePolicy);
        doubleSpinBox_delayTime->setMinimumSize(QSize(100, 20));
        doubleSpinBox_delayTime->setMaximumSize(QSize(100, 20));
        doubleSpinBox_delayTime->setFont(font);
        doubleSpinBox_delayTime->setAlignment(Qt::AlignCenter);
        doubleSpinBox_delayTime->setDecimals(0);
        doubleSpinBox_delayTime->setValue(0.000000000000000);

        gridLayout->addWidget(doubleSpinBox_delayTime, 0, 1, 1, 1);

        label_Flowrate = new QLabel(centralwidget);
        label_Flowrate->setObjectName(QString::fromUtf8("label_Flowrate"));
        sizePolicy.setHeightForWidth(label_Flowrate->sizePolicy().hasHeightForWidth());
        label_Flowrate->setSizePolicy(sizePolicy);
        label_Flowrate->setMinimumSize(QSize(136, 20));
        label_Flowrate->setMaximumSize(QSize(16777215, 20));
        label_Flowrate->setFont(font);

        gridLayout->addWidget(label_Flowrate, 1, 0, 1, 1);

        doubleSpinBox_flowRate = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_flowRate->setObjectName(QString::fromUtf8("doubleSpinBox_flowRate"));
        sizePolicy.setHeightForWidth(doubleSpinBox_flowRate->sizePolicy().hasHeightForWidth());
        doubleSpinBox_flowRate->setSizePolicy(sizePolicy);
        doubleSpinBox_flowRate->setMinimumSize(QSize(100, 20));
        doubleSpinBox_flowRate->setMaximumSize(QSize(100, 20));
        doubleSpinBox_flowRate->setFont(font);
        doubleSpinBox_flowRate->setAlignment(Qt::AlignCenter);
        doubleSpinBox_flowRate->setDecimals(2);

        gridLayout->addWidget(doubleSpinBox_flowRate, 1, 1, 1, 1);

        label_delayTim = new QLabel(centralwidget);
        label_delayTim->setObjectName(QString::fromUtf8("label_delayTim"));
        sizePolicy.setHeightForWidth(label_delayTim->sizePolicy().hasHeightForWidth());
        label_delayTim->setSizePolicy(sizePolicy);
        label_delayTim->setMinimumSize(QSize(136, 20));
        label_delayTim->setMaximumSize(QSize(16777215, 20));
        label_delayTim->setFont(font);

        gridLayout->addWidget(label_delayTim, 0, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout, 1, 1, 1, 2);

        horizontalSpacer_8 = new QSpacerItem(65, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_8, 2, 1, 1, 1);

        pushButton_PumpRunning = new QPushButton(centralwidget);
        pushButton_PumpRunning->setObjectName(QString::fromUtf8("pushButton_PumpRunning"));
        sizePolicy.setHeightForWidth(pushButton_PumpRunning->sizePolicy().hasHeightForWidth());
        pushButton_PumpRunning->setSizePolicy(sizePolicy);
        pushButton_PumpRunning->setMinimumSize(QSize(170, 40));
        pushButton_PumpRunning->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(75);
        pushButton_PumpRunning->setFont(font1);
        pushButton_PumpRunning->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
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

        gridLayout_6->addWidget(pushButton_PumpRunning, 2, 2, 1, 1);

        Window_PumpControl->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_PumpControl);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 442, 40));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        Window_PumpControl->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_PumpControl);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Window_PumpControl->setStatusBar(statusbar);

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

        retranslateUi(Window_PumpControl);

        QMetaObject::connectSlotsByName(Window_PumpControl);
    } // setupUi

    void retranslateUi(QMainWindow *Window_PumpControl)
    {
        Window_PumpControl->setWindowTitle(QApplication::translate("Window_PumpControl", "Window Pump Control", nullptr));
        actionOpen->setText(QApplication::translate("Window_PumpControl", "Open", nullptr));
        actionSave->setText(QApplication::translate("Window_PumpControl", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("Window_PumpControl", "Save As", nullptr));
        actionClose->setText(QApplication::translate("Window_PumpControl", "Close", nullptr));
        label_Electrolyte->setText(QApplication::translate("Window_PumpControl", "Electrolyte Type:", nullptr));
        label_pH->setText(QApplication::translate("Window_PumpControl", "Electrolyte pH:", nullptr));
        label_Conductivity->setText(QApplication::translate("Window_PumpControl", "Conductivity (mS/cm):", nullptr));
        label_Running_2->setText(QApplication::translate("Window_PumpControl", "Running:", nullptr));
        label_Running->setText(QApplication::translate("Window_PumpControl", "Initialized:", nullptr));
        label_Flowrate->setText(QApplication::translate("Window_PumpControl", "Flowrate Setpoint (lpm)", nullptr));
        label_delayTim->setText(QApplication::translate("Window_PumpControl", "Delay Time (sec)", nullptr));
        pushButton_PumpRunning->setText(QApplication::translate("Window_PumpControl", "ON", nullptr));
        menuFile->setTitle(QApplication::translate("Window_PumpControl", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("Window_PumpControl", "Edit", nullptr));
        menuTools->setTitle(QApplication::translate("Window_PumpControl", "Tools", nullptr));
        menuHelp->setTitle(QApplication::translate("Window_PumpControl", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_PumpControl: public Ui_Window_PumpControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_PUMP_CONTROL_H
