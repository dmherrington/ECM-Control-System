#include "sensoray_comms_marshaler.h"

namespace sensoray {
namespace comms{


//////////////////////////////////////////////////////////////
/// Setup
//////////////////////////////////////////////////////////////

CommsMarshaler::CommsMarshaler()
{
    //let us simplify this and do this upon constuction as there will only be one link
    link = std::make_shared<SensorayTCPLink>();
    link->AddListener(this);

    //let us simplify this and do this upon constuction as there will only be one protocol
    protocol = std::make_shared<SensorayProtocol>();
    protocol->AddListner(this);
}

CommsMarshaler::~CommsMarshaler()
{
    link->Disconnect();
}
///////////////////////////////////////////////////////////////////////////////////////////////
/// Connect/Disconnect from Rigol Methods
///////////////////////////////////////////////////////////////////////////////////////////////

//!
//! \brief Connect to an already created link
//! \param linkName Name of link to connect to
//! \return True if connection succesfull, false otherwise
//!
bool CommsMarshaler::ConnectToLink(const SensorayTCPConfiguration &linkConfig)
{
    link->setTCPConfiguration(linkConfig);
    link->Connect();
    return link->isConnected();
}

bool CommsMarshaler::DisconnetFromLink()
{
    auto func = [this]() {
        link->Disconnect();
    };

    link->MarshalOnThread(func);
    return link->isConnected();
}

void CommsMarshaler::EmitByteArray(const QByteArray &data)
{
    auto func = [this, data]() {
        //link->WriteBytes(data);
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
