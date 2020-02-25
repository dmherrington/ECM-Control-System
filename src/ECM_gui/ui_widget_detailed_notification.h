/********************************************************************************
** Form generated from reading UI file 'widget_detailed_notification.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_DETAILED_NOTIFICATION_H
#define UI_WIDGET_DETAILED_NOTIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_DetailedNotification
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit_Time;
    QSpacerItem *verticalSpacer_2;
    QPlainTextEdit *plainTextEdit_Message;

    void setupUi(QWidget *Widget_DetailedNotification)
    {
        if (Widget_DetailedNotification->objectName().isEmpty())
            Widget_DetailedNotification->setObjectName(QStringLiteral("Widget_DetailedNotification"));
        Widget_DetailedNotification->resize(360, 64);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_DetailedNotification->sizePolicy().hasHeightForWidth());
        Widget_DetailedNotification->setSizePolicy(sizePolicy);
        Widget_DetailedNotification->setMinimumSize(QSize(360, 64));
        Widget_DetailedNotification->setMaximumSize(QSize(360, 64));
        gridLayout_2 = new QGridLayout(Widget_DetailedNotification);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(Widget_DetailedNotification);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(360, 60));
        frame->setMaximumSize(QSize(360, 60));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(2);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        lineEdit_Time = new QLineEdit(frame);
        lineEdit_Time->setObjectName(QStringLiteral("lineEdit_Time"));
        lineEdit_Time->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_Time->sizePolicy().hasHeightForWidth());
        lineEdit_Time->setSizePolicy(sizePolicy1);
        lineEdit_Time->setMinimumSize(QSize(90, 25));
        lineEdit_Time->setMaximumSize(QSize(90, 25));
        QFont font;
        font.setPointSize(8);
        lineEdit_Time->setFont(font);
        lineEdit_Time->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lineEdit_Time);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        plainTextEdit_Message = new QPlainTextEdit(frame);
        plainTextEdit_Message->setObjectName(QStringLiteral("plainTextEdit_Message"));
        plainTextEdit_Message->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(plainTextEdit_Message->sizePolicy().hasHeightForWidth());
        plainTextEdit_Message->setSizePolicy(sizePolicy2);
        plainTextEdit_Message->setMinimumSize(QSize(260, 25));
        plainTextEdit_Message->setMaximumSize(QSize(260, 60));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        plainTextEdit_Message->setFont(font1);
        plainTextEdit_Message->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        plainTextEdit_Message->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_Message->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        plainTextEdit_Message->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        plainTextEdit_Message->setReadOnly(true);
        plainTextEdit_Message->setBackgroundVisible(false);
        plainTextEdit_Message->setCenterOnScroll(false);

        gridLayout->addWidget(plainTextEdit_Message, 0, 1, 1, 1);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(Widget_DetailedNotification);

        QMetaObject::connectSlotsByName(Widget_DetailedNotification);
    } // setupUi

    void retranslateUi(QWidget *Widget_DetailedNotification)
    {
        Widget_DetailedNotification->setWindowTitle(QApplication::translate("Widget_DetailedNotification", "Form", nullptr));
        lineEdit_Time->setText(QApplication::translate("Widget_DetailedNotification", "Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_DetailedNotification: public Ui_Widget_DetailedNotification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_DETAILED_NOTIFICATION_H
