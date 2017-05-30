#include "segment_times.h"

namespace DataParameter{

SegmentTimes::SegmentTimes():
    AbstractParameter(4170),
    numSeqSegments(2),segmentLevel(Data::SegmentLevel::LEVEL1),
    segmentMode(Data::SegmentMode::FORWARD),segmentPower(Data::SegmentPower::TEN),
    timeValue(20)
{

}

SegmentTimes::SegmentTimes(const int &startingSegment):
    AbstractParameter(4170 + startingSegment - 1),
    numSeqSegments(2),segmentLevel(Data::SegmentLevel::LEVEL1),
    segmentMode(Data::SegmentMode::FORWARD),segmentPower(Data::SegmentPower::TEN),
    timeValue(20)
{

}

SegmentTimes::SegmentTimes(const SegmentTimes &obj):
    AbstractParameter()
{
    this->operator =(obj);
}

QByteArray SegmentTimes::getByteArray() const
{
    QByteArray data;

    uint8_t HIGHPType = (uint8_t)((parameterCode & 0xFF00) >> 8);
    uint8_t LOWPType = (uint8_t)(parameterCode & 0x00FF);

    data.append(slaveAddress);
    data.append((uint8_t)readOrwrite);
    data.append(HIGHPType);
    data.append(LOWPType);

    uint8_t HIGHSeqType = (uint8_t)((numSeqSegments & 0xFF00) >> 8);
    uint8_t LOWSeqType = (uint8_t)(numSeqSegments & 0x00FF);
    data.append(HIGHSeqType);
    data.append(LOWSeqType);

    data.append((uint8_t)4);

    uint32_t newArray = constructBitArray();
    uint8_t HIGHBType = (uint8_t)((newArray & 0xFF00) >> 8);
    uint8_t LOWBType = (uint8_t)(newArray & 0x00FF);

    data.append(HIGHBType);
    data.append(LOWBType);

    return data;
}

std::string SegmentTimes::getDescription() const
{
    std::string str = "";
    return str;
}

ParameterType SegmentTimes::getParameterType() const
{
    return ParameterType::PATTERNWRITECOMMAND;
}

void SegmentTimes::setStartingRegister(const uint8_t &startSegment)
{
    this->startingSegment = startSegment;
    this->parameterCode = 4170 + startSegment - 1;
}

void SegmentTimes::setNumberofSequentialRegisters(const uint8_t &seqSegment)
{
    int maxSegments = 4185 - this->parameterCode;
    if(seqSegment > maxSegments){
        this->numSeqSegments = maxSegments;
        return;
    }
    this->numSeqSegments = seqSegment;
}

void SegmentTimes::setSegmentLevel(const Data::SegmentLevel &level)
{
    this->segmentLevel = level;
}

void SegmentTimes::setSegmentMode(const Data::SegmentMode &mode)
{
    this->segmentMode = mode;

    //Document this
    if(this->segmentMode == Data::SegmentMode::HIZ)
        setSegmentLevel(Data::SegmentLevel::LEVEL1);
    else if(this->segmentMode == Data::SegmentMode::DEAD)
        setSegmentLevel(Data::SegmentLevel::LEVEL2);
}

void SegmentTimes::setSegmentPower(const Data::SegmentPower &power)
{
/*
 *This basically forces us to check that if we are in one of these operational modes
 * to not allow the caller of the library to change this as the information could be
 * wrong. However, this should also signify a call to update the data on the GUI
 * in the event that they become out of sync.
 */
    if((this->segmentMode == Data::SegmentMode::HIZ) || (this->segmentMode == Data::SegmentMode::DEAD))
    {
        //we should ignore this command
        return;
    }

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

   return ba;
}

} //end of namespace DataRegister
