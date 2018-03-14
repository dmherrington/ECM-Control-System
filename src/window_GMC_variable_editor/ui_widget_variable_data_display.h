/********************************************************************************
** Form generated from reading UI file 'widget_variable_data_display.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_VARIABLE_DATA_DISPLAY_H
#define UI_WIDGET_VARIABLE_DATA_DISPLAY_H

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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetVariableDataDisplay
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_ProfileName;
    QLineEdit *lineEdit_profileName;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_ProfileLabel;
    QLineEdit *lineEdit_profileLabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_addVariable;
    QHBoxLayout *horizontalLayout_2;
    QFormLayout *formLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_PGain;
    QFormLayout *formLayout_2;
    QLabel *label_IGain;
    QDoubleSpinBox *doubleSpinBox_IGain;
    QFormLayout *formLayout;
    QLabel *label_DGain;
    QDoubleSpinBox *doubleSpinBox_DGain;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *WidgetVariableDataDisplay)
    {
        if (WidgetVariableDataDisplay->objectName().isEmpty())
            WidgetVariableDataDisplay->setObjectName(QStringLiteral("WidgetVariableDataDisplay"));
        WidgetVariableDataDisplay->resize(640, 286);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetVariableDataDisplay->sizePolicy().hasHeightForWidth());
        WidgetVariableDataDisplay->setSizePolicy(sizePolicy);
        WidgetVariableDataDisplay->setMinimumSize(QSize(640, 0));
        gridLayout_2 = new QGridLayout(WidgetVariableDataDisplay);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_ProfileName = new QLabel(WidgetVariableDataDisplay);
        label_ProfileName->setObjectName(QStringLiteral("label_ProfileName"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_ProfileName->sizePolicy().hasHeightForWidth());
        label_ProfileName->setSizePolicy(sizePolicy1);
        label_ProfileName->setMaximumSize(QSize(100, 25));
        QFont font;
        font.setPointSize(12);
        label_ProfileName->setFont(font);
        label_ProfileName->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_ProfileName);

        lineEdit_profileName = new QLineEdit(WidgetVariableDataDisplay);
        lineEdit_profileName->setObjectName(QStringLiteral("lineEdit_profileName"));
        sizePolicy1.setHeightForWidth(lineEdit_profileName->sizePolicy().hasHeightForWidth());
        lineEdit_profileName->setSizePolicy(sizePolicy1);
        lineEdit_profileName->setMaximumSize(QSize(180, 25));
        QFont font1;
        font1.setPointSize(10);
        lineEdit_profileName->setFont(font1);
        lineEdit_profileName->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit_profileName);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_ProfileLabel = new QLabel(WidgetVariableDataDisplay);
        label_ProfileLabel->setObjectName(QStringLiteral("label_ProfileLabel"));
        sizePolicy1.setHeightForWidth(label_ProfileLabel->sizePolicy().hasHeightForWidth());
        label_ProfileLabel->setSizePolicy(sizePolicy1);
        label_ProfileLabel->setMaximumSize(QSize(100, 25));
        label_ProfileLabel->setFont(font);
        label_ProfileLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_ProfileLabel);

        lineEdit_profileLabel = new QLineEdit(WidgetVariableDataDisplay);
        lineEdit_profileLabel->setObjectName(QStringLiteral("lineEdit_profileLabel"));
        sizePolicy1.setHeightForWidth(lineEdit_profileLabel->sizePolicy().hasHeightForWidth());
        lineEdit_profileLabel->setSizePolicy(sizePolicy1);
        lineEdit_profileLabel->setMaximumSize(QSize(180, 25));
        lineEdit_profileLabel->setFont(font1);
        lineEdit_profileLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lineEdit_profileLabel);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pushButton_addVariable = new QPushButton(WidgetVariableDataDisplay);
        pushButton_addVariable->setObjectName(QStringLiteral("pushButton_addVariable"));
        sizePolicy1.setHeightForWidth(pushButton_addVariable->sizePolicy().hasHeightForWidth());
        pushButton_addVariable->setSizePolicy(sizePolicy1);
        pushButton_addVariable->setMaximumSize(QSize(121, 25));
        pushButton_addVariable->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral("images/add_complex.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_addVariable->setIcon(icon);

        horizontalLayout_4->addWidget(pushButton_addVariable);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_2 = new QLabel(WidgetVariableDataDisplay);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMaximumSize(QSize(60, 25));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_2);

        doubleSpinBox_PGain = new QDoubleSpinBox(WidgetVariableDataDisplay);
        doubleSpinBox_PGain->setObjectName(QStringLiteral("doubleSpinBox_PGain"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_PGain->sizePolicy().hasHeightForWidth());
        doubleSpinBox_PGain->setSizePolicy(sizePolicy1);
        doubleSpinBox_PGain->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_PGain->setMaximum(1000);
        doubleSpinBox_PGain->setValue(0);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_PGain);


        horizontalLayout_2->addLayout(formLayout_3);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_IGain = new QLabel(WidgetVariableDataDisplay);
        label_IGain->setObjectName(QStringLiteral("label_IGain"));
        sizePolicy1.setHeightForWidth(label_IGain->sizePolicy().hasHeightForWidth());
        label_IGain->setSizePolicy(sizePolicy1);
        label_IGain->setMaximumSize(QSize(60, 25));
        label_IGain->setFont(font);
        label_IGain->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_IGain);

        doubleSpinBox_IGain = new QDoubleSpinBox(WidgetVariableDataDisplay);
        doubleSpinBox_IGain->setObjectName(QStringLiteral("doubleSpinBox_IGain"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_IGain->sizePolicy().hasHeightForWidth());
        doubleSpinBox_IGain->setSizePolicy(sizePolicy1);
        doubleSpinBox_IGain->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_IGain->setMaximum(1000);
        doubleSpinBox_IGain->setValue(0);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_IGain);


        horizontalLayout_2->addLayout(formLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_DGain = new QLabel(WidgetVariableDataDisplay);
        label_DGain->setObjectName(QStringLiteral("label_DGain"));
        sizePolicy1.setHeightForWidth(label_DGain->sizePolicy().hasHeightForWidth());
        label_DGain->setSizePolicy(sizePolicy1);
        label_DGain->setMaximumSize(QSize(60, 25));
        label_DGain->setFont(font);
        label_DGain->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_DGain);

        doubleSpinBox_DGain = new QDoubleSpinBox(WidgetVariableDataDisplay);
        doubleSpinBox_DGain->setObjectName(QStringLiteral("doubleSpinBox_DGain"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_DGain->sizePolicy().hasHeightForWidth());
        doubleSpinBox_DGain->setSizePolicy(sizePolicy1);
        doubleSpinBox_DGain->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_DGain->setMaximum(1000);
        doubleSpinBox_DGain->setValue(0);

        formLayout->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_DGain);


        horizontalLayout_2->addLayout(formLayout);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        scrollArea = new QScrollArea(WidgetVariableDataDisplay);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy2);
        scrollArea->setMinimumSize(QSize(600, 0));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 620, 203));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 2, 0, 1, 1);


        retranslateUi(WidgetVariableDataDisplay);

        QMetaObject::connectSlotsByName(WidgetVariableDataDisplay);
    } // setupUi

    void retranslateUi(QWidget *WidgetVariableDataDisplay)
    {
        WidgetVariableDataDisplay->setWindowTitle(QApplication::translate("WidgetVariableDataDisplay", "Form", nullptr));
        label_ProfileName->setText(QApplication::translate("WidgetVariableDataDisplay", " Profile Name", nullptr));
        label_ProfileLabel->setText(QApplication::translate("WidgetVariableDataDisplay", " Profile Label", nullptr));
        pushButton_addVariable->setText(QApplication::translate("WidgetVariableDataDisplay", "Add Variable", nullptr));
        label_2->setText(QApplication::translate("WidgetVariableDataDisplay", "PGain", nullptr));
        label_IGain->setText(QApplication::translate("WidgetVariableDataDisplay", "IGain", nullptr));
        label_DGain->setText(QApplication::translate("WidgetVariableDataDisplay", "DGain", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetVariableDataDisplay: public Ui_WidgetVariableDataDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_VARIABLE_DATA_DISPLAY_H
