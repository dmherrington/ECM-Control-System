#include "segment_current_setpoint.h"

namespace DataParameter
{

SegmentCurrentSetpoint::SegmentCurrentSetpoint()
{

}

ParameterType SegmentCurrentSetpoint::getParameterType() const
{
    return ParameterType::CURRENTSETPOINT;
}

std::string SegmentCurrentSetpoint::getDescription() const
{
    std::string str = "";
    return str;
}

QByteArray SegmentCurrentSetpoint::getByteArray() const
{
    QByteArray dummy;
    return dummy;
}

} //end of namespace DataParameter
