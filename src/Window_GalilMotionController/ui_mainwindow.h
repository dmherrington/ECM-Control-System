/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
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
#include "plot_handler.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave_Program;
    QAction *actionSave_As_Program;
    QAction *actionLoad_Program;
    QAction *actionSave_Current_Parameters;
    QAction *actionSave_As_Current_Parameters;
    QAction *actionLoad_Parameters;
    QAction *actionOpen_Connection;
    QAction *actionClose_Connection;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout_10;
    QTextEdit *programText;
    graphing::PlotHandler *graphingWidget;
    QGridLayout *gridLayout_9;
    QFrame *frame_ProfileOptions;
    QGridLayout *gridLayout_3;
    QSplitter *splitter_2;
    QLabel *label_ManualControl_2;
    QPushButton *pushButton_DownloadProgram;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout_7;
    QLabel *label_5;
    QSpinBox *spinBox_CutDepth_2;
    QLabel *label_6;
    QSpinBox *spinBox_RetractDistance_2;
    QWidget *tab_2;
    QGridLayout *gridLayout_6;
    QFormLayout *formLayout_6;
    QLabel *label_3;
    QSpinBox *spinBox_CutDepth;
    QLabel *label;
    QSpinBox *spinBox_RetractDistance;
    QLabel *label_2;
    QSpinBox *spinBox_RetractFrequency;
    QLabel *label_4;
    QSpinBox *spinBox_CutSpeed;
    QPushButton *pushButton_UploadProgram;
    QPushButton *pushButton_RunProfile;
    QPushButton *pushButton_StopProfile;
    QPushButton *pushButton_SetInitialGap;
    QSpinBox *spinBox_Jog_6;
    QFrame *frame_MaunalControl;
    QGridLayout *gridLayout_4;
    QSplitter *splitter;
    QLabel *label_ManualControl;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton_SetHome;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_MoveHome;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *label_ManualControl_3;
    QLabel *label_ManualControl_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_IncreaseJog;
    QSpinBox *spinBox_Jog;
    QPushButton *pushButton_DecreaseJog;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_IncreaseRelativeMove;
    QSpinBox *spinBox_RelativeMove;
    QPushButton *pushButton_DecreaseRelativeMove;
    QSpacerItem *horizontalSpacer_8;
    QFrame *frame;
    QGridLayout *gridLayout_8;
    QPushButton *pushButton_MotorEnable;
    QPushButton *pushButton_MotorDisable;
    QFrame *frame_ProfileOptions_2;
    QGridLayout *gridLayout_5;
    QLabel *label_ManualControl_5;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_D1;
    QRadioButton *radioButton_D2;
    QRadioButton *radioButton_D3;
    QFrame *frame_ProfileOptions_3;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *textEdit_CMD;
    QPushButton *pushButton_CMDSend;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QMenu *menuGalil;
    QMenu *menuSettings;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1087, 663);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionSave_Program = new QAction(MainWindow);
        actionSave_Program->setObjectName(QStringLiteral("actionSave_Program"));
        actionSave_As_Program = new QAction(MainWindow);
        actionSave_As_Program->setObjectName(QStringLiteral("actionSave_As_Program"));
        actionLoad_Program = new QAction(MainWindow);
        actionLoad_Program->setObjectName(QStringLiteral("actionLoad_Program"));
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
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_10 = new QGridLayout(centralWidget);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        programText = new QTextEdit(centralWidget);
        programText->setObjectName(QStringLiteral("programText"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(programText->sizePolicy().hasHeightForWidth());
        programText->setSizePolicy(sizePolicy1);
        programText->setMinimumSize(QSize(480, 0));
        programText->setMaximumSize(QSize(480, 16777215));

        gridLayout_10->addWidget(programText, 0, 0, 1, 1);

        graphingWidget = new graphing::PlotHandler(centralWidget);
        graphingWidget->setObjectName(QStringLiteral("graphingWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(graphingWidget->sizePolicy().hasHeightForWidth());
        graphingWidget->setSizePolicy(sizePolicy2);
        graphingWidget->setMinimumSize(QSize(0, 250));

        gridLayout_10->addWidget(graphingWidget, 0, 1, 1, 2);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        frame_ProfileOptions = new QFrame(centralWidget);
        frame_ProfileOptions->setObjectName(QStringLiteral("frame_ProfileOptions"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_ProfileOptions->sizePolicy().hasHeightForWidth());
        frame_ProfileOptions->setSizePolicy(sizePolicy3);
        frame_ProfileOptions->setMinimumSize(QSize(480, 250));
        frame_ProfileOptions->setMaximumSize(QSize(480, 16777215));
        frame_ProfileOptions->setFrameShape(QFrame::Box);
        frame_ProfileOptions->setFrameShadow(QFrame::Plain);
        frame_ProfileOptions->setLineWidth(2);
        gridLayout_3 = new QGridLayout(frame_ProfileOptions);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        splitter_2 = new QSplitter(frame_ProfileOptions);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label_ManualControl_2 = new QLabel(splitter_2);
        label_ManualControl_2->setObjectName(QStringLiteral("label_ManualControl_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_ManualControl_2->sizePolicy().hasHeightForWidth());
        label_ManualControl_2->setSizePolicy(sizePolicy4);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_ManualControl_2->setFont(font);
        label_ManualControl_2->setAlignment(Qt::AlignCenter);
        splitter_2->addWidget(label_ManualControl_2);

        gridLayout_3->addWidget(splitter_2, 0, 0, 1, 1);

        pushButton_DownloadProgram = new QPushButton(frame_ProfileOptions);
        pushButton_DownloadProgram->setObjectName(QStringLiteral("pushButton_DownloadProgram"));
        sizePolicy3.setHeightForWidth(pushButton_DownloadProgram->sizePolicy().hasHeightForWidth());
        pushButton_DownloadProgram->setSizePolicy(sizePolicy3);
        pushButton_DownloadProgram->setMinimumSize(QSize(180, 30));
        QFont font1;
        font1.setPointSize(12);
        pushButton_DownloadProgram->setFont(font1);

        gridLayout_3->addWidget(pushButton_DownloadProgram, 0, 1, 1, 1);

        tabWidget = new QTabWidget(frame_ProfileOptions);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        formLayout_7 = new QFormLayout();
        formLayout_7->setSpacing(6);
        formLayout_7->setObjectName(QStringLiteral("formLayout_7"));
        formLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(120, 0));
        label_5->setFont(font1);

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_5);

        spinBox_CutDepth_2 = new QSpinBox(tab);
        spinBox_CutDepth_2->setObjectName(QStringLiteral("spinBox_CutDepth_2"));
        sizePolicy3.setHeightForWidth(spinBox_CutDepth_2->sizePolicy().hasHeightForWidth());
        spinBox_CutDepth_2->setSizePolicy(sizePolicy3);
        spinBox_CutDepth_2->setMinimumSize(QSize(110, 30));
        spinBox_CutDepth_2->setFont(font1);
        spinBox_CutDepth_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_7->setWidget(0, QFormLayout::FieldRole, spinBox_CutDepth_2);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(120, 0));
        label_6->setFont(font1);

        formLayout_7->setWidget(1, QFormLayout::LabelRole, label_6);

        spinBox_RetractDistance_2 = new QSpinBox(tab);
        spinBox_RetractDistance_2->setObjectName(QStringLiteral("spinBox_RetractDistance_2"));
        sizePolicy3.setHeightForWidth(spinBox_RetractDistance_2->sizePolicy().hasHeightForWidth());
        spinBox_RetractDistance_2->setSizePolicy(sizePolicy3);
        spinBox_RetractDistance_2->setMinimumSize(QSize(110, 30));
        spinBox_RetractDistance_2->setFont(font1);
        spinBox_RetractDistance_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_7->setWidget(1, QFormLayout::FieldRole, spinBox_RetractDistance_2);


        gridLayout_2->addLayout(formLayout_7, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_6 = new QGridLayout(tab_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        formLayout_6 = new QFormLayout();
        formLayout_6->setSpacing(6);
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        formLayout_6->setSizeConstraint(QLayout::SetFixedSize);
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(120, 0));
        label_3->setFont(font1);

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_3);

        spinBox_CutDepth = new QSpinBox(tab_2);
        spinBox_CutDepth->setObjectName(QStringLiteral("spinBox_CutDepth"));
        sizePolicy3.setHeightForWidth(spinBox_CutDepth->sizePolicy().hasHeightForWidth());
        spinBox_CutDepth->setSizePolicy(sizePolicy3);
        spinBox_CutDepth->setMinimumSize(QSize(80, 30));
        spinBox_CutDepth->setFont(font1);
        spinBox_CutDepth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, spinBox_CutDepth);

        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(120, 0));
        label->setFont(font1);

        formLayout_6->setWidget(1, QFormLayout::LabelRole, label);

        spinBox_RetractDistance = new QSpinBox(tab_2);
        spinBox_RetractDistance->setObjectName(QStringLiteral("spinBox_RetractDistance"));
        sizePolicy3.setHeightForWidth(spinBox_RetractDistance->sizePolicy().hasHeightForWidth());
        spinBox_RetractDistance->setSizePolicy(sizePolicy3);
        spinBox_RetractDistance->setMinimumSize(QSize(80, 30));
        spinBox_RetractDistance->setFont(font1);
        spinBox_RetractDistance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_6->setWidget(1, QFormLayout::FieldRole, spinBox_RetractDistance);

        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(120, 0));
        label_2->setFont(font1);

        formLayout_6->setWidget(2, QFormLayout::LabelRole, label_2);

        spinBox_RetractFrequency = new QSpinBox(tab_2);
        spinBox_RetractFrequency->setObjectName(QStringLiteral("spinBox_RetractFrequency"));
        sizePolicy3.setHeightForWidth(spinBox_RetractFrequency->sizePolicy().hasHeightForWidth());
        spinBox_RetractFrequency->setSizePolicy(sizePolicy3);
        spinBox_RetractFrequency->setMinimumSize(QSize(80, 30));
        spinBox_RetractFrequency->setFont(font1);
        spinBox_RetractFrequency->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_6->setWidget(2, QFormLayout::FieldRole, spinBox_RetractFrequency);

        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(120, 0));
        label_4->setFont(font1);

        formLayout_6->setWidget(3, QFormLayout::LabelRole, label_4);

        spinBox_CutSpeed = new QSpinBox(tab_2);
        spinBox_CutSpeed->setObjectName(QStringLiteral("spinBox_CutSpeed"));
        sizePolicy3.setHeightForWidth(spinBox_CutSpeed->sizePolicy().hasHeightForWidth());
        spinBox_CutSpeed->setSizePolicy(sizePolicy3);
        spinBox_CutSpeed->setMinimumSize(QSize(80, 30));
        spinBox_CutSpeed->setFont(font1);
        spinBox_CutSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_6->setWidget(3, QFormLayout::FieldRole, spinBox_CutSpeed);


        gridLayout_6->addLayout(formLayout_6, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_3->addWidget(tabWidget, 1, 0, 5, 1);

        pushButton_UploadProgram = new QPushButton(frame_ProfileOptions);
        pushButton_UploadProgram->setObjectName(QStringLiteral("pushButton_UploadProgram"));
        sizePolicy3.setHeightForWidth(pushButton_UploadProgram->sizePolicy().hasHeightForWidth());
        pushButton_UploadProgram->setSizePolicy(sizePolicy3);
        pushButton_UploadProgram->setMinimumSize(QSize(180, 30));
        pushButton_UploadProgram->setFont(font1);

        gridLayout_3->addWidget(pushButton_UploadProgram, 1, 1, 1, 1);

        pushButton_RunProfile = new QPushButton(frame_ProfileOptions);
        pushButton_RunProfile->setObjectName(QStringLiteral("pushButton_RunProfile"));
        sizePolicy3.setHeightForWidth(pushButton_RunProfile->sizePolicy().hasHeightForWidth());
        pushButton_RunProfile->setSizePolicy(sizePolicy3);
        pushButton_RunProfile->setMinimumSize(QSize(180, 30));
        pushButton_RunProfile->setFont(font1);

        gridLayout_3->addWidget(pushButton_RunProfile, 2, 1, 1, 1);

        pushButton_StopProfile = new QPushButton(frame_ProfileOptions);
        pushButton_StopProfile->setObjectName(QStringLiteral("pushButton_StopProfile"));
        sizePolicy3.setHeightForWidth(pushButton_StopProfile->sizePolicy().hasHeightForWidth());
        pushButton_StopProfile->setSizePolicy(sizePolicy3);
        pushButton_StopProfile->setMinimumSize(QSize(180, 30));
        pushButton_StopProfile->setFont(font1);

        gridLayout_3->addWidget(pushButton_StopProfile, 3, 1, 1, 1);

        pushButton_SetInitialGap = new QPushButton(frame_ProfileOptions);
        pushButton_SetInitialGap->setObjectName(QStringLiteral("pushButton_SetInitialGap"));
        sizePolicy3.setHeightForWidth(pushButton_SetInitialGap->sizePolicy().hasHeightForWidth());
        pushButton_SetInitialGap->setSizePolicy(sizePolicy3);
        pushButton_SetInitialGap->setMinimumSize(QSize(180, 30));
        pushButton_SetInitialGap->setFont(font1);

        gridLayout_3->addWidget(pushButton_SetInitialGap, 4, 1, 1, 1);

        spinBox_Jog_6 = new QSpinBox(frame_ProfileOptions);
        spinBox_Jog_6->setObjectName(QStringLiteral("spinBox_Jog_6"));
        spinBox_Jog_6->setMinimumSize(QSize(180, 30));
        spinBox_Jog_6->setFont(font1);
        spinBox_Jog_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(spinBox_Jog_6, 5, 1, 1, 1);

        tabWidget->raise();
        splitter_2->raise();
        pushButton_RunProfile->raise();
        pushButton_SetInitialGap->raise();
        spinBox_Jog_6->raise();
        pushButton_StopProfile->raise();
        pushButton_UploadProgram->raise();
        pushButton_DownloadProgram->raise();

        gridLayout_9->addWidget(frame_ProfileOptions, 0, 0, 1, 1);

        frame_MaunalControl = new QFrame(centralWidget);
        frame_MaunalControl->setObjectName(QStringLiteral("frame_MaunalControl"));
        sizePolicy3.setHeightForWidth(frame_MaunalControl->sizePolicy().hasHeightForWidth());
        frame_MaunalControl->setSizePolicy(sizePolicy3);
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
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_ManualControl->sizePolicy().hasHeightForWidth());
        label_ManualControl->setSizePolicy(sizePolicy5);
        label_ManualControl->setFont(font);
        label_ManualControl->setAlignment(Qt::AlignCenter);
        splitter->addWidget(label_ManualControl);

        gridLayout_4->addWidget(splitter, 0, 1, 1, 3);

        horizontalSpacer_12 = new QSpacerItem(22, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_12, 1, 0, 1, 1);

        pushButton_SetHome = new QPushButton(frame_MaunalControl);
        pushButton_SetHome->setObjectName(QStringLiteral("pushButton_SetHome"));
        sizePolicy3.setHeightForWidth(pushButton_SetHome->sizePolicy().hasHeightForWidth());
        pushButton_SetHome->setSizePolicy(sizePolicy3);
        pushButton_SetHome->setMinimumSize(QSize(112, 30));
        pushButton_SetHome->setFont(font1);

        gridLayout_4->addWidget(pushButton_SetHome, 1, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_10, 1, 2, 1, 1);

        pushButton_MoveHome = new QPushButton(frame_MaunalControl);
        pushButton_MoveHome->setObjectName(QStringLiteral("pushButton_MoveHome"));
        sizePolicy3.setHeightForWidth(pushButton_MoveHome->sizePolicy().hasHeightForWidth());
        pushButton_MoveHome->setSizePolicy(sizePolicy3);
        pushButton_MoveHome->setMinimumSize(QSize(112, 30));
        pushButton_MoveHome->setFont(font1);

        gridLayout_4->addWidget(pushButton_MoveHome, 1, 3, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(21, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_11, 1, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 2, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_ManualControl_3 = new QLabel(frame_MaunalControl);
        label_ManualControl_3->setObjectName(QStringLiteral("label_ManualControl_3"));
        sizePolicy5.setHeightForWidth(label_ManualControl_3->sizePolicy().hasHeightForWidth());
        label_ManualControl_3->setSizePolicy(sizePolicy5);
        label_ManualControl_3->setFont(font);
        label_ManualControl_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_ManualControl_3, 0, 0, 1, 1);

        label_ManualControl_4 = new QLabel(frame_MaunalControl);
        label_ManualControl_4->setObjectName(QStringLiteral("label_ManualControl_4"));
        sizePolicy5.setHeightForWidth(label_ManualControl_4->sizePolicy().hasHeightForWidth());
        label_ManualControl_4->setSizePolicy(sizePolicy5);
        label_ManualControl_4->setFont(font);
        label_ManualControl_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_ManualControl_4, 0, 1, 1, 1);

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
        sizePolicy3.setHeightForWidth(pushButton_IncreaseJog->sizePolicy().hasHeightForWidth());
        pushButton_IncreaseJog->setSizePolicy(sizePolicy3);
        pushButton_IncreaseJog->setMinimumSize(QSize(112, 30));
        pushButton_IncreaseJog->setFont(font1);

        verticalLayout->addWidget(pushButton_IncreaseJog);

        spinBox_Jog = new QSpinBox(frame_MaunalControl);
        spinBox_Jog->setObjectName(QStringLiteral("spinBox_Jog"));
        sizePolicy3.setHeightForWidth(spinBox_Jog->sizePolicy().hasHeightForWidth());
        spinBox_Jog->setSizePolicy(sizePolicy3);
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
        sizePolicy3.setHeightForWidth(pushButton_DecreaseJog->sizePolicy().hasHeightForWidth());
        pushButton_DecreaseJog->setSizePolicy(sizePolicy3);
        pushButton_DecreaseJog->setMinimumSize(QSize(112, 30));
        pushButton_DecreaseJog->setFont(font1);

        verticalLayout->addWidget(pushButton_DecreaseJog);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

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
        sizePolicy3.setHeightForWidth(pushButton_IncreaseRelativeMove->sizePolicy().hasHeightForWidth());
        pushButton_IncreaseRelativeMove->setSizePolicy(sizePolicy3);
        pushButton_IncreaseRelativeMove->setMinimumSize(QSize(112, 30));
        pushButton_IncreaseRelativeMove->setFont(font1);

        verticalLayout_2->addWidget(pushButton_IncreaseRelativeMove);

        spinBox_RelativeMove = new QSpinBox(frame_MaunalControl);
        spinBox_RelativeMove->setObjectName(QStringLiteral("spinBox_RelativeMove"));
        sizePolicy3.setHeightForWidth(spinBox_RelativeMove->sizePolicy().hasHeightForWidth());
        spinBox_RelativeMove->setSizePolicy(sizePolicy3);
        spinBox_RelativeMove->setMinimumSize(QSize(112, 30));
        spinBox_RelativeMove->setFont(font1);
        spinBox_RelativeMove->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_RelativeMove->setMaximum(100000);
        spinBox_RelativeMove->setSingleStep(100);
        spinBox_RelativeMove->setValue(10000);

        verticalLayout_2->addWidget(spinBox_RelativeMove);

        pushButton_DecreaseRelativeMove = new QPushButton(frame_MaunalControl);
        pushButton_DecreaseRelativeMove->setObjectName(QStringLiteral("pushButton_DecreaseRelativeMove"));
        sizePolicy3.setHeightForWidth(pushButton_DecreaseRelativeMove->sizePolicy().hasHeightForWidth());
        pushButton_DecreaseRelativeMove->setSizePolicy(sizePolicy3);
        pushButton_DecreaseRelativeMove->setMinimumSize(QSize(112, 30));
        pushButton_DecreaseRelativeMove->setFont(font1);

        verticalLayout_2->addWidget(pushButton_DecreaseRelativeMove);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        gridLayout->addLayout(horizontalLayout_2, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout, 3, 0, 1, 5);


        gridLayout_9->addWidget(frame_MaunalControl, 0, 1, 1, 1);

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
        sizePolicy3.setHeightForWidth(pushButton_MotorEnable->sizePolicy().hasHeightForWidth());
        pushButton_MotorEnable->setSizePolicy(sizePolicy3);
        pushButton_MotorEnable->setMinimumSize(QSize(130, 30));
        pushButton_MotorEnable->setFont(font1);

        gridLayout_8->addWidget(pushButton_MotorEnable, 0, 0, 1, 1);

        pushButton_MotorDisable = new QPushButton(frame);
        pushButton_MotorDisable->setObjectName(QStringLiteral("pushButton_MotorDisable"));
        sizePolicy3.setHeightForWidth(pushButton_MotorDisable->sizePolicy().hasHeightForWidth());
        pushButton_MotorDisable->setSizePolicy(sizePolicy3);
        pushButton_MotorDisable->setMinimumSize(QSize(130, 30));
        pushButton_MotorDisable->setFont(font1);

        gridLayout_8->addWidget(pushButton_MotorDisable, 1, 0, 1, 1);


        gridLayout_9->addWidget(frame, 0, 2, 1, 1);

        frame_ProfileOptions_2 = new QFrame(centralWidget);
        frame_ProfileOptions_2->setObjectName(QStringLiteral("frame_ProfileOptions_2"));
        sizePolicy3.setHeightForWidth(frame_ProfileOptions_2->sizePolicy().hasHeightForWidth());
        frame_ProfileOptions_2->setSizePolicy(sizePolicy3);
        frame_ProfileOptions_2->setMinimumSize(QSize(480, 70));
        frame_ProfileOptions_2->setFrameShape(QFrame::Box);
        frame_ProfileOptions_2->setFrameShadow(QFrame::Plain);
        frame_ProfileOptions_2->setLineWidth(2);
        gridLayout_5 = new QGridLayout(frame_ProfileOptions_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_ManualControl_5 = new QLabel(frame_ProfileOptions_2);
        label_ManualControl_5->setObjectName(QStringLiteral("label_ManualControl_5"));
        sizePolicy4.setHeightForWidth(label_ManualControl_5->sizePolicy().hasHeightForWidth());
        label_ManualControl_5->setSizePolicy(sizePolicy4);
        label_ManualControl_5->setFont(font);
        label_ManualControl_5->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_ManualControl_5, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        radioButton_D1 = new QRadioButton(frame_ProfileOptions_2);
        radioButton_D1->setObjectName(QStringLiteral("radioButton_D1"));
        sizePolicy3.setHeightForWidth(radioButton_D1->sizePolicy().hasHeightForWidth());
        radioButton_D1->setSizePolicy(sizePolicy3);
        radioButton_D1->setFont(font1);

        horizontalLayout_3->addWidget(radioButton_D1);

        radioButton_D2 = new QRadioButton(frame_ProfileOptions_2);
        radioButton_D2->setObjectName(QStringLiteral("radioButton_D2"));
        sizePolicy3.setHeightForWidth(radioButton_D2->sizePolicy().hasHeightForWidth());
        radioButton_D2->setSizePolicy(sizePolicy3);
        radioButton_D2->setFont(font1);

        horizontalLayout_3->addWidget(radioButton_D2);

        radioButton_D3 = new QRadioButton(frame_ProfileOptions_2);
        radioButton_D3->setObjectName(QStringLiteral("radioButton_D3"));
        sizePolicy3.setHeightForWidth(radioButton_D3->sizePolicy().hasHeightForWidth());
        radioButton_D3->setSizePolicy(sizePolicy3);
        radioButton_D3->setFont(font1);

        horizontalLayout_3->addWidget(radioButton_D3);


        gridLayout_5->addLayout(horizontalLayout_3, 1, 0, 1, 1);


        gridLayout_9->addWidget(frame_ProfileOptions_2, 1, 0, 1, 1);

        frame_ProfileOptions_3 = new QFrame(centralWidget);
        frame_ProfileOptions_3->setObjectName(QStringLiteral("frame_ProfileOptions_3"));
        sizePolicy3.setHeightForWidth(frame_ProfileOptions_3->sizePolicy().hasHeightForWidth());
        frame_ProfileOptions_3->setSizePolicy(sizePolicy3);
        frame_ProfileOptions_3->setMinimumSize(QSize(370, 70));
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
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(textEdit_CMD->sizePolicy().hasHeightForWidth());
        textEdit_CMD->setSizePolicy(sizePolicy6);
        textEdit_CMD->setMinimumSize(QSize(0, 30));
        textEdit_CMD->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_4->addWidget(textEdit_CMD);

        pushButton_CMDSend = new QPushButton(frame_ProfileOptions_3);
        pushButton_CMDSend->setObjectName(QStringLiteral("pushButton_CMDSend"));
        sizePolicy3.setHeightForWidth(pushButton_CMDSend->sizePolicy().hasHeightForWidth());
        pushButton_CMDSend->setSizePolicy(sizePolicy3);
        pushButton_CMDSend->setMinimumSize(QSize(80, 30));
        pushButton_CMDSend->setFont(font1);

        horizontalLayout_4->addWidget(pushButton_CMDSend);


        gridLayout_7->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        gridLayout_9->addWidget(frame_ProfileOptions_3, 1, 1, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 1, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer, 1, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1087, 22));
        menuGalil = new QMenu(menuBar);
        menuGalil->setObjectName(QStringLiteral("menuGalil"));
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
        menuGalil->addAction(actionLoad_Program);
        menuGalil->addSeparator();
        menuGalil->addAction(actionOpen_Connection);
        menuGalil->addAction(actionClose_Connection);
        menuGalil->addSeparator();
        menuGalil->addAction(actionExit);
        menuSettings->addAction(actionSave_Current_Parameters);
        menuSettings->addAction(actionSave_As_Current_Parameters);
        menuSettings->addAction(actionLoad_Parameters);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionSave_Program->setText(QApplication::translate("MainWindow", "Save Program", Q_NULLPTR));
        actionSave_As_Program->setText(QApplication::translate("MainWindow", "Save_As Program", Q_NULLPTR));
        actionLoad_Program->setText(QApplication::translate("MainWindow", "Load Program", Q_NULLPTR));
        actionSave_Current_Parameters->setText(QApplication::translate("MainWindow", "Save Current Parameters", Q_NULLPTR));
        actionSave_As_Current_Parameters->setText(QApplication::translate("MainWindow", "Save_As Current Parameters", Q_NULLPTR));
        actionLoad_Parameters->setText(QApplication::translate("MainWindow", "Load Parameters", Q_NULLPTR));
        actionOpen_Connection->setText(QApplication::translate("MainWindow", "Open Connection", Q_NULLPTR));
        actionClose_Connection->setText(QApplication::translate("MainWindow", "Close Connection", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        label_ManualControl_2->setText(QApplication::translate("MainWindow", "Profile Optons", Q_NULLPTR));
        pushButton_DownloadProgram->setText(QApplication::translate("MainWindow", "Download Program", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Depth of Cut (um)", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Cut Speed (um/s)", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Linear ALL", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Retract Distance (um)", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Retract Period (ms)", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Pause (ms)", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Step Size (um)", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Vibration Profile", Q_NULLPTR));
        pushButton_UploadProgram->setText(QApplication::translate("MainWindow", "Upload Program", Q_NULLPTR));
        pushButton_RunProfile->setText(QApplication::translate("MainWindow", "Run Profile", Q_NULLPTR));
        pushButton_StopProfile->setText(QApplication::translate("MainWindow", "Stop Profile", Q_NULLPTR));
        pushButton_SetInitialGap->setText(QApplication::translate("MainWindow", "Set Initial Gap", Q_NULLPTR));
        label_ManualControl->setText(QApplication::translate("MainWindow", "Manual Control", Q_NULLPTR));
        pushButton_SetHome->setText(QApplication::translate("MainWindow", "Set Home", Q_NULLPTR));
        pushButton_MoveHome->setText(QApplication::translate("MainWindow", "Move To Home", Q_NULLPTR));
        label_ManualControl_3->setText(QApplication::translate("MainWindow", "Jog Control (um/sec)", Q_NULLPTR));
        label_ManualControl_4->setText(QApplication::translate("MainWindow", "Step Control (um)", Q_NULLPTR));
        pushButton_IncreaseJog->setText(QApplication::translate("MainWindow", "INCREASE", Q_NULLPTR));
        pushButton_DecreaseJog->setText(QApplication::translate("MainWindow", "DECREASE", Q_NULLPTR));
        pushButton_IncreaseRelativeMove->setText(QApplication::translate("MainWindow", "INCREASE", Q_NULLPTR));
        pushButton_DecreaseRelativeMove->setText(QApplication::translate("MainWindow", "DECREASE", Q_NULLPTR));
        pushButton_MotorEnable->setText(QApplication::translate("MainWindow", "ENABLE MOTOR", Q_NULLPTR));
        pushButton_MotorDisable->setText(QApplication::translate("MainWindow", "STOP MOTOR", Q_NULLPTR));
        label_ManualControl_5->setText(QApplication::translate("MainWindow", "DIO Signals", Q_NULLPTR));
        radioButton_D1->setText(QApplication::translate("MainWindow", "D1", Q_NULLPTR));
        radioButton_D2->setText(QApplication::translate("MainWindow", "D2", Q_NULLPTR));
        radioButton_D3->setText(QApplication::translate("MainWindow", "D3", Q_NULLPTR));
        textEdit_CMD->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", Q_NULLPTR));
        pushButton_CMDSend->setText(QApplication::translate("MainWindow", "SEND", Q_NULLPTR));
        menuGalil->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Parameters", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
