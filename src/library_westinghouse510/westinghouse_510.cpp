#include "westinghouse_510.h"

namespace westinghousePump {

Westinghouse510::Westinghouse510(const common::comms::ICommunication *commsObject, const int &pumpAddress)
{
    qRegisterMetaType<common::comms::CommunicationConnection>("CommunicationConnection");
    qRegisterMetaType<common::comms::CommunicationUpdate>("CommunicationUpdate");

    this->m_Comms = commsObject;
    connect(dynamic_cast<const QObject*>(m_Comms),SIGNAL(signal_SerialPortConnection(common::comms::CommunicationUpdate)),this,SLOT(slot_SerialPortConnection(common::comms::CommunicationUpdate)));
    connect(dynamic_cast<const QObject*>(m_Comms),SIGNAL(signal_SerialPortUpdate(common::comms::CommunicationUpdate)),this,SLOT(slot_SerialPortUpdate(common::comms::CommunicationUpdate)));
    connect(dynamic_cast<const QObject*>(m_Comms),SIGNAL(signal_RXNewSerialData(QByteArray)),this,SLOT(slot_SerialPortReceivedData(QByteArray)));

    this->m_State = new Westinghouse510_State();

    this->m_State->flowRate.AddNotifier(this,[this]
    {
        emit signal_PumpFlowUpdated(m_State->flowRate.get());
    });

    this->m_State->pumpON.AddNotifier(this,[this]
    {
        emit signal_PumpOperating(m_State->pumpON.get());
    });

    m_DataFraming = new comms::WestinghouseDataFraming(pumpAddress);

}

void Westinghouse510::updatePumpFlowRate(const registers::Register_FlowRate &desRate)
{
    this->m_Comms->writeToSerialPort(desRate.getFullMessage());
}

void Westinghouse510::updatePumpOperations(const registers::Register_OperationSignal &desOps)
{
    this->m_Comms->writeToSerialPort(desOps.getFullMessage());
}

void Westinghouse510::slot_SerialPortConnection(const common::comms::CommunicationConnection &connection)
{

}

void Westinghouse510::slot_SerialPortUpdate(const common::comms::CommunicationUpdate &update)
{

}

void Westinghouse510::slot_SerialPortReceivedData(const QByteArray &data)
{
    for(int i = 0; i < data.size(); i++)
    {
        comms::FramingState currentState = m_DataFraming->additionalByteRecevied(data.at(i));
        if(currentState == comms::FramingState::RECEIVED_ENTIRE_MESSAGE)
        {
            comms::WestinghouseMessage rxMSG = m_DataFraming->getCurrentMessage();
            this->parseReceivedMessage(rxMSG);
        }
    }
}

void Westinghouse510::parseReceivedMessage(const comms::WestinghouseMessage &msg)
{
    if(msg.isException() == data::ExceptionType::EXCEPTION)
    {

    }
    else {
        if(msg.isReadWriteType() == data::ReadWriteType::WRITE)
        {
            uint8_t dataHi = msg.getDataByte(2);
            uint8_t dataLo = msg.getDataByte(3);
            int registerCode = dataLo | (dataHi<<8);
            registers::RegisterType rxType = registers::RegisterTypeFromInt(registerCode);
            switch (rxType) {
            case registers::RegisterType::FLOWRATE:
            {
                registers::Register_FlowRate writeFlow;
                writeFlow.parseFromArray(msg.getDataArray());
                emit signal_PumpFlowUpdated(writeFlow.getVolumetricFlow());
                break;
            }
            case registers::RegisterType::OPERATION_SIGNAL:
            {
                registers::Register_OperationSignal writeOps;
                writeOps.parseFromArray(msg.getDataArray());
                emit signal_PumpOperating(writeOps.isRun());
                break;
            }
            default:
                break;
            }
        }
        else
        {

        }
    }
}

} //end of namespace westinghousePump
