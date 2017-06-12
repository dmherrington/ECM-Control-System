#ifndef MUNK_POWER_SUPPLY_H
#define MUNK_POWER_SUPPLY_H
#include <iostream>
#include <QDebug>

#include "library_munk_power_supply_global.h"

#include "data_registers/segment_time_general.h"
#include "data_registers/segment_time_detailed.h"

class LIBRARY_MUNK_POWER_SUPPLYSHARED_EXPORT MunkPowerSupply
{

public:
    MunkPowerSupply();

    void generateMessages(const DataParameter::SegmentTimeDetailed &detailedSegmentData);


private:

};

#endif // MUNK_POWER_SUPPLY_H
