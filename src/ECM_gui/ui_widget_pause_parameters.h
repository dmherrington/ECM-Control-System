/********************************************************************************
** Form generated from reading UI file 'widget_pause_parameters.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_PAUSE_PARAMETERS_H
#define UI_WIDGET_PAUSE_PARAMETERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_PauseParameters
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_Pump;
    QGridLayout *gridLayout_17;
    QFrame *frame_ScriptingVariables;
    QGridLayout *gridLayout_8;
    QFrame *frame_Touchoff;
    QGridLayout *gridLayout_14;
    QFrame *frame_PowerSupply;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_infinite;
    QRadioButton *radioButton_finite;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *doubleSpinBox_duration;
    QLabel *label;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Widget_PauseParameters)
    {
        if (Widget_PauseParameters->objectName().isEmpty())
            Widget_PauseParameters->setObjectName(QString::fromUtf8("Widget_PauseParameters"));
        Widget_PauseParameters->resize(1200, 560);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_PauseParameters->sizePolicy().hasHeightForWidth());
        Widget_PauseParameters->setSizePolicy(sizePolicy);
        Widget_PauseParameters->setMinimumSize(QSize(1200, 560));
        Widget_PauseParameters->setMaximumSize(QSize(1200, 560));
        gridLayout = new QGridLayout(Widget_PauseParameters);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_Pump = new QFrame(Widget_PauseParameters);
        frame_Pump->setObjectName(QString::fromUtf8("frame_Pump"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_Pump->sizePolicy().hasHeightForWidth());
        frame_Pump->setSizePolicy(sizePolicy1);
        frame_Pump->setMinimumSize(QSize(580, 170));
        frame_Pump->setMaximumSize(QSize(580, 170));
        frame_Pump->setFrameShape(QFrame::Box);
        frame_Pump->setFrameShadow(QFrame::Plain);
        frame_Pump->setLineWidth(2);
        gridLayout_17 = new QGridLayout(frame_Pump);
        gridLayout_17->setSpacing(0);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(frame_Pump, 1, 1, 1, 1);

        frame_ScriptingVariables = new QFrame(Widget_PauseParameters);
        frame_ScriptingVariables->setObjectName(QString::fromUtf8("frame_ScriptingVariables"));
        sizePolicy1.setHeightForWidth(frame_ScriptingVariables->sizePolicy().hasHeightForWidth());
        frame_ScriptingVariables->setSizePolicy(sizePolicy1);
        frame_ScriptingVariables->setMinimumSize(QSize(580, 340));
        frame_ScriptingVariables->setMaximumSize(QSize(580, 340));
        frame_ScriptingVariables->setFrameShape(QFrame::Box);
        frame_ScriptingVariables->setFrameShadow(QFrame::Plain);
        frame_ScriptingVariables->setLineWidth(2);
        gridLayout_8 = new QGridLayout(frame_ScriptingVariables);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(frame_ScriptingVariables, 0, 1, 1, 1);

        frame_Touchoff = new QFrame(Widget_PauseParameters);
        frame_Touchoff->setObjectName(QString::fromUtf8("frame_Touchoff"));
        sizePolicy1.setHeightForWidth(frame_Touchoff->sizePolicy().hasHeightForWidth());
        frame_Touchoff->setSizePolicy(sizePolicy1);
        frame_Touchoff->setMinimumSize(QSize(580, 170));
        frame_Touchoff->setMaximumSize(QSize(580, 170));
        frame_Touchoff->setFrameShape(QFrame::Box);
        frame_Touchoff->setFrameShadow(QFrame::Plain);
        frame_Touchoff->setLineWidth(2);
        gridLayout_14 = new QGridLayout(frame_Touchoff);
        gridLayout_14->setSpacing(0);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(frame_Touchoff, 1, 0, 1, 1);

        frame_PowerSupply = new QFrame(Widget_PauseParameters);
        frame_PowerSupply->setObjectName(QString::fromUtf8("frame_PowerSupply"));
        sizePolicy1.setHeightForWidth(frame_PowerSupply->sizePolicy().hasHeightForWidth());
        frame_PowerSupply->setSizePolicy(sizePolicy1);
        frame_PowerSupply->setMinimumSize(QSize(580, 340));
        frame_PowerSupply->setMaximumSize(QSize(580, 340));
        frame_PowerSupply->setFrameShape(QFrame::Box);
        frame_PowerSupply->setFrameShadow(QFrame::Plain);
        frame_PowerSupply->setLineWidth(2);
        gridLayout_3 = new QGridLayout(frame_PowerSupply);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(frame_PowerSupply);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton_infinite = new QRadioButton(groupBox);
        radioButton_infinite->setObjectName(QString::fromUtf8("radioButton_infinite"));
        sizePolicy.setHeightForWidth(radioButton_infinite->sizePolicy().hasHeightForWidth());
        radioButton_infinite->setSizePolicy(sizePolicy);
        radioButton_infinite->setMinimumSize(QSize(100, 30));
        radioButton_infinite->setMaximumSize(QSize(100, 30));
        radioButton_infinite->setChecked(true);

        horizontalLayout->addWidget(radioButton_infinite);

        radioButton_finite = new QRadioButton(groupBox);
        radioButton_finite->setObjectName(QString::fromUtf8("radioButton_finite"));
        radioButton_finite->setEnabled(false);
        sizePolicy.setHeightForWidth(radioButton_finite->sizePolicy().hasHeightForWidth());
        radioButton_finite->setSizePolicy(sizePolicy);
        radioButton_finite->setMinimumSize(QSize(120, 30));
        radioButton_finite->setMaximumSize(QSize(120, 30));

        horizontalLayout->addWidget(radioButton_finite);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        doubleSpinBox_duration = new QDoubleSpinBox(groupBox);
        doubleSpinBox_duration->setObjectName(QString::fromUtf8("doubleSpinBox_duration"));
        doubleSpinBox_duration->setEnabled(false);
        sizePolicy.setHeightForWidth(doubleSpinBox_duration->sizePolicy().hasHeightForWidth());
        doubleSpinBox_duration->setSizePolicy(sizePolicy);
        doubleSpinBox_duration->setMinimumSize(QSize(100, 30));
        doubleSpinBox_duration->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_duration->setDecimals(0);
        doubleSpinBox_duration->setMaximum(1000.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_duration);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 241, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout->addWidget(frame_PowerSupply, 0, 0, 1, 1);


        retranslateUi(Widget_PauseParameters);

        QMetaObject::connectSlotsByName(Widget_PauseParameters);
    } // setupUi

    void retranslateUi(QWidget *Widget_PauseParameters)
    {
        Widget_PauseParameters->setWindowTitle(QApplication::translate("Widget_PauseParameters", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("Widget_PauseParameters", "Pause Options", nullptr));
        radioButton_infinite->setText(QApplication::translate("Widget_PauseParameters", "Infinite", nullptr));
        radioButton_finite->setText(QApplication::translate("Widget_PauseParameters", "Finite Duration", nullptr));
        label->setText(QApplication::translate("Widget_PauseParameters", "ms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_PauseParameters: public Ui_Widget_PauseParameters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_PAUSE_PARAMETERS_H
