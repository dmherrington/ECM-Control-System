/********************************************************************************
** Form generated from reading UI file 'widget_sofware_versioning.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_SOFWARE_VERSIONING_H
#define UI_WIDGET_SOFWARE_VERSIONING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_SofwareVersioning
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_libraryName;
    QLineEdit *lineEdit_version;

    void setupUi(QWidget *Widget_SofwareVersioning)
    {
        if (Widget_SofwareVersioning->objectName().isEmpty())
            Widget_SofwareVersioning->setObjectName(QString::fromUtf8("Widget_SofwareVersioning"));
        Widget_SofwareVersioning->resize(330, 25);
        Widget_SofwareVersioning->setMinimumSize(QSize(330, 25));
        Widget_SofwareVersioning->setMaximumSize(QSize(330, 25));
        gridLayout = new QGridLayout(Widget_SofwareVersioning);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 1, 1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_libraryName = new QLabel(Widget_SofwareVersioning);
        label_libraryName->setObjectName(QString::fromUtf8("label_libraryName"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_libraryName->sizePolicy().hasHeightForWidth());
        label_libraryName->setSizePolicy(sizePolicy);
        label_libraryName->setMinimumSize(QSize(200, 20));
        label_libraryName->setMaximumSize(QSize(200, 20));
        QFont font;
        font.setPointSize(12);
        label_libraryName->setFont(font);
        label_libraryName->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_libraryName);

        lineEdit_version = new QLineEdit(Widget_SofwareVersioning);
        lineEdit_version->setObjectName(QString::fromUtf8("lineEdit_version"));
        sizePolicy.setHeightForWidth(lineEdit_version->sizePolicy().hasHeightForWidth());
        lineEdit_version->setSizePolicy(sizePolicy);
        lineEdit_version->setMinimumSize(QSize(120, 20));
        lineEdit_version->setMaximumSize(QSize(120, 20));
        lineEdit_version->setFont(font);
        lineEdit_version->setAlignment(Qt::AlignCenter);
        lineEdit_version->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit_version);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Widget_SofwareVersioning);

        QMetaObject::connectSlotsByName(Widget_SofwareVersioning);
    } // setupUi

    void retranslateUi(QWidget *Widget_SofwareVersioning)
    {
        Widget_SofwareVersioning->setWindowTitle(QApplication::translate("Widget_SofwareVersioning", "Form", nullptr));
        label_libraryName->setText(QApplication::translate("Widget_SofwareVersioning", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_SofwareVersioning: public Ui_Widget_SofwareVersioning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SOFWARE_VERSIONING_H
