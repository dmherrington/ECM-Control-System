/********************************************************************************
** Form generated from reading UI file 'dialog_settings_editor.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SETTINGS_EDITOR_H
#define UI_DIALOG_SETTINGS_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_SettingsEditor)
    {
        if (Dialog_SettingsEditor->objectName().isEmpty())
            Dialog_SettingsEditor->setObjectName(QStringLiteral("Dialog_SettingsEditor"));
        Dialog_SettingsEditor->resize(400, 300);
        gridLayout = new QGridLayout(Dialog_SettingsEditor);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Dialog_SettingsEditor);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(130, 25));
        label->setMaximumSize(QSize(130, 25));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        doubleSpinBox_alarmThermocouple1 = new QDoubleSpinBox(Dialog_SettingsEditor);
        doubleSpinBox_alarmThermocouple1->setObjectName(QStringLiteral("doubleSpinBox_alarmThermocouple1"));
        doubleSpinBox_alarmThermocouple1->setMinimumSize(QSize(80, 25));
        doubleSpinBox_alarmThermocouple1->setMaximumSize(QSize(80, 25));
        doubleSpinBox_alarmThermocouple1->setFont(font);
        doubleSpinBox_alarmThermocouple1->setMaximum(200);

        horizontalLayout->addWidget(doubleSpinBox_alarmThermocouple1);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 215, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Dialog_SettingsEditor);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(Dialog_SettingsEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_SettingsEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_SettingsEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_SettingsEditor);
    } // setupUi

    void retranslateUi(QDialog *Dialog_SettingsEditor)
    {
        Dialog_SettingsEditor->setWindowTitle(QApplication::translate("Dialog_SettingsEditor", "Dialog", nullptr));
        label->setText(QApplication::translate("Dialog_SettingsEditor", "Alarm Thermocouple 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_SettingsEditor: public Ui_Dialog_SettingsEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SETTINGS_EDITOR_H
