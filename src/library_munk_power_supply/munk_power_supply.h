#ifndef MUNK_POWER_SUPPLY_H
#define MUNK_POWER_SUPPLY_H

#include <iostream>
#include <QDebug>
#include <QObject>

#include "library_munk_power_supply_global.h"

#include "data_registers/segment_time_general.h"

#include "data_registers/segment_time_data_detailed.h"
#include "data_registers/segment_time_detailed.h"

#include "data_registers/segment_voltage_setpoint.h"
#include "data_registers/segment_current_setpoint.h"

#include "data/type_supply_output.h"

#include "data/type_current_voltage_prescale.h"

class LIBRARY_MUNK_POWER_SUPPLYSHARED_EXPORT MunkPowerSupply : public QObject
{
    Q_OBJECT
private:
    struct structSetpoints
    {
        DataParameter::SegmentCurrentSetpoint iSet;
        DataParameter::SegmentVoltageSetpoint vSet;
    };

public:
    //!
    //! \brief MunkPowerSupply
    //!
    MunkPowerSupply();

    //!
    //! \brief generateMessages
    //! \param detailedSegmentData
    //!
    void generateMessages(const DataParameter::SegmentTimeDetailed &detailedSegmentData);

signals:
    void messageGenerationProgress();
    void transmissionProgress();
    void munkSupplyError();
    void serialPortError();

};

#endif // MUNK_POWER_SUPPLY_H
