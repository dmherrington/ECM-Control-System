/********************************************************************************
** Form generated from reading UI file 'dialog_custom_commands.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_CUSTOM_COMMANDS_H
#define UI_DIALOG_CUSTOM_COMMANDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Dialog_CustomCommands
{
public:

    void setupUi(QDialog *Dialog_CustomCommands)
    {
        if (Dialog_CustomCommands->objectName().isEmpty())
            Dialog_CustomCommands->setObjectName(QStringLiteral("Dialog_CustomCommands"));
        Dialog_CustomCommands->resize(400, 300);

        retranslateUi(Dialog_CustomCommands);

        QMetaObject::connectSlotsByName(Dialog_CustomCommands);
    } // setupUi

    void retranslateUi(QDialog *Dialog_CustomCommands)
    {
        Dialog_CustomCommands->setWindowTitle(QApplication::translate("Dialog_CustomCommands", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog_CustomCommands: public Ui_Dialog_CustomCommands {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_CUSTOM_COMMANDS_H
