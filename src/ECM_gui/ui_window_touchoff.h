/********************************************************************************
** Form generated from reading UI file 'window_touchoff.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_TOUCHOFF_H
#define UI_WINDOW_TOUCHOFF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "LED.h"

QT_BEGIN_NAMESPACE

class Ui_Window_Touchoff
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionClose;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_TouchoffRef;
    QDoubleSpinBox *doubleSpinBox_TouchoffRef;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Connection;
    LED *widget_TouchoffComplete;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_RunTouchoff;
    QDoubleSpinBox *doubleSpinBox_InitialGap;
    QLabel *label_2;
    QPushButton *pushButton_ExecuteTouchoff;
    QLineEdit *lineEdit_TouchoffCode;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_Touchoff)
    {
        if (Window_Touchoff->objectName().isEmpty())
            Window_Touchoff->setObjectName(QStringLiteral("Window_Touchoff"));
        Window_Touchoff->resize(450, 195);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Window_Touchoff->sizePolicy().hasHeightForWidth());
        Window_Touchoff->setSizePolicy(sizePolicy);
        Window_Touchoff->setMinimumSize(QSize(450, 195));
        Window_Touchoff->setMaximumSize(QSize(452, 195));
        Window_Touchoff->setStyleSheet(QLatin1String("QMenuBar{\n"
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
        actionOpen = new QAction(Window_Touchoff);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(Window_Touchoff);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(Window_Touchoff);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionClose = new QAction(Window_Touchoff);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        centralwidget = new QWidget(Window_Touchoff);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_TouchoffRef = new QPushButton(centralwidget);
        pushButton_TouchoffRef->setObjectName(QStringLiteral("pushButton_TouchoffRef"));
        sizePolicy.setHeightForWidth(pushButton_TouchoffRef->sizePolicy().hasHeightForWidth());
        pushButton_TouchoffRef->setSizePolicy(sizePolicy);
        pushButton_TouchoffRef->setMinimumSize(QSize(180, 25));
        pushButton_TouchoffRef->setMaximumSize(QSize(180, 25));
        QFont font;
        font.setPointSize(12);
        pushButton_TouchoffRef->setFont(font);

        horizontalLayout->addWidget(pushButton_TouchoffRef);

        doubleSpinBox_TouchoffRef = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_TouchoffRef->setObjectName(QStringLiteral("doubleSpinBox_TouchoffRef"));
        sizePolicy.setHeightForWidth(doubleSpinBox_TouchoffRef->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TouchoffRef->setSizePolicy(sizePolicy);
        doubleSpinBox_TouchoffRef->setMinimumSize(QSize(120, 25));
        doubleSpinBox_TouchoffRef->setMaximumSize(QSize(120, 25));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(11);
        doubleSpinBox_TouchoffRef->setFont(font1);
        doubleSpinBox_TouchoffRef->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_TouchoffRef->setDecimals(1);
        doubleSpinBox_TouchoffRef->setMaximum(100000);

        horizontalLayout->addWidget(doubleSpinBox_TouchoffRef);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(32, 25));
        label->setMaximumSize(QSize(32, 25));

        horizontalLayout->addWidget(label);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_Connection = new QLabel(centralwidget);
        label_Connection->setObjectName(QStringLiteral("label_Connection"));
        sizePolicy.setHeightForWidth(label_Connection->sizePolicy().hasHeightForWidth());
        label_Connection->setSizePolicy(sizePolicy);
        label_Connection->setMinimumSize(QSize(80, 18));
        label_Connection->setMaximumSize(QSize(80, 18));
        QFont font2;
        font2.setPointSize(10);
        label_Connection->setFont(font2);
        label_Connection->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_Connection);

        widget_TouchoffComplete = new LED(centralwidget);
        widget_TouchoffComplete->setObjectName(QStringLiteral("widget_TouchoffComplete"));
        sizePolicy.setHeightForWidth(widget_TouchoffComplete->sizePolicy().hasHeightForWidth());
        widget_TouchoffComplete->setSizePolicy(sizePolicy);
        widget_TouchoffComplete->setMinimumSize(QSize(80, 50));
        widget_TouchoffComplete->setMaximumSize(QSize(80, 50));

        verticalLayout_2->addWidget(widget_TouchoffComplete);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 2, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_RunTouchoff = new QPushButton(centralwidget);
        pushButton_RunTouchoff->setObjectName(QStringLiteral("pushButton_RunTouchoff"));
        sizePolicy.setHeightForWidth(pushButton_RunTouchoff->sizePolicy().hasHeightForWidth());
        pushButton_RunTouchoff->setSizePolicy(sizePolicy);
        pushButton_RunTouchoff->setMinimumSize(QSize(180, 25));
        pushButton_RunTouchoff->setMaximumSize(QSize(16777215, 25));
        pushButton_RunTouchoff->setFont(font);

        horizontalLayout_2->addWidget(pushButton_RunTouchoff);

        doubleSpinBox_InitialGap = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_InitialGap->setObjectName(QStringLiteral("doubleSpinBox_InitialGap"));
        doubleSpinBox_InitialGap->setMinimumSize(QSize(120, 25));
        doubleSpinBox_InitialGap->setMaximumSize(QSize(120, 25));
        QFont font3;
        font3.setPointSize(11);
        doubleSpinBox_InitialGap->setFont(font3);
        doubleSpinBox_InitialGap->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_InitialGap->setDecimals(1);
        doubleSpinBox_InitialGap->setMaximum(100000);

        horizontalLayout_2->addWidget(doubleSpinBox_InitialGap);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(32, 25));
        label_2->setMaximumSize(QSize(32, 25));

        horizontalLayout_2->addWidget(label_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        pushButton_ExecuteTouchoff = new QPushButton(centralwidget);
        pushButton_ExecuteTouchoff->setObjectName(QStringLiteral("pushButton_ExecuteTouchoff"));
        sizePolicy.setHeightForWidth(pushButton_ExecuteTouchoff->sizePolicy().hasHeightForWidth());
        pushButton_ExecuteTouchoff->setSizePolicy(sizePolicy);
        pushButton_ExecuteTouchoff->setMinimumSize(QSize(100, 30));
        pushButton_ExecuteTouchoff->setMaximumSize(QSize(100, 30));
        pushButton_ExecuteTouchoff->setFont(font);

        gridLayout->addWidget(pushButton_ExecuteTouchoff, 2, 0, 1, 1);

        lineEdit_TouchoffCode = new QLineEdit(centralwidget);
        lineEdit_TouchoffCode->setObjectName(QStringLiteral("lineEdit_TouchoffCode"));
        sizePolicy.setHeightForWidth(lineEdit_TouchoffCode->sizePolicy().hasHeightForWidth());
        lineEdit_TouchoffCode->setSizePolicy(sizePolicy);
        lineEdit_TouchoffCode->setMinimumSize(QSize(300, 30));
        lineEdit_TouchoffCode->setMaximumSize(QSize(300, 30));
        lineEdit_TouchoffCode->setFont(font);
        lineEdit_TouchoffCode->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_TouchoffCode, 2, 1, 1, 2);

        Window_Touchoff->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_Touchoff);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 450, 40));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        Window_Touchoff->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_Touchoff);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Window_Touchoff->setStatusBar(statusbar);

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

        retranslateUi(Window_Touchoff);

        QMetaObject::connectSlotsByName(Window_Touchoff);
    } // setupUi

    void retranslateUi(QMainWindow *Window_Touchoff)
    {
        Window_Touchoff->setWindowTitle(QApplication::translate("Window_Touchoff", "Window Touchoff Control", nullptr));
        actionOpen->setText(QApplication::translate("Window_Touchoff", "Open", nullptr));
        actionSave->setText(QApplication::translate("Window_Touchoff", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("Window_Touchoff", "Save As", nullptr));
        actionClose->setText(QApplication::translate("Window_Touchoff", "Close", nullptr));
        pushButton_TouchoffRef->setText(QApplication::translate("Window_Touchoff", "Set Touchoff Ref", nullptr));
        label->setText(QApplication::translate("Window_Touchoff", "um", nullptr));
        label_Connection->setText(QApplication::translate("Window_Touchoff", "Completed:", nullptr));
        pushButton_RunTouchoff->setText(QApplication::translate("Window_Touchoff", "Set Initial Gap", nullptr));
        label_2->setText(QApplication::translate("Window_Touchoff", "um", nullptr));
        pushButton_ExecuteTouchoff->setText(QApplication::translate("Window_Touchoff", "Execute", nullptr));
        menuFile->setTitle(QApplication::translate("Window_Touchoff", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("Window_Touchoff", "Edit", nullptr));
        menuTools->setTitle(QApplication::translate("Window_Touchoff", "Tools", nullptr));
        menuHelp->setTitle(QApplication::translate("Window_Touchoff", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_Touchoff: public Ui_Window_Touchoff {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_TOUCHOFF_H
