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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
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
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_18;
    QListWidget *listWidget_Variables;

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
        listWidget_Variables = new QListWidget(scrollAreaWidgetContents_3);
        listWidget_Variables->setObjectName(QStringLiteral("listWidget_Variables"));

        gridLayout_18->addWidget(listWidget_Variables, 0, 0, 1, 1);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        gridLayout_3->addWidget(scrollArea_3, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 2);


        retranslateUi(Widget_ScriptingVariables);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget_ScriptingVariables);
    } // setupUi

    void retranslateUi(QWidget *Widget_ScriptingVariables)
    {
        Widget_ScriptingVariables->setWindowTitle(QApplication::translate("Widget_ScriptingVariables", "Form", nullptr));
        label_ManualControl_2->setText(QApplication::translate("Widget_ScriptingVariables", "Scripting Variables", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget_ScriptingVariables", "Unmatched Parameters", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_ScriptingVariables: public Ui_Widget_ScriptingVariables {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SCRIPTING_VARIABLES_H
