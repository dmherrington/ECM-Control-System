#include "sensoray_comms_marshaler.h"

namespace sensoray {
namespace comms{


//////////////////////////////////////////////////////////////
/// Setup
//////////////////////////////////////////////////////////////

CommsMarshaler::CommsMarshaler()
{
    //let us simplify this and do this upon constuction as there will only be one link
    link = std::make_shared<SensorayLink>();
    link->AddListener(this);

    //let us simplify this and do this upon constuction as there will only be one protocol
    protocol = std::make_shared<SensorayProtocol>();
    protocol->AddListner(this);
}

CommsMarshaler::~CommsMarshaler()
{
    link->DisconnectFromDevice();
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
        protocol->openSerialPort(link.get(),config);
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
        protocol->closeSerialPort(link.get());
    };
    link->MarshalOnThread(func);
}

void CommsMarshaler::WriteToSerialPort(const QByteArray &data) const
{
    auto func = [this, data]() {
        protocol->transmitDataToSerialPort(link.get(),data);
    };
    link->MarshalOnThread(func);
}

void CommsMarshaler::resetSensorayIO()
{
    auto func = [this]() {
        protocol->resetSensorayIO(link.get());
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

void CommsMarshaler::ReceiveData(const std::vector<uint8_t> &buffer) const
{
    protocol->ReceiveData(link.get(),buffer);
    //if there is something still in the queue we should send it
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
void CommsMarshaler::ResponseReceived(const ILink* link_ptr, const std::vector<uint8_t> &buffer) const
{
    Emit([&](CommsEvents *ptr){ptr->NewDataReceived(buffer);});
}

} //end of namespace comms
} //end of namespace sensoray
