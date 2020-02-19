/********************************************************************************
** Form generated from reading UI file 'widget_front_panel_touchoff.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_FRONT_PANEL_TOUCHOFF_H
#define UI_WIDGET_FRONT_PANEL_TOUCHOFF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "LED.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetFrontPanel_Touchoff
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_TouchoffGap;
    QVBoxLayout *verticalLayout_initialGap;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_TouchoffRef;
    QVBoxLayout *verticalLayout_touchoffRef;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_ExecuteTouchoff;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    LED *widget_LEDTouchoffStatus;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *WidgetFrontPanel_Touchoff)
    {
        if (WidgetFrontPanel_Touchoff->objectName().isEmpty())
            WidgetFrontPanel_Touchoff->setObjectName(QString::fromUtf8("WidgetFrontPanel_Touchoff"));
        WidgetFrontPanel_Touchoff->resize(375, 115);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetFrontPanel_Touchoff->sizePolicy().hasHeightForWidth());
        WidgetFrontPanel_Touchoff->setSizePolicy(sizePolicy);
        WidgetFrontPanel_Touchoff->setMinimumSize(QSize(375, 115));
        WidgetFrontPanel_Touchoff->setMaximumSize(QSize(375, 300));
        gridLayout = new QGridLayout(WidgetFrontPanel_Touchoff);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_TouchoffGap = new QPushButton(WidgetFrontPanel_Touchoff);
        pushButton_TouchoffGap->setObjectName(QString::fromUtf8("pushButton_TouchoffGap"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_TouchoffGap->sizePolicy().hasHeightForWidth());
        pushButton_TouchoffGap->setSizePolicy(sizePolicy1);
        pushButton_TouchoffGap->setMinimumSize(QSize(110, 25));
        pushButton_TouchoffGap->setMaximumSize(QSize(110, 25));
        QFont font;
        font.setPointSize(10);
        pushButton_TouchoffGap->setFont(font);

        verticalLayout_2->addWidget(pushButton_TouchoffGap);

        verticalLayout_initialGap = new QVBoxLayout();
        verticalLayout_initialGap->setSpacing(1);
        verticalLayout_initialGap->setObjectName(QString::fromUtf8("verticalLayout_initialGap"));

        verticalLayout_2->addLayout(verticalLayout_initialGap);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_TouchoffRef = new QPushButton(WidgetFrontPanel_Touchoff);
        pushButton_TouchoffRef->setObjectName(QString::fromUtf8("pushButton_TouchoffRef"));
        sizePolicy1.setHeightForWidth(pushButton_TouchoffRef->sizePolicy().hasHeightForWidth());
        pushButton_TouchoffRef->setSizePolicy(sizePolicy1);
        pushButton_TouchoffRef->setMinimumSize(QSize(110, 25));
        pushButton_TouchoffRef->setMaximumSize(QSize(110, 25));
        pushButton_TouchoffRef->setFont(font);

        verticalLayout->addWidget(pushButton_TouchoffRef);

        verticalLayout_touchoffRef = new QVBoxLayout();
        verticalLayout_touchoffRef->setSpacing(1);
        verticalLayout_touchoffRef->setObjectName(QString::fromUtf8("verticalLayout_touchoffRef"));

        verticalLayout->addLayout(verticalLayout_touchoffRef);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(2, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_ExecuteTouchoff = new QPushButton(WidgetFrontPanel_Touchoff);
        pushButton_ExecuteTouchoff->setObjectName(QString::fromUtf8("pushButton_ExecuteTouchoff"));
        sizePolicy1.setHeightForWidth(pushButton_ExecuteTouchoff->sizePolicy().hasHeightForWidth());
        pushButton_ExecuteTouchoff->setSizePolicy(sizePolicy1);
        pushButton_ExecuteTouchoff->setMinimumSize(QSize(100, 30));
        pushButton_ExecuteTouchoff->setMaximumSize(QSize(100, 30));
        QFont font1;
        font1.setPointSize(12);
        pushButton_ExecuteTouchoff->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_ExecuteTouchoff);

        horizontalSpacer_3 = new QSpacerItem(2, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(2, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        widget_LEDTouchoffStatus = new LED(WidgetFrontPanel_Touchoff);
        widget_LEDTouchoffStatus->setObjectName(QString::fromUtf8("widget_LEDTouchoffStatus"));
        sizePolicy1.setHeightForWidth(widget_LEDTouchoffStatus->sizePolicy().hasHeightForWidth());
        widget_LEDTouchoffStatus->setSizePolicy(sizePolicy1);
        widget_LEDTouchoffStatus->setMinimumSize(QSize(40, 30));
        widget_LEDTouchoffStatus->setMaximumSize(QSize(40, 30));

        horizontalLayout->addWidget(widget_LEDTouchoffStatus);

        horizontalSpacer_5 = new QSpacerItem(2, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_3, 0, 2, 1, 1);


        retranslateUi(WidgetFrontPanel_Touchoff);

        QMetaObject::connectSlotsByName(WidgetFrontPanel_Touchoff);
    } // setupUi

    void retranslateUi(QWidget *WidgetFrontPanel_Touchoff)
    {
        WidgetFrontPanel_Touchoff->setWindowTitle(QApplication::translate("WidgetFrontPanel_Touchoff", "Form", nullptr));
        pushButton_TouchoffGap->setText(QApplication::translate("WidgetFrontPanel_Touchoff", "Set Initial Gap", nullptr));
        pushButton_TouchoffRef->setText(QApplication::translate("WidgetFrontPanel_Touchoff", "Set Touchoff Ref", nullptr));
        pushButton_ExecuteTouchoff->setText(QApplication::translate("WidgetFrontPanel_Touchoff", "Execute", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetFrontPanel_Touchoff: public Ui_WidgetFrontPanel_Touchoff {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_FRONT_PANEL_TOUCHOFF_H
