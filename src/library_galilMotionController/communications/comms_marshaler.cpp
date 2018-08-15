#include "comms_marshaler.h"

namespace Comms
{


//////////////////////////////////////////////////////////////
/// Setup
//////////////////////////////////////////////////////////////

CommsMarshaler::CommsMarshaler():
    isConnected(false)
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
bool CommsMarshaler::ConnectToLink(const std::string &address)
{
    link->SetLinkAddress(address);
    isConnected = link->Connect();
    return isConnected;
}

bool CommsMarshaler::DisconnetLink()
{
    isConnected = link->Disconnect();
    return isConnected;
}

///////////////////////////////////////////////////////////////////////////////////////////////
/// Methods issuing Galil commands, requests, programs
///////////////////////////////////////////////////////////////////////////////////////////////

void CommsMarshaler::sendCustomGalilCommands(const std::vector<string> &stringCommands)
{
    //    if(!isConnected)
    //    {
    //        Emit([&](const CommsEvents *ptr){ptr->StatusMessage("Galil not connected. Cannot execute command.");});
    //        return;
    //    }

    auto func = [this, stringCommands]() {
            protocol->SendCustomProtocolCommand(link.get(), stringCommands);
    };

    link->MarshalOnThread(func);
}

void CommsMarshaler::sendAbstractGalilCommand(const AbstractCommandPtr command)
{
//    if(!isConnected)
//    {
//        Emit([&](const CommsEvents *ptr){ptr->StatusMessage("Galil not connected. Cannot execute command.");});
//        return;
//    }

    auto func = [this, command]() {
            protocol->SendProtocolCommand(link.get(), command);
    };

    link->MarshalOnThread(func);
}

void CommsMarshaler::sendAbstractGalilMotionCommand(const AbstractCommandPtr command)
{
//    if(!isConnected)
//    {
//        Emit([&](const CommsEvents *ptr){ptr->StatusMessage("Galil not connected. Cannot execute motion command.");});
//        return;
//    }

    auto func = [this, command]() {
            protocol->SendProtocolMotionCommand(link.get(), command);
    };

    link->MarshalOnThread(func);
}

void CommsMarshaler::sendAbstractGalilRequest(const AbstractRequestPtr request) const
{
//    if(!isConnected)
//    {
//        Emit([&](const CommsEvents *ptr){ptr->StatusMessage("Galil not connected. Cannot send request.");});
//        return;
//    }

    auto func = [this, request]() {
            protocol->SendProtocolRequest(link.get(), request);
    };

    link->MarshalOnThread(func);
}

//I do not think this method is called
void CommsMarshaler::sendGalilProfileExecution(const AbstractCommandPtr &command)
{
//    if(!isConnected)
//    {
//        Emit([&](const CommsEvents *ptr){ptr->StatusMessage("Galil not connected. Cannot execute profile.");});
//        return;
//    }

    auto func = [this, command]() {
        protocol->ExecuteProfile(link.get(), command);
    };

    link->MarshalOnThread(func);
}

void CommsMarshaler::sendGalilControllerGains(const CommandControllerGain &command)
{
//    if(!isConnected)
//    {
//        Emit([&](const CommsEvents *ptr){ptr->StatusMessage("Galil not connected. Cannot update controller gains.");});
//        return;
//    }

    auto func = [this, command]() {
        protocol->SendProtocolGainCommand(link.get(),command);
    };
    link->MarshalOnThread(func);
}

void CommsMarshaler::uploadProgram(const AbstractCommandPtr uploadCommand) const
{
//    if(!isConnected)
//    {
//        Emit([&](const CommsEvents *ptr){ptr->StatusMessage("Galil not connected. Cannot upload program.");});
//        return;
//    }

    auto func = [this, uploadCommand] () {
        protocol->UploadNewProgram(link.get(), uploadCommand);
    };
    link->MarshalOnThread(func);
}

void CommsMarshaler::downloadProgram(const AbstractCommandPtr downloadCommand) const
{
//    if(!isConnected)
//    {
//        Emit([&](const CommsEvents *ptr){ptr->StatusMessage("Galil not connected. Cannot download program.");});
//        return;
//    }

    auto func = [this, downloadCommand] () {
        protocol->DownloadCurrentProgram(link.get(), downloadCommand);
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

}

void CommsMarshaler::BadRequestResponse(const AbstractStatus &status) const
{

}

void CommsMarshaler::BadCommandResponse(const AbstractStatus &status) const
{

}

//////////////////////////////////////////////////////////////
/// Galil Protocol Events
//////////////////////////////////////////////////////////////

void CommsMarshaler::NewCustomStatusReceived(const string &initialCommand, const string &newStatus) const
{
    Emit([&](CommsEvents *ptr){ptr->CustomUserRequestReceived(initialCommand,newStatus);});
}

void CommsMarshaler::NewProgramUploaded(const ProgramGeneric &program) const
{
    Emit([&](CommsEvents *ptr){ptr->NewProgramUploaded(program);});

    //We now have a new program, let us query for the available labels and variables
    RequestListLabelsPtr requestLabels = std::make_shared<RequestListLabels>();
    sendAbstractGalilRequest(requestLabels);

    RequestListVariablesPtr requestVariables = std::make_shared<RequestListVariables>();
    sendAbstractGalilRequest(requestVariables);
}

void CommsMarshaler::NewProgramDownloaded(const ProgramGeneric &program) const
{
    Emit([&](CommsEvents *ptr){ptr->NewProgramDownloaded(program);});
}

void CommsMarshaler::ErrorBadCommand(const CommandType &type, const std::string &description) const
{
    Emit([&](CommsEvents *ptr){ptr->ErrorBadCommand(CommandToString(type),description);});
}

void CommsMarshaler::ErrorBadRequest(const RequestTypes &type, const string &description) const
{
    Emit([&](CommsEvents *ptr){ptr->ErrorBadCommand(RequestToString(type),description);});
}

void CommsMarshaler::NewPositionReceived(const Status_Position &status) const
{

}

void CommsMarshaler::NewStatusReceived(const std::vector<AbstractStatusPtr> &status) const
{
    for(int i = 0; i < status.size(); i++)
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
