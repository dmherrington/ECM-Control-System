/********************************************************************************
** Form generated from reading UI file 'table_widget_operation_descriptor.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_WIDGET_OPERATION_DESCRIPTOR_H
#define UI_TABLE_WIDGET_OPERATION_DESCRIPTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableWidget_OperationDescriptor
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox_OperationOrder;
    QLineEdit *lineEdit_OperationName;
    QCheckBox *checkBox_EnableOperation;
    QPushButton *pushButton_ExecuteExplicitOp;

    void setupUi(QWidget *TableWidget_OperationDescriptor)
    {
        if (TableWidget_OperationDescriptor->objectName().isEmpty())
            TableWidget_OperationDescriptor->setObjectName(QStringLiteral("TableWidget_OperationDescriptor"));
        TableWidget_OperationDescriptor->resize(470, 40);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TableWidget_OperationDescriptor->sizePolicy().hasHeightForWidth());
        TableWidget_OperationDescriptor->setSizePolicy(sizePolicy);
        TableWidget_OperationDescriptor->setMinimumSize(QSize(470, 40));
        TableWidget_OperationDescriptor->setMaximumSize(QSize(470, 40));
        gridLayout_2 = new QGridLayout(TableWidget_OperationDescriptor);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        spinBox_OperationOrder = new QSpinBox(TableWidget_OperationDescriptor);
        spinBox_OperationOrder->setObjectName(QStringLiteral("spinBox_OperationOrder"));
        spinBox_OperationOrder->setEnabled(false);
        sizePolicy.setHeightForWidth(spinBox_OperationOrder->sizePolicy().hasHeightForWidth());
        spinBox_OperationOrder->setSizePolicy(sizePolicy);
        spinBox_OperationOrder->setMinimumSize(QSize(60, 20));
        spinBox_OperationOrder->setMaximumSize(QSize(60, 20));
        QFont font;
        font.setPointSize(10);
        spinBox_OperationOrder->setFont(font);
        spinBox_OperationOrder->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        spinBox_OperationOrder->setMinimum(1);

        horizontalLayout->addWidget(spinBox_OperationOrder);

        lineEdit_OperationName = new QLineEdit(TableWidget_OperationDescriptor);
        lineEdit_OperationName->setObjectName(QStringLiteral("lineEdit_OperationName"));
        sizePolicy.setHeightForWidth(lineEdit_OperationName->sizePolicy().hasHeightForWidth());
        lineEdit_OperationName->setSizePolicy(sizePolicy);
        lineEdit_OperationName->setMinimumSize(QSize(150, 20));
        lineEdit_OperationName->setMaximumSize(QSize(150, 20));
        lineEdit_OperationName->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit_OperationName);

        checkBox_EnableOperation = new QCheckBox(TableWidget_OperationDescriptor);
        checkBox_EnableOperation->setObjectName(QStringLiteral("checkBox_EnableOperation"));
        sizePolicy.setHeightForWidth(checkBox_EnableOperation->sizePolicy().hasHeightForWidth());
        checkBox_EnableOperation->setSizePolicy(sizePolicy);
        checkBox_EnableOperation->setMinimumSize(QSize(20, 20));
        checkBox_EnableOperation->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(checkBox_EnableOperation);

        pushButton_ExecuteExplicitOp = new QPushButton(TableWidget_OperationDescriptor);
        pushButton_ExecuteExplicitOp->setObjectName(QStringLiteral("pushButton_ExecuteExplicitOp"));
        sizePolicy.setHeightForWidth(pushButton_ExecuteExplicitOp->sizePolicy().hasHeightForWidth());
        pushButton_ExecuteExplicitOp->setSizePolicy(sizePolicy);
        pushButton_ExecuteExplicitOp->setMinimumSize(QSize(180, 20));
        pushButton_ExecuteExplicitOp->setMaximumSize(QSize(180, 20));
        pushButton_ExecuteExplicitOp->setFont(font);

        horizontalLayout->addWidget(pushButton_ExecuteExplicitOp);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(TableWidget_OperationDescriptor);

        QMetaObject::connectSlotsByName(TableWidget_OperationDescriptor);
    } // setupUi

    void retranslateUi(QWidget *TableWidget_OperationDescriptor)
    {
        TableWidget_OperationDescriptor->setWindowTitle(QApplication::translate("TableWidget_OperationDescriptor", "Form", nullptr));
        checkBox_EnableOperation->setText(QString());
        pushButton_ExecuteExplicitOp->setText(QApplication::translate("TableWidget_OperationDescriptor", "Execute Operation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableWidget_OperationDescriptor: public Ui_TableWidget_OperationDescriptor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_WIDGET_OPERATION_DESCRIPTOR_H
