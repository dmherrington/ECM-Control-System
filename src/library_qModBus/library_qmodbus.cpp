#include "library_qmodbus.h"

Library_QModBus::Library_QModBus(const std::string &name, QObject *parent):
    QObject(parent),
    ICommunication(),
    commsMarshaler(nullptr),
    deviceName(name)
{
    qRegisterMetaType<common::comms::CommunicationConnection>("CommunicationConnection");
    qRegisterMetaType<common::comms::CommunicationUpdate>("CommunicationUpdate");

    deviceName = name;

}

///////////////////////////////////////////////////////////////////////////
/// Methods supporting the Connect/Disconnect from accompanying RS485 port
///////////////////////////////////////////////////////////////////////////

bool Library_QModBus::isSerialDeviceReadyToConnect() const
{
    if(commsMarshaler != nullptr)
        return true;
    return false;
}

void Library_QModBus::openSerialPortConnection(const common::comms::SerialConfiguration &config) const
{
    commsMarshaler->ConnectToSerialPort(config);
}

void Library_QModBus::closeSerialPortConnection() const
{

}
void Library_QModBus::writeToSerialPort(const QByteArray &msg) const
{
    commsMarshaler->WriteToSerialPort(msg);
}
bool Library_QModBus::isSerialPortOpen() const
{
    return false;
}

//////////////////////////////////////////////////////////////
/// Virtual methods allowed from comms::CommsEvents
//////////////////////////////////////////////////////////////

//!
//! \brief Sensoray::ConnectionStatusUpdated
//! \param update
//!
void Library_QModBus::ConnectionStatusUpdated(const common::comms::CommunicationUpdate &update) const
{
    if(update.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::CONNECTED)
    {
        emit signal_SensorayCommunicationUpdate(update);
        emit signal_SerialPortReadyToConnect();
    }
    else
    {
        emit signal_SensorayCommunicationUpdate(update);
    }
}

void Library_QModBus::SerialPortStatusUpdate(const common::comms::CommunicationUpdate &update) const
{
    emit signal_SerialPortUpdate(update);
}

void Library_QModBus::NewDataReceived(const QByteArray &buffer) const
{
    emit signal_RXNewSerialData(buffer);
}
