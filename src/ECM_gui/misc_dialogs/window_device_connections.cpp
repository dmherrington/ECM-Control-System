#include "window_device_connections.h"
#include "ui_window_device_connections.h"

Window_DeviceConnections::Window_DeviceConnections(ECM_API *obj, QWidget *parent) :
    GeneralDialogWindow(DialogWindowTypes::WINDOW_CONNECTIONS,"Device Connections",parent),
    ui(new Ui::Window_DeviceConnections),
    m_API(obj)
{

    GeneralDialogWindow::readWindowSettings();

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
    connect(m_API->m_MotionController,SIGNAL(signal_MotionControllerCommunicationUpdate(common::comms::CommunicationUpdate)),this,SLOT(slot_GalilConnectionUpdate(common::comms::CommunicationUpdate)));
    connect(m_API->m_Munk,SIGNAL(signal_MunkCommunicationUpdate(common::comms::CommunicationUpdate)),this,SLOT(slot_MunkConnectionUpdate(common::comms::CommunicationUpdate)));
    connect(m_API->m_Rigol,SIGNAL(signal_RigolCommunicationUpdate(common::comms::CommunicationUpdate)),this,SLOT(slot_RigolConnectionUpdate(common::comms::CommunicationUpdate)));

    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
        ui->comboBox_PortMunk->addItem(port.portName());
        ui->comboBox_PortPump->addItem(port.portName());
    }

    readCommunicationSettings();
}

Window_DeviceConnections::~Window_DeviceConnections()
{
    delete ui;
}

void Window_DeviceConnections::connectToAllDevices()
{
    this->connect_MotionController(true);
    this->connect_Oscilliscope(true);
    this->connect_PowerSupply(true);
    this->connect_Pump(true);
}

void Window_DeviceConnections::connect_MotionController(const bool &connect)
{
    if((!connect) && m_API->m_MotionController->isDeviceConnected())
    {
        m_API->m_MotionController->closeConnection();
    }
    else if(connect && (!m_API->m_MotionController->isDeviceConnected()))
    {
        QString ipAddress = ui->lineEdit_IPGalil->text();

        if(ipAddress.isEmpty())
            return;

        ipAddress += " -d";
        m_API->m_MotionController->ConnectToSimulation();

        //m_API->m_MotionController->openConnection(ipAddress.toStdString());
    }
}

void Window_DeviceConnections::connect_Oscilliscope(const bool &connect)
{
    if((!connect) && m_API->m_Rigol->isDeviceConnected())
    {
        m_API->m_Rigol->closeConnection();
    }
    else if(connect && (!m_API->m_Rigol->isDeviceConnected()))
    {
        QString ipAddress = ui->lineEdit_IPRigol->text();

        if(ipAddress.isEmpty())
            return;

        m_API->m_Rigol->openConnection(ipAddress.toStdString() , 5555);
    }
}

void Window_DeviceConnections::connect_PowerSupply(const bool &connect)
{
    if((!connect) && m_API->m_Munk->isConnected())
    {
        m_API->m_Munk->closeSerialPort();
    }
    else if(connect && (!m_API->m_Munk->isConnected()))
    {
        QString portNumber = ui->comboBox_PortMunk->currentText();

        if(portNumber.isEmpty())
            return;

        portNumber.remove(0,3);

        if(portNumber.toInt() > 9)
        {
            portNumber = "\\\\.\\COM" + portNumber;
        }
        else
        {
            portNumber = "COM" + portNumber;
        }

        m_API->m_Munk->openSerialPort(portNumber.toStdString());
    }
}

void Window_DeviceConnections::connect_Pump(const bool &connect)
{
    if((!connect) && m_API->m_Pump->isPumpConnected())
    {
        m_API->m_Pump->closePumpConnection();
    }
    else if(connect && (!m_API->m_Pump->isPumpConnected()))
    {
        QString portNumber = ui->comboBox_PortPump->currentText();

        if(portNumber.isEmpty())
            return;

        portNumber.remove(0,3);

        if(portNumber.toInt() > 9)
        {
            portNumber = "\\\\.\\COM" + portNumber;
        }
        else
        {
            portNumber = "COM" + portNumber;
        }

        m_API->m_Pump->openPumpConnection(portNumber.toStdString());
    }
}

void Window_DeviceConnections::closeEvent(QCloseEvent *event)
{
    this->saveCommunicationSettings();
    GeneralDialogWindow::closeEvent(event);
}

bool Window_DeviceConnections::areAllDevicesConnected() const
{
    if(m_API->m_MotionController->isDeviceConnected())
        if(m_API->m_Munk->isConnected())
            if(m_API->m_Pump->isPumpConnected())
                if(m_API->m_Rigol->isDeviceConnected())
                    return true;
    return false;
}

void Window_DeviceConnections::on_actionClose_triggered()
{
    GeneralDialogWindow::onCloseAction();
}

void Window_DeviceConnections::on_pushButton_Close_released()
{
    GeneralDialogWindow::onCloseAction();
}

