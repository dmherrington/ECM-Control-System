#include "rigol_comms_marshaler.h"

namespace comms_Rigol{

//////////////////////////////////////////////////////////////
/// Setup
//////////////////////////////////////////////////////////////

RigolCommsMarshaler::RigolCommsMarshaler()
{
    //let us simplify this and do this upon constuction as there will only be one link
    link = std::make_shared<RigolTCPLink>();
    link->AddListener(this);

    //let us simplify this and do this upon constuction as there will only be one protocol
    protocol = std::make_shared<RigolProtocol>();
    protocol->AddListner(this);
}

RigolCommsMarshaler::~RigolCommsMarshaler()
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
bool RigolCommsMarshaler::ConnectToLink(const TCPConfiguration &linkConfig)
{
    link->setTCPConfiguration(linkConfig);
    link->Connect();
    return link->isConnected();
}

bool RigolCommsMarshaler::DisconnetFromLink()
{
    auto func = [this]() {
        link->Disconnect();
    };

    link->MarshalOnThread(func);
    return link->isConnected();
}

void RigolCommsMarshaler::sendAbstractAcquireCommand(const commands_Rigol::AbstractAcquireCommandPtr command)
{
    auto func = [this, command]() {
        protocol->sendSetAcquisitionCommand(link.get(), command);
    };

    link->MarshalOnThread(func);
}


void RigolCommsMarshaler::sendSetMeasurementCommand(const commands_Rigol::MeasureCommand_Item &command)
{
    if(!link->isConnected())
        return;
    auto func = [this, command]() {
            protocol->sendSetMeasurementCommand(link.get(), command);
    };

    link->MarshalOnThread(func);
}

void RigolCommsMarshaler::sendMeasurementRequest(const commands_Rigol::MeasureCommand_Item &command)
{
//    if(!link->isConnected())
//        return;
    auto func = [this, command]() {
            protocol->sendMeasurementRequest(link.get(), command);
    };

    link->MarshalOnThread(func);
}

void RigolCommsMarshaler::EmitByteArray(const QByteArray &data)
{
    auto func = [this, data]() {
        link->WriteBytes(data);
    };

    link->MarshalOnThread(func);
}

//////////////////////////////////////////////////////////////
/// React to Link Events
//////////////////////////////////////////////////////////////

void RigolCommsMarshaler::ConnectionOpened() const
{
    Emit([&](CommsEvents *ptr){ptr->ConnectionOpened();});
}

void RigolCommsMarshaler::ConnectionClosed() const
{
    Emit([&](CommsEvents *ptr){ptr->ConnectionClosed();});
}

void RigolCommsMarshaler::ReceiveData(const std::vector<uint8_t> &buffer) const
{
    protocol->ReceiveData(link.get(),buffer);
    //if there is something still in the queue we should send it
}

void RigolCommsMarshaler::CommunicationError(const std::string &type, const std::string &msg) const
{
    Emit([&](CommsEvents *ptr){ptr->CommunicationError(type,msg);});
}

void RigolCommsMarshaler::CommunicationUpdate(const std::string &name, const std::string &msg) const
{
    Emit([&](CommsEvents *ptr){ptr->CommunicationUpdate(name,msg);});
}

//////////////////////////////////////////////////////////////
/// IProtocolRigolEvents
//////////////////////////////////////////////////////////////
void RigolCommsMarshaler::ResponseReceived(const ILink* link_ptr, const std::vector<uint8_t> &buffer) const
{
    UNUSED(link_ptr);
    Emit([&](CommsEvents *ptr){ptr->NewDataReceived(buffer);});
}

void RigolCommsMarshaler::NewMeaurementReceived(const ILink* link_ptr, const commands_Rigol::RigolMeasurementStatus &status) const
{
    UNUSED(link_ptr);
    Emit([&](CommsEvents *ptr){ptr->NewMeaurementReceived(status);});
}

} //end of namespace comms_Rigol

