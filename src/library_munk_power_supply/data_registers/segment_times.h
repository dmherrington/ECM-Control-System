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
    SegmentTimes(const SegmentTimes &obj);

public:
    virtual DataParameter::ParameterType getParamterType() const;

    virtual QByteArray getByteArray() const;

    virtual QByteArray getCompletedMessage() const;

    virtual std::string getDescription() const;

public:
    void setBeginningRegister(const uint8_t &begRegister);
    void setEndingRegister(const uint8_t &endRegister);
    void setSegmentLevel(const Data::SegmentLevel &level);
    void setSegmentMode(const Data::SegmentMode &mode);
    void setSegmentPower(const Data::SegmentPower &power);
    void setTimeValue(const uint8_t &time);


public:
    void operator = (const SegmentTimes &rhs)
    {
        AbstractParameter::operator =(rhs);
        this->beginningRegister = rhs.beginningRegister;
        this->endingRegister = rhs.endingRegister;
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
        if(this->beginningRegister != rhs.beginningRegister){
            return false;
        }
        if(this->endingRegister != rhs.endingRegister){
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
    uint32_t constructBitArray();

private:
    uint8_t beginningRegister;
    uint8_t endingRegister;
    Data::SegmentLevel segmentLevel;
    Data::SegmentMode segmentMode;
    Data::SegmentPower segmentPower;
    uint8_t timeValue; //this time is denoted in us
};

} //end of namespace MunkPowerSupply
#endif // SEGMENT_TIMES_H
