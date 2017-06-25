#include "segment_current_setpoint.h"

namespace DataParameter
{

SegmentCurrentSetpoint::SegmentCurrentSetpoint(const Data::TypeSupplyOutput &outputNum, const Data::SegmentMode &levelMode)
{
    this->supplyOutput = outputNum;
    this->mode = levelMode;

    //now we have to determine the correct parameter ID and update the object held by the AbstractParameter class
    switch (levelMode) {
    case Data::SegmentMode::FORWARD:
    {
        Data::CurrentSetFWDType paramType = Data::getFWDCurrentIndex((int)levelValue);
        this->parameterCode = (int)paramType;
        break;
    }
    case Data::SegmentMode::REVERSE:
    {
        Data::CurrentSetREVType paramType = Data::getREVCurrentIndex((int)levelValue);
        this->parameterCode = (int)paramType;
        break;
    }
    default:
        break;
    }
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
    this->data.at(currentSetpoint.getSegmentLevel()) = currentSetpoint;
}

} //end of namespace DataParameter
