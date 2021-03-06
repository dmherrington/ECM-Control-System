#include "comms_marshaler.h"

namespace Comms
{


//////////////////////////////////////////////////////////////
/// Setup
//////////////////////////////////////////////////////////////

CommsMarshaler::CommsMarshaler()
{
    //let us simplify this and do this upon constuction as there will only be one link
    link = std::make_shared<GalilLink>();
    link->AddListener(this);

    //let us simplify this and do this upon constuction as there will only be one protocol
    protocol = std::make_shared<GalilProtocol>();
    protocol->AddListner(this);
    //protocol->ResetMetadataForLink(); I dont know why this is done
}


///////////////////////////////////////////////////////////////////////////////////////////////
/// Connect/Disconnect from Galil Methods
///////////////////////////////////////////////////////////////////////////////////////////////

//!
//! \brief Connect to an already created link
//! \param linkName Name of link to connect to
//! \return True if connection succesfull, false otherwise
//!
void CommsMarshaler::ConnectToLink(const std::string &address)
{
    link->SetLinkAddress(address);
    link->Connect();
}

void CommsMarshaler::DisconnetLink()
{
    link->Disconnect();
}

bool CommsMarshaler::isDeviceConnected() const
{
    return link->isConnected();
}

///////////////////////////////////////////////////////////////////////////////////////////////
/// Methods issuing Galil commands, requests, programs
///////////////////////////////////////////////////////////////////////////////////////////////

void CommsMarshaler::sendCustomGalilCommands(const std::vector<string> &stringCommands)
{
    auto func = [this, stringCommands]() {
        if(!link->isConnected())
            return;

            protocol->SendCustomProtocolCommand(link.get(), stringCommands);
    };

    link->MarshalOnThread(func);
}

void CommsMarshaler::sendAbstractGalilCommand(const AbstractCommandPtr command)
{
    auto func = [this, command]() {
        if(!link->isConnected())
            return;

            protocol->SendProtocolCommand(link.get(), command);
    };

    link->MarshalOnThread(func);
}

void CommsMarshaler::sendAbstractGalilMotionCommand(const AbstractCommandPtr command)
{
    auto func = [this, command]() {
        if(!link->isConnected())
            return;

            protocol->SendProtocolMotionCommand(link.get(), command);
    };

    link->MarshalOnThread(func);
}

void CommsMarshaler::sendAbstractGalilRequest(const AbstractRequestPtr request) const
{
    auto func = [this, request]() {
        if(!link->isConnected())
            return;

            protocol->SendProtocolRequest(link.get(), request);
    };

    link->MarshalOnThread(func);
}

//I do not think this method is called
void CommsMarshaler::sendGalilProfileExecution(const AbstractCommandPtr &command)
{
    auto func = [this, command]() {
        if(!link->isConnected())
            return;

        protocol->ExecuteProfile(link.get(), command);
    };

    link->MarshalOnThread(func);
}

void CommsMarshaler::sendGalilControllerGains(const CommandControllerGain &command)
{
    auto func = [this, command]() {
        if(!link->isConnected())
            return;

        protocol->SendProtocolGainCommand(link.get(),command);
    };
    link->MarshalOnThread(func);
}

void CommsMarshaler::uploadProgram(const AbstractCommandPtr uploadCommand) const
{
    auto func = [this, uploadCommand] () {
        if(!link->isConnected())
        {
            this->NewProgramUploaded(false);
            return;
        }

        protocol->UploadNewProgram(link.get(), uploadCommand);
    };
    link->MarshalOnThread(func);
}

void CommsMarshaler::downloadProgram(const AbstractCommandPtr downloadCommand) const
{
    auto func = [this, downloadCommand] () {
        if(!link->isConnected())
            return;

        protocol->DownloadCurrentProgram(link.get(), downloadCommand);
    };
    link->MarshalOnThread(func);
}


void CommsMarshaler::uploadGalilProfileVariables(const ProgramVariableList &varList) const
{
    auto func = [this, varList] () {
        if(!link->isConnected())
            return;

        protocol->UploadProgramVariables(link.get(), varList);
    };
    link->MarshalOnThread(func);
}

///////////////////////////////////////////////////////////////////////////////////////////////
/// Query
///////////////////////////////////////////////////////////////////////////////////////////////

//!
//! \brief Issue a message to a given link
//!
//! The type used in the shall be an underlaying type which the protocol understands
//! \param link Link to send message on
//! \param message Message to send
//!
template <typename T>
void CommsMarshaler::SendGalilMessage(const T& message)
{
    UNUSED(message);

    ///////////////////
    /// Define function that sends the given message
    ///////////////////
//    auto func = [this, message]() {
//            protocol->SendProtocolMessage(link.get(), message);
//    };

//    link->MarshalOnThread(func);
}





//////////////////////////////////////////////////////////////
/// React to Link Events
//////////////////////////////////////////////////////////////

void CommsMarshaler::ConnectionUpdate(const common::comms::CommunicationUpdate &update) const
{
    Emit([&](CommsEvents *ptr){ptr->LinkConnectionUpdate(update);});
}

void CommsMarshaler::ConnectionOpened() const
{
    Emit([&](CommsEvents *ptr){ptr->LinkConnected();});
}

void CommsMarshaler::ConnectionClosed() const
{
    Emit([&](const CommsEvents *ptr){ptr->LinkDisconnected();});
}

void CommsMarshaler::StatusReceived(const AbstractStatus &status) const
{
    UNUSED(status);
}

void CommsMarshaler::BadRequestResponse(const AbstractStatus &status) const
{
    UNUSED(status);
}

void CommsMarshaler::BadCommandResponse(const AbstractStatus &status) const
{
    UNUSED(status);
}

//////////////////////////////////////////////////////////////
/// Galil Protocol Events
//////////////////////////////////////////////////////////////

void CommsMarshaler::NewCustomStatusReceived(const string &initialCommand, const string &newStatus) const
{
    Emit([&](CommsEvents *ptr){ptr->CustomUserRequestReceived(initialCommand,newStatus);});
}

void CommsMarshaler::NewProgramUploaded(const bool &success, const GalilCurrentProgram &program) const
{
    Emit([&](CommsEvents *ptr){ptr->NewProgramUploaded(success, program);});
}

void CommsMarshaler::NewVariableListUploaded(const bool &success, const ProgramVariableList &list) const
{
    Emit([&](CommsEvents *ptr){ptr->NewVariableListUploaded(success, list);});
}

void CommsMarshaler::NewProgramDownloaded(const ProgramGeneric &program) const
{
    Emit([&](CommsEvents *ptr){ptr->NewProgramDownloaded(program);});
}

void CommsMarshaler::ErrorBadCommand(const CommandType &type, const std::string &description) const
{
    Emit([&](CommsEvents *ptr){ptr->ErrorBadCommand(type,description);});
}

void CommsMarshaler::ErrorBadRequest(const RequestTypes &type, const string &description) const
{
    Emit([&](CommsEvents *ptr){ptr->ErrorBadRequest(type,description);});
}

void CommsMarshaler::NewPositionReceived(const Status_Position &status) const
{
    UNUSED(status);
}

void CommsMarshaler::NewStatusReceived(const std::vector<AbstractStatusPtr> &status) const
{
    for(size_t i = 0; i < status.size(); i++)
    {
        parseStatus(status.at(i));
    }
}

void CommsMarshaler::parseStatus(const AbstractStatusPtr &status) const
{
    switch (status->getStatusType()) {
    case StatusTypes::STATUS_POSITION:
    {
        Status_Position castStatus(*status.get()->as<Status_Position>());
        if(castStatus.isStatusValid())
            Emit([&](CommsEvents *ptr){ptr->NewStatusPosition(castStatus);});
        else
            std::cout<<"The status is no longer valid!"<<std::endl;
        break;
    }
    case StatusTypes::STATUS_TELLINPUTS:
    {
        StatusInputs castStatus(*status.get()->as<StatusInputs>());
        if(castStatus.isStatusValid())
            Emit([&](CommsEvents *ptr){ptr->NewStatusInputs(castStatus);});
        break;
    }
    case StatusTypes::STATUS_SWITCH:
    {
        Status_Switch castStatus(*status.get()->as<Status_Switch>());

        Status_MotorEnabled motorEnabled;
        motorEnabled.setMotorEnabled(!castStatus.getSwitchStatus(SwitchStatus::MOTOR_OFF));
        if(castStatus.isStatusValid())
            Emit([&](CommsEvents *ptr){ptr->NewStatusMotorEnabled(motorEnabled);});

        Status_AxisInMotion axisMotion;
        axisMotion.setMotorMoving(castStatus.getSwitchStatus(SwitchStatus::AXIS_IN_MOTION));
        if(castStatus.isStatusValid())
            Emit([&](CommsEvents *ptr){ptr->NewStatusMotorInMotion(axisMotion);});
        break;
    }
    case StatusTypes::STATUS_STOPCODE:
    {
        Status_StopCode castStatus(*status.get()->as<Status_StopCode>());
        if(castStatus.isStatusValid())
            Emit([&](CommsEvents *ptr){ptr->NewStatusMotorStopCode(castStatus);});
        break;
    }
    case StatusTypes::STATUS_LABELLIST:
    {
        Status_LabelList castStatus(*status.get()->as<Status_LabelList>());
        if(castStatus.isStatusValid())
            Emit([&](CommsEvents *ptr){ptr->NewStatusLabelList(castStatus);});
        break;
    }
    case StatusTypes::STATUS_VARIABLELIST:
    {
        Status_VariableList castStatus(*status.get()->as<Status_VariableList>());
        if(castStatus.isStatusValid())
            Emit([&](CommsEvents *ptr){ptr->NewStatusVariableList(castStatus);});
        break;
    }
    case StatusTypes::STATUS_VARIABLEVALUE:
    {
        Status_VariableValue castStatus(*status.get()->as<Status_VariableValue>());
        if(castStatus.isStatusValid())
            Emit([&](CommsEvents *ptr){ptr->NewStatusVariableValue(castStatus);});
        break;
    }
    default:
        break;
    }
}

template void CommsMarshaler::SendGalilMessage<double>(const double&);

}//END Comms
