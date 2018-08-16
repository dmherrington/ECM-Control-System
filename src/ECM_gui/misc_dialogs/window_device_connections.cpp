#include "window_device_connections.h"
#include "ui_window_device_connections.h"

Window_DeviceConnections::Window_DeviceConnections(ECM_API *obj, QWidget *parent) :
    GeneralDialogWindow(DialogWindowTypes::WINDOW_CONNECTIONS,"Device Connections",parent),
    m_API(obj),
    ui(new Ui::Window_DeviceConnections)
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

Window_DeviceConnections::~Window_DeviceConnections()
{
    delete ui;
}

void Window_DeviceConnections::closeEvent(QCloseEvent *event)
{
    GeneralDialogWindow::closeEvent(event);
}

void Window_DeviceConnections::on_actionClose_triggered()
{
    GeneralDialogWindow::onCloseAction();
}

void Window_DeviceConnections::on_pushButton_Close_released()
{
    GeneralDialogWindow::onCloseAction();
}

void Window_DeviceConnections::updateLEDConnectionColor(LED *ledWidget, const common::comms::CommunicationUpdate &connected)
{
    if(connected.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::CONNECTED)
        ledWidget->setColor(QColor(0,255,0));
    else if(connected.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::DISCONNECTED)
        ledWidget->setColor(QColor(255,0,0));

    ui->statusbar->showMessage(QString::fromStdString(connected.getPeripheralMessage()),2000);
}

void Window_DeviceConnections::slot_SensorayConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    this->updateLEDConnectionColor(ui->widget_SensorayConnection,update);
}

void Window_DeviceConnections::slot_PumpConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    this->updateLEDConnectionColor(ui->widget_WestinghouseConnection,update);
}

void Window_DeviceConnections::slot_RigolConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    this->updateLEDConnectionColor(ui->widget_RigolConnection,update);
}

void Window_DeviceConnections::slot_MunkConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    this->updateLEDConnectionColor(ui->widget_MunkConnection,update);
}

void Window_DeviceConnections::slot_GalilConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    this->updateLEDConnectionColor(ui->widget_GalilConnection,update);
}

void Window_DeviceConnections::on_pushButton_connectSensoray_released()
{

//    comms_Sensoray::SensorayTCPConfiguration config;
//    m_API->m_Sensoray->openConnection(config);
}

void Window_DeviceConnections::on_pushButton_connectPump_released()
{
    m_API->m_Pump->openPumpConnection();
}

void Window_DeviceConnections::on_pushButton_connect_Rigol_released()
{
    m_API->m_Rigol->openConnection("192.168.1.17",5555);
}

void Window_DeviceConnections::on_pushButton_connectMunk_released()
{
    m_API->m_Munk->openSerialPort("COM4");
}

void Window_DeviceConnections::on_pushButton_connectGalil_released()
{
    m_API->m_Galil->openConnection("169.254.78.101 -d");
}

void Window_DeviceConnections::on_pushButton_ConnectAll_released()
{
    this->on_pushButton_connectGalil_released();
    this->on_pushButton_connectPump_released();
    this->on_pushButton_connectMunk_released();
    this->on_pushButton_connect_Rigol_released();
}
