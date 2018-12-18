/********************************************************************************
** Form generated from reading UI file 'widget_scripting_variables.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_SCRIPTING_VARIABLES_H
#define UI_WIDGET_SCRIPTING_VARIABLES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_ScriptingVariables
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QGridLayout *gridLayout_6;
    QLabel *label_ManualControl_2;
    QSpacerItem *horizontalSpacer_8;
    QComboBox *comboBox_ProgramLabels;
    QTabWidget *tabWidget;
    QWidget *tab_linearParams;
    QGridLayout *gridLayout_4;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_7;
    QFormLayout *formLayout_2;
    QLabel *label_CutDepth;
    QLabel *label_CutSpeed;
    QDoubleSpinBox *doubleSpinBox_CutDepth;
    QDoubleSpinBox *doubleSpinBox_CutSpeed;
    QWidget *tab_vibrationParams;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_5;
    QFormLayout *formLayout;
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
    QLabel *label_RetractSpeed;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_18;
    QFormLayout *formLayout_3;

    void setupUi(QWidget *Widget_ScriptingVariables)
    {
        if (Widget_ScriptingVariables->objectName().isEmpty())
            Widget_ScriptingVariables->setObjectName(QStringLiteral("Widget_ScriptingVariables"));
        Widget_ScriptingVariables->resize(560, 300);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_ScriptingVariables->sizePolicy().hasHeightForWidth());
        Widget_ScriptingVariables->setSizePolicy(sizePolicy);
        Widget_ScriptingVariables->setMinimumSize(QSize(560, 300));
        Widget_ScriptingVariables->setMaximumSize(QSize(560, 300));
        Widget_ScriptingVariables->setStyleSheet(QLatin1String("QMenuBar{\n"
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
        gridLayout = new QGridLayout(Widget_ScriptingVariables);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_ManualControl_2 = new QLabel(Widget_ScriptingVariables);
        label_ManualControl_2->setObjectName(QStringLiteral("label_ManualControl_2"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_ManualControl_2->sizePolicy().hasHeightForWidth());
        label_ManualControl_2->setSizePolicy(sizePolicy1);
        label_ManualControl_2->setMinimumSize(QSize(0, 32));
        label_ManualControl_2->setMaximumSize(QSize(16777215, 32));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_ManualControl_2->setFont(font);
        label_ManualControl_2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_ManualControl_2, 0, 0, 1, 1);


        horizontalLayout_7->addLayout(gridLayout_6);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        gridLayout->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        comboBox_ProgramLabels = new QComboBox(Widget_ScriptingVariables);
        comboBox_ProgramLabels->setObjectName(QStringLiteral("comboBox_ProgramLabels"));
        sizePolicy.setHeightForWidth(comboBox_ProgramLabels->sizePolicy().hasHeightForWidth());
        comboBox_ProgramLabels->setSizePolicy(sizePolicy);
        comboBox_ProgramLabels->setMinimumSize(QSize(210, 20));
        comboBox_ProgramLabels->setMaximumSize(QSize(210, 20));
        QFont font1;
        font1.setPointSize(10);
        comboBox_ProgramLabels->setFont(font1);

        gridLayout->addWidget(comboBox_ProgramLabels, 0, 1, 1, 1);

        tabWidget = new QTabWidget(Widget_ScriptingVariables);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setMinimumSize(QSize(550, 240));
        tabWidget->setMaximumSize(QSize(550, 350));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab_linearParams = new QWidget();
        tab_linearParams->setObjectName(QStringLiteral("tab_linearParams"));
        gridLayout_4 = new QGridLayout(tab_linearParams);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        scrollArea_2 = new QScrollArea(tab_linearParams);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setMinimumSize(QSize(0, 210));
        scrollArea_2->setWidgetResizable(true);
        scrollArea_2->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 524, 208));
        gridLayout_7 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_CutDepth = new QLabel(scrollAreaWidgetContents_2);
        label_CutDepth->setObjectName(QStringLiteral("label_CutDepth"));
        sizePolicy1.setHeightForWidth(label_CutDepth->sizePolicy().hasHeightForWidth());
        label_CutDepth->setSizePolicy(sizePolicy1);
        label_CutDepth->setMinimumSize(QSize(145, 25));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label_CutDepth->setFont(font2);
        label_CutDepth->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_CutDepth);

        label_CutSpeed = new QLabel(scrollAreaWidgetContents_2);
        label_CutSpeed->setObjectName(QStringLiteral("label_CutSpeed"));
        sizePolicy1.setHeightForWidth(label_CutSpeed->sizePolicy().hasHeightForWidth());
        label_CutSpeed->setSizePolicy(sizePolicy1);
        label_CutSpeed->setMinimumSize(QSize(145, 25));
        label_CutSpeed->setFont(font2);
        label_CutSpeed->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_CutSpeed);

        doubleSpinBox_CutDepth = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        doubleSpinBox_CutDepth->setObjectName(QStringLiteral("doubleSpinBox_CutDepth"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_CutDepth->sizePolicy().hasHeightForWidth());
        doubleSpinBox_CutDepth->setSizePolicy(sizePolicy2);
        doubleSpinBox_CutDepth->setMinimumSize(QSize(100, 25));
        doubleSpinBox_CutDepth->setFont(font1);
        doubleSpinBox_CutDepth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_CutDepth->setDecimals(1);
        doubleSpinBox_CutDepth->setMaximum(150000);
        doubleSpinBox_CutDepth->setValue(50);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_CutDepth);

        doubleSpinBox_CutSpeed = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        doubleSpinBox_CutSpeed->setObjectName(QStringLiteral("doubleSpinBox_CutSpeed"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_CutSpeed->sizePolicy().hasHeightForWidth());
        doubleSpinBox_CutSpeed->setSizePolicy(sizePolicy2);
        doubleSpinBox_CutSpeed->setMinimumSize(QSize(100, 25));
        doubleSpinBox_CutSpeed->setFont(font1);
        doubleSpinBox_CutSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_CutSpeed->setDecimals(1);
        doubleSpinBox_CutSpeed->setMinimum(0);
        doubleSpinBox_CutSpeed->setMaximum(1000);
        doubleSpinBox_CutSpeed->setValue(0.4);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, doubleSpinBox_CutSpeed);


        gridLayout_7->addLayout(formLayout_2, 0, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_4->addWidget(scrollArea_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_linearParams, QString());
        tab_vibrationParams = new QWidget();
        tab_vibrationParams->setObjectName(QStringLiteral("tab_vibrationParams"));
        gridLayout_2 = new QGridLayout(tab_vibrationParams);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        scrollArea = new QScrollArea(tab_vibrationParams);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(470, 210));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 524, 208));
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        spinBox_RetractSpeed = new QSpinBox(scrollAreaWidgetContents);
        spinBox_RetractSpeed->setObjectName(QStringLiteral("spinBox_RetractSpeed"));
        sizePolicy2.setHeightForWidth(spinBox_RetractSpeed->sizePolicy().hasHeightForWidth());
        spinBox_RetractSpeed->setSizePolicy(sizePolicy2);
        spinBox_RetractSpeed->setMinimumSize(QSize(100, 25));
        spinBox_RetractSpeed->setFont(font1);
        spinBox_RetractSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_RetractSpeed->setMinimum(0);
        spinBox_RetractSpeed->setMaximum(10000);
        spinBox_RetractSpeed->setSingleStep(10);
        spinBox_RetractSpeed->setValue(0);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox_RetractSpeed);

        label_PlungeSpeed = new QLabel(scrollAreaWidgetContents);
        label_PlungeSpeed->setObjectName(QStringLiteral("label_PlungeSpeed"));
        sizePolicy1.setHeightForWidth(label_PlungeSpeed->sizePolicy().hasHeightForWidth());
        label_PlungeSpeed->setSizePolicy(sizePolicy1);
        label_PlungeSpeed->setMinimumSize(QSize(145, 25));
        label_PlungeSpeed->setFont(font2);
        label_PlungeSpeed->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_PlungeSpeed);

        spinBox_PlungeSpeed = new QSpinBox(scrollAreaWidgetContents);
        spinBox_PlungeSpeed->setObjectName(QStringLiteral("spinBox_PlungeSpeed"));
        sizePolicy2.setHeightForWidth(spinBox_PlungeSpeed->sizePolicy().hasHeightForWidth());
        spinBox_PlungeSpeed->setSizePolicy(sizePolicy2);
        spinBox_PlungeSpeed->setMinimumSize(QSize(100, 25));
        spinBox_PlungeSpeed->setFont(font1);
        spinBox_PlungeSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_PlungeSpeed->setMinimum(0);
        spinBox_PlungeSpeed->setMaximum(10000);
        spinBox_PlungeSpeed->setSingleStep(10);
        spinBox_PlungeSpeed->setValue(0);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox_PlungeSpeed);

        label_RetractDistance = new QLabel(scrollAreaWidgetContents);
        label_RetractDistance->setObjectName(QStringLiteral("label_RetractDistance"));
        sizePolicy1.setHeightForWidth(label_RetractDistance->sizePolicy().hasHeightForWidth());
        label_RetractDistance->setSizePolicy(sizePolicy1);
        label_RetractDistance->setMinimumSize(QSize(145, 25));
        label_RetractDistance->setFont(font2);
        label_RetractDistance->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_RetractDistance);

        doubleSpinBox_RetractDistance = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_RetractDistance->setObjectName(QStringLiteral("doubleSpinBox_RetractDistance"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_RetractDistance->sizePolicy().hasHeightForWidth());
        doubleSpinBox_RetractDistance->setSizePolicy(sizePolicy2);
        doubleSpinBox_RetractDistance->setMinimumSize(QSize(100, 25));
        doubleSpinBox_RetractDistance->setFont(font1);
        doubleSpinBox_RetractDistance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_RetractDistance->setDecimals(1);
        doubleSpinBox_RetractDistance->setMaximum(150000);
        doubleSpinBox_RetractDistance->setValue(100);

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox_RetractDistance);

        label_StepSize = new QLabel(scrollAreaWidgetContents);
        label_StepSize->setObjectName(QStringLiteral("label_StepSize"));
        sizePolicy1.setHeightForWidth(label_StepSize->sizePolicy().hasHeightForWidth());
        label_StepSize->setSizePolicy(sizePolicy1);
        label_StepSize->setMinimumSize(QSize(145, 25));
        label_StepSize->setFont(font2);
        label_StepSize->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_StepSize);

        doubleSpinBox_StepSize = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_StepSize->setObjectName(QStringLiteral("doubleSpinBox_StepSize"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_StepSize->sizePolicy().hasHeightForWidth());
        doubleSpinBox_StepSize->setSizePolicy(sizePolicy2);
        doubleSpinBox_StepSize->setMinimumSize(QSize(100, 25));
        doubleSpinBox_StepSize->setFont(font1);
        doubleSpinBox_StepSize->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_StepSize->setDecimals(3);
        doubleSpinBox_StepSize->setMaximum(1000);
        doubleSpinBox_StepSize->setValue(0.05);

        formLayout->setWidget(3, QFormLayout::FieldRole, doubleSpinBox_StepSize);

        label_RetractPeriod = new QLabel(scrollAreaWidgetContents);
        label_RetractPeriod->setObjectName(QStringLiteral("label_RetractPeriod"));
        sizePolicy1.setHeightForWidth(label_RetractPeriod->sizePolicy().hasHeightForWidth());
        label_RetractPeriod->setSizePolicy(sizePolicy1);
        label_RetractPeriod->setMinimumSize(QSize(145, 25));
        label_RetractPeriod->setFont(font2);
        label_RetractPeriod->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_RetractPeriod);

        spinBox_RetractPeriod = new QSpinBox(scrollAreaWidgetContents);
        spinBox_RetractPeriod->setObjectName(QStringLiteral("spinBox_RetractPeriod"));
        sizePolicy2.setHeightForWidth(spinBox_RetractPeriod->sizePolicy().hasHeightForWidth());
        spinBox_RetractPeriod->setSizePolicy(sizePolicy2);
        spinBox_RetractPeriod->setMinimumSize(QSize(100, 25));
        spinBox_RetractPeriod->setFont(font1);
        spinBox_RetractPeriod->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_RetractPeriod->setMinimum(0);
        spinBox_RetractPeriod->setMaximum(10000);
        spinBox_RetractPeriod->setSingleStep(1);
        spinBox_RetractPeriod->setValue(10);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBox_RetractPeriod);

        label_Pause = new QLabel(scrollAreaWidgetContents);
        label_Pause->setObjectName(QStringLiteral("label_Pause"));
        sizePolicy1.setHeightForWidth(label_Pause->sizePolicy().hasHeightForWidth());
        label_Pause->setSizePolicy(sizePolicy1);
        label_Pause->setMinimumSize(QSize(145, 25));
        label_Pause->setFont(font2);
        label_Pause->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_Pause);

        spinBox_Pause = new QSpinBox(scrollAreaWidgetContents);
        spinBox_Pause->setObjectName(QStringLiteral("spinBox_Pause"));
        sizePolicy2.setHeightForWidth(spinBox_Pause->sizePolicy().hasHeightForWidth());
        spinBox_Pause->setSizePolicy(sizePolicy2);
        spinBox_Pause->setMinimumSize(QSize(100, 25));
        spinBox_Pause->setFont(font1);
        spinBox_Pause->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_Pause->setMinimum(0);
        spinBox_Pause->setMaximum(10000);
        spinBox_Pause->setSingleStep(1);
        spinBox_Pause->setValue(8);

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBox_Pause);

        label_RetractSpeed = new QLabel(scrollAreaWidgetContents);
        label_RetractSpeed->setObjectName(QStringLiteral("label_RetractSpeed"));
        sizePolicy1.setHeightForWidth(label_RetractSpeed->sizePolicy().hasHeightForWidth());
        label_RetractSpeed->setSizePolicy(sizePolicy1);
        label_RetractSpeed->setMinimumSize(QSize(145, 25));
        label_RetractSpeed->setFont(font2);
        label_RetractSpeed->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_RetractSpeed);


        gridLayout_5->addLayout(formLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

        tabWidget->addTab(tab_vibrationParams, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        scrollArea_3 = new QScrollArea(tab);
        scrollArea_3->setObjectName(QStringLiteral("scrollArea_3"));
        scrollArea_3->setMinimumSize(QSize(470, 210));
        scrollArea_3->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea_3->setWidgetResizable(true);
        scrollArea_3->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 524, 208));
        gridLayout_18 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));

        gridLayout_18->addLayout(formLayout_3, 0, 0, 1, 1);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        gridLayout_3->addWidget(scrollArea_3, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 2);


        retranslateUi(Widget_ScriptingVariables);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget_ScriptingVariables);
    } // setupUi

    void retranslateUi(QWidget *Widget_ScriptingVariables)
    {
        Widget_ScriptingVariables->setWindowTitle(QApplication::translate("Widget_ScriptingVariables", "Form", nullptr));
        label_ManualControl_2->setText(QApplication::translate("Widget_ScriptingVariables", "Scripting Variables", nullptr));
        label_CutDepth->setText(QApplication::translate("Widget_ScriptingVariables", "Depth of Cut (um)", nullptr));
        label_CutSpeed->setText(QApplication::translate("Widget_ScriptingVariables", "Cut Speed (um/s)", nullptr));
#ifndef QT_NO_TOOLTIP
        doubleSpinBox_CutDepth->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        doubleSpinBox_CutDepth->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        tabWidget->setTabText(tabWidget->indexOf(tab_linearParams), QApplication::translate("Widget_ScriptingVariables", "Linear Parameters", nullptr));
        label_PlungeSpeed->setText(QApplication::translate("Widget_ScriptingVariables", "Plunge Speed (um/s)", nullptr));
        label_RetractDistance->setText(QApplication::translate("Widget_ScriptingVariables", "Retract Distance (um)", nullptr));
        label_StepSize->setText(QApplication::translate("Widget_ScriptingVariables", "Step Size (um)", nullptr));
        label_RetractPeriod->setText(QApplication::translate("Widget_ScriptingVariables", "Retract Period (ms)", nullptr));
        label_Pause->setText(QApplication::translate("Widget_ScriptingVariables", "Pause (ms)", nullptr));
        label_RetractSpeed->setText(QApplication::translate("Widget_ScriptingVariables", "Retract Speed (um/s)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_vibrationParams), QApplication::translate("Widget_ScriptingVariables", "Vibration Parameters", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget_ScriptingVariables", "Unmatched Parameters", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_ScriptingVariables: public Ui_Widget_ScriptingVariables {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SCRIPTING_VARIABLES_H
