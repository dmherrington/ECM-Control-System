#include "widget_pause_parameters.h"
#include "ui_widget_pause_parameters.h"

Widget_PauseParameters::Widget_PauseParameters(QWidget *parent) :
    Widget_AbstractProfile(ProfileOpType::PAUSE,0,parent),
    ui(new Ui::Widget_PauseParameters)
{
    ui->setupUi(this);
}

Widget_PauseParameters::~Widget_PauseParameters()
{
    delete ui;
}

void Widget_PauseParameters::on_radioButton_infinite_toggled(bool checked)
{
    ui->doubleSpinBox_duration->setValue(0);

    if(checked)
        ui->doubleSpinBox_duration->setEnabled(false);
    else
        ui->doubleSpinBox_duration->setEnabled(true);
}

void Widget_PauseParameters::on_radioButton_finite_toggled(bool checked)
{
    if(checked)
        ui->doubleSpinBox_duration->setEnabled(true);
    else
        ui->doubleSpinBox_duration->setEnabled(false);
}

ECMCommand_AbstractProfileConfigPtr Widget_PauseParameters::getCurrentProfileConfiguration() const
{
    ECMCommand_ProfilePausePtr currentConfiguration = std::make_shared<ECMCommand_ProfilePause>();
    currentConfiguration->setPauseDuration(static_cast<unsigned int>(ui->doubleSpinBox_duration->value()));
    if(ui->radioButton_finite->isChecked())
        currentConfiguration->setPauseType(ECMCommand_ProfilePause::WaitType::FINITE);
    else
        currentConfiguration->setPauseType(ECMCommand_ProfilePause::WaitType::INF);

    currentConfiguration->m_PumpParameters.setUtilizePump(false);

    return currentConfiguration;
}

void Widget_PauseParameters::loadFromProfileConfiguration(const ECMCommand_AbstractProfileConfigPtr config)
{
    ECMCommand_ProfilePausePtr castConfiguration = static_pointer_cast<ECMCommand_ProfilePause>(config);

    bool oldFiniteState = ui->radioButton_finite->blockSignals(true);
    bool oldInfState = ui->radioButton_infinite->blockSignals(true);

    switch (castConfiguration->getPauseType()) {
    case ECMCommand_ProfilePause::WaitType::FINITE:
    {
        ui->radioButton_finite->setChecked(true);
        ui->radioButton_infinite->setChecked(false);
        ui->doubleSpinBox_duration->setEnabled(true);
        ui->doubleSpinBox_duration->setValue(static_cast<double>(castConfiguration->getPauseDuration()));
        break;
    }
    case ECMCommand_ProfilePause::WaitType::INF:
    {
        ui->radioButton_infinite->setChecked(true);
        ui->radioButton_finite->setChecked(false);
        ui->doubleSpinBox_duration->setEnabled(false);
        ui->doubleSpinBox_duration->setValue(0.0);
        break;
    }
    default:
        break;
    }

    ui->radioButton_finite->blockSignals(oldFiniteState);
    ui->radioButton_infinite->blockSignals(oldInfState);
}
