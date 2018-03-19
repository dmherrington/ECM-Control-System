/********************************************************************************
** Form generated from reading UI file 'window_munk_power_supply.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "LED.h"
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
    QGridLayout *gridLayout;
    WidgetSegmentTimeDisplay *segmentWidget;
    QFormLayout *formLayout;
    QLabel *label;
    LED *widget_connection;
    QPushButton *pushButton_AddSegment;
    QPushButton *pushButton_transmit;
    QProgressBar *progressBar;
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
        Window_MunkPowerSupply->resize(524, 330);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Window_MunkPowerSupply->sizePolicy().hasHeightForWidth());
        Window_MunkPowerSupply->setSizePolicy(sizePolicy);
        Window_MunkPowerSupply->setMinimumSize(QSize(524, 330));
        Window_MunkPowerSupply->setMaximumSize(QSize(16777215, 330));
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
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
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

        gridLayout->addWidget(segmentWidget, 0, 0, 1, 4);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(90, 30));
        label->setMaximumSize(QSize(90, 30));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        widget_connection = new LED(centralwidget);
        widget_connection->setObjectName(QStringLiteral("widget_connection"));
        sizePolicy2.setHeightForWidth(widget_connection->sizePolicy().hasHeightForWidth());
        widget_connection->setSizePolicy(sizePolicy2);
        widget_connection->setMinimumSize(QSize(30, 30));
        widget_connection->setMaximumSize(QSize(30, 30));

        formLayout->setWidget(0, QFormLayout::FieldRole, widget_connection);


        gridLayout->addLayout(formLayout, 1, 0, 1, 1);

        pushButton_AddSegment = new QPushButton(centralwidget);
        pushButton_AddSegment->setObjectName(QStringLiteral("pushButton_AddSegment"));
        sizePolicy2.setHeightForWidth(pushButton_AddSegment->sizePolicy().hasHeightForWidth());
        pushButton_AddSegment->setSizePolicy(sizePolicy2);
        pushButton_AddSegment->setMinimumSize(QSize(80, 30));
        pushButton_AddSegment->setFont(font);
        pushButton_AddSegment->setFlat(false);

        gridLayout->addWidget(pushButton_AddSegment, 1, 1, 1, 1);

        pushButton_transmit = new QPushButton(centralwidget);
        pushButton_transmit->setObjectName(QStringLiteral("pushButton_transmit"));
        sizePolicy2.setHeightForWidth(pushButton_transmit->sizePolicy().hasHeightForWidth());
        pushButton_transmit->setSizePolicy(sizePolicy2);
        pushButton_transmit->setMinimumSize(QSize(100, 30));
        pushButton_transmit->setFont(font);
        pushButton_transmit->setToolTipDuration(-1);

        gridLayout->addWidget(pushButton_transmit, 1, 2, 1, 1);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 1, 3, 1, 1);

        Window_MunkPowerSupply->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_MunkPowerSupply);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 524, 40));
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
        Window_MunkPowerSupply->setWindowTitle(QApplication::translate("Window_MunkPowerSupply", "Munk Power Supply Control", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("Window_MunkPowerSupply", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("Window_MunkPowerSupply", "Save", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("Window_MunkPowerSupply", "Save As", Q_NULLPTR));
        actionClose->setText(QApplication::translate("Window_MunkPowerSupply", "Close", Q_NULLPTR));
        actionOpen_Connection->setText(QApplication::translate("Window_MunkPowerSupply", "Open Connection", Q_NULLPTR));
        actionClose_Connection->setText(QApplication::translate("Window_MunkPowerSupply", "Close Connection", Q_NULLPTR));
        actionTX_To_Munk->setText(QApplication::translate("Window_MunkPowerSupply", "Transmit Parameters", Q_NULLPTR));
        actionRead_Parameters->setText(QApplication::translate("Window_MunkPowerSupply", "Read Parameters", Q_NULLPTR));
        label->setText(QApplication::translate("Window_MunkPowerSupply", "Connected:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_AddSegment->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_AddSegment->setText(QApplication::translate("Window_MunkPowerSupply", "ADD", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_transmit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_transmit->setText(QApplication::translate("Window_MunkPowerSupply", "TRANSMIT", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("Window_MunkPowerSupply", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("Window_MunkPowerSupply", "Edit", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("Window_MunkPowerSupply", "Tools", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("Window_MunkPowerSupply", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Window_MunkPowerSupply: public Ui_Window_MunkPowerSupply {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_MUNK_POWER_SUPPLY_H
