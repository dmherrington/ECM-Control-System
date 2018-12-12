/********************************************************************************
** Form generated from reading UI file 'dialog_execution_paused.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_EXECUTION_PAUSED_H
#define UI_DIALOG_EXECUTION_PAUSED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Dialog_ExecutionPaused
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_ExecutionPaused)
    {
        if (Dialog_ExecutionPaused->objectName().isEmpty())
            Dialog_ExecutionPaused->setObjectName(QStringLiteral("Dialog_ExecutionPaused"));
        Dialog_ExecutionPaused->resize(400, 300);
        buttonBox = new QDialogButtonBox(Dialog_ExecutionPaused);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Dialog_ExecutionPaused);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_ExecutionPaused, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_ExecutionPaused, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_ExecutionPaused);
    } // setupUi

    void retranslateUi(QDialog *Dialog_ExecutionPaused)
    {
        Dialog_ExecutionPaused->setWindowTitle(QApplication::translate("Dialog_ExecutionPaused", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_ExecutionPaused: public Ui_Dialog_ExecutionPaused {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_EXECUTION_PAUSED_H
