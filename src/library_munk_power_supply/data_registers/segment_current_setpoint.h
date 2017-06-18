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

class SegmentCurrentSetpoint : public AbstractParameter
{
public:
    SegmentCurrentSetpoint(const Data::SegmentLevel &levelValue, const Data::SegmentMode &levelMode);

public:
    virtual DataParameter::ParameterType getParameterType() const;

    virtual QByteArray getByteArray() const;

    virtual std::string getDescription() const;

public:
    void updateCurrentFactor(const Data::CurrentFactorType &value);
    void updatePrescalePower(const Data::SegmentVIPower &value);
    void updateCurrentSetpoint(const int &value);

private:
    uint32_t updateAmpsBitArray(const uint32_t &bitArray) const;
    uint32_t updatePrescaleBitArray(const uint32_t &bitArray) const;
    uint32_t updateSetPointBitArray(const uint32_t &bitArray) const;

private:
    Data::SegmentLevel level;
    Data::SegmentMode mode;
    Data::CurrentFactorType currentFactor;
    Data::SegmentVIPower prescale;
    int current;
};

} //end of namespace DataParameter

#endif // SEGMENT_CURRENT_SETPOINT_H