void Window_DeviceConnections::saveCommunicationSettings()
{
    QSettings settings("Communication Settings", "ECM Application");
    settings.setValue("IPGalil", ui->lineEdit_IPGalil->text());
    settings.setValue("IPRigol", ui->lineEdit_IPRigol->text());
    settings.setValue("IPSensoray", ui->lineEdit_IPSensoray->text());
    settings.setValue("PortMunk", ui->comboBox_PortMunk->currentText());
    settings.setValue("PortPump", ui->comboBox_PortPump->currentText());
}

void Window_DeviceConnections::readCommunicationSettings()
{
    QSettings settings("Communication Settings", "ECM Application");
    ui->lineEdit_IPGalil->setText(settings.value("IPGalil").toString());
    ui->lineEdit_IPRigol->setText(settings.value("IPRigol").toString());
    ui->lineEdit_IPSensoray->setText(settings.value("IPSensoray").toString());

    QString portMunk = settings.value("PortMunk").toString();
    int munkIndex = ui->comboBox_PortMunk->findText(portMunk);
    if ( munkIndex != -1 ) { // -1 for not found
        ui->comboBox_PortMunk->setCurrentIndex(munkIndex);
    }

    QString portPump = settings.value("PortPump").toString();
    int pumpIndex = ui->comboBox_PortPump->findText(portPump);
    if ( pumpIndex != -1 ) { // -1 for not found
        ui->comboBox_PortPump->setCurrentIndex(pumpIndex);
    }
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
    if(update.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::CONNECTED)
    {
        ui->comboBox_PortPump->setDisabled(true);
        ui->pushButton_connectPump->setText("DISCONNECT");
    }
    else if(update.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::DISCONNECTED)
    {
        ui->comboBox_PortPump->setEnabled(true);
        ui->pushButton_connectPump->setText("CONNECT");
    }

    emit signal_DeviceConnectionComplete(areAllDevicesConnected());

    this->updateLEDConnectionColor(ui->widget_WestinghouseConnection,update);
}

void Window_DeviceConnections::slot_RigolConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    if(update.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::CONNECTED)
    {
        ui->lineEdit_IPRigol->setDisabled(true);
        ui->pushButton_connect_Rigol->setText("DISCONNECT");
    }
    else if(update.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::DISCONNECTED)
    {
        ui->comboBox_PortPump->setEnabled(true);
        ui->pushButton_connect_Rigol->setText("CONNECT");
    }

    emit signal_DeviceConnectionComplete(areAllDevicesConnected());

    this->updateLEDConnectionColor(ui->widget_RigolConnection,update);
}

void Window_DeviceConnections::slot_MunkConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    if(update.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::CONNECTED)
    {
        ui->comboBox_PortMunk->setDisabled(true);
        ui->pushButton_connectMunk->setText("DISCONNECT");
    }
    else if(update.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::DISCONNECTED)
    {
        ui->comboBox_PortMunk->setEnabled(true);
        ui->pushButton_connectMunk->setText("CONNECT");
    }

    emit signal_DeviceConnectionComplete(areAllDevicesConnected());

    this->updateLEDConnectionColor(ui->widget_MunkConnection,update);
}

void Window_DeviceConnections::slot_GalilConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    if(update.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::CONNECTED)
    {
        ui->lineEdit_IPGalil->setDisabled(true);
        ui->pushButton_connectGalil->setText("DISCONNECT");
    }
    else if(update.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::DISCONNECTED)
    {
        ui->lineEdit_IPGalil->setEnabled(true);
        ui->pushButton_connectGalil->setText("CONNECT");
    }

    emit signal_DeviceConnectionComplete(areAllDevicesConnected());

    this->updateLEDConnectionColor(ui->widget_GalilConnection,update);
}

void Window_DeviceConnections::on_pushButton_connectSensoray_released()
{

//    comms_Sensoray::SensorayTCPConfiguration config;
//    m_API->m_Sensoray->openConnection(config);
}

void Window_DeviceConnections::on_pushButton_connectPump_released()
{
    if(m_API->m_Pump->isPumpConnected())
        this->connect_Pump(false);
    else
        this->connect_Pump(true);
}

void Window_DeviceConnections::on_pushButton_connect_Rigol_released()
{
    if(m_API->m_Rigol->isDeviceConnected())
        this->connect_Oscilliscope(false);
    else
        this->connect_Oscilliscope(true);
}

void Window_DeviceConnections::on_pushButton_connectMunk_released()
{
    if(m_API->m_Munk->isConnected())
        this->connect_PowerSupply(false);
    else
        this->connect_PowerSupply(true);
}

void Window_DeviceConnections::on_pushButton_connectGalil_released()
{
    if(m_API->m_MotionController->isDeviceConnected())
        this->connect_MotionController(false);
    else
        this->connect_MotionController(true);
}

void Window_DeviceConnections::on_pushButton_ConnectAll_released()
{
    this->connectToAllDevices();
}
