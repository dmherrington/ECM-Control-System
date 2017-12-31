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
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_profileName;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_addVariable;
    QHBoxLayout *horizontalLayout_2;
    QFormLayout *formLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QFormLayout *formLayout;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_3;
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
        WidgetVariableDataDisplay->setMinimumSize(QSize(620, 0));
        gridLayout_2 = new QGridLayout(WidgetVariableDataDisplay);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(WidgetVariableDataDisplay);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(100, 25));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

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


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_addVariable = new QPushButton(WidgetVariableDataDisplay);
        pushButton_addVariable->setObjectName(QStringLiteral("pushButton_addVariable"));
        sizePolicy1.setHeightForWidth(pushButton_addVariable->sizePolicy().hasHeightForWidth());
        pushButton_addVariable->setSizePolicy(sizePolicy1);
        pushButton_addVariable->setMaximumSize(QSize(121, 25));
        pushButton_addVariable->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral("images/add_complex.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_addVariable->setIcon(icon);

        horizontalLayout_3->addWidget(pushButton_addVariable);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

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

        doubleSpinBox = new QDoubleSpinBox(WidgetVariableDataDisplay);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        sizePolicy1.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy1);
        doubleSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox->setMaximum(1000);
        doubleSpinBox->setValue(0);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, doubleSpinBox);


        horizontalLayout_2->addLayout(formLayout_3);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_3 = new QLabel(WidgetVariableDataDisplay);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMaximumSize(QSize(60, 25));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        doubleSpinBox_2 = new QDoubleSpinBox(WidgetVariableDataDisplay);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_2->sizePolicy().hasHeightForWidth());
        doubleSpinBox_2->setSizePolicy(sizePolicy1);
        doubleSpinBox_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_2->setMaximum(1000);
        doubleSpinBox_2->setValue(0);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_2);


        horizontalLayout_2->addLayout(formLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_4 = new QLabel(WidgetVariableDataDisplay);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMaximumSize(QSize(60, 25));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        doubleSpinBox_3 = new QDoubleSpinBox(WidgetVariableDataDisplay);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_3->sizePolicy().hasHeightForWidth());
        doubleSpinBox_3->setSizePolicy(sizePolicy1);
        doubleSpinBox_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_3->setMaximum(1000);
        doubleSpinBox_3->setValue(0);

        formLayout->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_3);


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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 620, 197));
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
        label->setText(QApplication::translate("WidgetVariableDataDisplay", " Profile Name", nullptr));
        pushButton_addVariable->setText(QApplication::translate("WidgetVariableDataDisplay", "Add Variable", nullptr));
        label_2->setText(QApplication::translate("WidgetVariableDataDisplay", "PGain", nullptr));
        label_3->setText(QApplication::translate("WidgetVariableDataDisplay", "IGain", nullptr));
        label_4->setText(QApplication::translate("WidgetVariableDataDisplay", "DGain", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetVariableDataDisplay: public Ui_WidgetVariableDataDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_VARIABLE_DATA_DISPLAY_H
