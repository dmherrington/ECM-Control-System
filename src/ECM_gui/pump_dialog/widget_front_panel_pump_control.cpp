#include "widget_front_panel_pump_control.h"
#include "ui_widget_front_panel_pump_control.h"

WidgetFrontPanel_PumpControl::WidgetFrontPanel_PumpControl(Westinghouse510 *pumpObject, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetFrontPanel_PumpControl)
{
    ui->setupUi(this);

    m_Pump = pumpObject;
}

WidgetFrontPanel_PumpControl::~WidgetFrontPanel_PumpControl()
{
    delete ui;
}

void WidgetFrontPanel_PumpControl::loadFromPumpProperties(const Command_PumpProperties &config)
{
    ui->doubleSpinBox_delayTime->setValue(config.getInitializationTime()/1000.0);
    ui->doubleSpinBox_flowRate->setValue(config.getPumpFlowRate());
}

void WidgetFrontPanel_PumpControl::setPumpFlowRate(const double &rate)
{
//    ui->doubleSpinBox_flowRate->setStyleSheet("background-color: red");
    ui->doubleSpinBox_flowRate->setValue(rate);
}

void WidgetFrontPanel_PumpControl::setPumpDelayTime(const double &time)
{
    ui->doubleSpinBox_delayTime->setValue(time);
}

void WidgetFrontPanel_PumpControl::slot_updatedFlowRate(const double &value)
{
    if(abs(value - ui->doubleSpinBox_flowRate->value()) < 0.05)
    {
        //ui->doubleSpinBox_flowRate->setStyleSheet("background-color: green");
    }
    else{
        //ui->doubleSpinBox_flowRate->setStyleSheet("background-color: red");
    }
    //ui->statusbar->showMessage(tr("Flow rate has been updated."),2500);
}

void WidgetFrontPanel_PumpControl::slot_updatedDelayTime(const double &value)
{
    ui->doubleSpinBox_delayTime->setValue(value);
    //ui->statusbar->showMessage(tr("Delay time has been updated."),2500);
}

void WidgetFrontPanel_PumpControl::on_doubleSpinBox_flowRate_valueChanged(double arg1)
{
    //ui->doubleSpinBox_flowRate->setStyleSheet("background-color: red");
//    registers_WestinghousePump::Register_FlowRate newFlowRate;
//    newFlowRate.setVolumetricFlow(arg1);
//    m_Pump->setPumpFlowRate(newFlowRate);
}

void WidgetFrontPanel_PumpControl::on_doubleSpinBox_delayTime_valueChanged(double arg1)
{
//    unsigned int initializationTime = arg1 * 1000;
//    m_Pump->setInitializationTime(initializationTime);
}
