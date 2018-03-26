#include "window_pump_control.h"
#include "ui_window_pump_control.h"

Window_PumpControl::Window_PumpControl(Westinghouse510* obj, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_PumpControl),
    m_Pump(obj)
{
    ui->setupUi(this);

    readSettings();

    if(m_Pump->m_State->pumpON.get())
        ui->pushButton_PumpRunning->setText("OFF");
    else
        ui->pushButton_PumpRunning->setText("ON");

    ui->doubleSpinBox_flowRate->setValue(m_Pump->m_State->flowRate.get());

    ui->doubleSpinBox_delayTime->setValue(m_Pump->m_State->delayTime.get());

    connect(m_Pump,SIGNAL(signal_PumpConnectionUpdate(common::comms::CommunicationConnection)),this,SLOT(slot_PumpConnectionUpdate(common::comms::CommunicationConnection)));

    this->m_Pump->m_State->flowRate.AddNotifier(this,[this]
    {
        this->slot_updatedFlowRate(m_Pump->m_State->flowRate.get());
    });

    this->m_Pump->m_State->pumpON.AddNotifier(this,[this]
    {
        this->slot_updatedPumpOn(m_Pump->m_State->pumpON.get());
    });
}

Window_PumpControl::~Window_PumpControl()
{
    delete ui;
}


bool Window_PumpControl::isWindowHidden() const
{
    return windowHidden;
}

void Window_PumpControl::readSettings()
{
    QSettings settings("Pump Window", "ECM Application");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();
    resize(size);
    move(pos);
}

void Window_PumpControl::closeEvent(QCloseEvent *event)
{
    QSettings settings("Pump Window", "ECM Application");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}

void Window_PumpControl::hideEvent(QHideEvent *event)
{
    windowHidden = true;
}

void Window_PumpControl::showEvent(QShowEvent *event)
{
    windowHidden = false;
}

void Window_PumpControl::slot_PumpConnectionUpdate(const common::comms::CommunicationConnection &value)
{
    if(value.isConnected())
        ui->widget_PumpConnected->setColor(QColor(0,255,0));
    else
        ui->widget_PumpConnected->setColor(QColor(255,0,0));
}

void Window_PumpControl::slot_updatedPumpOn(const bool &value)
{
    if(value)
    {
        ui->widget_PumpRunning->setColor(QColor(0,255,0));
        ui->pushButton_PumpRunning->setText("OFF");
        statusBar()->showMessage(tr("The pump has been turned on."),2500);
    }
    else
    {
        ui->widget_PumpRunning->setColor(QColor(255,0,0));
        ui->pushButton_PumpRunning->setText("ON");
        statusBar()->showMessage(tr("The pump has been turned off."),2500);
    }
}

void Window_PumpControl::slot_updatedFlowRate(const double &value)
{
    ui->doubleSpinBox_flowRate->setValue(value);
    statusBar()->showMessage(tr("Flow rate has been updated."),2500);
}

void Window_PumpControl::slot_updatedDelayTime(const double &value)
{
    ui->doubleSpinBox_delayTime->setValue(value);
    statusBar()->showMessage(tr("Delay time has been updated."),2500);
}

void Window_PumpControl::slot_updatedStartTime()
{

}

void Window_PumpControl::on_pushButton_PumpRunning_released()
{
    bool run = !m_Pump->m_State->pumpON.get();
    registers_WestinghousePump::Register_OperationSignal newOps;
    newOps.shouldRun(run);
    m_Pump->setPumpOperations(newOps);
}

void Window_PumpControl::on_doubleSpinBox_flowRate_valueChanged(double arg1)
{
    //m_Pump->m_State->flowRate.set(flowRate); // I dont know if I should do it like this
    registers_WestinghousePump::Register_FlowRate newFlowRate;
    newFlowRate.setVolumetricFlow(arg1);
    m_Pump->setPumpFlowRate(newFlowRate);
}

void Window_PumpControl::on_doubleSpinBox_delayTime_valueChanged(double arg1)
{

}

void Window_PumpControl::on_actionClose_triggered()
{
    this->hide();
}
