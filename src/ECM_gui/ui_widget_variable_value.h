/********************************************************************************
** Form generated from reading UI file 'widget_variable_value.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_VARIABLE_VALUE_H
#define UI_WIDGET_VARIABLE_VALUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_VariableValue
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label_VariableName;
    QSpinBox *spinBox_VariableValue;

    void setupUi(QWidget *Widget_VariableValue)
    {
        if (Widget_VariableValue->objectName().isEmpty())
            Widget_VariableValue->setObjectName(QStringLiteral("Widget_VariableValue"));
        Widget_VariableValue->resize(247, 27);
        gridLayout = new QGridLayout(Widget_VariableValue);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(0);
        label_VariableName = new QLabel(Widget_VariableValue);
        label_VariableName->setObjectName(QStringLiteral("label_VariableName"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_VariableName->sizePolicy().hasHeightForWidth());
        label_VariableName->setSizePolicy(sizePolicy);
        label_VariableName->setMinimumSize(QSize(145, 25));
        label_VariableName->setMaximumSize(QSize(145, 25));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_VariableName->setFont(font);
        label_VariableName->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_VariableName);

        spinBox_VariableValue = new QSpinBox(Widget_VariableValue);
        spinBox_VariableValue->setObjectName(QStringLiteral("spinBox_VariableValue"));
        sizePolicy.setHeightForWidth(spinBox_VariableValue->sizePolicy().hasHeightForWidth());
        spinBox_VariableValue->setSizePolicy(sizePolicy);
        spinBox_VariableValue->setMinimumSize(QSize(100, 25));
        QFont font1;
        font1.setPointSize(10);
        spinBox_VariableValue->setFont(font1);
        spinBox_VariableValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_VariableValue->setMinimum(0);
        spinBox_VariableValue->setMaximum(10000);
        spinBox_VariableValue->setSingleStep(10);
        spinBox_VariableValue->setValue(0);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox_VariableValue);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);


        retranslateUi(Widget_VariableValue);

        QMetaObject::connectSlotsByName(Widget_VariableValue);
    } // setupUi

    void retranslateUi(QWidget *Widget_VariableValue)
    {
        Widget_VariableValue->setWindowTitle(QApplication::translate("Widget_VariableValue", "Form", nullptr));
        label_VariableName->setText(QApplication::translate("Widget_VariableValue", "Variable Value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_VariableValue: public Ui_Widget_VariableValue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_VARIABLE_VALUE_H
