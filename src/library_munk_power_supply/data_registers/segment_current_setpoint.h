#ifndef SEGMENT_CURRENT_SETPOINT_H
#define SEGMENT_CURRENT_SETPOINT_H

#include <string>
#include <vector>
#include <iostream>
#include <map>

#include "abstract_parameter.h"

#include "data/type_supply_output.h"
#include "data/type_segment_level.h"
#include "data/type_current_set.h"

#include "data_registers/segment_current_data.h"

namespace DataParameter
{

//!
//! \brief The SegmentCurrentSetpoint class
//!
class SegmentCurrentSetpoint : public AbstractParameter
{
public:
    //!
    //! \brief SegmentCurrentSetpoint
    //! \param levelValue
    //! \param levelMode
    //!
    SegmentCurrentSetpoint(const Data::TypeSupplyOutput &outputNum, const Data::SegmentMode &levelMode);

public:
    //!
    //! \brief getParameterType
    //! \return
    //!
    virtual DataParameter::ParameterType getParameterType() const;

    //!
    //! \brief getByteArray
    //! \return
    //!
    virtual QByteArray getByteArray() const;

    //!
    //! \brief getDescription
    //! \return
    //!
    virtual std::string getDescription() const;

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
    std::map<Data::SegmentLevel, SegmentCurrentData> data;
};

} //end of namespace DataParameter

#endif // SEGMENT_CURRENT_SETPOINT_H
