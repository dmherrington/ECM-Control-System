#include "segment_voltage_setpoint.h"

namespace registers_Munk {

//!
//! \brief SegmentVoltageSetpoint::SegmentVoltageSetpoint
//! \param levelValue
//! \param levelMode
//!
SegmentVoltageSetpoint::SegmentVoltageSetpoint(const data_Munk::TypeSupplyOutput &outputNum, const data_Munk::SegmentMode &levelMode):
    AbstractParameter()
{
    //let us update the stored values with those that created the object
    this->supplyOutput = outputNum;
    this->mode = levelMode;

    if(levelMode == data_Munk::SegmentMode::FORWARD)
    {
        this->parameterCode = (int)data_Munk::getFWDVoltageIndex((int)outputNum);
        this->parameterType = registers_Munk::ParameterType::VOLTAGESETPOINT_FORWARD;
    }
    else if(levelMode == data_Munk::SegmentMode::REVERSE)
    {
        this->parameterCode = (int)data_Munk::getREVVoltageIndex((int)outputNum);
        this->parameterType = registers_Munk::ParameterType::VOLTAGESETPOINT_REVERSE;
    }
    else{

    }
}

SegmentVoltageSetpoint::SegmentVoltageSetpoint(const SegmentVoltageSetpoint &copy):
    AbstractParameter(copy)
{
    this->supplyOutput = copy.supplyOutput;
    this->mode = copy.mode;
    this->data = copy.data;
}

std::string SegmentVoltageSetpoint::getDescription() const
{
    std::string str = "";
    return str;
}

QByteArray SegmentVoltageSetpoint::getByteArray() const
{
    QByteArray ba;

    if(data.size() > 0)
    {
        uint8_t HIGHSeqType = (uint8_t)((this->data.size() & 0xFF00) >> 8);
        uint8_t LOWSeqType = (uint8_t)(this->data.size() & 0x00FF);
        ba.append(HIGHSeqType);
        ba.append(LOWSeqType);

        ba.append((uint8_t)data.size() * 2);
        for (std::map<data_Munk::SegmentLevel, SegmentVoltageData>::const_iterator it=this->data.begin(); it!=this->data.end(); ++it)
        {
            SegmentVoltageData tmpVoltage = it->second;
            QByteArray tmpArray = tmpVoltage.getDataArray();
            ba.append(tmpArray);
        }
    }

    return ba;
}

QByteArray SegmentVoltageSetpoint::getExpectedResponse() const
{
    QByteArray ba;
    uint8_t HIGHSeqType = (uint8_t)((this->data.size() & 0xFF00) >> 8);
    uint8_t LOWSeqType = (uint8_t)(this->data.size() & 0x00FF);
    ba.append(HIGHSeqType);
    ba.append(LOWSeqType);

    return ba;
}

void SegmentVoltageSetpoint::appendData(const SegmentVoltageData &voltageSetpoint)
{
    this->data.insert(std::pair<data_Munk::SegmentLevel,SegmentVoltageData>(voltageSetpoint.getSegmentLevel(),voltageSetpoint));
}

void SegmentVoltageSetpoint::initializeData()
{
    this->data.clear();
}

} //end of namespace registers_Munk

