#ifndef SEGMENT_TIME_DATA_GENERAL_H
#define SEGMENT_TIME_DATA_GENERAL_H

#include <data/type_prescalar_power.h>
#include <data/type_segment_level.h>
#include <data/type_segment_mode.h>

namespace DataParameter
{

class SegmentTimeDataGeneral
{
public:
    SegmentTimeDataGeneral();
    SegmentTimeDataGeneral(const Data::SegmentLevel &level, const Data::SegmentMode &mode, const Data::SegmentPower &power, const uint8_t &time);

public:
    void setSegmentLevel(const Data::SegmentLevel &level);
    void setSegmentMode(const Data::SegmentMode &mode);
    void setSegmentPower(const Data::SegmentPower &power);
    void setTimeValue(const uint8_t &time);
    void resetData();
    void updateData(const SegmentTimeDataGeneral &data);

public:
    uint32_t getConstructedBitArray() const;

public:
    void operator = (const SegmentTimeDataGeneral &rhs)
    {
        this->segmentLevel = rhs.segmentLevel;
        this->segmentMode = rhs.segmentMode;
        this->segmentPower = rhs.segmentPower;
        this->timeValue = rhs.timeValue;
    }

    bool operator == (const SegmentTimeDataGeneral &rhs) const {

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

    bool operator != (const SegmentTimeDataGeneral &rhs) const {
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
