/********************************************************************************
** Form generated from reading UI file 'widget_munk_temperature_state.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_MUNK_TEMPERATURE_STATE_H
#define UI_WIDGET_MUNK_TEMPERATURE_STATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_MunkTemperatureState
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_BoardNumber;
    QLineEdit *lineEdit_Temp1;
    QLineEdit *lineEdit_Temp2;

    void setupUi(QWidget *Widget_MunkTemperatureState)
    {
        if (Widget_MunkTemperatureState->objectName().isEmpty())
            Widget_MunkTemperatureState->setObjectName(QStringLiteral("Widget_MunkTemperatureState"));
        Widget_MunkTemperatureState->resize(392, 40);
        gridLayout = new QGridLayout(Widget_MunkTemperatureState);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_BoardNumber = new QLineEdit(Widget_MunkTemperatureState);
        lineEdit_BoardNumber->setObjectName(QStringLiteral("lineEdit_BoardNumber"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_BoardNumber->sizePolicy().hasHeightForWidth());
        lineEdit_BoardNumber->setSizePolicy(sizePolicy);
        lineEdit_BoardNumber->setMinimumSize(QSize(120, 0));
        lineEdit_BoardNumber->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(12);
        lineEdit_BoardNumber->setFont(font);
        lineEdit_BoardNumber->setAlignment(Qt::AlignCenter);
        lineEdit_BoardNumber->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit_BoardNumber);

        lineEdit_Temp1 = new QLineEdit(Widget_MunkTemperatureState);
        lineEdit_Temp1->setObjectName(QStringLiteral("lineEdit_Temp1"));
        sizePolicy.setHeightForWidth(lineEdit_Temp1->sizePolicy().hasHeightForWidth());
        lineEdit_Temp1->setSizePolicy(sizePolicy);
        lineEdit_Temp1->setMinimumSize(QSize(120, 0));
        lineEdit_Temp1->setMaximumSize(QSize(16777215, 20));
        lineEdit_Temp1->setFont(font);
        lineEdit_Temp1->setAlignment(Qt::AlignCenter);
        lineEdit_Temp1->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit_Temp1);

        lineEdit_Temp2 = new QLineEdit(Widget_MunkTemperatureState);
        lineEdit_Temp2->setObjectName(QStringLiteral("lineEdit_Temp2"));
        sizePolicy.setHeightForWidth(lineEdit_Temp2->sizePolicy().hasHeightForWidth());
        lineEdit_Temp2->setSizePolicy(sizePolicy);
        lineEdit_Temp2->setMinimumSize(QSize(120, 0));
        lineEdit_Temp2->setMaximumSize(QSize(16777215, 20));
        lineEdit_Temp2->setFont(font);
        lineEdit_Temp2->setAlignment(Qt::AlignCenter);
        lineEdit_Temp2->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit_Temp2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Widget_MunkTemperatureState);

        QMetaObject::connectSlotsByName(Widget_MunkTemperatureState);
    } // setupUi

    void retranslateUi(QWidget *Widget_MunkTemperatureState)
    {
        Widget_MunkTemperatureState->setWindowTitle(QApplication::translate("Widget_MunkTemperatureState", "Form", nullptr));
        lineEdit_BoardNumber->setText(QApplication::translate("Widget_MunkTemperatureState", "0", nullptr));
        lineEdit_Temp1->setText(QApplication::translate("Widget_MunkTemperatureState", "0", nullptr));
        lineEdit_Temp2->setText(QApplication::translate("Widget_MunkTemperatureState", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_MunkTemperatureState: public Ui_Widget_MunkTemperatureState {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_MUNK_TEMPERATURE_STATE_H
