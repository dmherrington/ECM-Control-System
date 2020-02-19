/********************************************************************************
** Form generated from reading UI file 'window_buffer_manager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
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
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionClose;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_Sync;
    QStackedWidget *stackedWidget_BufferContents;
    QListWidget *listWidget_Buffers;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_BufferManager)
    {
        if (Window_BufferManager->objectName().isEmpty())
            Window_BufferManager->setObjectName(QString::fromUtf8("Window_BufferManager"));
        Window_BufferManager->resize(915, 498);
        Window_BufferManager->setStyleSheet(QString::fromUtf8("QMenuBar{\n"
"background-color:#1d1d1d;\n"
"padding:5px;\n"
"	font: 12pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
"QMenuBar::item{\n"
"background-color:#1d1d1d;\n"
"color:#fff;\n"
"padding:5px;\n"
"\n"
"}\n"
"\n"
"QMenu{\n"
"color:#fff;\n"
"padding:0;\n"
"}\n"
"\n"
"QMenu::item:selected{\n"
"color:#fff;\n"
"background-color:#00aba9;\n"
"}\n"
"\n"
"QTableWidget{\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"  selection-background-color: #da532c;\n"
"border:solid;\n"
"border-width:3px;\n"
"border-color:#da532c;\n"
"}\n"
"QHeaderView::section{\n"
"background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"border:none;\n"
"border-top-style:solid;\n"
"border-width:1px;\n"
"border-top-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"color:#fff;\n"
"\n"
"}\n"
"QHeaderView{\n"
"background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, "
                        "217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"\n"
"border:none;\n"
"border-top-style:solid;\n"
"border-width:1px;\n"
"border-top-color:#149ED9;\n"
"color:#fff;\n"
"	font: 75 12pt \"Calibri\";\n"
"}\n"
"\n"
"QTableCornerButton::section{\n"
"border:none;\n"
"background-color:#149ED9;\n"
"}\n"
"\n"
"QMenu{\n"
"background-color:#3d3d3d;\n"
"}\n"
"QStatusBar{\n"
"background-color:#7e3878;\n"
"color:#fff;\n"
"}\n"
"\n"
"QPushButton{\n"
"border-style:solid;\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"background-color: rgb(204, 0, 0);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"color:#ccc;\n"
"	background-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(45, 45, 45, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));\n"
"	border-color:#2d89ef;\n"
"border-width:2px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(29, 29, 29, 2"
                        "55), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));\n"
"}\n"
"\n"
"\n"
"QTabWidget::tab{\n"
"background-color:#3d3d3d;\n"
"}\n"
"\n"
"QLineEdit{\n"
"border-radius:0;\n"
"}\n"
"\n"
"QProgressBar{\n"
"border-radius:0;\n"
"text-align:center;\n"
"color:#fff;\n"
"background-color:transparent;\n"
"border: 2px solid #e3a21a;\n"
"border-radius:7px;\n"
"	font: 75 12pt \"Open Sans\";\n"
"\n"
"}\n"
"\n"
"QProgressBar::chunk{\n"
"background-color:#2d89ef;\n"
"width:20px;\n"
"}"));
        actionOpen = new QAction(Window_BufferManager);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(Window_BufferManager);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(Window_BufferManager);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionClose = new QAction(Window_BufferManager);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        centralwidget = new QWidget(Window_BufferManager);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 24));
        QFont font;
        font.setPointSize(10);
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        pushButton_Sync = new QPushButton(centralwidget);
        pushButton_Sync->setObjectName(QString::fromUtf8("pushButton_Sync"));
        pushButton_Sync->setMinimumSize(QSize(0, 24));
        pushButton_Sync->setFont(font);

        horizontalLayout->addWidget(pushButton_Sync);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        stackedWidget_BufferContents = new QStackedWidget(centralwidget);
        stackedWidget_BufferContents->setObjectName(QString::fromUtf8("stackedWidget_BufferContents"));
        stackedWidget_BufferContents->setFrameShape(QFrame::Box);

        gridLayout->addWidget(stackedWidget_BufferContents, 0, 1, 2, 1);

        listWidget_Buffers = new QListWidget(centralwidget);
        listWidget_Buffers->setObjectName(QString::fromUtf8("listWidget_Buffers"));
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
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 915, 40));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        Window_BufferManager->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_BufferManager);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Window_BufferManager->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);

        retranslateUi(Window_BufferManager);

        QMetaObject::connectSlotsByName(Window_BufferManager);
    } // setupUi

    void retranslateUi(QMainWindow *Window_BufferManager)
    {
        Window_BufferManager->setWindowTitle(QApplication::translate("Window_BufferManager", "SPII Buffer Editor", nullptr));
        actionOpen->setText(QApplication::translate("Window_BufferManager", "Open", nullptr));
        actionSave->setText(QApplication::translate("Window_BufferManager", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("Window_BufferManager", "Save As", nullptr));
        actionClose->setText(QApplication::translate("Window_BufferManager", "Close", nullptr));
        pushButton->setText(QString());
        pushButton_Sync->setText(QApplication::translate("Window_BufferManager", "SYNC BUFFERS TO ACS", nullptr));
        menuFile->setTitle(QApplication::translate("Window_BufferManager", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_BufferManager: public Ui_Window_BufferManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_BUFFER_MANAGER_H
