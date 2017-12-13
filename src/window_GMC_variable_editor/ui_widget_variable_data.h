/********************************************************************************
** Form generated from reading UI file 'widget_variable_data.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_VARIABLE_DATA_H
#define UI_WIDGET_VARIABLE_DATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetVariableData
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_max;
    QDoubleSpinBox *doubleSpinBox_min;
    QDoubleSpinBox *doubleSpinBox_default;
    QPushButton *pushButton_removeVariable;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEdit_displayName;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLineEdit *lineEdit_varName;
    QSpacerItem *horizontalSpacer;
    QFrame *line;

    void setupUi(QWidget *WidgetVariableData)
    {
        if (WidgetVariableData->objectName().isEmpty())
            WidgetVariableData->setObjectName(QStringLiteral("WidgetVariableData"));
        WidgetVariableData->resize(580, 113);
        gridLayout = new QGridLayout(WidgetVariableData);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(WidgetVariableData);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(WidgetVariableData);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(WidgetVariableData);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        doubleSpinBox_max = new QDoubleSpinBox(WidgetVariableData);
        doubleSpinBox_max->setObjectName(QStringLiteral("doubleSpinBox_max"));
        doubleSpinBox_max->setMinimumSize(QSize(100, 0));
        doubleSpinBox_max->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_max);

        doubleSpinBox_min = new QDoubleSpinBox(WidgetVariableData);
        doubleSpinBox_min->setObjectName(QStringLiteral("doubleSpinBox_min"));
        doubleSpinBox_min->setMinimumSize(QSize(100, 0));
        doubleSpinBox_min->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, doubleSpinBox_min);

        doubleSpinBox_default = new QDoubleSpinBox(WidgetVariableData);
        doubleSpinBox_default->setObjectName(QStringLiteral("doubleSpinBox_default"));
        doubleSpinBox_default->setMinimumSize(QSize(100, 0));
        doubleSpinBox_default->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox_default);


        gridLayout->addLayout(formLayout, 0, 2, 1, 1);

        pushButton_removeVariable = new QPushButton(WidgetVariableData);
        pushButton_removeVariable->setObjectName(QStringLiteral("pushButton_removeVariable"));

        gridLayout->addWidget(pushButton_removeVariable, 0, 3, 1, 1);

        verticalSpacer = new QSpacerItem(181, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_4 = new QLabel(WidgetVariableData);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(131, 0));
        QFont font1;
        font1.setPointSize(12);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_4);

        lineEdit_displayName = new QLineEdit(WidgetVariableData);
        lineEdit_displayName->setObjectName(QStringLiteral("lineEdit_displayName"));
        sizePolicy1.setHeightForWidth(lineEdit_displayName->sizePolicy().hasHeightForWidth());
        lineEdit_displayName->setSizePolicy(sizePolicy1);
        lineEdit_displayName->setMinimumSize(QSize(100, 0));
        lineEdit_displayName->setFont(font);

        verticalLayout_2->addWidget(lineEdit_displayName);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_5 = new QLabel(WidgetVariableData);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(131, 0));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_5);

        lineEdit_varName = new QLineEdit(WidgetVariableData);
        lineEdit_varName->setObjectName(QStringLiteral("lineEdit_varName"));
        sizePolicy1.setHeightForWidth(lineEdit_varName->sizePolicy().hasHeightForWidth());
        lineEdit_varName->setSizePolicy(sizePolicy1);
        lineEdit_varName->setMinimumSize(QSize(100, 0));
        lineEdit_varName->setFont(font);
        lineEdit_varName->setMaxLength(7);
        lineEdit_varName->setFrame(true);
        lineEdit_varName->setClearButtonEnabled(false);

        verticalLayout->addWidget(lineEdit_varName);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 4, 1, 1);

        line = new QFrame(WidgetVariableData);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 5);


        retranslateUi(WidgetVariableData);

        QMetaObject::connectSlotsByName(WidgetVariableData);
    } // setupUi

    void retranslateUi(QWidget *WidgetVariableData)
    {
        WidgetVariableData->setWindowTitle(QApplication::translate("WidgetVariableData", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("WidgetVariableData", "Max Value", Q_NULLPTR));
        label_2->setText(QApplication::translate("WidgetVariableData", "Min Value", Q_NULLPTR));
        label_3->setText(QApplication::translate("WidgetVariableData", "Default Value", Q_NULLPTR));
        pushButton_removeVariable->setText(QApplication::translate("WidgetVariableData", "Remove Variable", Q_NULLPTR));
        label_4->setText(QApplication::translate("WidgetVariableData", "Display Name", Q_NULLPTR));
        lineEdit_displayName->setPlaceholderText(QString());
        label_5->setText(QApplication::translate("WidgetVariableData", "Variable Name", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetVariableData: public Ui_WidgetVariableData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_VARIABLE_DATA_H
