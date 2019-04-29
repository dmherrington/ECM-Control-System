#include "munk_comms_marshaler.h"


namespace comms_Munk{

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
void MunkCommsMarshaler::ConnectToLink(const SerialConfiguration &linkConfig)
{
    link->setSerialConfiguration(linkConfig);
    link->Connect();

    if(link->isConnected())
    {
        auto func = [this]() {
            bool validLink = false;
            if(link->isConnected())
            {
                registers_Munk::Register_SupplyIdentifier registerRequest;
                if(!protocol->sendRegisterSupplyIdentifier(link.get(),registerRequest))
                    link->Disconnect(); //we are either connected to the wrong port or something else is wrong
                else
                    validLink = true;
            }
        };

        link->MarshalOnThread(func);
    }
}

bool MunkCommsMarshaler::ValidateConnection()
{

}

bool MunkCommsMarshaler::DisconnetFromLink()
{
    auto func = [this]() {
        link->Disconnect();
    };

    link->MarshalOnThread(func);
    return link->isConnected();
}

bool MunkCommsMarshaler::isConnected() const
{
    return link->isConnected();
}

void MunkCommsMarshaler::sendCompleteMunkParameters(const registers_Munk::SegmentTimeDetailed &segmentData, std::vector<registers_Munk::AbstractParameterPtr> parameters)
{
    auto func = [this, segmentData, parameters]() {
        if(!link->isConnected())
            return;

            protocol->updateCompleteMunkParameters(link.get(), segmentData, parameters);
    };

    link->MarshalOnThread(func);

}

///////////////////////////////////////////////////////////////////
/// Methods issuing voltage setpoints relevant to the munk program
///////////////////////////////////////////////////////////////////
void MunkCommsMarshaler::sendForwardVoltageSetpoint(const registers_Munk::SegmentVoltageSetpoint &setpoint)
{
    auto func = [this, setpoint]() {
        if(!link->isConnected())
            return;

            protocol->sendForwardVoltageSetpoint(link.get(), setpoint);
    };

    link->MarshalOnThread(func);
}

void MunkCommsMarshaler::sendReverseVoltageSetpoint(const registers_Munk::SegmentVoltageSetpoint &setpoint)
{
    auto func = [this, setpoint]() {
        if(!link->isConnected())
            return;

            protocol->sendReverseVoltageSetpoint(link.get(), setpoint);
    };

    link->MarshalOnThread(func);
}

/////////////////////////////////////////////////////////////////////
/// Methods issuing current setpoints relevant to the munk program
/////////////////////////////////////////////////////////////////////

void MunkCommsMarshaler::sendForwardCurrentSetpoint(const registers_Munk::SegmentCurrentSetpoint &setpoint)
{
    auto func = [this, setpoint]() {
        if(!link->isConnected())
            return;

            protocol->sendForwardCurrentSetpoint(link.get(), setpoint);
    };

    link->MarshalOnThread(func);
}

void MunkCommsMarshaler::sendReverseCurrentSetpoint(const registers_Munk::SegmentCurrentSetpoint &setpoint)
{
    auto func = [this, setpoint]() {
        if(!link->isConnected())
            return;

            protocol->sendReverseCurrentSetpoint(link.get(), setpoint);
    };

    link->MarshalOnThread(func);
}

/////////////////////////////////////////////////////////////////////
/// Methods issuing general segment data to the munk program
/////////////////////////////////////////////////////////////////////

void MunkCommsMarshaler::sendSegmentTime(const registers_Munk::SegmentTimeGeneral &segment)
{
    if(!link->isConnected())
        return;

    auto func = [this, segment]() {
            protocol->sendSegmentTime(link.get(), segment);
    };

    link->MarshalOnThread(func);
}

void MunkCommsMarshaler::sendCommitToEEPROM()
{
    registers_Munk::ParameterMemoryWrite command;
    command.setSlaveAddress(01);

    auto func = [this, command]() {
        if(!link->isConnected())
            return;

            protocol->sendCommitToEEPROM(link.get(), command);
    };

    link->MarshalOnThread(func);
}

/////////////////////////////////////////////////////////////////////
/// Methods issuing general fault & status requests
/////////////////////////////////////////////////////////////////////

void MunkCommsMarshaler::sendRegisterFaultStateRequest(const registers_Munk::RegisterFaultState &request)
{
    auto func = [this, request]() {
        if(!link->isConnected())
            return;

            protocol->sendFaultStateRequest(link.get(), request);
    };

    link->MarshalOnThread(func);
}

void MunkCommsMarshaler::sendRegisterFaultStateClear(const registers_Munk::Register_FaultReset &request)
{
    auto func = [this, request]() {
        if(!link->isConnected())
            return;

            protocol->sendFaultStateReset(link.get(), request);
    };

    link->MarshalOnThread(func);
}

/////////////////////////////////////////////////////////////////////
/// Methods issuing general register pulse mode
/////////////////////////////////////////////////////////////////////

void MunkCommsMarshaler::sendRegisterPulseMode(const registers_Munk::Register_PulseMode &registerMode)
{
    auto func = [this, registerMode]() {
        if(!link->isConnected())
            return;

            protocol->sendPulseMode(link.get(), registerMode);
    };

    link->MarshalOnThread(func);
}

//////////////////////////////////////////////////////////////
/// React to Link Events
//////////////////////////////////////////////////////////////

void MunkCommsMarshaler::ConnectionOpened() const
{
    //Emit([&](CommsEvents *ptr){ptr->ConnectionOpened();});
}

void MunkCommsMarshaler::ConnectionClosed() const
{
    Emit([&](CommsEvents *ptr){ptr->ConnectionClosed();});
}

void MunkCommsMarshaler::ReceiveData(const std::vector<uint8_t> &buffer) const
{
    //protocol->ReceiveData(link.get(),buffer);
    UNUSED(buffer);
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

void MunkCommsMarshaler::RegisterPulseModeUpdated(const bool &success, const registers_Munk::Register_PulseMode &registerMode) const
{
    UNUSED(success);
    Emit([&](CommsEvents *ptr){ptr->NewPulseMode(success,registerMode);});
}

void MunkCommsMarshaler::FaultCodeReceived(const ILink* link_ptr, const data_Munk::FaultRegisterType &faultRegister, const unsigned int &code) const
{
    UNUSED(link_ptr);
    Emit([&](CommsEvents *ptr){ptr->FaultCodeReceived(faultRegister,code);});
}

void MunkCommsMarshaler::FaultStateCleared(const ILink *link_ptr) const
{
    UNUSED(link_ptr);
    Emit([&](CommsEvents *ptr){ptr->FaultStateCleared();});
}

void MunkCommsMarshaler::SegmentVoltageSetpointAcknowledged(const ILink* link_ptr, const data_Munk::SegmentMode &mode) const
{
    UNUSED(link_ptr);
    if(mode == data_Munk::SegmentMode::FORWARD)
        Emit([&](CommsEvents *ptr){ptr->ForwardVoltageSetpointAcknowledged();});
    else
        Emit([&](CommsEvents *ptr){ptr->ReverseVoltageSetpointAcknowledged();});
}

void MunkCommsMarshaler::SegmentCurrentSetpointAcknowledged(const ILink* link_ptr , const data_Munk::SegmentMode &mode) const
{
    UNUSED(link_ptr);
    if(mode == data_Munk::SegmentMode::FORWARD)
        Emit([&](CommsEvents *ptr){ptr->ForwardCurrentSetpointAcknowledged();});
    else
        Emit([&](CommsEvents *ptr){ptr->ReverseCurrentSetpointAcknowledged();});
}

void MunkCommsMarshaler::SegmentTimeSetpointAcknowledged(const ILink* link_ptr) const
{
    UNUSED(link_ptr);
    Emit([&](CommsEvents *ptr){ptr->SegmentTimeAcknowledged();});
}

void MunkCommsMarshaler::SegmentCommittedToMemory(const ILink* link_ptr) const
{
    UNUSED(link_ptr);
    Emit([&](CommsEvents *ptr){ptr->SegmentCommitedToMemoryAcknowledged();});
}

void MunkCommsMarshaler::SegmentUploadComplete(const bool &success, const registers_Munk::SegmentTimeDetailed &segmentData) const
{
    Emit([&](CommsEvents *ptr){ptr->NewSegmentSequence(success, segmentData);});
}

void MunkCommsMarshaler::ExceptionResponseReceived(const ILink* link_ptr, const data_Munk::MunkRWType &type, const uint8_t &code) const
{
    UNUSED(link_ptr);
    Emit([&](CommsEvents *ptr){ptr->ExceptionResponseReceived(type,data_Munk::ExceptionCodeToString(data_Munk::ExceptionCodeFromInt(code)));});
}


} //end of namespace comms_Munk

