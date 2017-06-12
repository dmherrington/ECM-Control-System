#ifndef SEGMENT_TIME_DETAILED_H
#define SEGMENT_TIME_DETAILED_H

#include <string>
#include <vector>

#include "abstract_parameter.h"
#include "segment_time_data_detailed.h"
#include "segment_time_general.h"

namespace DataParameter
{

class SegmentTimeDetailed : public AbstractParameter
{
public:
    SegmentTimeDetailed();
    SegmentTimeDetailed(const int &numSegments);
    SegmentTimeDetailed(const SegmentTimeDetailed &obj);

public:
    virtual DataParameter::ParameterType getParameterType() const;

    virtual QByteArray getByteArray() const;

    virtual std::string getDescription() const;

public:
    void setStartingRegister(const uint8_t &startSegment);
    void setNumberofSequentialRegisters(const uint8_t &seqSegment);
    void appendRegisterData(const SegmentTimeDataDetailed &data);
    void updateRegisterData(const int &registerIndex, const SegmentTimeDataDetailed &data);
    std::vector<DataParameter::SegmentTimeDataDetailed> getRegisterData();
    void initializeData();

public:
    void operator = (const SegmentTimeDetailed &rhs)
    {
        AbstractParameter::operator =(rhs);
        this->numSeqSegments = rhs.numSeqSegments;
        this->detailedRegisterData = rhs.detailedRegisterData;
    }

    bool operator == (const SegmentTimeDetailed &rhs) {
        if(!AbstractParameter::operator ==(rhs))
        {
            return false;
        }
        if(this->numSeqSegments != rhs.numSeqSegments){
            return false;
        }
        if(this->detailedRegisterData != rhs.detailedRegisterData){
            return false;
        }
        return true;
    }

    bool operator != (const SegmentTimeDetailed &rhs) {
        return !(*this == rhs);
    }

private:
    uint8_t numSeqSegments;
    std::vector<DataParameter::SegmentTimeDataDetailed> detailedRegisterData;
};

} //end of namespace MunkPowerSupply

#endif // SEGMENT_TIME_DETAILED_H
