#ifndef SEGMENT_TIMES_H
#define SEGMENT_TIMES_H

#include <string>
#include <bitset>

#include "abstract_parameter.h"

#include <data/type_prescalar_power.h>
#include <data/type_segment_level.h>
#include <data/type_segment_mode.h>

namespace DataParameter
{

class SegmentTimes : public AbstractParameter
{
public:
    SegmentTimes();
    SegmentTimes(const int &startingSegment);
    SegmentTimes(const SegmentTimes &obj);

public:
    virtual DataParameter::ParameterType getParameterType() const;

    virtual QByteArray getByteArray() const;

    virtual std::string getDescription() const;

public:
    void setStartingRegister(const uint8_t &startSegment);
    void setNumberofSequentialRegisters(const uint8_t &seqSegment);
    void setSegmentLevel(const Data::SegmentLevel &level);
    void setSegmentMode(const Data::SegmentMode &mode);
    void setSegmentPower(const Data::SegmentPower &power);
    void setTimeValue(const uint8_t &time);


public:
    void operator = (const SegmentTimes &rhs)
    {
        AbstractParameter::operator =(rhs);
        this->startingSegment = rhs.startingSegment;
        this->numSeqSegments = rhs.numSeqSegments;
        this->segmentLevel = rhs.segmentLevel;
        this->segmentMode = rhs.segmentMode;
        this->segmentPower = rhs.segmentPower;
        this->timeValue = rhs.timeValue;
    }

    bool operator == (const SegmentTimes &rhs) {
        if(!AbstractParameter::operator ==(rhs))
        {
            return false;
        }
        if(this->numSeqSegments != rhs.numSeqSegments){
            return false;
        }
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

    bool operator != (const SegmentTimes &rhs) {
        return !(*this == rhs);
    }

private:
    uint32_t constructBitArray() const;

private:
    uint8_t startingSegment;
    uint8_t numSeqSegments;
    Data::SegmentLevel segmentLevel;
    Data::SegmentMode segmentMode;
    Data::SegmentPower segmentPower;
    uint8_t timeValue; //this time is denoted in us
};

} //end of namespace MunkPowerSupply
#endif // SEGMENT_TIMES_H
