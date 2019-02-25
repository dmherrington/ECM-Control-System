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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_BufferManager
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStackedWidget *stackedWidget_BufferContents;
    QListWidget *listWidget_Buffers;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_BufferManager)
    {
        if (Window_BufferManager->objectName().isEmpty())
            Window_BufferManager->setObjectName(QStringLiteral("Window_BufferManager"));
        Window_BufferManager->resize(915, 498);
        centralwidget = new QWidget(Window_BufferManager);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        stackedWidget_BufferContents = new QStackedWidget(centralwidget);
        stackedWidget_BufferContents->setObjectName(QStringLiteral("stackedWidget_BufferContents"));
        stackedWidget_BufferContents->setFrameShape(QFrame::Box);

        gridLayout->addWidget(stackedWidget_BufferContents, 0, 1, 2, 1);

        listWidget_Buffers = new QListWidget(centralwidget);
        listWidget_Buffers->setObjectName(QStringLiteral("listWidget_Buffers"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget_Buffers->sizePolicy().hasHeightForWidth());
        listWidget_Buffers->setSizePolicy(sizePolicy);
        listWidget_Buffers->setMinimumSize(QSize(440, 0));
        listWidget_Buffers->setMaximumSize(QSize(440, 16777215));

        gridLayout->addWidget(listWidget_Buffers, 1, 0, 1, 1);

        Window_BufferManager->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_BufferManager);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 915, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        Window_BufferManager->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_BufferManager);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Window_BufferManager->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());

        retranslateUi(Window_BufferManager);

        QMetaObject::connectSlotsByName(Window_BufferManager);
    } // setupUi

    void retranslateUi(QMainWindow *Window_BufferManager)
    {
        Window_BufferManager->setWindowTitle(QApplication::translate("Window_BufferManager", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("Window_BufferManager", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("Window_BufferManager", "PushButton", nullptr));
        menuFile->setTitle(QApplication::translate("Window_BufferManager", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_BufferManager: public Ui_Window_BufferManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_BUFFER_MANAGER_H
