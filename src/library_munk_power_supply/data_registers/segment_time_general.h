#ifndef SEGMENT_TIMES_H
#define SEGMENT_TIMES_H

#include <string>
#include <vector>

#include "abstract_parameter.h"
#include "segment_time_data_general.h"

#include <data/type_prescalar_power.h>
#include <data/type_segment_level.h>
#include <data/type_segment_mode.h>

namespace DataParameter
{

class SegmentTimeGeneral : public AbstractParameter
{
public:
    SegmentTimeGeneral();
    SegmentTimeGeneral(const int &numSegments);
    SegmentTimeGeneral(const SegmentTimeGeneral &obj);

public:
    virtual DataParameter::ParameterType getParameterType() const;

    virtual QByteArray getByteArray() const;

    virtual std::string getDescription() const;

public:
    void setStartingRegister(const uint8_t &startSegment);
    void setNumberofSequentialRegisters(const uint8_t &seqSegment);
    void appendRegisterData(const SegmentTimeDataGeneral &data);
    void updateRegisterData(const int &registerIndex, const SegmentTimeDataGeneral &data);
    void initializeData();

public:
    void operator = (const SegmentTimeGeneral &rhs)
    {
        AbstractParameter::operator =(rhs);
        this->numSeqSegments = rhs.numSeqSegments;
        this->registerData = rhs.registerData;
    }

    bool operator == (const SegmentTimeGeneral &rhs) {
        if(!AbstractParameter::operator ==(rhs))
        {
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

    bool operator != (const SegmentTimeGeneral &rhs) {
        return !(*this == rhs);
    }

private:
    uint8_t numSeqSegments;
    std::vector<DataParameter::SegmentTimeDataGeneral> registerData;
};

} //end of namespace MunkPowerSupply
#endif // SEGMENT_TIMES_H
