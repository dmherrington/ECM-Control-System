#ifndef SEGMENT_VOLTAGE_SETPOINT_H
#define SEGMENT_VOLTAGE_SETPOINT_H

#include <string>
#include <vector>
#include <iostream>
#include <map>

#include "abstract_parameter.h"

#include "data/type_supply_output.h"
#include "data/type_segment_level.h"

#include "data_registers/segment_voltage_data.h"

namespace DataParameter
{
//!
//! \brief The SegmentVoltageSetpoint class
//!
class SegmentVoltageSetpoint : public AbstractParameter
{

public:
    //!
    //! \brief SegmentVoltageSetpoint
    //! \param levelValue
    //! \param levelMode
    //!
    SegmentVoltageSetpoint(const Data::SegmentLevel &levelValue, const Data::SegmentMode &levelMode);

public:
    //!
    //! \brief getParameterType
    //! \return
    //!
    virtual DataParameter::ParameterType getParameterType() const;

    //!
    //! \brief getDescription
    //! \return
    //!
    virtual std::string getDescription() const;

    //!
    //! \brief getByteArray
    //! \return
    //!
    virtual QByteArray getByteArray() const;

private:
    //!
    //! \brief supplyOutput
    //!
    Data::TypeSupplyOutput supplyOutput;

    //!
    //! \brief mode
    //!
    Data::SegmentMode mode;

    //!
    //! \brief data
    //!
    std::map<Data::SegmentLevel, SegmentVoltageData> data;
};

} //end of namespace DataParameter

#endif // SEGMENT_VOLTAGE_SETPOINT_H
