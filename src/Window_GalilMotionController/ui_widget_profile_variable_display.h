/********************************************************************************
** Form generated from reading UI file 'widget_profile_variable_display.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_PROFILE_VARIABLE_DISPLAY_H
#define UI_WIDGET_PROFILE_VARIABLE_DISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetProfileVariableDisplay
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label_displayName;
    QDoubleSpinBox *doubleSpinBox_desiredValue;

    void setupUi(QWidget *WidgetProfileVariableDisplay)
    {
        if (WidgetProfileVariableDisplay->objectName().isEmpty())
            WidgetProfileVariableDisplay->setObjectName(QStringLiteral("WidgetProfileVariableDisplay"));
        WidgetProfileVariableDisplay->resize(210, 47);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetProfileVariableDisplay->sizePolicy().hasHeightForWidth());
        WidgetProfileVariableDisplay->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(WidgetProfileVariableDisplay);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_displayName = new QLabel(WidgetProfileVariableDisplay);
        label_displayName->setObjectName(QStringLiteral("label_displayName"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_displayName->sizePolicy().hasHeightForWidth());
        label_displayName->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(12);
        label_displayName->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_displayName);

        doubleSpinBox_desiredValue = new QDoubleSpinBox(WidgetProfileVariableDisplay);
        doubleSpinBox_desiredValue->setObjectName(QStringLiteral("doubleSpinBox_desiredValue"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(doubleSpinBox_desiredValue->sizePolicy().hasHeightForWidth());
        doubleSpinBox_desiredValue->setSizePolicy(sizePolicy2);
        doubleSpinBox_desiredValue->setFont(font);
        doubleSpinBox_desiredValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_desiredValue->setDecimals(3);

        formLayout->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_desiredValue);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);


        retranslateUi(WidgetProfileVariableDisplay);

        QMetaObject::connectSlotsByName(WidgetProfileVariableDisplay);
    } // setupUi

    void retranslateUi(QWidget *WidgetProfileVariableDisplay)
    {
        WidgetProfileVariableDisplay->setWindowTitle(QApplication::translate("WidgetProfileVariableDisplay", "Form", nullptr));
        label_displayName->setText(QApplication::translate("WidgetProfileVariableDisplay", "Display Name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetProfileVariableDisplay: public Ui_WidgetProfileVariableDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_PROFILE_VARIABLE_DISPLAY_H
