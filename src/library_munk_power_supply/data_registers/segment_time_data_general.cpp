#include "segment_time_data_general.h"


namespace registers_Munk{

SegmentTimeDataGeneral::SegmentTimeDataGeneral():
    segmentLevel(data_Munk::SegmentLevel::LEVEL1),segmentMode(data_Munk::SegmentMode::HIZ),segmentPower(data_Munk::SegmentPower::ONE),timeValue(0)
{

}

SegmentTimeDataGeneral::SegmentTimeDataGeneral(const data_Munk::SegmentLevel &level, const data_Munk::SegmentMode &mode, const uint32_t &time)
{
    setSegmentMode(mode);
    setSegmentLevel(level);
    setTimeValue(time);
}


void SegmentTimeDataGeneral::setSegmentLevel(const data_Munk::SegmentLevel &level)
{
    /*
     *This basically forces us to check that if we are in one of these operational modes
     * to not allow the caller of the library to change this as the information could be
     * wrong. However, this should also signify a call to update the data on the GUI
     * in the event that they become out of sync.
     */
    if((this->segmentMode == data_Munk::SegmentMode::HIZ) || (this->segmentMode == data_Munk::SegmentMode::DEAD))
    {
        //we should ignore this command
        return;
    }

    this->segmentLevel = level;
}

void SegmentTimeDataGeneral::setSegmentMode(const data_Munk::SegmentMode &mode)
{
    this->segmentMode = mode;

    //Document this
    if(this->segmentMode == data_Munk::SegmentMode::HIZ)
        this->segmentLevel = data_Munk::SegmentLevel::LEVEL1;
    else if(this->segmentMode == data_Munk::SegmentMode::DEAD)
        this->segmentLevel = data_Munk::SegmentLevel::LEVEL2;
}

void SegmentTimeDataGeneral::setSegmentPower(const data_Munk::SegmentPower &power)
{
    this->segmentPower = power;
}

void SegmentTimeDataGeneral::setTimeValue(const uint32_t &time)
{
    if(time <= 127)
    {
        this->setSegmentPower(data_Munk::SegmentPower::ONE);
        this->timeValue = time;

    }
    else{
        int result = 1;
        while(((result * 10) <= 10000) && ((result * 10) <= time))
            result *= 10;

        this->setSegmentPower(data_Munk::ValueToEquivalentSegmentPower(result));
        uint32_t resultingTime = time / result;

        if(resultingTime > 127)
        {
            //we should throw an error as this is not allowed
            this->timeValue = 127;
        }else{
            this->timeValue = resultingTime;
        }
    }

}

uint32_t SegmentTimeDataGeneral::getConstructedBitArray() const
{
   uint32_t ba = 0;
   ba = data_Munk::SegmentLevelToBitArray(this->segmentLevel,ba);
   ba = data_Munk::SegmentModeToBitArray(this->segmentMode,ba);
   ba = data_Munk::SegmentPowerToBitArray(this->segmentPower,ba);

   uint32_t timeMask = 127<<0;
   ba = (ba & (~timeMask)) | (this->timeValue<<0);

   return ba;
}

void SegmentTimeDataGeneral::resetData()
{
    setSegmentLevel(data_Munk::SegmentLevel::LEVEL1);
    setSegmentMode(data_Munk::SegmentMode::DEAD);
    setSegmentPower(data_Munk::SegmentPower::ONE);
    setTimeValue(0);
}

void SegmentTimeDataGeneral::updateData(const SegmentTimeDataGeneral &data)
{
    this->operator =(data);
}

} //end of namespace registers_Munk

