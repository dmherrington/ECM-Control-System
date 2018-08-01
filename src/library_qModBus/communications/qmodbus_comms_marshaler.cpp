#include "qmodbus_comms_marshaler.h"

namespace comms_QModBus{


//////////////////////////////////////////////////////////////
/// Setup
//////////////////////////////////////////////////////////////

CommsMarshaler::CommsMarshaler()
{
    m_Session = new SensoraySession();

    //let us simplify this and do this upon constuction as there will only be one link
    link = std::make_shared<QModBusLink>();
    link->AddListener(this);
    link->updateCurrentSession(m_Session);

    //let us simplify this and do this upon constuction as there will only be one protocol
    protocol = std::make_shared<QModBusProtocol>();
    protocol->AddListner(this);
    protocol->updateCurrentSession(m_Session);
}

CommsMarshaler::~CommsMarshaler()
{
    protocol->closeSerialPort();
    link->DisconnectFromDevice();
    if(m_Session) delete m_Session;
    m_Session = nullptr;
}
///////////////////////////////////////////////////////////////////////////////////////////////
/// Methods supporting the Connect/Disconnect from the RS485 port
///////////////////////////////////////////////////////////////////////////////////////////////

//!
//! \brief Connect to an already created link
//! \param linkName Name of link to connect to
//! \return True if connection succesfull, false otherwise
//!
bool CommsMarshaler::ConnectToLink(const common::comms::SerialConfiguration &linkConfig)
{
    link->setSerialConfiguration(linkConfig);
    link->ConnectToDevice();
    return link->isConnected();
}

bool CommsMarshaler::DisconnetFromLink()
{
    auto func = [this]() {
        link->DisconnectFromDevice();
    };

    link->MarshalOnThread(func);
    return link->isConnected();
}

bool CommsMarshaler::isLinkConnected() const
{
    return link->isConnected();
}

void CommsMarshaler::WriteToSerialPort(const QByteArray &data) const
{

    auto func = [this, command]() {
            protocol->SendProtocolCommand(link.get(), command);
    };

    link->MarshalOnThread(func);

    auto func = [this, data]() {
        protocol->transmitDataToSerialPort(data);
    };
    link->MarshalOnThread(func);
}

void CommsMarshaler::resetSensorayIO()
{
    auto func = [this]() {
        protocol->resetSensorayIO();
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
    Emit([&](CommsEvents *ptr){ptr->SerialPortStatusUpdate(update);});
}

void CommsMarshaler::ResponseReceived(const QByteArray &buffer) const
{
    Emit([&](CommsEvents *ptr){ptr->NewDataReceived(buffer);});
}

} //end of namespace comms

