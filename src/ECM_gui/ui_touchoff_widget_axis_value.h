/********************************************************************************
** Form generated from reading UI file 'touchoff_widget_axis_value.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOUCHOFF_WIDGET_AXIS_VALUE_H
#define UI_TOUCHOFF_WIDGET_AXIS_VALUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TouchoffWidget_AxisValue
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Axis;
    QSpacerItem *horizontalSpacer_3;
    QDoubleSpinBox *doubleSpinBox_TouchoffGap;
    QSpacerItem *horizontalSpacer;
    QDoubleSpinBox *doubleSpinBox_TouchoffRef;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_DirectionP;
    QLabel *label;
    QRadioButton *radioButton_DirectionM;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_Run;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *TouchoffWidget_AxisValue)
    {
        if (TouchoffWidget_AxisValue->objectName().isEmpty())
            TouchoffWidget_AxisValue->setObjectName(QStringLiteral("TouchoffWidget_AxisValue"));
        TouchoffWidget_AxisValue->resize(350, 28);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TouchoffWidget_AxisValue->sizePolicy().hasHeightForWidth());
        TouchoffWidget_AxisValue->setSizePolicy(sizePolicy);
        TouchoffWidget_AxisValue->setMinimumSize(QSize(350, 28));
        TouchoffWidget_AxisValue->setMaximumSize(QSize(350, 28));
        gridLayout = new QGridLayout(TouchoffWidget_AxisValue);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_Axis = new QLabel(TouchoffWidget_AxisValue);
        label_Axis->setObjectName(QStringLiteral("label_Axis"));
        label_Axis->setMinimumSize(QSize(20, 0));
        label_Axis->setMaximumSize(QSize(20, 16777215));
        QFont font;
        font.setPointSize(11);
        label_Axis->setFont(font);
        label_Axis->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_Axis);

        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        doubleSpinBox_TouchoffGap = new QDoubleSpinBox(TouchoffWidget_AxisValue);
        doubleSpinBox_TouchoffGap->setObjectName(QStringLiteral("doubleSpinBox_TouchoffGap"));
        sizePolicy.setHeightForWidth(doubleSpinBox_TouchoffGap->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TouchoffGap->setSizePolicy(sizePolicy);
        doubleSpinBox_TouchoffGap->setMinimumSize(QSize(80, 25));
        doubleSpinBox_TouchoffGap->setMaximumSize(QSize(80, 25));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(11);
        doubleSpinBox_TouchoffGap->setFont(font1);
        doubleSpinBox_TouchoffGap->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_TouchoffGap->setDecimals(1);
        doubleSpinBox_TouchoffGap->setMaximum(500000);

        horizontalLayout_2->addWidget(doubleSpinBox_TouchoffGap);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        doubleSpinBox_TouchoffRef = new QDoubleSpinBox(TouchoffWidget_AxisValue);
        doubleSpinBox_TouchoffRef->setObjectName(QStringLiteral("doubleSpinBox_TouchoffRef"));
        sizePolicy.setHeightForWidth(doubleSpinBox_TouchoffRef->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TouchoffRef->setSizePolicy(sizePolicy);
        doubleSpinBox_TouchoffRef->setMinimumSize(QSize(80, 25));
        doubleSpinBox_TouchoffRef->setMaximumSize(QSize(80, 25));
        doubleSpinBox_TouchoffRef->setFont(font1);
        doubleSpinBox_TouchoffRef->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_TouchoffRef->setDecimals(1);
        doubleSpinBox_TouchoffRef->setMaximum(500000);

        horizontalLayout_2->addWidget(doubleSpinBox_TouchoffRef);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButton_DirectionP = new QRadioButton(TouchoffWidget_AxisValue);
        radioButton_DirectionP->setObjectName(QStringLiteral("radioButton_DirectionP"));
        radioButton_DirectionP->setMinimumSize(QSize(13, 13));
        radioButton_DirectionP->setMaximumSize(QSize(13, 13));

        horizontalLayout->addWidget(radioButton_DirectionP);

        label = new QLabel(TouchoffWidget_AxisValue);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(16, 13));
        label->setMaximumSize(QSize(16, 13));

        horizontalLayout->addWidget(label);

        radioButton_DirectionM = new QRadioButton(TouchoffWidget_AxisValue);
        radioButton_DirectionM->setObjectName(QStringLiteral("radioButton_DirectionM"));
        radioButton_DirectionM->setMinimumSize(QSize(13, 13));
        radioButton_DirectionM->setMaximumSize(QSize(13, 13));

        horizontalLayout->addWidget(radioButton_DirectionM);


        horizontalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        pushButton_Run = new QPushButton(TouchoffWidget_AxisValue);
        pushButton_Run->setObjectName(QStringLiteral("pushButton_Run"));
        pushButton_Run->setMinimumSize(QSize(50, 25));
        pushButton_Run->setMaximumSize(QSize(50, 25));

        horizontalLayout_3->addWidget(pushButton_Run);

        horizontalSpacer_5 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_3, 0, 1, 1, 1);


        retranslateUi(TouchoffWidget_AxisValue);

        QMetaObject::connectSlotsByName(TouchoffWidget_AxisValue);
    } // setupUi

    void retranslateUi(QWidget *TouchoffWidget_AxisValue)
    {
        TouchoffWidget_AxisValue->setWindowTitle(QApplication::translate("TouchoffWidget_AxisValue", "Form", nullptr));
        label_Axis->setText(QApplication::translate("TouchoffWidget_AxisValue", "TextLabel", nullptr));
        radioButton_DirectionP->setText(QString());
        label->setText(QApplication::translate("TouchoffWidget_AxisValue", "+/-", nullptr));
        radioButton_DirectionM->setText(QString());
        pushButton_Run->setText(QApplication::translate("TouchoffWidget_AxisValue", "RUN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TouchoffWidget_AxisValue: public Ui_TouchoffWidget_AxisValue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOUCHOFF_WIDGET_AXIS_VALUE_H
