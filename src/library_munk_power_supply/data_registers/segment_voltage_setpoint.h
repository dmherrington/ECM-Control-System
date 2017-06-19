#ifndef SEGMENT_VOLTAGE_SETPOINT_H
#define SEGMENT_VOLTAGE_SETPOINT_H

#include <string>
#include <vector>
#include <iostream>

#include "abstract_parameter.h"
#include "data/type_segment_level.h"
#include "data/type_segment_mode.h"

#include "data/type_current_voltage_prescale.h"
#include "data/type_voltage_set.h"


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

public:
    //!
    //! \brief updatePrescalePower
    //! \param value
    //!
    void updatePrescalePower(const Data::SegmentVIPower &value);

    //!
    //! \brief updateVoltageSetpoint
    //! \param value
    //!
    void updateVoltageSetpoint(const int &value);


private:
    //!
    //! \brief updatePrescaleBitArray
    //! \param bitArray
    //! \return
    //!
    uint32_t updatePrescaleBitArray(const uint32_t &bitArray) const;

    //!
    //! \brief updateSetPointBitArray
    //! \param bitArray
    //! \return
    //!
    uint32_t updateSetPointBitArray(const uint32_t &bitArray) const;

private:
    //!
    //! \brief level
    //!
    Data::SegmentLevel level;

    //!
    //! \brief mode
    //!
    Data::SegmentMode mode;

    //!
    //! \brief prescale
    //!
    Data::SegmentVIPower prescale;

    //!
    //! \brief voltage
    //!
    int voltage;
};

} //end of namespace DataParameter

#endif // SEGMENT_VOLTAGE_SETPOINT_H
