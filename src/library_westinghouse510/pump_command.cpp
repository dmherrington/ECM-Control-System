#include "pump_command.h"

PumpCommand::PumpCommand()
{

}

void PumpCommand::setPumpFlowRate(const registers_WestinghousePump::Register_FlowRate &desRate)
{
    this->m_OpsFlow = desRate;
}

void PumpCommand::setPumpOperations(const registers_WestinghousePump::Register_OperationSignal &desOps)
{
    this->m_OpsTime = desOps;
}

Register_FlowRate PumpCommand::getPumpFlowRate() const
{
    return this->m_OpsFlow;
}

Register_OperationSignal PumpCommand::getPumpOperations() const
{
    return this->m_OpsTime;
}
