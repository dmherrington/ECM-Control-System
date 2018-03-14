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

void CommsMarshaler::sendAbstractGalilCommand(const AbstractCommandPtr command)
{
    std::cout<<"Lets send an abstract galil command"<<std::endl;

    auto func = [this, command]() {
            protocol->SendProtocolCommand(link.get(), command);
    };

    link->MarshalOnThread(func);
}

void CommsMarshaler::sendAbstractGalilMotionCommand(const AbstractCommandPtr command)
{
    std::cout<<"Lets send an abstract galil motion command"<<std::endl;

    auto func = [this, command]() {
            protocol->SendProtocolMotionCommand(link.get(), command);
    };

    link->MarshalOnThread(func);
}

void CommsMarshaler::sendAbstractGalilRequest(const AbstractRequestPtr request)
{
    auto func = [this, request]() {
            protocol->SendProtocolRequest(link.get(), request);
    };

    link->MarshalOnThread(func);
}

void CommsMarshaler::sendGalilProfileExecution(const AbstractCommandPtr &command)
{
    std::cout<<"Lets send an request to execute a specific galil profile."<<std::endl;
    auto func = [this, command]() {
        protocol->ExecuteProfile(link.get(), command);
    };

    link->MarshalOnThread(func);
}

void CommsMarshaler::sendGalilControllerGains(const CommandControllerGain &command)
{
    std::cout<<"Lets send an request to to update the controller gains."<<std::endl;
    auto func = [this, command]() {
        protocol->SendProtocolGainCommand(link.get(),command);
    };
    link->MarshalOnThread(func);
}

void CommsMarshaler::uploadProgram(const ProgramGeneric &program) const
{
    auto func = [this, &program] () {
        protocol->UploadNewProgram(link.get(), program);
    };
    link->MarshalOnThread(func);
}

void CommsMarshaler::downloadProgram() const
{
    auto func = [this] () {
        protocol->DownloadCurrentProgram(link.get());
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
    Emit([&](const CommsEvents *ptr){ptr->LinkConnected();});
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
/// MAVLINK Protocol Events
//////////////////////////////////////////////////////////////


//!
//! \brief A Message has been received over Mavlink protocol
//! \param linkName Link identifier which generated call
//! \param message Message that has been received
//!
void CommsMarshaler::MessageReceived(const double &message) const
{
    Emit([&](CommsEvents *ptr)
    {
        ptr->StatusMessage("Testing");
    });
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
        Emit([&](CommsEvents *ptr){ptr->NewStatusPosition(castStatus);});
        break;
    }
    case StatusTypes::STATUS_TELLINPUTS:
    {
        StatusInputs castStatus(*status.get()->as<StatusInputs>());
        Emit([&](CommsEvents *ptr){ptr->NewStatusInputs(castStatus);});
        break;
    }
    case StatusTypes::STATUS_SWITCH:
    {
        Status_Switch castStatus(*status.get()->as<Status_Switch>());

        Status_MotorEnabled motorEnabled;
        motorEnabled.setMotorEnabled(!castStatus.getSwitchStatus(SwitchStatus::MOTOR_OFF));
        Emit([&](CommsEvents *ptr){ptr->NewStatusMotorEnabled(motorEnabled);});

        Status_AxisInMotion axisMotion;
        axisMotion.setMotorMoving(castStatus.getSwitchStatus(SwitchStatus::AXIS_IN_MOTION));
        Emit([&](CommsEvents *ptr){ptr->NewStatusMotorInMotion(axisMotion);});
        break;
    }
    case StatusTypes::STATUS_STOPCODE:
    {
        Status_StopCode castStatus(*status.get()->as<Status_StopCode>());
        Emit([&](CommsEvents *ptr){ptr->NewStatusMotorStopCode(castStatus);});
        break;
    }
    case StatusTypes::STATUS_VARIABLELIST:
    {
        Status_VariableList castStatus(*status.get()->as<Status_VariableList>());
        Emit([&](CommsEvents *ptr){ptr->NewStatusVariableList(castStatus);});
        break;
    }
    case StatusTypes::STATUS_VARIABLEVALUE:
    {
        Status_VariableValue castStatus(*status.get()->as<Status_VariableValue>());
        Emit([&](CommsEvents *ptr){ptr->NewStatusVariableValue(castStatus);});
        break;
    }
    default:
        break;
    }
}

template void CommsMarshaler::SendGalilMessage<double>(const double&);

}//END Comms
