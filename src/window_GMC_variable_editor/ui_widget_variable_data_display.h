/********************************************************************************
** Form generated from reading UI file 'widget_variable_data_display.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_VARIABLE_DATA_DISPLAY_H
#define UI_WIDGET_VARIABLE_DATA_DISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_profileName;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_addVariable;
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
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
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
        label->setMaximumSize(QSize(91, 25));
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


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_addVariable = new QPushButton(WidgetVariableDataDisplay);
        pushButton_addVariable->setObjectName(QStringLiteral("pushButton_addVariable"));
        sizePolicy1.setHeightForWidth(pushButton_addVariable->sizePolicy().hasHeightForWidth());
        pushButton_addVariable->setSizePolicy(sizePolicy1);
        pushButton_addVariable->setMaximumSize(QSize(121, 25));
        pushButton_addVariable->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral("images/add_complex.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_addVariable->setIcon(icon);

        horizontalLayout_2->addWidget(pushButton_addVariable);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 620, 233));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 1, 0, 1, 1);


        retranslateUi(WidgetVariableDataDisplay);

        QMetaObject::connectSlotsByName(WidgetVariableDataDisplay);
    } // setupUi

    void retranslateUi(QWidget *WidgetVariableDataDisplay)
    {
        WidgetVariableDataDisplay->setWindowTitle(QApplication::translate("WidgetVariableDataDisplay", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("WidgetVariableDataDisplay", "Profile Name", Q_NULLPTR));
        pushButton_addVariable->setText(QApplication::translate("WidgetVariableDataDisplay", "Add Variable", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetVariableDataDisplay: public Ui_WidgetVariableDataDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_VARIABLE_DATA_DISPLAY_H
