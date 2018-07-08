/********************************************************************************
** Form generated from reading UI file 'ECM_controller_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
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
#include "LED.h"
#include "plot_handler.h"

QT_BEGIN_NAMESPACE

class Ui_ECMControllerGUI
{
public:
    QAction *actionConnections;
    QAction *actionPower_Supply;
    QAction *actionPump;
    QAction *actionOscilliscope;
    QAction *actionTouchoff;
    QAction *actionOpen_Sensors_Window;
    QAction *actionClose;
    QWidget *centralWidget;
    QGridLayout *gridLayout_8;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QFrame *frame_MotorControl;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton;
    QFrame *frame_DIO;
    QGridLayout *gridLayout_9;
    QLabel *label_ManualControl_5;
    QGridLayout *gridLayout_7;
    LED *widget_LEDEStop_DIO;
    QLabel *label_2;
    LED *widget_LEDTouchoff_DIO;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    graphing::PlotHandler *widget_primaryPlot;
    QFrame *frame_ProfileOptions;
    QGridLayout *gridLayout_2;
    QSplitter *splitter_2;
    QLabel *label_ManualControl_2;
    QPushButton *pushButton_RunProfile;
    QTabWidget *tabWidget;
    QWidget *tab_linearParams;
    QGridLayout *gridLayout_5;
    QFormLayout *formLayout_2;
    QLabel *label_CutDepth;
    QLabel *label_CutSpeed;
    QDoubleSpinBox *doubleSpinBox_CutDepth;
    QDoubleSpinBox *doubleSpinBox_CutSpeed;
    QWidget *tab_vibrationParams;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label_RetractSpeed;
    QSpinBox *spinBox_RetractSpeed;
    QLabel *label_PlungeSpeed;
    QSpinBox *spinBox_PlungeSpeed;
    QLabel *label_RetractDistance;
    QDoubleSpinBox *doubleSpinBox_RetractDistance;
    QLabel *label_StepSize;
    QDoubleSpinBox *doubleSpinBox_StepSize;
    QLabel *label_RetractPeriod;
    QSpinBox *spinBox_RetractPeriod;
    QLabel *label_Pause;
    QSpinBox *spinBox_Pause;
    QComboBox *comboBox_ProgramProfiles;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_PartNumber;
    QLineEdit *lineEdit_PartNumber;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_PartNumber_2;
    QLineEdit *lineEdit_SerialNumber;
    QPushButton *pushButton_UploadProgram;
    QFormLayout *formLayout_3;
    QPushButton *pushButton_EstablishTouchoff;
    LED *widget_LEDTouchoffEstablished;
    QPushButton *pushButton_DownloadProgram;
    QFrame *frame_MaunalControl;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_4;
    QLabel *label_ManualControl;
    QPushButton *pushButton_ResetHome;
    LED *widget_LEDHomeIndicated;
    QLineEdit *lineEdit_GalilState;
    QPushButton *pushButton_MoveHome;
    QSpacerItem *horizontalSpacer_11;
    QFormLayout *formLayout_4;
    QLabel *label;
    QLineEdit *lineEdit_MachinePosition;
    QLabel *label_ManualControl_3;
    QLabel *label_ManualControl_4;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_IncreaseJog;
    QSpinBox *spinBox_Jog;
    QPushButton *pushButton_DecreaseJog;
    QPushButton *pushButton_MotorEnable;
    QSpacerItem *horizontalSpacer_6;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_IncreaseRelativeMove;
    QSpinBox *spinBox_RelativeMove;
    QPushButton *pushButton_DecreaseRelativeMove;
    QPushButton *pushButton_MotorDisable;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ECMControllerGUI)
    {
        if (ECMControllerGUI->objectName().isEmpty())
            ECMControllerGUI->setObjectName(QStringLiteral("ECMControllerGUI"));
        ECMControllerGUI->resize(1040, 746);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ECMControllerGUI->sizePolicy().hasHeightForWidth());
        ECMControllerGUI->setSizePolicy(sizePolicy);
        ECMControllerGUI->setMinimumSize(QSize(1040, 0));
        ECMControllerGUI->setMaximumSize(QSize(1040, 16777215));
        ECMControllerGUI->setStyleSheet(QLatin1String("QMenuBar{\n"
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
        actionConnections = new QAction(ECMControllerGUI);
        actionConnections->setObjectName(QStringLiteral("actionConnections"));
        actionConnections->setCheckable(true);
        actionPower_Supply = new QAction(ECMControllerGUI);
        actionPower_Supply->setObjectName(QStringLiteral("actionPower_Supply"));
        actionPower_Supply->setCheckable(true);
        actionPump = new QAction(ECMControllerGUI);
        actionPump->setObjectName(QStringLiteral("actionPump"));
        actionPump->setCheckable(true);
        actionOscilliscope = new QAction(ECMControllerGUI);
        actionOscilliscope->setObjectName(QStringLiteral("actionOscilliscope"));
        actionOscilliscope->setCheckable(true);
        actionTouchoff = new QAction(ECMControllerGUI);
        actionTouchoff->setObjectName(QStringLiteral("actionTouchoff"));
        actionTouchoff->setCheckable(true);
        actionOpen_Sensors_Window = new QAction(ECMControllerGUI);
        actionOpen_Sensors_Window->setObjectName(QStringLiteral("actionOpen_Sensors_Window"));
        actionClose = new QAction(ECMControllerGUI);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        centralWidget = new QWidget(ECMControllerGUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_8 = new QGridLayout(centralWidget);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(490, 25));
        lineEdit->setMaximumSize(QSize(490, 25));
        QFont font;
        font.setPointSize(10);
        lineEdit->setFont(font);
        lineEdit->setReadOnly(true);

        gridLayout_8->addWidget(lineEdit, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);
        lineEdit_2->setMinimumSize(QSize(522, 25));
        lineEdit_2->setMaximumSize(QSize(522, 25));
        lineEdit_2->setFont(font);
        lineEdit_2->setReadOnly(true);

        gridLayout_8->addWidget(lineEdit_2, 1, 1, 1, 2);

        frame_MotorControl = new QFrame(centralWidget);
        frame_MotorControl->setObjectName(QStringLiteral("frame_MotorControl"));
        sizePolicy1.setHeightForWidth(frame_MotorControl->sizePolicy().hasHeightForWidth());
        frame_MotorControl->setSizePolicy(sizePolicy1);
        frame_MotorControl->setMinimumSize(QSize(166, 74));
        frame_MotorControl->setMaximumSize(QSize(166, 74));
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
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);


        gridLayout_8->addWidget(frame_MotorControl, 2, 2, 1, 1);

        frame_DIO = new QFrame(centralWidget);
        frame_DIO->setObjectName(QStringLiteral("frame_DIO"));
        sizePolicy1.setHeightForWidth(frame_DIO->sizePolicy().hasHeightForWidth());
        frame_DIO->setSizePolicy(sizePolicy1);
        frame_DIO->setMinimumSize(QSize(166, 220));
        frame_DIO->setMaximumSize(QSize(166, 220));
        frame_DIO->setFrameShape(QFrame::Box);
        frame_DIO->setFrameShadow(QFrame::Plain);
        frame_DIO->setLineWidth(2);
        gridLayout_9 = new QGridLayout(frame_DIO);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_ManualControl_5 = new QLabel(frame_DIO);
        label_ManualControl_5->setObjectName(QStringLiteral("label_ManualControl_5"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_ManualControl_5->sizePolicy().hasHeightForWidth());
        label_ManualControl_5->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_ManualControl_5->setFont(font2);
        label_ManualControl_5->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_ManualControl_5, 0, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        widget_LEDEStop_DIO = new LED(frame_DIO);
        widget_LEDEStop_DIO->setObjectName(QStringLiteral("widget_LEDEStop_DIO"));
        sizePolicy1.setHeightForWidth(widget_LEDEStop_DIO->sizePolicy().hasHeightForWidth());
        widget_LEDEStop_DIO->setSizePolicy(sizePolicy1);
        widget_LEDEStop_DIO->setMinimumSize(QSize(32, 32));
        widget_LEDEStop_DIO->setMaximumSize(QSize(32, 32));

        gridLayout_7->addWidget(widget_LEDEStop_DIO, 0, 0, 1, 1);

        label_2 = new QLabel(frame_DIO);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(110, 32));
        label_2->setMaximumSize(QSize(110, 32));
        label_2->setFont(font);

        gridLayout_7->addWidget(label_2, 0, 1, 1, 1);

        widget_LEDTouchoff_DIO = new LED(frame_DIO);
        widget_LEDTouchoff_DIO->setObjectName(QStringLiteral("widget_LEDTouchoff_DIO"));
        sizePolicy1.setHeightForWidth(widget_LEDTouchoff_DIO->sizePolicy().hasHeightForWidth());
        widget_LEDTouchoff_DIO->setSizePolicy(sizePolicy1);
        widget_LEDTouchoff_DIO->setMinimumSize(QSize(32, 32));
        widget_LEDTouchoff_DIO->setMaximumSize(QSize(32, 32));

        gridLayout_7->addWidget(widget_LEDTouchoff_DIO, 1, 0, 1, 1);

        label_3 = new QLabel(frame_DIO);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(110, 32));
        label_3->setMaximumSize(QSize(110, 32));
        label_3->setFont(font);

        gridLayout_7->addWidget(label_3, 1, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_7, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 92, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer, 2, 0, 1, 1);


        gridLayout_8->addWidget(frame_DIO, 3, 2, 1, 1);

        widget_primaryPlot = new graphing::PlotHandler(centralWidget);
        widget_primaryPlot->setObjectName(QStringLiteral("widget_primaryPlot"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_primaryPlot->sizePolicy().hasHeightForWidth());
        widget_primaryPlot->setSizePolicy(sizePolicy3);
        widget_primaryPlot->setMinimumSize(QSize(1020, 300));
        widget_primaryPlot->setMaximumSize(QSize(1020, 16777215));

        gridLayout_8->addWidget(widget_primaryPlot, 0, 0, 1, 3);

        frame_ProfileOptions = new QFrame(centralWidget);
        frame_ProfileOptions->setObjectName(QStringLiteral("frame_ProfileOptions"));
        sizePolicy1.setHeightForWidth(frame_ProfileOptions->sizePolicy().hasHeightForWidth());
        frame_ProfileOptions->setSizePolicy(sizePolicy1);
        frame_ProfileOptions->setMinimumSize(QSize(490, 300));
        frame_ProfileOptions->setMaximumSize(QSize(490, 300));
        frame_ProfileOptions->setFrameShape(QFrame::Box);
        frame_ProfileOptions->setFrameShadow(QFrame::Plain);
        frame_ProfileOptions->setLineWidth(2);
        gridLayout_2 = new QGridLayout(frame_ProfileOptions);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        splitter_2 = new QSplitter(frame_ProfileOptions);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label_ManualControl_2 = new QLabel(splitter_2);
        label_ManualControl_2->setObjectName(QStringLiteral("label_ManualControl_2"));
        sizePolicy1.setHeightForWidth(label_ManualControl_2->sizePolicy().hasHeightForWidth());
        label_ManualControl_2->setSizePolicy(sizePolicy1);
        label_ManualControl_2->setMinimumSize(QSize(120, 20));
        label_ManualControl_2->setMaximumSize(QSize(120, 20));
        label_ManualControl_2->setFont(font2);
        label_ManualControl_2->setAlignment(Qt::AlignCenter);
        splitter_2->addWidget(label_ManualControl_2);

        gridLayout_2->addWidget(splitter_2, 0, 0, 1, 1);

        pushButton_RunProfile = new QPushButton(frame_ProfileOptions);
        pushButton_RunProfile->setObjectName(QStringLiteral("pushButton_RunProfile"));
        sizePolicy1.setHeightForWidth(pushButton_RunProfile->sizePolicy().hasHeightForWidth());
        pushButton_RunProfile->setSizePolicy(sizePolicy1);
        pushButton_RunProfile->setMinimumSize(QSize(180, 30));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        pushButton_RunProfile->setFont(font3);

        gridLayout_2->addWidget(pushButton_RunProfile, 0, 1, 2, 1);

        tabWidget = new QTabWidget(frame_ProfileOptions);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(280, 160));
        tabWidget->setMaximumSize(QSize(280, 350));
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
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_CutDepth->sizePolicy().hasHeightForWidth());
        label_CutDepth->setSizePolicy(sizePolicy4);
        label_CutDepth->setMinimumSize(QSize(145, 25));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        label_CutDepth->setFont(font4);
        label_CutDepth->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_CutDepth);

        label_CutSpeed = new QLabel(tab_linearParams);
        label_CutSpeed->setObjectName(QStringLiteral("label_CutSpeed"));
        sizePolicy4.setHeightForWidth(label_CutSpeed->sizePolicy().hasHeightForWidth());
        label_CutSpeed->setSizePolicy(sizePolicy4);
        label_CutSpeed->setMinimumSize(QSize(145, 25));
        label_CutSpeed->setFont(font4);
        label_CutSpeed->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_CutSpeed);

        doubleSpinBox_CutDepth = new QDoubleSpinBox(tab_linearParams);
        doubleSpinBox_CutDepth->setObjectName(QStringLiteral("doubleSpinBox_CutDepth"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_CutDepth->sizePolicy().hasHeightForWidth());
        doubleSpinBox_CutDepth->setSizePolicy(sizePolicy1);
        doubleSpinBox_CutDepth->setMinimumSize(QSize(100, 25));
        doubleSpinBox_CutDepth->setFont(font);
        doubleSpinBox_CutDepth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_CutDepth->setValue(40);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_CutDepth);

        doubleSpinBox_CutSpeed = new QDoubleSpinBox(tab_linearParams);
        doubleSpinBox_CutSpeed->setObjectName(QStringLiteral("doubleSpinBox_CutSpeed"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_CutSpeed->sizePolicy().hasHeightForWidth());
        doubleSpinBox_CutSpeed->setSizePolicy(sizePolicy1);
        doubleSpinBox_CutSpeed->setMinimumSize(QSize(100, 25));
        doubleSpinBox_CutSpeed->setFont(font);
        doubleSpinBox_CutSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_CutSpeed->setMinimum(0.01);
        doubleSpinBox_CutSpeed->setValue(0.4);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, doubleSpinBox_CutSpeed);


        gridLayout_5->addLayout(formLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_linearParams, QString());
        tab_vibrationParams = new QWidget();
        tab_vibrationParams->setObjectName(QStringLiteral("tab_vibrationParams"));
        layoutWidget = new QWidget(tab_vibrationParams);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 254, 187));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_RetractSpeed = new QLabel(layoutWidget);
        label_RetractSpeed->setObjectName(QStringLiteral("label_RetractSpeed"));
        sizePolicy4.setHeightForWidth(label_RetractSpeed->sizePolicy().hasHeightForWidth());
        label_RetractSpeed->setSizePolicy(sizePolicy4);
        label_RetractSpeed->setMinimumSize(QSize(145, 25));
        label_RetractSpeed->setFont(font4);
        label_RetractSpeed->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_RetractSpeed);

        spinBox_RetractSpeed = new QSpinBox(layoutWidget);
        spinBox_RetractSpeed->setObjectName(QStringLiteral("spinBox_RetractSpeed"));
        sizePolicy1.setHeightForWidth(spinBox_RetractSpeed->sizePolicy().hasHeightForWidth());
        spinBox_RetractSpeed->setSizePolicy(sizePolicy1);
        spinBox_RetractSpeed->setMinimumSize(QSize(100, 25));
        spinBox_RetractSpeed->setFont(font);
        spinBox_RetractSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_RetractSpeed->setMinimum(0);
        spinBox_RetractSpeed->setMaximum(10000);
        spinBox_RetractSpeed->setSingleStep(10);
        spinBox_RetractSpeed->setValue(0);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox_RetractSpeed);

        label_PlungeSpeed = new QLabel(layoutWidget);
        label_PlungeSpeed->setObjectName(QStringLiteral("label_PlungeSpeed"));
        sizePolicy4.setHeightForWidth(label_PlungeSpeed->sizePolicy().hasHeightForWidth());
        label_PlungeSpeed->setSizePolicy(sizePolicy4);
        label_PlungeSpeed->setMinimumSize(QSize(145, 25));
        label_PlungeSpeed->setFont(font4);
        label_PlungeSpeed->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_PlungeSpeed);

        spinBox_PlungeSpeed = new QSpinBox(layoutWidget);
        spinBox_PlungeSpeed->setObjectName(QStringLiteral("spinBox_PlungeSpeed"));
        sizePolicy1.setHeightForWidth(spinBox_PlungeSpeed->sizePolicy().hasHeightForWidth());
        spinBox_PlungeSpeed->setSizePolicy(sizePolicy1);
        spinBox_PlungeSpeed->setMinimumSize(QSize(100, 25));
        spinBox_PlungeSpeed->setFont(font);
        spinBox_PlungeSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_PlungeSpeed->setMinimum(0);
        spinBox_PlungeSpeed->setMaximum(10000);
        spinBox_PlungeSpeed->setSingleStep(10);
        spinBox_PlungeSpeed->setValue(0);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox_PlungeSpeed);

        label_RetractDistance = new QLabel(layoutWidget);
        label_RetractDistance->setObjectName(QStringLiteral("label_RetractDistance"));
        sizePolicy4.setHeightForWidth(label_RetractDistance->sizePolicy().hasHeightForWidth());
        label_RetractDistance->setSizePolicy(sizePolicy4);
        label_RetractDistance->setMinimumSize(QSize(145, 25));
        label_RetractDistance->setFont(font4);
        label_RetractDistance->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_RetractDistance);

        doubleSpinBox_RetractDistance = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_RetractDistance->setObjectName(QStringLiteral("doubleSpinBox_RetractDistance"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_RetractDistance->sizePolicy().hasHeightForWidth());
        doubleSpinBox_RetractDistance->setSizePolicy(sizePolicy1);
        doubleSpinBox_RetractDistance->setMinimumSize(QSize(100, 25));
        doubleSpinBox_RetractDistance->setFont(font);
        doubleSpinBox_RetractDistance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_RetractDistance->setMaximum(1000);
        doubleSpinBox_RetractDistance->setValue(100);

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox_RetractDistance);

        label_StepSize = new QLabel(layoutWidget);
        label_StepSize->setObjectName(QStringLiteral("label_StepSize"));
        sizePolicy4.setHeightForWidth(label_StepSize->sizePolicy().hasHeightForWidth());
        label_StepSize->setSizePolicy(sizePolicy4);
        label_StepSize->setMinimumSize(QSize(145, 25));
        label_StepSize->setFont(font4);
        label_StepSize->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_StepSize);

        doubleSpinBox_StepSize = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_StepSize->setObjectName(QStringLiteral("doubleSpinBox_StepSize"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_StepSize->sizePolicy().hasHeightForWidth());
        doubleSpinBox_StepSize->setSizePolicy(sizePolicy1);
        doubleSpinBox_StepSize->setMinimumSize(QSize(100, 25));
        doubleSpinBox_StepSize->setFont(font);
        doubleSpinBox_StepSize->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_StepSize->setValue(0.02);

        formLayout->setWidget(3, QFormLayout::FieldRole, doubleSpinBox_StepSize);

        label_RetractPeriod = new QLabel(layoutWidget);
        label_RetractPeriod->setObjectName(QStringLiteral("label_RetractPeriod"));
        sizePolicy4.setHeightForWidth(label_RetractPeriod->sizePolicy().hasHeightForWidth());
        label_RetractPeriod->setSizePolicy(sizePolicy4);
        label_RetractPeriod->setMinimumSize(QSize(145, 25));
        label_RetractPeriod->setFont(font4);
        label_RetractPeriod->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_RetractPeriod);

        spinBox_RetractPeriod = new QSpinBox(layoutWidget);
        spinBox_RetractPeriod->setObjectName(QStringLiteral("spinBox_RetractPeriod"));
        sizePolicy1.setHeightForWidth(spinBox_RetractPeriod->sizePolicy().hasHeightForWidth());
        spinBox_RetractPeriod->setSizePolicy(sizePolicy1);
        spinBox_RetractPeriod->setMinimumSize(QSize(100, 25));
        spinBox_RetractPeriod->setFont(font);
        spinBox_RetractPeriod->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_RetractPeriod->setMinimum(0);
        spinBox_RetractPeriod->setMaximum(10000);
        spinBox_RetractPeriod->setSingleStep(1);
        spinBox_RetractPeriod->setValue(10);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBox_RetractPeriod);

        label_Pause = new QLabel(layoutWidget);
        label_Pause->setObjectName(QStringLiteral("label_Pause"));
        sizePolicy4.setHeightForWidth(label_Pause->sizePolicy().hasHeightForWidth());
        label_Pause->setSizePolicy(sizePolicy4);
        label_Pause->setMinimumSize(QSize(145, 25));
        label_Pause->setFont(font4);
        label_Pause->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_Pause);

        spinBox_Pause = new QSpinBox(layoutWidget);
        spinBox_Pause->setObjectName(QStringLiteral("spinBox_Pause"));
        sizePolicy1.setHeightForWidth(spinBox_Pause->sizePolicy().hasHeightForWidth());
        spinBox_Pause->setSizePolicy(sizePolicy1);
        spinBox_Pause->setMinimumSize(QSize(100, 25));
        spinBox_Pause->setFont(font);
        spinBox_Pause->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_Pause->setMinimum(0);
        spinBox_Pause->setMaximum(10000);
        spinBox_Pause->setSingleStep(1);
        spinBox_Pause->setValue(8);

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBox_Pause);

        tabWidget->addTab(tab_vibrationParams, QString());

        gridLayout_2->addWidget(tabWidget, 1, 0, 5, 1);

        comboBox_ProgramProfiles = new QComboBox(frame_ProfileOptions);
        comboBox_ProgramProfiles->setObjectName(QStringLiteral("comboBox_ProgramProfiles"));
        sizePolicy1.setHeightForWidth(comboBox_ProgramProfiles->sizePolicy().hasHeightForWidth());
        comboBox_ProgramProfiles->setSizePolicy(sizePolicy1);
        comboBox_ProgramProfiles->setMinimumSize(QSize(180, 30));

        gridLayout_2->addWidget(comboBox_ProgramProfiles, 2, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_PartNumber = new QLabel(frame_ProfileOptions);
        label_PartNumber->setObjectName(QStringLiteral("label_PartNumber"));
        sizePolicy1.setHeightForWidth(label_PartNumber->sizePolicy().hasHeightForWidth());
        label_PartNumber->setSizePolicy(sizePolicy1);
        label_PartNumber->setMinimumSize(QSize(180, 25));
        label_PartNumber->setMaximumSize(QSize(180, 25));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(false);
        font5.setItalic(true);
        font5.setWeight(50);
        label_PartNumber->setFont(font5);
        label_PartNumber->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_PartNumber);

        lineEdit_PartNumber = new QLineEdit(frame_ProfileOptions);
        lineEdit_PartNumber->setObjectName(QStringLiteral("lineEdit_PartNumber"));
        sizePolicy1.setHeightForWidth(lineEdit_PartNumber->sizePolicy().hasHeightForWidth());
        lineEdit_PartNumber->setSizePolicy(sizePolicy1);
        lineEdit_PartNumber->setMinimumSize(QSize(180, 30));
        lineEdit_PartNumber->setMaximumSize(QSize(180, 30));
        lineEdit_PartNumber->setFont(font);
        lineEdit_PartNumber->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lineEdit_PartNumber);


        gridLayout_2->addLayout(verticalLayout_4, 3, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_PartNumber_2 = new QLabel(frame_ProfileOptions);
        label_PartNumber_2->setObjectName(QStringLiteral("label_PartNumber_2"));
        sizePolicy1.setHeightForWidth(label_PartNumber_2->sizePolicy().hasHeightForWidth());
        label_PartNumber_2->setSizePolicy(sizePolicy1);
        label_PartNumber_2->setMinimumSize(QSize(180, 25));
        label_PartNumber_2->setMaximumSize(QSize(180, 25));
        label_PartNumber_2->setFont(font5);
        label_PartNumber_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_PartNumber_2);

        lineEdit_SerialNumber = new QLineEdit(frame_ProfileOptions);
        lineEdit_SerialNumber->setObjectName(QStringLiteral("lineEdit_SerialNumber"));
        sizePolicy1.setHeightForWidth(lineEdit_SerialNumber->sizePolicy().hasHeightForWidth());
        lineEdit_SerialNumber->setSizePolicy(sizePolicy1);
        lineEdit_SerialNumber->setMinimumSize(QSize(180, 30));
        lineEdit_SerialNumber->setMaximumSize(QSize(180, 30));
        lineEdit_SerialNumber->setFont(font);
        lineEdit_SerialNumber->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lineEdit_SerialNumber);


        gridLayout_2->addLayout(verticalLayout_3, 4, 1, 1, 1);

        pushButton_UploadProgram = new QPushButton(frame_ProfileOptions);
        pushButton_UploadProgram->setObjectName(QStringLiteral("pushButton_UploadProgram"));
        sizePolicy1.setHeightForWidth(pushButton_UploadProgram->sizePolicy().hasHeightForWidth());
        pushButton_UploadProgram->setSizePolicy(sizePolicy1);
        pushButton_UploadProgram->setMinimumSize(QSize(180, 30));
        QFont font6;
        font6.setPointSize(12);
        pushButton_UploadProgram->setFont(font6);

        gridLayout_2->addWidget(pushButton_UploadProgram, 5, 1, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        pushButton_EstablishTouchoff = new QPushButton(frame_ProfileOptions);
        pushButton_EstablishTouchoff->setObjectName(QStringLiteral("pushButton_EstablishTouchoff"));
        sizePolicy1.setHeightForWidth(pushButton_EstablishTouchoff->sizePolicy().hasHeightForWidth());
        pushButton_EstablishTouchoff->setSizePolicy(sizePolicy1);
        pushButton_EstablishTouchoff->setMinimumSize(QSize(180, 32));
        pushButton_EstablishTouchoff->setMaximumSize(QSize(16777215, 32));
        pushButton_EstablishTouchoff->setFont(font6);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, pushButton_EstablishTouchoff);

        widget_LEDTouchoffEstablished = new LED(frame_ProfileOptions);
        widget_LEDTouchoffEstablished->setObjectName(QStringLiteral("widget_LEDTouchoffEstablished"));
        widget_LEDTouchoffEstablished->setMinimumSize(QSize(32, 32));
        widget_LEDTouchoffEstablished->setMaximumSize(QSize(32, 32));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, widget_LEDTouchoffEstablished);


        gridLayout_2->addLayout(formLayout_3, 6, 0, 1, 1);

        pushButton_DownloadProgram = new QPushButton(frame_ProfileOptions);
        pushButton_DownloadProgram->setObjectName(QStringLiteral("pushButton_DownloadProgram"));
        sizePolicy1.setHeightForWidth(pushButton_DownloadProgram->sizePolicy().hasHeightForWidth());
        pushButton_DownloadProgram->setSizePolicy(sizePolicy1);
        pushButton_DownloadProgram->setMinimumSize(QSize(180, 30));
        pushButton_DownloadProgram->setFont(font6);

        gridLayout_2->addWidget(pushButton_DownloadProgram, 6, 1, 1, 1);


        gridLayout_8->addWidget(frame_ProfileOptions, 2, 0, 2, 1);

        frame_MaunalControl = new QFrame(centralWidget);
        frame_MaunalControl->setObjectName(QStringLiteral("frame_MaunalControl"));
        sizePolicy1.setHeightForWidth(frame_MaunalControl->sizePolicy().hasHeightForWidth());
        frame_MaunalControl->setSizePolicy(sizePolicy1);
        frame_MaunalControl->setMinimumSize(QSize(350, 300));
        frame_MaunalControl->setMaximumSize(QSize(350, 300));
        frame_MaunalControl->setFrameShape(QFrame::Box);
        frame_MaunalControl->setFrameShadow(QFrame::Plain);
        frame_MaunalControl->setLineWidth(2);
        gridLayout_10 = new QGridLayout(frame_MaunalControl);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_ManualControl = new QLabel(frame_MaunalControl);
        label_ManualControl->setObjectName(QStringLiteral("label_ManualControl"));
        sizePolicy4.setHeightForWidth(label_ManualControl->sizePolicy().hasHeightForWidth());
        label_ManualControl->setSizePolicy(sizePolicy4);
        label_ManualControl->setMinimumSize(QSize(0, 32));
        label_ManualControl->setMaximumSize(QSize(16777215, 32));
        label_ManualControl->setFont(font2);
        label_ManualControl->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_ManualControl, 0, 0, 1, 1);

        pushButton_ResetHome = new QPushButton(frame_MaunalControl);
        pushButton_ResetHome->setObjectName(QStringLiteral("pushButton_ResetHome"));
        sizePolicy1.setHeightForWidth(pushButton_ResetHome->sizePolicy().hasHeightForWidth());
        pushButton_ResetHome->setSizePolicy(sizePolicy1);
        pushButton_ResetHome->setMinimumSize(QSize(112, 32));
        pushButton_ResetHome->setMaximumSize(QSize(16777215, 32));
        pushButton_ResetHome->setFont(font6);

        gridLayout_4->addWidget(pushButton_ResetHome, 0, 1, 1, 1);

        widget_LEDHomeIndicated = new LED(frame_MaunalControl);
        widget_LEDHomeIndicated->setObjectName(QStringLiteral("widget_LEDHomeIndicated"));
        widget_LEDHomeIndicated->setMinimumSize(QSize(32, 32));
        widget_LEDHomeIndicated->setMaximumSize(QSize(32, 32));

        gridLayout_4->addWidget(widget_LEDHomeIndicated, 0, 2, 1, 1);

        lineEdit_GalilState = new QLineEdit(frame_MaunalControl);
        lineEdit_GalilState->setObjectName(QStringLiteral("lineEdit_GalilState"));
        sizePolicy1.setHeightForWidth(lineEdit_GalilState->sizePolicy().hasHeightForWidth());
        lineEdit_GalilState->setSizePolicy(sizePolicy1);
        lineEdit_GalilState->setMinimumSize(QSize(160, 32));
        lineEdit_GalilState->setMaximumSize(QSize(160, 32));
        lineEdit_GalilState->setFont(font);
        lineEdit_GalilState->setAlignment(Qt::AlignCenter);
        lineEdit_GalilState->setReadOnly(true);

        gridLayout_4->addWidget(lineEdit_GalilState, 1, 0, 1, 1);

        pushButton_MoveHome = new QPushButton(frame_MaunalControl);
        pushButton_MoveHome->setObjectName(QStringLiteral("pushButton_MoveHome"));
        sizePolicy1.setHeightForWidth(pushButton_MoveHome->sizePolicy().hasHeightForWidth());
        pushButton_MoveHome->setSizePolicy(sizePolicy1);
        pushButton_MoveHome->setMinimumSize(QSize(112, 32));
        pushButton_MoveHome->setMaximumSize(QSize(16777215, 32));
        pushButton_MoveHome->setFont(font6);

        gridLayout_4->addWidget(pushButton_MoveHome, 1, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(13, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_11, 1, 2, 1, 1);


        gridLayout_10->addLayout(gridLayout_4, 0, 0, 1, 2);

        formLayout_4 = new QFormLayout();
        formLayout_4->setSpacing(6);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        label = new QLabel(frame_MaunalControl);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(130, 25));
        label->setMaximumSize(QSize(130, 25));
        label->setFont(font);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_MachinePosition = new QLineEdit(frame_MaunalControl);
        lineEdit_MachinePosition->setObjectName(QStringLiteral("lineEdit_MachinePosition"));
        lineEdit_MachinePosition->setMinimumSize(QSize(190, 25));
        lineEdit_MachinePosition->setMaximumSize(QSize(190, 25));
        lineEdit_MachinePosition->setFont(font);
        lineEdit_MachinePosition->setAlignment(Qt::AlignCenter);
        lineEdit_MachinePosition->setReadOnly(true);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lineEdit_MachinePosition);


        gridLayout_10->addLayout(formLayout_4, 1, 0, 1, 2);

        label_ManualControl_3 = new QLabel(frame_MaunalControl);
        label_ManualControl_3->setObjectName(QStringLiteral("label_ManualControl_3"));
        sizePolicy4.setHeightForWidth(label_ManualControl_3->sizePolicy().hasHeightForWidth());
        label_ManualControl_3->setSizePolicy(sizePolicy4);
        label_ManualControl_3->setFont(font2);
        label_ManualControl_3->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_ManualControl_3, 2, 0, 1, 1);

        label_ManualControl_4 = new QLabel(frame_MaunalControl);
        label_ManualControl_4->setObjectName(QStringLiteral("label_ManualControl_4"));
        sizePolicy4.setHeightForWidth(label_ManualControl_4->sizePolicy().hasHeightForWidth());
        label_ManualControl_4->setSizePolicy(sizePolicy4);
        label_ManualControl_4->setFont(font2);
        label_ManualControl_4->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_ManualControl_4, 2, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_7 = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_IncreaseJog = new QPushButton(frame_MaunalControl);
        pushButton_IncreaseJog->setObjectName(QStringLiteral("pushButton_IncreaseJog"));
        sizePolicy1.setHeightForWidth(pushButton_IncreaseJog->sizePolicy().hasHeightForWidth());
        pushButton_IncreaseJog->setSizePolicy(sizePolicy1);
        pushButton_IncreaseJog->setMinimumSize(QSize(130, 30));
        pushButton_IncreaseJog->setMaximumSize(QSize(130, 16777215));
        pushButton_IncreaseJog->setFont(font6);

        verticalLayout->addWidget(pushButton_IncreaseJog);

        spinBox_Jog = new QSpinBox(frame_MaunalControl);
        spinBox_Jog->setObjectName(QStringLiteral("spinBox_Jog"));
        sizePolicy1.setHeightForWidth(spinBox_Jog->sizePolicy().hasHeightForWidth());
        spinBox_Jog->setSizePolicy(sizePolicy1);
        spinBox_Jog->setMinimumSize(QSize(130, 30));
        spinBox_Jog->setFont(font6);
        spinBox_Jog->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_Jog->setMinimum(1);
        spinBox_Jog->setMaximum(10000);
        spinBox_Jog->setSingleStep(10);
        spinBox_Jog->setValue(100);

        verticalLayout->addWidget(spinBox_Jog);

        pushButton_DecreaseJog = new QPushButton(frame_MaunalControl);
        pushButton_DecreaseJog->setObjectName(QStringLiteral("pushButton_DecreaseJog"));
        sizePolicy1.setHeightForWidth(pushButton_DecreaseJog->sizePolicy().hasHeightForWidth());
        pushButton_DecreaseJog->setSizePolicy(sizePolicy1);
        pushButton_DecreaseJog->setMinimumSize(QSize(130, 30));
        pushButton_DecreaseJog->setMaximumSize(QSize(130, 16777215));
        pushButton_DecreaseJog->setFont(font6);

        verticalLayout->addWidget(pushButton_DecreaseJog);

        pushButton_MotorEnable = new QPushButton(frame_MaunalControl);
        pushButton_MotorEnable->setObjectName(QStringLiteral("pushButton_MotorEnable"));
        sizePolicy1.setHeightForWidth(pushButton_MotorEnable->sizePolicy().hasHeightForWidth());
        pushButton_MotorEnable->setSizePolicy(sizePolicy1);
        pushButton_MotorEnable->setMinimumSize(QSize(130, 30));
        pushButton_MotorEnable->setFont(font6);

        verticalLayout->addWidget(pushButton_MotorEnable);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 2, 1, 1);


        gridLayout_10->addLayout(gridLayout, 3, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        horizontalSpacer_9 = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_9, 0, 0, 2, 2);

        horizontalSpacer_8 = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_8, 0, 2, 2, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton_IncreaseRelativeMove = new QPushButton(frame_MaunalControl);
        pushButton_IncreaseRelativeMove->setObjectName(QStringLiteral("pushButton_IncreaseRelativeMove"));
        sizePolicy1.setHeightForWidth(pushButton_IncreaseRelativeMove->sizePolicy().hasHeightForWidth());
        pushButton_IncreaseRelativeMove->setSizePolicy(sizePolicy1);
        pushButton_IncreaseRelativeMove->setMinimumSize(QSize(130, 30));
        pushButton_IncreaseRelativeMove->setMaximumSize(QSize(130, 16777215));
        pushButton_IncreaseRelativeMove->setFont(font6);

        verticalLayout_2->addWidget(pushButton_IncreaseRelativeMove);

        spinBox_RelativeMove = new QSpinBox(frame_MaunalControl);
        spinBox_RelativeMove->setObjectName(QStringLiteral("spinBox_RelativeMove"));
        sizePolicy1.setHeightForWidth(spinBox_RelativeMove->sizePolicy().hasHeightForWidth());
        spinBox_RelativeMove->setSizePolicy(sizePolicy1);
        spinBox_RelativeMove->setMinimumSize(QSize(130, 30));
        spinBox_RelativeMove->setMaximumSize(QSize(130, 16777215));
        spinBox_RelativeMove->setFont(font6);
        spinBox_RelativeMove->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_RelativeMove->setMaximum(100000);
        spinBox_RelativeMove->setSingleStep(100);
        spinBox_RelativeMove->setValue(10000);

        verticalLayout_2->addWidget(spinBox_RelativeMove);

        pushButton_DecreaseRelativeMove = new QPushButton(frame_MaunalControl);
        pushButton_DecreaseRelativeMove->setObjectName(QStringLiteral("pushButton_DecreaseRelativeMove"));
        sizePolicy1.setHeightForWidth(pushButton_DecreaseRelativeMove->sizePolicy().hasHeightForWidth());
        pushButton_DecreaseRelativeMove->setSizePolicy(sizePolicy1);
        pushButton_DecreaseRelativeMove->setMinimumSize(QSize(130, 30));
        pushButton_DecreaseRelativeMove->setMaximumSize(QSize(130, 16777215));
        pushButton_DecreaseRelativeMove->setFont(font6);

        verticalLayout_2->addWidget(pushButton_DecreaseRelativeMove);

        pushButton_MotorDisable = new QPushButton(frame_MaunalControl);
        pushButton_MotorDisable->setObjectName(QStringLiteral("pushButton_MotorDisable"));
        sizePolicy1.setHeightForWidth(pushButton_MotorDisable->sizePolicy().hasHeightForWidth());
        pushButton_MotorDisable->setSizePolicy(sizePolicy1);
        pushButton_MotorDisable->setMinimumSize(QSize(130, 30));
        pushButton_MotorDisable->setFont(font6);

        verticalLayout_2->addWidget(pushButton_MotorDisable);


        gridLayout_6->addLayout(verticalLayout_2, 1, 1, 1, 1);


        gridLayout_10->addLayout(gridLayout_6, 3, 1, 1, 1);


        gridLayout_8->addWidget(frame_MaunalControl, 2, 1, 2, 1);

        ECMControllerGUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ECMControllerGUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1040, 40));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        ECMControllerGUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ECMControllerGUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ECMControllerGUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ECMControllerGUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ECMControllerGUI->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionClose);
        menuTools->addAction(actionConnections);
        menuTools->addSeparator();
        menuTools->addAction(actionPower_Supply);
        menuTools->addAction(actionPump);
        menuTools->addAction(actionOscilliscope);
        menuTools->addSeparator();
        menuTools->addAction(actionTouchoff);
        menuView->addAction(actionOpen_Sensors_Window);
        menuView->addSeparator();

        retranslateUi(ECMControllerGUI);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ECMControllerGUI);
    } // setupUi

    void retranslateUi(QMainWindow *ECMControllerGUI)
    {
        ECMControllerGUI->setWindowTitle(QApplication::translate("ECMControllerGUI", "ECMControllerGUI", nullptr));
        actionConnections->setText(QApplication::translate("ECMControllerGUI", "Connections", nullptr));
        actionPower_Supply->setText(QApplication::translate("ECMControllerGUI", "Power Supply", nullptr));
        actionPump->setText(QApplication::translate("ECMControllerGUI", "Pump", nullptr));
        actionOscilliscope->setText(QApplication::translate("ECMControllerGUI", "Oscilliscope", nullptr));
        actionTouchoff->setText(QApplication::translate("ECMControllerGUI", "Touchoff", nullptr));
        actionOpen_Sensors_Window->setText(QApplication::translate("ECMControllerGUI", "Open Sensors Window", nullptr));
        actionClose->setText(QApplication::translate("ECMControllerGUI", "Close", nullptr));
        pushButton->setText(QApplication::translate("ECMControllerGUI", "STOP", nullptr));
        label_ManualControl_5->setText(QApplication::translate("ECMControllerGUI", "DIO Signals", nullptr));
        label_2->setText(QApplication::translate("ECMControllerGUI", "ESTOP", nullptr));
        label_3->setText(QApplication::translate("ECMControllerGUI", "TOUCHOFF", nullptr));
        label_ManualControl_2->setText(QApplication::translate("ECMControllerGUI", "Profile Optons", nullptr));
        pushButton_RunProfile->setText(QApplication::translate("ECMControllerGUI", "Run Profile", nullptr));
        label_CutDepth->setText(QApplication::translate("ECMControllerGUI", "Depth of Cut (um)", nullptr));
        label_CutSpeed->setText(QApplication::translate("ECMControllerGUI", "Cut Speed (um/s)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_linearParams), QApplication::translate("ECMControllerGUI", "Linear Parameters", nullptr));
        label_RetractSpeed->setText(QApplication::translate("ECMControllerGUI", "Retract Speed (um/s)", nullptr));
        label_PlungeSpeed->setText(QApplication::translate("ECMControllerGUI", "Plunge Speed (um/s)", nullptr));
        label_RetractDistance->setText(QApplication::translate("ECMControllerGUI", "Retract Distance (um)", nullptr));
        label_StepSize->setText(QApplication::translate("ECMControllerGUI", "Step Size (um)", nullptr));
        label_RetractPeriod->setText(QApplication::translate("ECMControllerGUI", "Retract Period (ms)", nullptr));
        label_Pause->setText(QApplication::translate("ECMControllerGUI", "Pause (ms)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_vibrationParams), QApplication::translate("ECMControllerGUI", "Vibration Parameters", nullptr));
        label_PartNumber->setText(QApplication::translate("ECMControllerGUI", "Part Number:", nullptr));
        lineEdit_PartNumber->setText(QApplication::translate("ECMControllerGUI", "DEFAULT PART #", nullptr));
        label_PartNumber_2->setText(QApplication::translate("ECMControllerGUI", "Serial Number:", nullptr));
        lineEdit_SerialNumber->setText(QApplication::translate("ECMControllerGUI", "DEFAULT SERIAL #", nullptr));
        pushButton_UploadProgram->setText(QApplication::translate("ECMControllerGUI", "Upload Program", nullptr));
        pushButton_EstablishTouchoff->setText(QApplication::translate("ECMControllerGUI", "Establish Touchoff", nullptr));
        pushButton_DownloadProgram->setText(QApplication::translate("ECMControllerGUI", "Download Program", nullptr));
        label_ManualControl->setText(QApplication::translate("ECMControllerGUI", "Manual Control", nullptr));
        pushButton_ResetHome->setText(QApplication::translate("ECMControllerGUI", "Reset Home", nullptr));
        pushButton_MoveHome->setText(QApplication::translate("ECMControllerGUI", "Move To Home", nullptr));
        label->setText(QApplication::translate("ECMControllerGUI", "Current Position (um):", nullptr));
        label_ManualControl_3->setText(QApplication::translate("ECMControllerGUI", "Jog Control (um/sec)", nullptr));
        label_ManualControl_4->setText(QApplication::translate("ECMControllerGUI", "Step Control (um)", nullptr));
        pushButton_IncreaseJog->setText(QApplication::translate("ECMControllerGUI", "INCREASE", nullptr));
        pushButton_DecreaseJog->setText(QApplication::translate("ECMControllerGUI", "DECREASE", nullptr));
        pushButton_MotorEnable->setText(QApplication::translate("ECMControllerGUI", "ENABLE MOTOR", nullptr));
        pushButton_IncreaseRelativeMove->setText(QApplication::translate("ECMControllerGUI", "INCREASE", nullptr));
        pushButton_DecreaseRelativeMove->setText(QApplication::translate("ECMControllerGUI", "DECREASE", nullptr));
        pushButton_MotorDisable->setText(QApplication::translate("ECMControllerGUI", "DISABLE MOTOR", nullptr));
        menuFile->setTitle(QApplication::translate("ECMControllerGUI", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("ECMControllerGUI", "Edit", nullptr));
        menuTools->setTitle(QApplication::translate("ECMControllerGUI", "Tools", nullptr));
        menuHelp->setTitle(QApplication::translate("ECMControllerGUI", "Help", nullptr));
        menuView->setTitle(QApplication::translate("ECMControllerGUI", "Plot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ECMControllerGUI: public Ui_ECMControllerGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECM_CONTROLLER_GUI_H
