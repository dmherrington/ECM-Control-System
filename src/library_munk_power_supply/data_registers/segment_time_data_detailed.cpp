#include "segment_time_data_detailed.h"

namespace DataParameter {

SegmentTimeDataDetailed::SegmentTimeDataDetailed():
    segmentVoltage(0),segmentCurrent(0),segmentMode(Data::SegmentMode::DEAD),segmentPower(Data::SegmentPower::ONE),timeValue(0)
{

}

SegmentTimeDataDetailed::SegmentTimeDataDetailed(const int &voltage, const int &current, const Data::SegmentMode &mode, const Data::SegmentPower &power, const uint8_t &time)
{
    setSegmentVoltage(voltage);
    setSegmentCurrent(current);
    setSegmentMode(mode);
    setSegmentPower(power);
    setTimeValue(time);
}

void SegmentTimeDataDetailed::setSegmentVoltage(const int &voltage)
{
    this->segmentVoltage = voltage;
}

void SegmentTimeDataDetailed::setSegmentCurrent(const int &current)
{
    this->segmentCurrent = current;
}

void SegmentTimeDataDetailed::setSegmentMode(const Data::SegmentMode &mode)
{
    this->segmentMode = mode;
}

void SegmentTimeDataDetailed::setSegmentPower(const Data::SegmentPower &power)
{
    this->segmentPower = power;
}

void SegmentTimeDataDetailed::setTimeValue(const uint8_t &time)
{
    if(time > 127)
    {
        //we should throw an error as this is not allowed
        this->timeValue = 127;
    }else{
        this->timeValue = time;
    }
}

void SegmentTimeDataDetailed::resetData()
{
    setSegmentVoltage(0);
    setSegmentCurrent(0);
    setSegmentMode(Data::SegmentMode::DEAD);
    setSegmentPower(Data::SegmentPower::ONE);
    setTimeValue(0);
}

void SegmentTimeDataDetailed::updateData(const SegmentTimeDataDetailed &data)
{
    this->operator =(data);
}

} //end of namespace DataParameter
