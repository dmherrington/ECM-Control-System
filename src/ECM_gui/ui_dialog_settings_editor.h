/********************************************************************************
** Form generated from reading UI file 'dialog_settings_editor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SETTINGS_EDITOR_H
#define UI_DIALOG_SETTINGS_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Dialog_SettingsEditor
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_alarmThermocouple1;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_plotDurationWindow;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_AvailableAxis;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioButton_X;
    QRadioButton *radioButton_Y;
    QRadioButton *radioButton_Z;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_SettingsEditor)
    {
        if (Dialog_SettingsEditor->objectName().isEmpty())
            Dialog_SettingsEditor->setObjectName(QString::fromUtf8("Dialog_SettingsEditor"));
        Dialog_SettingsEditor->resize(400, 300);
        gridLayout = new QGridLayout(Dialog_SettingsEditor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Dialog_SettingsEditor);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(130, 25));
        label->setMaximumSize(QSize(130, 25));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        doubleSpinBox_alarmThermocouple1 = new QDoubleSpinBox(Dialog_SettingsEditor);
        doubleSpinBox_alarmThermocouple1->setObjectName(QString::fromUtf8("doubleSpinBox_alarmThermocouple1"));
        doubleSpinBox_alarmThermocouple1->setMinimumSize(QSize(80, 25));
        doubleSpinBox_alarmThermocouple1->setMaximumSize(QSize(80, 25));
        doubleSpinBox_alarmThermocouple1->setFont(font);
        doubleSpinBox_alarmThermocouple1->setMaximum(200.000000000000000);

        horizontalLayout->addWidget(doubleSpinBox_alarmThermocouple1);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(Dialog_SettingsEditor);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(130, 25));
        label_2->setMaximumSize(QSize(130, 25));
        label_2->setFont(font);

        horizontalLayout_4->addWidget(label_2);

        doubleSpinBox_plotDurationWindow = new QDoubleSpinBox(Dialog_SettingsEditor);
        doubleSpinBox_plotDurationWindow->setObjectName(QString::fromUtf8("doubleSpinBox_plotDurationWindow"));
        doubleSpinBox_plotDurationWindow->setMinimumSize(QSize(80, 25));
        doubleSpinBox_plotDurationWindow->setMaximumSize(QSize(80, 25));
        doubleSpinBox_plotDurationWindow->setFont(font);
        doubleSpinBox_plotDurationWindow->setAlignment(Qt::AlignCenter);
        doubleSpinBox_plotDurationWindow->setDecimals(1);
        doubleSpinBox_plotDurationWindow->setMaximum(3600.000000000000000);
        doubleSpinBox_plotDurationWindow->setValue(10.000000000000000);

        horizontalLayout_4->addWidget(doubleSpinBox_plotDurationWindow);


        horizontalLayout_3->addLayout(horizontalLayout_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_AvailableAxis = new QLabel(Dialog_SettingsEditor);
        label_AvailableAxis->setObjectName(QString::fromUtf8("label_AvailableAxis"));
        label_AvailableAxis->setFont(font);
        label_AvailableAxis->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_AvailableAxis);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        radioButton_X = new QRadioButton(Dialog_SettingsEditor);
        radioButton_X->setObjectName(QString::fromUtf8("radioButton_X"));
        radioButton_X->setFont(font);
        radioButton_X->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_5->addWidget(radioButton_X);

        radioButton_Y = new QRadioButton(Dialog_SettingsEditor);
        radioButton_Y->setObjectName(QString::fromUtf8("radioButton_Y"));
        radioButton_Y->setFont(font);
        radioButton_Y->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_5->addWidget(radioButton_Y);

        radioButton_Z = new QRadioButton(Dialog_SettingsEditor);
        radioButton_Z->setObjectName(QString::fromUtf8("radioButton_Z"));
        radioButton_Z->setFont(font);
        radioButton_Z->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_5->addWidget(radioButton_Z);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_6, 2, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Dialog_SettingsEditor);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 1, 1, 1);


        retranslateUi(Dialog_SettingsEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_SettingsEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_SettingsEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_SettingsEditor);
    } // setupUi

    void retranslateUi(QDialog *Dialog_SettingsEditor)
    {
        Dialog_SettingsEditor->setWindowTitle(QApplication::translate("Dialog_SettingsEditor", "Dialog", nullptr));
        label->setText(QApplication::translate("Dialog_SettingsEditor", "Alarm Thermocouple 1", nullptr));
        label_2->setText(QApplication::translate("Dialog_SettingsEditor", "Plot Window Duration", nullptr));
        label_AvailableAxis->setText(QApplication::translate("Dialog_SettingsEditor", "Available Axis:", nullptr));
        radioButton_X->setText(QApplication::translate("Dialog_SettingsEditor", "X", nullptr));
        radioButton_Y->setText(QApplication::translate("Dialog_SettingsEditor", "Y", nullptr));
        radioButton_Z->setText(QApplication::translate("Dialog_SettingsEditor", "Z", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_SettingsEditor: public Ui_Dialog_SettingsEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SETTINGS_EDITOR_H
