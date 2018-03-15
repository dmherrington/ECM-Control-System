#include "dialog_pump_control.h"
#include "ui_dialog_pump_control.h"

Dialog_PumpControl::Dialog_PumpControl(const westinghousePump::Westinghouse510* ref, QWidget *parent) :
    QDialog(parent),
    m_pump(ref),
    ui(new Ui::Dialog_PumpControl)
{
    ui->setupUi(this);
    if(ref->m_State->pumpON.get())
    {
        ui->pushButton_PumpRunning->setText("OFF");
    }
    else
    {
        ui->pushButton_PumpRunning->setText("OFF");
    }
    ui->doubleSpinBox_flowRate->setValue(ref->m_State->flowRate.get());

    ui->doubleSpinBox_delayTime->setValue(ref->m_State->delayTime.get());
}

Dialog_PumpControl::~Dialog_PumpControl()
{
    delete ui;
}

void Dialog_PumpControl::on_pushButton_PumpRunning_released()
{
    bool run = !m_pump->m_State->pumpON.get();
    emit signal_updatePumpRunning(run);
}

void Dialog_PumpControl::on_doubleSpinBox_flowRate_editingFinished()
{
    double flowRate = ui->doubleSpinBox_flowRate->value();
    emit signal_updatePumpFlowRate(flowRate);
}

void Dialog_PumpControl::on_doubleSpinBox_delayTime_editingFinished()
{
    double delayTime = ui->doubleSpinBox_delayTime->value();
    emit signal_updatePumpDelayTime(delayTime);
}
