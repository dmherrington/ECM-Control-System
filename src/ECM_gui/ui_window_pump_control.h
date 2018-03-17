/********************************************************************************
** Form generated from reading UI file 'window_pump_control.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_PUMP_CONTROL_H
#define UI_WINDOW_PUMP_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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

class Ui_Window_PumpControl
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_7;
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
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Connection;
    LED *widget_PumpOn;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_Running;
    LED *widget_PumpConnected;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBox_delayTime;
    QLabel *label_Flowrate;
    QDoubleSpinBox *doubleSpinBox_flowRate;
    QLabel *label_delayTim;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_PumpRunning;
    QLabel *label_OnTime;
    QLineEdit *lineEdit_OnTime;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_PumpControl)
    {
        if (Window_PumpControl->objectName().isEmpty())
            Window_PumpControl->setObjectName(QStringLiteral("Window_PumpControl"));
        Window_PumpControl->resize(440, 325);
        Window_PumpControl->setMinimumSize(QSize(440, 325));
        Window_PumpControl->setStyleSheet(QLatin1String("QMenuBar{\n"
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
        centralwidget = new QWidget(Window_PumpControl);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_7 = new QGridLayout(centralwidget);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_Electrolyte = new QLabel(centralwidget);
        label_Electrolyte->setObjectName(QStringLiteral("label_Electrolyte"));
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
        lineEdit_Electrolyte->setObjectName(QStringLiteral("lineEdit_Electrolyte"));
        lineEdit_Electrolyte->setMinimumSize(QSize(170, 20));
        lineEdit_Electrolyte->setMaximumSize(QSize(170, 20));
        lineEdit_Electrolyte->setFont(font);
        lineEdit_Electrolyte->setAlignment(Qt::AlignCenter);
        lineEdit_Electrolyte->setReadOnly(true);

        gridLayout_4->addWidget(lineEdit_Electrolyte, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_pH = new QLabel(centralwidget);
        label_pH->setObjectName(QStringLiteral("label_pH"));
        sizePolicy.setHeightForWidth(label_pH->sizePolicy().hasHeightForWidth());
        label_pH->setSizePolicy(sizePolicy);
        label_pH->setMinimumSize(QSize(170, 20));
        label_pH->setMaximumSize(QSize(170, 20));
        label_pH->setFont(font);
        label_pH->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_pH, 0, 0, 1, 1);

        lineEdit_pH = new QLineEdit(centralwidget);
        lineEdit_pH->setObjectName(QStringLiteral("lineEdit_pH"));
        lineEdit_pH->setMinimumSize(QSize(170, 20));
        lineEdit_pH->setMaximumSize(QSize(170, 20));
        lineEdit_pH->setFont(font);
        lineEdit_pH->setAlignment(Qt::AlignCenter);
        lineEdit_pH->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_pH, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_Conductivity = new QLabel(centralwidget);
        label_Conductivity->setObjectName(QStringLiteral("label_Conductivity"));
        sizePolicy.setHeightForWidth(label_Conductivity->sizePolicy().hasHeightForWidth());
        label_Conductivity->setSizePolicy(sizePolicy);
        label_Conductivity->setMinimumSize(QSize(170, 20));
        label_Conductivity->setMaximumSize(QSize(170, 20));
        label_Conductivity->setFont(font);
        label_Conductivity->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_Conductivity, 0, 0, 1, 1);

        lineEdit_Conuctivity = new QLineEdit(centralwidget);
        lineEdit_Conuctivity->setObjectName(QStringLiteral("lineEdit_Conuctivity"));
        lineEdit_Conuctivity->setMinimumSize(QSize(170, 20));
        lineEdit_Conuctivity->setMaximumSize(QSize(170, 20));
        lineEdit_Conuctivity->setFont(font);
        lineEdit_Conuctivity->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:1px solid red;\n"
"}"));
        lineEdit_Conuctivity->setAlignment(Qt::AlignCenter);
        lineEdit_Conuctivity->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_Conuctivity, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 2, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_5, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_Connection = new QLabel(centralwidget);
        label_Connection->setObjectName(QStringLiteral("label_Connection"));
        sizePolicy.setHeightForWidth(label_Connection->sizePolicy().hasHeightForWidth());
        label_Connection->setSizePolicy(sizePolicy);
        label_Connection->setMinimumSize(QSize(80, 18));
        label_Connection->setMaximumSize(QSize(80, 18));
        label_Connection->setFont(font);
        label_Connection->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_Connection);

        widget_PumpOn = new LED(centralwidget);
        widget_PumpOn->setObjectName(QStringLiteral("widget_PumpOn"));
        sizePolicy.setHeightForWidth(widget_PumpOn->sizePolicy().hasHeightForWidth());
        widget_PumpOn->setSizePolicy(sizePolicy);
        widget_PumpOn->setMinimumSize(QSize(80, 50));
        widget_PumpOn->setMaximumSize(QSize(80, 50));

        verticalLayout_2->addWidget(widget_PumpOn);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 50, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_Running = new QLabel(centralwidget);
        label_Running->setObjectName(QStringLiteral("label_Running"));
        sizePolicy.setHeightForWidth(label_Running->sizePolicy().hasHeightForWidth());
        label_Running->setSizePolicy(sizePolicy);
        label_Running->setMinimumSize(QSize(80, 18));
        label_Running->setMaximumSize(QSize(80, 18));
        label_Running->setFont(font);
        label_Running->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_Running);

        widget_PumpConnected = new LED(centralwidget);
        widget_PumpConnected->setObjectName(QStringLiteral("widget_PumpConnected"));
        sizePolicy.setHeightForWidth(widget_PumpConnected->sizePolicy().hasHeightForWidth());
        widget_PumpConnected->setSizePolicy(sizePolicy);
        widget_PumpConnected->setMinimumSize(QSize(80, 50));
        widget_PumpConnected->setMaximumSize(QSize(80, 50));

        verticalLayout_3->addWidget(widget_PumpConnected);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout_6->addLayout(horizontalLayout, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_6->addItem(verticalSpacer, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        doubleSpinBox_delayTime = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_delayTime->setObjectName(QStringLiteral("doubleSpinBox_delayTime"));
        sizePolicy.setHeightForWidth(doubleSpinBox_delayTime->sizePolicy().hasHeightForWidth());
        doubleSpinBox_delayTime->setSizePolicy(sizePolicy);
        doubleSpinBox_delayTime->setMinimumSize(QSize(100, 20));
        doubleSpinBox_delayTime->setMaximumSize(QSize(100, 20));
        doubleSpinBox_delayTime->setFont(font);
        doubleSpinBox_delayTime->setAlignment(Qt::AlignCenter);
        doubleSpinBox_delayTime->setDecimals(0);
        doubleSpinBox_delayTime->setValue(0);

        gridLayout->addWidget(doubleSpinBox_delayTime, 0, 1, 1, 1);

        label_Flowrate = new QLabel(centralwidget);
        label_Flowrate->setObjectName(QStringLiteral("label_Flowrate"));
        sizePolicy.setHeightForWidth(label_Flowrate->sizePolicy().hasHeightForWidth());
        label_Flowrate->setSizePolicy(sizePolicy);
        label_Flowrate->setMinimumSize(QSize(136, 20));
        label_Flowrate->setMaximumSize(QSize(16777215, 20));
        label_Flowrate->setFont(font);

        gridLayout->addWidget(label_Flowrate, 1, 0, 1, 1);

        doubleSpinBox_flowRate = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_flowRate->setObjectName(QStringLiteral("doubleSpinBox_flowRate"));
        sizePolicy.setHeightForWidth(doubleSpinBox_flowRate->sizePolicy().hasHeightForWidth());
        doubleSpinBox_flowRate->setSizePolicy(sizePolicy);
        doubleSpinBox_flowRate->setMinimumSize(QSize(100, 20));
        doubleSpinBox_flowRate->setMaximumSize(QSize(100, 20));
        doubleSpinBox_flowRate->setFont(font);
        doubleSpinBox_flowRate->setAlignment(Qt::AlignCenter);
        doubleSpinBox_flowRate->setDecimals(2);

        gridLayout->addWidget(doubleSpinBox_flowRate, 1, 1, 1, 1);

        label_delayTim = new QLabel(centralwidget);
        label_delayTim->setObjectName(QStringLiteral("label_delayTim"));
        sizePolicy.setHeightForWidth(label_delayTim->sizePolicy().hasHeightForWidth());
        label_delayTim->setSizePolicy(sizePolicy);
        label_delayTim->setMinimumSize(QSize(136, 20));
        label_delayTim->setMaximumSize(QSize(16777215, 20));
        label_delayTim->setFont(font);

        gridLayout->addWidget(label_delayTim, 0, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout, 3, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_PumpRunning = new QPushButton(centralwidget);
        pushButton_PumpRunning->setObjectName(QStringLiteral("pushButton_PumpRunning"));
        sizePolicy.setHeightForWidth(pushButton_PumpRunning->sizePolicy().hasHeightForWidth());
        pushButton_PumpRunning->setSizePolicy(sizePolicy);
        pushButton_PumpRunning->setMinimumSize(QSize(242, 40));
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

        label_OnTime = new QLabel(centralwidget);
        label_OnTime->setObjectName(QStringLiteral("label_OnTime"));
        sizePolicy.setHeightForWidth(label_OnTime->sizePolicy().hasHeightForWidth());
        label_OnTime->setSizePolicy(sizePolicy);
        label_OnTime->setMinimumSize(QSize(242, 20));
        label_OnTime->setMaximumSize(QSize(16777215, 20));
        QFont font2;
        font2.setPointSize(12);
        label_OnTime->setFont(font2);
        label_OnTime->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_OnTime);

        lineEdit_OnTime = new QLineEdit(centralwidget);
        lineEdit_OnTime->setObjectName(QStringLiteral("lineEdit_OnTime"));
        lineEdit_OnTime->setEnabled(true);
        sizePolicy.setHeightForWidth(lineEdit_OnTime->sizePolicy().hasHeightForWidth());
        lineEdit_OnTime->setSizePolicy(sizePolicy);
        lineEdit_OnTime->setMinimumSize(QSize(242, 20));
        lineEdit_OnTime->setMaximumSize(QSize(16777215, 20));
        QFont font3;
        font3.setPointSize(13);
        lineEdit_OnTime->setFont(font3);
        lineEdit_OnTime->setAlignment(Qt::AlignCenter);
        lineEdit_OnTime->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_OnTime);


        gridLayout_6->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 1, 2, 1);

        pushButton = new QPushButton(centralwidget);
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

        gridLayout_7->addWidget(pushButton, 1, 0, 1, 1);

        Window_PumpControl->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_PumpControl);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 440, 40));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        Window_PumpControl->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_PumpControl);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Window_PumpControl->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp->menuAction());

        retranslateUi(Window_PumpControl);

        QMetaObject::connectSlotsByName(Window_PumpControl);
    } // setupUi

    void retranslateUi(QMainWindow *Window_PumpControl)
    {
        Window_PumpControl->setWindowTitle(QApplication::translate("Window_PumpControl", "Window Pump Control", nullptr));
        label_Electrolyte->setText(QApplication::translate("Window_PumpControl", "Electrolyte Type:", nullptr));
        label_pH->setText(QApplication::translate("Window_PumpControl", "Electrolyte pH:", nullptr));
        label_Conductivity->setText(QApplication::translate("Window_PumpControl", "Conductivity (mS/cm):", nullptr));
        label_Connection->setText(QApplication::translate("Window_PumpControl", "Connection:", nullptr));
        label_Running->setText(QApplication::translate("Window_PumpControl", "Running:", nullptr));
        label_Flowrate->setText(QApplication::translate("Window_PumpControl", "Flowrate Setpoint (lpm)", nullptr));
        label_delayTim->setText(QApplication::translate("Window_PumpControl", "Delay Time (sec)", nullptr));
        pushButton_PumpRunning->setText(QApplication::translate("Window_PumpControl", "ON", nullptr));
        label_OnTime->setText(QApplication::translate("Window_PumpControl", "On Time:", nullptr));
        pushButton->setText(QApplication::translate("Window_PumpControl", "DONE", nullptr));
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
