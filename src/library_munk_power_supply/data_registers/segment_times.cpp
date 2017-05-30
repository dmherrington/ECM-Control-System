#include "segment_times.h"

namespace DataParameter{

SegmentTimes::SegmentTimes():
    beginningRegister(0),endingRegister(0),segmentLevel(Data::SegmentLevel::LEVEL1),
    segmentMode(Data::SegmentMode::DEAD),segmentPower(Data::SegmentPower::ONE),
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
    uint32_t newArray = constructBitArray();
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


void SegmentTimes::setBeginningRegister(const uint8_t &begRegister)
{
    this->beginningRegister = begRegister;
}

void SegmentTimes::setEndingRegister(const uint8_t &endRegister)
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

void SegmentTimes::setTimeValue(const uint8_t &time)
{
    if(time > 127)
    {
        //we should throw an error as this is not allowed
        this->timeValue = 127;
    }else{
        this->timeValue = time;
    }
}

uint32_t SegmentTimes::constructBitArray() const
{
   uint32_t ba = 0;
   ba = Data::SegmentLevelToBitArray(this->segmentLevel,ba);
   ba = Data::SegmentModeToBitArray(this->segmentMode,ba);
   ba = Data::SegmentPowerToBitArray(this->segmentPower,ba);

   uint32_t timeMask = 127<<0;
   ba = (ba & (~timeMask)) | (this->timeValue<<0);
}

} //end of namespace DataRegister
