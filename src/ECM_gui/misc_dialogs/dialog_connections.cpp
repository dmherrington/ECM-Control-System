#include "dialog_connections.h"
#include "ui_dialog_connections.h"

Dialog_Connections::Dialog_Connections(ECM_API *obj, QWidget *parent) :
    QDialog(parent),
    m_API(obj),
    ui(new Ui::Dialog_Connections)
{
    ui->setupUi(this);
    double ledDiameter = 6;
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

    connect(m_API->m_Sensoray,SIGNAL(signal_SensorayConnectionUpdate(common::comms::CommunicationConnection)),this,SLOT(slot_SensorayConnectionUpdate(common::comms::CommunicationConnection)));
    connect(m_API->m_Pump,SIGNAL(signal_PumpConnectionUpdate(common::comms::CommunicationConnection)),this,SLOT(slot_PumpConnectionUpdate(common::comms::CommunicationConnection)));
    connect(m_API->m_Galil,SIGNAL(signal_MotionControllerConnectionUpdate(common::comms::CommunicationConnection)),this,SLOT(slot_GalilConnectionUpdate(common::comms::CommunicationConnection)));
    connect(m_API->m_Munk,SIGNAL(signal_MunkConnectionUpdate(common::comms::CommunicationConnection)),this,SLOT(slot_MunkConnectionUpdate(common::comms::CommunicationConnection)));
    connect(m_API->m_Rigol,SIGNAL(signal_RigolConnectionUpdate(common::comms::CommunicationConnection)),this,SLOT(slot_RigolConnectionUpdate(common::comms::CommunicationConnection)));

}

Dialog_Connections::~Dialog_Connections()
{
    delete ui;
}

void Dialog_Connections::updateLEDConnectionColor(LED *ledWidget, const bool &connected)
{
    if(connected)
        ledWidget->setColor(QColor(0,255,0));
    else
        ledWidget->setColor(QColor(255,0,0));
}

void Dialog_Connections::slot_SensorayConnectionUpdate(const common::comms::CommunicationConnection &update)
{
    this->updateLEDConnectionColor(ui->widget_SensorayConnection,update.isConnected());
}

void Dialog_Connections::slot_PumpConnectionUpdate(const common::comms::CommunicationConnection &update)
{
    this->updateLEDConnectionColor(ui->widget_WestinghouseConnection,update.isConnected());
}

void Dialog_Connections::slot_RigolConnectionUpdate(const common::comms::CommunicationConnection &update)
{
    this->updateLEDConnectionColor(ui->widget_RigolConnection,update.isConnected());
}

void Dialog_Connections::slot_MunkConnectionUpdate(const common::comms::CommunicationConnection &update)
{
    this->updateLEDConnectionColor(ui->widget_MunkConnection,update.isConnected());
}

void Dialog_Connections::slot_GalilConnectionUpdate(const common::comms::CommunicationConnection &update)
{
    this->updateLEDConnectionColor(ui->widget_GalilConnection,update.isConnected());
}

void Dialog_Connections::on_pushButton_connectSensoray_released()
{
    comms_Sensoray::SensorayTCPConfiguration config;
    m_API->m_Sensoray->openConnection(config);
}

void Dialog_Connections::on_pushButton_connectPump_released()
{

}

void Dialog_Connections::on_pushButton_connect_Rigol_released()
{
    m_API->m_Rigol->openConnection("192.168.1.17",5555);
}

void Dialog_Connections::on_pushButton_connectMunk_released()
{
    m_API->m_Munk->openSerialPort("COM8");
}

void Dialog_Connections::on_pushButton_connectGalil_released()
{
    m_API->m_Galil->openConnection("169.254.78.101 -d");
}

void Dialog_Connections::on_pushButton_Close_released()
{
    this->hide();
}
