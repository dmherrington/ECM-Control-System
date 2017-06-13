#include "segment_voltage_setpoint.h"

namespace DataParameter
{

SegmentVoltageSetpoint::SegmentVoltageSetpoint()
{

}

ParameterType SegmentVoltageSetpoint::getParameterType() const
{
    return ParameterType::VOLTAGESETPOINT;
}

std::string SegmentVoltageSetpoint::getDescription() const
{
    std::string str = "";
    return str;
}

QByteArray SegmentVoltageSetpoint::getByteArray() const
{
    QByteArray dummy;
    return dummy;
}

} //end of namepsace DataParameter
