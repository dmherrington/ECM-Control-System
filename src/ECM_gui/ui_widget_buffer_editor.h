/********************************************************************************
** Form generated from reading UI file 'widget_buffer_editor.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_BUFFER_EDITOR_H
#define UI_WIDGET_BUFFER_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "LED.h"
#include "misc_dialogs/code_edit_widget.h"

QT_BEGIN_NAMESPACE

class Ui_Widget_BufferEditor
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_4;
    QLabel *label_Header;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *lineEdit_BufferName;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_BuferIndex;
    QLabel *label_BufferIndexNumber;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout;
    QPushButton *pushButton_Upload;
    QPushButton *pushButton_Download;
    QPushButton *pushButton_Execute;
    QPushButton *pushButton_Clear;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_Current;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    LED *led_ProgramCurrent;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Compiled;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    LED *led_ProgramCompiled;
    QSpacerItem *horizontalSpacer_8;
    CodeEditWidget *codeTextEdit;

    void setupUi(QWidget *Widget_BufferEditor)
    {
        if (Widget_BufferEditor->objectName().isEmpty())
            Widget_BufferEditor->setObjectName(QStringLiteral("Widget_BufferEditor"));
        Widget_BufferEditor->resize(672, 626);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_BufferEditor->sizePolicy().hasHeightForWidth());
        Widget_BufferEditor->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(Widget_BufferEditor);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_Header = new QLabel(Widget_BufferEditor);
        label_Header->setObjectName(QStringLiteral("label_Header"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_Header->sizePolicy().hasHeightForWidth());
        label_Header->setSizePolicy(sizePolicy1);
        label_Header->setMinimumSize(QSize(0, 32));
        label_Header->setMaximumSize(QSize(16777215, 32));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_Header->setFont(font);
        label_Header->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_Header, 0, 0, 1, 1);


        horizontalLayout_6->addLayout(gridLayout_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        horizontalLayout->addLayout(horizontalLayout_6);

        horizontalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        lineEdit_BufferName = new QLineEdit(Widget_BufferEditor);
        lineEdit_BufferName->setObjectName(QStringLiteral("lineEdit_BufferName"));
        sizePolicy1.setHeightForWidth(lineEdit_BufferName->sizePolicy().hasHeightForWidth());
        lineEdit_BufferName->setSizePolicy(sizePolicy1);
        lineEdit_BufferName->setMinimumSize(QSize(200, 20));
        lineEdit_BufferName->setMaximumSize(QSize(200, 20));
        QFont font1;
        font1.setPointSize(12);
        lineEdit_BufferName->setFont(font1);
        lineEdit_BufferName->setAlignment(Qt::AlignCenter);
        lineEdit_BufferName->setClearButtonEnabled(false);

        horizontalLayout->addWidget(lineEdit_BufferName);

        horizontalSpacer_10 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetMaximumSize);
        label_BuferIndex = new QLabel(Widget_BufferEditor);
        label_BuferIndex->setObjectName(QStringLiteral("label_BuferIndex"));
        sizePolicy1.setHeightForWidth(label_BuferIndex->sizePolicy().hasHeightForWidth());
        label_BuferIndex->setSizePolicy(sizePolicy1);
        label_BuferIndex->setMinimumSize(QSize(110, 20));
        label_BuferIndex->setMaximumSize(QSize(110, 20));
        label_BuferIndex->setFont(font1);
        label_BuferIndex->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_BuferIndex);

        label_BufferIndexNumber = new QLabel(Widget_BufferEditor);
        label_BufferIndexNumber->setObjectName(QStringLiteral("label_BufferIndexNumber"));
        sizePolicy1.setHeightForWidth(label_BufferIndexNumber->sizePolicy().hasHeightForWidth());
        label_BufferIndexNumber->setSizePolicy(sizePolicy1);
        label_BufferIndexNumber->setMinimumSize(QSize(80, 20));
        label_BufferIndexNumber->setMaximumSize(QSize(80, 20));
        label_BufferIndexNumber->setFont(font1);
        label_BufferIndexNumber->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_BufferIndexNumber);


        horizontalLayout->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_Upload = new QPushButton(Widget_BufferEditor);
        pushButton_Upload->setObjectName(QStringLiteral("pushButton_Upload"));
        sizePolicy1.setHeightForWidth(pushButton_Upload->sizePolicy().hasHeightForWidth());
        pushButton_Upload->setSizePolicy(sizePolicy1);
        pushButton_Upload->setMinimumSize(QSize(50, 30));
        pushButton_Upload->setMaximumSize(QSize(50, 30));
        pushButton_Upload->setFont(font1);

        gridLayout->addWidget(pushButton_Upload, 0, 0, 1, 1);

        pushButton_Download = new QPushButton(Widget_BufferEditor);
        pushButton_Download->setObjectName(QStringLiteral("pushButton_Download"));
        sizePolicy1.setHeightForWidth(pushButton_Download->sizePolicy().hasHeightForWidth());
        pushButton_Download->setSizePolicy(sizePolicy1);
        pushButton_Download->setMinimumSize(QSize(50, 30));
        pushButton_Download->setMaximumSize(QSize(50, 30));
        pushButton_Download->setFont(font1);

        gridLayout->addWidget(pushButton_Download, 0, 1, 1, 1);

        pushButton_Execute = new QPushButton(Widget_BufferEditor);
        pushButton_Execute->setObjectName(QStringLiteral("pushButton_Execute"));
        sizePolicy1.setHeightForWidth(pushButton_Execute->sizePolicy().hasHeightForWidth());
        pushButton_Execute->setSizePolicy(sizePolicy1);
        pushButton_Execute->setMinimumSize(QSize(50, 30));
        pushButton_Execute->setMaximumSize(QSize(50, 30));
        pushButton_Execute->setFont(font1);

        gridLayout->addWidget(pushButton_Execute, 1, 0, 1, 1);

        pushButton_Clear = new QPushButton(Widget_BufferEditor);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));
        sizePolicy1.setHeightForWidth(pushButton_Clear->sizePolicy().hasHeightForWidth());
        pushButton_Clear->setSizePolicy(sizePolicy1);
        pushButton_Clear->setMinimumSize(QSize(50, 30));
        pushButton_Clear->setMaximumSize(QSize(50, 30));
        pushButton_Clear->setFont(font1);

        gridLayout->addWidget(pushButton_Clear, 1, 1, 1, 1);


        horizontalLayout_5->addLayout(gridLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_Current = new QLabel(Widget_BufferEditor);
        label_Current->setObjectName(QStringLiteral("label_Current"));
        sizePolicy1.setHeightForWidth(label_Current->sizePolicy().hasHeightForWidth());
        label_Current->setSizePolicy(sizePolicy1);
        label_Current->setMinimumSize(QSize(80, 18));
        label_Current->setMaximumSize(QSize(80, 18));
        label_Current->setFont(font1);
        label_Current->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_Current);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(2, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        led_ProgramCurrent = new LED(Widget_BufferEditor);
        led_ProgramCurrent->setObjectName(QStringLiteral("led_ProgramCurrent"));
        sizePolicy1.setHeightForWidth(led_ProgramCurrent->sizePolicy().hasHeightForWidth());
        led_ProgramCurrent->setSizePolicy(sizePolicy1);
        led_ProgramCurrent->setMinimumSize(QSize(40, 40));
        led_ProgramCurrent->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(led_ProgramCurrent);

        horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_Compiled = new QLabel(Widget_BufferEditor);
        label_Compiled->setObjectName(QStringLiteral("label_Compiled"));
        sizePolicy1.setHeightForWidth(label_Compiled->sizePolicy().hasHeightForWidth());
        label_Compiled->setSizePolicy(sizePolicy1);
        label_Compiled->setMinimumSize(QSize(80, 18));
        label_Compiled->setMaximumSize(QSize(80, 18));
        label_Compiled->setFont(font1);
        label_Compiled->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_Compiled);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(2, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        led_ProgramCompiled = new LED(Widget_BufferEditor);
        led_ProgramCompiled->setObjectName(QStringLiteral("led_ProgramCompiled"));
        sizePolicy1.setHeightForWidth(led_ProgramCompiled->sizePolicy().hasHeightForWidth());
        led_ProgramCompiled->setSizePolicy(sizePolicy1);
        led_ProgramCompiled->setMinimumSize(QSize(40, 40));
        led_ProgramCompiled->setMaximumSize(QSize(40, 40));

        horizontalLayout_3->addWidget(led_ProgramCompiled);

        horizontalSpacer_8 = new QSpacerItem(2, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout_2);


        gridLayout_2->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        codeTextEdit = new CodeEditWidget(Widget_BufferEditor);
        codeTextEdit->setObjectName(QStringLiteral("codeTextEdit"));

        gridLayout_2->addWidget(codeTextEdit, 2, 0, 1, 1);


        retranslateUi(Widget_BufferEditor);

        QMetaObject::connectSlotsByName(Widget_BufferEditor);
    } // setupUi

    void retranslateUi(QWidget *Widget_BufferEditor)
    {
        Widget_BufferEditor->setWindowTitle(QApplication::translate("Widget_BufferEditor", "Form", nullptr));
        label_Header->setText(QApplication::translate("Widget_BufferEditor", "Buffer Code", nullptr));
        lineEdit_BufferName->setText(QApplication::translate("Widget_BufferEditor", "DEFAULT BUFFER NAME", nullptr));
        label_BuferIndex->setText(QApplication::translate("Widget_BufferEditor", "Buffer Index:", nullptr));
        label_BufferIndexNumber->setText(QApplication::translate("Widget_BufferEditor", "0", nullptr));
        pushButton_Upload->setText(QApplication::translate("Widget_BufferEditor", "UP", nullptr));
        pushButton_Download->setText(QApplication::translate("Widget_BufferEditor", "DN", nullptr));
        pushButton_Execute->setText(QApplication::translate("Widget_BufferEditor", "EXE", nullptr));
        pushButton_Clear->setText(QApplication::translate("Widget_BufferEditor", "CLR", nullptr));
        label_Current->setText(QApplication::translate("Widget_BufferEditor", "Current:", nullptr));
        label_Compiled->setText(QApplication::translate("Widget_BufferEditor", "Compiled:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_BufferEditor: public Ui_Widget_BufferEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_BUFFER_EDITOR_H
