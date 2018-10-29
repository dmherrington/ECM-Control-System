/********************************************************************************
** Form generated from reading UI file 'window_munk_temperature_status.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_MUNK_TEMPERATURE_STATUS_H
#define UI_WINDOW_MUNK_TEMPERATURE_STATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_MunkTemperatureStatus
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_boardNumber;
    QLabel *label_Temp1;
    QLabel *label_Temp2;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_MunkTemperatureStatus)
    {
        if (Window_MunkTemperatureStatus->objectName().isEmpty())
            Window_MunkTemperatureStatus->setObjectName(QStringLiteral("Window_MunkTemperatureStatus"));
        Window_MunkTemperatureStatus->resize(394, 118);
        Window_MunkTemperatureStatus->setStyleSheet(QLatin1String("QMenuBar{\n"
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
        centralwidget = new QWidget(Window_MunkTemperatureStatus);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_boardNumber = new QLabel(centralwidget);
        label_boardNumber->setObjectName(QStringLiteral("label_boardNumber"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_boardNumber->sizePolicy().hasHeightForWidth());
        label_boardNumber->setSizePolicy(sizePolicy);
        label_boardNumber->setMinimumSize(QSize(120, 0));
        label_boardNumber->setMaximumSize(QSize(16777215, 25));
        QFont font;
        font.setPointSize(12);
        label_boardNumber->setFont(font);
        label_boardNumber->setFrameShape(QFrame::Box);
        label_boardNumber->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_boardNumber);

        label_Temp1 = new QLabel(centralwidget);
        label_Temp1->setObjectName(QStringLiteral("label_Temp1"));
        sizePolicy.setHeightForWidth(label_Temp1->sizePolicy().hasHeightForWidth());
        label_Temp1->setSizePolicy(sizePolicy);
        label_Temp1->setMinimumSize(QSize(120, 0));
        label_Temp1->setMaximumSize(QSize(16777215, 25));
        label_Temp1->setFont(font);
        label_Temp1->setFrameShape(QFrame::Box);
        label_Temp1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_Temp1);

        label_Temp2 = new QLabel(centralwidget);
        label_Temp2->setObjectName(QStringLiteral("label_Temp2"));
        sizePolicy.setHeightForWidth(label_Temp2->sizePolicy().hasHeightForWidth());
        label_Temp2->setSizePolicy(sizePolicy);
        label_Temp2->setMinimumSize(QSize(120, 0));
        label_Temp2->setMaximumSize(QSize(16777215, 25));
        label_Temp2->setFont(font);
        label_Temp2->setFrameShape(QFrame::Box);
        label_Temp2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_Temp2);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalSpacer = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        Window_MunkTemperatureStatus->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_MunkTemperatureStatus);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 394, 40));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        Window_MunkTemperatureStatus->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_MunkTemperatureStatus);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Window_MunkTemperatureStatus->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp->menuAction());

        retranslateUi(Window_MunkTemperatureStatus);

        QMetaObject::connectSlotsByName(Window_MunkTemperatureStatus);
    } // setupUi

    void retranslateUi(QMainWindow *Window_MunkTemperatureStatus)
    {
        Window_MunkTemperatureStatus->setWindowTitle(QApplication::translate("Window_MunkTemperatureStatus", "MainWindow", nullptr));
        label_boardNumber->setText(QApplication::translate("Window_MunkTemperatureStatus", "Board Number", nullptr));
        label_Temp1->setText(QApplication::translate("Window_MunkTemperatureStatus", "Temperature F", nullptr));
        label_Temp2->setText(QApplication::translate("Window_MunkTemperatureStatus", "Temperature F", nullptr));
        menuFile->setTitle(QApplication::translate("Window_MunkTemperatureStatus", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("Window_MunkTemperatureStatus", "Edit", nullptr));
        menuTools->setTitle(QApplication::translate("Window_MunkTemperatureStatus", "Tools", nullptr));
        menuHelp->setTitle(QApplication::translate("Window_MunkTemperatureStatus", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_MunkTemperatureStatus: public Ui_Window_MunkTemperatureStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_MUNK_TEMPERATURE_STATUS_H
