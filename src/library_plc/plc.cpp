#include "plc.h"

PLC::PLC(const int &plcAddress, const std::string &name):
    deviceName(name)
{
    qRegisterMetaType<common::comms::CommunicationConnection>("CommunicationConnection");
    qRegisterMetaType<common::comms::CommunicationUpdate>("CommunicationUpdate");

    m_Comms = new Library_QModBus();

//    connect(dynamic_cast<const QObject*>(m_Comms),SIGNAL(signal_SerialPortUpdate(common::comms::CommunicationUpdate)),this,SLOT(slot_SerialPortUpdate(common::comms::CommunicationUpdate)));
//    connect(dynamic_cast<const QObject*>(m_Comms),SIGNAL(signal_RXNewSerialData(QByteArray)),this,SLOT(slot_SerialPortReceivedData(QByteArray)));

    m_DataFraming = new comms_PLC::PLCDataFraming(plcAddress);
}


bool PLC::isPLCConnected() const
{
    return this->m_Comms->isModbusPortOpen();
}

void PLC::openPLCConnection(const common::comms::TCPConfiguration &linkConfig)
{
    this->m_Comms->openSerialPortConnection(config);
}

void PLC::closePLCConnection()
{
    this->m_Comms->closePortConnection();
}


void PLC::slot_PortUpdate(const common::comms::CommunicationUpdate &update)
{
    using namespace common::comms;
    switch (update.getUpdateType()) {
    case CommunicationUpdate::UpdateTypes::ALERT:

        break;
    case CommunicationUpdate::UpdateTypes::CONNECTED:
    {
        m_State->pumpConnected.set(true);
        registers_WestinghousePump::Register_RunSource updateRunSource(registers_WestinghousePump::Register_RunSource::SourceSetting::SOURCE_RS485);
        this->m_Comms->writeModbusDataPort(updateRunSource.getModbusRegister());

        this->ceasePumpOperations();

        break;
    }
    case CommunicationUpdate::UpdateTypes::DISCONNECTED:
        m_State->pumpConnected.set(false);
        break;
//    case CommunicationUpdate::UpdateTypes::ERROR:

//        break;
    case CommunicationUpdate::UpdateTypes::UPDATE:

        break;
    default:
        break;
    }
    emit signal_PumpCommunicationUpdate(update);
}

void PLC::slot_PortReceivedData(const QByteArray &data)
{
    for(int i = 0; i < data.size(); i++)
    {
        comms_PLC::PLCMessageFramingState currentState = m_DataFraming->additionalByteRecevied(data.at(i));
        if(currentState == comms_PLC::PLCMessageFramingState::RECEIVED_ENTIRE_MESSAGE)
        {
            comms_PLC::PLCMessage rxMSG = m_DataFraming->getCurrentMessage();
            this->parseReceivedMessage(rxMSG);
        }
    }
}

void PLC::parseReceivedMessage(const comms_PLC::PLCMessage &msg)
{
    if(msg.isException() == data_PLC::PLCExceptionTypes::EXCEPTION)
    {

    }
    else {
        data_PLC::RWType currentType = msg.isReadWriteType();

        if(currentType == data_PLC::RWType::WRITE)
        {

        }
        else if(currentType == data_PLC::RWType::READ)
        {

        }
        else
        {

        }
    }
}
