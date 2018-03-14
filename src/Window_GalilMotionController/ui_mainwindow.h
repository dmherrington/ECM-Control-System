/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "LED.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave_Program;
    QAction *actionSave_As_Program;
    QAction *actionSave_Current_Parameters;
    QAction *actionSave_As_Current_Parameters;
    QAction *actionLoad_Parameters;
    QAction *actionOpen_Connection;
    QAction *actionClose_Connection;
    QAction *actionExit;
    QAction *action_LoadProgram;
    QAction *action_LoadProfile;
    QWidget *centralWidget;
    QGridLayout *gridLayout_6;
    QWidget *graphingWidget;
    QTextEdit *programText;
    QGridLayout *gridLayout_5;
    QFrame *frame_ProfileOptions;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_4;
    QSplitter *splitter_2;
    QLabel *label_ManualControl_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_DownloadProgram;
    QPushButton *pushButton_UploadProgram;
    QPushButton *pushButton_RunProfile;
    QPushButton *pushButton_StopProfile;
    QPushButton *pushButton_SetInitialGap;
    QSpinBox *spinBox_Jog_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *frame_MaunalControl;
    QGridLayout *gridLayout_4;
    QSplitter *splitter;
    QLabel *label_ManualControl;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *label_ManualControl_4;
    QLabel *label_ManualControl_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_IncreaseRelativeMove;
    QSpinBox *spinBox_RelativeMove;
    QPushButton *pushButton_DecreaseRelativeMove;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_IncreaseJog;
    QSpinBox *spinBox_Jog;
    QPushButton *pushButton_DecreaseJog;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_SetHome;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_MoveHome;
    QFrame *frame;
    QGridLayout *gridLayout_8;
    QPushButton *pushButton_MotorEnable;
    QPushButton *pushButton_MotorDisable;
    QFrame *frame_ProfileOptions_2;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_D1;
    QRadioButton *radioButton_D2;
    QRadioButton *radioButton_D3;
    QLabel *label_ManualControl_5;
    QFrame *frame_ProfileOptions_3;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *textEdit_CMD;
    QPushButton *pushButton_CMDSend;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    LED *ledWidget;
    QMenuBar *menuBar;
    QMenu *menuGalil;
    QMenu *menuLoad;
    QMenu *menuSettings;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1080, 731);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionSave_Program = new QAction(MainWindow);
        actionSave_Program->setObjectName(QStringLiteral("actionSave_Program"));
        actionSave_As_Program = new QAction(MainWindow);
        actionSave_As_Program->setObjectName(QStringLiteral("actionSave_As_Program"));
        actionSave_Current_Parameters = new QAction(MainWindow);
        actionSave_Current_Parameters->setObjectName(QStringLiteral("actionSave_Current_Parameters"));
        actionSave_As_Current_Parameters = new QAction(MainWindow);
        actionSave_As_Current_Parameters->setObjectName(QStringLiteral("actionSave_As_Current_Parameters"));
        actionLoad_Parameters = new QAction(MainWindow);
        actionLoad_Parameters->setObjectName(QStringLiteral("actionLoad_Parameters"));
        actionOpen_Connection = new QAction(MainWindow);
        actionOpen_Connection->setObjectName(QStringLiteral("actionOpen_Connection"));
        actionClose_Connection = new QAction(MainWindow);
        actionClose_Connection->setObjectName(QStringLiteral("actionClose_Connection"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        action_LoadProgram = new QAction(MainWindow);
        action_LoadProgram->setObjectName(QStringLiteral("action_LoadProgram"));
        action_LoadProfile = new QAction(MainWindow);
        action_LoadProfile->setObjectName(QStringLiteral("action_LoadProfile"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        graphingWidget = new QWidget(centralWidget);
        graphingWidget->setObjectName(QStringLiteral("graphingWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphingWidget->sizePolicy().hasHeightForWidth());
        graphingWidget->setSizePolicy(sizePolicy1);
        graphingWidget->setMinimumSize(QSize(0, 250));

        gridLayout_6->addWidget(graphingWidget, 0, 1, 1, 2);

        programText = new QTextEdit(centralWidget);
        programText->setObjectName(QStringLiteral("programText"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(programText->sizePolicy().hasHeightForWidth());
        programText->setSizePolicy(sizePolicy2);
        programText->setMinimumSize(QSize(480, 0));
        programText->setMaximumSize(QSize(480, 16777215));

        gridLayout_6->addWidget(programText, 0, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        frame_ProfileOptions = new QFrame(centralWidget);
        frame_ProfileOptions->setObjectName(QStringLiteral("frame_ProfileOptions"));
        sizePolicy1.setHeightForWidth(frame_ProfileOptions->sizePolicy().hasHeightForWidth());
        frame_ProfileOptions->setSizePolicy(sizePolicy1);
        frame_ProfileOptions->setMinimumSize(QSize(480, 250));
        frame_ProfileOptions->setMaximumSize(QSize(2000, 16777215));
        frame_ProfileOptions->setFrameShape(QFrame::Box);
        frame_ProfileOptions->setFrameShadow(QFrame::Plain);
        frame_ProfileOptions->setLineWidth(2);
        gridLayout_2 = new QGridLayout(frame_ProfileOptions);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer_4 = new QSpacerItem(20, 83, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 2, 1, 1, 1);

        splitter_2 = new QSplitter(frame_ProfileOptions);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label_ManualControl_2 = new QLabel(splitter_2);
        label_ManualControl_2->setObjectName(QStringLiteral("label_ManualControl_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_ManualControl_2->sizePolicy().hasHeightForWidth());
        label_ManualControl_2->setSizePolicy(sizePolicy3);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_ManualControl_2->setFont(font);
        label_ManualControl_2->setAlignment(Qt::AlignCenter);
        splitter_2->addWidget(label_ManualControl_2);

        gridLayout_2->addWidget(splitter_2, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        pushButton_DownloadProgram = new QPushButton(frame_ProfileOptions);
        pushButton_DownloadProgram->setObjectName(QStringLiteral("pushButton_DownloadProgram"));
        sizePolicy.setHeightForWidth(pushButton_DownloadProgram->sizePolicy().hasHeightForWidth());
        pushButton_DownloadProgram->setSizePolicy(sizePolicy);
        pushButton_DownloadProgram->setMinimumSize(QSize(180, 30));
        QFont font1;
        font1.setPointSize(12);
        pushButton_DownloadProgram->setFont(font1);

        verticalLayout_4->addWidget(pushButton_DownloadProgram);

        pushButton_UploadProgram = new QPushButton(frame_ProfileOptions);
        pushButton_UploadProgram->setObjectName(QStringLiteral("pushButton_UploadProgram"));
        sizePolicy.setHeightForWidth(pushButton_UploadProgram->sizePolicy().hasHeightForWidth());
        pushButton_UploadProgram->setSizePolicy(sizePolicy);
        pushButton_UploadProgram->setMinimumSize(QSize(180, 30));
        pushButton_UploadProgram->setFont(font1);

        verticalLayout_4->addWidget(pushButton_UploadProgram);

        pushButton_RunProfile = new QPushButton(frame_ProfileOptions);
        pushButton_RunProfile->setObjectName(QStringLiteral("pushButton_RunProfile"));
        sizePolicy.setHeightForWidth(pushButton_RunProfile->sizePolicy().hasHeightForWidth());
        pushButton_RunProfile->setSizePolicy(sizePolicy);
        pushButton_RunProfile->setMinimumSize(QSize(180, 30));
        pushButton_RunProfile->setFont(font1);

        verticalLayout_4->addWidget(pushButton_RunProfile);

        pushButton_StopProfile = new QPushButton(frame_ProfileOptions);
        pushButton_StopProfile->setObjectName(QStringLiteral("pushButton_StopProfile"));
        sizePolicy.setHeightForWidth(pushButton_StopProfile->sizePolicy().hasHeightForWidth());
        pushButton_StopProfile->setSizePolicy(sizePolicy);
        pushButton_StopProfile->setMinimumSize(QSize(180, 30));
        pushButton_StopProfile->setFont(font1);

        verticalLayout_4->addWidget(pushButton_StopProfile);

        pushButton_SetInitialGap = new QPushButton(frame_ProfileOptions);
        pushButton_SetInitialGap->setObjectName(QStringLiteral("pushButton_SetInitialGap"));
        sizePolicy.setHeightForWidth(pushButton_SetInitialGap->sizePolicy().hasHeightForWidth());
        pushButton_SetInitialGap->setSizePolicy(sizePolicy);
        pushButton_SetInitialGap->setMinimumSize(QSize(180, 30));
        pushButton_SetInitialGap->setFont(font1);

        verticalLayout_4->addWidget(pushButton_SetInitialGap);

        spinBox_Jog_6 = new QSpinBox(frame_ProfileOptions);
        spinBox_Jog_6->setObjectName(QStringLiteral("spinBox_Jog_6"));
        spinBox_Jog_6->setMinimumSize(QSize(180, 30));
        spinBox_Jog_6->setFont(font1);
        spinBox_Jog_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(spinBox_Jog_6);


        gridLayout_2->addLayout(verticalLayout_4, 0, 1, 2, 1);

        tabWidget = new QTabWidget(frame_ProfileOptions);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());

        gridLayout_2->addWidget(tabWidget, 1, 0, 2, 1);

        splitter_2->raise();
        tabWidget->raise();

        gridLayout_5->addWidget(frame_ProfileOptions, 0, 0, 4, 1);

        frame_MaunalControl = new QFrame(centralWidget);
        frame_MaunalControl->setObjectName(QStringLiteral("frame_MaunalControl"));
        sizePolicy.setHeightForWidth(frame_MaunalControl->sizePolicy().hasHeightForWidth());
        frame_MaunalControl->setSizePolicy(sizePolicy);
        frame_MaunalControl->setMinimumSize(QSize(350, 250));
        frame_MaunalControl->setFrameShape(QFrame::Box);
        frame_MaunalControl->setFrameShadow(QFrame::Plain);
        frame_MaunalControl->setLineWidth(2);
        gridLayout_4 = new QGridLayout(frame_MaunalControl);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        splitter = new QSplitter(frame_MaunalControl);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        label_ManualControl = new QLabel(splitter);
        label_ManualControl->setObjectName(QStringLiteral("label_ManualControl"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_ManualControl->sizePolicy().hasHeightForWidth());
        label_ManualControl->setSizePolicy(sizePolicy4);
        label_ManualControl->setFont(font);
        label_ManualControl->setAlignment(Qt::AlignCenter);
        splitter->addWidget(label_ManualControl);

        gridLayout_4->addWidget(splitter, 0, 1, 1, 3);

        horizontalSpacer_12 = new QSpacerItem(22, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_12, 1, 0, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(21, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_11, 1, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 2, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_ManualControl_4 = new QLabel(frame_MaunalControl);
        label_ManualControl_4->setObjectName(QStringLiteral("label_ManualControl_4"));
        sizePolicy4.setHeightForWidth(label_ManualControl_4->sizePolicy().hasHeightForWidth());
        label_ManualControl_4->setSizePolicy(sizePolicy4);
        label_ManualControl_4->setFont(font);
        label_ManualControl_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_ManualControl_4, 0, 1, 1, 1);

        label_ManualControl_3 = new QLabel(frame_MaunalControl);
        label_ManualControl_3->setObjectName(QStringLiteral("label_ManualControl_3"));
        sizePolicy4.setHeightForWidth(label_ManualControl_3->sizePolicy().hasHeightForWidth());
        label_ManualControl_3->setSizePolicy(sizePolicy4);
        label_ManualControl_3->setFont(font);
        label_ManualControl_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_ManualControl_3, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton_IncreaseRelativeMove = new QPushButton(frame_MaunalControl);
        pushButton_IncreaseRelativeMove->setObjectName(QStringLiteral("pushButton_IncreaseRelativeMove"));
        sizePolicy.setHeightForWidth(pushButton_IncreaseRelativeMove->sizePolicy().hasHeightForWidth());
        pushButton_IncreaseRelativeMove->setSizePolicy(sizePolicy);
        pushButton_IncreaseRelativeMove->setMinimumSize(QSize(112, 30));
        pushButton_IncreaseRelativeMove->setFont(font1);

        verticalLayout_2->addWidget(pushButton_IncreaseRelativeMove);

        spinBox_RelativeMove = new QSpinBox(frame_MaunalControl);
        spinBox_RelativeMove->setObjectName(QStringLiteral("spinBox_RelativeMove"));
        sizePolicy.setHeightForWidth(spinBox_RelativeMove->sizePolicy().hasHeightForWidth());
        spinBox_RelativeMove->setSizePolicy(sizePolicy);
        spinBox_RelativeMove->setMinimumSize(QSize(112, 30));
        spinBox_RelativeMove->setFont(font1);
        spinBox_RelativeMove->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_RelativeMove->setMaximum(100000);
        spinBox_RelativeMove->setSingleStep(100);
        spinBox_RelativeMove->setValue(10000);

        verticalLayout_2->addWidget(spinBox_RelativeMove);

        pushButton_DecreaseRelativeMove = new QPushButton(frame_MaunalControl);
        pushButton_DecreaseRelativeMove->setObjectName(QStringLiteral("pushButton_DecreaseRelativeMove"));
        sizePolicy.setHeightForWidth(pushButton_DecreaseRelativeMove->sizePolicy().hasHeightForWidth());
        pushButton_DecreaseRelativeMove->setSizePolicy(sizePolicy);
        pushButton_DecreaseRelativeMove->setMinimumSize(QSize(112, 30));
        pushButton_DecreaseRelativeMove->setFont(font1);

        verticalLayout_2->addWidget(pushButton_DecreaseRelativeMove);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        gridLayout->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_IncreaseJog = new QPushButton(frame_MaunalControl);
        pushButton_IncreaseJog->setObjectName(QStringLiteral("pushButton_IncreaseJog"));
        sizePolicy.setHeightForWidth(pushButton_IncreaseJog->sizePolicy().hasHeightForWidth());
        pushButton_IncreaseJog->setSizePolicy(sizePolicy);
        pushButton_IncreaseJog->setMinimumSize(QSize(112, 30));
        pushButton_IncreaseJog->setFont(font1);

        verticalLayout->addWidget(pushButton_IncreaseJog);

        spinBox_Jog = new QSpinBox(frame_MaunalControl);
        spinBox_Jog->setObjectName(QStringLiteral("spinBox_Jog"));
        sizePolicy.setHeightForWidth(spinBox_Jog->sizePolicy().hasHeightForWidth());
        spinBox_Jog->setSizePolicy(sizePolicy);
        spinBox_Jog->setMinimumSize(QSize(112, 30));
        spinBox_Jog->setFont(font1);
        spinBox_Jog->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_Jog->setMinimum(1);
        spinBox_Jog->setMaximum(10000);
        spinBox_Jog->setSingleStep(10);
        spinBox_Jog->setValue(100);

        verticalLayout->addWidget(spinBox_Jog);

        pushButton_DecreaseJog = new QPushButton(frame_MaunalControl);
        pushButton_DecreaseJog->setObjectName(QStringLiteral("pushButton_DecreaseJog"));
        sizePolicy.setHeightForWidth(pushButton_DecreaseJog->sizePolicy().hasHeightForWidth());
        pushButton_DecreaseJog->setSizePolicy(sizePolicy);
        pushButton_DecreaseJog->setMinimumSize(QSize(112, 30));
        pushButton_DecreaseJog->setFont(font1);

        verticalLayout->addWidget(pushButton_DecreaseJog);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout, 3, 0, 1, 5);

        pushButton_SetHome = new QPushButton(frame_MaunalControl);
        pushButton_SetHome->setObjectName(QStringLiteral("pushButton_SetHome"));
        sizePolicy.setHeightForWidth(pushButton_SetHome->sizePolicy().hasHeightForWidth());
        pushButton_SetHome->setSizePolicy(sizePolicy);
        pushButton_SetHome->setMinimumSize(QSize(112, 30));
        pushButton_SetHome->setFont(font1);

        gridLayout_4->addWidget(pushButton_SetHome, 1, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_10, 1, 2, 1, 1);

        pushButton_MoveHome = new QPushButton(frame_MaunalControl);
        pushButton_MoveHome->setObjectName(QStringLiteral("pushButton_MoveHome"));
        sizePolicy.setHeightForWidth(pushButton_MoveHome->sizePolicy().hasHeightForWidth());
        pushButton_MoveHome->setSizePolicy(sizePolicy);
        pushButton_MoveHome->setMinimumSize(QSize(112, 30));
        pushButton_MoveHome->setFont(font1);

        gridLayout_4->addWidget(pushButton_MoveHome, 1, 3, 1, 1);


        gridLayout_5->addWidget(frame_MaunalControl, 0, 1, 2, 1);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(2);
        gridLayout_8 = new QGridLayout(frame);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        pushButton_MotorEnable = new QPushButton(frame);
        pushButton_MotorEnable->setObjectName(QStringLiteral("pushButton_MotorEnable"));
        sizePolicy.setHeightForWidth(pushButton_MotorEnable->sizePolicy().hasHeightForWidth());
        pushButton_MotorEnable->setSizePolicy(sizePolicy);
        pushButton_MotorEnable->setMinimumSize(QSize(130, 30));
        pushButton_MotorEnable->setFont(font1);

        gridLayout_8->addWidget(pushButton_MotorEnable, 0, 0, 1, 1);

        pushButton_MotorDisable = new QPushButton(frame);
        pushButton_MotorDisable->setObjectName(QStringLiteral("pushButton_MotorDisable"));
        sizePolicy.setHeightForWidth(pushButton_MotorDisable->sizePolicy().hasHeightForWidth());
        pushButton_MotorDisable->setSizePolicy(sizePolicy);
        pushButton_MotorDisable->setMinimumSize(QSize(130, 30));
        pushButton_MotorDisable->setFont(font1);

        gridLayout_8->addWidget(pushButton_MotorDisable, 1, 0, 1, 1);


        gridLayout_5->addWidget(frame, 0, 2, 1, 1);

        frame_ProfileOptions_2 = new QFrame(centralWidget);
        frame_ProfileOptions_2->setObjectName(QStringLiteral("frame_ProfileOptions_2"));
        sizePolicy1.setHeightForWidth(frame_ProfileOptions_2->sizePolicy().hasHeightForWidth());
        frame_ProfileOptions_2->setSizePolicy(sizePolicy1);
        frame_ProfileOptions_2->setMinimumSize(QSize(152, 70));
        frame_ProfileOptions_2->setFrameShape(QFrame::Box);
        frame_ProfileOptions_2->setFrameShadow(QFrame::Plain);
        frame_ProfileOptions_2->setLineWidth(2);
        gridLayout_3 = new QGridLayout(frame_ProfileOptions_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        radioButton_D1 = new QRadioButton(frame_ProfileOptions_2);
        radioButton_D1->setObjectName(QStringLiteral("radioButton_D1"));
        sizePolicy.setHeightForWidth(radioButton_D1->sizePolicy().hasHeightForWidth());
        radioButton_D1->setSizePolicy(sizePolicy);
        radioButton_D1->setFont(font1);

        verticalLayout_3->addWidget(radioButton_D1);

        radioButton_D2 = new QRadioButton(frame_ProfileOptions_2);
        radioButton_D2->setObjectName(QStringLiteral("radioButton_D2"));
        sizePolicy.setHeightForWidth(radioButton_D2->sizePolicy().hasHeightForWidth());
        radioButton_D2->setSizePolicy(sizePolicy);
        radioButton_D2->setFont(font1);

        verticalLayout_3->addWidget(radioButton_D2);

        radioButton_D3 = new QRadioButton(frame_ProfileOptions_2);
        radioButton_D3->setObjectName(QStringLiteral("radioButton_D3"));
        sizePolicy.setHeightForWidth(radioButton_D3->sizePolicy().hasHeightForWidth());
        radioButton_D3->setSizePolicy(sizePolicy);
        radioButton_D3->setFont(font1);

        verticalLayout_3->addWidget(radioButton_D3);


        gridLayout_3->addLayout(verticalLayout_3, 1, 0, 1, 1);

        label_ManualControl_5 = new QLabel(frame_ProfileOptions_2);
        label_ManualControl_5->setObjectName(QStringLiteral("label_ManualControl_5"));
        sizePolicy3.setHeightForWidth(label_ManualControl_5->sizePolicy().hasHeightForWidth());
        label_ManualControl_5->setSizePolicy(sizePolicy3);
        label_ManualControl_5->setFont(font);
        label_ManualControl_5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_ManualControl_5, 0, 0, 1, 1);


        gridLayout_5->addWidget(frame_ProfileOptions_2, 1, 2, 1, 1);

        frame_ProfileOptions_3 = new QFrame(centralWidget);
        frame_ProfileOptions_3->setObjectName(QStringLiteral("frame_ProfileOptions_3"));
        sizePolicy.setHeightForWidth(frame_ProfileOptions_3->sizePolicy().hasHeightForWidth());
        frame_ProfileOptions_3->setSizePolicy(sizePolicy);
        frame_ProfileOptions_3->setMinimumSize(QSize(350, 70));
        frame_ProfileOptions_3->setFrameShape(QFrame::Box);
        frame_ProfileOptions_3->setFrameShadow(QFrame::Plain);
        frame_ProfileOptions_3->setLineWidth(2);
        gridLayout_7 = new QGridLayout(frame_ProfileOptions_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        textEdit_CMD = new QTextEdit(frame_ProfileOptions_3);
        textEdit_CMD->setObjectName(QStringLiteral("textEdit_CMD"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(textEdit_CMD->sizePolicy().hasHeightForWidth());
        textEdit_CMD->setSizePolicy(sizePolicy5);
        textEdit_CMD->setMinimumSize(QSize(0, 30));
        textEdit_CMD->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_4->addWidget(textEdit_CMD);

        pushButton_CMDSend = new QPushButton(frame_ProfileOptions_3);
        pushButton_CMDSend->setObjectName(QStringLiteral("pushButton_CMDSend"));
        sizePolicy.setHeightForWidth(pushButton_CMDSend->sizePolicy().hasHeightForWidth());
        pushButton_CMDSend->setSizePolicy(sizePolicy);
        pushButton_CMDSend->setMinimumSize(QSize(80, 30));
        pushButton_CMDSend->setFont(font1);

        horizontalLayout_4->addWidget(pushButton_CMDSend);


        gridLayout_7->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        gridLayout_5->addWidget(frame_ProfileOptions_3, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 118, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 2, 2, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 62, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 3, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 1, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 1, 2, 1, 1);

        ledWidget = new LED(centralWidget);
        ledWidget->setObjectName(QStringLiteral("ledWidget"));

        gridLayout_6->addWidget(ledWidget, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1080, 21));
        menuGalil = new QMenu(menuBar);
        menuGalil->setObjectName(QStringLiteral("menuGalil"));
        menuLoad = new QMenu(menuGalil);
        menuLoad->setObjectName(QStringLiteral("menuLoad"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuGalil->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuGalil->addAction(actionSave_Program);
        menuGalil->addAction(actionSave_As_Program);
        menuGalil->addAction(menuLoad->menuAction());
        menuGalil->addSeparator();
        menuGalil->addAction(actionOpen_Connection);
        menuGalil->addAction(actionClose_Connection);
        menuGalil->addSeparator();
        menuGalil->addAction(actionExit);
        menuLoad->addAction(action_LoadProgram);
        menuLoad->addAction(action_LoadProfile);
        menuSettings->addAction(actionSave_Current_Parameters);
        menuSettings->addAction(actionSave_As_Current_Parameters);
        menuSettings->addAction(actionLoad_Parameters);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSave_Program->setText(QApplication::translate("MainWindow", "Save Program", nullptr));
        actionSave_As_Program->setText(QApplication::translate("MainWindow", "Save_As Program", nullptr));
        actionSave_Current_Parameters->setText(QApplication::translate("MainWindow", "Save Current Parameters", nullptr));
        actionSave_As_Current_Parameters->setText(QApplication::translate("MainWindow", "Save_As Current Parameters", nullptr));
        actionLoad_Parameters->setText(QApplication::translate("MainWindow", "Load Parameters", nullptr));
        actionOpen_Connection->setText(QApplication::translate("MainWindow", "Open Connection", nullptr));
        actionClose_Connection->setText(QApplication::translate("MainWindow", "Close Connection", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        action_LoadProgram->setText(QApplication::translate("MainWindow", "Load Program", nullptr));
        action_LoadProfile->setText(QApplication::translate("MainWindow", "Load Profile", nullptr));
        label_ManualControl_2->setText(QApplication::translate("MainWindow", "Profile Optons", nullptr));
        pushButton_DownloadProgram->setText(QApplication::translate("MainWindow", "Download Program", nullptr));
        pushButton_UploadProgram->setText(QApplication::translate("MainWindow", "Upload Program", nullptr));
        pushButton_RunProfile->setText(QApplication::translate("MainWindow", "Run Profile", nullptr));
        pushButton_StopProfile->setText(QApplication::translate("MainWindow", "Stop Profile", nullptr));
        pushButton_SetInitialGap->setText(QApplication::translate("MainWindow", "Set Initial Gap", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", nullptr));
        label_ManualControl->setText(QApplication::translate("MainWindow", "Manual Control", nullptr));
        label_ManualControl_4->setText(QApplication::translate("MainWindow", "Step Control (um)", nullptr));
        label_ManualControl_3->setText(QApplication::translate("MainWindow", "Jog Control (um/sec)", nullptr));
        pushButton_IncreaseRelativeMove->setText(QApplication::translate("MainWindow", "INCREASE", nullptr));
        pushButton_DecreaseRelativeMove->setText(QApplication::translate("MainWindow", "DECREASE", nullptr));
        pushButton_IncreaseJog->setText(QApplication::translate("MainWindow", "INCREASE", nullptr));
        pushButton_DecreaseJog->setText(QApplication::translate("MainWindow", "DECREASE", nullptr));
        pushButton_SetHome->setText(QApplication::translate("MainWindow", "Set Home", nullptr));
        pushButton_MoveHome->setText(QApplication::translate("MainWindow", "Move To Home", nullptr));
        pushButton_MotorEnable->setText(QApplication::translate("MainWindow", "ENABLE MOTOR", nullptr));
        pushButton_MotorDisable->setText(QApplication::translate("MainWindow", "STOP MOTOR", nullptr));
        radioButton_D1->setText(QApplication::translate("MainWindow", "D1", nullptr));
        radioButton_D2->setText(QApplication::translate("MainWindow", "D2", nullptr));
        radioButton_D3->setText(QApplication::translate("MainWindow", "D3", nullptr));
        label_ManualControl_5->setText(QApplication::translate("MainWindow", "DIO Signals", nullptr));
        textEdit_CMD->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton_CMDSend->setText(QApplication::translate("MainWindow", "SEND", nullptr));
        menuGalil->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuLoad->setTitle(QApplication::translate("MainWindow", "Load", nullptr));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Parameters", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
