/********************************************************************************
** Form generated from reading UI file 'widget_munk_power_supply.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_MUNK_POWER_SUPPLY_H
#define UI_WIDGET_MUNK_POWER_SUPPLY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "munk_dialog/widget_segment_time_display.h"

QT_BEGIN_NAMESPACE

class Ui_Widget_MunkPowerSupply
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_15;
    QGridLayout *gridLayout_13;
    QLabel *label_ManualControl_4;
    QSpacerItem *horizontalSpacer_16;
    WidgetSegmentTimeDisplay *segmentWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_singlePulse;
    QRadioButton *radioButton_continuousPulse;
    QRadioButton *radioButton_specifiedPulses;
    QSpinBox *spinBox_NumPulses;

    void setupUi(QWidget *Widget_MunkPowerSupply)
    {
        if (Widget_MunkPowerSupply->objectName().isEmpty())
            Widget_MunkPowerSupply->setObjectName(QString::fromUtf8("Widget_MunkPowerSupply"));
        Widget_MunkPowerSupply->resize(583, 316);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_MunkPowerSupply->sizePolicy().hasHeightForWidth());
        Widget_MunkPowerSupply->setSizePolicy(sizePolicy);
        Widget_MunkPowerSupply->setMinimumSize(QSize(580, 316));
        Widget_MunkPowerSupply->setMaximumSize(QSize(586, 316));
        gridLayout_2 = new QGridLayout(Widget_MunkPowerSupply);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_15);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        label_ManualControl_4 = new QLabel(Widget_MunkPowerSupply);
        label_ManualControl_4->setObjectName(QString::fromUtf8("label_ManualControl_4"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_ManualControl_4->sizePolicy().hasHeightForWidth());
        label_ManualControl_4->setSizePolicy(sizePolicy1);
        label_ManualControl_4->setMinimumSize(QSize(0, 32));
        label_ManualControl_4->setMaximumSize(QSize(16777215, 32));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_ManualControl_4->setFont(font);
        label_ManualControl_4->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(label_ManualControl_4, 0, 0, 1, 1);


        horizontalLayout_11->addLayout(gridLayout_13);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_16);


        gridLayout_2->addLayout(horizontalLayout_11, 0, 0, 1, 1);

        segmentWidget = new WidgetSegmentTimeDisplay(Widget_MunkPowerSupply);
        segmentWidget->setObjectName(QString::fromUtf8("segmentWidget"));
        sizePolicy1.setHeightForWidth(segmentWidget->sizePolicy().hasHeightForWidth());
        segmentWidget->setSizePolicy(sizePolicy1);
        segmentWidget->setMinimumSize(QSize(200, 210));
        segmentWidget->setAutoFillBackground(false);
        segmentWidget->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
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

        gridLayout_2->addWidget(segmentWidget, 1, 0, 1, 1);

        groupBox = new QGroupBox(Widget_MunkPowerSupply);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        radioButton_singlePulse = new QRadioButton(groupBox);
        radioButton_singlePulse->setObjectName(QString::fromUtf8("radioButton_singlePulse"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(radioButton_singlePulse->sizePolicy().hasHeightForWidth());
        radioButton_singlePulse->setSizePolicy(sizePolicy2);
        radioButton_singlePulse->setMinimumSize(QSize(130, 20));
        radioButton_singlePulse->setMaximumSize(QSize(130, 20));
        QFont font1;
        font1.setPointSize(10);
        radioButton_singlePulse->setFont(font1);
        radioButton_singlePulse->setChecked(true);

        gridLayout->addWidget(radioButton_singlePulse, 0, 0, 1, 1);

        radioButton_continuousPulse = new QRadioButton(groupBox);
        radioButton_continuousPulse->setObjectName(QString::fromUtf8("radioButton_continuousPulse"));
        sizePolicy2.setHeightForWidth(radioButton_continuousPulse->sizePolicy().hasHeightForWidth());
        radioButton_continuousPulse->setSizePolicy(sizePolicy2);
        radioButton_continuousPulse->setMinimumSize(QSize(160, 20));
        radioButton_continuousPulse->setMaximumSize(QSize(160, 20));
        radioButton_continuousPulse->setFont(font1);
        radioButton_continuousPulse->setChecked(false);

        gridLayout->addWidget(radioButton_continuousPulse, 0, 1, 1, 1);

        radioButton_specifiedPulses = new QRadioButton(groupBox);
        radioButton_specifiedPulses->setObjectName(QString::fromUtf8("radioButton_specifiedPulses"));
        sizePolicy2.setHeightForWidth(radioButton_specifiedPulses->sizePolicy().hasHeightForWidth());
        radioButton_specifiedPulses->setSizePolicy(sizePolicy2);
        radioButton_specifiedPulses->setMinimumSize(QSize(180, 20));
        radioButton_specifiedPulses->setMaximumSize(QSize(180, 20));
        radioButton_specifiedPulses->setFont(font1);

        gridLayout->addWidget(radioButton_specifiedPulses, 0, 2, 1, 1);

        spinBox_NumPulses = new QSpinBox(groupBox);
        spinBox_NumPulses->setObjectName(QString::fromUtf8("spinBox_NumPulses"));
        spinBox_NumPulses->setMinimumSize(QSize(60, 20));
        spinBox_NumPulses->setMaximumSize(QSize(60, 20));
        spinBox_NumPulses->setFont(font1);
        spinBox_NumPulses->setMinimum(0);
        spinBox_NumPulses->setMaximum(255);
        spinBox_NumPulses->setValue(0);

        gridLayout->addWidget(spinBox_NumPulses, 0, 3, 1, 1);


        gridLayout_2->addWidget(groupBox, 2, 0, 1, 1);


        retranslateUi(Widget_MunkPowerSupply);

        QMetaObject::connectSlotsByName(Widget_MunkPowerSupply);
    } // setupUi

    void retranslateUi(QWidget *Widget_MunkPowerSupply)
    {
        Widget_MunkPowerSupply->setWindowTitle(QApplication::translate("Widget_MunkPowerSupply", "Form", nullptr));
        label_ManualControl_4->setText(QApplication::translate("Widget_MunkPowerSupply", "Power Supply Configuration", nullptr));
        groupBox->setTitle(QString());
        radioButton_singlePulse->setText(QApplication::translate("Widget_MunkPowerSupply", "Single Pulse Mode", nullptr));
        radioButton_continuousPulse->setText(QApplication::translate("Widget_MunkPowerSupply", "Continuous Pulse Mode", nullptr));
        radioButton_specifiedPulses->setText(QApplication::translate("Widget_MunkPowerSupply", "Specified Number of Pulses", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_MunkPowerSupply: public Ui_Widget_MunkPowerSupply {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_MUNK_POWER_SUPPLY_H
