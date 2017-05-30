#include "segment_times.h"

namespace DataParameter{

SegmentTimes::SegmentTimes():
    beginningRegister(0),endingRegister(0),segmentLevel(Data::SegmentLevel::LEVEL1),
    segmentMode(Data::SegmentMode::FORWARD),segmentPower(Data::SegmentPower::ONE),
    timeValue(0)
{

}

SegmentTimes::SegmentTimes(const SegmentTimes &obj)
{
    this->operator =(obj);
}

QByteArray SegmentTimes::getByteArray() const
{
    QByteArray data;
    return data;
}

QByteArray SegmentTimes::getCompletedMessage() const
{
    QByteArray data;
    return data;
}

std::string SegmentTimes::getDescription() const
{
    std::string str = "";
    return str;
}

ParameterType SegmentTimes::getParamterType() const
{
    return ParameterType::PATTERNWRITECOMMAND;
}


void SegmentTimes::setBeginningRegister(const int &begRegister)
{
    this->beginningRegister = begRegister;
}

void SegmentTimes::setEndingRegister(const int &endRegister)
{
    this->endingRegister = endRegister;
}

void SegmentTimes::setSegmentLevel(const Data::SegmentLevel &level)
{
    this->segmentLevel = level;
}

void SegmentTimes::setSegmentMode(const Data::SegmentMode &mode)
{
    this->segmentMode = mode;
}

void SegmentTimes::setSegmentPower(const Data::SegmentPower &power)
{
    this->segmentPower = power;
}

void SegmentTimes::setTimeValue(const int &time)
{
    if(time > 127)
    {
        //we should throw an error as this is not allowed
        this->timeValue = 127;
    }else{
        this->timeValue = time;
    }
}

} //end of namespace DataRegister
