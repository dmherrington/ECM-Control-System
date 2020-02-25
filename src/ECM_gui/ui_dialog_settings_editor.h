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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

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
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_AvailableAxis_4;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *label_AvailableAxis;
    QHBoxLayout *horizontalLayout_Available;
    QRadioButton *radioButton_XAvailable;
    QRadioButton *radioButton_YAvailable;
    QRadioButton *radioButton_ZAvailable;
    QFormLayout *formLayout_2;
    QLabel *label_IgnoreMotion;
    QHBoxLayout *horizontalLayout_Motion;
    QRadioButton *radioButton_XMotion;
    QRadioButton *radioButton_YMotion;
    QRadioButton *radioButton_ZMotion;
    QFormLayout *formLayout_3;
    QLabel *label_AvailableAxis_3;
    QHBoxLayout *horizontalLayout_Faults;
    QRadioButton *radioButton_XFault;
    QRadioButton *radioButton_YFault;
    QRadioButton *radioButton_ZFault;
    QSpacerItem *horizontalSpacer_8;
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

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(Dialog_SettingsEditor);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(130, 25));
        label_2->setMaximumSize(QSize(130, 25));
        label_2->setFont(font);

        horizontalLayout_4->addWidget(label_2);

        doubleSpinBox_plotDurationWindow = new QDoubleSpinBox(Dialog_SettingsEditor);
        doubleSpinBox_plotDurationWindow->setObjectName(QStringLiteral("doubleSpinBox_plotDurationWindow"));
        doubleSpinBox_plotDurationWindow->setMinimumSize(QSize(80, 25));
        doubleSpinBox_plotDurationWindow->setMaximumSize(QSize(80, 25));
        doubleSpinBox_plotDurationWindow->setFont(font);
        doubleSpinBox_plotDurationWindow->setAlignment(Qt::AlignCenter);
        doubleSpinBox_plotDurationWindow->setDecimals(1);
        doubleSpinBox_plotDurationWindow->setMaximum(3600);
        doubleSpinBox_plotDurationWindow->setValue(10);

        horizontalLayout_4->addWidget(doubleSpinBox_plotDurationWindow);


        horizontalLayout_3->addLayout(horizontalLayout_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        line = new QFrame(Dialog_SettingsEditor);
        line->setObjectName(QStringLiteral("line"));
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_7);

        label_AvailableAxis_4 = new QLabel(Dialog_SettingsEditor);
        label_AvailableAxis_4->setObjectName(QStringLiteral("label_AvailableAxis_4"));
        label_AvailableAxis_4->setFont(font);
        label_AvailableAxis_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label_AvailableAxis_4);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_11);


        gridLayout->addLayout(verticalLayout, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_AvailableAxis = new QLabel(Dialog_SettingsEditor);
        label_AvailableAxis->setObjectName(QStringLiteral("label_AvailableAxis"));
        label_AvailableAxis->setMinimumSize(QSize(125, 20));
        label_AvailableAxis->setMaximumSize(QSize(125, 20));
        label_AvailableAxis->setFont(font);
        label_AvailableAxis->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_AvailableAxis);

        horizontalLayout_Available = new QHBoxLayout();
        horizontalLayout_Available->setObjectName(QStringLiteral("horizontalLayout_Available"));
        radioButton_XAvailable = new QRadioButton(Dialog_SettingsEditor);
        radioButton_XAvailable->setObjectName(QStringLiteral("radioButton_XAvailable"));
        radioButton_XAvailable->setFont(font);
        radioButton_XAvailable->setLayoutDirection(Qt::LeftToRight);
        radioButton_XAvailable->setAutoExclusive(false);

        horizontalLayout_Available->addWidget(radioButton_XAvailable);

        radioButton_YAvailable = new QRadioButton(Dialog_SettingsEditor);
        radioButton_YAvailable->setObjectName(QStringLiteral("radioButton_YAvailable"));
        radioButton_YAvailable->setFont(font);
        radioButton_YAvailable->setLayoutDirection(Qt::LeftToRight);
        radioButton_YAvailable->setAutoExclusive(false);

        horizontalLayout_Available->addWidget(radioButton_YAvailable);

        radioButton_ZAvailable = new QRadioButton(Dialog_SettingsEditor);
        radioButton_ZAvailable->setObjectName(QStringLiteral("radioButton_ZAvailable"));
        radioButton_ZAvailable->setFont(font);
        radioButton_ZAvailable->setLayoutDirection(Qt::LeftToRight);
        radioButton_ZAvailable->setAutoExclusive(false);

        horizontalLayout_Available->addWidget(radioButton_ZAvailable);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_Available);


        verticalLayout_2->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_IgnoreMotion = new QLabel(Dialog_SettingsEditor);
        label_IgnoreMotion->setObjectName(QStringLiteral("label_IgnoreMotion"));
        label_IgnoreMotion->setMinimumSize(QSize(125, 20));
        label_IgnoreMotion->setMaximumSize(QSize(125, 20));
        label_IgnoreMotion->setFont(font);
        label_IgnoreMotion->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_IgnoreMotion);

        horizontalLayout_Motion = new QHBoxLayout();
        horizontalLayout_Motion->setObjectName(QStringLiteral("horizontalLayout_Motion"));
        radioButton_XMotion = new QRadioButton(Dialog_SettingsEditor);
        radioButton_XMotion->setObjectName(QStringLiteral("radioButton_XMotion"));
        radioButton_XMotion->setFont(font);
        radioButton_XMotion->setLayoutDirection(Qt::LeftToRight);
        radioButton_XMotion->setAutoExclusive(false);

        horizontalLayout_Motion->addWidget(radioButton_XMotion);

        radioButton_YMotion = new QRadioButton(Dialog_SettingsEditor);
        radioButton_YMotion->setObjectName(QStringLiteral("radioButton_YMotion"));
        radioButton_YMotion->setMinimumSize(QSize(0, 20));
        radioButton_YMotion->setMaximumSize(QSize(16777215, 20));
        radioButton_YMotion->setFont(font);
        radioButton_YMotion->setLayoutDirection(Qt::LeftToRight);
        radioButton_YMotion->setAutoExclusive(false);

        horizontalLayout_Motion->addWidget(radioButton_YMotion);

        radioButton_ZMotion = new QRadioButton(Dialog_SettingsEditor);
        radioButton_ZMotion->setObjectName(QStringLiteral("radioButton_ZMotion"));
        radioButton_ZMotion->setFont(font);
        radioButton_ZMotion->setLayoutDirection(Qt::LeftToRight);
        radioButton_ZMotion->setAutoExclusive(false);

        horizontalLayout_Motion->addWidget(radioButton_ZMotion);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, horizontalLayout_Motion);


        verticalLayout_2->addLayout(formLayout_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_AvailableAxis_3 = new QLabel(Dialog_SettingsEditor);
        label_AvailableAxis_3->setObjectName(QStringLiteral("label_AvailableAxis_3"));
        label_AvailableAxis_3->setMinimumSize(QSize(125, 20));
        label_AvailableAxis_3->setMaximumSize(QSize(125, 20));
        label_AvailableAxis_3->setFont(font);
        label_AvailableAxis_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_AvailableAxis_3);

        horizontalLayout_Faults = new QHBoxLayout();
        horizontalLayout_Faults->setObjectName(QStringLiteral("horizontalLayout_Faults"));
        radioButton_XFault = new QRadioButton(Dialog_SettingsEditor);
        radioButton_XFault->setObjectName(QStringLiteral("radioButton_XFault"));
        radioButton_XFault->setFont(font);
        radioButton_XFault->setLayoutDirection(Qt::LeftToRight);
        radioButton_XFault->setAutoExclusive(false);

        horizontalLayout_Faults->addWidget(radioButton_XFault);

        radioButton_YFault = new QRadioButton(Dialog_SettingsEditor);
        radioButton_YFault->setObjectName(QStringLiteral("radioButton_YFault"));
        radioButton_YFault->setFont(font);
        radioButton_YFault->setLayoutDirection(Qt::LeftToRight);
        radioButton_YFault->setAutoExclusive(false);

        horizontalLayout_Faults->addWidget(radioButton_YFault);

        radioButton_ZFault = new QRadioButton(Dialog_SettingsEditor);
        radioButton_ZFault->setObjectName(QStringLiteral("radioButton_ZFault"));
        radioButton_ZFault->setFont(font);
        radioButton_ZFault->setLayoutDirection(Qt::LeftToRight);
        radioButton_ZFault->setAutoExclusive(false);

        horizontalLayout_Faults->addWidget(radioButton_ZFault);


        formLayout_3->setLayout(0, QFormLayout::FieldRole, horizontalLayout_Faults);


        verticalLayout_2->addLayout(formLayout_3);


        horizontalLayout_6->addLayout(verticalLayout_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);


        gridLayout->addLayout(horizontalLayout_6, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Dialog_SettingsEditor);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 0, 1, 1);


        retranslateUi(Dialog_SettingsEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_SettingsEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_SettingsEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_SettingsEditor);
    } // setupUi

    void retranslateUi(QDialog *Dialog_SettingsEditor)
    {
        Dialog_SettingsEditor->setWindowTitle(QApplication::translate("Dialog_SettingsEditor", "ECM General Settings", nullptr));
        label->setText(QApplication::translate("Dialog_SettingsEditor", "Alarm Thermocouple 1", nullptr));
        label_2->setText(QApplication::translate("Dialog_SettingsEditor", "Plot Window Duration", nullptr));
        label_AvailableAxis_4->setText(QApplication::translate("Dialog_SettingsEditor", "Axis Settings:", nullptr));
        label_AvailableAxis->setText(QApplication::translate("Dialog_SettingsEditor", "Available:", nullptr));
        radioButton_XAvailable->setText(QApplication::translate("Dialog_SettingsEditor", "X", nullptr));
        radioButton_YAvailable->setText(QApplication::translate("Dialog_SettingsEditor", "Y", nullptr));
        radioButton_ZAvailable->setText(QApplication::translate("Dialog_SettingsEditor", "Z", nullptr));
        label_IgnoreMotion->setText(QApplication::translate("Dialog_SettingsEditor", "Ignore Motion Check:", nullptr));
        radioButton_XMotion->setText(QApplication::translate("Dialog_SettingsEditor", "X", nullptr));
        radioButton_YMotion->setText(QApplication::translate("Dialog_SettingsEditor", "Y", nullptr));
        radioButton_ZMotion->setText(QApplication::translate("Dialog_SettingsEditor", "Z", nullptr));
        label_AvailableAxis_3->setText(QApplication::translate("Dialog_SettingsEditor", "Ignore Faults:", nullptr));
        radioButton_XFault->setText(QApplication::translate("Dialog_SettingsEditor", "X", nullptr));
        radioButton_YFault->setText(QApplication::translate("Dialog_SettingsEditor", "Y", nullptr));
        radioButton_ZFault->setText(QApplication::translate("Dialog_SettingsEditor", "Z", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_SettingsEditor: public Ui_Dialog_SettingsEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SETTINGS_EDITOR_H
