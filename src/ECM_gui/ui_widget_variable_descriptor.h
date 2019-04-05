/********************************************************************************
** Form generated from reading UI file 'widget_variable_descriptor.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_VARIABLE_DESCRIPTOR_H
#define UI_WIDGET_VARIABLE_DESCRIPTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_VariableDescriptor
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_VariableName;
    QDoubleSpinBox *doubleSpinBox_VariableValue;

    void setupUi(QWidget *Widget_VariableDescriptor)
    {
        if (Widget_VariableDescriptor->objectName().isEmpty())
            Widget_VariableDescriptor->setObjectName(QStringLiteral("Widget_VariableDescriptor"));
        Widget_VariableDescriptor->resize(226, 40);
        gridLayout = new QGridLayout(Widget_VariableDescriptor);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_VariableName = new QLabel(Widget_VariableDescriptor);
        label_VariableName->setObjectName(QStringLiteral("label_VariableName"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_VariableName->sizePolicy().hasHeightForWidth());
        label_VariableName->setSizePolicy(sizePolicy);
        label_VariableName->setMinimumSize(QSize(120, 20));
        label_VariableName->setMaximumSize(QSize(120, 20));
        QFont font;
        font.setPointSize(10);
        label_VariableName->setFont(font);

        horizontalLayout->addWidget(label_VariableName);

        doubleSpinBox_VariableValue = new QDoubleSpinBox(Widget_VariableDescriptor);
        doubleSpinBox_VariableValue->setObjectName(QStringLiteral("doubleSpinBox_VariableValue"));
        doubleSpinBox_VariableValue->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(doubleSpinBox_VariableValue->sizePolicy().hasHeightForWidth());
        doubleSpinBox_VariableValue->setSizePolicy(sizePolicy1);
        doubleSpinBox_VariableValue->setMinimumSize(QSize(80, 20));
        doubleSpinBox_VariableValue->setMaximumSize(QSize(80, 20));
        doubleSpinBox_VariableValue->setFont(font);
        doubleSpinBox_VariableValue->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(doubleSpinBox_VariableValue);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Widget_VariableDescriptor);

        QMetaObject::connectSlotsByName(Widget_VariableDescriptor);
    } // setupUi

    void retranslateUi(QWidget *Widget_VariableDescriptor)
    {
        Widget_VariableDescriptor->setWindowTitle(QApplication::translate("Widget_VariableDescriptor", "Form", nullptr));
        label_VariableName->setText(QApplication::translate("Widget_VariableDescriptor", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_VariableDescriptor: public Ui_Widget_VariableDescriptor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_VARIABLE_DESCRIPTOR_H
