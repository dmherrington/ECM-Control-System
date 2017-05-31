#include "segment_times.h"

namespace DataParameter{

SegmentTimes::SegmentTimes():
    AbstractParameter(4170), numSeqSegments(2)
{

}

SegmentTimes::SegmentTimes(const int &startingSegment):
    AbstractParameter(4170 + startingSegment - 1), numSeqSegments(2)
{

}

SegmentTimes::SegmentTimes(const SegmentTimes &obj):
    AbstractParameter()
{
    this->operator =(obj);
}

QByteArray SegmentTimes::getByteArray() const
{
    QByteArray data;

    uint8_t HIGHPType = (uint8_t)((parameterCode & 0xFF00) >> 8);
    uint8_t LOWPType = (uint8_t)(parameterCode & 0x00FF);

    data.append(slaveAddress);
    data.append((uint8_t)readOrwrite);
    data.append(HIGHPType);
    data.append(LOWPType);

    uint8_t HIGHSeqType = (uint8_t)((numSeqSegments & 0xFF00) >> 8);
    uint8_t LOWSeqType = (uint8_t)(numSeqSegments & 0x00FF);
    data.append(HIGHSeqType);
    data.append(LOWSeqType);

    data.append((uint8_t)numSeqSegments * 2);


    for (std::list<SegmentTimeData>::const_iterator it = registerData.begin(); it != registerData.end(); ++it){
        uint32_t newArray = it->getConstructedBitArray();
        uint8_t HIGHBType = (uint8_t)((newArray & 0xFF00) >> 8);
        uint8_t LOWBType = (uint8_t)(newArray & 0x00FF);

        data.append(HIGHBType);
        data.append(LOWBType);
    }


    return data;
}

std::string SegmentTimes::getDescription() const
{
    std::string str = "";
    return str;
}

ParameterType SegmentTimes::getParameterType() const
{
    return ParameterType::PATTERNWRITECOMMAND;
}

void SegmentTimes::setStartingRegister(const uint8_t &startSegment)
{
    this->startingSegment = startSegment;
    this->parameterCode = 4170 + startSegment - 1;
}

void SegmentTimes::setNumberofSequentialRegisters(const uint8_t &seqSegment)
{
    int maxSegments = 4185 - this->parameterCode;
    if(seqSegment > maxSegments){
        this->numSeqSegments = maxSegments;
        return;
    }
    this->numSeqSegments = seqSegment;

    //resize the register data
    this->registerData.resize(this->numSeqSegments);
}

} //end of namespace DataRegister
