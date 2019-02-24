/********************************************************************************
** Form generated from reading UI file 'widget_buffer_descriptor.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_BUFFER_DESCRIPTOR_H
#define UI_WIDGET_BUFFER_DESCRIPTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_Lines;
    QSpacerItem *horizontalSpacer_3;
    LED *led_ProgramChanges;
    QSpacerItem *horizontalSpacer_4;
    LED *led_ProgramCompiled;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line;

    void setupUi(QWidget *Widget_BufferDescriptor)
    {
        if (Widget_BufferDescriptor->objectName().isEmpty())
            Widget_BufferDescriptor->setObjectName(QStringLiteral("Widget_BufferDescriptor"));
        Widget_BufferDescriptor->resize(435, 48);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_BufferDescriptor->sizePolicy().hasHeightForWidth());
        Widget_BufferDescriptor->setSizePolicy(sizePolicy);
        Widget_BufferDescriptor->setMinimumSize(QSize(435, 48));
        Widget_BufferDescriptor->setMaximumSize(QSize(435, 48));
        gridLayout = new QGridLayout(Widget_BufferDescriptor);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_BufferIndex = new QLabel(Widget_BufferDescriptor);
        label_BufferIndex->setObjectName(QStringLiteral("label_BufferIndex"));
        sizePolicy.setHeightForWidth(label_BufferIndex->sizePolicy().hasHeightForWidth());
        label_BufferIndex->setSizePolicy(sizePolicy);
        label_BufferIndex->setMinimumSize(QSize(30, 18));
        label_BufferIndex->setMaximumSize(QSize(30, 18));
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
        label_BufferName->setMinimumSize(QSize(100, 18));
        label_BufferName->setMaximumSize(QSize(100, 18));
        label_BufferName->setFont(font);
        label_BufferName->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_BufferName);

        horizontalSpacer_6 = new QSpacerItem(13, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        pushButton = new QPushButton(Widget_BufferDescriptor);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(40, 18));
        pushButton->setMaximumSize(QSize(40, 18));
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(13, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_Lines = new QLabel(Widget_BufferDescriptor);
        label_Lines->setObjectName(QStringLiteral("label_Lines"));
        sizePolicy.setHeightForWidth(label_Lines->sizePolicy().hasHeightForWidth());
        label_Lines->setSizePolicy(sizePolicy);
        label_Lines->setMinimumSize(QSize(50, 18));
        label_Lines->setMaximumSize(QSize(50, 18));
        label_Lines->setFont(font);
        label_Lines->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_Lines);

        horizontalSpacer_3 = new QSpacerItem(13, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        led_ProgramChanges = new LED(Widget_BufferDescriptor);
        led_ProgramChanges->setObjectName(QStringLiteral("led_ProgramChanges"));
        sizePolicy.setHeightForWidth(led_ProgramChanges->sizePolicy().hasHeightForWidth());
        led_ProgramChanges->setSizePolicy(sizePolicy);
        led_ProgramChanges->setMinimumSize(QSize(18, 18));
        led_ProgramChanges->setMaximumSize(QSize(18, 18));

        horizontalLayout->addWidget(led_ProgramChanges);

        horizontalSpacer_4 = new QSpacerItem(13, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        led_ProgramCompiled = new LED(Widget_BufferDescriptor);
        led_ProgramCompiled->setObjectName(QStringLiteral("led_ProgramCompiled"));
        sizePolicy.setHeightForWidth(led_ProgramCompiled->sizePolicy().hasHeightForWidth());
        led_ProgramCompiled->setSizePolicy(sizePolicy);
        led_ProgramCompiled->setMinimumSize(QSize(18, 18));
        led_ProgramCompiled->setMaximumSize(QSize(18, 18));

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
        pushButton->setText(QApplication::translate("Widget_BufferDescriptor", "OPEN", nullptr));
        label_Lines->setText(QApplication::translate("Widget_BufferDescriptor", "LINES", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_BufferDescriptor: public Ui_Widget_BufferDescriptor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_BUFFER_DESCRIPTOR_H
