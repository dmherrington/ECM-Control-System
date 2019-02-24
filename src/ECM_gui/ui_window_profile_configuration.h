/********************************************************************************
** Form generated from reading UI file 'window_profile_configuration.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_PROFILE_CONFIGURATION_H
#define UI_WINDOW_PROFILE_CONFIGURATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_ProfileConfiguration
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionClose;
    QAction *actionMotion_Profile;
    QAction *actionNew;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_21;
    QGridLayout *gridLayout_20;
    QLabel *label_ManualControl_6;
    QSpacerItem *horizontalSpacer_22;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_ConfugrationPath;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_OpenMotionScript;
    QPushButton *pushButton_UploadMotionScript;
    QPushButton *pushButton_DownloadMotionScript;
    QSpacerItem *horizontalSpacer_6;
    QGridLayout *gridLayout;
    QLabel *label;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_AddOperation;
    QPushButton *pushButton_RemoveOperation;
    QComboBox *comboBox_ProfileType;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QCheckBox *checkBox_ShouldHomeBeIndicated;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget_OperationParameters;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_ProfileConfiguration)
    {
        if (Window_ProfileConfiguration->objectName().isEmpty())
            Window_ProfileConfiguration->setObjectName(QStringLiteral("Window_ProfileConfiguration"));
        Window_ProfileConfiguration->resize(1720, 680);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Window_ProfileConfiguration->sizePolicy().hasHeightForWidth());
        Window_ProfileConfiguration->setSizePolicy(sizePolicy);
        Window_ProfileConfiguration->setMinimumSize(QSize(1720, 680));
        Window_ProfileConfiguration->setMaximumSize(QSize(1720, 680));
        Window_ProfileConfiguration->setStyleSheet(QLatin1String("QMenuBar{\n"
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
        actionOpen = new QAction(Window_ProfileConfiguration);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(Window_ProfileConfiguration);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(Window_ProfileConfiguration);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionClose = new QAction(Window_ProfileConfiguration);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionMotion_Profile = new QAction(Window_ProfileConfiguration);
        actionMotion_Profile->setObjectName(QStringLiteral("actionMotion_Profile"));
        actionMotion_Profile->setCheckable(true);
        actionNew = new QAction(Window_ProfileConfiguration);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        centralwidget = new QWidget(Window_ProfileConfiguration);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_21);

        gridLayout_20 = new QGridLayout();
        gridLayout_20->setObjectName(QStringLiteral("gridLayout_20"));
        label_ManualControl_6 = new QLabel(centralwidget);
        label_ManualControl_6->setObjectName(QStringLiteral("label_ManualControl_6"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_ManualControl_6->sizePolicy().hasHeightForWidth());
        label_ManualControl_6->setSizePolicy(sizePolicy1);
        label_ManualControl_6->setMinimumSize(QSize(0, 32));
        label_ManualControl_6->setMaximumSize(QSize(16777215, 32));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_ManualControl_6->setFont(font);
        label_ManualControl_6->setAlignment(Qt::AlignCenter);

        gridLayout_20->addWidget(label_ManualControl_6, 0, 0, 1, 1);


        horizontalLayout_15->addLayout(gridLayout_20);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_22);


        verticalLayout_2->addLayout(horizontalLayout_15);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setPointSize(10);
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        lineEdit_ConfugrationPath = new QLineEdit(centralwidget);
        lineEdit_ConfugrationPath->setObjectName(QStringLiteral("lineEdit_ConfugrationPath"));
        lineEdit_ConfugrationPath->setFont(font1);

        verticalLayout->addWidget(lineEdit_ConfugrationPath);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_7 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_OpenMotionScript = new QPushButton(centralwidget);
        pushButton_OpenMotionScript->setObjectName(QStringLiteral("pushButton_OpenMotionScript"));
        sizePolicy.setHeightForWidth(pushButton_OpenMotionScript->sizePolicy().hasHeightForWidth());
        pushButton_OpenMotionScript->setSizePolicy(sizePolicy);
        pushButton_OpenMotionScript->setMinimumSize(QSize(140, 20));
        pushButton_OpenMotionScript->setMaximumSize(QSize(140, 20));
        pushButton_OpenMotionScript->setFont(font1);
        pushButton_OpenMotionScript->setStyleSheet(QLatin1String("QMenuBar{\n"
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
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../../Users/KenWork/Desktop/ECM-Control-System-master/src/window_GMC_variable_editor/images/add_simple.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_OpenMotionScript->setIcon(icon);

        horizontalLayout_2->addWidget(pushButton_OpenMotionScript);

        pushButton_UploadMotionScript = new QPushButton(centralwidget);
        pushButton_UploadMotionScript->setObjectName(QStringLiteral("pushButton_UploadMotionScript"));
        sizePolicy.setHeightForWidth(pushButton_UploadMotionScript->sizePolicy().hasHeightForWidth());
        pushButton_UploadMotionScript->setSizePolicy(sizePolicy);
        pushButton_UploadMotionScript->setMinimumSize(QSize(140, 20));
        pushButton_UploadMotionScript->setMaximumSize(QSize(140, 20));
        pushButton_UploadMotionScript->setFont(font1);
        pushButton_UploadMotionScript->setIcon(icon);

        horizontalLayout_2->addWidget(pushButton_UploadMotionScript);

        pushButton_DownloadMotionScript = new QPushButton(centralwidget);
        pushButton_DownloadMotionScript->setObjectName(QStringLiteral("pushButton_DownloadMotionScript"));
        sizePolicy.setHeightForWidth(pushButton_DownloadMotionScript->sizePolicy().hasHeightForWidth());
        pushButton_DownloadMotionScript->setSizePolicy(sizePolicy);
        pushButton_DownloadMotionScript->setMinimumSize(QSize(140, 20));
        pushButton_DownloadMotionScript->setMaximumSize(QSize(140, 20));
        pushButton_DownloadMotionScript->setFont(font1);
        pushButton_DownloadMotionScript->setIcon(icon);

        horizontalLayout_2->addWidget(pushButton_DownloadMotionScript);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_5);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMinimumSize(QSize(470, 200));
        listWidget->setMaximumSize(QSize(470, 200));
        listWidget->setStyleSheet(QLatin1String("QListWidget{\n"
"    color:#00ff00;\n"
"    background-color:transparent;\n"
"}"));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget->setTabKeyNavigation(true);
        listWidget->setDragEnabled(true);
        listWidget->setDragDropMode(QAbstractItemView::DragDrop);
        listWidget->setDefaultDropAction(Qt::MoveAction);
        listWidget->setAlternatingRowColors(true);
        listWidget->setResizeMode(QListView::Adjust);
        listWidget->setModelColumn(0);

        gridLayout->addWidget(listWidget, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_AddOperation = new QPushButton(centralwidget);
        pushButton_AddOperation->setObjectName(QStringLiteral("pushButton_AddOperation"));
        sizePolicy.setHeightForWidth(pushButton_AddOperation->sizePolicy().hasHeightForWidth());
        pushButton_AddOperation->setSizePolicy(sizePolicy);
        pushButton_AddOperation->setMinimumSize(QSize(140, 20));
        pushButton_AddOperation->setMaximumSize(QSize(140, 20));
        pushButton_AddOperation->setFont(font1);
        pushButton_AddOperation->setIcon(icon);

        horizontalLayout->addWidget(pushButton_AddOperation);

        pushButton_RemoveOperation = new QPushButton(centralwidget);
        pushButton_RemoveOperation->setObjectName(QStringLiteral("pushButton_RemoveOperation"));
        sizePolicy.setHeightForWidth(pushButton_RemoveOperation->sizePolicy().hasHeightForWidth());
        pushButton_RemoveOperation->setSizePolicy(sizePolicy);
        pushButton_RemoveOperation->setMinimumSize(QSize(175, 20));
        pushButton_RemoveOperation->setMaximumSize(QSize(175, 20));
        pushButton_RemoveOperation->setFont(font1);
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../../../Users/KenWork/Desktop/ECM-Control-System-master/src/window_GMC_variable_editor/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_RemoveOperation->setIcon(icon1);

        horizontalLayout->addWidget(pushButton_RemoveOperation);

        comboBox_ProfileType = new QComboBox(centralwidget);
        comboBox_ProfileType->addItem(QString());
        comboBox_ProfileType->addItem(QString());
        comboBox_ProfileType->setObjectName(QStringLiteral("comboBox_ProfileType"));
        comboBox_ProfileType->setFont(font1);

        horizontalLayout->addWidget(comboBox_ProfileType);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(470, 0));
        groupBox->setMaximumSize(QSize(470, 16777215));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        checkBox_ShouldHomeBeIndicated = new QCheckBox(groupBox);
        checkBox_ShouldHomeBeIndicated->setObjectName(QStringLiteral("checkBox_ShouldHomeBeIndicated"));
        QFont font2;
        font2.setPointSize(12);
        checkBox_ShouldHomeBeIndicated->setFont(font2);
        checkBox_ShouldHomeBeIndicated->setChecked(true);

        gridLayout_5->addWidget(checkBox_ShouldHomeBeIndicated, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(14, 105, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabWidget_OperationParameters = new QTabWidget(centralwidget);
        tabWidget_OperationParameters->setObjectName(QStringLiteral("tabWidget_OperationParameters"));
        sizePolicy.setHeightForWidth(tabWidget_OperationParameters->sizePolicy().hasHeightForWidth());
        tabWidget_OperationParameters->setSizePolicy(sizePolicy);
        tabWidget_OperationParameters->setMinimumSize(QSize(1220, 600));
        tabWidget_OperationParameters->setMaximumSize(QSize(1220, 600));
        tabWidget_OperationParameters->setStyleSheet(QLatin1String("QTabWidget{\n"
"background-color:#f5f5f5;\n"
"padding:5px;\n"
"	font: 12pt \"MS Shell Dlg 2\";\n"
"}"));

        gridLayout_2->addWidget(tabWidget_OperationParameters, 0, 1, 1, 1);

        Window_ProfileConfiguration->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_ProfileConfiguration);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1720, 40));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        Window_ProfileConfiguration->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_ProfileConfiguration);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Window_ProfileConfiguration->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuTools->addAction(actionMotion_Profile);

        retranslateUi(Window_ProfileConfiguration);

        comboBox_ProfileType->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Window_ProfileConfiguration);
    } // setupUi

    void retranslateUi(QMainWindow *Window_ProfileConfiguration)
    {
        Window_ProfileConfiguration->setWindowTitle(QApplication::translate("Window_ProfileConfiguration", "Profile Configuration", nullptr));
        actionOpen->setText(QApplication::translate("Window_ProfileConfiguration", "Open", nullptr));
        actionSave->setText(QApplication::translate("Window_ProfileConfiguration", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("Window_ProfileConfiguration", "Save As", nullptr));
        actionClose->setText(QApplication::translate("Window_ProfileConfiguration", "Close", nullptr));
        actionMotion_Profile->setText(QApplication::translate("Window_ProfileConfiguration", "Motion Profile", nullptr));
        actionNew->setText(QApplication::translate("Window_ProfileConfiguration", "New", nullptr));
        label_ManualControl_6->setText(QApplication::translate("Window_ProfileConfiguration", "Profile Configuration", nullptr));
        label_3->setText(QApplication::translate("Window_ProfileConfiguration", "Current Configuration:", nullptr));
        label_2->setText(QApplication::translate("Window_ProfileConfiguration", "Galil Script:", nullptr));
        pushButton_OpenMotionScript->setText(QApplication::translate("Window_ProfileConfiguration", "Open New Script", nullptr));
        pushButton_UploadMotionScript->setText(QApplication::translate("Window_ProfileConfiguration", "Upload Script", nullptr));
        pushButton_DownloadMotionScript->setText(QApplication::translate("Window_ProfileConfiguration", "Download Script", nullptr));
        label->setText(QApplication::translate("Window_ProfileConfiguration", "Operations:", nullptr));
        pushButton_AddOperation->setText(QApplication::translate("Window_ProfileConfiguration", "Add Operation", nullptr));
        pushButton_RemoveOperation->setText(QApplication::translate("Window_ProfileConfiguration", "Remove Operation", nullptr));
        comboBox_ProfileType->setItemText(0, QApplication::translate("Window_ProfileConfiguration", "OPERATION", nullptr));
        comboBox_ProfileType->setItemText(1, QApplication::translate("Window_ProfileConfiguration", "PAUSE", nullptr));

        groupBox->setTitle(QApplication::translate("Window_ProfileConfiguration", "Settings", nullptr));
        checkBox_ShouldHomeBeIndicated->setText(QApplication::translate("Window_ProfileConfiguration", "Indicate Home Autonomously", nullptr));
        menuFile->setTitle(QApplication::translate("Window_ProfileConfiguration", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("Window_ProfileConfiguration", "Edit", nullptr));
        menuTools->setTitle(QApplication::translate("Window_ProfileConfiguration", "Tools", nullptr));
        menuHelp->setTitle(QApplication::translate("Window_ProfileConfiguration", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_ProfileConfiguration: public Ui_Window_ProfileConfiguration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_PROFILE_CONFIGURATION_H
