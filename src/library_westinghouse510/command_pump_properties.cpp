#include "command_pump_properties.h"

Command_PumpProperties::Command_PumpProperties()
{

}

void Command_PumpProperties::setPumpFlowRate(const registers_WestinghousePump::Register_FlowRate &desRate)
{
    this->m_OpsFlow = desRate;
}

void Command_PumpProperties::setPumpInitializationTime(const unsigned int &initializationTime)
{
    this->initTime = initializationTime;
}

registers_WestinghousePump::Register_FlowRate Command_PumpProperties::getPumpFlowRate() const
{
    return this->m_OpsFlow;
}

unsigned int Command_PumpProperties::getInitializationTime() const
{
    return this->initTime;
}
