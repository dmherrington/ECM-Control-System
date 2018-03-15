/********************************************************************************
** Form generated from reading UI file 'ECM_controller_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ECM_CONTROLLER_GUI_H
#define UI_ECM_CONTROLLER_GUI_H

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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ECMControllerGUI
{
public:
    QWidget *centralWidget;
    QFrame *frame_TouchoffControl;
    QGridLayout *gridLayout_9;
    QPushButton *pushButton_TouchoffRef;
    QSpinBox *spinBox_TouchoffRef;
    QFrame *frame_ProfileOptions;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_4;
    QSplitter *splitter_2;
    QLabel *label_ManualControl_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_DownloadProgram;
    QPushButton *pushButton_UploadProgram;
    QPushButton *pushButton_RunProfile;
    QPushButton *pushButton_SetInitialGap;
    QSpinBox *spinBox_Jog_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *frame_MaunalControl;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_4;
    QLabel *label_ManualControl;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton_SetHome;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_MoveHome;
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
    QWidget *layoutWidget;
    QGridLayout *frame_General;
    QFrame *frame_MotorControl;
    QGridLayout *gridLayout_8;
    QPushButton *pushButton_MotorEnable;
    QPushButton *pushButton_MotorDisable;
    QFrame *frame_DIO;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_D1;
    QRadioButton *radioButton_D2;
    QRadioButton *radioButton_D3;
    QLabel *label_ManualControl_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ECMControllerGUI)
    {
        if (ECMControllerGUI->objectName().isEmpty())
            ECMControllerGUI->setObjectName(QStringLiteral("ECMControllerGUI"));
        ECMControllerGUI->resize(1152, 812);
        centralWidget = new QWidget(ECMControllerGUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame_TouchoffControl = new QFrame(centralWidget);
        frame_TouchoffControl->setObjectName(QStringLiteral("frame_TouchoffControl"));
        frame_TouchoffControl->setGeometry(QRect(430, 670, 366, 70));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_TouchoffControl->sizePolicy().hasHeightForWidth());
        frame_TouchoffControl->setSizePolicy(sizePolicy);
        frame_TouchoffControl->setMinimumSize(QSize(350, 70));
        frame_TouchoffControl->setFrameShape(QFrame::Box);
        frame_TouchoffControl->setFrameShadow(QFrame::Plain);
        frame_TouchoffControl->setLineWidth(2);
        gridLayout_9 = new QGridLayout(frame_TouchoffControl);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        pushButton_TouchoffRef = new QPushButton(frame_TouchoffControl);
        pushButton_TouchoffRef->setObjectName(QStringLiteral("pushButton_TouchoffRef"));
        sizePolicy.setHeightForWidth(pushButton_TouchoffRef->sizePolicy().hasHeightForWidth());
        pushButton_TouchoffRef->setSizePolicy(sizePolicy);
        pushButton_TouchoffRef->setMinimumSize(QSize(130, 30));
        QFont font;
        font.setPointSize(12);
        pushButton_TouchoffRef->setFont(font);

        gridLayout_9->addWidget(pushButton_TouchoffRef, 0, 0, 1, 1);

        spinBox_TouchoffRef = new QSpinBox(frame_TouchoffControl);
        spinBox_TouchoffRef->setObjectName(QStringLiteral("spinBox_TouchoffRef"));
        sizePolicy.setHeightForWidth(spinBox_TouchoffRef->sizePolicy().hasHeightForWidth());
        spinBox_TouchoffRef->setSizePolicy(sizePolicy);
        spinBox_TouchoffRef->setMinimumSize(QSize(112, 30));
        spinBox_TouchoffRef->setFont(font);
        spinBox_TouchoffRef->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_TouchoffRef->setMinimum(1);
        spinBox_TouchoffRef->setMaximum(10000);
        spinBox_TouchoffRef->setSingleStep(10);
        spinBox_TouchoffRef->setValue(100);

        gridLayout_9->addWidget(spinBox_TouchoffRef, 0, 1, 1, 1);

        frame_ProfileOptions = new QFrame(centralWidget);
        frame_ProfileOptions->setObjectName(QStringLiteral("frame_ProfileOptions"));
        frame_ProfileOptions->setGeometry(QRect(10, 366, 480, 287));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
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
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_ManualControl_2->sizePolicy().hasHeightForWidth());
        label_ManualControl_2->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_ManualControl_2->setFont(font1);
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
        pushButton_DownloadProgram->setFont(font);

        verticalLayout_4->addWidget(pushButton_DownloadProgram);

        pushButton_UploadProgram = new QPushButton(frame_ProfileOptions);
        pushButton_UploadProgram->setObjectName(QStringLiteral("pushButton_UploadProgram"));
        sizePolicy.setHeightForWidth(pushButton_UploadProgram->sizePolicy().hasHeightForWidth());
        pushButton_UploadProgram->setSizePolicy(sizePolicy);
        pushButton_UploadProgram->setMinimumSize(QSize(180, 30));
        pushButton_UploadProgram->setFont(font);

        verticalLayout_4->addWidget(pushButton_UploadProgram);

        pushButton_RunProfile = new QPushButton(frame_ProfileOptions);
        pushButton_RunProfile->setObjectName(QStringLiteral("pushButton_RunProfile"));
        sizePolicy.setHeightForWidth(pushButton_RunProfile->sizePolicy().hasHeightForWidth());
        pushButton_RunProfile->setSizePolicy(sizePolicy);
        pushButton_RunProfile->setMinimumSize(QSize(180, 30));
        pushButton_RunProfile->setFont(font);

        verticalLayout_4->addWidget(pushButton_RunProfile);

        pushButton_SetInitialGap = new QPushButton(frame_ProfileOptions);
        pushButton_SetInitialGap->setObjectName(QStringLiteral("pushButton_SetInitialGap"));
        sizePolicy.setHeightForWidth(pushButton_SetInitialGap->sizePolicy().hasHeightForWidth());
        pushButton_SetInitialGap->setSizePolicy(sizePolicy);
        pushButton_SetInitialGap->setMinimumSize(QSize(180, 30));
        pushButton_SetInitialGap->setFont(font);

        verticalLayout_4->addWidget(pushButton_SetInitialGap);

        spinBox_Jog_6 = new QSpinBox(frame_ProfileOptions);
        spinBox_Jog_6->setObjectName(QStringLiteral("spinBox_Jog_6"));
        spinBox_Jog_6->setMinimumSize(QSize(180, 30));
        spinBox_Jog_6->setFont(font);
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
        frame_MaunalControl = new QFrame(centralWidget);
        frame_MaunalControl->setObjectName(QStringLiteral("frame_MaunalControl"));
        frame_MaunalControl->setGeometry(QRect(498, 368, 370, 250));
        sizePolicy.setHeightForWidth(frame_MaunalControl->sizePolicy().hasHeightForWidth());
        frame_MaunalControl->setSizePolicy(sizePolicy);
        frame_MaunalControl->setMinimumSize(QSize(350, 250));
        frame_MaunalControl->setFrameShape(QFrame::Box);
        frame_MaunalControl->setFrameShadow(QFrame::Plain);
        frame_MaunalControl->setLineWidth(2);
        gridLayout_6 = new QGridLayout(frame_MaunalControl);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_ManualControl = new QLabel(frame_MaunalControl);
        label_ManualControl->setObjectName(QStringLiteral("label_ManualControl"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_ManualControl->sizePolicy().hasHeightForWidth());
        label_ManualControl->setSizePolicy(sizePolicy3);
        label_ManualControl->setFont(font1);
        label_ManualControl->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_ManualControl, 0, 1, 1, 3);

        horizontalSpacer_12 = new QSpacerItem(19, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_12, 1, 0, 1, 1);

        pushButton_SetHome = new QPushButton(frame_MaunalControl);
        pushButton_SetHome->setObjectName(QStringLiteral("pushButton_SetHome"));
        sizePolicy.setHeightForWidth(pushButton_SetHome->sizePolicy().hasHeightForWidth());
        pushButton_SetHome->setSizePolicy(sizePolicy);
        pushButton_SetHome->setMinimumSize(QSize(112, 30));
        pushButton_SetHome->setFont(font);

        gridLayout_4->addWidget(pushButton_SetHome, 1, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_10, 1, 2, 1, 1);

        pushButton_MoveHome = new QPushButton(frame_MaunalControl);
        pushButton_MoveHome->setObjectName(QStringLiteral("pushButton_MoveHome"));
        sizePolicy.setHeightForWidth(pushButton_MoveHome->sizePolicy().hasHeightForWidth());
        pushButton_MoveHome->setSizePolicy(sizePolicy);
        pushButton_MoveHome->setMinimumSize(QSize(112, 30));
        pushButton_MoveHome->setFont(font);

        gridLayout_4->addWidget(pushButton_MoveHome, 1, 3, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(18, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_11, 1, 4, 1, 1);

        verticalSpacer = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 2, 2, 1, 1);


        gridLayout_6->addLayout(gridLayout_4, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_ManualControl_4 = new QLabel(frame_MaunalControl);
        label_ManualControl_4->setObjectName(QStringLiteral("label_ManualControl_4"));
        sizePolicy3.setHeightForWidth(label_ManualControl_4->sizePolicy().hasHeightForWidth());
        label_ManualControl_4->setSizePolicy(sizePolicy3);
        label_ManualControl_4->setFont(font1);
        label_ManualControl_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_ManualControl_4, 0, 1, 1, 1);

        label_ManualControl_3 = new QLabel(frame_MaunalControl);
        label_ManualControl_3->setObjectName(QStringLiteral("label_ManualControl_3"));
        sizePolicy3.setHeightForWidth(label_ManualControl_3->sizePolicy().hasHeightForWidth());
        label_ManualControl_3->setSizePolicy(sizePolicy3);
        label_ManualControl_3->setFont(font1);
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
        pushButton_IncreaseRelativeMove->setFont(font);

        verticalLayout_2->addWidget(pushButton_IncreaseRelativeMove);

        spinBox_RelativeMove = new QSpinBox(frame_MaunalControl);
        spinBox_RelativeMove->setObjectName(QStringLiteral("spinBox_RelativeMove"));
        sizePolicy.setHeightForWidth(spinBox_RelativeMove->sizePolicy().hasHeightForWidth());
        spinBox_RelativeMove->setSizePolicy(sizePolicy);
        spinBox_RelativeMove->setMinimumSize(QSize(112, 30));
        spinBox_RelativeMove->setFont(font);
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
        pushButton_DecreaseRelativeMove->setFont(font);

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
        pushButton_IncreaseJog->setFont(font);

        verticalLayout->addWidget(pushButton_IncreaseJog);

        spinBox_Jog = new QSpinBox(frame_MaunalControl);
        spinBox_Jog->setObjectName(QStringLiteral("spinBox_Jog"));
        sizePolicy.setHeightForWidth(spinBox_Jog->sizePolicy().hasHeightForWidth());
        spinBox_Jog->setSizePolicy(sizePolicy);
        spinBox_Jog->setMinimumSize(QSize(112, 30));
        spinBox_Jog->setFont(font);
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
        pushButton_DecreaseJog->setFont(font);

        verticalLayout->addWidget(pushButton_DecreaseJog);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout, 1, 0, 1, 1);

        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(874, 368, 154, 226));
        frame_General = new QGridLayout(layoutWidget);
        frame_General->setSpacing(6);
        frame_General->setContentsMargins(11, 11, 11, 11);
        frame_General->setObjectName(QStringLiteral("frame_General"));
        frame_General->setContentsMargins(0, 0, 0, 0);
        frame_MotorControl = new QFrame(layoutWidget);
        frame_MotorControl->setObjectName(QStringLiteral("frame_MotorControl"));
        frame_MotorControl->setFrameShape(QFrame::Box);
        frame_MotorControl->setFrameShadow(QFrame::Plain);
        frame_MotorControl->setLineWidth(2);
        gridLayout_8 = new QGridLayout(frame_MotorControl);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        pushButton_MotorEnable = new QPushButton(frame_MotorControl);
        pushButton_MotorEnable->setObjectName(QStringLiteral("pushButton_MotorEnable"));
        sizePolicy.setHeightForWidth(pushButton_MotorEnable->sizePolicy().hasHeightForWidth());
        pushButton_MotorEnable->setSizePolicy(sizePolicy);
        pushButton_MotorEnable->setMinimumSize(QSize(130, 30));
        pushButton_MotorEnable->setFont(font);

        gridLayout_8->addWidget(pushButton_MotorEnable, 0, 0, 1, 1);

        pushButton_MotorDisable = new QPushButton(frame_MotorControl);
        pushButton_MotorDisable->setObjectName(QStringLiteral("pushButton_MotorDisable"));
        sizePolicy.setHeightForWidth(pushButton_MotorDisable->sizePolicy().hasHeightForWidth());
        pushButton_MotorDisable->setSizePolicy(sizePolicy);
        pushButton_MotorDisable->setMinimumSize(QSize(130, 30));
        pushButton_MotorDisable->setFont(font);

        gridLayout_8->addWidget(pushButton_MotorDisable, 1, 0, 1, 1);


        frame_General->addWidget(frame_MotorControl, 0, 0, 1, 1);

        frame_DIO = new QFrame(layoutWidget);
        frame_DIO->setObjectName(QStringLiteral("frame_DIO"));
        sizePolicy1.setHeightForWidth(frame_DIO->sizePolicy().hasHeightForWidth());
        frame_DIO->setSizePolicy(sizePolicy1);
        frame_DIO->setMinimumSize(QSize(152, 70));
        frame_DIO->setFrameShape(QFrame::Box);
        frame_DIO->setFrameShadow(QFrame::Plain);
        frame_DIO->setLineWidth(2);
        gridLayout_3 = new QGridLayout(frame_DIO);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        radioButton_D1 = new QRadioButton(frame_DIO);
        radioButton_D1->setObjectName(QStringLiteral("radioButton_D1"));
        sizePolicy.setHeightForWidth(radioButton_D1->sizePolicy().hasHeightForWidth());
        radioButton_D1->setSizePolicy(sizePolicy);
        radioButton_D1->setFont(font);

        verticalLayout_3->addWidget(radioButton_D1);

        radioButton_D2 = new QRadioButton(frame_DIO);
        radioButton_D2->setObjectName(QStringLiteral("radioButton_D2"));
        sizePolicy.setHeightForWidth(radioButton_D2->sizePolicy().hasHeightForWidth());
        radioButton_D2->setSizePolicy(sizePolicy);
        radioButton_D2->setFont(font);

        verticalLayout_3->addWidget(radioButton_D2);

        radioButton_D3 = new QRadioButton(frame_DIO);
        radioButton_D3->setObjectName(QStringLiteral("radioButton_D3"));
        sizePolicy.setHeightForWidth(radioButton_D3->sizePolicy().hasHeightForWidth());
        radioButton_D3->setSizePolicy(sizePolicy);
        radioButton_D3->setFont(font);

        verticalLayout_3->addWidget(radioButton_D3);


        gridLayout_3->addLayout(verticalLayout_3, 1, 0, 1, 1);

        label_ManualControl_5 = new QLabel(frame_DIO);
        label_ManualControl_5->setObjectName(QStringLiteral("label_ManualControl_5"));
        sizePolicy2.setHeightForWidth(label_ManualControl_5->sizePolicy().hasHeightForWidth());
        label_ManualControl_5->setSizePolicy(sizePolicy2);
        label_ManualControl_5->setFont(font1);
        label_ManualControl_5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_ManualControl_5, 0, 0, 1, 1);


        frame_General->addWidget(frame_DIO, 1, 0, 1, 1);

        ECMControllerGUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ECMControllerGUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1152, 21));
        ECMControllerGUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ECMControllerGUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ECMControllerGUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ECMControllerGUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ECMControllerGUI->setStatusBar(statusBar);

        retranslateUi(ECMControllerGUI);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ECMControllerGUI);
    } // setupUi

    void retranslateUi(QMainWindow *ECMControllerGUI)
    {
        ECMControllerGUI->setWindowTitle(QApplication::translate("ECMControllerGUI", "ECMControllerGUI", nullptr));
        pushButton_TouchoffRef->setText(QApplication::translate("ECMControllerGUI", "Set Touchoff Ref", nullptr));
        label_ManualControl_2->setText(QApplication::translate("ECMControllerGUI", "Profile Optons", nullptr));
        pushButton_DownloadProgram->setText(QApplication::translate("ECMControllerGUI", "Download Program", nullptr));
        pushButton_UploadProgram->setText(QApplication::translate("ECMControllerGUI", "Upload Program", nullptr));
        pushButton_RunProfile->setText(QApplication::translate("ECMControllerGUI", "Run Profile", nullptr));
        pushButton_SetInitialGap->setText(QApplication::translate("ECMControllerGUI", "Set Initial Gap", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ECMControllerGUI", "Tab 1", nullptr));
        label_ManualControl->setText(QApplication::translate("ECMControllerGUI", "Manual Control", nullptr));
        pushButton_SetHome->setText(QApplication::translate("ECMControllerGUI", "Find Home", nullptr));
        pushButton_MoveHome->setText(QApplication::translate("ECMControllerGUI", "Move To Home", nullptr));
        label_ManualControl_4->setText(QApplication::translate("ECMControllerGUI", "Step Control (um)", nullptr));
        label_ManualControl_3->setText(QApplication::translate("ECMControllerGUI", "Jog Control (um/sec)", nullptr));
        pushButton_IncreaseRelativeMove->setText(QApplication::translate("ECMControllerGUI", "INCREASE", nullptr));
        pushButton_DecreaseRelativeMove->setText(QApplication::translate("ECMControllerGUI", "DECREASE", nullptr));
        pushButton_IncreaseJog->setText(QApplication::translate("ECMControllerGUI", "INCREASE", nullptr));
        pushButton_DecreaseJog->setText(QApplication::translate("ECMControllerGUI", "DECREASE", nullptr));
        pushButton_MotorEnable->setText(QApplication::translate("ECMControllerGUI", "ENABLE MOTOR", nullptr));
        pushButton_MotorDisable->setText(QApplication::translate("ECMControllerGUI", "STOP MOTOR", nullptr));
        radioButton_D1->setText(QApplication::translate("ECMControllerGUI", "D1", nullptr));
        radioButton_D2->setText(QApplication::translate("ECMControllerGUI", "D2", nullptr));
        radioButton_D3->setText(QApplication::translate("ECMControllerGUI", "D3", nullptr));
        label_ManualControl_5->setText(QApplication::translate("ECMControllerGUI", "DIO Signals", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ECMControllerGUI: public Ui_ECMControllerGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECM_CONTROLLER_GUI_H
