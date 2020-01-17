/********************************************************************************
** Form generated from reading UI file 'widget_axis_vertical_control.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_AXIS_VERTICAL_CONTROL_H
#define UI_WIDGET_AXIS_VERTICAL_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_AxisVerticalControl
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_6;
    QLabel *label_ManualControl_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_IncreaseJog;
    QSpinBox *spinBox_Jog;
    QPushButton *pushButton_DecreaseJog;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_ManualControl_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout_SetpControlInner;
    QPushButton *pushButton_IncreaseRelativeMove;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox_RelativeMove;
    QSpinBox *spinBox_RelativeMoveSpeed;
    QPushButton *pushButton_DecreaseRelativeMove;
    QSpacerItem *horizontalSpacer_9;

    void setupUi(QWidget *Widget_AxisVerticalControl)
    {
        if (Widget_AxisVerticalControl->objectName().isEmpty())
            Widget_AxisVerticalControl->setObjectName(QStringLiteral("Widget_AxisVerticalControl"));
        Widget_AxisVerticalControl->resize(350, 153);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_AxisVerticalControl->sizePolicy().hasHeightForWidth());
        Widget_AxisVerticalControl->setSizePolicy(sizePolicy);
        Widget_AxisVerticalControl->setMinimumSize(QSize(350, 153));
        Widget_AxisVerticalControl->setMaximumSize(QSize(350, 153));
        gridLayout_2 = new QGridLayout(Widget_AxisVerticalControl);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(1);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(1, 1, 1, 1);
        label_ManualControl_3 = new QLabel(Widget_AxisVerticalControl);
        label_ManualControl_3->setObjectName(QStringLiteral("label_ManualControl_3"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_ManualControl_3->sizePolicy().hasHeightForWidth());
        label_ManualControl_3->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_ManualControl_3->setFont(font);
        label_ManualControl_3->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_ManualControl_3, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 1, 1);
        horizontalSpacer_7 = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_IncreaseJog = new QPushButton(Widget_AxisVerticalControl);
        pushButton_IncreaseJog->setObjectName(QStringLiteral("pushButton_IncreaseJog"));
        sizePolicy.setHeightForWidth(pushButton_IncreaseJog->sizePolicy().hasHeightForWidth());
        pushButton_IncreaseJog->setSizePolicy(sizePolicy);
        pushButton_IncreaseJog->setMinimumSize(QSize(130, 30));
        pushButton_IncreaseJog->setMaximumSize(QSize(130, 16777215));
        QFont font1;
        font1.setPointSize(12);
        pushButton_IncreaseJog->setFont(font1);

        verticalLayout->addWidget(pushButton_IncreaseJog);

        spinBox_Jog = new QSpinBox(Widget_AxisVerticalControl);
        spinBox_Jog->setObjectName(QStringLiteral("spinBox_Jog"));
        sizePolicy.setHeightForWidth(spinBox_Jog->sizePolicy().hasHeightForWidth());
        spinBox_Jog->setSizePolicy(sizePolicy);
        spinBox_Jog->setMinimumSize(QSize(130, 30));
        QFont font2;
        font2.setPointSize(10);
        spinBox_Jog->setFont(font2);
        spinBox_Jog->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_Jog->setMinimum(1);
        spinBox_Jog->setMaximum(10000);
        spinBox_Jog->setSingleStep(10);
        spinBox_Jog->setValue(3000);

        verticalLayout->addWidget(spinBox_Jog);

        pushButton_DecreaseJog = new QPushButton(Widget_AxisVerticalControl);
        pushButton_DecreaseJog->setObjectName(QStringLiteral("pushButton_DecreaseJog"));
        sizePolicy.setHeightForWidth(pushButton_DecreaseJog->sizePolicy().hasHeightForWidth());
        pushButton_DecreaseJog->setSizePolicy(sizePolicy);
        pushButton_DecreaseJog->setMinimumSize(QSize(130, 30));
        pushButton_DecreaseJog->setMaximumSize(QSize(130, 16777215));
        pushButton_DecreaseJog->setFont(font1);

        verticalLayout->addWidget(pushButton_DecreaseJog);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_6, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(1);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(1, 1, 1, 1);
        label_ManualControl_4 = new QLabel(Widget_AxisVerticalControl);
        label_ManualControl_4->setObjectName(QStringLiteral("label_ManualControl_4"));
        sizePolicy1.setHeightForWidth(label_ManualControl_4->sizePolicy().hasHeightForWidth());
        label_ManualControl_4->setSizePolicy(sizePolicy1);
        label_ManualControl_4->setFont(font);
        label_ManualControl_4->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_ManualControl_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_8 = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        verticalLayout_SetpControlInner = new QVBoxLayout();
        verticalLayout_SetpControlInner->setObjectName(QStringLiteral("verticalLayout_SetpControlInner"));
        verticalLayout_SetpControlInner->setContentsMargins(1, 1, 1, 1);
        pushButton_IncreaseRelativeMove = new QPushButton(Widget_AxisVerticalControl);
        pushButton_IncreaseRelativeMove->setObjectName(QStringLiteral("pushButton_IncreaseRelativeMove"));
        sizePolicy.setHeightForWidth(pushButton_IncreaseRelativeMove->sizePolicy().hasHeightForWidth());
        pushButton_IncreaseRelativeMove->setSizePolicy(sizePolicy);
        pushButton_IncreaseRelativeMove->setMinimumSize(QSize(130, 30));
        pushButton_IncreaseRelativeMove->setMaximumSize(QSize(130, 16777215));
        pushButton_IncreaseRelativeMove->setFont(font1);

        verticalLayout_SetpControlInner->addWidget(pushButton_IncreaseRelativeMove);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        spinBox_RelativeMove = new QSpinBox(Widget_AxisVerticalControl);
        spinBox_RelativeMove->setObjectName(QStringLiteral("spinBox_RelativeMove"));
        sizePolicy.setHeightForWidth(spinBox_RelativeMove->sizePolicy().hasHeightForWidth());
        spinBox_RelativeMove->setSizePolicy(sizePolicy);
        spinBox_RelativeMove->setMinimumSize(QSize(65, 30));
        spinBox_RelativeMove->setMaximumSize(QSize(65, 16777215));
        spinBox_RelativeMove->setFont(font2);
        spinBox_RelativeMove->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_RelativeMove->setMaximum(125000);
        spinBox_RelativeMove->setSingleStep(100);
        spinBox_RelativeMove->setValue(2000);

        horizontalLayout->addWidget(spinBox_RelativeMove);

        spinBox_RelativeMoveSpeed = new QSpinBox(Widget_AxisVerticalControl);
        spinBox_RelativeMoveSpeed->setObjectName(QStringLiteral("spinBox_RelativeMoveSpeed"));
        spinBox_RelativeMoveSpeed->setMinimumSize(QSize(65, 30));
        spinBox_RelativeMoveSpeed->setMaximumSize(QSize(65, 16777215));
        spinBox_RelativeMoveSpeed->setFont(font2);
        spinBox_RelativeMoveSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_RelativeMoveSpeed->setMaximum(10000);
        spinBox_RelativeMoveSpeed->setSingleStep(10);
        spinBox_RelativeMoveSpeed->setValue(1000);

        horizontalLayout->addWidget(spinBox_RelativeMoveSpeed);


        verticalLayout_SetpControlInner->addLayout(horizontalLayout);

        pushButton_DecreaseRelativeMove = new QPushButton(Widget_AxisVerticalControl);
        pushButton_DecreaseRelativeMove->setObjectName(QStringLiteral("pushButton_DecreaseRelativeMove"));
        sizePolicy.setHeightForWidth(pushButton_DecreaseRelativeMove->sizePolicy().hasHeightForWidth());
        pushButton_DecreaseRelativeMove->setSizePolicy(sizePolicy);
        pushButton_DecreaseRelativeMove->setMinimumSize(QSize(130, 30));
        pushButton_DecreaseRelativeMove->setMaximumSize(QSize(130, 16777215));
        pushButton_DecreaseRelativeMove->setFont(font1);

        verticalLayout_SetpControlInner->addWidget(pushButton_DecreaseRelativeMove);


        horizontalLayout_2->addLayout(verticalLayout_SetpControlInner);

        horizontalSpacer_9 = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);


        verticalLayout_5->addLayout(horizontalLayout_2);


        gridLayout_2->addLayout(verticalLayout_5, 0, 1, 1, 1);


        retranslateUi(Widget_AxisVerticalControl);

        QMetaObject::connectSlotsByName(Widget_AxisVerticalControl);
    } // setupUi

    void retranslateUi(QWidget *Widget_AxisVerticalControl)
    {
        Widget_AxisVerticalControl->setWindowTitle(QApplication::translate("Widget_AxisVerticalControl", "Form", nullptr));
        label_ManualControl_3->setText(QApplication::translate("Widget_AxisVerticalControl", "Jog  (um/sec)", nullptr));
        pushButton_IncreaseJog->setText(QApplication::translate("Widget_AxisVerticalControl", "INCREASE", nullptr));
        pushButton_DecreaseJog->setText(QApplication::translate("Widget_AxisVerticalControl", "DECREASE", nullptr));
        label_ManualControl_4->setText(QApplication::translate("Widget_AxisVerticalControl", "Step (um | um/sec)", nullptr));
        pushButton_IncreaseRelativeMove->setText(QApplication::translate("Widget_AxisVerticalControl", "INCREASE", nullptr));
#ifndef QT_NO_TOOLTIP
        spinBox_RelativeMoveSpeed->setToolTip(QApplication::translate("Widget_AxisVerticalControl", "Testing1", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        spinBox_RelativeMoveSpeed->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        pushButton_DecreaseRelativeMove->setText(QApplication::translate("Widget_AxisVerticalControl", "DECREASE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_AxisVerticalControl: public Ui_Widget_AxisVerticalControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_AXIS_VERTICAL_CONTROL_H
