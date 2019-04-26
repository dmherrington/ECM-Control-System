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
    protocol->AddListner(this);
}

void CommsMarshaler::initializeBufferContents()
{
    auto func = [this]() {
        if(!link->isConnected())
            return;

            protocol->synchronizeBufferContents();
    };

    link->MarshalOnThread(func);
}

///////////////////////////////////////////////////////////////////////////////////////////////
/// Connect/Disconnect from Galil Methods
///////////////////////////////////////////////////////////////////////////////////////////////

bool CommsMarshaler::ConnectToSimulation(SPII_Settings &deviceSettings)
{
    HANDLE* commsLink = nullptr;

    link->SetSimulationConnection();
    if(link->Connect(commsLink))
    {
        deviceSettings.setDeviceHandle(commsLink);
        protocol->updateDeviceSettings(deviceSettings);

        //If the device is connected we should get the remaining parameters describing the device
        double numberOfAxis, dBufferIndex, numOfBuffers;
        if(protocol->requestNumberofAxes(numberOfAxis))
            deviceSettings.setAxisCount(static_cast<unsigned int>(numberOfAxis));
        if(protocol->requestDBufferIndex(dBufferIndex))
            deviceSettings.setDBufferIndex(static_cast<unsigned int>(dBufferIndex));
        if(protocol->requestNumberofBuffers(numOfBuffers))
            deviceSettings.setBufferCount(static_cast<unsigned int>(numOfBuffers));

        protocol->updateDeviceSettings(deviceSettings);

    }

    return link->isConnected();
}

SPII_Settings CommsMarshaler::ConnectToSerialPort(const common::comms::SerialConfiguration &linkConfig)
{
    SPII_Settings deviceSettings;

    HANDLE* commsLink = nullptr;

    link->SetSerialConnection(linkConfig);
    if(link->Connect(commsLink))
    {
        deviceSettings.setDeviceHandle(commsLink);
        protocol->updateDeviceSettings(deviceSettings);

        //If the device is connected we should get the remaining parameters describing the device
        double numberOfAxis, dBufferIndex, numOfBuffers;
        if(protocol->requestNumberofAxes(numberOfAxis))
            deviceSettings.setAxisCount(static_cast<unsigned int>(numberOfAxis));
        if(protocol->requestDBufferIndex(dBufferIndex))
            deviceSettings.setAxisCount(static_cast<unsigned int>(numberOfAxis));
        if(protocol->requestNumberofBuffers(numOfBuffers))
            deviceSettings.setAxisCount(static_cast<unsigned int>(numOfBuffers));
    }

    return deviceSettings;
}

bool CommsMarshaler::ConnectToEthernetPort(const common::comms::TCPConfiguration &linkConfig, SPII_Settings &deviceSettings)
{
    HANDLE* commsLink = nullptr;

    link->SetEthernetConnection(linkConfig);
    if(link->Connect(commsLink))
    {
        deviceSettings.setDeviceHandle(commsLink);
        protocol->updateDeviceSettings(deviceSettings);

        //If the device is connected we should get the remaining parameters describing the device
        double numberOfAxis, dBufferIndex, numOfBuffers;
        if(protocol->requestNumberofAxes(numberOfAxis))
            deviceSettings.setAxisCount(static_cast<unsigned int>(numberOfAxis));
        if(protocol->requestDBufferIndex(dBufferIndex))
            deviceSettings.setDBufferIndex(static_cast<unsigned int>(dBufferIndex));
        if(protocol->requestNumberofBuffers(numOfBuffers))
            deviceSettings.setBufferCount(static_cast<unsigned int>(numOfBuffers));

        protocol->updateDeviceSettings(deviceSettings);

    }

    return link->isConnected();
}

SPII_Settings CommsMarshaler::ConnectToPCIPort(const ACSC_PCI_SLOT &linkConfig)
{
    SPII_Settings deviceSettings;

    HANDLE* commsLink = nullptr;

    link->SetPCIConnection(linkConfig);
    if(link->Connect(commsLink))
    {
        deviceSettings.setDeviceHandle(commsLink);
        protocol->updateDeviceSettings(deviceSettings);

        //If the device is connected we should get the remaining parameters describing the device
        double numberOfAxis, dBufferIndex, numOfBuffers;
        if(protocol->requestNumberofAxes(numberOfAxis))
            deviceSettings.setAxisCount(static_cast<unsigned int>(numberOfAxis));
        if(protocol->requestDBufferIndex(dBufferIndex))
            deviceSettings.setAxisCount(static_cast<unsigned int>(numberOfAxis));
        if(protocol->requestNumberofBuffers(numOfBuffers))
            deviceSettings.setAxisCount(static_cast<unsigned int>(numOfBuffers));
    }

    return deviceSettings;
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

            protocol->SendCustomProtocolCommand(stringCommands);
    };

    link->MarshalOnThread(func);
}

void CommsMarshaler::sendAbstractSPIICommand(const AbstractCommandPtr command)
{
    auto func = [this, command]() {
        if(!link->isConnected())
            return;

            protocol->SendProtocolCommand(command);
    };

    link->MarshalOnThread(func);
}

