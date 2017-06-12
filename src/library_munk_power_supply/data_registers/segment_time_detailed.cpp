#include "segment_time_detailed.h"

namespace DataParameter{

SegmentTimeDetailed::SegmentTimeDetailed():
    AbstractParameter(4170), numSeqSegments(1)
{
    initializeData();
}

SegmentTimeDetailed::SegmentTimeDetailed(const int &startingSegment):
    AbstractParameter(4170 + startingSegment - 1), numSeqSegments(1)
{
    initializeData();
}

SegmentTimeDetailed::SegmentTimeDetailed(const int &startingSegment, const int &numSegments):
    AbstractParameter(4170 + startingSegment - 1)
{
    //should enforce this to have starting segment of 1
    setNumberofSequentialRegisters(numSegments);
}

SegmentTimeDetailed::SegmentTimeDetailed(const SegmentTimeDetailed &obj):
    AbstractParameter()
{
    this->operator =(obj);
}

std::string SegmentTimeDetailed::getDescription() const
{
    std::string str = "";
    return str;
}

ParameterType SegmentTimeDetailed::getParameterType() const
{
    return ParameterType::PATTERNWRITECOMMAND;
}

void SegmentTimeDetailed::setStartingRegister(const uint8_t &startSegment)
{
    this->startingSegment = startSegment;
    this->parameterCode = 4170 + startSegment - 1;

    //this is a dirty hack but it works for now
    int originalRegisterLength = this->numSeqSegments;
    setNumberofSequentialRegisters(originalRegisterLength);
}

void SegmentTimeDetailed::setNumberofSequentialRegisters(const uint8_t &seqSegment)
{
    int maxSegments = 4185 - this->parameterCode;
    if(seqSegment > maxSegments){
        this->numSeqSegments = maxSegments;
        return;
    }
    this->numSeqSegments = seqSegment;

    initializeData();
}

void SegmentTimeDetailed::updateRegisterData(const int &registerIndex, const SegmentTimeDataDetailed &data)
{
    this->detailedRegisterData.at(registerIndex).updateData(data);
}

std::vector<DataParameter::SegmentTimeDataDetailed> SegmentTimeDetailed::getRegisterData()
{
    return this->detailedRegisterData;
}

void SegmentTimeDetailed::initializeData()
{
    this->detailedRegisterData.clear();

    for (int i = 0; i<numSeqSegments; i++)
    {
        SegmentTimeDataDetailed data;
        this->detailedRegisterData.push_back(data);
    }}

} //end of namespace DataRegister
