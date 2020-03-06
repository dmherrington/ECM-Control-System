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
    ui->radioButton_XAvailable->setChecked(isXAvailable);
    bool isYAvailable = settings.value("availableAxis_Y", false).toBool();
    ui->radioButton_YAvailable->setChecked(isYAvailable);
    bool isZAvailable = settings.value("availableAxis_Z", true).toBool();
    ui->radioButton_ZAvailable->setChecked(isZAvailable);

    bool ignoreXMotion = settings.value("ignoreMotion_X", false).toBool();
    ui->radioButton_XMotion->setChecked(ignoreXMotion);
    bool ignoreYMotion = settings.value("ignoreMotion_Y", false).toBool();
    ui->radioButton_YMotion->setChecked(ignoreYMotion);
    bool ignoreZMotion = settings.value("ignoreMotion_Z", false).toBool();
    ui->radioButton_ZMotion->setChecked(ignoreZMotion);

    bool ignoreXFaults = settings.value("ignoreFaults_X", false).toBool();
    ui->radioButton_XFault->setChecked(ignoreXFaults);
    bool ignoreYFaults = settings.value("ignoreFaults_Y", false).toBool();
    ui->radioButton_YFault->setChecked(ignoreYFaults);
    bool ignoreZFaults = settings.value("ignoreFaults_Z", false).toBool();
    ui->radioButton_ZFault->setChecked(ignoreZFaults);
}

void Dialog_SettingsEditor::closeEvent(QCloseEvent *event)
{
        event->accept();
}

void Dialog_SettingsEditor::on_radioButton_XAvailable_released()
{
    bool available = ui->radioButton_XAvailable->isChecked();
    if(available == false)
    {
        ui->radioButton_XFault->setChecked(available);
        ui->radioButton_XMotion->setChecked(available);
    }

    ui->radioButton_XFault->setCheckable(available);
    ui->radioButton_XMotion->setCheckable(available);
}

void Dialog_SettingsEditor::on_radioButton_YAvailable_released()
{
    bool available = ui->radioButton_YAvailable->isChecked();
    if(available == false)
    {
        ui->radioButton_YMotion->setChecked(available);
        ui->radioButton_YFault->setChecked(available);
    }

    ui->radioButton_YFault->setCheckable(available);
    ui->radioButton_YMotion->setCheckable(available);
}

void Dialog_SettingsEditor::on_radioButton_ZAvailable_released()
{
    bool available = ui->radioButton_ZAvailable->isChecked();
    if(available == false)
    {
        ui->radioButton_ZFault->setChecked(available);
        ui->radioButton_ZMotion->setChecked(available);
    }

    ui->radioButton_ZFault->setCheckable(available);
    ui->radioButton_ZMotion->setCheckable(available);
}

void Dialog_SettingsEditor::slot_EventAccepted()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,"ECMController", "Alarm Settings");

    settings.setValue("alarm_thermocouple1",ui->doubleSpinBox_alarmThermocouple1->value());
    settings.setValue("plotting_duration",ui->doubleSpinBox_plotDurationWindow->value());

    settings.setValue("availableAxis_X",ui->radioButton_XAvailable->isChecked());
    settings.setValue("availableAxis_Y",ui->radioButton_YAvailable->isChecked());
    settings.setValue("availableAxis_Z",ui->radioButton_ZAvailable->isChecked());

    settings.setValue("ignoreMotion_X",ui->radioButton_XMotion->isChecked());
    settings.setValue("ignoreMotion_Y",ui->radioButton_YMotion->isChecked());
    settings.setValue("ignoreMotion_Z",ui->radioButton_ZMotion->isChecked());

    settings.setValue("ignoreFaults_X",ui->radioButton_XFault->isChecked());
    settings.setValue("ignoreFaults_Y",ui->radioButton_YFault->isChecked());
    settings.setValue("ignoreFaults_Z",ui->radioButton_ZFault->isChecked());

    settings.sync();
}

double Dialog_SettingsEditor::getPlottingDuration() const
{
    return ui->doubleSpinBox_plotDurationWindow->value();
}

AxisSettings Dialog_SettingsEditor::getCurrentAxisSettings() const
{
    AxisSettings currentSettings;
    currentSettings.updateAvilableAxes(whichAxesAreAvailable());
    currentSettings.updateIgnoredFaults(ignoreWhichAxisFaults());
    currentSettings.updateIgnoredMotion(ignoreWhichAxisMotion());
    return currentSettings;
}

std::vector<MotorAxis> Dialog_SettingsEditor::whichAxesAreAvailable() const
{
    std::vector<MotorAxis> rtnAxis;
    if(ui->radioButton_XAvailable->isChecked())
        rtnAxis.push_back(MotorAxis::X);
    if(ui->radioButton_YAvailable->isChecked())
        rtnAxis.push_back(MotorAxis::Y);
    if(ui->radioButton_ZAvailable->isChecked())
        rtnAxis.push_back(MotorAxis::Z);

    return rtnAxis;
}

std::vector<MotorAxis> Dialog_SettingsEditor::ignoreWhichAxisMotion() const
{
    std::vector<MotorAxis> rtnAxis;
    if(ui->radioButton_XMotion->isChecked())
        rtnAxis.push_back(MotorAxis::X);
    if(ui->radioButton_YMotion->isChecked())
        rtnAxis.push_back(MotorAxis::Y);
    if(ui->radioButton_ZMotion->isChecked())
        rtnAxis.push_back(MotorAxis::Z);

    return rtnAxis;
}

std::vector<MotorAxis> Dialog_SettingsEditor::ignoreWhichAxisFaults() const
{
    std::vector<MotorAxis> rtnAxis;
    if(ui->radioButton_XFault->isChecked())
        rtnAxis.push_back(MotorAxis::X);
    if(ui->radioButton_YFault->isChecked())
        rtnAxis.push_back(MotorAxis::Y);
    if(ui->radioButton_ZFault->isChecked())
        rtnAxis.push_back(MotorAxis::Z);

    return rtnAxis;
}
