/********************************************************************************
** Form generated from reading UI file 'widget_variable_edit.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_VARIABLE_EDIT_H
#define UI_WIDGET_VARIABLE_EDIT_H

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

class Ui_Widget_VariableEdit
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label_VariableName;
    QSpinBox *spinBox_VariableValue;

    void setupUi(QWidget *Widget_VariableEdit)
    {
        if (Widget_VariableEdit->objectName().isEmpty())
            Widget_VariableEdit->setObjectName(QStringLiteral("Widget_VariableEdit"));
        Widget_VariableEdit->resize(255, 30);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_VariableEdit->sizePolicy().hasHeightForWidth());
        Widget_VariableEdit->setSizePolicy(sizePolicy);
        Widget_VariableEdit->setMinimumSize(QSize(255, 30));
        Widget_VariableEdit->setMaximumSize(QSize(255, 30));
        gridLayout = new QGridLayout(Widget_VariableEdit);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_VariableName = new QLabel(Widget_VariableEdit);
        label_VariableName->setObjectName(QStringLiteral("label_VariableName"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_VariableName->sizePolicy().hasHeightForWidth());
        label_VariableName->setSizePolicy(sizePolicy1);
        label_VariableName->setMinimumSize(QSize(145, 25));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_VariableName->setFont(font);
        label_VariableName->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_VariableName);

        spinBox_VariableValue = new QSpinBox(Widget_VariableEdit);
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


        retranslateUi(Widget_VariableEdit);

        QMetaObject::connectSlotsByName(Widget_VariableEdit);
    } // setupUi

    void retranslateUi(QWidget *Widget_VariableEdit)
    {
        Widget_VariableEdit->setWindowTitle(QApplication::translate("Widget_VariableEdit", "Form", nullptr));
        label_VariableName->setText(QApplication::translate("Widget_VariableEdit", "Variable Value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_VariableEdit: public Ui_Widget_VariableEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_VARIABLE_EDIT_H
