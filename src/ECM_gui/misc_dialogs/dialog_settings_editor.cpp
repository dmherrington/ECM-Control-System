#include "dialog_settings_editor.h"
#include "ui_dialog_settings_editor.h"

Dialog_SettingsEditor::Dialog_SettingsEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_SettingsEditor)
{
    ui->setupUi(this);

    this->readSettings();
    connect(this, SIGNAL(accepted()), this, SLOT(slot_EventAccepted()));

}

Dialog_SettingsEditor::~Dialog_SettingsEditor()
{
    delete ui;
}

void Dialog_SettingsEditor::readSettings()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "ECMController", "Alarm Settings");

    double alarmValue_thermocouple1 = settings.value("alarm_thermocouple1", false).toDouble();
    ui->doubleSpinBox_alarmThermocouple1->setValue(alarmValue_thermocouple1);

    double plotting_timeout = settings.value("plotting_timeout", false).toDouble();
    ui->doubleSpinBox_PlotClearingTimeout->setValue(plotting_timeout);
}

void Dialog_SettingsEditor::closeEvent(QCloseEvent *event)
{
        event->accept();
}

void Dialog_SettingsEditor::slot_EventAccepted()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,"ECMController", "Alarm Settings");

    settings.setValue("alarm_thermocouple1",ui->doubleSpinBox_alarmThermocouple1->value());
    settings.setValue("plotting_timeout",ui->doubleSpinBox_PlotClearingTimeout->value());
    settings.sync();
}

double Dialog_SettingsEditor::getPlottingTimeout() const
{
    return ui->doubleSpinBox_PlotClearingTimeout->value();
}