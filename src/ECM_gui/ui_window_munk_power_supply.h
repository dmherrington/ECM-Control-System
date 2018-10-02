/********************************************************************************
** Form generated from reading UI file 'window_munk_power_supply.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_MUNK_POWER_SUPPLY_H
#define UI_WINDOW_MUNK_POWER_SUPPLY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "LED.h"
#include "misc_dialogs/widget_device_fault.h"
#include "munk_dialog/widget_segment_time_display.h"

QT_BEGIN_NAMESPACE

class Ui_Window_MunkPowerSupply
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionClose;
    QAction *actionOpen_Connection;
    QAction *actionClose_Connection;
    QAction *actionTX_To_Munk;
    QAction *actionRead_Parameters;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    WidgetSegmentTimeDisplay *segmentWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_singlePulse;
    QRadioButton *radioButton_continuousPulse;
    QRadioButton *radioButton_specifiedPulses;
    QSpinBox *spinBox_NumPulses;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    LED *widget_connection;
    QPushButton *pushButton_AddSegment;
    QPushButton *pushButton_transmit;
    QProgressBar *progressBar;
    Widget_DeviceFault *widget_DeviceFault;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_MunkPowerSupply)
    {
        if (Window_MunkPowerSupply->objectName().isEmpty())
            Window_MunkPowerSupply->setObjectName(QStringLiteral("Window_MunkPowerSupply"));
        Window_MunkPowerSupply->setWindowModality(Qt::NonModal);
        Window_MunkPowerSupply->resize(600, 400);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Window_MunkPowerSupply->sizePolicy().hasHeightForWidth());
        Window_MunkPowerSupply->setSizePolicy(sizePolicy);
        Window_MunkPowerSupply->setMinimumSize(QSize(600, 400));
        Window_MunkPowerSupply->setMaximumSize(QSize(16777215, 450));
        Window_MunkPowerSupply->setStyleSheet(QLatin1String("QMenuBar{\n"
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
        Window_MunkPowerSupply->setUnifiedTitleAndToolBarOnMac(false);
        actionOpen = new QAction(Window_MunkPowerSupply);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(Window_MunkPowerSupply);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(Window_MunkPowerSupply);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionClose = new QAction(Window_MunkPowerSupply);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionOpen_Connection = new QAction(Window_MunkPowerSupply);
        actionOpen_Connection->setObjectName(QStringLiteral("actionOpen_Connection"));
        actionClose_Connection = new QAction(Window_MunkPowerSupply);
        actionClose_Connection->setObjectName(QStringLiteral("actionClose_Connection"));
        actionTX_To_Munk = new QAction(Window_MunkPowerSupply);
        actionTX_To_Munk->setObjectName(QStringLiteral("actionTX_To_Munk"));
        actionRead_Parameters = new QAction(Window_MunkPowerSupply);
        actionRead_Parameters->setObjectName(QStringLiteral("actionRead_Parameters"));
        centralwidget = new QWidget(Window_MunkPowerSupply);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        segmentWidget = new WidgetSegmentTimeDisplay(centralwidget);
        segmentWidget->setObjectName(QStringLiteral("segmentWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(segmentWidget->sizePolicy().hasHeightForWidth());
        segmentWidget->setSizePolicy(sizePolicy1);
        segmentWidget->setMinimumSize(QSize(200, 210));
        segmentWidget->setAutoFillBackground(false);
        segmentWidget->setStyleSheet(QLatin1String("QMainWindow{\n"
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

        gridLayout_2->addWidget(segmentWidget, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radioButton_singlePulse = new QRadioButton(groupBox);
        radioButton_singlePulse->setObjectName(QStringLiteral("radioButton_singlePulse"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(radioButton_singlePulse->sizePolicy().hasHeightForWidth());
        radioButton_singlePulse->setSizePolicy(sizePolicy2);
        radioButton_singlePulse->setMinimumSize(QSize(130, 0));
        QFont font;
        font.setPointSize(10);
        radioButton_singlePulse->setFont(font);
        radioButton_singlePulse->setChecked(true);

        gridLayout->addWidget(radioButton_singlePulse, 0, 0, 1, 1);

        radioButton_continuousPulse = new QRadioButton(groupBox);
        radioButton_continuousPulse->setObjectName(QStringLiteral("radioButton_continuousPulse"));
        sizePolicy2.setHeightForWidth(radioButton_continuousPulse->sizePolicy().hasHeightForWidth());
        radioButton_continuousPulse->setSizePolicy(sizePolicy2);
        radioButton_continuousPulse->setMinimumSize(QSize(160, 0));
        radioButton_continuousPulse->setFont(font);
        radioButton_continuousPulse->setChecked(false);

        gridLayout->addWidget(radioButton_continuousPulse, 0, 1, 1, 1);

        radioButton_specifiedPulses = new QRadioButton(groupBox);
        radioButton_specifiedPulses->setObjectName(QStringLiteral("radioButton_specifiedPulses"));
        sizePolicy2.setHeightForWidth(radioButton_specifiedPulses->sizePolicy().hasHeightForWidth());
        radioButton_specifiedPulses->setSizePolicy(sizePolicy2);
        radioButton_specifiedPulses->setMinimumSize(QSize(180, 0));
        radioButton_specifiedPulses->setFont(font);

        gridLayout->addWidget(radioButton_specifiedPulses, 0, 2, 1, 1);

        spinBox_NumPulses = new QSpinBox(groupBox);
        spinBox_NumPulses->setObjectName(QStringLiteral("spinBox_NumPulses"));
        spinBox_NumPulses->setMinimumSize(QSize(60, 0));
        spinBox_NumPulses->setFont(font);
        spinBox_NumPulses->setMinimum(0);
        spinBox_NumPulses->setMaximum(255);
        spinBox_NumPulses->setValue(0);

        gridLayout->addWidget(spinBox_NumPulses, 0, 3, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setMinimumSize(QSize(90, 30));
        label->setMaximumSize(QSize(90, 30));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        widget_connection = new LED(centralwidget);
        widget_connection->setObjectName(QStringLiteral("widget_connection"));
        sizePolicy3.setHeightForWidth(widget_connection->sizePolicy().hasHeightForWidth());
        widget_connection->setSizePolicy(sizePolicy3);
        widget_connection->setMinimumSize(QSize(30, 30));
        widget_connection->setMaximumSize(QSize(30, 30));

        formLayout->setWidget(0, QFormLayout::FieldRole, widget_connection);


        horizontalLayout->addLayout(formLayout);

        pushButton_AddSegment = new QPushButton(centralwidget);
        pushButton_AddSegment->setObjectName(QStringLiteral("pushButton_AddSegment"));
        sizePolicy3.setHeightForWidth(pushButton_AddSegment->sizePolicy().hasHeightForWidth());
        pushButton_AddSegment->setSizePolicy(sizePolicy3);
        pushButton_AddSegment->setMinimumSize(QSize(80, 30));
        pushButton_AddSegment->setFont(font1);
        pushButton_AddSegment->setFlat(false);

        horizontalLayout->addWidget(pushButton_AddSegment);

        pushButton_transmit = new QPushButton(centralwidget);
        pushButton_transmit->setObjectName(QStringLiteral("pushButton_transmit"));
        sizePolicy3.setHeightForWidth(pushButton_transmit->sizePolicy().hasHeightForWidth());
        pushButton_transmit->setSizePolicy(sizePolicy3);
        pushButton_transmit->setMinimumSize(QSize(100, 30));
        pushButton_transmit->setFont(font1);
        pushButton_transmit->setToolTipDuration(-1);

        horizontalLayout->addWidget(pushButton_transmit);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 1);

        widget_DeviceFault = new Widget_DeviceFault(centralwidget);
        widget_DeviceFault->setObjectName(QStringLiteral("widget_DeviceFault"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget_DeviceFault->sizePolicy().hasHeightForWidth());
        widget_DeviceFault->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(widget_DeviceFault, 3, 0, 1, 1);

        Window_MunkPowerSupply->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_MunkPowerSupply);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 40));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        Window_MunkPowerSupply->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_MunkPowerSupply);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Window_MunkPowerSupply->setStatusBar(statusbar);

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
        menuTools->addAction(actionOpen_Connection);
        menuTools->addAction(actionClose_Connection);
        menuTools->addSeparator();
        menuTools->addAction(actionTX_To_Munk);
        menuTools->addAction(actionRead_Parameters);

        retranslateUi(Window_MunkPowerSupply);

        QMetaObject::connectSlotsByName(Window_MunkPowerSupply);
    } // setupUi

    void retranslateUi(QMainWindow *Window_MunkPowerSupply)
    {
        Window_MunkPowerSupply->setWindowTitle(QApplication::translate("Window_MunkPowerSupply", "Munk Power Supply Control", nullptr));
        actionOpen->setText(QApplication::translate("Window_MunkPowerSupply", "Open", nullptr));
        actionSave->setText(QApplication::translate("Window_MunkPowerSupply", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("Window_MunkPowerSupply", "Save As", nullptr));
        actionClose->setText(QApplication::translate("Window_MunkPowerSupply", "Close", nullptr));
        actionOpen_Connection->setText(QApplication::translate("Window_MunkPowerSupply", "Open Connection", nullptr));
        actionClose_Connection->setText(QApplication::translate("Window_MunkPowerSupply", "Close Connection", nullptr));
        actionTX_To_Munk->setText(QApplication::translate("Window_MunkPowerSupply", "Transmit Parameters", nullptr));
        actionRead_Parameters->setText(QApplication::translate("Window_MunkPowerSupply", "Read Parameters", nullptr));
        groupBox->setTitle(QString());
        radioButton_singlePulse->setText(QApplication::translate("Window_MunkPowerSupply", "Single Pulse Mode", nullptr));
        radioButton_continuousPulse->setText(QApplication::translate("Window_MunkPowerSupply", "Continuous Pulse Mode", nullptr));
        radioButton_specifiedPulses->setText(QApplication::translate("Window_MunkPowerSupply", "Specified Number of Pulses", nullptr));
        label->setText(QApplication::translate("Window_MunkPowerSupply", "Connected:", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_AddSegment->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_AddSegment->setText(QApplication::translate("Window_MunkPowerSupply", "ADD", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_transmit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_transmit->setText(QApplication::translate("Window_MunkPowerSupply", "TRANSMIT", nullptr));
        menuFile->setTitle(QApplication::translate("Window_MunkPowerSupply", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("Window_MunkPowerSupply", "Edit", nullptr));
        menuTools->setTitle(QApplication::translate("Window_MunkPowerSupply", "Tools", nullptr));
        menuHelp->setTitle(QApplication::translate("Window_MunkPowerSupply", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_MunkPowerSupply: public Ui_Window_MunkPowerSupply {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_MUNK_POWER_SUPPLY_H
