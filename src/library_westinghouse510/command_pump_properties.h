#ifndef COMMAND_PUMP_PROPERTIES_H
#define COMMAND_PUMP_PROPERTIES_H

#include "data_registers/register_flow_rate.h"
#include "data_registers/register_operation_signal.h"

class Command_PumpProperties
{
public:
    Command_PumpProperties();

public:
    void setPumpFlowRate(const registers_WestinghousePump::Register_FlowRate &desRate);

    void setPumpInitializationTime(const unsigned int &initializationTime);

public:
    registers_WestinghousePump::Register_FlowRate getPumpFlowRate() const;

    unsigned int getInitializationTime() const;

private:
    registers_WestinghousePump::Register_FlowRate m_OpsFlow;
    unsigned int initTime = 0;
};

#endif // COMMAND_PUMP_PROPERTIES_H
