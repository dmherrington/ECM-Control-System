/********************************************************************************
** Form generated from reading UI file 'widget_pump_control.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_PUMP_CONTROL_H
#define UI_WIDGET_PUMP_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_PumpControl
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_16;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_23;
    QGridLayout *gridLayout_24;
    QLabel *label_ManualControl_5;
    QSpacerItem *horizontalSpacer_24;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_OnTime;
    QLineEdit *lineEdit_OnTime;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_17;
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer_18;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *pushButton_PumpRunning;
    QSpacerItem *horizontalSpacer_20;
    QGridLayout *gridLayout_15;
    QDoubleSpinBox *doubleSpinBox_delayTime;
    QLabel *label_Flowrate;
    QDoubleSpinBox *doubleSpinBox_flowRate;
    QLabel *label_delayTim;

    void setupUi(QWidget *Widget_PumpControl)
    {
        if (Widget_PumpControl->objectName().isEmpty())
            Widget_PumpControl->setObjectName(QStringLiteral("Widget_PumpControl"));
        Widget_PumpControl->resize(530, 160);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_PumpControl->sizePolicy().hasHeightForWidth());
        Widget_PumpControl->setSizePolicy(sizePolicy);
        Widget_PumpControl->setMinimumSize(QSize(530, 160));
        Widget_PumpControl->setMaximumSize(QSize(530, 160));
        Widget_PumpControl->setStyleSheet(QLatin1String("QMenuBar{\n"
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
        gridLayout = new QGridLayout(Widget_PumpControl);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_16 = new QGridLayout();
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_23);

        gridLayout_24 = new QGridLayout();
        gridLayout_24->setObjectName(QStringLiteral("gridLayout_24"));
        label_ManualControl_5 = new QLabel(Widget_PumpControl);
        label_ManualControl_5->setObjectName(QStringLiteral("label_ManualControl_5"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_ManualControl_5->sizePolicy().hasHeightForWidth());
        label_ManualControl_5->setSizePolicy(sizePolicy1);
        label_ManualControl_5->setMinimumSize(QSize(0, 32));
        label_ManualControl_5->setMaximumSize(QSize(16777215, 32));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_ManualControl_5->setFont(font);
        label_ManualControl_5->setAlignment(Qt::AlignCenter);

        gridLayout_24->addWidget(label_ManualControl_5, 0, 0, 1, 1);


        horizontalLayout_17->addLayout(gridLayout_24);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_24);


        gridLayout_16->addLayout(horizontalLayout_17, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_OnTime = new QLabel(Widget_PumpControl);
        label_OnTime->setObjectName(QStringLiteral("label_OnTime"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_OnTime->sizePolicy().hasHeightForWidth());
        label_OnTime->setSizePolicy(sizePolicy2);
        label_OnTime->setMinimumSize(QSize(242, 20));
        label_OnTime->setMaximumSize(QSize(16777215, 20));
        QFont font1;
        font1.setPointSize(12);
        label_OnTime->setFont(font1);
        label_OnTime->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_OnTime);

        lineEdit_OnTime = new QLineEdit(Widget_PumpControl);
        lineEdit_OnTime->setObjectName(QStringLiteral("lineEdit_OnTime"));
        lineEdit_OnTime->setEnabled(true);
        sizePolicy2.setHeightForWidth(lineEdit_OnTime->sizePolicy().hasHeightForWidth());
        lineEdit_OnTime->setSizePolicy(sizePolicy2);
        lineEdit_OnTime->setMinimumSize(QSize(242, 20));
        lineEdit_OnTime->setMaximumSize(QSize(16777215, 20));
        QFont font2;
        font2.setPointSize(13);
        lineEdit_OnTime->setFont(font2);
        lineEdit_OnTime->setAlignment(Qt::AlignCenter);
        lineEdit_OnTime->setReadOnly(true);

        verticalLayout_3->addWidget(lineEdit_OnTime);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalSpacer_17 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_17);

        checkBox_2 = new QCheckBox(Widget_PumpControl);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setFont(font1);

        horizontalLayout_13->addWidget(checkBox_2);

        horizontalSpacer_18 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_18);


        verticalLayout_4->addLayout(horizontalLayout_13);


        gridLayout_16->addLayout(verticalLayout_4, 0, 1, 2, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer_19 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_19);

        pushButton_PumpRunning = new QPushButton(Widget_PumpControl);
        pushButton_PumpRunning->setObjectName(QStringLiteral("pushButton_PumpRunning"));
        sizePolicy2.setHeightForWidth(pushButton_PumpRunning->sizePolicy().hasHeightForWidth());
        pushButton_PumpRunning->setSizePolicy(sizePolicy2);
        pushButton_PumpRunning->setMinimumSize(QSize(242, 40));
        pushButton_PumpRunning->setMaximumSize(QSize(16777215, 40));
        QFont font3;
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setWeight(75);
        pushButton_PumpRunning->setFont(font3);
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

        horizontalLayout_14->addWidget(pushButton_PumpRunning);

        horizontalSpacer_20 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_20);


        gridLayout_16->addLayout(horizontalLayout_14, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_16, 0, 0, 1, 1);

        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        doubleSpinBox_delayTime = new QDoubleSpinBox(Widget_PumpControl);
        doubleSpinBox_delayTime->setObjectName(QStringLiteral("doubleSpinBox_delayTime"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_delayTime->sizePolicy().hasHeightForWidth());
        doubleSpinBox_delayTime->setSizePolicy(sizePolicy2);
        doubleSpinBox_delayTime->setMinimumSize(QSize(100, 20));
        doubleSpinBox_delayTime->setMaximumSize(QSize(100, 20));
        QFont font4;
        font4.setPointSize(10);
        doubleSpinBox_delayTime->setFont(font4);
        doubleSpinBox_delayTime->setAlignment(Qt::AlignCenter);
        doubleSpinBox_delayTime->setDecimals(0);
        doubleSpinBox_delayTime->setValue(0);

        gridLayout_15->addWidget(doubleSpinBox_delayTime, 0, 1, 1, 1);

        label_Flowrate = new QLabel(Widget_PumpControl);
        label_Flowrate->setObjectName(QStringLiteral("label_Flowrate"));
        sizePolicy2.setHeightForWidth(label_Flowrate->sizePolicy().hasHeightForWidth());
        label_Flowrate->setSizePolicy(sizePolicy2);
        label_Flowrate->setMinimumSize(QSize(136, 20));
        label_Flowrate->setMaximumSize(QSize(16777215, 20));
        label_Flowrate->setFont(font1);

        gridLayout_15->addWidget(label_Flowrate, 1, 0, 1, 1);

        doubleSpinBox_flowRate = new QDoubleSpinBox(Widget_PumpControl);
        doubleSpinBox_flowRate->setObjectName(QStringLiteral("doubleSpinBox_flowRate"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_flowRate->sizePolicy().hasHeightForWidth());
        doubleSpinBox_flowRate->setSizePolicy(sizePolicy2);
        doubleSpinBox_flowRate->setMinimumSize(QSize(100, 20));
        doubleSpinBox_flowRate->setMaximumSize(QSize(100, 20));
        doubleSpinBox_flowRate->setFont(font4);
        doubleSpinBox_flowRate->setAlignment(Qt::AlignCenter);
        doubleSpinBox_flowRate->setDecimals(2);

        gridLayout_15->addWidget(doubleSpinBox_flowRate, 1, 1, 1, 1);

        label_delayTim = new QLabel(Widget_PumpControl);
        label_delayTim->setObjectName(QStringLiteral("label_delayTim"));
        sizePolicy2.setHeightForWidth(label_delayTim->sizePolicy().hasHeightForWidth());
        label_delayTim->setSizePolicy(sizePolicy2);
        label_delayTim->setMinimumSize(QSize(136, 20));
        label_delayTim->setMaximumSize(QSize(16777215, 20));
        label_delayTim->setFont(font1);

        gridLayout_15->addWidget(label_delayTim, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_15, 1, 0, 1, 1);


        retranslateUi(Widget_PumpControl);

        QMetaObject::connectSlotsByName(Widget_PumpControl);
    } // setupUi

    void retranslateUi(QWidget *Widget_PumpControl)
    {
        Widget_PumpControl->setWindowTitle(QApplication::translate("Widget_PumpControl", "Form", nullptr));
        label_ManualControl_5->setText(QApplication::translate("Widget_PumpControl", "Pump Configuration", nullptr));
        label_OnTime->setText(QApplication::translate("Widget_PumpControl", "On Time:", nullptr));
        checkBox_2->setText(QApplication::translate("Widget_PumpControl", "Wait For Delay", nullptr));
        pushButton_PumpRunning->setText(QApplication::translate("Widget_PumpControl", "ON", nullptr));
        label_Flowrate->setText(QApplication::translate("Widget_PumpControl", "Flowrate Setpoint (lpm)", nullptr));
        label_delayTim->setText(QApplication::translate("Widget_PumpControl", "Delay Time (sec)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_PumpControl: public Ui_Widget_PumpControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_PUMP_CONTROL_H
