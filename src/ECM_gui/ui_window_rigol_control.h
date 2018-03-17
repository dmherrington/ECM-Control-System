/********************************************************************************
** Form generated from reading UI file 'window_rigol_control.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_RIGOL_CONTROL_H
#define UI_WINDOW_RIGOL_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "LED.h"

QT_BEGIN_NAMESPACE

class Ui_Window_RigolControl
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_MAX;
    QRadioButton *radioButton_BASE;
    QRadioButton *radioButton_OVERSHOOT;
    QRadioButton *radioButton_PERIOD;
    QRadioButton *radioButton_PWIDTH;
    QRadioButton *radioButton_RDELAY;
    QRadioButton *radioButton_MIN;
    QRadioButton *radioButton_AMP;
    QRadioButton *radioButton_PRESHOOT;
    QRadioButton *radioButton_FREQUENCY;
    QRadioButton *radioButton_NWIDTH;
    QRadioButton *radioButton_FDELAY;
    QRadioButton *radioButton_VPP;
    QRadioButton *radioButton_AVG;
    QRadioButton *radioButton_MAREA;
    QRadioButton *radioButton_RTIME;
    QRadioButton *radioButton_PDUTY;
    QRadioButton *radioButton_RPHASE;
    QRadioButton *radioButton_VTOP;
    QRadioButton *radioButton_RMS;
    QRadioButton *radioButton_MPAREA;
    QRadioButton *radioButton_FTIME;
    QRadioButton *radioButton_NDUTY;
    QRadioButton *radioButton_FPHASE;
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
        Window_RigolControl->setStyleSheet(QLatin1String("QMainWindow{\n"
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
        centralwidget = new QWidget(Window_RigolControl);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radioButton_MAX = new QRadioButton(centralwidget);
        radioButton_MAX->setObjectName(QStringLiteral("radioButton_MAX"));
        radioButton_MAX->setMinimumSize(QSize(0, 20));
        radioButton_MAX->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        radioButton_MAX->setFont(font);

        gridLayout->addWidget(radioButton_MAX, 0, 0, 1, 1);

        radioButton_BASE = new QRadioButton(centralwidget);
        radioButton_BASE->setObjectName(QStringLiteral("radioButton_BASE"));
        radioButton_BASE->setMinimumSize(QSize(0, 20));
        radioButton_BASE->setMaximumSize(QSize(16777215, 20));
        radioButton_BASE->setFont(font);

        gridLayout->addWidget(radioButton_BASE, 0, 1, 1, 1);

        radioButton_OVERSHOOT = new QRadioButton(centralwidget);
        radioButton_OVERSHOOT->setObjectName(QStringLiteral("radioButton_OVERSHOOT"));
        radioButton_OVERSHOOT->setMinimumSize(QSize(0, 20));
        radioButton_OVERSHOOT->setMaximumSize(QSize(16777215, 20));
        radioButton_OVERSHOOT->setFont(font);

        gridLayout->addWidget(radioButton_OVERSHOOT, 0, 2, 1, 1);

        radioButton_PERIOD = new QRadioButton(centralwidget);
        radioButton_PERIOD->setObjectName(QStringLiteral("radioButton_PERIOD"));
        radioButton_PERIOD->setMinimumSize(QSize(0, 20));
        radioButton_PERIOD->setMaximumSize(QSize(16777215, 20));
        radioButton_PERIOD->setFont(font);

        gridLayout->addWidget(radioButton_PERIOD, 0, 3, 1, 1);

        radioButton_PWIDTH = new QRadioButton(centralwidget);
        radioButton_PWIDTH->setObjectName(QStringLiteral("radioButton_PWIDTH"));
        radioButton_PWIDTH->setMinimumSize(QSize(0, 20));
        radioButton_PWIDTH->setMaximumSize(QSize(16777215, 20));
        radioButton_PWIDTH->setFont(font);

        gridLayout->addWidget(radioButton_PWIDTH, 0, 4, 1, 1);

        radioButton_RDELAY = new QRadioButton(centralwidget);
        radioButton_RDELAY->setObjectName(QStringLiteral("radioButton_RDELAY"));
        radioButton_RDELAY->setMinimumSize(QSize(0, 20));
        radioButton_RDELAY->setMaximumSize(QSize(16777215, 20));
        radioButton_RDELAY->setFont(font);

        gridLayout->addWidget(radioButton_RDELAY, 0, 5, 1, 1);

        radioButton_MIN = new QRadioButton(centralwidget);
        radioButton_MIN->setObjectName(QStringLiteral("radioButton_MIN"));
        radioButton_MIN->setMinimumSize(QSize(0, 20));
        radioButton_MIN->setMaximumSize(QSize(16777215, 20));
        radioButton_MIN->setFont(font);

        gridLayout->addWidget(radioButton_MIN, 1, 0, 1, 1);

        radioButton_AMP = new QRadioButton(centralwidget);
        radioButton_AMP->setObjectName(QStringLiteral("radioButton_AMP"));
        radioButton_AMP->setMinimumSize(QSize(0, 20));
        radioButton_AMP->setMaximumSize(QSize(16777215, 20));
        radioButton_AMP->setFont(font);

        gridLayout->addWidget(radioButton_AMP, 1, 1, 1, 1);

        radioButton_PRESHOOT = new QRadioButton(centralwidget);
        radioButton_PRESHOOT->setObjectName(QStringLiteral("radioButton_PRESHOOT"));
        radioButton_PRESHOOT->setMinimumSize(QSize(0, 20));
        radioButton_PRESHOOT->setMaximumSize(QSize(16777215, 20));
        radioButton_PRESHOOT->setFont(font);

        gridLayout->addWidget(radioButton_PRESHOOT, 1, 2, 1, 1);

        radioButton_FREQUENCY = new QRadioButton(centralwidget);
        radioButton_FREQUENCY->setObjectName(QStringLiteral("radioButton_FREQUENCY"));
        radioButton_FREQUENCY->setMinimumSize(QSize(0, 20));
        radioButton_FREQUENCY->setMaximumSize(QSize(16777215, 20));
        radioButton_FREQUENCY->setFont(font);

        gridLayout->addWidget(radioButton_FREQUENCY, 1, 3, 1, 1);

        radioButton_NWIDTH = new QRadioButton(centralwidget);
        radioButton_NWIDTH->setObjectName(QStringLiteral("radioButton_NWIDTH"));
        radioButton_NWIDTH->setMinimumSize(QSize(0, 20));
        radioButton_NWIDTH->setMaximumSize(QSize(16777215, 20));
        radioButton_NWIDTH->setFont(font);

        gridLayout->addWidget(radioButton_NWIDTH, 1, 4, 1, 1);

        radioButton_FDELAY = new QRadioButton(centralwidget);
        radioButton_FDELAY->setObjectName(QStringLiteral("radioButton_FDELAY"));
        radioButton_FDELAY->setMinimumSize(QSize(0, 20));
        radioButton_FDELAY->setMaximumSize(QSize(16777215, 20));
        radioButton_FDELAY->setFont(font);

        gridLayout->addWidget(radioButton_FDELAY, 1, 5, 1, 1);

        radioButton_VPP = new QRadioButton(centralwidget);
        radioButton_VPP->setObjectName(QStringLiteral("radioButton_VPP"));
        radioButton_VPP->setMinimumSize(QSize(0, 20));
        radioButton_VPP->setMaximumSize(QSize(16777215, 20));
        radioButton_VPP->setFont(font);

        gridLayout->addWidget(radioButton_VPP, 2, 0, 1, 1);

        radioButton_AVG = new QRadioButton(centralwidget);
        radioButton_AVG->setObjectName(QStringLiteral("radioButton_AVG"));
        radioButton_AVG->setMinimumSize(QSize(0, 20));
        radioButton_AVG->setMaximumSize(QSize(16777215, 20));
        radioButton_AVG->setFont(font);

        gridLayout->addWidget(radioButton_AVG, 2, 1, 1, 1);

        radioButton_MAREA = new QRadioButton(centralwidget);
        radioButton_MAREA->setObjectName(QStringLiteral("radioButton_MAREA"));
        radioButton_MAREA->setMinimumSize(QSize(0, 20));
        radioButton_MAREA->setMaximumSize(QSize(16777215, 20));
        radioButton_MAREA->setFont(font);

        gridLayout->addWidget(radioButton_MAREA, 2, 2, 1, 1);

        radioButton_RTIME = new QRadioButton(centralwidget);
        radioButton_RTIME->setObjectName(QStringLiteral("radioButton_RTIME"));
        radioButton_RTIME->setMinimumSize(QSize(0, 20));
        radioButton_RTIME->setMaximumSize(QSize(16777215, 20));
        radioButton_RTIME->setFont(font);

        gridLayout->addWidget(radioButton_RTIME, 2, 3, 1, 1);

        radioButton_PDUTY = new QRadioButton(centralwidget);
        radioButton_PDUTY->setObjectName(QStringLiteral("radioButton_PDUTY"));
        radioButton_PDUTY->setMinimumSize(QSize(0, 20));
        radioButton_PDUTY->setMaximumSize(QSize(16777215, 20));
        radioButton_PDUTY->setFont(font);

        gridLayout->addWidget(radioButton_PDUTY, 2, 4, 1, 1);

        radioButton_RPHASE = new QRadioButton(centralwidget);
        radioButton_RPHASE->setObjectName(QStringLiteral("radioButton_RPHASE"));
        radioButton_RPHASE->setMinimumSize(QSize(0, 20));
        radioButton_RPHASE->setMaximumSize(QSize(16777215, 20));
        radioButton_RPHASE->setFont(font);

        gridLayout->addWidget(radioButton_RPHASE, 2, 5, 1, 1);

        radioButton_VTOP = new QRadioButton(centralwidget);
        radioButton_VTOP->setObjectName(QStringLiteral("radioButton_VTOP"));
        radioButton_VTOP->setMinimumSize(QSize(0, 20));
        radioButton_VTOP->setMaximumSize(QSize(16777215, 20));
        radioButton_VTOP->setFont(font);

        gridLayout->addWidget(radioButton_VTOP, 3, 0, 1, 1);

        radioButton_RMS = new QRadioButton(centralwidget);
        radioButton_RMS->setObjectName(QStringLiteral("radioButton_RMS"));
        radioButton_RMS->setMinimumSize(QSize(0, 20));
        radioButton_RMS->setMaximumSize(QSize(16777215, 20));
        radioButton_RMS->setFont(font);

        gridLayout->addWidget(radioButton_RMS, 3, 1, 1, 1);

        radioButton_MPAREA = new QRadioButton(centralwidget);
        radioButton_MPAREA->setObjectName(QStringLiteral("radioButton_MPAREA"));
        radioButton_MPAREA->setMinimumSize(QSize(0, 20));
        radioButton_MPAREA->setMaximumSize(QSize(16777215, 20));
        radioButton_MPAREA->setFont(font);

        gridLayout->addWidget(radioButton_MPAREA, 3, 2, 1, 1);

        radioButton_FTIME = new QRadioButton(centralwidget);
        radioButton_FTIME->setObjectName(QStringLiteral("radioButton_FTIME"));
        radioButton_FTIME->setMinimumSize(QSize(0, 20));
        radioButton_FTIME->setMaximumSize(QSize(16777215, 20));
        radioButton_FTIME->setFont(font);

        gridLayout->addWidget(radioButton_FTIME, 3, 3, 1, 1);

        radioButton_NDUTY = new QRadioButton(centralwidget);
        radioButton_NDUTY->setObjectName(QStringLiteral("radioButton_NDUTY"));
        radioButton_NDUTY->setMinimumSize(QSize(0, 20));
        radioButton_NDUTY->setMaximumSize(QSize(16777215, 20));
        radioButton_NDUTY->setFont(font);

        gridLayout->addWidget(radioButton_NDUTY, 3, 4, 1, 1);

        radioButton_FPHASE = new QRadioButton(centralwidget);
        radioButton_FPHASE->setObjectName(QStringLiteral("radioButton_FPHASE"));
        radioButton_FPHASE->setMinimumSize(QSize(0, 20));
        radioButton_FPHASE->setMaximumSize(QSize(16777215, 20));
        radioButton_FPHASE->setFont(font);

        gridLayout->addWidget(radioButton_FPHASE, 3, 5, 1, 1);

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
        QFont font1;
        font1.setPointSize(10);
        label_Connection->setFont(font1);
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
        comboBox_Channel->setFont(font1);

        horizontalLayout->addWidget(comboBox_Channel);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_Done = new QPushButton(centralwidget);
        pushButton_Done->setObjectName(QStringLiteral("pushButton_Done"));
        sizePolicy1.setHeightForWidth(pushButton_Done->sizePolicy().hasHeightForWidth());
        pushButton_Done->setSizePolicy(sizePolicy1);
        pushButton_Done->setMinimumSize(QSize(100, 40));
        pushButton_Done->setMaximumSize(QSize(100, 40));
        QFont font2;
        font2.setPointSize(12);
        pushButton_Done->setFont(font2);

        horizontalLayout->addWidget(pushButton_Done);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 6);

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

        retranslateUi(Window_RigolControl);

        QMetaObject::connectSlotsByName(Window_RigolControl);
    } // setupUi

    void retranslateUi(QMainWindow *Window_RigolControl)
    {
        Window_RigolControl->setWindowTitle(QApplication::translate("Window_RigolControl", "MainWindow", nullptr));
        radioButton_MAX->setText(QApplication::translate("Window_RigolControl", "MAX", nullptr));
        radioButton_BASE->setText(QApplication::translate("Window_RigolControl", "BASE", nullptr));
        radioButton_OVERSHOOT->setText(QApplication::translate("Window_RigolControl", "OVERSHOOT", nullptr));
        radioButton_PERIOD->setText(QApplication::translate("Window_RigolControl", "PERIOD", nullptr));
        radioButton_PWIDTH->setText(QApplication::translate("Window_RigolControl", "PWIDTH", nullptr));
        radioButton_RDELAY->setText(QApplication::translate("Window_RigolControl", "RDELAY", nullptr));
        radioButton_MIN->setText(QApplication::translate("Window_RigolControl", "MIN", nullptr));
        radioButton_AMP->setText(QApplication::translate("Window_RigolControl", "AMP", nullptr));
        radioButton_PRESHOOT->setText(QApplication::translate("Window_RigolControl", "PRESHOOT", nullptr));
        radioButton_FREQUENCY->setText(QApplication::translate("Window_RigolControl", "FREQUENCY", nullptr));
        radioButton_NWIDTH->setText(QApplication::translate("Window_RigolControl", "NWIDTH", nullptr));
        radioButton_FDELAY->setText(QApplication::translate("Window_RigolControl", "FDELAY", nullptr));
        radioButton_VPP->setText(QApplication::translate("Window_RigolControl", "VPP", nullptr));
        radioButton_AVG->setText(QApplication::translate("Window_RigolControl", "AVG", nullptr));
        radioButton_MAREA->setText(QApplication::translate("Window_RigolControl", "MAREA", nullptr));
        radioButton_RTIME->setText(QApplication::translate("Window_RigolControl", "RTIME", nullptr));
        radioButton_PDUTY->setText(QApplication::translate("Window_RigolControl", "PDUTY", nullptr));
        radioButton_RPHASE->setText(QApplication::translate("Window_RigolControl", "RPHASE", nullptr));
        radioButton_VTOP->setText(QApplication::translate("Window_RigolControl", "VTOP", nullptr));
        radioButton_RMS->setText(QApplication::translate("Window_RigolControl", "RMS", nullptr));
        radioButton_MPAREA->setText(QApplication::translate("Window_RigolControl", "MPAREA", nullptr));
        radioButton_FTIME->setText(QApplication::translate("Window_RigolControl", "FTIME", nullptr));
        radioButton_NDUTY->setText(QApplication::translate("Window_RigolControl", "NDUTY", nullptr));
        radioButton_FPHASE->setText(QApplication::translate("Window_RigolControl", "FPHASE", nullptr));
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
