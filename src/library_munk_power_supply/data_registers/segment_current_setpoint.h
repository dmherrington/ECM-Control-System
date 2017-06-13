#ifndef SEGMENT_CURRENT_SETPOINT_H
#define SEGMENT_CURRENT_SETPOINT_H


#include <string>
#include <vector>
#include <iostream>

#include "abstract_parameter.h"

namespace DataParameter
{

class SegmentCurrentSetpoint : public AbstractParameter
{
public:
    SegmentCurrentSetpoint();

public:
    virtual DataParameter::ParameterType getParameterType() const;

    virtual QByteArray getByteArray() const;

    virtual std::string getDescription() const;

private:
    int current;
};

} //end of namespace DataParameter

#endif // SEGMENT_CURRENT_SETPOINT_H
