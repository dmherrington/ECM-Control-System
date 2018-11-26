#ifndef PUMP_COMMAND_H
#define PUMP_COMMAND_H

#include "data_registers/register_flow_rate.h"
#include "data_registers/register_operation_signal.h"

using namespace registers_WestinghousePump;

class PumpCommand
{
public:
    PumpCommand();

public:
    void setPumpFlowRate(const registers_WestinghousePump::Register_FlowRate &desRate);

    void setPumpOperations(const registers_WestinghousePump::Register_OperationSignal &desOps);

public:
    Register_FlowRate getPumpFlowRate() const;

    Register_OperationSignal getPumpOperations() const;

private:
    Register_FlowRate m_OpsFlow;
    Register_OperationSignal m_OpsTime;
};

#endif // PUMP_COMMAND_H
