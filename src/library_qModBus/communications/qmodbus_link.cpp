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
        if(QCoreApplication::instance() == NULL)
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
        QTimer *timer = new QTimer(0);
        timer->moveToThread(this);
        pApp->connect(timer, &QTimer::timeout, m_Func);
        timer->start(m_Interval);

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
    _config = config;
    _config.setDynamic();

    std::cout << "Create QModBusLink " << config.portName() << config.baud() << config.flowControl()
             << config.parity() << config.dataBits() << config.stopBits() << std::endl;
    std::cout <<  "portName: " << config.portName() << std::endl;
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
        modbus_close(m_Session->m_serialModbus);
        modbus_free(m_Session->m_serialModbus);
        m_Session->m_serialModbus = nullptr;
        m_Session->setSerialPortConnected(false);
    }

    EmitEvent([this](const ILinkEvents *ptr){
        common::comms::CommunicationUpdate commsUpdate;
        commsUpdate.setSourceName("QModBus");
        commsUpdate.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::CONNECTED);
        commsUpdate.setPeripheralMessage("Serial Port connection for QModbus has been opened.");

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

    char parity('N');

    m_Session->m_serialModbus = modbus_new_rtu(_config.portName().c_str(),_config.baud(),parity,_config.dataBits(),_config.stopBits());
    if(modbus_connect(m_Session->m_serialModbus) == -1) //unable to open the port for some reason
    {
        _emitLinkError("Unable to open serial connection for QModBus.");
        return false;
    }

    this->SetSlaveAddress(3);

    m_Session->setSerialPortConnected(true);

    m_ListenThread = new AppThread(10, [&](){
        //this->PortEventLoop();
    });

    m_Session->moveToThread(m_ListenThread);
    m_ListenThread->start();

    EmitEvent([this](const ILinkEvents *ptr){
        common::comms::CommunicationUpdate commsUpdate;
        commsUpdate.setSourceName("QModBus");
        commsUpdate.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::CONNECTED);
        commsUpdate.setPeripheralMessage("Serial Port connection for QModbus has been opened.");

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
    modbus_set_slave(m_Session->m_serialModbus,slaveAddress);
}

bool QModBusLink::WriteSingleRegister(const unsigned long &dataRegister, const unsigned long &data) const
{
    int returned = -1;
    returned = modbus_write_register(m_Session->m_serialModbus,dataRegister,data);
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
    return m_Session->isSerialPortConnected();
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

common::comms::LinkConfiguration QModBusLink::getLinkConfiguration()
{
    return _config;
}

} //end of namepsace comms

