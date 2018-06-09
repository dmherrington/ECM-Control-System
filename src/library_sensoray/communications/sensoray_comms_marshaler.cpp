#include "sensoray_comms_marshaler.h"


namespace comms_Sensoray{


//////////////////////////////////////////////////////////////
/// Setup
//////////////////////////////////////////////////////////////

CommsMarshaler::CommsMarshaler()
{
    m_Session = new SensoraySession();

    //let us simplify this and do this upon constuction as there will only be one link
    link = std::make_shared<SensorayLink>();
    link->AddListener(this);
    link->updateCurrentSession(m_Session);

    //let us simplify this and do this upon constuction as there will only be one protocol
    protocol = std::make_shared<SensorayProtocol>();
    protocol->AddListner(this);
    protocol->updateCurrentSession(m_Session);
}

CommsMarshaler::~CommsMarshaler()
{
    protocol->closeSerialPort();
    link->DisconnectFromDevice();
    if(m_Session) delete m_Session;
    m_Session = nullptr;
}
///////////////////////////////////////////////////////////////////////////////////////////////
/// Methods supporting the Connect/Disconnect from Sensoray Device
///////////////////////////////////////////////////////////////////////////////////////////////

//!
//! \brief Connect to an already created link
//! \param linkName Name of link to connect to
//! \return True if connection succesfull, false otherwise
//!
bool CommsMarshaler::ConnectToLink(const SensorayTCPConfiguration &linkConfig)
{
    link->setTCPConfiguration(linkConfig);
    link->ConnectToDevice();
    return link->isConnected();
}

bool CommsMarshaler::DisconnetFromLink()
{
    auto func = [this]() {
        link->DisconnectFromDevice();
    };

    link->MarshalOnThread(func);
    return link->isConnected();
}

bool CommsMarshaler::isLinkConnected() const
{
    return link->isConnected();
}

///////////////////////////////////////////////////////////////////////////////////////////////
/// Methods supporting the Connect/Disconnect from of the Sensory Device and accompanying
/// RS485 port
///////////////////////////////////////////////////////////////////////////////////////////////

//!
//! \brief ConnectToSerialPort
//! \param linkConfig
//! \return
//!
void CommsMarshaler::ConnectToSerialPort(const common::comms::SerialConfiguration &config)
{
    auto func = [this, config]() {
        protocol->openSerialPort(config);
    };
    link->MarshalOnThread(func);
}

//!
//! \brief DisconnetFromSerialPort
//! \return
//!
void CommsMarshaler::DisconnetFromSerialPort()
{
    auto func = [this]() {
        protocol->closeSerialPort();
    };
    link->MarshalOnThread(func);
}

void CommsMarshaler::WriteToSerialPort(const QByteArray &data) const
{
    auto func = [this, data]() {
        protocol->transmitDataToSerialPort(data);
    };
    link->MarshalOnThread(func);
}

void CommsMarshaler::resetSensorayIO()
{
    auto func = [this]() {
        protocol->resetSensorayIO();
    };

    link->MarshalOnThread(func);
}

//////////////////////////////////////////////////////////////
/// React to Link Events
//////////////////////////////////////////////////////////////

void CommsMarshaler::CommunicationUpdate(const common::comms::CommunicationUpdate &update) const
{
    Emit([&](CommsEvents *ptr){ptr->ConnectionStatusUpdated(update);});
}

//////////////////////////////////////////////////////////////
/// IProtocolSensorayEvents
//////////////////////////////////////////////////////////////

void CommsMarshaler::SerialPortStatusUpdate(const common::comms::CommunicationUpdate &update) const
{
    Emit([&](CommsEvents *ptr){ptr->SerialPortStatusUpdate(update);});
}

void CommsMarshaler::ResponseReceived(const QByteArray &buffer) const
{
    Emit([&](CommsEvents *ptr){ptr->NewDataReceived(buffer);});
}

} //end of namespace comms

