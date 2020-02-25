/********************************************************************************
** Form generated from reading UI file 'widget_device_fault.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_DEVICE_FAULT_H
#define UI_WIDGET_DEVICE_FAULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_DeviceFault
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_ClearFault;
    QPlainTextEdit *plainTextEdit_ErrorMessage;

    void setupUi(QWidget *Widget_DeviceFault)
    {
        if (Widget_DeviceFault->objectName().isEmpty())
            Widget_DeviceFault->setObjectName(QStringLiteral("Widget_DeviceFault"));
        Widget_DeviceFault->resize(641, 50);
        Widget_DeviceFault->setMinimumSize(QSize(0, 50));
        Widget_DeviceFault->setMaximumSize(QSize(16777215, 100));
        Widget_DeviceFault->setStyleSheet(QLatin1String("QMenuBar{\n"
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
        gridLayout = new QGridLayout(Widget_DeviceFault);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_ClearFault = new QPushButton(Widget_DeviceFault);
        pushButton_ClearFault->setObjectName(QStringLiteral("pushButton_ClearFault"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_ClearFault->sizePolicy().hasHeightForWidth());
        pushButton_ClearFault->setSizePolicy(sizePolicy);
        pushButton_ClearFault->setMinimumSize(QSize(180, 30));
        QFont font;
        font.setPointSize(12);
        pushButton_ClearFault->setFont(font);

        gridLayout->addWidget(pushButton_ClearFault, 0, 0, 1, 1);

        plainTextEdit_ErrorMessage = new QPlainTextEdit(Widget_DeviceFault);
        plainTextEdit_ErrorMessage->setObjectName(QStringLiteral("plainTextEdit_ErrorMessage"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plainTextEdit_ErrorMessage->sizePolicy().hasHeightForWidth());
        plainTextEdit_ErrorMessage->setSizePolicy(sizePolicy1);
        plainTextEdit_ErrorMessage->setMinimumSize(QSize(0, 30));
        plainTextEdit_ErrorMessage->setReadOnly(true);

        gridLayout->addWidget(plainTextEdit_ErrorMessage, 0, 1, 1, 1);


        retranslateUi(Widget_DeviceFault);

        pushButton_ClearFault->setDefault(true);


        QMetaObject::connectSlotsByName(Widget_DeviceFault);
    } // setupUi

    void retranslateUi(QWidget *Widget_DeviceFault)
    {
        Widget_DeviceFault->setWindowTitle(QApplication::translate("Widget_DeviceFault", "Form", nullptr));
        pushButton_ClearFault->setText(QApplication::translate("Widget_DeviceFault", "Clear Fault", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_DeviceFault: public Ui_Widget_DeviceFault {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_DEVICE_FAULT_H
