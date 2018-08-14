/********************************************************************************
** Form generated from reading UI file 'window_custom_motion_commands.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_CUSTOM_MOTION_COMMANDS_H
#define UI_WINDOW_CUSTOM_MOTION_COMMANDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_CustomMotionCommands
{
public:
    QAction *actionTools;
    QAction *actionClose;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit_MotionCommand;
    QPushButton *pushButton_TransmitMotionCommand;
    QSpacerItem *horizontalSpacer;
    QPlainTextEdit *plainTextEdit_MotionResponse;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_CustomMotionCommands)
    {
        if (Window_CustomMotionCommands->objectName().isEmpty())
            Window_CustomMotionCommands->setObjectName(QStringLiteral("Window_CustomMotionCommands"));
        Window_CustomMotionCommands->resize(531, 166);
        Window_CustomMotionCommands->setMinimumSize(QSize(480, 0));
        Window_CustomMotionCommands->setStyleSheet(QLatin1String("QMenuBar{\n"
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
"QListWidget{\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
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
"background-color: qlineargrad"
                        "ient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(29, 29, 29, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));\n"
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
        actionTools = new QAction(Window_CustomMotionCommands);
        actionTools->setObjectName(QStringLiteral("actionTools"));
        actionClose = new QAction(Window_CustomMotionCommands);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        centralwidget = new QWidget(Window_CustomMotionCommands);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        plainTextEdit_MotionCommand = new QPlainTextEdit(centralwidget);
        plainTextEdit_MotionCommand->setObjectName(QStringLiteral("plainTextEdit_MotionCommand"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit_MotionCommand->sizePolicy().hasHeightForWidth());
        plainTextEdit_MotionCommand->setSizePolicy(sizePolicy);
        plainTextEdit_MotionCommand->setMinimumSize(QSize(100, 20));
        QFont font;
        font.setPointSize(12);
        plainTextEdit_MotionCommand->setFont(font);

        horizontalLayout->addWidget(plainTextEdit_MotionCommand);

        pushButton_TransmitMotionCommand = new QPushButton(centralwidget);
        pushButton_TransmitMotionCommand->setObjectName(QStringLiteral("pushButton_TransmitMotionCommand"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_TransmitMotionCommand->sizePolicy().hasHeightForWidth());
        pushButton_TransmitMotionCommand->setSizePolicy(sizePolicy1);
        pushButton_TransmitMotionCommand->setMinimumSize(QSize(180, 30));
        pushButton_TransmitMotionCommand->setFont(font);

        horizontalLayout->addWidget(pushButton_TransmitMotionCommand);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        plainTextEdit_MotionResponse = new QPlainTextEdit(centralwidget);
        plainTextEdit_MotionResponse->setObjectName(QStringLiteral("plainTextEdit_MotionResponse"));
        plainTextEdit_MotionResponse->setMinimumSize(QSize(0, 50));
        plainTextEdit_MotionResponse->setFont(font);
        plainTextEdit_MotionResponse->setReadOnly(true);

        gridLayout->addWidget(plainTextEdit_MotionResponse, 1, 0, 1, 1);

        Window_CustomMotionCommands->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_CustomMotionCommands);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 531, 40));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        Window_CustomMotionCommands->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_CustomMotionCommands);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Window_CustomMotionCommands->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionClose);

        retranslateUi(Window_CustomMotionCommands);

        pushButton_TransmitMotionCommand->setDefault(true);


        QMetaObject::connectSlotsByName(Window_CustomMotionCommands);
    } // setupUi

    void retranslateUi(QMainWindow *Window_CustomMotionCommands)
    {
        Window_CustomMotionCommands->setWindowTitle(QApplication::translate("Window_CustomMotionCommands", "MainWindow", nullptr));
        actionTools->setText(QApplication::translate("Window_CustomMotionCommands", "Tools", nullptr));
        actionClose->setText(QApplication::translate("Window_CustomMotionCommands", "Close", nullptr));
        pushButton_TransmitMotionCommand->setText(QApplication::translate("Window_CustomMotionCommands", "Transmit Command", nullptr));
        menuFile->setTitle(QApplication::translate("Window_CustomMotionCommands", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("Window_CustomMotionCommands", "Edit", nullptr));
        menuTools->setTitle(QApplication::translate("Window_CustomMotionCommands", "Tools", nullptr));
        menuHelp->setTitle(QApplication::translate("Window_CustomMotionCommands", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_CustomMotionCommands: public Ui_Window_CustomMotionCommands {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_CUSTOM_MOTION_COMMANDS_H
