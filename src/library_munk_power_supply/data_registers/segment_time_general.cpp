#include "segment_time_general.h"

namespace DataParameter{

SegmentTimeGeneral::SegmentTimeGeneral():
    AbstractParameter(4170), numSeqSegments(1)
{
    initializeData();
}

SegmentTimeGeneral::SegmentTimeGeneral(const int &numSegments):
    AbstractParameter(4170)
{
    //should enforce this to have starting segment of 1
    setNumberofSequentialRegisters(numSegments);
}

SegmentTimeGeneral::SegmentTimeGeneral(const SegmentTimeGeneral &obj):
    AbstractParameter()
{
    this->operator =(obj);
}

QByteArray SegmentTimeGeneral::getByteArray() const
{
    QByteArray data;

    uint8_t HIGHSeqType = (uint8_t)((numSeqSegments & 0xFF00) >> 8);
    uint8_t LOWSeqType = (uint8_t)(numSeqSegments & 0x00FF);
    data.append(HIGHSeqType);
    data.append(LOWSeqType);

    data.append((uint8_t)numSeqSegments * 2);

    for (std::vector<SegmentTimeDataGeneral>::const_iterator it = registerData.begin(); it != registerData.end(); ++it){
        uint32_t newArray = it->getConstructedBitArray();
        uint8_t HIGHBType = (uint8_t)((newArray & 0xFF00) >> 8);
        uint8_t LOWBType = (uint8_t)(newArray & 0x00FF);

        data.append(HIGHBType);
        data.append(LOWBType);
    }

    return data;
}

std::string SegmentTimeGeneral::getDescription() const
{
    std::string str = "";
    return str;
}

ParameterType SegmentTimeGeneral::getParameterType() const
{
    return ParameterType::PATTERNWRITECOMMAND;
}

void SegmentTimeGeneral::setStartingRegister(const uint8_t &startSegment)
{
    this->parameterCode = 4170 + startSegment - 1;

    //this is a dirty hack but it works for now
    int originalRegisterLength = this->numSeqSegments;
    setNumberofSequentialRegisters(originalRegisterLength);
}

void SegmentTimeGeneral::setNumberofSequentialRegisters(const uint8_t &seqSegment)
{
    int maxSegments = 4185 - this->parameterCode;
    if(seqSegment > maxSegments){
        this->numSeqSegments = maxSegments;
        return;
    }
    this->numSeqSegments = seqSegment;

    initializeData();
}

void SegmentTimeGeneral::updateRegisterData(const int &registerIndex, const SegmentTimeDataGeneral &data)
{
    this->registerData.at(registerIndex).updateData(data);
}

void SegmentTimeGeneral::initializeData()
{
    this->registerData.clear();

    for (int i = 0; i<numSeqSegments; i++)
    {
        SegmentTimeDataGeneral data;
        this->registerData.push_back(data);
    }
}

void SegmentTimeGeneral::appendRegisterData(const SegmentTimeDataGeneral &data)
{
    this->registerData.push_back(data);
}

} //end of namespace DataRegister
