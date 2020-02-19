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

    double plotting_timeout = settings.value("plotting_duration", false).toDouble();
    ui->doubleSpinBox_plotDurationWindow->setValue(plotting_timeout);

    bool isXAvailable = settings.value("availableAxis_X", false).toBool();
    ui->radioButton_X->setChecked(isXAvailable);
    bool isYAvailable = settings.value("availableAxis_X", false).toBool();
    ui->radioButton_Y->setChecked(isYAvailable);
    bool isZAvailable = settings.value("availableAxis_X", false).toBool();
    ui->radioButton_Z->setChecked(isZAvailable);
}

void Dialog_SettingsEditor::closeEvent(QCloseEvent *event)
{
        event->accept();
}

void Dialog_SettingsEditor::slot_EventAccepted()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,"ECMController", "Alarm Settings");

    settings.setValue("alarm_thermocouple1",ui->doubleSpinBox_alarmThermocouple1->value());
    settings.setValue("plotting_duration",ui->doubleSpinBox_plotDurationWindow->value());

    settings.setValue("availableAxis_X",ui->radioButton_Z->isChecked());
    settings.setValue("availableAxis_Y",ui->radioButton_Z->isChecked());
    settings.setValue("availableAxis_Z",ui->radioButton_Z->isChecked());

    settings.sync();
}

double Dialog_SettingsEditor::getPlottingDuration() const
{
    return ui->doubleSpinBox_plotDurationWindow->value();
}

std::vector<MotorAxis> Dialog_SettingsEditor::whichAxesAreAvailable() const
{
    std::vector<MotorAxis> rtnAxis;
    if(ui->radioButton_X->isChecked())
        rtnAxis.push_back(MotorAxis::X);
    if(ui->radioButton_Y->isChecked())
        rtnAxis.push_back(MotorAxis::Y);
    if(ui->radioButton_Z->isChecked())
        rtnAxis.push_back(MotorAxis::Z);


}
