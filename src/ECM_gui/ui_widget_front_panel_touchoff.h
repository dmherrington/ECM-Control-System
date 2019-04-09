/********************************************************************************
** Form generated from reading UI file 'widget_front_panel_touchoff.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_FRONT_PANEL_TOUCHOFF_H
#define UI_WIDGET_FRONT_PANEL_TOUCHOFF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetFrontPanel_Touchoff
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_15;
    QGridLayout *gridLayout_13;
    QLabel *label_ManualControl_4;
    QSpacerItem *horizontalSpacer_16;
    QFormLayout *formLayout;
    QPushButton *pushButton_TouchoffRef;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *doubleSpinBox_TouchoffRef;
    QLabel *label;
    QFormLayout *formLayout_3;
    QPushButton *pushButton_TouchoffGap;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *doubleSpinBox_InitialGap;
    QLabel *label_2;
    QFormLayout *formLayout_2;
    QPushButton *pushButton_ExecuteTouchoff;
    QLineEdit *lineEdit_TouchoffCode;

    void setupUi(QWidget *WidgetFrontPanel_Touchoff)
    {
        if (WidgetFrontPanel_Touchoff->objectName().isEmpty())
            WidgetFrontPanel_Touchoff->setObjectName(QStringLiteral("WidgetFrontPanel_Touchoff"));
        WidgetFrontPanel_Touchoff->resize(430, 163);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetFrontPanel_Touchoff->sizePolicy().hasHeightForWidth());
        WidgetFrontPanel_Touchoff->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(WidgetFrontPanel_Touchoff);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_15);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        label_ManualControl_4 = new QLabel(WidgetFrontPanel_Touchoff);
        label_ManualControl_4->setObjectName(QStringLiteral("label_ManualControl_4"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_ManualControl_4->sizePolicy().hasHeightForWidth());
        label_ManualControl_4->setSizePolicy(sizePolicy1);
        label_ManualControl_4->setMinimumSize(QSize(0, 32));
        label_ManualControl_4->setMaximumSize(QSize(16777215, 32));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_ManualControl_4->setFont(font);
        label_ManualControl_4->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(label_ManualControl_4, 0, 0, 1, 1);


        horizontalLayout_11->addLayout(gridLayout_13);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_16);


        gridLayout->addLayout(horizontalLayout_11, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        pushButton_TouchoffRef = new QPushButton(WidgetFrontPanel_Touchoff);
        pushButton_TouchoffRef->setObjectName(QStringLiteral("pushButton_TouchoffRef"));
        sizePolicy.setHeightForWidth(pushButton_TouchoffRef->sizePolicy().hasHeightForWidth());
        pushButton_TouchoffRef->setSizePolicy(sizePolicy);
        pushButton_TouchoffRef->setMinimumSize(QSize(180, 25));
        pushButton_TouchoffRef->setMaximumSize(QSize(180, 25));
        QFont font1;
        font1.setPointSize(12);
        pushButton_TouchoffRef->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, pushButton_TouchoffRef);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        doubleSpinBox_TouchoffRef = new QDoubleSpinBox(WidgetFrontPanel_Touchoff);
        doubleSpinBox_TouchoffRef->setObjectName(QStringLiteral("doubleSpinBox_TouchoffRef"));
        sizePolicy.setHeightForWidth(doubleSpinBox_TouchoffRef->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TouchoffRef->setSizePolicy(sizePolicy);
        doubleSpinBox_TouchoffRef->setMinimumSize(QSize(120, 25));
        doubleSpinBox_TouchoffRef->setMaximumSize(QSize(120, 25));
        QFont font2;
        font2.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font2.setPointSize(11);
        doubleSpinBox_TouchoffRef->setFont(font2);
        doubleSpinBox_TouchoffRef->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_TouchoffRef->setDecimals(1);
        doubleSpinBox_TouchoffRef->setMaximum(500000);

        horizontalLayout->addWidget(doubleSpinBox_TouchoffRef);

        label = new QLabel(WidgetFrontPanel_Touchoff);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(32, 25));
        label->setMaximumSize(QSize(32, 25));

        horizontalLayout->addWidget(label);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);


        gridLayout->addLayout(formLayout, 1, 0, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        pushButton_TouchoffGap = new QPushButton(WidgetFrontPanel_Touchoff);
        pushButton_TouchoffGap->setObjectName(QStringLiteral("pushButton_TouchoffGap"));
        sizePolicy.setHeightForWidth(pushButton_TouchoffGap->sizePolicy().hasHeightForWidth());
        pushButton_TouchoffGap->setSizePolicy(sizePolicy);
        pushButton_TouchoffGap->setMinimumSize(QSize(180, 25));
        pushButton_TouchoffGap->setMaximumSize(QSize(16777215, 25));
        pushButton_TouchoffGap->setFont(font1);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, pushButton_TouchoffGap);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        doubleSpinBox_InitialGap = new QDoubleSpinBox(WidgetFrontPanel_Touchoff);
        doubleSpinBox_InitialGap->setObjectName(QStringLiteral("doubleSpinBox_InitialGap"));
        doubleSpinBox_InitialGap->setMinimumSize(QSize(120, 25));
        doubleSpinBox_InitialGap->setMaximumSize(QSize(120, 25));
        QFont font3;
        font3.setPointSize(11);
        doubleSpinBox_InitialGap->setFont(font3);
        doubleSpinBox_InitialGap->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_InitialGap->setDecimals(1);
        doubleSpinBox_InitialGap->setMaximum(100000);

        horizontalLayout_2->addWidget(doubleSpinBox_InitialGap);

        label_2 = new QLabel(WidgetFrontPanel_Touchoff);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(32, 25));
        label_2->setMaximumSize(QSize(32, 25));

        horizontalLayout_2->addWidget(label_2);


        formLayout_3->setLayout(0, QFormLayout::FieldRole, horizontalLayout_2);


        gridLayout->addLayout(formLayout_3, 2, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        pushButton_ExecuteTouchoff = new QPushButton(WidgetFrontPanel_Touchoff);
        pushButton_ExecuteTouchoff->setObjectName(QStringLiteral("pushButton_ExecuteTouchoff"));
        sizePolicy.setHeightForWidth(pushButton_ExecuteTouchoff->sizePolicy().hasHeightForWidth());
        pushButton_ExecuteTouchoff->setSizePolicy(sizePolicy);
        pushButton_ExecuteTouchoff->setMinimumSize(QSize(100, 30));
        pushButton_ExecuteTouchoff->setMaximumSize(QSize(100, 30));
        pushButton_ExecuteTouchoff->setFont(font1);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, pushButton_ExecuteTouchoff);

        lineEdit_TouchoffCode = new QLineEdit(WidgetFrontPanel_Touchoff);
        lineEdit_TouchoffCode->setObjectName(QStringLiteral("lineEdit_TouchoffCode"));
        sizePolicy.setHeightForWidth(lineEdit_TouchoffCode->sizePolicy().hasHeightForWidth());
        lineEdit_TouchoffCode->setSizePolicy(sizePolicy);
        lineEdit_TouchoffCode->setMinimumSize(QSize(300, 30));
        lineEdit_TouchoffCode->setMaximumSize(QSize(300, 30));
        lineEdit_TouchoffCode->setFont(font1);
        lineEdit_TouchoffCode->setAlignment(Qt::AlignCenter);
        lineEdit_TouchoffCode->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit_TouchoffCode);


        gridLayout->addLayout(formLayout_2, 3, 0, 1, 1);


        retranslateUi(WidgetFrontPanel_Touchoff);

        QMetaObject::connectSlotsByName(WidgetFrontPanel_Touchoff);
    } // setupUi

    void retranslateUi(QWidget *WidgetFrontPanel_Touchoff)
    {
        WidgetFrontPanel_Touchoff->setWindowTitle(QApplication::translate("WidgetFrontPanel_Touchoff", "Form", nullptr));
        label_ManualControl_4->setText(QApplication::translate("WidgetFrontPanel_Touchoff", "Touchoff Configuration", nullptr));
        pushButton_TouchoffRef->setText(QApplication::translate("WidgetFrontPanel_Touchoff", "Set Touchoff Ref", nullptr));
        label->setText(QApplication::translate("WidgetFrontPanel_Touchoff", "um", nullptr));
        pushButton_TouchoffGap->setText(QApplication::translate("WidgetFrontPanel_Touchoff", "Set Initial Gap", nullptr));
        label_2->setText(QApplication::translate("WidgetFrontPanel_Touchoff", "um", nullptr));
        pushButton_ExecuteTouchoff->setText(QApplication::translate("WidgetFrontPanel_Touchoff", "Execute", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetFrontPanel_Touchoff: public Ui_WidgetFrontPanel_Touchoff {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_FRONT_PANEL_TOUCHOFF_H
