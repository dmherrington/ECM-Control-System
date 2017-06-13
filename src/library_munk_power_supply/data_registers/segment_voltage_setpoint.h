#ifndef SEGMENT_VOLTAGE_SETPOINT_H
#define SEGMENT_VOLTAGE_SETPOINT_H

#include <string>
#include <vector>
#include <iostream>

#include "abstract_parameter.h"

namespace DataParameter
{

class SegmentVoltageSetpoint : public AbstractParameter
{
public:
    SegmentVoltageSetpoint();

public:
    virtual DataParameter::ParameterType getParameterType() const;

    virtual std::string getDescription() const;

    virtual QByteArray getByteArray() const;


private:
    int voltage;
};

} //end of namespace DataParameter
#endif // SEGMENT_VOLTAGE_SETPOINT_H
