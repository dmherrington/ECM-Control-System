/********************************************************************************
** Form generated from reading UI file 'widget_front_panel_touchoff.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_FRONT_PANEL_TOUCHOFF_H
#define UI_WIDGET_FRONT_PANEL_TOUCHOFF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_TouchoffGap;
    QPushButton *pushButton_TouchoffRef;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_Values;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    LED *widget_LEDTouchoffStatus;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_ExecuteTouchoff;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *WidgetFrontPanel_Touchoff)
    {
        if (WidgetFrontPanel_Touchoff->objectName().isEmpty())
            WidgetFrontPanel_Touchoff->setObjectName(QStringLiteral("WidgetFrontPanel_Touchoff"));
        WidgetFrontPanel_Touchoff->resize(375, 115);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetFrontPanel_Touchoff->sizePolicy().hasHeightForWidth());
        WidgetFrontPanel_Touchoff->setSizePolicy(sizePolicy);
        WidgetFrontPanel_Touchoff->setMinimumSize(QSize(375, 115));
        WidgetFrontPanel_Touchoff->setMaximumSize(QSize(375, 300));
        gridLayout = new QGridLayout(WidgetFrontPanel_Touchoff);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_TouchoffGap = new QPushButton(WidgetFrontPanel_Touchoff);
        pushButton_TouchoffGap->setObjectName(QStringLiteral("pushButton_TouchoffGap"));
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

        horizontalLayout_3->addWidget(pushButton_TouchoffGap);

        pushButton_TouchoffRef = new QPushButton(WidgetFrontPanel_Touchoff);
        pushButton_TouchoffRef->setObjectName(QStringLiteral("pushButton_TouchoffRef"));
        sizePolicy1.setHeightForWidth(pushButton_TouchoffRef->sizePolicy().hasHeightForWidth());
        pushButton_TouchoffRef->setSizePolicy(sizePolicy1);
        pushButton_TouchoffRef->setMinimumSize(QSize(110, 25));
        pushButton_TouchoffRef->setMaximumSize(QSize(110, 25));
        pushButton_TouchoffRef->setFont(font);

        horizontalLayout_3->addWidget(pushButton_TouchoffRef);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout_Values = new QVBoxLayout();
        verticalLayout_Values->setSpacing(1);
        verticalLayout_Values->setObjectName(QStringLiteral("verticalLayout_Values"));

        verticalLayout->addLayout(verticalLayout_Values);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(2, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        widget_LEDTouchoffStatus = new LED(WidgetFrontPanel_Touchoff);
        widget_LEDTouchoffStatus->setObjectName(QStringLiteral("widget_LEDTouchoffStatus"));
        sizePolicy1.setHeightForWidth(widget_LEDTouchoffStatus->sizePolicy().hasHeightForWidth());
        widget_LEDTouchoffStatus->setSizePolicy(sizePolicy1);
        widget_LEDTouchoffStatus->setMinimumSize(QSize(40, 30));
        widget_LEDTouchoffStatus->setMaximumSize(QSize(40, 30));

        horizontalLayout->addWidget(widget_LEDTouchoffStatus);

        horizontalSpacer_5 = new QSpacerItem(2, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(2, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_ExecuteTouchoff = new QPushButton(WidgetFrontPanel_Touchoff);
        pushButton_ExecuteTouchoff->setObjectName(QStringLiteral("pushButton_ExecuteTouchoff"));
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


        horizontalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);


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
