/********************************************************************************
** Form generated from reading UI file 'widget_front_panel_axis_motion_control.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_FRONT_PANEL_AXIS_MOTION_CONTROL_H
#define UI_WIDGET_FRONT_PANEL_AXIS_MOTION_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetFrontPanel_AxisMotionControl
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_ManualControl;
    QLabel *label_AxisControl;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_MachinePosition;
    QFrame *frame;
    QGridLayout *gridLayout_4;

    void setupUi(QWidget *WidgetFrontPanel_AxisMotionControl)
    {
        if (WidgetFrontPanel_AxisMotionControl->objectName().isEmpty())
            WidgetFrontPanel_AxisMotionControl->setObjectName(QStringLiteral("WidgetFrontPanel_AxisMotionControl"));
        WidgetFrontPanel_AxisMotionControl->resize(368, 234);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetFrontPanel_AxisMotionControl->sizePolicy().hasHeightForWidth());
        WidgetFrontPanel_AxisMotionControl->setSizePolicy(sizePolicy);
        WidgetFrontPanel_AxisMotionControl->setMinimumSize(QSize(368, 234));
        WidgetFrontPanel_AxisMotionControl->setMaximumSize(QSize(368, 234));
        gridLayout = new QGridLayout(WidgetFrontPanel_AxisMotionControl);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_ManualControl = new QLabel(WidgetFrontPanel_AxisMotionControl);
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
        label_ManualControl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_ManualControl);

        label_AxisControl = new QLabel(WidgetFrontPanel_AxisMotionControl);
        label_AxisControl->setObjectName(QStringLiteral("label_AxisControl"));
        sizePolicy1.setHeightForWidth(label_AxisControl->sizePolicy().hasHeightForWidth());
        label_AxisControl->setSizePolicy(sizePolicy1);
        label_AxisControl->setMinimumSize(QSize(0, 20));
        label_AxisControl->setMaximumSize(QSize(16777215, 20));
        label_AxisControl->setFont(font);
        label_AxisControl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_AxisControl);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(WidgetFrontPanel_AxisMotionControl);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(130, 25));
        label->setMaximumSize(QSize(130, 25));
        QFont font1;
        font1.setPointSize(10);
        label->setFont(font1);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEdit_MachinePosition = new QLineEdit(WidgetFrontPanel_AxisMotionControl);
        lineEdit_MachinePosition->setObjectName(QStringLiteral("lineEdit_MachinePosition"));
        lineEdit_MachinePosition->setMinimumSize(QSize(190, 25));
        lineEdit_MachinePosition->setMaximumSize(QSize(190, 25));
        lineEdit_MachinePosition->setFont(font1);
        lineEdit_MachinePosition->setAlignment(Qt::AlignCenter);
        lineEdit_MachinePosition->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_MachinePosition, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 0, 1, 1);

        frame = new QFrame(WidgetFrontPanel_AxisMotionControl);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(355, 155));
        frame->setMaximumSize(QSize(355, 155));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));

        gridLayout->addWidget(frame, 2, 0, 1, 1);


        retranslateUi(WidgetFrontPanel_AxisMotionControl);

        QMetaObject::connectSlotsByName(WidgetFrontPanel_AxisMotionControl);
    } // setupUi

    void retranslateUi(QWidget *WidgetFrontPanel_AxisMotionControl)
    {
        WidgetFrontPanel_AxisMotionControl->setWindowTitle(QApplication::translate("WidgetFrontPanel_AxisMotionControl", "Form", nullptr));
        label_ManualControl->setText(QApplication::translate("WidgetFrontPanel_AxisMotionControl", "Axis: ", nullptr));
        label_AxisControl->setText(QApplication::translate("WidgetFrontPanel_AxisMotionControl", "?", nullptr));
        label->setText(QApplication::translate("WidgetFrontPanel_AxisMotionControl", "Current Position (um):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetFrontPanel_AxisMotionControl: public Ui_WidgetFrontPanel_AxisMotionControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_FRONT_PANEL_AXIS_MOTION_CONTROL_H
