#include "segment_current_setpoint.h"

namespace DataParameter
{

SegmentCurrentSetpoint::SegmentCurrentSetpoint(const Data::TypeSupplyOutput &outputNum, const Data::SegmentMode &levelMode)
{
    this->supplyOutput = outputNum;
    this->mode = levelMode;

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
    QByteArray byteArray;
    uint32_t ba = 0;

    byteArray.append(ba);
    return byteArray;
}

void SegmentCurrentSetpoint::appendData(const SegmentCurrentData &currentSetpoint)
{
    this->data.insert(std::pair<Data::SegmentLevel,SegmentCurrentData>(currentSetpoint.getSegmentLevel(),currentSetpoint));
    //this->data.at(currentSetpoint.getSegmentLevel()) = currentSetpoint;
}

} //end of namespace DataParameter
