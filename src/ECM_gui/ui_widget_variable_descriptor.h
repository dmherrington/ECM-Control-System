/********************************************************************************
** Form generated from reading UI file 'widget_variable_descriptor.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_VARIABLE_DESCRIPTOR_H
#define UI_WIDGET_VARIABLE_DESCRIPTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_VariableDescriptor
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_VariableName;
    QDoubleSpinBox *doubleSpinBox_VariableValue;

    void setupUi(QWidget *Widget_VariableDescriptor)
    {
        if (Widget_VariableDescriptor->objectName().isEmpty())
            Widget_VariableDescriptor->setObjectName(QStringLiteral("Widget_VariableDescriptor"));
        Widget_VariableDescriptor->resize(226, 40);
        Widget_VariableDescriptor->setStyleSheet(QLatin1String("QMenuBar{\n"
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
        gridLayout = new QGridLayout(Widget_VariableDescriptor);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_VariableName = new QLabel(Widget_VariableDescriptor);
        label_VariableName->setObjectName(QStringLiteral("label_VariableName"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_VariableName->sizePolicy().hasHeightForWidth());
        label_VariableName->setSizePolicy(sizePolicy);
        label_VariableName->setMinimumSize(QSize(120, 20));
        label_VariableName->setMaximumSize(QSize(120, 20));
        QFont font;
        font.setPointSize(10);
        label_VariableName->setFont(font);

        horizontalLayout->addWidget(label_VariableName);

        doubleSpinBox_VariableValue = new QDoubleSpinBox(Widget_VariableDescriptor);
        doubleSpinBox_VariableValue->setObjectName(QStringLiteral("doubleSpinBox_VariableValue"));
        doubleSpinBox_VariableValue->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(doubleSpinBox_VariableValue->sizePolicy().hasHeightForWidth());
        doubleSpinBox_VariableValue->setSizePolicy(sizePolicy1);
        doubleSpinBox_VariableValue->setMinimumSize(QSize(80, 20));
        doubleSpinBox_VariableValue->setMaximumSize(QSize(80, 20));
        doubleSpinBox_VariableValue->setFont(font);
        doubleSpinBox_VariableValue->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        doubleSpinBox_VariableValue->setMinimum(-1e+6);
        doubleSpinBox_VariableValue->setMaximum(1e+6);

        horizontalLayout->addWidget(doubleSpinBox_VariableValue);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Widget_VariableDescriptor);

        QMetaObject::connectSlotsByName(Widget_VariableDescriptor);
    } // setupUi

    void retranslateUi(QWidget *Widget_VariableDescriptor)
    {
        Widget_VariableDescriptor->setWindowTitle(QApplication::translate("Widget_VariableDescriptor", "Form", nullptr));
        label_VariableName->setText(QApplication::translate("Widget_VariableDescriptor", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_VariableDescriptor: public Ui_Widget_VariableDescriptor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_VARIABLE_DESCRIPTOR_H
