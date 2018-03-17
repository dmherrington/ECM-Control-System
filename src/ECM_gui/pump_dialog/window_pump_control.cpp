#include "window_pump_control.h"
#include "ui_window_pump_control.h"

Window_PumpControl::Window_PumpControl(const Westinghouse510* obj, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_PumpControl),
    m_pump(obj)
{
    ui->setupUi(this);
    if(m_pump->m_State->pumpON.get())
    {
        ui->pushButton_PumpRunning->setText("OFF");
    }
    else
    {
        ui->pushButton_PumpRunning->setText("OFF");
    }
    ui->doubleSpinBox_flowRate->setValue(m_pump->m_State->flowRate.get());

    ui->doubleSpinBox_delayTime->setValue(m_pump->m_State->delayTime.get());
}

Window_PumpControl::~Window_PumpControl()
{
    delete ui;
}

void Window_PumpControl::slot_updatedDelayTime(const double &value)
{

}

void Window_PumpControl::slot_updatedConnection()
{

}

void Window_PumpControl::slot_updatedPumpOn(const bool &value)
{

}

void Window_PumpControl::slot_updatedFlowRate(const double &value)
{

}

void Window_PumpControl::slot_updatedStartTime()
{

}

void Window_PumpControl::on_pushButton_PumpRunning_released()
{
    //bool run = !m_pump->m_State->pumpON.get();
    //emit signal_updatePumpRunning(run);
}

void Window_PumpControl::on_doubleSpinBox_flowRate_editingFinished()
{
    double flowRate = ui->doubleSpinBox_flowRate->value();
    emit signal_updatePumpFlowRate(flowRate);
}

void Window_PumpControl::on_doubleSpinBox_delayTime_editingFinished()
{
    double delayTime = ui->doubleSpinBox_delayTime->value();
    emit signal_updatePumpDelayTime(delayTime);
}
