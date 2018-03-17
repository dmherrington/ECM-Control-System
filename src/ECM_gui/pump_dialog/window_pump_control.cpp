#include "window_pump_control.h"
#include "ui_window_pump_control.h"

Window_PumpControl::Window_PumpControl(const Westinghouse510* obj, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_PumpControl),
    m_pump(obj)
{
    ui->setupUi(this);
//    if(m_pump->m_State->pumpON.get())
//    {
//        ui->pushButton_PumpRunning->setText("OFF");
//    }
//    else
//    {
//        ui->pushButton_PumpRunning->setText("OFF");
//    }
//    ui->doubleSpinBox_flowRate->setValue(m_pump->m_State->flowRate.get());

//    ui->doubleSpinBox_delayTime->setValue(m_pump->m_State->delayTime.get());
}

Window_PumpControl::~Window_PumpControl()
{
    delete ui;
}

