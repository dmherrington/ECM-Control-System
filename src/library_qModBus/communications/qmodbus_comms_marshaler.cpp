#include "qmodbus_comms_marshaler.h"

namespace comms_QModBus{


//////////////////////////////////////////////////////////////
/// Setup
//////////////////////////////////////////////////////////////

CommsMarshaler::CommsMarshaler()
{
    //let us simplify this and do this upon constuction as there will only be one link
    link = std::make_shared<QModBusLink>();
    link->AddListener(this);

    //let us simplify this and do this upon constuction as there will only be one protocol
    protocol = std::make_shared<QModBusProtocol>();
    protocol->AddListner(this);
}

CommsMarshaler::~CommsMarshaler()
{
    link->DisconnectFromDevice();
}
///////////////////////////////////////////////////////////////////////////////////////////////
/// Methods supporting the Connect/Disconnect from the RS485 port
///////////////////////////////////////////////////////////////////////////////////////////////

//!
//! \brief Connect to an already created link
//! \param linkName Name of link to connect to
//! \return True if connection succesfull, false otherwise
//!
bool CommsMarshaler::ConnectToSerialPort(const common::comms::SerialConfiguration &linkConfig)
{
    link->setSerialConfiguration(linkConfig);
    link->ConnectToDevice();
    return link->isConnected();
}

bool CommsMarshaler::ConnectToEthernetPort(const common::comms::TCPConfiguration &linkConfig)
{
    link->setTCPConfiguration(linkConfig);
    link->ConnectToDevice();
    return link->isConnected();
}

bool CommsMarshaler::DisconnectFromDevice()
{
    auto func = [this]() {
        link->DisconnectFromDevice();
    };

    link->MarshalOnThread(func);
    return link->isConnected();
}

bool CommsMarshaler::isDeviceConnected() const
{
    return link->isConnected();
}

void CommsMarshaler::WriteToSingleRegister(const ModbusRegister &regMsg) const
{
    auto func = [this, regMsg]() {
        if(!link->isConnected())
            return;

        protocol->writeDataToSingleRegister(link.get(),regMsg);
    };

    link->MarshalOnThread(func);
}

//////////////////////////////////////////////////////////////
/// React to Link Events
//////////////////////////////////////////////////////////////

void CommsMarshaler::CommunicationUpdate(const common::comms::CommunicationUpdate &update) const
{
    Emit([&](CommsEvents *ptr){ptr->ConnectionStatusUpdated(update);});
}

//////////////////////////////////////////////////////////////
/// IProtocolSensorayEvents
//////////////////////////////////////////////////////////////

void CommsMarshaler::SerialPortStatusUpdate(const common::comms::CommunicationUpdate &update) const
{
    //this is basically a duplicate of the communication update in this case
    UNUSED(update);
}

void CommsMarshaler::ResponseReceived(const QByteArray &buffer) const
{
    Emit([&](CommsEvents *ptr){ptr->NewDataReceived(buffer);});
}

} //end of namespace comms

