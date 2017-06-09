#ifndef SEGMENT_TIMES_H
#define SEGMENT_TIMES_H

#include <string>
#include <vector>

#include "abstract_parameter.h"
#include "segment_time_data.h"

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
    SegmentTimes(const int &startingSegment, const int &numSegments);
    SegmentTimes(const SegmentTimes &obj);

public:
    virtual DataParameter::ParameterType getParameterType() const;

    virtual QByteArray getByteArray() const;

    virtual std::string getDescription() const;

public:
    void setStartingRegister(const uint8_t &startSegment);
    void setNumberofSequentialRegisters(const uint8_t &seqSegment);
    void appendRegisterData(const SegmentTimeData &data);
    void updateRegisterData(const int &registerIndex, const SegmentTimeData &data);
    void initializeData();

public:
    void operator = (const SegmentTimes &rhs)
    {
        AbstractParameter::operator =(rhs);
        this->startingSegment = rhs.startingSegment;
        this->numSeqSegments = rhs.numSeqSegments;
        this->registerData = rhs.registerData;
    }

    bool operator == (const SegmentTimes &rhs) {
        if(!AbstractParameter::operator ==(rhs))
        {
            return false;
        }
        if(this->startingSegment != rhs.startingSegment){
            return false;
        }
        if(this->numSeqSegments != rhs.numSeqSegments){
            return false;
        }
        if(this->registerData != rhs.registerData){
            return false;
        }
        return true;
    }

    bool operator != (const SegmentTimes &rhs) {
        return !(*this == rhs);
    }

private:
    uint8_t startingSegment;
    uint8_t numSeqSegments;
    std::vector<DataParameter::SegmentTimeData> registerData;
};

} //end of namespace MunkPowerSupply
#endif // SEGMENT_TIMES_H
