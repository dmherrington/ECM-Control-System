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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QFrame *frame_ProfileOptions;
    QGridLayout *gridLayout_7;
    QSplitter *splitter_2;
    QLabel *label_ManualControl_2;
    QPushButton *pushButton_RunProfile;
    QTabWidget *tabWidget;
    QWidget *tab_linearParams;
    QGridLayout *gridLayout_5;
    QFormLayout *formLayout_2;
    QLabel *label_CutDepth;
    QSpinBox *spinBox_CutDepth;
    QLabel *label_CutSpeed;
    QSpinBox *spinBox_CutSpeed;
    QWidget *tab_vibrationParams;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    QLabel *label_RetractDistance;
    QSpinBox *spinBox_RetractDistance;
    QLabel *label_RetractPeriod;
    QSpinBox *spinBox_RetractPeriod;
    QLabel *label_Pause;
    QSpinBox *spinBox_Pause;
    QLabel *label_StepSize;
    QSpinBox *spinBox_StepSize;
    QComboBox *comboBox_ProgramProfiles;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_UploadProgram;
    QFormLayout *formLayout_3;
    QPushButton *pushButton_EstablishTouchoff;
    QWidget *widget;
    QPushButton *pushButton_DownloadProgram;
    QFrame *frame_MaunalControl;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_4;
    QLabel *label_ManualControl;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton_SetHome;
    QPushButton *pushButton_MoveHome;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_11;
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
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_MotorEnable;
    QPushButton *pushButton_MotorDisable;
    QFrame *frame_MotorControl;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton;
    QFrame *frame_DIO;
    QLabel *label_ManualControl_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ECMControllerGUI)
    {
        if (ECMControllerGUI->objectName().isEmpty())
            ECMControllerGUI->setObjectName(QStringLiteral("ECMControllerGUI"));
        ECMControllerGUI->resize(1019, 812);
        ECMControllerGUI->setStyleSheet(QLatin1String("QMainWindow{\n"
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
        centralWidget = new QWidget(ECMControllerGUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame_ProfileOptions = new QFrame(centralWidget);
        frame_ProfileOptions->setObjectName(QStringLiteral("frame_ProfileOptions"));
        frame_ProfileOptions->setGeometry(QRect(10, 480, 480, 250));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_ProfileOptions->sizePolicy().hasHeightForWidth());
        frame_ProfileOptions->setSizePolicy(sizePolicy);
        frame_ProfileOptions->setMinimumSize(QSize(480, 250));
        frame_ProfileOptions->setMaximumSize(QSize(480, 250));
        frame_ProfileOptions->setFrameShape(QFrame::Box);
        frame_ProfileOptions->setFrameShadow(QFrame::Plain);
        frame_ProfileOptions->setLineWidth(2);
        gridLayout_7 = new QGridLayout(frame_ProfileOptions);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        splitter_2 = new QSplitter(frame_ProfileOptions);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label_ManualControl_2 = new QLabel(splitter_2);
        label_ManualControl_2->setObjectName(QStringLiteral("label_ManualControl_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_ManualControl_2->sizePolicy().hasHeightForWidth());
        label_ManualControl_2->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_ManualControl_2->setFont(font);
        label_ManualControl_2->setAlignment(Qt::AlignCenter);
        splitter_2->addWidget(label_ManualControl_2);

        gridLayout_7->addWidget(splitter_2, 0, 0, 1, 1);

        pushButton_RunProfile = new QPushButton(frame_ProfileOptions);
        pushButton_RunProfile->setObjectName(QStringLiteral("pushButton_RunProfile"));
        sizePolicy.setHeightForWidth(pushButton_RunProfile->sizePolicy().hasHeightForWidth());
        pushButton_RunProfile->setSizePolicy(sizePolicy);
        pushButton_RunProfile->setMinimumSize(QSize(180, 30));
        QFont font1;
        font1.setPointSize(12);
        pushButton_RunProfile->setFont(font1);

        gridLayout_7->addWidget(pushButton_RunProfile, 0, 1, 2, 1);

        tabWidget = new QTabWidget(frame_ProfileOptions);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(280, 160));
        tabWidget->setMaximumSize(QSize(280, 160));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab_linearParams = new QWidget();
        tab_linearParams->setObjectName(QStringLiteral("tab_linearParams"));
        gridLayout_5 = new QGridLayout(tab_linearParams);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_CutDepth = new QLabel(tab_linearParams);
        label_CutDepth->setObjectName(QStringLiteral("label_CutDepth"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_CutDepth->sizePolicy().hasHeightForWidth());
        label_CutDepth->setSizePolicy(sizePolicy2);
        label_CutDepth->setMinimumSize(QSize(145, 25));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label_CutDepth->setFont(font2);
        label_CutDepth->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_CutDepth);

        spinBox_CutDepth = new QSpinBox(tab_linearParams);
        spinBox_CutDepth->setObjectName(QStringLiteral("spinBox_CutDepth"));
        sizePolicy.setHeightForWidth(spinBox_CutDepth->sizePolicy().hasHeightForWidth());
        spinBox_CutDepth->setSizePolicy(sizePolicy);
        spinBox_CutDepth->setMinimumSize(QSize(100, 25));
        QFont font3;
        font3.setPointSize(10);
        spinBox_CutDepth->setFont(font3);
        spinBox_CutDepth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_CutDepth->setMinimum(1);
        spinBox_CutDepth->setMaximum(10000);
        spinBox_CutDepth->setSingleStep(10);
        spinBox_CutDepth->setValue(100);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinBox_CutDepth);

        label_CutSpeed = new QLabel(tab_linearParams);
        label_CutSpeed->setObjectName(QStringLiteral("label_CutSpeed"));
        sizePolicy2.setHeightForWidth(label_CutSpeed->sizePolicy().hasHeightForWidth());
        label_CutSpeed->setSizePolicy(sizePolicy2);
        label_CutSpeed->setMinimumSize(QSize(145, 25));
        label_CutSpeed->setFont(font2);
        label_CutSpeed->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_CutSpeed);

        spinBox_CutSpeed = new QSpinBox(tab_linearParams);
        spinBox_CutSpeed->setObjectName(QStringLiteral("spinBox_CutSpeed"));
        sizePolicy.setHeightForWidth(spinBox_CutSpeed->sizePolicy().hasHeightForWidth());
        spinBox_CutSpeed->setSizePolicy(sizePolicy);
        spinBox_CutSpeed->setMinimumSize(QSize(100, 25));
        spinBox_CutSpeed->setFont(font3);
        spinBox_CutSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_CutSpeed->setMinimum(1);
        spinBox_CutSpeed->setMaximum(10000);
        spinBox_CutSpeed->setSingleStep(10);
        spinBox_CutSpeed->setValue(100);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spinBox_CutSpeed);


        gridLayout_5->addLayout(formLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_linearParams, QString());
        tab_vibrationParams = new QWidget();
        tab_vibrationParams->setObjectName(QStringLiteral("tab_vibrationParams"));
        gridLayout_2 = new QGridLayout(tab_vibrationParams);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_RetractDistance = new QLabel(tab_vibrationParams);
        label_RetractDistance->setObjectName(QStringLiteral("label_RetractDistance"));
        sizePolicy2.setHeightForWidth(label_RetractDistance->sizePolicy().hasHeightForWidth());
        label_RetractDistance->setSizePolicy(sizePolicy2);
        label_RetractDistance->setMinimumSize(QSize(145, 25));
        label_RetractDistance->setFont(font2);
        label_RetractDistance->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_RetractDistance);

        spinBox_RetractDistance = new QSpinBox(tab_vibrationParams);
        spinBox_RetractDistance->setObjectName(QStringLiteral("spinBox_RetractDistance"));
        sizePolicy.setHeightForWidth(spinBox_RetractDistance->sizePolicy().hasHeightForWidth());
        spinBox_RetractDistance->setSizePolicy(sizePolicy);
        spinBox_RetractDistance->setMinimumSize(QSize(100, 25));
        spinBox_RetractDistance->setFont(font3);
        spinBox_RetractDistance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_RetractDistance->setMinimum(1);
        spinBox_RetractDistance->setMaximum(10000);
        spinBox_RetractDistance->setSingleStep(10);
        spinBox_RetractDistance->setValue(100);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox_RetractDistance);

        label_RetractPeriod = new QLabel(tab_vibrationParams);
        label_RetractPeriod->setObjectName(QStringLiteral("label_RetractPeriod"));
        sizePolicy2.setHeightForWidth(label_RetractPeriod->sizePolicy().hasHeightForWidth());
        label_RetractPeriod->setSizePolicy(sizePolicy2);
        label_RetractPeriod->setMinimumSize(QSize(145, 25));
        label_RetractPeriod->setFont(font2);
        label_RetractPeriod->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_RetractPeriod);

        spinBox_RetractPeriod = new QSpinBox(tab_vibrationParams);
        spinBox_RetractPeriod->setObjectName(QStringLiteral("spinBox_RetractPeriod"));
        sizePolicy.setHeightForWidth(spinBox_RetractPeriod->sizePolicy().hasHeightForWidth());
        spinBox_RetractPeriod->setSizePolicy(sizePolicy);
        spinBox_RetractPeriod->setMinimumSize(QSize(100, 25));
        spinBox_RetractPeriod->setFont(font3);
        spinBox_RetractPeriod->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_RetractPeriod->setMinimum(1);
        spinBox_RetractPeriod->setMaximum(10000);
        spinBox_RetractPeriod->setSingleStep(10);
        spinBox_RetractPeriod->setValue(100);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox_RetractPeriod);

        label_Pause = new QLabel(tab_vibrationParams);
        label_Pause->setObjectName(QStringLiteral("label_Pause"));
        sizePolicy2.setHeightForWidth(label_Pause->sizePolicy().hasHeightForWidth());
        label_Pause->setSizePolicy(sizePolicy2);
        label_Pause->setMinimumSize(QSize(145, 25));
        label_Pause->setFont(font2);
        label_Pause->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_Pause);

        spinBox_Pause = new QSpinBox(tab_vibrationParams);
        spinBox_Pause->setObjectName(QStringLiteral("spinBox_Pause"));
        sizePolicy.setHeightForWidth(spinBox_Pause->sizePolicy().hasHeightForWidth());
        spinBox_Pause->setSizePolicy(sizePolicy);
        spinBox_Pause->setMinimumSize(QSize(100, 25));
        spinBox_Pause->setFont(font3);
        spinBox_Pause->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_Pause->setMinimum(1);
        spinBox_Pause->setMaximum(10000);
        spinBox_Pause->setSingleStep(10);
        spinBox_Pause->setValue(100);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox_Pause);

        label_StepSize = new QLabel(tab_vibrationParams);
        label_StepSize->setObjectName(QStringLiteral("label_StepSize"));
        sizePolicy2.setHeightForWidth(label_StepSize->sizePolicy().hasHeightForWidth());
        label_StepSize->setSizePolicy(sizePolicy2);
        label_StepSize->setMinimumSize(QSize(145, 25));
        label_StepSize->setFont(font2);
        label_StepSize->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_StepSize);

        spinBox_StepSize = new QSpinBox(tab_vibrationParams);
        spinBox_StepSize->setObjectName(QStringLiteral("spinBox_StepSize"));
        sizePolicy.setHeightForWidth(spinBox_StepSize->sizePolicy().hasHeightForWidth());
        spinBox_StepSize->setSizePolicy(sizePolicy);
        spinBox_StepSize->setMinimumSize(QSize(100, 25));
        spinBox_StepSize->setFont(font3);
        spinBox_StepSize->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_StepSize->setMinimum(1);
        spinBox_StepSize->setMaximum(10000);
        spinBox_StepSize->setSingleStep(10);
        spinBox_StepSize->setValue(100);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBox_StepSize);


        gridLayout_2->addLayout(formLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab_vibrationParams, QString());

        gridLayout_7->addWidget(tabWidget, 1, 0, 4, 1);

        comboBox_ProgramProfiles = new QComboBox(frame_ProfileOptions);
        comboBox_ProgramProfiles->setObjectName(QStringLiteral("comboBox_ProgramProfiles"));
        comboBox_ProgramProfiles->setMinimumSize(QSize(180, 30));

        gridLayout_7->addWidget(comboBox_ProgramProfiles, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 79, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_2, 3, 1, 1, 1);

        pushButton_UploadProgram = new QPushButton(frame_ProfileOptions);
        pushButton_UploadProgram->setObjectName(QStringLiteral("pushButton_UploadProgram"));
        sizePolicy.setHeightForWidth(pushButton_UploadProgram->sizePolicy().hasHeightForWidth());
        pushButton_UploadProgram->setSizePolicy(sizePolicy);
        pushButton_UploadProgram->setMinimumSize(QSize(180, 30));
        pushButton_UploadProgram->setFont(font1);

        gridLayout_7->addWidget(pushButton_UploadProgram, 4, 1, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        pushButton_EstablishTouchoff = new QPushButton(frame_ProfileOptions);
        pushButton_EstablishTouchoff->setObjectName(QStringLiteral("pushButton_EstablishTouchoff"));
        sizePolicy.setHeightForWidth(pushButton_EstablishTouchoff->sizePolicy().hasHeightForWidth());
        pushButton_EstablishTouchoff->setSizePolicy(sizePolicy);
        pushButton_EstablishTouchoff->setMinimumSize(QSize(180, 30));
        pushButton_EstablishTouchoff->setFont(font1);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, pushButton_EstablishTouchoff);

        widget = new QWidget(frame_ProfileOptions);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(30, 30));
        widget->setMaximumSize(QSize(30, 30));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, widget);


        gridLayout_7->addLayout(formLayout_3, 5, 0, 1, 1);

        pushButton_DownloadProgram = new QPushButton(frame_ProfileOptions);
        pushButton_DownloadProgram->setObjectName(QStringLiteral("pushButton_DownloadProgram"));
        sizePolicy.setHeightForWidth(pushButton_DownloadProgram->sizePolicy().hasHeightForWidth());
        pushButton_DownloadProgram->setSizePolicy(sizePolicy);
        pushButton_DownloadProgram->setMinimumSize(QSize(180, 30));
        pushButton_DownloadProgram->setFont(font1);

        gridLayout_7->addWidget(pushButton_DownloadProgram, 5, 1, 1, 1);

        frame_MaunalControl = new QFrame(centralWidget);
        frame_MaunalControl->setObjectName(QStringLiteral("frame_MaunalControl"));
        frame_MaunalControl->setGeometry(QRect(500, 480, 350, 250));
        sizePolicy.setHeightForWidth(frame_MaunalControl->sizePolicy().hasHeightForWidth());
        frame_MaunalControl->setSizePolicy(sizePolicy);
        frame_MaunalControl->setMinimumSize(QSize(350, 250));
        frame_MaunalControl->setMaximumSize(QSize(350, 250));
        frame_MaunalControl->setFrameShape(QFrame::Box);
        frame_MaunalControl->setFrameShadow(QFrame::Plain);
        frame_MaunalControl->setLineWidth(2);
        gridLayout_9 = new QGridLayout(frame_MaunalControl);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_ManualControl = new QLabel(frame_MaunalControl);
        label_ManualControl->setObjectName(QStringLiteral("label_ManualControl"));
        sizePolicy2.setHeightForWidth(label_ManualControl->sizePolicy().hasHeightForWidth());
        label_ManualControl->setSizePolicy(sizePolicy2);
        label_ManualControl->setFont(font);
        label_ManualControl->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_ManualControl, 0, 1, 1, 3);

        horizontalSpacer_12 = new QSpacerItem(19, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_12, 1, 0, 1, 1);

        pushButton_SetHome = new QPushButton(frame_MaunalControl);
        pushButton_SetHome->setObjectName(QStringLiteral("pushButton_SetHome"));
        sizePolicy.setHeightForWidth(pushButton_SetHome->sizePolicy().hasHeightForWidth());
        pushButton_SetHome->setSizePolicy(sizePolicy);
        pushButton_SetHome->setMinimumSize(QSize(112, 30));
        pushButton_SetHome->setFont(font1);

        gridLayout_4->addWidget(pushButton_SetHome, 1, 1, 1, 1);

        pushButton_MoveHome = new QPushButton(frame_MaunalControl);
        pushButton_MoveHome->setObjectName(QStringLiteral("pushButton_MoveHome"));
        sizePolicy.setHeightForWidth(pushButton_MoveHome->sizePolicy().hasHeightForWidth());
        pushButton_MoveHome->setSizePolicy(sizePolicy);
        pushButton_MoveHome->setMinimumSize(QSize(112, 30));
        pushButton_MoveHome->setFont(font1);

        gridLayout_4->addWidget(pushButton_MoveHome, 1, 3, 1, 1);

        verticalSpacer = new QSpacerItem(17, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 2, 2, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_10, 1, 2, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(18, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_11, 1, 4, 1, 1);


        gridLayout_9->addLayout(gridLayout_4, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_ManualControl_4 = new QLabel(frame_MaunalControl);
        label_ManualControl_4->setObjectName(QStringLiteral("label_ManualControl_4"));
        sizePolicy2.setHeightForWidth(label_ManualControl_4->sizePolicy().hasHeightForWidth());
        label_ManualControl_4->setSizePolicy(sizePolicy2);
        label_ManualControl_4->setFont(font);
        label_ManualControl_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_ManualControl_4, 0, 1, 1, 1);

        label_ManualControl_3 = new QLabel(frame_MaunalControl);
        label_ManualControl_3->setObjectName(QStringLiteral("label_ManualControl_3"));
        sizePolicy2.setHeightForWidth(label_ManualControl_3->sizePolicy().hasHeightForWidth());
        label_ManualControl_3->setSizePolicy(sizePolicy2);
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


        gridLayout_9->addLayout(gridLayout, 1, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        pushButton_MotorEnable = new QPushButton(frame_MaunalControl);
        pushButton_MotorEnable->setObjectName(QStringLiteral("pushButton_MotorEnable"));
        sizePolicy.setHeightForWidth(pushButton_MotorEnable->sizePolicy().hasHeightForWidth());
        pushButton_MotorEnable->setSizePolicy(sizePolicy);
        pushButton_MotorEnable->setMinimumSize(QSize(130, 30));
        pushButton_MotorEnable->setFont(font1);

        gridLayout_6->addWidget(pushButton_MotorEnable, 0, 0, 1, 1);

        pushButton_MotorDisable = new QPushButton(frame_MaunalControl);
        pushButton_MotorDisable->setObjectName(QStringLiteral("pushButton_MotorDisable"));
        sizePolicy.setHeightForWidth(pushButton_MotorDisable->sizePolicy().hasHeightForWidth());
        pushButton_MotorDisable->setSizePolicy(sizePolicy);
        pushButton_MotorDisable->setMinimumSize(QSize(130, 30));
        pushButton_MotorDisable->setFont(font1);

        gridLayout_6->addWidget(pushButton_MotorDisable, 0, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_6, 2, 0, 1, 1);

        frame_MotorControl = new QFrame(centralWidget);
        frame_MotorControl->setObjectName(QStringLiteral("frame_MotorControl"));
        frame_MotorControl->setGeometry(QRect(860, 480, 151, 91));
        frame_MotorControl->setFrameShape(QFrame::Box);
        frame_MotorControl->setFrameShadow(QFrame::Plain);
        frame_MotorControl->setLineWidth(2);
        gridLayout_3 = new QGridLayout(frame_MotorControl);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton = new QPushButton(frame_MotorControl);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(120, 50));
        pushButton->setMaximumSize(QSize(120, 50));
        QFont font4;
        font4.setPointSize(18);
        font4.setBold(true);
        font4.setWeight(75);
        pushButton->setFont(font4);

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);

        frame_DIO = new QFrame(centralWidget);
        frame_DIO->setObjectName(QStringLiteral("frame_DIO"));
        frame_DIO->setGeometry(QRect(860, 579, 152, 151));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_DIO->sizePolicy().hasHeightForWidth());
        frame_DIO->setSizePolicy(sizePolicy3);
        frame_DIO->setMinimumSize(QSize(152, 70));
        frame_DIO->setFrameShape(QFrame::Box);
        frame_DIO->setFrameShadow(QFrame::Plain);
        frame_DIO->setLineWidth(2);
        label_ManualControl_5 = new QLabel(frame_DIO);
        label_ManualControl_5->setObjectName(QStringLiteral("label_ManualControl_5"));
        label_ManualControl_5->setGeometry(QRect(30, 10, 94, 19));
        sizePolicy1.setHeightForWidth(label_ManualControl_5->sizePolicy().hasHeightForWidth());
        label_ManualControl_5->setSizePolicy(sizePolicy1);
        label_ManualControl_5->setFont(font);
        label_ManualControl_5->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 450, 480, 25));
        lineEdit->setMinimumSize(QSize(480, 25));
        lineEdit->setMaximumSize(QSize(480, 25));
        lineEdit->setFont(font3);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(500, 450, 350, 25));
        lineEdit_2->setMinimumSize(QSize(350, 25));
        lineEdit_2->setMaximumSize(QSize(350, 25));
        lineEdit_2->setFont(font3);
        ECMControllerGUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ECMControllerGUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1019, 40));
        ECMControllerGUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ECMControllerGUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ECMControllerGUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ECMControllerGUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ECMControllerGUI->setStatusBar(statusBar);

        retranslateUi(ECMControllerGUI);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ECMControllerGUI);
    } // setupUi

    void retranslateUi(QMainWindow *ECMControllerGUI)
    {
        ECMControllerGUI->setWindowTitle(QApplication::translate("ECMControllerGUI", "ECMControllerGUI", nullptr));
        label_ManualControl_2->setText(QApplication::translate("ECMControllerGUI", "Profile Optons", nullptr));
        pushButton_RunProfile->setText(QApplication::translate("ECMControllerGUI", "Run Profile", nullptr));
        label_CutDepth->setText(QApplication::translate("ECMControllerGUI", "Depth of Cut (um)", nullptr));
        label_CutSpeed->setText(QApplication::translate("ECMControllerGUI", "Cut Speed (um/s)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_linearParams), QApplication::translate("ECMControllerGUI", "Linear Parameters", nullptr));
        label_RetractDistance->setText(QApplication::translate("ECMControllerGUI", "Retract Distance (um)", nullptr));
        label_RetractPeriod->setText(QApplication::translate("ECMControllerGUI", "Retract Period (ms)", nullptr));
        label_Pause->setText(QApplication::translate("ECMControllerGUI", "Pause (ms)", nullptr));
        label_StepSize->setText(QApplication::translate("ECMControllerGUI", "Step Size (um)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_vibrationParams), QApplication::translate("ECMControllerGUI", "Vibration Parameters", nullptr));
        pushButton_UploadProgram->setText(QApplication::translate("ECMControllerGUI", "Upload Program", nullptr));
        pushButton_EstablishTouchoff->setText(QApplication::translate("ECMControllerGUI", "Establish Touchoff", nullptr));
        pushButton_DownloadProgram->setText(QApplication::translate("ECMControllerGUI", "Download Program", nullptr));
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
        pushButton_MotorDisable->setText(QApplication::translate("ECMControllerGUI", "DISABLE MOTOR", nullptr));
        pushButton->setText(QApplication::translate("ECMControllerGUI", "STOP", nullptr));
        label_ManualControl_5->setText(QApplication::translate("ECMControllerGUI", "DIO Signals", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ECMControllerGUI: public Ui_ECMControllerGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECM_CONTROLLER_GUI_H
