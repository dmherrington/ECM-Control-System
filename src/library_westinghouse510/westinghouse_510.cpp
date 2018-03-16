#include "westinghouse_510.h"

Westinghouse510::Westinghouse510(const common::comms::ICommunication *commsObject, const int &pumpAddress)
{
    qRegisterMetaType<common::comms::CommunicationConnection>("CommunicationConnection");
    qRegisterMetaType<common::comms::CommunicationUpdate>("CommunicationUpdate");

    this->m_Comms = commsObject;
    connect(dynamic_cast<const QObject*>(m_Comms),SIGNAL(signal_SerialPortConnection(common::comms::CommunicationUpdate)),this,SLOT(slot_SerialPortConnection(common::comms::CommunicationUpdate)));
    connect(dynamic_cast<const QObject*>(m_Comms),SIGNAL(signal_SerialPortUpdate(common::comms::CommunicationUpdate)),this,SLOT(slot_SerialPortUpdate(common::comms::CommunicationUpdate)));
    connect(dynamic_cast<const QObject*>(m_Comms),SIGNAL(signal_RXNewSerialData(QByteArray)),this,SLOT(slot_SerialPortReceivedData(QByteArray)));

    this->m_State = new Westinghouse510_State();

//    this->m_State->flowRate.AddNotifier(this,[this]
//    {
//        emit signal_PumpFlowUpdated(m_State->flowRate.get());
//    });

//    this->m_State->pumpON.AddNotifier(this,[this]
//    {
//        emit signal_PumpOperating(m_State->pumpON.get());
//    });

    m_DataFraming = new WestinghouseDataFraming(pumpAddress);

}

void Westinghouse510::setPumpFlowRate(const Register_FlowRate &desRate)
{
    this->m_Comms->writeToSerialPort(desRate.getFullMessage());
}

void Westinghouse510::setPumpOperations(const Register_OperationSignal &desOps)
{
    this->m_Comms->writeToSerialPort(desOps.getFullMessage());
}

void Westinghouse510::slot_SerialPortConnection(const common::comms::CommunicationConnection &connection)
{
    this->m_State->pumpConnected = connection.isConnected();
}

void Westinghouse510::slot_SerialPortUpdate(const common::comms::CommunicationUpdate &update)
{

}

void Westinghouse510::slot_SerialPortReceivedData(const QByteArray &data)
{
    for(int i = 0; i < data.size(); i++)
    {
        FramingState currentState = m_DataFraming->additionalByteRecevied(data.at(i));
        if(currentState == FramingState::RECEIVED_ENTIRE_MESSAGE)
        {
            WestinghouseMessage rxMSG = m_DataFraming->getCurrentMessage();
            this->parseReceivedMessage(rxMSG);
        }
    }
}

void Westinghouse510::parseReceivedMessage(const WestinghouseMessage &msg)
{
    if(msg.isException() == data_WestinghousePump::ExceptionType::EXCEPTION)
    {

    }
    else {
        if(msg.isReadWriteType() == data_WestinghousePump::ReadWriteType::WRITE)
        {
            uint8_t dataHi = msg.getDataByte(2);
            uint8_t dataLo = msg.getDataByte(3);
            int registerCode = dataLo | (dataHi<<8);
            RegisterType rxType = RegisterTypeFromInt(registerCode);
            switch (rxType) {
            case RegisterType::FLOWRATE:
            {
                Register_FlowRate writeFlow;
                writeFlow.parseFromArray(msg.getDataArray());
                if(m_State->flowRate.set(writeFlow.getVolumetricFlow()))
                {
                    emit signal_PumpFlowUpdated(writeFlow.getVolumetricFlow());
                }
                break;
            }
            case RegisterType::OPERATION_SIGNAL:
            {
                Register_OperationSignal writeOps;
                writeOps.parseFromArray(msg.getDataArray());
                if(m_State->pumpON.set(writeOps.isRun()))
                {
                    emit signal_PumpOperating(writeOps.isRun());
                }
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
