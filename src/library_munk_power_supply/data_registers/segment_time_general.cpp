#include "segment_time_general.h"

namespace DataParameter{

SegmentTimeGeneral::SegmentTimeGeneral():
    AbstractParameter()
{
    initializeData();
    parameterCode = 4170;
}


SegmentTimeGeneral::SegmentTimeGeneral(const SegmentTimeGeneral &obj):
    AbstractParameter()
{
    this->operator =(obj);
}

QByteArray SegmentTimeGeneral::getByteArray() const
{
    QByteArray data;

    int numberOfSegments = registerData.size();

    uint8_t HIGHSeqType = (uint8_t)((numberOfSegments & 0xFF00) >> 8);
    uint8_t LOWSeqType = (uint8_t)(numberOfSegments & 0x00FF);
    data.append(HIGHSeqType);
    data.append(LOWSeqType);

    data.append((uint8_t)numberOfSegments * 2);

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


void SegmentTimeGeneral::updateRegisterData(const int &registerIndex, const SegmentTimeDataGeneral &data)
{
    this->registerData.at(registerIndex).updateData(data);
}

void SegmentTimeGeneral::initializeData()
{
    this->registerData.clear();
}

void SegmentTimeGeneral::appendRegisterData(const SegmentTimeDataGeneral &data)
{
    this->registerData.push_back(data);
}

} //end of namespace DataRegister
