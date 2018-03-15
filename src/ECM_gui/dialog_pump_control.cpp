#include "dialog_pump_control.h"
#include "ui_dialog_pump_control.h"

Dialog_PumpControl::Dialog_PumpControl(QWidget *parent, const westinghousePump::Westinghouse510* ref) :
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
    ui->doubleSpinBox_delayTime->setValue();
}

Dialog_PumpControl::~Dialog_PumpControl()
{
    delete ui;
}
