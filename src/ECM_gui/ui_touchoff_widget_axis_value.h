/********************************************************************************
** Form generated from reading UI file 'touchoff_widget_axis_value.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOUCHOFF_WIDGET_AXIS_VALUE_H
#define UI_TOUCHOFF_WIDGET_AXIS_VALUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TouchoffWidget_AxisValue
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBox_TouchoffRef;

    void setupUi(QWidget *TouchoffWidget_AxisValue)
    {
        if (TouchoffWidget_AxisValue->objectName().isEmpty())
            TouchoffWidget_AxisValue->setObjectName(QString::fromUtf8("TouchoffWidget_AxisValue"));
        TouchoffWidget_AxisValue->resize(102, 27);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TouchoffWidget_AxisValue->sizePolicy().hasHeightForWidth());
        TouchoffWidget_AxisValue->setSizePolicy(sizePolicy);
        TouchoffWidget_AxisValue->setMinimumSize(QSize(102, 27));
        TouchoffWidget_AxisValue->setMaximumSize(QSize(102, 27));
        gridLayout_2 = new QGridLayout(TouchoffWidget_AxisValue);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        doubleSpinBox_TouchoffRef = new QDoubleSpinBox(TouchoffWidget_AxisValue);
        doubleSpinBox_TouchoffRef->setObjectName(QString::fromUtf8("doubleSpinBox_TouchoffRef"));
        sizePolicy.setHeightForWidth(doubleSpinBox_TouchoffRef->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TouchoffRef->setSizePolicy(sizePolicy);
        doubleSpinBox_TouchoffRef->setMinimumSize(QSize(100, 25));
        doubleSpinBox_TouchoffRef->setMaximumSize(QSize(100, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(11);
        doubleSpinBox_TouchoffRef->setFont(font);
        doubleSpinBox_TouchoffRef->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_TouchoffRef->setDecimals(1);
        doubleSpinBox_TouchoffRef->setMaximum(500000.000000000000000);

        gridLayout->addWidget(doubleSpinBox_TouchoffRef, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(TouchoffWidget_AxisValue);

        QMetaObject::connectSlotsByName(TouchoffWidget_AxisValue);
    } // setupUi

    void retranslateUi(QWidget *TouchoffWidget_AxisValue)
    {
        TouchoffWidget_AxisValue->setWindowTitle(QApplication::translate("TouchoffWidget_AxisValue", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TouchoffWidget_AxisValue: public Ui_TouchoffWidget_AxisValue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOUCHOFF_WIDGET_AXIS_VALUE_H
