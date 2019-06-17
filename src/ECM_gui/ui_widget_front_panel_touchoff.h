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
#include <QtWidgets/QWidget>
#include "LED.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetFrontPanel_Touchoff
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_initialGap;
    QPushButton *pushButton_TouchoffGap;
    QHBoxLayout *horizontalLayout_touchoffRef;
    QPushButton *pushButton_TouchoffRef;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_ExecuteTouchoff;
    QSpacerItem *horizontalSpacer;
    LED *widget_LEDTouchoffStatus;

    void setupUi(QWidget *WidgetFrontPanel_Touchoff)
    {
        if (WidgetFrontPanel_Touchoff->objectName().isEmpty())
            WidgetFrontPanel_Touchoff->setObjectName(QStringLiteral("WidgetFrontPanel_Touchoff"));
        WidgetFrontPanel_Touchoff->resize(375, 116);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetFrontPanel_Touchoff->sizePolicy().hasHeightForWidth());
        WidgetFrontPanel_Touchoff->setSizePolicy(sizePolicy);
        WidgetFrontPanel_Touchoff->setMinimumSize(QSize(375, 0));
        WidgetFrontPanel_Touchoff->setMaximumSize(QSize(1000, 16777215));
        gridLayout = new QGridLayout(WidgetFrontPanel_Touchoff);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_initialGap = new QHBoxLayout();
        horizontalLayout_initialGap->setSpacing(0);
        horizontalLayout_initialGap->setObjectName(QStringLiteral("horizontalLayout_initialGap"));
        pushButton_TouchoffGap = new QPushButton(WidgetFrontPanel_Touchoff);
        pushButton_TouchoffGap->setObjectName(QStringLiteral("pushButton_TouchoffGap"));
        sizePolicy.setHeightForWidth(pushButton_TouchoffGap->sizePolicy().hasHeightForWidth());
        pushButton_TouchoffGap->setSizePolicy(sizePolicy);
        pushButton_TouchoffGap->setMinimumSize(QSize(180, 25));
        pushButton_TouchoffGap->setMaximumSize(QSize(16777215, 25));
        QFont font;
        font.setPointSize(12);
        pushButton_TouchoffGap->setFont(font);

        horizontalLayout_initialGap->addWidget(pushButton_TouchoffGap);


        gridLayout->addLayout(horizontalLayout_initialGap, 0, 0, 1, 1);

        horizontalLayout_touchoffRef = new QHBoxLayout();
        horizontalLayout_touchoffRef->setSpacing(0);
        horizontalLayout_touchoffRef->setObjectName(QStringLiteral("horizontalLayout_touchoffRef"));
        pushButton_TouchoffRef = new QPushButton(WidgetFrontPanel_Touchoff);
        pushButton_TouchoffRef->setObjectName(QStringLiteral("pushButton_TouchoffRef"));
        sizePolicy.setHeightForWidth(pushButton_TouchoffRef->sizePolicy().hasHeightForWidth());
        pushButton_TouchoffRef->setSizePolicy(sizePolicy);
        pushButton_TouchoffRef->setMinimumSize(QSize(180, 25));
        pushButton_TouchoffRef->setMaximumSize(QSize(180, 25));
        pushButton_TouchoffRef->setFont(font);

        horizontalLayout_touchoffRef->addWidget(pushButton_TouchoffRef);


        gridLayout->addLayout(horizontalLayout_touchoffRef, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_ExecuteTouchoff = new QPushButton(WidgetFrontPanel_Touchoff);
        pushButton_ExecuteTouchoff->setObjectName(QStringLiteral("pushButton_ExecuteTouchoff"));
        sizePolicy.setHeightForWidth(pushButton_ExecuteTouchoff->sizePolicy().hasHeightForWidth());
        pushButton_ExecuteTouchoff->setSizePolicy(sizePolicy);
        pushButton_ExecuteTouchoff->setMinimumSize(QSize(100, 30));
        pushButton_ExecuteTouchoff->setMaximumSize(QSize(100, 30));
        pushButton_ExecuteTouchoff->setFont(font);

        horizontalLayout->addWidget(pushButton_ExecuteTouchoff);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget_LEDTouchoffStatus = new LED(WidgetFrontPanel_Touchoff);
        widget_LEDTouchoffStatus->setObjectName(QStringLiteral("widget_LEDTouchoffStatus"));
        sizePolicy.setHeightForWidth(widget_LEDTouchoffStatus->sizePolicy().hasHeightForWidth());
        widget_LEDTouchoffStatus->setSizePolicy(sizePolicy);
        widget_LEDTouchoffStatus->setMinimumSize(QSize(40, 30));
        widget_LEDTouchoffStatus->setMaximumSize(QSize(40, 30));

        horizontalLayout->addWidget(widget_LEDTouchoffStatus);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


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
