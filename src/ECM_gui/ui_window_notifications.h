/********************************************************************************
** Form generated from reading UI file 'window_notifications.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_NOTIFICATIONS_H
#define UI_WINDOW_NOTIFICATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_Notifications
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget_Notifications;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_Notifications)
    {
        if (Window_Notifications->objectName().isEmpty())
            Window_Notifications->setObjectName(QStringLiteral("Window_Notifications"));
        Window_Notifications->resize(654, 227);
        Window_Notifications->setMinimumSize(QSize(550, 64));
        centralwidget = new QWidget(Window_Notifications);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        listWidget_Notifications = new QListWidget(centralwidget);
        listWidget_Notifications->setObjectName(QStringLiteral("listWidget_Notifications"));
        listWidget_Notifications->setGeometry(QRect(0, 0, 654, 186));
        listWidget_Notifications->setMinimumSize(QSize(0, 64));
        Window_Notifications->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_Notifications);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 654, 21));
        Window_Notifications->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_Notifications);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Window_Notifications->setStatusBar(statusbar);

        retranslateUi(Window_Notifications);

        QMetaObject::connectSlotsByName(Window_Notifications);
    } // setupUi

    void retranslateUi(QMainWindow *Window_Notifications)
    {
        Window_Notifications->setWindowTitle(QApplication::translate("Window_Notifications", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_Notifications: public Ui_Window_Notifications {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_NOTIFICATIONS_H
