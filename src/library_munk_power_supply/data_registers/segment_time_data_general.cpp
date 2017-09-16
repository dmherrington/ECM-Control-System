#include "segment_time_data_general.h"

namespace DataParameter {

SegmentTimeDataGeneral::SegmentTimeDataGeneral():
    segmentLevel(Data::SegmentLevel::LEVEL1),segmentMode(Data::SegmentMode::HIZ),segmentPower(Data::SegmentPower::ONE),timeValue(0)
{

}

SegmentTimeDataGeneral::SegmentTimeDataGeneral(const Data::SegmentLevel &level, const Data::SegmentMode &mode, const uint32_t &time)
{
    setSegmentMode(mode);
    setSegmentLevel(level);
    setTimeValue(time);
}


void SegmentTimeDataGeneral::setSegmentLevel(const Data::SegmentLevel &level)
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

    this->segmentLevel = level;
}

void SegmentTimeDataGeneral::setSegmentMode(const Data::SegmentMode &mode)
{
    this->segmentMode = mode;

    //Document this
    if(this->segmentMode == Data::SegmentMode::HIZ)
        this->segmentLevel = Data::SegmentLevel::LEVEL1;
    else if(this->segmentMode == Data::SegmentMode::DEAD)
        this->segmentLevel = Data::SegmentLevel::LEVEL2;
}

void SegmentTimeDataGeneral::setSegmentPower(const Data::SegmentPower &power)
{
    this->segmentPower = power;
}

void SegmentTimeDataGeneral::setTimeValue(const uint32_t &time)
{
    if(time <= 127)
    {
        this->setSegmentPower(Data::SegmentPower::ONE);
        this->timeValue = time;

    }
    else{
        int result = pow(10,(int)log10(time));
        this->setSegmentPower(Data::ValueToEquivalentSegmentPower(result));
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
   ba = Data::SegmentLevelToBitArray(this->segmentLevel,ba);
   ba = Data::SegmentModeToBitArray(this->segmentMode,ba);
   ba = Data::SegmentPowerToBitArray(this->segmentPower,ba);

   uint32_t timeMask = 127<<0;
   ba = (ba & (~timeMask)) | (this->timeValue<<0);

   return ba;
}

void SegmentTimeDataGeneral::resetData()
{
    setSegmentLevel(Data::SegmentLevel::LEVEL1);
    setSegmentMode(Data::SegmentMode::DEAD);
    setSegmentPower(Data::SegmentPower::ONE);
    setTimeValue(0);
}

void SegmentTimeDataGeneral::updateData(const SegmentTimeDataGeneral &data)
{
    this->operator =(data);
}

} //end of namespace DataParameter
