/********************************************************************************
** Form generated from reading UI file 'widget_profile_display.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_PROFILE_DISPLAY_H
#define UI_WIDGET_PROFILE_DISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetProfileDisplay
{
public:
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_Variables;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_PGain;
    QFormLayout *formLayout_2;
    QLabel *label_IGain;
    QDoubleSpinBox *doubleSpinBox_IGain;
    QFormLayout *formLayout;
    QLabel *label_DGain;
    QDoubleSpinBox *doubleSpinBox_DGain;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *WidgetProfileDisplay)
    {
        if (WidgetProfileDisplay->objectName().isEmpty())
            WidgetProfileDisplay->setObjectName(QStringLiteral("WidgetProfileDisplay"));
        WidgetProfileDisplay->resize(408, 311);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetProfileDisplay->sizePolicy().hasHeightForWidth());
        WidgetProfileDisplay->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(WidgetProfileDisplay);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        scrollArea = new QScrollArea(WidgetProfileDisplay);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMinimumSize(QSize(240, 0));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 238, 291));
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_Variables = new QVBoxLayout();
        verticalLayout_Variables->setSpacing(4);
        verticalLayout_Variables->setObjectName(QStringLiteral("verticalLayout_Variables"));
        verticalLayout_Variables->setSizeConstraint(QLayout::SetDefaultConstraint);

        gridLayout->addLayout(verticalLayout_Variables, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 2, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_2 = new QLabel(WidgetProfileDisplay);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(60, 25));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_2);

        doubleSpinBox_PGain = new QDoubleSpinBox(WidgetProfileDisplay);
        doubleSpinBox_PGain->setObjectName(QStringLiteral("doubleSpinBox_PGain"));
        doubleSpinBox_PGain->setEnabled(false);
        sizePolicy.setHeightForWidth(doubleSpinBox_PGain->sizePolicy().hasHeightForWidth());
        doubleSpinBox_PGain->setSizePolicy(sizePolicy);
        doubleSpinBox_PGain->setFont(font);
        doubleSpinBox_PGain->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_PGain->setMaximum(1000);
        doubleSpinBox_PGain->setValue(0);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_PGain);


        verticalLayout->addLayout(formLayout_3);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_IGain = new QLabel(WidgetProfileDisplay);
        label_IGain->setObjectName(QStringLiteral("label_IGain"));
        sizePolicy.setHeightForWidth(label_IGain->sizePolicy().hasHeightForWidth());
        label_IGain->setSizePolicy(sizePolicy);
        label_IGain->setMaximumSize(QSize(60, 25));
        label_IGain->setFont(font);
        label_IGain->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_IGain);

        doubleSpinBox_IGain = new QDoubleSpinBox(WidgetProfileDisplay);
        doubleSpinBox_IGain->setObjectName(QStringLiteral("doubleSpinBox_IGain"));
        doubleSpinBox_IGain->setEnabled(false);
        sizePolicy.setHeightForWidth(doubleSpinBox_IGain->sizePolicy().hasHeightForWidth());
        doubleSpinBox_IGain->setSizePolicy(sizePolicy);
        doubleSpinBox_IGain->setFont(font);
        doubleSpinBox_IGain->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_IGain->setMaximum(1000);
        doubleSpinBox_IGain->setValue(0);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_IGain);


        verticalLayout->addLayout(formLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_DGain = new QLabel(WidgetProfileDisplay);
        label_DGain->setObjectName(QStringLiteral("label_DGain"));
        sizePolicy.setHeightForWidth(label_DGain->sizePolicy().hasHeightForWidth());
        label_DGain->setSizePolicy(sizePolicy);
        label_DGain->setMaximumSize(QSize(60, 25));
        label_DGain->setFont(font);
        label_DGain->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_DGain);

        doubleSpinBox_DGain = new QDoubleSpinBox(WidgetProfileDisplay);
        doubleSpinBox_DGain->setObjectName(QStringLiteral("doubleSpinBox_DGain"));
        doubleSpinBox_DGain->setEnabled(false);
        sizePolicy.setHeightForWidth(doubleSpinBox_DGain->sizePolicy().hasHeightForWidth());
        doubleSpinBox_DGain->setSizePolicy(sizePolicy);
        doubleSpinBox_DGain->setFont(font);
        doubleSpinBox_DGain->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_DGain->setMaximum(1000);
        doubleSpinBox_DGain->setValue(0);

        formLayout->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_DGain);


        verticalLayout->addLayout(formLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 186, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 1, 1, 1);


        retranslateUi(WidgetProfileDisplay);

        QMetaObject::connectSlotsByName(WidgetProfileDisplay);
    } // setupUi

    void retranslateUi(QWidget *WidgetProfileDisplay)
    {
        WidgetProfileDisplay->setWindowTitle(QApplication::translate("WidgetProfileDisplay", "Form", nullptr));
        label_2->setText(QApplication::translate("WidgetProfileDisplay", "PGain", nullptr));
        label_IGain->setText(QApplication::translate("WidgetProfileDisplay", "IGain  ", nullptr));
        label_DGain->setText(QApplication::translate("WidgetProfileDisplay", "DGain", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetProfileDisplay: public Ui_WidgetProfileDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_PROFILE_DISPLAY_H
