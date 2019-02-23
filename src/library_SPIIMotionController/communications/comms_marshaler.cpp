#include "comms_marshaler.h"

namespace Comms
{


//////////////////////////////////////////////////////////////
/// Setup
//////////////////////////////////////////////////////////////

CommsMarshaler::CommsMarshaler()
{
    //let us simplify this and do this upon constuction as there will only be one link
    link = std::make_shared<SPIILink>();
    link->AddListener(this);

    //let us simplify this and do this upon constuction as there will only be one protocol
    protocol = std::make_shared<SPIIProtocol>();
    //protocol->AddListner(this);
}


///////////////////////////////////////////////////////////////////////////////////////////////
/// Connect/Disconnect from Galil Methods
///////////////////////////////////////////////////////////////////////////////////////////////

std::shared_ptr<HANDLE> CommsMarshaler::ConnectToSimulation()
{
    HANDLE* commsLink = nullptr;

    link->SetSimulationConnection();
    link->Connect(commsLink);

    std::shared_ptr<HANDLE> sharedCommsLink(commsLink);

    return sharedCommsLink;
}

HANDLE CommsMarshaler::ConnectToSerialPort(const common::comms::SerialConfiguration &linkConfig)
{
    HANDLE commsLink;

    link->SetSerialConnection(linkConfig);
    link->Connect();

    return commsLink;
}

HANDLE CommsMarshaler::ConnectToEthernetPort(const common::comms::TCPConfiguration &linkConfig)
{
    HANDLE commsLink;

    link->SetEthernetConnection(linkConfig);
    link->Connect();

    return commsLink;
}

HANDLE CommsMarshaler::ConnectToPCIPort(const ACSC_PCI_SLOT &linkConfig)
{
    HANDLE commsLink;

    link->SetPCIConnection(linkConfig);
    link->Connect();

    return commsLink;
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

void CommsMarshaler::sendCustomSPIICommands(const std::vector<std::string> &stringCommands)
{
    auto func = [this, stringCommands]() {
        if(!link->isConnected())
            return;

            //protocol->SendCustomProtocolCommand(link.get(), stringCommands);
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
void CommsMarshaler::SendSPIIMessage(const T& message)
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

std::vector<SPII::Status_PerAxis> CommsMarshaler::requestAxisState(const SPII::RequestAxisStatus* request)
{
    std::vector<SPII::Status_PerAxis> rtnAxis;
    if(!link->isConnected())
        return rtnAxis;

    std::list<MotorAxis>::iterator it;
    std::list<MotorAxis> axisList = request->getAxis();

    for (it = axisList.begin(); it != axisList.end(); ++it){
        int binaryState;
        if(protocol->requestAxisStatus(*it,binaryState))
        {
            Status_PerAxis axisState;
            axisState.setAxis(*it);
            axisState.updateAxisStatus(binaryState);
            rtnAxis.push_back(axisState);
        }
    }
}

std::vector<SPII::Status_MotorPerAxis> CommsMarshaler::requestMotorState(const SPII::RequestMotorStatus* request)
{
    std::vector<SPII::Status_MotorPerAxis> rtnMotor;
    if(!link->isConnected())
        return rtnMotor;

    std::list<MotorAxis>::iterator it;
    std::list<MotorAxis> axisList = request->getAxis();

    for (it = axisList.begin(); it != axisList.end(); ++it){
        int binaryState;
        if(protocol->requestMotorStatus(*it,binaryState))
        {
            Status_MotorPerAxis motorState;
            motorState.setAxis(*it);
            motorState.updateMotorAxisStatus(binaryState);
            rtnMotor.push_back(motorState);
        }
    }
}

std::vector<SPII::Status_PositionPerAxis> CommsMarshaler::requestPosition(const SPII::RequestTellPosition* request)
{
    std::vector<SPII::Status_PositionPerAxis> rtnPosition;
    if(!link->isConnected())
        return rtnPosition;

    std::list<MotorAxis>::iterator it;
    std::list<MotorAxis> axisList = request->getAxis();

    for (it = axisList.begin(); it != axisList.end(); ++it){
        double position;
        if(protocol->requestPosition(*it,position))
        {
            Status_PositionPerAxis axisPosition;
            axisPosition.setAxis(*it);
            axisPosition.setPosition(position);
            rtnPosition.push_back(axisPosition);
        }
    }
}

template void CommsMarshaler::SendSPIIMessage<double>(const double&);

}//END Comms
