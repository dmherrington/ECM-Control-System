/********************************************************************************
** Form generated from reading UI file 'window_motion_profile.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_MOTION_PROFILE_H
#define UI_WINDOW_MOTION_PROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "LED.h"
#include "misc_dialogs/code_edit_widget.h"

QT_BEGIN_NAMESPACE

class Ui_Window_MotionProfile
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionClose;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_4;
    QLabel *label_ManualControl;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_motionScriptPath;
    QGridLayout *gridLayout;
    QPushButton *pushButton_DownloadProgram;
    QPushButton *pushButton_UploadProgram;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_Connection;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    LED *led_ProgramCurrent;
    QSpacerItem *horizontalSpacer;
    CodeEditWidget *codeTextEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_MotionProfile)
    {
        if (Window_MotionProfile->objectName().isEmpty())
            Window_MotionProfile->setObjectName(QStringLiteral("Window_MotionProfile"));
        Window_MotionProfile->resize(482, 295);
        Window_MotionProfile->setStyleSheet(QLatin1String("QMenuBar{\n"
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
        actionOpen = new QAction(Window_MotionProfile);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(Window_MotionProfile);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(Window_MotionProfile);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionClose = new QAction(Window_MotionProfile);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        centralwidget = new QWidget(Window_MotionProfile);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_ManualControl = new QLabel(centralwidget);
        label_ManualControl->setObjectName(QStringLiteral("label_ManualControl"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_ManualControl->sizePolicy().hasHeightForWidth());
        label_ManualControl->setSizePolicy(sizePolicy);
        label_ManualControl->setMinimumSize(QSize(0, 32));
        label_ManualControl->setMaximumSize(QSize(16777215, 32));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_ManualControl->setFont(font);
        label_ManualControl->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_ManualControl, 0, 0, 1, 1);


        horizontalLayout_6->addLayout(gridLayout_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        gridLayout_3->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(110, 18));
        label->setMaximumSize(QSize(110, 18));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        lineEdit_motionScriptPath = new QLineEdit(centralwidget);
        lineEdit_motionScriptPath->setObjectName(QStringLiteral("lineEdit_motionScriptPath"));
        sizePolicy1.setHeightForWidth(lineEdit_motionScriptPath->sizePolicy().hasHeightForWidth());
        lineEdit_motionScriptPath->setSizePolicy(sizePolicy1);
        lineEdit_motionScriptPath->setMinimumSize(QSize(330, 18));
        lineEdit_motionScriptPath->setMaximumSize(QSize(400, 18));
        lineEdit_motionScriptPath->setFont(font1);

        horizontalLayout->addWidget(lineEdit_motionScriptPath);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_DownloadProgram = new QPushButton(centralwidget);
        pushButton_DownloadProgram->setObjectName(QStringLiteral("pushButton_DownloadProgram"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_DownloadProgram->sizePolicy().hasHeightForWidth());
        pushButton_DownloadProgram->setSizePolicy(sizePolicy2);
        pushButton_DownloadProgram->setMinimumSize(QSize(180, 30));
        pushButton_DownloadProgram->setMaximumSize(QSize(16777215, 30));
        pushButton_DownloadProgram->setFont(font1);

        gridLayout->addWidget(pushButton_DownloadProgram, 0, 1, 1, 1);

        pushButton_UploadProgram = new QPushButton(centralwidget);
        pushButton_UploadProgram->setObjectName(QStringLiteral("pushButton_UploadProgram"));
        sizePolicy2.setHeightForWidth(pushButton_UploadProgram->sizePolicy().hasHeightForWidth());
        pushButton_UploadProgram->setSizePolicy(sizePolicy2);
        pushButton_UploadProgram->setMinimumSize(QSize(180, 30));
        pushButton_UploadProgram->setMaximumSize(QSize(16777215, 30));
        pushButton_UploadProgram->setFont(font1);

        gridLayout->addWidget(pushButton_UploadProgram, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(2, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_Connection = new QLabel(centralwidget);
        label_Connection->setObjectName(QStringLiteral("label_Connection"));
        sizePolicy2.setHeightForWidth(label_Connection->sizePolicy().hasHeightForWidth());
        label_Connection->setSizePolicy(sizePolicy2);
        label_Connection->setMinimumSize(QSize(80, 18));
        label_Connection->setMaximumSize(QSize(80, 18));
        label_Connection->setFont(font1);
        label_Connection->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_Connection);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(2, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        led_ProgramCurrent = new LED(centralwidget);
        led_ProgramCurrent->setObjectName(QStringLiteral("led_ProgramCurrent"));
        sizePolicy2.setHeightForWidth(led_ProgramCurrent->sizePolicy().hasHeightForWidth());
        led_ProgramCurrent->setSizePolicy(sizePolicy2);
        led_ProgramCurrent->setMinimumSize(QSize(40, 40));
        led_ProgramCurrent->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(led_ProgramCurrent);

        horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 2);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);

        codeTextEdit = new CodeEditWidget(centralwidget);
        codeTextEdit->setObjectName(QStringLiteral("codeTextEdit"));

        gridLayout_3->addWidget(codeTextEdit, 2, 0, 1, 1);

        Window_MotionProfile->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_MotionProfile);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 482, 40));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        Window_MotionProfile->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_MotionProfile);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Window_MotionProfile->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);

        retranslateUi(Window_MotionProfile);

        QMetaObject::connectSlotsByName(Window_MotionProfile);
    } // setupUi

    void retranslateUi(QMainWindow *Window_MotionProfile)
    {
        Window_MotionProfile->setWindowTitle(QApplication::translate("Window_MotionProfile", "Galil Script", nullptr));
        actionOpen->setText(QApplication::translate("Window_MotionProfile", "Open", nullptr));
        actionSave->setText(QApplication::translate("Window_MotionProfile", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("Window_MotionProfile", "Save As", nullptr));
        actionClose->setText(QApplication::translate("Window_MotionProfile", "Close", nullptr));
        label_ManualControl->setText(QApplication::translate("Window_MotionProfile", "Scripting Code", nullptr));
        label->setText(QApplication::translate("Window_MotionProfile", "Scripting Path:", nullptr));
        pushButton_DownloadProgram->setText(QApplication::translate("Window_MotionProfile", "Download Program", nullptr));
        pushButton_UploadProgram->setText(QApplication::translate("Window_MotionProfile", "Upload Program", nullptr));
        label_Connection->setText(QApplication::translate("Window_MotionProfile", "Current:", nullptr));
        menuFile->setTitle(QApplication::translate("Window_MotionProfile", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("Window_MotionProfile", "Edit", nullptr));
        menuTools->setTitle(QApplication::translate("Window_MotionProfile", "Tools", nullptr));
        menuHelp->setTitle(QApplication::translate("Window_MotionProfile", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_MotionProfile: public Ui_Window_MotionProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_MOTION_PROFILE_H
