#ifndef COMMAND_PUMP_PROPERTIES_H
#define COMMAND_PUMP_PROPERTIES_H

#include "data_registers/register_flow_rate.h"
#include "data_registers/register_operation_signal.h"

class Command_PumpProperties
{
public:

    Command_PumpProperties() = default;

    Command_PumpProperties(const Command_PumpProperties &copy)
    {
        this->m_OpsFlow = copy.m_OpsFlow;
        this->initTime = copy.initTime;
    }

public:
    void setPumpFlowRate(const registers_WestinghousePump::Register_FlowRate &desRate)
    {
        this->m_OpsFlow = desRate;
    }

    void setPumpInitializationTime(const unsigned int &initializationTime)
    {
        this->initTime = initializationTime;
    }

public:
    registers_WestinghousePump::Register_FlowRate getPumpFlowRate() const
    {
        return this->m_OpsFlow;
    }

    unsigned int getInitializationTime() const
    {
        return this->initTime;
    }

private:
    registers_WestinghousePump::Register_FlowRate m_OpsFlow;
    unsigned int initTime = 0;
};

#endif // COMMAND_PUMP_PROPERTIES_H
