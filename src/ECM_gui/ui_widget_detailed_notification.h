/********************************************************************************
** Form generated from reading UI file 'widget_detailed_notification.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_DETAILED_NOTIFICATION_H
#define UI_WIDGET_DETAILED_NOTIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_DetailedNotification
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_Time;
    QPlainTextEdit *plainTextEdit_Message;

    void setupUi(QWidget *Widget_DetailedNotification)
    {
        if (Widget_DetailedNotification->objectName().isEmpty())
            Widget_DetailedNotification->setObjectName(QStringLiteral("Widget_DetailedNotification"));
        Widget_DetailedNotification->resize(350, 27);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_DetailedNotification->sizePolicy().hasHeightForWidth());
        Widget_DetailedNotification->setSizePolicy(sizePolicy);
        Widget_DetailedNotification->setMinimumSize(QSize(350, 27));
        Widget_DetailedNotification->setMaximumSize(QSize(16777215, 110));
        gridLayout = new QGridLayout(Widget_DetailedNotification);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_Time = new QLineEdit(Widget_DetailedNotification);
        lineEdit_Time->setObjectName(QStringLiteral("lineEdit_Time"));
        lineEdit_Time->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_Time->sizePolicy().hasHeightForWidth());
        lineEdit_Time->setSizePolicy(sizePolicy1);
        lineEdit_Time->setMinimumSize(QSize(90, 25));
        lineEdit_Time->setMaximumSize(QSize(90, 25));
        QFont font;
        font.setPointSize(8);
        lineEdit_Time->setFont(font);
        lineEdit_Time->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_Time, 0, 0, 1, 1);

        plainTextEdit_Message = new QPlainTextEdit(Widget_DetailedNotification);
        plainTextEdit_Message->setObjectName(QStringLiteral("plainTextEdit_Message"));
        plainTextEdit_Message->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(plainTextEdit_Message->sizePolicy().hasHeightForWidth());
        plainTextEdit_Message->setSizePolicy(sizePolicy2);
        plainTextEdit_Message->setMinimumSize(QSize(200, 25));
        plainTextEdit_Message->setMaximumSize(QSize(260, 100));
        plainTextEdit_Message->setFont(font);
        plainTextEdit_Message->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        plainTextEdit_Message->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_Message->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        plainTextEdit_Message->setReadOnly(true);

        gridLayout->addWidget(plainTextEdit_Message, 0, 1, 1, 1);


        retranslateUi(Widget_DetailedNotification);

        QMetaObject::connectSlotsByName(Widget_DetailedNotification);
    } // setupUi

    void retranslateUi(QWidget *Widget_DetailedNotification)
    {
        Widget_DetailedNotification->setWindowTitle(QApplication::translate("Widget_DetailedNotification", "Form", nullptr));
        lineEdit_Time->setText(QApplication::translate("Widget_DetailedNotification", "Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_DetailedNotification: public Ui_Widget_DetailedNotification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_DETAILED_NOTIFICATION_H
