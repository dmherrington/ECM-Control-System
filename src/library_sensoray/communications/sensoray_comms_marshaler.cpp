#include "sensoray_comms_marshaler.h"

namespace sensoray {
namespace comms{


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

///////////////////////////////////////////////////////////////////////////////////////////////
/// Methods supporting the Connect/Disconnect from of the Sensory Device and accompanying
/// RS485 port
///////////////////////////////////////////////////////////////////////////////////////////////

//!
//! \brief ConnectToSerialPort
//! \param linkConfig
//! \return
//!
bool CommsMarshaler::ConnectToSerialPort(const SerialConfiguration &config)
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
bool CommsMarshaler::DisconnetFromSerialPort()
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

void CommsMarshaler::ConnectionOpened() const
{
    Emit([&](CommsEvents *ptr){ptr->ConnectionOpened();});
}

void CommsMarshaler::ConnectionClosed() const
{
    Emit([&](CommsEvents *ptr){ptr->ConnectionClosed();});
}

void CommsMarshaler::CommunicationError(const std::string &type, const std::string &msg) const
{
    Emit([&](CommsEvents *ptr){ptr->CommunicationError(type,msg);});
}

void CommsMarshaler::CommunicationUpdate(const std::string &name, const std::string &msg) const
{
    Emit([&](CommsEvents *ptr){ptr->CommunicationUpdate(name,msg);});
}

//////////////////////////////////////////////////////////////
/// IProtocolSensorayEvents
//////////////////////////////////////////////////////////////
void CommsMarshaler::ResponseReceived(const QByteArray &buffer) const
{
    Emit([&](CommsEvents *ptr){ptr->NewDataReceived(buffer);});
}

} //end of namespace comms
} //end of namespace sensoray
