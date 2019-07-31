#include "widget_front_panel_pump.h"
#include "ui_widget_front_panel_pump.h"

WidgetFrontPanel_Pump::WidgetFrontPanel_Pump(Westinghouse510* pumpObj, PLC *plcObj,  QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetFrontPanel_Pump),
    m_Pump(pumpObj)
{
    ui->setupUi(this);
    ui->widget_PumpInitialized->setDiameter(6);
    ui->widget_PumpRunning->setDiameter(6);

    QPalette palPH = ui->lcdNumber_pH->palette();
    palPH.setColor(QPalette::Normal, QPalette::WindowText, Qt::black);

    QPalette palConductivity = ui->lcdNumber_Conductivity->palette();
    palConductivity.setColor(QPalette::Normal, QPalette::WindowText, Qt::black);

    connect(m_Pump, SIGNAL(signal_PumpFlowUpdated(double)), this, SLOT(slot_updatedFlowRate(double)));
    connect(m_Pump, SIGNAL(signal_PumpOperating(bool)), this, SLOT(slot_updatedPumpOn(bool)));

    connect(plcObj, SIGNAL(signal_PLCNewSensorValue(common::TupleSensorString,common_data::SensorState)),
            this, SLOT(slot_NewSensorValue(common::TupleSensorString,common_data::SensorState)));

    m_Pump->AddLambda_FinishedPumpInitialization(this,[this](const bool completed){
        if(completed)
        {
            if(!m_Pump->isPumpRunning())
                ui->widget_PumpInitialized->setColor(QColor(255,0,0));
            else
            {
                if(m_Pump->isPumpInitialized())
                    ui->widget_PumpInitialized->setColor(QColor(0,255,0));
            }
        }
    });
}

WidgetFrontPanel_Pump::~WidgetFrontPanel_Pump()
{
    delete ui;
}

void WidgetFrontPanel_Pump::executingAutomatedSequence(const bool &value)
{
    ui->doubleSpinBox_delayTime->blockSignals(value);
    ui->doubleSpinBox_flowRate->blockSignals(value);
    ui->doubleSpinBox_delayTime->setDisabled(value);
    ui->doubleSpinBox_flowRate->setDisabled(value);
}

void WidgetFrontPanel_Pump::setPumpFlowRate(const double &rate)
{
//    ui->doubleSpinBox_flowRate->setStyleSheet("background-color: red");
    ui->doubleSpinBox_flowRate->setValue(rate);
}

void WidgetFrontPanel_Pump::setPumpDelayTime(const double &time)
{
    ui->doubleSpinBox_delayTime->setValue(time);
}

void WidgetFrontPanel_Pump::slot_updatedPumpOn(const bool &value)
{
    if(value)
    {
        ui->widget_PumpRunning->setColor(QColor(0,255,0));
        ui->pushButton_PumpRunning->setText("OFF");
        //ui->statusbar->showMessage("The pump has been turned on.",2500);
    }
    else
    {
        ui->widget_PumpRunning->setColor(QColor(255,0,0));
        ui->widget_PumpInitialized->setColor(QColor(255,0,0));
        ui->pushButton_PumpRunning->setText("ON");
        //ui->statusbar->showMessage(tr("The pump has been turned off."),2500);
    }
}

void WidgetFrontPanel_Pump::slot_updatedFlowRate(const double &value)
{
    if(abs(value - ui->doubleSpinBox_flowRate->value()) < 0.05)
    {
        //ui->doubleSpinBox_flowRate->setStyleSheet("background-color: green");
    }
    else{
        //ui->doubleSpinBox_flowRate->setStyleSheet("background-color: red");
    }
}

void WidgetFrontPanel_Pump::slot_NewSensorValue(const common::TupleSensorString &sensorTuple, const common_data::SensorState &data)
{
    UNUSED(sensorTuple);

    switch (data.getSensorType()) {
    case common_data::SensorTypes::SENSOR_PH:
    {
        double sensorValue = ((common_data::Sensor_pH*)data.getSensorData().get())->getPH(common_data::pHUnit::UNIT_BASE);
        ui->lcdNumber_pH->display(sensorValue);
        break;
    }
    case common_data::SensorTypes::SENSOR_CONDUCTIVITY:
    {
        double sensorValue = ((common_data::Sensor_Conductivity*)data.getSensorData().get())->getConductivity(common_data::ConductivityUnit::UNIT_BASE);
        ui->lcdNumber_Conductivity->display(sensorValue);
        break;

    }
    default:
        break;
    }
}

void WidgetFrontPanel_Pump::slot_updatedDelayTime(const double &value)
{
    ui->doubleSpinBox_delayTime->setValue(value);
    //ui->statusbar->showMessage(tr("Delay time has been updated."),2500);
}

void WidgetFrontPanel_Pump::on_pushButton_PumpRunning_released()
{
    bool run = !m_Pump->m_State->pumpON.get();

    if((run) && (!hasTransmitted)) //if we have told it to run and have not transmitted anything before let us send some stuff
    {
        hasTransmitted = true;

        registers_WestinghousePump::Register_FlowRate newFlowRate;
        newFlowRate.setVolumetricFlow(ui->doubleSpinBox_flowRate->value());
        m_Pump->setPumpFlowRate(newFlowRate);

        unsigned int initializationTime = ui->doubleSpinBox_delayTime->value() * 1000;
        m_Pump->setInitializationTime(initializationTime);
    }

    registers_WestinghousePump::Register_OperationSignal newOps;
    newOps.shouldRun(run);
    m_Pump->setPumpOperations(newOps);
}

void WidgetFrontPanel_Pump::on_doubleSpinBox_flowRate_valueChanged(double arg1)
{
    //ui->doubleSpinBox_flowRate->setStyleSheet("background-color: red");
    registers_WestinghousePump::Register_FlowRate newFlowRate;
    newFlowRate.setVolumetricFlow(arg1);
    m_Pump->setPumpFlowRate(newFlowRate);
}

void WidgetFrontPanel_Pump::on_doubleSpinBox_delayTime_valueChanged(double arg1)
{
    unsigned int initializationTime = arg1 * 1000;
    m_Pump->setInitializationTime(initializationTime);
}
