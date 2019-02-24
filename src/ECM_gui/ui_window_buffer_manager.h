/********************************************************************************
** Form generated from reading UI file 'window_buffer_manager.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_BUFFER_MANAGER_H
#define UI_WINDOW_BUFFER_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_BufferManager
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget_Buffers;
    QWidget *widget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_BufferManager)
    {
        if (Window_BufferManager->objectName().isEmpty())
            Window_BufferManager->setObjectName(QStringLiteral("Window_BufferManager"));
        Window_BufferManager->resize(800, 600);
        centralwidget = new QWidget(Window_BufferManager);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        listWidget_Buffers = new QListWidget(centralwidget);
        listWidget_Buffers->setObjectName(QStringLiteral("listWidget_Buffers"));
        listWidget_Buffers->setGeometry(QRect(10, 80, 256, 461));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(290, 10, 471, 521));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 40, 75, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 40, 75, 23));
        Window_BufferManager->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_BufferManager);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Window_BufferManager->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_BufferManager);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Window_BufferManager->setStatusBar(statusbar);

        retranslateUi(Window_BufferManager);

        QMetaObject::connectSlotsByName(Window_BufferManager);
    } // setupUi

    void retranslateUi(QMainWindow *Window_BufferManager)
    {
        Window_BufferManager->setWindowTitle(QApplication::translate("Window_BufferManager", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("Window_BufferManager", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("Window_BufferManager", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_BufferManager: public Ui_Window_BufferManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_BUFFER_MANAGER_H