void CommsMarshaler::sendAbstractSPIIMotionCommand(const AbstractCommandPtr command)
{
    auto func = [this, command]() {
        if(!link->isConnected())
            return;

            protocol->SendProtocolMotionCommand(command);
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

bool CommsMarshaler::commandMotionStop(const CommandStop &stop)
{
    if(!link->isConnected())
        return false;

    return protocol->commandKillMotion(stop);
}

bool CommsMarshaler::commandMotorDisable(const CommandMotorDisable &disable)
{
    if(!link->isConnected())
        return false;

    return protocol->commandMotorDisable(disable);
}

bool CommsMarshaler::commandMotorEnable(const CommandMotorEnable &enable)
{
    if(!link->isConnected())
        return false;

    return protocol->commandMotorEnable(enable);
}

std::vector<Status_PerAxis> CommsMarshaler::requestAxisState(const RequestAxisStatus* request)
{
    std::vector<Status_PerAxis> rtnAxis;
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
    return rtnAxis;
}

std::vector<Status_MotorAxisFault> CommsMarshaler::requestMotorFaultStatus(const Request_MotorFault* request)
{
    std::vector<Status_MotorAxisFault> rtnAxis;
    if(!link->isConnected())
        return rtnAxis;

    std::list<MotorAxis>::iterator it;
    std::list<MotorAxis> axisList = request->getAxis();

    for (it = axisList.begin(); it != axisList.end(); ++it){
        int binaryState;
        if(protocol->requestMotorFaults(*it,binaryState))
        {
            Status_MotorAxisFault motorFaultState;
            motorFaultState.setAxis(*it);
            motorFaultState.updateMotorFaultState(binaryState);
            rtnAxis.push_back(motorFaultState);
        }
    }
    return rtnAxis;
}

std::vector<Status_MotorPerAxis> CommsMarshaler::requestMotorState(const RequestMotorStatus* request)
{
    std::vector<Status_MotorPerAxis> rtnMotor;
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

    return rtnMotor;
}

std::vector<Status_PositionPerAxis> CommsMarshaler::requestPosition(const RequestTellPosition* request)
{
    std::vector<Status_PositionPerAxis> rtnPosition;
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
    return rtnPosition;
}

std::vector<Status_VariableValue> CommsMarshaler::requestVariableValue(const Request_TellVariable* request)
{

    std::vector<Status_VariableValue> rtnStatus;

    Status_VariableValue variableStatus;

    if(protocol->ReadIntegerVariableValue(*request, variableStatus))
        rtnStatus.push_back(variableStatus);

    return rtnStatus;
}

bool CommsMarshaler::requestSystemFaults(const Request_SystemFaults *request, Status_SystemFault &status)
{
    if(!link->isConnected())
        return false;

    int binaryState = 0;

    if(protocol->requestSystemFaults(binaryState))
    {
        status.setStatusValidity(true);
        status.updateSystemFaultState(binaryState);
        return true;
    }

    return false;
}

//////////////////////////////////////////////////////////////
/// Virtual methods imposed from IProtocolSPIIEvents
//////////////////////////////////////////////////////////////

void CommsMarshaler::NewBuffer_ProgramSuite(const bool &success, const SPII_CurrentProgram &program) const
{
    Emit([&](CommsEvents *ptr){ptr->NewBuffer_ProgramSuite(success,program);});
}

void CommsMarshaler::NewBufferState(const Status_BufferState &state) const
{
    Emit([&](CommsEvents *ptr){ptr->NewBufferState(state);});
}

void CommsMarshaler::NewBuffer_AvailableData(const BufferData &bufferData) const
{
    Emit([&](CommsEvents *ptr){ptr->NewBuffer_AvailableData(bufferData);});
}

void CommsMarshaler::NewStatus_OperationalLabels(const Operation_LabelList &labelList) const
{
    Emit([&](CommsEvents *ptr){ptr->NewStatus_OperationalLabels(labelList);});
}

void CommsMarshaler::NewStatus_UploadedOperationalVariables(const bool &success, const Operation_VariableList &variableList) const
{
    Emit([&](CommsEvents *ptr){ptr->NewStatus_UploadedOperationalVariables(success, variableList);});
}

void CommsMarshaler::NewStatus_PrivateOperationalVariables(const bool &success, const Operation_VariableList &variableList) const
{
    Emit([&](CommsEvents *ptr){ptr->NewStatus_PrivateOperationalVariables(success, variableList);});
}

void CommsMarshaler::NewStatus_UserOperationalVariables(const bool &success, const Operation_VariableList &variableList) const
{
    Emit([&](CommsEvents *ptr){ptr->NewStatus_UserOperationalVariables(success, variableList);});
}

void CommsMarshaler::NewStatus_CustomCommandReceived(const std::string &command, const std::string &response) const
{
    Emit([&](CommsEvents *ptr){ptr->NewStatus_CustomCommandReceived(command, response);});
}



template void CommsMarshaler::SendSPIIMessage<double>(const double&);

}//END Comms
