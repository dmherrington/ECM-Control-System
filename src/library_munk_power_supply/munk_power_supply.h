#ifndef MUNK_POWER_SUPPLY_H
#define MUNK_POWER_SUPPLY_H
#include <iostream>
#include <QDebug>

#include "library_munk_power_supply_global.h"

#include "data_registers/segment_time_general.h"
#include "data_registers/segment_time_detailed.h"
#include "data_registers/segment_voltage_setpoint.h"
#include "data_registers/segment_current_setpoint.h"

#include "data/type_current_voltage_prescale.h"

class LIBRARY_MUNK_POWER_SUPPLYSHARED_EXPORT MunkPowerSupply
{

public:
    MunkPowerSupply();

    void generateMessages(const DataParameter::SegmentTimeDetailed &detailedSegmentData);

private:
    void generateSetpointMessages(const std::map<Data::RegisterDataObject,Data::SegmentLevel> &map, const Data::SegmentMode &mode, std::vector<DataParameter::SegmentVoltageSetpoint> &VMsgs, std::vector<DataParameter::SegmentCurrentSetpoint> &IMsgs);
};

#endif // MUNK_POWER_SUPPLY_H
