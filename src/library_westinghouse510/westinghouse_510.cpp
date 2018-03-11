#include "westinghouse_510.h"

namespace westinghousePump {

Westinghouse510::Westinghouse510(const common::comms::ICommunication *commsObject)
{
    qRegisterMetaType<common::comms::CommunicationConnection>("CommunicationConnection");
    qRegisterMetaType<common::comms::CommunicationUpdate>("CommunicationUpdate");

    this->m_Comms = commsObject;
    connect(dynamic_cast<const QObject*>(m_Comms),SIGNAL(signal_SerialPortConnectionUpdate(common::comms::CommunicationUpdate)),this,SLOT(slot_SerialPortConnectionUpdate(common::comms::CommunicationUpdate)));

    this->m_State = new Westinghouse510_State();

    this->m_State->flowRate.AddNotifier(this,[this]
    {
        emit signal_PumpFlowUpdated(m_State->flowRate.get());
    });

    this->m_State->pumpON.AddNotifier(this,[this]
    {
        emit signal_PumpOperating(m_State->pumpON.get());
    });
}

void Westinghouse510::updatePumpFlowRate(const registers::Register_FlowRate &desRate)
{
    this->m_Comms->writeToSerialPort(desRate.getFullMessage());
}

void Westinghouse510::updatePumpOperations(const registers::Register_OperationSignal &desOps)
{
    this->m_Comms->writeToSerialPort(desOps.getFullMessage());
}

void Westinghouse510::slot_SerialPortConnectionUpdate(const common::comms::CommunicationUpdate &update) const
{
    std::cout<<"This has been called"<<std::endl;
}

}
