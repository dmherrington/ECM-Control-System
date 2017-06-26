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

#include "data/type_fault_codes_general.h"

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

    //!
    //! \brief signal_NewCurrentSetpoint
    //! \param currentSetpoint
    //!
    void signal_NewCurrentSetpoint(const DataParameter::SegmentCurrentSetpoint &currentSetpoint);

    //!
    //! \brief signal_NewVoltageSetpoint
    //! \param voltageSetpoint
    //!
    void signal_NewVoltageSetpoint(const DataParameter::SegmentVoltageSetpoint &voltageSetpoint);

    //!
    //! \brief signal_NewTimeSetpoint
    //! \param segmentTime
    //!
    void signal_NewTimeSetpoint(const DataParameter::SegmentTimeDataGeneral &segmentTime);

    void messageGenerationProgress(const Data::DataFaultCodes &code);
    void transmissionProgress();
    void munkSupplyError();
    void serialPortError();

};

#endif // MUNK_POWER_SUPPLY_H
