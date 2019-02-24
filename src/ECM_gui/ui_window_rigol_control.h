/********************************************************************************
** Form generated from reading UI file 'window_rigol_control.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_RIGOL_CONTROL_H
#define UI_WINDOW_RIGOL_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "LED.h"
#include "rigol_dialog/widget_rigol_radio.h"

QT_BEGIN_NAMESPACE

class Ui_Window_RigolControl
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionClose;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    Widget_RigolRadio *widget_RadioButtons;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Connection;
    LED *widget_PumpOn;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox_Channel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Done;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_RigolControl)
    {
        if (Window_RigolControl->objectName().isEmpty())
            Window_RigolControl->setObjectName(QStringLiteral("Window_RigolControl"));
        Window_RigolControl->resize(501, 260);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Window_RigolControl->sizePolicy().hasHeightForWidth());
        Window_RigolControl->setSizePolicy(sizePolicy);
        Window_RigolControl->setMinimumSize(QSize(501, 260));
        Window_RigolControl->setMaximumSize(QSize(1000, 1000));
        Window_RigolControl->setStyleSheet(QLatin1String("QMenuBar{\n"
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
"border-radius:1px solid red;\n"
"background-color:#c4c4c4;\n"
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
        actionOpen = new QAction(Window_RigolControl);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(Window_RigolControl);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(Window_RigolControl);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionClose = new QAction(Window_RigolControl);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        centralwidget = new QWidget(Window_RigolControl);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget_RadioButtons = new Widget_RigolRadio(centralwidget);
        widget_RadioButtons->setObjectName(QStringLiteral("widget_RadioButtons"));
        widget_RadioButtons->setMinimumSize(QSize(482, 100));
        widget_RadioButtons->setMaximumSize(QSize(482, 100));

        gridLayout->addWidget(widget_RadioButtons, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_Connection = new QLabel(centralwidget);
        label_Connection->setObjectName(QStringLiteral("label_Connection"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_Connection->sizePolicy().hasHeightForWidth());
        label_Connection->setSizePolicy(sizePolicy1);
        label_Connection->setMinimumSize(QSize(80, 18));
        label_Connection->setMaximumSize(QSize(80, 18));
        QFont font;
        font.setPointSize(10);
        label_Connection->setFont(font);
        label_Connection->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_Connection);

        widget_PumpOn = new LED(centralwidget);
        widget_PumpOn->setObjectName(QStringLiteral("widget_PumpOn"));
        sizePolicy1.setHeightForWidth(widget_PumpOn->sizePolicy().hasHeightForWidth());
        widget_PumpOn->setSizePolicy(sizePolicy1);
        widget_PumpOn->setMinimumSize(QSize(80, 50));
        widget_PumpOn->setMaximumSize(QSize(80, 50));

        verticalLayout_2->addWidget(widget_PumpOn);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        comboBox_Channel = new QComboBox(centralwidget);
        comboBox_Channel->setObjectName(QStringLiteral("comboBox_Channel"));
        sizePolicy1.setHeightForWidth(comboBox_Channel->sizePolicy().hasHeightForWidth());
        comboBox_Channel->setSizePolicy(sizePolicy1);
        comboBox_Channel->setMinimumSize(QSize(200, 25));
        comboBox_Channel->setMaximumSize(QSize(200, 25));
        comboBox_Channel->setFont(font);

        horizontalLayout->addWidget(comboBox_Channel);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_Done = new QPushButton(centralwidget);
        pushButton_Done->setObjectName(QStringLiteral("pushButton_Done"));
        sizePolicy1.setHeightForWidth(pushButton_Done->sizePolicy().hasHeightForWidth());
        pushButton_Done->setSizePolicy(sizePolicy1);
        pushButton_Done->setMinimumSize(QSize(100, 40));
        pushButton_Done->setMaximumSize(QSize(100, 40));
        QFont font1;
        font1.setPointSize(12);
        pushButton_Done->setFont(font1);

        horizontalLayout->addWidget(pushButton_Done);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        Window_RigolControl->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_RigolControl);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 501, 40));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        Window_RigolControl->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_RigolControl);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Window_RigolControl->setStatusBar(statusbar);

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

        retranslateUi(Window_RigolControl);

        QMetaObject::connectSlotsByName(Window_RigolControl);
    } // setupUi

    void retranslateUi(QMainWindow *Window_RigolControl)
    {
        Window_RigolControl->setWindowTitle(QApplication::translate("Window_RigolControl", "Window Rigol Control", nullptr));
        actionOpen->setText(QApplication::translate("Window_RigolControl", "Open", nullptr));
        actionSave->setText(QApplication::translate("Window_RigolControl", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("Window_RigolControl", "Save As", nullptr));
        actionClose->setText(QApplication::translate("Window_RigolControl", "Close", nullptr));
        label_Connection->setText(QApplication::translate("Window_RigolControl", "Connection:", nullptr));
        pushButton_Done->setText(QApplication::translate("Window_RigolControl", "DONE", nullptr));
        menuFile->setTitle(QApplication::translate("Window_RigolControl", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("Window_RigolControl", "Edit", nullptr));
        menuTools->setTitle(QApplication::translate("Window_RigolControl", "Tools", nullptr));
        menuHelp->setTitle(QApplication::translate("Window_RigolControl", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_RigolControl: public Ui_Window_RigolControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_RIGOL_CONTROL_H
