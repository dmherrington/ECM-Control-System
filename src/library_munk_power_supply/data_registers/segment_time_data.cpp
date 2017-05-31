#include "segment_time_data.h"

namespace DataParameter {

SegmentTimeData::SegmentTimeData()
{

}
SegmentTimeData::SegmentTimeData(const Data::SegmentLevel &level, const Data::SegmentMode &mode, const Data::SegmentPower &power, const uint8_t &time)
{
    setSegmentLevel(level);
    setSegmentMode(mode);
    setSegmentPower(power);
    setTimeValue(time);
}


void SegmentTimeData::setSegmentLevel(const Data::SegmentLevel &level)
{
    this->segmentLevel = level;
}

void SegmentTimeData::setSegmentMode(const Data::SegmentMode &mode)
{
    this->segmentMode = mode;

    //Document this
    if(this->segmentMode == Data::SegmentMode::HIZ)
        setSegmentLevel(Data::SegmentLevel::LEVEL1);
    else if(this->segmentMode == Data::SegmentMode::DEAD)
        setSegmentLevel(Data::SegmentLevel::LEVEL2);
}

void SegmentTimeData::setSegmentPower(const Data::SegmentPower &power)
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

void SegmentTimeData::setTimeValue(const uint8_t &time)
{
    if(time > 127)
    {
        //we should throw an error as this is not allowed
        this->timeValue = 127;
    }else{
        this->timeValue = time;
    }
}

uint32_t SegmentTimeData::getConstructedBitArray() const
{
   uint32_t ba = 0;
   ba = Data::SegmentLevelToBitArray(this->segmentLevel,ba);
   ba = Data::SegmentModeToBitArray(this->segmentMode,ba);
   ba = Data::SegmentPowerToBitArray(this->segmentPower,ba);

   uint32_t timeMask = 127<<0;
   ba = (ba & (~timeMask)) | (this->timeValue<<0);

   return ba;
}

} //end of namespace DataParameter
