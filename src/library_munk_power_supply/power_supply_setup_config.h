#ifndef POWER_SUPPLY_SETUP_CONFIG_H
#define POWER_SUPPLY_SETUP_CONFIG_H

#include <QJsonArray>
#include <QJsonObject>

#include "data_registers/segment_time_detailed.h"
#include "data_registers/register_pulse_mode.h"

class PowerSupply_SetupConfig
{
public:
    PowerSupply_SetupConfig();

public:
    void writeToJSON(QJsonObject &saveObject);

    void readFromJSON(const QJsonObject &openObject);

public:
    registers_Munk::SegmentTimeDetailed m_MunkSegment;

    registers_Munk::Register_PulseMode m_MunkPulseMode;

};

#endif // POWER_SUPPLY_SETUP_CONFIG_H
