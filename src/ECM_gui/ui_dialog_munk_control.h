/********************************************************************************
** Form generated from reading UI file 'dialog_munk_control.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_MUNK_CONTROL_H
#define UI_DIALOG_MUNK_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Dialog_MunkControl
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_MunkControl)
    {
        if (Dialog_MunkControl->objectName().isEmpty())
            Dialog_MunkControl->setObjectName(QStringLiteral("Dialog_MunkControl"));
        Dialog_MunkControl->resize(400, 300);
        buttonBox = new QDialogButtonBox(Dialog_MunkControl);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Dialog_MunkControl);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_MunkControl, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_MunkControl, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_MunkControl);
    } // setupUi

    void retranslateUi(QDialog *Dialog_MunkControl)
    {
        Dialog_MunkControl->setWindowTitle(QApplication::translate("Dialog_MunkControl", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog_MunkControl: public Ui_Dialog_MunkControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_MUNK_CONTROL_H
