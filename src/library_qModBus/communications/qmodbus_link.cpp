#include "qmodbus_link.h"

namespace comms_QModBus {

//!
//! \brief This class defines a thread such that a QObject can run in peace.
//!
class AppThread : public QThread
{
public:
    AppThread(const size_t interval, std::function<void()> func)
    {
        if(QCoreApplication::instance() == nullptr)
        {
            int argc = 0;
            char * argv[] = {(char *)"sharedlib.app"};
            pApp = new QCoreApplication(argc, argv);
        }

        m_Interval = interval;
        m_Func = func;
    }

    virtual void run()
    {
        QTimer *timer = new QTimer();
        timer->moveToThread(this);
        pApp->connect(timer, &QTimer::timeout, m_Func);
        timer->start(static_cast<int>(m_Interval));

        exec();
    }

private:

    QCoreApplication *pApp;

    std::function<void()> m_Func;
    size_t m_Interval;
};


QModBusLink::QModBusLink()
{
    m_Session = new QModBusSession();
}

QModBusLink::~QModBusLink()
{
    DisconnectFromDevice();
    delete m_Session;
    m_Session = nullptr;
}

void QModBusLink::RequestReset()
{

}

void QModBusLink::setSerialConfiguration(const common::comms::SerialConfiguration &config)
{
    if(isConnected())
        DisconnectFromDevice();
    ILink::setSerialConfiguration(config);
}

void QModBusLink::setTCPConfiguration(const common::comms::TCPConfiguration &config)
{
    if(isConnected())
        DisconnectFromDevice();
    ILink::setTCPConfiguration(config);
}

bool QModBusLink::ConnectToDevice(void)
{
    DisconnectFromDevice();

    // Initialize the connection
    if (!_hardwareConnect()) {
        return false;
    }
    return true;
}

bool QModBusLink::DisconnectFromDevice(void)
{
    if(isConnected())
    {
        modbus_close(m_Session->m_ModbusSession);
        modbus_free(m_Session->m_ModbusSession);
        m_Session->m_ModbusSession = nullptr;
        m_Session->setDeviceConnected(false);
    }

    EmitEvent([this](const ILinkEvents *ptr){
        common::comms::CommunicationUpdate commsUpdate;
        commsUpdate.setSourceName("QModBus");
        commsUpdate.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::DISCONNECTED);
        commsUpdate.setPeripheralMessage("Serial Port connection for QModbus has been closed.");

        ptr->CommunicationUpdate(commsUpdate);
    });

    return true;
}

/// Performs the actual hardware port connection.
///     @param[out] error if failed
///     @param[out] error string if failed
/// @return success/fail
bool QModBusLink::_hardwareConnect()
{
    common::comms::CommunicationUpdate commsStatus;
    commsStatus.setSourceName("QModBus");

    switch (m_CommunicationSettings.type) {
    case comms_QModBus::COMMS_TYPE::SERIAL:
    {
        char parity('N');
        common::comms::SerialConfiguration config = m_CommunicationSettings.serialPort;

        m_Session->m_ModbusSession = modbus_new_rtu(config.portName().c_str(),config.baud(),parity,config.dataBits(),config.stopBits());
        if(modbus_connect(m_Session->m_ModbusSession) == -1) //unable to open the port for some reason
        {
            _emitLinkError("Unable to open serial connection for QModBus.");
            return false;
        }

        this->SetSlaveAddress(3);


        break;
    }
    case comms_QModBus::COMMS_TYPE::ETHERNET:
    {
        common::comms::TCPConfiguration config = m_CommunicationSettings.ethernetPort;
        m_Session->m_ModbusSession = modbus_new_tcp(config.listenAddress().c_str(), config.listenPortNumber());
        if(modbus_connect(m_Session->m_ModbusSession) == -1) //unable to open the port for some reason
        {
            _emitLinkError("Unable to open serial connection for QModBus.");
            return false;
        }
        this->SetSlaveAddress(1);

        break;
    }
    };

    m_Session->setDeviceConnected(true);

    m_ListenThread = new AppThread(10, [&](){
        //this->PortEventLoop();
    });

    m_Session->moveToThread(m_ListenThread);
    m_ListenThread->start();

    EmitEvent([this](const ILinkEvents *ptr){
        common::comms::CommunicationUpdate commsUpdate;
        commsUpdate.setSourceName("QModBus");
        commsUpdate.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::CONNECTED);
        commsUpdate.setPeripheralMessage("Connection for QModbus has been opened.");

        ptr->CommunicationUpdate(commsUpdate);
    });

    return true; // successful connection
}

unsigned int QModBusLink::GetSlaveAddress() const
{
    return this->slaveID;
}

void QModBusLink::SetSlaveAddress(const unsigned int &slaveAddress)
{
    this->slaveID = slaveAddress;
    modbus_set_slave(m_Session->m_ModbusSession,static_cast<int>(slaveAddress));
}

bool QModBusLink::WriteSingleRegister(const unsigned long &dataRegister, const unsigned long &data) const
{
    int returned = -1;
    returned = modbus_write_register(m_Session->m_ModbusSession,static_cast<int>(dataRegister),static_cast<int>(data));
    if( returned == 1  )
        return true;
    return false;
}

//!
//! \brief Determine the connection status
//! \return True if the connection is established, false otherwise
//!
bool QModBusLink::isConnected() const
{
    return m_Session->isDeviceConnected();
}

void QModBusLink::_emitLinkError(const std::string& errorMsg) const
{

    EmitEvent([this,errorMsg](const ILinkEvents *ptr){
        common::comms::CommunicationUpdate commsUpdate;
        commsUpdate.setSourceName("QModBus");
        commsUpdate.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::ALERT);
        std::string msg = "Error on link:" + errorMsg;
        commsUpdate.setPeripheralMessage(msg);

        ptr->CommunicationUpdate(commsUpdate);
    });
}

} //end of namepsace comms

