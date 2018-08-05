#include "dialog_connections.h"
#include "ui_dialog_connections.h"

Dialog_Connections::Dialog_Connections(ECM_API *obj, QWidget *parent) :
    QDialog(parent),
    m_API(obj),
    ui(new Ui::Dialog_Connections)
{
    ui->setupUi(this);
    double ledDiameter = 4;
    ui->widget_GalilConnection->setDiameter(ledDiameter);
    ui->widget_GalilConnection->setColor(QColor(255,0,0));
    ui->widget_MunkConnection->setDiameter(ledDiameter);
    ui->widget_MunkConnection->setColor(QColor(255,0,0));
    ui->widget_RigolConnection->setDiameter(ledDiameter);
    ui->widget_RigolConnection->setColor(QColor(255,0,0));
    ui->widget_SensorayConnection->setDiameter(ledDiameter);
    ui->widget_SensorayConnection->setColor(QColor(255,0,0));
    ui->widget_WestinghouseConnection->setDiameter(ledDiameter);
    ui->widget_WestinghouseConnection->setColor(QColor(255,0,0));
    //let us check all of the device connections

    connect(m_API->m_Sensoray,SIGNAL(signal_SensorayCommunicationUpdate(common::comms::CommunicationUpdate)),this,SLOT(slot_SensorayConnectionUpdate(common::comms::CommunicationUpdate)));
    connect(m_API->m_Pump,SIGNAL(signal_PumpCommunicationUpdate(common::comms::CommunicationUpdate)),this,SLOT(slot_PumpConnectionUpdate(common::comms::CommunicationUpdate)));
    connect(m_API->m_Galil,SIGNAL(signal_MotionControllerCommunicationUpdate(common::comms::CommunicationUpdate)),this,SLOT(slot_GalilConnectionUpdate(common::comms::CommunicationUpdate)));
    connect(m_API->m_Munk,SIGNAL(signal_MunkCommunicationUpdate(common::comms::CommunicationUpdate)),this,SLOT(slot_MunkConnectionUpdate(common::comms::CommunicationUpdate)));
    connect(m_API->m_Rigol,SIGNAL(signal_RigolCommunicationUpdate(common::comms::CommunicationUpdate)),this,SLOT(slot_RigolConnectionUpdate(common::comms::CommunicationUpdate)));

}

Dialog_Connections::~Dialog_Connections()
{
    delete ui;
}

void Dialog_Connections::updateLEDConnectionColor(LED *ledWidget, const common::comms::CommunicationUpdate &connected)
{
    if(connected.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::CONNECTED)
        ledWidget->setColor(QColor(0,255,0));
    else if(connected.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::DISCONNECTED)
        ledWidget->setColor(QColor(255,0,0));
}

void Dialog_Connections::slot_SensorayConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    this->updateLEDConnectionColor(ui->widget_SensorayConnection,update);
}

void Dialog_Connections::slot_PumpConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    this->updateLEDConnectionColor(ui->widget_WestinghouseConnection,update);
}

void Dialog_Connections::slot_RigolConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    this->updateLEDConnectionColor(ui->widget_RigolConnection,update);
}

void Dialog_Connections::slot_MunkConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    this->updateLEDConnectionColor(ui->widget_MunkConnection,update);
}

void Dialog_Connections::slot_GalilConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    this->updateLEDConnectionColor(ui->widget_GalilConnection,update);
}

void Dialog_Connections::on_pushButton_connectSensoray_released()
{
    comms_Sensoray::SensorayTCPConfiguration config;
    m_API->m_Sensoray->openConnection(config);
}

void Dialog_Connections::on_pushButton_connectPump_released()
{
    m_API->m_Pump->openPumpConnection();
}

void Dialog_Connections::on_pushButton_connect_Rigol_released()
{
    m_API->m_Rigol->openConnection("192.168.1.17",5555);
}

void Dialog_Connections::on_pushButton_connectMunk_released()
{
    m_API->m_Munk->openSerialPort("COM4");
}

void Dialog_Connections::on_pushButton_connectGalil_released()
{
    m_API->m_Galil->openConnection("169.254.78.101 -d");
}

void Dialog_Connections::on_pushButton_Close_released()
{
    this->hide();
}
