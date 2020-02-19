/********************************************************************************
** Form generated from reading UI file 'widget_axis_horizontal_control.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_AXIS_HORIZONTAL_CONTROL_H
#define UI_WIDGET_AXIS_HORIZONTAL_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_AxisHorizontalControl
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_ManualControl_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_IncreaseJog;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QSpinBox *spinBox_Jog;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_DecreaseJog;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_ManualControl_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_IncreaseRelativeMove;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *spinBox_RelativeMove;
    QSpinBox *spinBox_RelativeMoveSpeed;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_DecreaseRelativeMove;

    void setupUi(QWidget *Widget_AxisHorizontalControl)
    {
        if (Widget_AxisHorizontalControl->objectName().isEmpty())
            Widget_AxisHorizontalControl->setObjectName(QString::fromUtf8("Widget_AxisHorizontalControl"));
        Widget_AxisHorizontalControl->resize(350, 150);
        Widget_AxisHorizontalControl->setMinimumSize(QSize(350, 150));
        Widget_AxisHorizontalControl->setMaximumSize(QSize(350, 150));
        gridLayout = new QGridLayout(Widget_AxisHorizontalControl);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_ManualControl_3 = new QLabel(Widget_AxisHorizontalControl);
        label_ManualControl_3->setObjectName(QString::fromUtf8("label_ManualControl_3"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_ManualControl_3->sizePolicy().hasHeightForWidth());
        label_ManualControl_3->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_ManualControl_3->setFont(font);
        label_ManualControl_3->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_ManualControl_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_IncreaseJog = new QPushButton(Widget_AxisHorizontalControl);
        pushButton_IncreaseJog->setObjectName(QString::fromUtf8("pushButton_IncreaseJog"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_IncreaseJog->sizePolicy().hasHeightForWidth());
        pushButton_IncreaseJog->setSizePolicy(sizePolicy1);
        pushButton_IncreaseJog->setMinimumSize(QSize(32, 102));
        pushButton_IncreaseJog->setMaximumSize(QSize(32, 102));
        QFont font1;
        font1.setPointSize(12);
        pushButton_IncreaseJog->setFont(font1);

        horizontalLayout_4->addWidget(pushButton_IncreaseJog);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(2, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        spinBox_Jog = new QSpinBox(Widget_AxisHorizontalControl);
        spinBox_Jog->setObjectName(QString::fromUtf8("spinBox_Jog"));
        sizePolicy1.setHeightForWidth(spinBox_Jog->sizePolicy().hasHeightForWidth());
        spinBox_Jog->setSizePolicy(sizePolicy1);
        spinBox_Jog->setMinimumSize(QSize(65, 30));
        spinBox_Jog->setMaximumSize(QSize(65, 30));
        QFont font2;
        font2.setPointSize(10);
        spinBox_Jog->setFont(font2);
        spinBox_Jog->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_Jog->setMinimum(1);
        spinBox_Jog->setMaximum(10000);
        spinBox_Jog->setSingleStep(10);
        spinBox_Jog->setValue(3000);

        horizontalLayout_3->addWidget(spinBox_Jog);

        horizontalSpacer_6 = new QSpacerItem(2, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_4);

        pushButton_DecreaseJog = new QPushButton(Widget_AxisHorizontalControl);
        pushButton_DecreaseJog->setObjectName(QString::fromUtf8("pushButton_DecreaseJog"));
        sizePolicy1.setHeightForWidth(pushButton_DecreaseJog->sizePolicy().hasHeightForWidth());
        pushButton_DecreaseJog->setSizePolicy(sizePolicy1);
        pushButton_DecreaseJog->setMinimumSize(QSize(32, 102));
        pushButton_DecreaseJog->setMaximumSize(QSize(32, 102));
        pushButton_DecreaseJog->setFont(font1);

        horizontalLayout_4->addWidget(pushButton_DecreaseJog);


        verticalLayout_5->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_ManualControl_4 = new QLabel(Widget_AxisHorizontalControl);
        label_ManualControl_4->setObjectName(QString::fromUtf8("label_ManualControl_4"));
        sizePolicy.setHeightForWidth(label_ManualControl_4->sizePolicy().hasHeightForWidth());
        label_ManualControl_4->setSizePolicy(sizePolicy);
        label_ManualControl_4->setFont(font);
        label_ManualControl_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_ManualControl_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_IncreaseRelativeMove = new QPushButton(Widget_AxisHorizontalControl);
        pushButton_IncreaseRelativeMove->setObjectName(QString::fromUtf8("pushButton_IncreaseRelativeMove"));
        sizePolicy1.setHeightForWidth(pushButton_IncreaseRelativeMove->sizePolicy().hasHeightForWidth());
        pushButton_IncreaseRelativeMove->setSizePolicy(sizePolicy1);
        pushButton_IncreaseRelativeMove->setMinimumSize(QSize(32, 102));
        pushButton_IncreaseRelativeMove->setMaximumSize(QSize(32, 102));
        pushButton_IncreaseRelativeMove->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_IncreaseRelativeMove);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_8 = new QSpacerItem(2, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        spinBox_RelativeMove = new QSpinBox(Widget_AxisHorizontalControl);
        spinBox_RelativeMove->setObjectName(QString::fromUtf8("spinBox_RelativeMove"));
        sizePolicy1.setHeightForWidth(spinBox_RelativeMove->sizePolicy().hasHeightForWidth());
        spinBox_RelativeMove->setSizePolicy(sizePolicy1);
        spinBox_RelativeMove->setMinimumSize(QSize(65, 30));
        spinBox_RelativeMove->setMaximumSize(QSize(65, 16777215));
        spinBox_RelativeMove->setFont(font2);
        spinBox_RelativeMove->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_RelativeMove->setMaximum(100000);
        spinBox_RelativeMove->setSingleStep(100);
        spinBox_RelativeMove->setValue(2000);

        verticalLayout_2->addWidget(spinBox_RelativeMove);

        spinBox_RelativeMoveSpeed = new QSpinBox(Widget_AxisHorizontalControl);
        spinBox_RelativeMoveSpeed->setObjectName(QString::fromUtf8("spinBox_RelativeMoveSpeed"));
        spinBox_RelativeMoveSpeed->setMinimumSize(QSize(65, 30));
        spinBox_RelativeMoveSpeed->setMaximumSize(QSize(65, 16777215));
        spinBox_RelativeMoveSpeed->setFont(font2);
        spinBox_RelativeMoveSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_RelativeMoveSpeed->setMaximum(5000);
        spinBox_RelativeMoveSpeed->setSingleStep(10);
        spinBox_RelativeMoveSpeed->setValue(1000);

        verticalLayout_2->addWidget(spinBox_RelativeMoveSpeed);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_9 = new QSpacerItem(2, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);


        horizontalLayout_2->addLayout(horizontalLayout);

        pushButton_DecreaseRelativeMove = new QPushButton(Widget_AxisHorizontalControl);
        pushButton_DecreaseRelativeMove->setObjectName(QString::fromUtf8("pushButton_DecreaseRelativeMove"));
        sizePolicy1.setHeightForWidth(pushButton_DecreaseRelativeMove->sizePolicy().hasHeightForWidth());
        pushButton_DecreaseRelativeMove->setSizePolicy(sizePolicy1);
        pushButton_DecreaseRelativeMove->setMinimumSize(QSize(32, 102));
        pushButton_DecreaseRelativeMove->setMaximumSize(QSize(32, 102));
        pushButton_DecreaseRelativeMove->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_DecreaseRelativeMove);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);


        retranslateUi(Widget_AxisHorizontalControl);

        QMetaObject::connectSlotsByName(Widget_AxisHorizontalControl);
    } // setupUi

    void retranslateUi(QWidget *Widget_AxisHorizontalControl)
    {
        Widget_AxisHorizontalControl->setWindowTitle(QApplication::translate("Widget_AxisHorizontalControl", "Form", nullptr));
        label_ManualControl_3->setText(QApplication::translate("Widget_AxisHorizontalControl", "Jog  (um/sec)", nullptr));
        pushButton_IncreaseJog->setText(QApplication::translate("Widget_AxisHorizontalControl", "I", nullptr));
        pushButton_DecreaseJog->setText(QApplication::translate("Widget_AxisHorizontalControl", "D", nullptr));
        label_ManualControl_4->setText(QApplication::translate("Widget_AxisHorizontalControl", "Step (um | um/sec)", nullptr));
        pushButton_IncreaseRelativeMove->setText(QApplication::translate("Widget_AxisHorizontalControl", "I", nullptr));
#ifndef QT_NO_TOOLTIP
        spinBox_RelativeMoveSpeed->setToolTip(QApplication::translate("Widget_AxisHorizontalControl", "Testing1", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        spinBox_RelativeMoveSpeed->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        pushButton_DecreaseRelativeMove->setText(QApplication::translate("Widget_AxisHorizontalControl", "D", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_AxisHorizontalControl: public Ui_Widget_AxisHorizontalControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_AXIS_HORIZONTAL_CONTROL_H
