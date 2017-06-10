#ifndef SEGMENT_TIME_DATA_DETAILED_H
#define SEGMENT_TIME_DATA_DETAILED_H


#include <data/type_prescalar_power.h>
#include <data/type_segment_level.h>
#include <data/type_segment_mode.h>

namespace DataParameter
{

class SegmentTimeDataDetailed
{
public:
    SegmentTimeDataDetailed();
    SegmentTimeDataDetailed(const int &voltage, const int &current, const Data::SegmentMode &mode, const Data::SegmentPower &power, const uint8_t &time);

public:
    void setSegmentVoltage(const int &voltage);
    void setSegmentCurrent(const int &current);
    void setSegmentMode(const Data::SegmentMode &mode);
    void setSegmentPower(const Data::SegmentPower &power);
    void setTimeValue(const uint8_t &time);
    void resetData();
    void updateData(const SegmentTimeDataDetailed &data);

public:
    void operator = (const SegmentTimeDataDetailed &rhs)
    {
        this->segmentVoltage = rhs.segmentVoltage;
        this->segmentCurrent = rhs.segmentCurrent;
        this->segmentMode = rhs.segmentMode;
        this->segmentPower = rhs.segmentPower;
        this->timeValue = rhs.timeValue;
    }

    bool operator == (const SegmentTimeDataDetailed &rhs) const {

        if(this->segmentVoltage != rhs.segmentVoltage){
            return false;
        }
        if(this->segmentCurrent != rhs.segmentCurrent){
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

    bool operator != (const SegmentTimeDataDetailed &rhs) const {
        return !(*this == rhs);
    }

private:
    int segmentVoltage;
    int segmentCurrent;
    Data::SegmentMode segmentMode;
    Data::SegmentPower segmentPower;
    uint8_t timeValue; //this time is denoted in us

};

} //end of namespace DataParameter


#endif // SEGMENT_TIME_DATA_DETAILED_H
