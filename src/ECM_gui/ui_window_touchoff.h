/********************************************************************************
** Form generated from reading UI file 'window_touchoff.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_TOUCHOFF_H
#define UI_WINDOW_TOUCHOFF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_Touchoff
{
public:
    QWidget *centralwidget;
    QFrame *frame_TouchoffControl;
    QPushButton *pushButton_TouchoffRef;
    QSpinBox *spinBox_TouchoffRef;
    QSpinBox *spinBox_InitialGap;
    QPushButton *pushButton_RunTouchoff;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_Touchoff)
    {
        if (Window_Touchoff->objectName().isEmpty())
            Window_Touchoff->setObjectName(QStringLiteral("Window_Touchoff"));
        Window_Touchoff->resize(567, 177);
        Window_Touchoff->setStyleSheet(QLatin1String("QMainWindow{\n"
"background-color:#1d1d1d;\n"
"}\n"
"\n"
"QMenuBar{\n"
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
"background-color:qlineargradient"
                        "(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));\n"
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
""
                        "QPushButton:pressed{\n"
"background-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(29, 29, 29, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));\n"
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
        centralwidget = new QWidget(Window_Touchoff);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        frame_TouchoffControl = new QFrame(centralwidget);
        frame_TouchoffControl->setObjectName(QStringLiteral("frame_TouchoffControl"));
        frame_TouchoffControl->setGeometry(QRect(20, 10, 511, 81));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_TouchoffControl->sizePolicy().hasHeightForWidth());
        frame_TouchoffControl->setSizePolicy(sizePolicy);
        frame_TouchoffControl->setMinimumSize(QSize(350, 70));
        frame_TouchoffControl->setFrameShape(QFrame::Box);
        frame_TouchoffControl->setFrameShadow(QFrame::Plain);
        frame_TouchoffControl->setLineWidth(2);
        pushButton_TouchoffRef = new QPushButton(frame_TouchoffControl);
        pushButton_TouchoffRef->setObjectName(QStringLiteral("pushButton_TouchoffRef"));
        pushButton_TouchoffRef->setGeometry(QRect(70, 10, 130, 30));
        sizePolicy.setHeightForWidth(pushButton_TouchoffRef->sizePolicy().hasHeightForWidth());
        pushButton_TouchoffRef->setSizePolicy(sizePolicy);
        pushButton_TouchoffRef->setMinimumSize(QSize(130, 30));
        QFont font;
        font.setPointSize(12);
        pushButton_TouchoffRef->setFont(font);
        spinBox_TouchoffRef = new QSpinBox(frame_TouchoffControl);
        spinBox_TouchoffRef->setObjectName(QStringLiteral("spinBox_TouchoffRef"));
        spinBox_TouchoffRef->setGeometry(QRect(261, 11, 112, 30));
        sizePolicy.setHeightForWidth(spinBox_TouchoffRef->sizePolicy().hasHeightForWidth());
        spinBox_TouchoffRef->setSizePolicy(sizePolicy);
        spinBox_TouchoffRef->setMinimumSize(QSize(112, 30));
        spinBox_TouchoffRef->setFont(font);
        spinBox_TouchoffRef->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_TouchoffRef->setMinimum(0);
        spinBox_TouchoffRef->setMaximum(10000);
        spinBox_TouchoffRef->setSingleStep(10);
        spinBox_TouchoffRef->setValue(0);
        spinBox_InitialGap = new QSpinBox(frame_TouchoffControl);
        spinBox_InitialGap->setObjectName(QStringLiteral("spinBox_InitialGap"));
        spinBox_InitialGap->setGeometry(QRect(261, 44, 180, 30));
        spinBox_InitialGap->setMinimumSize(QSize(180, 30));
        spinBox_InitialGap->setFont(font);
        spinBox_InitialGap->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_RunTouchoff = new QPushButton(frame_TouchoffControl);
        pushButton_RunTouchoff->setObjectName(QStringLiteral("pushButton_RunTouchoff"));
        pushButton_RunTouchoff->setGeometry(QRect(50, 40, 180, 30));
        sizePolicy.setHeightForWidth(pushButton_RunTouchoff->sizePolicy().hasHeightForWidth());
        pushButton_RunTouchoff->setSizePolicy(sizePolicy);
        pushButton_RunTouchoff->setMinimumSize(QSize(180, 30));
        pushButton_RunTouchoff->setFont(font);
        Window_Touchoff->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_Touchoff);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 567, 40));
        Window_Touchoff->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_Touchoff);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Window_Touchoff->setStatusBar(statusbar);

        retranslateUi(Window_Touchoff);

        QMetaObject::connectSlotsByName(Window_Touchoff);
    } // setupUi

    void retranslateUi(QMainWindow *Window_Touchoff)
    {
        Window_Touchoff->setWindowTitle(QApplication::translate("Window_Touchoff", "MainWindow", nullptr));
        pushButton_TouchoffRef->setText(QApplication::translate("Window_Touchoff", "Set Touchoff Ref", nullptr));
        pushButton_RunTouchoff->setText(QApplication::translate("Window_Touchoff", "Set Initial Gap", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_Touchoff: public Ui_Window_Touchoff {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_TOUCHOFF_H
