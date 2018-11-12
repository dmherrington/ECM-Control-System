/********************************************************************************
** Form generated from reading UI file 'widget_profile_parameters.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_PROFILE_PARAMETERS_H
#define UI_WIDGET_PROFILE_PARAMETERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_ProfileParameters
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_PowerSupply;
    QGridLayout *gridLayout_10;
    QFrame *frame_ScriptingVariables;
    QGridLayout *gridLayout_8;
    QFrame *frame_Touchoff;
    QGridLayout *gridLayout_14;
    QFrame *frame_Pump;
    QGridLayout *gridLayout_17;

    void setupUi(QWidget *Widget_ProfileParameters)
    {
        if (Widget_ProfileParameters->objectName().isEmpty())
            Widget_ProfileParameters->setObjectName(QStringLiteral("Widget_ProfileParameters"));
        Widget_ProfileParameters->resize(1130, 560);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_ProfileParameters->sizePolicy().hasHeightForWidth());
        Widget_ProfileParameters->setSizePolicy(sizePolicy);
        Widget_ProfileParameters->setMinimumSize(QSize(1130, 560));
        Widget_ProfileParameters->setMaximumSize(QSize(1200, 560));
        gridLayout = new QGridLayout(Widget_ProfileParameters);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame_PowerSupply = new QFrame(Widget_ProfileParameters);
        frame_PowerSupply->setObjectName(QStringLiteral("frame_PowerSupply"));
        sizePolicy.setHeightForWidth(frame_PowerSupply->sizePolicy().hasHeightForWidth());
        frame_PowerSupply->setSizePolicy(sizePolicy);
        frame_PowerSupply->setMinimumSize(QSize(575, 340));
        frame_PowerSupply->setMaximumSize(QSize(575, 340));
        frame_PowerSupply->setFrameShape(QFrame::Box);
        frame_PowerSupply->setFrameShadow(QFrame::Plain);
        frame_PowerSupply->setLineWidth(2);
        gridLayout_10 = new QGridLayout(frame_PowerSupply);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(frame_PowerSupply, 0, 0, 1, 1);

        frame_ScriptingVariables = new QFrame(Widget_ProfileParameters);
        frame_ScriptingVariables->setObjectName(QStringLiteral("frame_ScriptingVariables"));
        sizePolicy.setHeightForWidth(frame_ScriptingVariables->sizePolicy().hasHeightForWidth());
        frame_ScriptingVariables->setSizePolicy(sizePolicy);
        frame_ScriptingVariables->setMinimumSize(QSize(525, 340));
        frame_ScriptingVariables->setMaximumSize(QSize(525, 340));
        frame_ScriptingVariables->setFrameShape(QFrame::Box);
        frame_ScriptingVariables->setFrameShadow(QFrame::Plain);
        frame_ScriptingVariables->setLineWidth(2);
        gridLayout_8 = new QGridLayout(frame_ScriptingVariables);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(frame_ScriptingVariables, 0, 1, 1, 1);

        frame_Touchoff = new QFrame(Widget_ProfileParameters);
        frame_Touchoff->setObjectName(QStringLiteral("frame_Touchoff"));
        sizePolicy.setHeightForWidth(frame_Touchoff->sizePolicy().hasHeightForWidth());
        frame_Touchoff->setSizePolicy(sizePolicy);
        frame_Touchoff->setMinimumSize(QSize(525, 170));
        frame_Touchoff->setMaximumSize(QSize(575, 170));
        frame_Touchoff->setFrameShape(QFrame::Box);
        frame_Touchoff->setFrameShadow(QFrame::Plain);
        frame_Touchoff->setLineWidth(2);
        gridLayout_14 = new QGridLayout(frame_Touchoff);
        gridLayout_14->setSpacing(0);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(frame_Touchoff, 1, 0, 1, 1);

        frame_Pump = new QFrame(Widget_ProfileParameters);
        frame_Pump->setObjectName(QStringLiteral("frame_Pump"));
        sizePolicy.setHeightForWidth(frame_Pump->sizePolicy().hasHeightForWidth());
        frame_Pump->setSizePolicy(sizePolicy);
        frame_Pump->setMinimumSize(QSize(525, 170));
        frame_Pump->setMaximumSize(QSize(525, 170));
        frame_Pump->setFrameShape(QFrame::Box);
        frame_Pump->setFrameShadow(QFrame::Plain);
        frame_Pump->setLineWidth(2);
        gridLayout_17 = new QGridLayout(frame_Pump);
        gridLayout_17->setSpacing(0);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(frame_Pump, 1, 1, 1, 1);


        retranslateUi(Widget_ProfileParameters);

        QMetaObject::connectSlotsByName(Widget_ProfileParameters);
    } // setupUi

    void retranslateUi(QWidget *Widget_ProfileParameters)
    {
        Widget_ProfileParameters->setWindowTitle(QApplication::translate("Widget_ProfileParameters", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_ProfileParameters: public Ui_Widget_ProfileParameters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_PROFILE_PARAMETERS_H
