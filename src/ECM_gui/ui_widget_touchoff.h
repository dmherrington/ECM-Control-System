/********************************************************************************
** Form generated from reading UI file 'widget_touchoff.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_TOUCHOFF_H
#define UI_WIDGET_TOUCHOFF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Touchoff
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_15;
    QGridLayout *gridLayout_13;
    QLabel *label_ManualControl_4;
    QSpacerItem *horizontalSpacer_16;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_TouchoffRef;
    QDoubleSpinBox *doubleSpinBox_TouchoffRef;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_TouchoffGap;
    QDoubleSpinBox *doubleSpinBox_InitialGap;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_17;
    QCheckBox *checkBox_UtilizeTouchoff;
    QSpacerItem *horizontalSpacer_18;
    QCheckBox *checkBox_ReferenceOldPosition;
    QSpacerItem *horizontalSpacer_19;

    void setupUi(QWidget *Widget_Touchoff)
    {
        if (Widget_Touchoff->objectName().isEmpty())
            Widget_Touchoff->setObjectName(QStringLiteral("Widget_Touchoff"));
        Widget_Touchoff->resize(506, 160);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_Touchoff->sizePolicy().hasHeightForWidth());
        Widget_Touchoff->setSizePolicy(sizePolicy);
        Widget_Touchoff->setMinimumSize(QSize(506, 160));
        Widget_Touchoff->setMaximumSize(QSize(506, 160));
        Widget_Touchoff->setStyleSheet(QLatin1String("QMenuBar{\n"
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
        gridLayout_2 = new QGridLayout(Widget_Touchoff);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_15);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        label_ManualControl_4 = new QLabel(Widget_Touchoff);
        label_ManualControl_4->setObjectName(QStringLiteral("label_ManualControl_4"));
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

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pushButton_TouchoffRef = new QPushButton(Widget_Touchoff);
        pushButton_TouchoffRef->setObjectName(QStringLiteral("pushButton_TouchoffRef"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_TouchoffRef->sizePolicy().hasHeightForWidth());
        pushButton_TouchoffRef->setSizePolicy(sizePolicy2);
        pushButton_TouchoffRef->setMinimumSize(QSize(180, 25));
        pushButton_TouchoffRef->setMaximumSize(QSize(180, 25));
        QFont font1;
        font1.setPointSize(12);
        pushButton_TouchoffRef->setFont(font1);

        horizontalLayout_9->addWidget(pushButton_TouchoffRef);

        doubleSpinBox_TouchoffRef = new QDoubleSpinBox(Widget_Touchoff);
        doubleSpinBox_TouchoffRef->setObjectName(QStringLiteral("doubleSpinBox_TouchoffRef"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_TouchoffRef->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TouchoffRef->setSizePolicy(sizePolicy2);
        doubleSpinBox_TouchoffRef->setMinimumSize(QSize(120, 25));
        doubleSpinBox_TouchoffRef->setMaximumSize(QSize(120, 25));
        QFont font2;
        font2.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font2.setPointSize(11);
        doubleSpinBox_TouchoffRef->setFont(font2);
        doubleSpinBox_TouchoffRef->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_TouchoffRef->setDecimals(1);
        doubleSpinBox_TouchoffRef->setMinimum(0);
        doubleSpinBox_TouchoffRef->setMaximum(500000);

        horizontalLayout_9->addWidget(doubleSpinBox_TouchoffRef);

        label_3 = new QLabel(Widget_Touchoff);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(32, 25));
        label_3->setMaximumSize(QSize(32, 25));
        label_3->setFont(font1);

        horizontalLayout_9->addWidget(label_3);


        gridLayout->addLayout(horizontalLayout_9, 0, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        pushButton_TouchoffGap = new QPushButton(Widget_Touchoff);
        pushButton_TouchoffGap->setObjectName(QStringLiteral("pushButton_TouchoffGap"));
        sizePolicy2.setHeightForWidth(pushButton_TouchoffGap->sizePolicy().hasHeightForWidth());
        pushButton_TouchoffGap->setSizePolicy(sizePolicy2);
        pushButton_TouchoffGap->setMinimumSize(QSize(180, 25));
        pushButton_TouchoffGap->setMaximumSize(QSize(16777215, 25));
        pushButton_TouchoffGap->setFont(font1);

        horizontalLayout_10->addWidget(pushButton_TouchoffGap);

        doubleSpinBox_InitialGap = new QDoubleSpinBox(Widget_Touchoff);
        doubleSpinBox_InitialGap->setObjectName(QStringLiteral("doubleSpinBox_InitialGap"));
        doubleSpinBox_InitialGap->setMinimumSize(QSize(120, 25));
        doubleSpinBox_InitialGap->setMaximumSize(QSize(120, 25));
        QFont font3;
        font3.setPointSize(11);
        doubleSpinBox_InitialGap->setFont(font3);
        doubleSpinBox_InitialGap->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_InitialGap->setDecimals(1);
        doubleSpinBox_InitialGap->setMaximum(100000);

        horizontalLayout_10->addWidget(doubleSpinBox_InitialGap);

        label_4 = new QLabel(Widget_Touchoff);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(32, 25));
        label_4->setMaximumSize(QSize(32, 25));
        label_4->setFont(font1);

        horizontalLayout_10->addWidget(label_4);


        gridLayout->addLayout(horizontalLayout_10, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_17);

        checkBox_UtilizeTouchoff = new QCheckBox(Widget_Touchoff);
        checkBox_UtilizeTouchoff->setObjectName(QStringLiteral("checkBox_UtilizeTouchoff"));
        checkBox_UtilizeTouchoff->setFont(font1);
        checkBox_UtilizeTouchoff->setChecked(true);

        horizontalLayout->addWidget(checkBox_UtilizeTouchoff);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_18);

        checkBox_ReferenceOldPosition = new QCheckBox(Widget_Touchoff);
        checkBox_ReferenceOldPosition->setObjectName(QStringLiteral("checkBox_ReferenceOldPosition"));
        checkBox_ReferenceOldPosition->setFont(font1);

        horizontalLayout->addWidget(checkBox_ReferenceOldPosition);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_19);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(Widget_Touchoff);

        QMetaObject::connectSlotsByName(Widget_Touchoff);
    } // setupUi

    void retranslateUi(QWidget *Widget_Touchoff)
    {
        Widget_Touchoff->setWindowTitle(QApplication::translate("Widget_Touchoff", "Form", nullptr));
        label_ManualControl_4->setText(QApplication::translate("Widget_Touchoff", "Touchoff Configuration", nullptr));
        pushButton_TouchoffRef->setText(QApplication::translate("Widget_Touchoff", "Set Touchoff Ref", nullptr));
        label_3->setText(QApplication::translate("Widget_Touchoff", "um", nullptr));
        pushButton_TouchoffGap->setText(QApplication::translate("Widget_Touchoff", "Set Initial Gap", nullptr));
        label_4->setText(QApplication::translate("Widget_Touchoff", "um", nullptr));
        checkBox_UtilizeTouchoff->setText(QApplication::translate("Widget_Touchoff", "Utilize Touchoff", nullptr));
        checkBox_ReferenceOldPosition->setText(QApplication::translate("Widget_Touchoff", "Utilize Current", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_Touchoff: public Ui_Widget_Touchoff {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_TOUCHOFF_H
