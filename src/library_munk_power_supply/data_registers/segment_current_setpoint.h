#ifndef SEGMENT_CURRENT_SETPOINT_H
#define SEGMENT_CURRENT_SETPOINT_H


#include <string>
#include <vector>
#include <iostream>

#include "abstract_parameter.h"
#include "data/type_segment_level.h"
#include "data/type_segment_mode.h"
#include "data/type_current_factor.h"

#include "data/type_current_voltage_prescale.h"
#include "data/type_voltage_set.h"

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
    SegmentCurrentSetpoint(const Data::SegmentLevel &levelValue, const Data::SegmentMode &levelMode);

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

public:
    //!
    //! \brief updateCurrentFactor
    //! \param value
    //!
    void updateCurrentFactor(const Data::CurrentFactorType &value);

    //!
    //! \brief updatePrescalePower
    //! \param value
    //!
    void updatePrescalePower(const Data::SegmentVIPower &value);

    //!
    //! \brief updateCurrentSetpoint
    //! \param value
    //!
    void updateCurrentSetpoint(const int &value);

private:
    //!
    //! \brief updateAmpsBitArray
    //! \param bitArray
    //! \return
    //!
    uint32_t updateAmpsBitArray(const uint32_t &bitArray) const;

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
    //! \brief currentFactor
    //!
    Data::CurrentFactorType currentFactor;

    //!
    //! \brief prescale
    //!
    Data::SegmentVIPower prescale;

    //!
    //! \brief current
    //!
    int current;
};

} //end of namespace DataParameter

#endif // SEGMENT_CURRENT_SETPOINT_H
