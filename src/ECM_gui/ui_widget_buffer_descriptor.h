/********************************************************************************
** Form generated from reading UI file 'widget_buffer_descriptor.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_BUFFER_DESCRIPTOR_H
#define UI_WIDGET_BUFFER_DESCRIPTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "LED.h"

QT_BEGIN_NAMESPACE

class Ui_Widget_BufferDescriptor
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_BufferIndex;
    QSpacerItem *horizontalSpacer;
    QLabel *label_BufferName;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_DisplayBuffer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_Lines;
    QSpacerItem *horizontalSpacer_3;
    LED *led_ProgramChanged;
    QSpacerItem *horizontalSpacer_4;
    LED *led_ProgramCompiled;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line;

    void setupUi(QWidget *Widget_BufferDescriptor)
    {
        if (Widget_BufferDescriptor->objectName().isEmpty())
            Widget_BufferDescriptor->setObjectName(QStringLiteral("Widget_BufferDescriptor"));
        Widget_BufferDescriptor->resize(435, 32);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_BufferDescriptor->sizePolicy().hasHeightForWidth());
        Widget_BufferDescriptor->setSizePolicy(sizePolicy);
        Widget_BufferDescriptor->setMinimumSize(QSize(435, 32));
        Widget_BufferDescriptor->setMaximumSize(QSize(435, 32));
        Widget_BufferDescriptor->setStyleSheet(QLatin1String("QMenuBar{\n"
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
        gridLayout = new QGridLayout(Widget_BufferDescriptor);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_BufferIndex = new QLabel(Widget_BufferDescriptor);
        label_BufferIndex->setObjectName(QStringLiteral("label_BufferIndex"));
        sizePolicy.setHeightForWidth(label_BufferIndex->sizePolicy().hasHeightForWidth());
        label_BufferIndex->setSizePolicy(sizePolicy);
        label_BufferIndex->setMinimumSize(QSize(30, 20));
        label_BufferIndex->setMaximumSize(QSize(30, 20));
        QFont font;
        font.setPointSize(10);
        label_BufferIndex->setFont(font);
        label_BufferIndex->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_BufferIndex);

        horizontalSpacer = new QSpacerItem(13, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_BufferName = new QLabel(Widget_BufferDescriptor);
        label_BufferName->setObjectName(QStringLiteral("label_BufferName"));
        sizePolicy.setHeightForWidth(label_BufferName->sizePolicy().hasHeightForWidth());
        label_BufferName->setSizePolicy(sizePolicy);
        label_BufferName->setMinimumSize(QSize(100, 20));
        label_BufferName->setMaximumSize(QSize(100, 20));
        label_BufferName->setFont(font);
        label_BufferName->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_BufferName);

        horizontalSpacer_6 = new QSpacerItem(13, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        pushButton_DisplayBuffer = new QPushButton(Widget_BufferDescriptor);
        pushButton_DisplayBuffer->setObjectName(QStringLiteral("pushButton_DisplayBuffer"));
        pushButton_DisplayBuffer->setMinimumSize(QSize(40, 20));
        pushButton_DisplayBuffer->setMaximumSize(QSize(40, 20));
        pushButton_DisplayBuffer->setFont(font);

        horizontalLayout->addWidget(pushButton_DisplayBuffer);

        horizontalSpacer_2 = new QSpacerItem(13, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_Lines = new QLabel(Widget_BufferDescriptor);
        label_Lines->setObjectName(QStringLiteral("label_Lines"));
        sizePolicy.setHeightForWidth(label_Lines->sizePolicy().hasHeightForWidth());
        label_Lines->setSizePolicy(sizePolicy);
        label_Lines->setMinimumSize(QSize(50, 20));
        label_Lines->setMaximumSize(QSize(50, 20));
        label_Lines->setFont(font);
        label_Lines->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_Lines);

        horizontalSpacer_3 = new QSpacerItem(13, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        led_ProgramChanged = new LED(Widget_BufferDescriptor);
        led_ProgramChanged->setObjectName(QStringLiteral("led_ProgramChanged"));
        sizePolicy.setHeightForWidth(led_ProgramChanged->sizePolicy().hasHeightForWidth());
        led_ProgramChanged->setSizePolicy(sizePolicy);
        led_ProgramChanged->setMinimumSize(QSize(20, 20));
        led_ProgramChanged->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(led_ProgramChanged);

        horizontalSpacer_4 = new QSpacerItem(13, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        led_ProgramCompiled = new LED(Widget_BufferDescriptor);
        led_ProgramCompiled->setObjectName(QStringLiteral("led_ProgramCompiled"));
        sizePolicy.setHeightForWidth(led_ProgramCompiled->sizePolicy().hasHeightForWidth());
        led_ProgramCompiled->setSizePolicy(sizePolicy);
        led_ProgramCompiled->setMinimumSize(QSize(20, 20));
        led_ProgramCompiled->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(led_ProgramCompiled);

        horizontalSpacer_5 = new QSpacerItem(13, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        line = new QFrame(Widget_BufferDescriptor);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 1);


        retranslateUi(Widget_BufferDescriptor);

        QMetaObject::connectSlotsByName(Widget_BufferDescriptor);
    } // setupUi

    void retranslateUi(QWidget *Widget_BufferDescriptor)
    {
        Widget_BufferDescriptor->setWindowTitle(QApplication::translate("Widget_BufferDescriptor", "Form", nullptr));
        label_BufferIndex->setText(QApplication::translate("Widget_BufferDescriptor", "0", nullptr));
        label_BufferName->setText(QApplication::translate("Widget_BufferDescriptor", "BufferName", nullptr));
        pushButton_DisplayBuffer->setText(QApplication::translate("Widget_BufferDescriptor", "OPEN", nullptr));
        label_Lines->setText(QApplication::translate("Widget_BufferDescriptor", "LINES", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_BufferDescriptor: public Ui_Widget_BufferDescriptor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_BUFFER_DESCRIPTOR_H
