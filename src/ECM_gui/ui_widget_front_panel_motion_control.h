/********************************************************************************
** Form generated from reading UI file 'widget_front_panel_motion_control.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_FRONT_PANEL_MOTION_CONTROL_H
#define UI_WIDGET_FRONT_PANEL_MOTION_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetFrontPanel_MotionControl
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_4;
    QLabel *label_ManualControl;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *WidgetFrontPanel_MotionControl)
    {
        if (WidgetFrontPanel_MotionControl->objectName().isEmpty())
            WidgetFrontPanel_MotionControl->setObjectName(QStringLiteral("WidgetFrontPanel_MotionControl"));
        WidgetFrontPanel_MotionControl->resize(375, 100);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetFrontPanel_MotionControl->sizePolicy().hasHeightForWidth());
        WidgetFrontPanel_MotionControl->setSizePolicy(sizePolicy);
        WidgetFrontPanel_MotionControl->setMinimumSize(QSize(375, 100));
        WidgetFrontPanel_MotionControl->setMaximumSize(QSize(375, 16777215));
        verticalLayout = new QVBoxLayout(WidgetFrontPanel_MotionControl);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_ManualControl = new QLabel(WidgetFrontPanel_MotionControl);
        label_ManualControl->setObjectName(QStringLiteral("label_ManualControl"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_ManualControl->sizePolicy().hasHeightForWidth());
        label_ManualControl->setSizePolicy(sizePolicy1);
        label_ManualControl->setMinimumSize(QSize(0, 20));
        label_ManualControl->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_ManualControl->setFont(font);
        label_ManualControl->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_ManualControl, 0, 0, 1, 1);


        horizontalLayout_6->addLayout(gridLayout_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(WidgetFrontPanel_MotionControl);

        QMetaObject::connectSlotsByName(WidgetFrontPanel_MotionControl);
    } // setupUi

    void retranslateUi(QWidget *WidgetFrontPanel_MotionControl)
    {
        WidgetFrontPanel_MotionControl->setWindowTitle(QApplication::translate("WidgetFrontPanel_MotionControl", "Form", nullptr));
        label_ManualControl->setText(QApplication::translate("WidgetFrontPanel_MotionControl", "Manual Control", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetFrontPanel_MotionControl: public Ui_WidgetFrontPanel_MotionControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_FRONT_PANEL_MOTION_CONTROL_H
