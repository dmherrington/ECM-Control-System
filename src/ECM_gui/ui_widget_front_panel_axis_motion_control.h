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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetFrontPanel_AxisMotionControl
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_MachinePosition;
    QFrame *frame;
    QGridLayout *gridLayout_4;

    void setupUi(QWidget *WidgetFrontPanel_AxisMotionControl)
    {
        if (WidgetFrontPanel_AxisMotionControl->objectName().isEmpty())
            WidgetFrontPanel_AxisMotionControl->setObjectName(QStringLiteral("WidgetFrontPanel_AxisMotionControl"));
        WidgetFrontPanel_AxisMotionControl->resize(368, 185);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetFrontPanel_AxisMotionControl->sizePolicy().hasHeightForWidth());
        WidgetFrontPanel_AxisMotionControl->setSizePolicy(sizePolicy);
        WidgetFrontPanel_AxisMotionControl->setMinimumSize(QSize(368, 185));
        WidgetFrontPanel_AxisMotionControl->setMaximumSize(QSize(368, 185));
        gridLayout = new QGridLayout(WidgetFrontPanel_AxisMotionControl);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 1, 1);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(WidgetFrontPanel_AxisMotionControl);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(130, 25));
        label->setMaximumSize(QSize(130, 25));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEdit_MachinePosition = new QLineEdit(WidgetFrontPanel_AxisMotionControl);
        lineEdit_MachinePosition->setObjectName(QStringLiteral("lineEdit_MachinePosition"));
        lineEdit_MachinePosition->setMinimumSize(QSize(190, 25));
        lineEdit_MachinePosition->setMaximumSize(QSize(190, 25));
        lineEdit_MachinePosition->setFont(font);
        lineEdit_MachinePosition->setAlignment(Qt::AlignCenter);
        lineEdit_MachinePosition->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_MachinePosition, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        frame = new QFrame(WidgetFrontPanel_AxisMotionControl);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(355, 155));
        frame->setMaximumSize(QSize(355, 155));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(frame, 1, 0, 1, 1);


        retranslateUi(WidgetFrontPanel_AxisMotionControl);

        QMetaObject::connectSlotsByName(WidgetFrontPanel_AxisMotionControl);
    } // setupUi

    void retranslateUi(QWidget *WidgetFrontPanel_AxisMotionControl)
    {
        WidgetFrontPanel_AxisMotionControl->setWindowTitle(QApplication::translate("WidgetFrontPanel_AxisMotionControl", "Form", nullptr));
        label->setText(QApplication::translate("WidgetFrontPanel_AxisMotionControl", "Current Position (um):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetFrontPanel_AxisMotionControl: public Ui_WidgetFrontPanel_AxisMotionControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_FRONT_PANEL_AXIS_MOTION_CONTROL_H
