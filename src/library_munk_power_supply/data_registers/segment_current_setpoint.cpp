#include "segment_current_setpoint.h"


namespace registers_Munk {

SegmentCurrentSetpoint::SegmentCurrentSetpoint(const data_Munk::TypeSupplyOutput &outputNum, const data_Munk::SegmentMode &levelMode)
{
    this->supplyOutput = outputNum;
    this->mode = levelMode;

    if(levelMode == data_Munk::SegmentMode::FORWARD)
    {
        this->parameterCode = (int)data_Munk::getFWDCurrentIndex((int)outputNum);
    }
    else if(levelMode == data_Munk::SegmentMode::REVERSE)
    {
        this->parameterCode = (int)data_Munk::getREVCurrentIndex((int)outputNum);
    }
    else{

    }
}

SegmentCurrentSetpoint::SegmentCurrentSetpoint(const SegmentCurrentSetpoint &copy):
    AbstractParameter(copy)
{
    this->supplyOutput = copy.supplyOutput;
    this->mode = copy.mode;
    this->data = copy.data;
}

ParameterType SegmentCurrentSetpoint::getParameterType() const
{
    return ParameterType::CURRENTSETPOINT;
}

std::string SegmentCurrentSetpoint::getDescription() const
{
    std::string str = "";
    return str;
}

QByteArray SegmentCurrentSetpoint::getByteArray() const
{
    QByteArray ba;

    if(data.size() > 0)
    {
        uint8_t HIGHSeqType = (uint8_t)((this->data.size() & 0xFF00) >> 8);
        uint8_t LOWSeqType = (uint8_t)(this->data.size() & 0x00FF);
        ba.append(HIGHSeqType);
        ba.append(LOWSeqType);

        ba.append((uint8_t)data.size() * 2);
        for (std::map<data_Munk::SegmentLevel, SegmentCurrentData>::const_iterator it=this->data.begin(); it!=this->data.end(); ++it)
        {
            SegmentCurrentData tmpCurrent = it->second;
            QByteArray tmpArray = tmpCurrent.getDataArray();
            ba.append(tmpArray);
        }
    }
    return ba;
}

QByteArray SegmentCurrentSetpoint::getExpectedResponse() const
{
    QByteArray ba;
    uint8_t HIGHSeqType = (uint8_t)((this->data.size() & 0xFF00) >> 8);
    uint8_t LOWSeqType = (uint8_t)(this->data.size() & 0x00FF);
    ba.append(HIGHSeqType);
    ba.append(LOWSeqType);

    return ba;
}

void SegmentCurrentSetpoint::appendData(const SegmentCurrentData &currentSetpoint)
{
    this->data.insert(std::pair<data_Munk::SegmentLevel,SegmentCurrentData>(currentSetpoint.getSegmentLevel(),currentSetpoint));
}

void SegmentCurrentSetpoint::initializeData()
{
    this->data.clear();
}

} //end of namespace registers_Munk

