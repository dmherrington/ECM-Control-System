#ifndef SEGMENT_TIME_DATA_H
#define SEGMENT_TIME_DATA_H

#include <data/type_prescalar_power.h>
#include <data/type_segment_level.h>
#include <data/type_segment_mode.h>

namespace DataParameter
{

class SegmentTimeData
{
public:
    SegmentTimeData();
    SegmentTimeData(const Data::SegmentLevel &level, const Data::SegmentMode &mode, const Data::SegmentPower &power, const uint8_t &time);

public:
    void setSegmentLevel(const Data::SegmentLevel &level);
    void setSegmentMode(const Data::SegmentMode &mode);
    void setSegmentPower(const Data::SegmentPower &power);
    void setTimeValue(const uint8_t &time);

public:
    uint32_t getConstructedBitArray() const;

public:
    void operator = (const SegmentTimeData &rhs)
    {
        this->segmentLevel = rhs.segmentLevel;
        this->segmentMode = rhs.segmentMode;
        this->segmentPower = rhs.segmentPower;
        this->timeValue = rhs.timeValue;
    }

    bool operator == (const SegmentTimeData &rhs) const {

        if(this->segmentLevel != rhs.segmentLevel){
            return false;
        }
        if(this->segmentMode != rhs.segmentMode){
            return false;
        }
        if(this->segmentPower != rhs.segmentPower){
            return false;
        }
        if(this->timeValue != rhs.timeValue){
            return false;
        }
        return true;
    }

    bool operator != (const SegmentTimeData &rhs) const {
        return !(*this == rhs);
    }

private:
    Data::SegmentLevel segmentLevel;
    Data::SegmentMode segmentMode;
    Data::SegmentPower segmentPower;
    uint8_t timeValue; //this time is denoted in us

};

} //end of namespace DataParameter
#endif // SEGMENT_TIME_DATA_H
