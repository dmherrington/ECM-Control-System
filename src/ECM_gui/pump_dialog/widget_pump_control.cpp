#include "widget_pump_control.h"
#include "ui_widget_pump_control.h"

Widget_PumpControl::Widget_PumpControl(Westinghouse510 *pumpObject, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_PumpControl)
{

    ui->setupUi(this);

    m_Pump = pumpObject;

    m_OperationsTimer = new QTimer(this);
    //connect(m_OperationsTimer,SIGNAL(timeout()),this,SLOT(slot_PumpOperationalTimeout()));
}

Widget_PumpControl::~Widget_PumpControl()
{
    delete ui;
}

void Widget_PumpControl::loadFromPumpProperties(const Command_PumpProperties &config)
{
    this->ui->doubleSpinBox_delayTime->setValue(config.getInitializationTime()/1000.0);
    this->ui->doubleSpinBox_flowRate->setValue(config.getPumpFlowRate());
}

Command_PumpProperties Widget_PumpControl::getPumpProperties() const
{
    Command_PumpProperties newPumpCommand;

    unsigned int initializationTime = ui->doubleSpinBox_delayTime->value() * 1000;
    newPumpCommand.setPumpInitializationTime(initializationTime);

    registers_WestinghousePump::Register_FlowRate newFlowRate;
    newFlowRate.setVolumetricFlow(ui->doubleSpinBox_flowRate->value());

    newPumpCommand.setPumpFlowRate(newFlowRate);

    return newPumpCommand;
}

void Widget_PumpControl::setPumpFlowRate(const double &rate)
{
//    ui->doubleSpinBox_flowRate->setStyleSheet("background-color: red");
    ui->doubleSpinBox_flowRate->setValue(rate);
}

void Widget_PumpControl::setPumpDelayTime(const double &time)
{
    ui->doubleSpinBox_delayTime->setValue(time);
}

void Widget_PumpControl::setWaitForPumpDelay(const bool &wait)
{
    ui->checkBox_WaitForDelay->setChecked(wait);
}

void Widget_PumpControl::slot_PumpConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    using namespace common::comms;
    switch (update.getUpdateType()) {
    case CommunicationUpdate::UpdateTypes::ALERT:
        break;
    case CommunicationUpdate::UpdateTypes::CONNECTED:
        //ui->widget_PumpConnected->setColor(QColor(0,255,0));
        break;
    case CommunicationUpdate::UpdateTypes::DISCONNECTED:
        //ui->widget_PumpConnected->setColor(QColor(255,0,0));
        break;
    default:
        break;
    }
    //ui->statusbar->showMessage(QString::fromStdString(update.getPeripheralMessage()),2000);
}

void Widget_PumpControl::slot_updatedPumpOn(const bool &value)
{
    if(value)
    {
        //ui->widget_PumpRunning->setColor(QColor(0,255,0));
        ui->pushButton_PumpRunning->setText("OFF");
        common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,startTime);
        ui->lineEdit_OnTime->setText(QString::fromStdString(startTime.timeString()));
        //ui->statusbar->showMessage("The pump has been turned on.",2500);
        m_OperationsTimer->start(1000);
    }
    else
    {
        //ui->widget_PumpRunning->setColor(QColor(255,0,0));
        //ui->widget_PumpInitialized->setColor(QColor(255,0,0));
        ui->doubleSpinBox_flowRate->setStyleSheet("background-color: red");
        ui->pushButton_PumpRunning->setText("ON");
        ui->lineEdit_OnTime->setText("");
        ui->lineEdit_OnTime->clear();
        //ui->statusbar->showMessage(tr("The pump has been turned off."),2500);

        if(m_OperationsTimer->isActive())
            m_OperationsTimer->stop();
    }
}

void Widget_PumpControl::slot_updatedFlowRate(const double &value)
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

void Widget_PumpControl::slot_updatedDelayTime(const double &value)
{
    ui->doubleSpinBox_delayTime->setValue(value);
    //ui->statusbar->showMessage(tr("Delay time has been updated."),2500);
}

void Widget_PumpControl::slot_PumpInitialized()
{
    //ui->widget_PumpInitialized->setColor(QColor(0,255,0));
}

void Widget_PumpControl::on_pushButton_PumpRunning_released()
{
    bool run = !m_Pump->m_State->pumpON.get();
    registers_WestinghousePump::Register_OperationSignal newOps;
    newOps.shouldRun(run);
    m_Pump->setPumpOperations(newOps);
}

void Widget_PumpControl::on_doubleSpinBox_flowRate_valueChanged(double arg1)
{
    //ui->doubleSpinBox_flowRate->setStyleSheet("background-color: red");
    registers_WestinghousePump::Register_FlowRate newFlowRate;
    newFlowRate.setVolumetricFlow(arg1);
    m_Pump->setPumpFlowRate(newFlowRate);
}

void Widget_PumpControl::on_doubleSpinBox_delayTime_valueChanged(double arg1)
{
    unsigned int initializationTime = arg1 * 1000;
    m_Pump->setInitializationTime(initializationTime);
}

void Widget_PumpControl::writeToJSON(QJsonObject &saveObject)
{
    QJsonArray segmentDataArray;

    QJsonObject segmentObject;
    segmentObject["pumpDelayTime"] = this->ui->doubleSpinBox_delayTime->value();
    segmentObject["pumpFlowRate"] = this->ui->doubleSpinBox_flowRate->value();
    segmentObject["pumpWaitForDelay"] = this->ui->checkBox_WaitForDelay->isChecked();
    segmentDataArray.append(segmentObject);

    saveObject["pumpData"] = segmentDataArray;
}

void Widget_PumpControl::readFromJSON(const QJsonObject &openObject)
{  
    QJsonArray pumpDataArray = openObject["pumpData"].toArray();
    QJsonObject segmentObject = pumpDataArray[0].toObject();

    setPumpDelayTime(segmentObject["pumpDelayTime"].toDouble());
    setPumpFlowRate(segmentObject["pumpFlowRate"].toDouble());
    setWaitForPumpDelay(segmentObject["pumpWaitForDelay"].toBool());
}
