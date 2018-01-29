#include "munk_comms_marshaler.h"

namespace munk {
namespace comms{


//////////////////////////////////////////////////////////////
/// Setup
//////////////////////////////////////////////////////////////

MunkCommsMarshaler::MunkCommsMarshaler()
{
    //let us simplify this and do this upon constuction as there will only be one link
    link = std::make_shared<MunkSerialLink>();
    link->AddListener(this);

    //let us simplify this and do this upon constuction as there will only be one protocol
    protocol = std::make_shared<MunkProtocol>();
    protocol->AddListner(this);
}

MunkCommsMarshaler::~MunkCommsMarshaler()
{
    link->Disconnect();
}
///////////////////////////////////////////////////////////////////////////////////////////////
/// Connect/Disconnect from Munk Methods
///////////////////////////////////////////////////////////////////////////////////////////////

//!
//! \brief Connect to an already created link
//! \param linkName Name of link to connect to
//! \return True if connection succesfull, false otherwise
//!
bool MunkCommsMarshaler::ConnectToLink(const SerialConfiguration &linkConfig)
{
    link->setSerialConfiguration(linkConfig);
    link->Connect();
    return link->isConnected();
}

bool MunkCommsMarshaler::DisconnetFromLink()
{
    link->Disconnect();
    return link->isConnected();
}

///////////////////////////////////////////////////////////////////
/// Methods issuing voltage setpoints relevant to the munk program
///////////////////////////////////////////////////////////////////
void MunkCommsMarshaler::sendForwardVoltageSetpoint(const DataParameter::SegmentVoltageSetpoint &setpoint)
{
    std::cout<<"Lets send a forward voltage setpoint to the munk."<<std::endl;
    auto func = [this, setpoint]() {
            protocol->sendForwardVoltageSetpoint(link.get(), setpoint);
    };

    link->MarshalOnThread(func);
}

void MunkCommsMarshaler::sendReverseVoltageSetpoint(const DataParameter::SegmentVoltageSetpoint &setpoint)
{
    std::cout<<"Lets send a reverse voltage setpoint to the munk."<<std::endl;
    auto func = [this, setpoint]() {
            protocol->sendReverseVoltageSetpoint(link.get(), setpoint);
    };

    link->MarshalOnThread(func);
}

/////////////////////////////////////////////////////////////////////
/// Methods issuing current setpoints relevant to the munk program
/////////////////////////////////////////////////////////////////////

void MunkCommsMarshaler::sendForwardCurrentSetpoint(const DataParameter::SegmentCurrentSetpoint &setpoint)
{
    std::cout<<"Lets send a forward current setpoint to the munk."<<std::endl;
    auto func = [this, setpoint]() {
            protocol->sendForwardCurrentSetpoint(link.get(), setpoint);
    };

    link->MarshalOnThread(func);
}

void MunkCommsMarshaler::sendReverseCurrentSetpoint(const DataParameter::SegmentCurrentSetpoint &setpoint)
{
    std::cout<<"Lets send a reverse current setpoint to the munk."<<std::endl;
    auto func = [this, setpoint]() {
            protocol->sendReverseCurrentSetpoint(link.get(), setpoint);
    };

    link->MarshalOnThread(func);
}

/////////////////////////////////////////////////////////////////////
/// Methods issuing general segment data to the munk program
/////////////////////////////////////////////////////////////////////

void MunkCommsMarshaler::sendSegmentTime(const DataParameter::SegmentTimeGeneral &segment)
{
    std::cout<<"Lets send a segment time to the munk."<<std::endl;
    auto func = [this, segment]() {
            protocol->sendSegmentTime(link.get(), segment);
    };

    link->MarshalOnThread(func);
}

void MunkCommsMarshaler::sendCommitToEEPROM()
{
    DataParameter::ParameterMemoryWrite command;

    std::cout<<"Lets send a commit to EEPROM of the munk."<<std::endl;
    auto func = [this, command]() {
            protocol->sendCommitToEEPROM(link.get(), command);
    };

    link->MarshalOnThread(func);
}

//////////////////////////////////////////////////////////////
/// React to Link Events
//////////////////////////////////////////////////////////////

void MunkCommsMarshaler::ConnectionOpened() const
{
    Emit([&](CommsEvents *ptr){ptr->ConnectionOpened();});
}

void MunkCommsMarshaler::ConnectionClosed() const
{
    Emit([&](CommsEvents *ptr){ptr->ConnectionClosed();});
}

void MunkCommsMarshaler::ReceiveData(const std::vector<uint8_t> &buffer) const
{
    protocol->ReceiveData(link.get(),buffer);
}

void MunkCommsMarshaler::CommunicationError(const std::string &type, const std::string &msg) const
{
    Emit([&](CommsEvents *ptr){ptr->CommunicationError(type,msg);});
}

void MunkCommsMarshaler::CommunicationUpdate(const std::string &name, const std::string &msg) const
{
    Emit([&](CommsEvents *ptr){ptr->CommunicationUpdate(name,msg);});
}

//////////////////////////////////////////////////////////////
/// IProtocolMunkEvents
//////////////////////////////////////////////////////////////

void MunkCommsMarshaler::FaultCodeRegister1Received(const ILink* link_ptr) const
{
    UNUSED(link_ptr);

    Emit([&](CommsEvents *ptr){ptr->FaultCodeRegister1Received();});
}

void MunkCommsMarshaler::FaultCodeRegister2Received(const ILink* link_ptr) const
{
    UNUSED(link_ptr);

    Emit([&](CommsEvents *ptr){ptr->FaultCodeRegister2Received();});
}

void MunkCommsMarshaler::FaultCodeRegister3Received(const ILink* link_ptr) const
{
    UNUSED(link_ptr);

    Emit([&](CommsEvents *ptr){ptr->FaultCodeRegister3Received();});
}

void MunkCommsMarshaler::SegmentSetpointAcknowledged(const ILink* link_ptr) const
{
    UNUSED(link_ptr);

    Emit([&](CommsEvents *ptr){ptr->SegmentSetpointAcknowledged();});
}

void MunkCommsMarshaler::ExceptionResponseReceived(const ILink* link_ptr) const
{
    UNUSED(link_ptr);

    Emit([&](CommsEvents *ptr){ptr->ExceptionResponseReceived();});
}

} //end of namespace comms
} //end of namespace munk