#include "library_qmodbus.h"

Library_QModBus::Library_QModBus(const std::string &name, QObject *parent):
    QObject(parent),
    ICommunication(),
    commsMarshaler(nullptr),
    deviceName(name)
{
    qRegisterMetaType<ModbusRegister>("ModbusRegister");
    qRegisterMetaType<common::comms::CommunicationConnection>("CommunicationConnection");
    qRegisterMetaType<common::comms::CommunicationUpdate>("CommunicationUpdate");

    deviceName = name;

    commsMarshaler = new comms_QModBus::CommsMarshaler();
    commsMarshaler->AddSubscriber(this);
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

void Library_QModBus::openEthernetPortConnection(const common::comms::TCPConfiguration &config) const
{
    commsMarshaler->ConnectToEthernetPort(config);
}

void Library_QModBus::openSerialPortConnection(const common::comms::SerialConfiguration &config) const
{
    commsMarshaler->ConnectToSerialPort(config);
}

void Library_QModBus::closePortConnection() const
{
    commsMarshaler->DisconnectFromDevice();
}

void Library_QModBus::writeModbusDataPort(const ModbusRegister &regMsg) const
{
    commsMarshaler->WriteToSingleRegister(regMsg);
}

void Library_QModBus::readModbusDataPort(const ModbusRegister &regMsg) const
{
    commsMarshaler->ReadFromRegisters(regMsg);
}

bool Library_QModBus::isModbusPortOpen() const
{
    return commsMarshaler->isDeviceConnected();
}

//////////////////////////////////////////////////////////////
/// Virtual methods allowed from comms::CommsEvents
//////////////////////////////////////////////////////////////

//!
//! \brief Sensoray::ConnectionStatusUpdated
//! \param update
//!
void Library_QModBus::CommunicationStatusUpdate(const common::comms::CommunicationUpdate &update) const
{
    if(update.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::CONNECTED)
    {
        emit signal_PortUpdate(update);
        emit signal_PortReadyToConnect();
    }
    else
    {
        emit signal_PortUpdate(update);
    }
}

void Library_QModBus::ModbusFailedDataTransmission(const common::comms::CommunicationUpdate &update, const ModbusRegister &reg) const
{
    emit signal_PortFailedTransmission(update, reg);
}

void Library_QModBus::NewRegisterData(const ModbusRegister &regObj) const
{
    emit signal_RXNewRegister(regObj);
}

void Library_QModBus::NewDataReceived(const QByteArray &buffer) const
{
    emit signal_RXNewPortData(buffer);
}
