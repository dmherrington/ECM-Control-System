/********************************************************************************
** Form generated from reading UI file 'dialog_execution_paused.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_EXECUTION_PAUSED_H
#define UI_DIALOG_EXECUTION_PAUSED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Dialog_ExecutionPaused
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_Ok;
    QPushButton *pushButton_Cancel;

    void setupUi(QDialog *Dialog_ExecutionPaused)
    {
        if (Dialog_ExecutionPaused->objectName().isEmpty())
            Dialog_ExecutionPaused->setObjectName(QString::fromUtf8("Dialog_ExecutionPaused"));
        Dialog_ExecutionPaused->resize(390, 150);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog_ExecutionPaused->sizePolicy().hasHeightForWidth());
        Dialog_ExecutionPaused->setSizePolicy(sizePolicy);
        Dialog_ExecutionPaused->setMinimumSize(QSize(390, 150));
        Dialog_ExecutionPaused->setMaximumSize(QSize(390, 150));
        Dialog_ExecutionPaused->setModal(false);
        gridLayout = new QGridLayout(Dialog_ExecutionPaused);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Dialog_ExecutionPaused);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        textBrowser = new QTextBrowser(Dialog_ExecutionPaused);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setFont(font);

        gridLayout->addWidget(textBrowser, 1, 0, 1, 2);

        pushButton_Ok = new QPushButton(Dialog_ExecutionPaused);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));
        pushButton_Ok->setFont(font);

        gridLayout->addWidget(pushButton_Ok, 2, 0, 1, 1);

        pushButton_Cancel = new QPushButton(Dialog_ExecutionPaused);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setFont(font);

        gridLayout->addWidget(pushButton_Cancel, 2, 1, 1, 1);


        retranslateUi(Dialog_ExecutionPaused);

        QMetaObject::connectSlotsByName(Dialog_ExecutionPaused);
    } // setupUi

    void retranslateUi(QDialog *Dialog_ExecutionPaused)
    {
        Dialog_ExecutionPaused->setWindowTitle(QApplication::translate("Dialog_ExecutionPaused", "Pause Dialog", nullptr));
        label->setText(QApplication::translate("Dialog_ExecutionPaused", "The current machining process has encountered a pause point. ", nullptr));
        pushButton_Ok->setText(QApplication::translate("Dialog_ExecutionPaused", "Ok", nullptr));
        pushButton_Cancel->setText(QApplication::translate("Dialog_ExecutionPaused", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_ExecutionPaused: public Ui_Dialog_ExecutionPaused {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_EXECUTION_PAUSED_H
