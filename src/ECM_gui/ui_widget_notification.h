/********************************************************************************
** Form generated from reading UI file 'widget_notification.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_NOTIFICATION_H
#define UI_WIDGET_NOTIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Notification
{
public:
    QGridLayout *gridLayout;
    QListWidget *listWidget_Notifications;

    void setupUi(QWidget *Widget_Notification)
    {
        if (Widget_Notification->objectName().isEmpty())
            Widget_Notification->setObjectName(QStringLiteral("Widget_Notification"));
        Widget_Notification->resize(350, 64);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_Notification->sizePolicy().hasHeightForWidth());
        Widget_Notification->setSizePolicy(sizePolicy);
        Widget_Notification->setMinimumSize(QSize(350, 64));
        Widget_Notification->setAutoFillBackground(true);
        gridLayout = new QGridLayout(Widget_Notification);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        listWidget_Notifications = new QListWidget(Widget_Notification);
        listWidget_Notifications->setObjectName(QStringLiteral("listWidget_Notifications"));
        sizePolicy.setHeightForWidth(listWidget_Notifications->sizePolicy().hasHeightForWidth());
        listWidget_Notifications->setSizePolicy(sizePolicy);
        listWidget_Notifications->setMinimumSize(QSize(0, 60));
        listWidget_Notifications->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_Notifications->setSortingEnabled(false);

        gridLayout->addWidget(listWidget_Notifications, 0, 0, 1, 1);


        retranslateUi(Widget_Notification);

        QMetaObject::connectSlotsByName(Widget_Notification);
    } // setupUi

    void retranslateUi(QWidget *Widget_Notification)
    {
        Widget_Notification->setWindowTitle(QApplication::translate("Widget_Notification", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_Notification: public Ui_Widget_Notification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_NOTIFICATION_H
