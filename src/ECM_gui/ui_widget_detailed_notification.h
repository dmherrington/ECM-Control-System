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
    QLineEdit *lineEdit_NotificationType;
    QLineEdit *lineEdit_Time;
    QPlainTextEdit *plainTextEdit_Message;

    void setupUi(QWidget *Widget_DetailedNotification)
    {
        if (Widget_DetailedNotification->objectName().isEmpty())
            Widget_DetailedNotification->setObjectName(QStringLiteral("Widget_DetailedNotification"));
        Widget_DetailedNotification->resize(500, 32);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_DetailedNotification->sizePolicy().hasHeightForWidth());
        Widget_DetailedNotification->setSizePolicy(sizePolicy);
        Widget_DetailedNotification->setMinimumSize(QSize(500, 32));
        Widget_DetailedNotification->setMaximumSize(QSize(16777215, 32));
        gridLayout = new QGridLayout(Widget_DetailedNotification);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_NotificationType = new QLineEdit(Widget_DetailedNotification);
        lineEdit_NotificationType->setObjectName(QStringLiteral("lineEdit_NotificationType"));
        lineEdit_NotificationType->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_NotificationType->sizePolicy().hasHeightForWidth());
        lineEdit_NotificationType->setSizePolicy(sizePolicy1);
        lineEdit_NotificationType->setMinimumSize(QSize(80, 25));
        lineEdit_NotificationType->setMaximumSize(QSize(80, 25));
        QFont font;
        font.setPointSize(8);
        lineEdit_NotificationType->setFont(font);
        lineEdit_NotificationType->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_NotificationType, 0, 0, 1, 1);

        lineEdit_Time = new QLineEdit(Widget_DetailedNotification);
        lineEdit_Time->setObjectName(QStringLiteral("lineEdit_Time"));
        lineEdit_Time->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_Time->sizePolicy().hasHeightForWidth());
        lineEdit_Time->setSizePolicy(sizePolicy1);
        lineEdit_Time->setMinimumSize(QSize(90, 25));
        lineEdit_Time->setMaximumSize(QSize(90, 25));
        lineEdit_Time->setFont(font);
        lineEdit_Time->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_Time, 0, 1, 1, 1);

        plainTextEdit_Message = new QPlainTextEdit(Widget_DetailedNotification);
        plainTextEdit_Message->setObjectName(QStringLiteral("plainTextEdit_Message"));
        plainTextEdit_Message->setEnabled(false);
        plainTextEdit_Message->setMinimumSize(QSize(250, 25));
        plainTextEdit_Message->setMaximumSize(QSize(16777215, 25));
        plainTextEdit_Message->setFont(font);
        plainTextEdit_Message->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(plainTextEdit_Message, 0, 2, 1, 1);


        retranslateUi(Widget_DetailedNotification);

        QMetaObject::connectSlotsByName(Widget_DetailedNotification);
    } // setupUi

    void retranslateUi(QWidget *Widget_DetailedNotification)
    {
        Widget_DetailedNotification->setWindowTitle(QApplication::translate("Widget_DetailedNotification", "Form", nullptr));
        lineEdit_NotificationType->setText(QApplication::translate("Widget_DetailedNotification", "NOTIFICATION", nullptr));
        lineEdit_Time->setText(QApplication::translate("Widget_DetailedNotification", "Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_DetailedNotification: public Ui_Widget_DetailedNotification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_DETAILED_NOTIFICATION_H
