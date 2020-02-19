/********************************************************************************
** Form generated from reading UI file 'widget_front_panel_motion_control.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_FRONT_PANEL_MOTION_CONTROL_H
#define UI_WIDGET_FRONT_PANEL_MOTION_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetFrontPanel_MotionControl
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;

    void setupUi(QWidget *WidgetFrontPanel_MotionControl)
    {
        if (WidgetFrontPanel_MotionControl->objectName().isEmpty())
            WidgetFrontPanel_MotionControl->setObjectName(QString::fromUtf8("WidgetFrontPanel_MotionControl"));
        WidgetFrontPanel_MotionControl->resize(375, 216);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetFrontPanel_MotionControl->sizePolicy().hasHeightForWidth());
        WidgetFrontPanel_MotionControl->setSizePolicy(sizePolicy);
        WidgetFrontPanel_MotionControl->setMinimumSize(QSize(375, 100));
        WidgetFrontPanel_MotionControl->setMaximumSize(QSize(375, 16777215));
        gridLayout = new QGridLayout(WidgetFrontPanel_MotionControl);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 1, 1);
        tabWidget = new QTabWidget(WidgetFrontPanel_MotionControl);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(WidgetFrontPanel_MotionControl);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(WidgetFrontPanel_MotionControl);
    } // setupUi

    void retranslateUi(QWidget *WidgetFrontPanel_MotionControl)
    {
        WidgetFrontPanel_MotionControl->setWindowTitle(QApplication::translate("WidgetFrontPanel_MotionControl", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetFrontPanel_MotionControl: public Ui_WidgetFrontPanel_MotionControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_FRONT_PANEL_MOTION_CONTROL_H
