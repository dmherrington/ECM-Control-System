#include "segment_voltage_setpoint.h"

namespace DataParameter
{

//!
//! \brief SegmentVoltageSetpoint::SegmentVoltageSetpoint
//! \param levelValue
//! \param levelMode
//!
SegmentVoltageSetpoint::SegmentVoltageSetpoint(const Data::TypeSupplyOutput &outputNum, const Data::SegmentMode &levelMode):
    AbstractParameter()
{
    //let us update the stored values with those that created the object
    this->supplyOutput = outputNum;
    this->mode = levelMode;

    if(levelMode == Data::SegmentMode::FORWARD)
    {
        this->parameterCode = (int)Data::getFWDVoltageIndex((int)outputNum);
    }
    else if(levelMode == Data::SegmentMode::REVERSE)
    {
        this->parameterCode = (int)Data::getREVVoltageIndex((int)outputNum);
    }
    else{

    }
}

ParameterType SegmentVoltageSetpoint::getParameterType() const
{
    return ParameterType::VOLTAGESETPOINT;
}

std::string SegmentVoltageSetpoint::getDescription() const
{
    std::string str = "";
    return str;
}

QByteArray SegmentVoltageSetpoint::getByteArray() const
{
    QByteArray ba;

    uint8_t HIGHSeqType = (uint8_t)((this->data.size() & 0xFF00) >> 8);
    uint8_t LOWSeqType = (uint8_t)(this->data.size() & 0x00FF);
    ba.append(HIGHSeqType);
    ba.append(LOWSeqType);

    ba.append((uint8_t)data.size() * 2);
    for (std::map<Data::SegmentLevel, SegmentVoltageData>::const_iterator it=this->data.begin(); it!=this->data.end(); ++it)
    {
        SegmentVoltageData tmpVoltage = it->second;
        QByteArray tmpArray = tmpVoltage.getDataArray();
        ba.append(tmpArray);
    }

    return ba;
}

void SegmentVoltageSetpoint::appendData(const SegmentVoltageData &voltageSetpoint)
{
    this->data.insert(std::pair<Data::SegmentLevel,SegmentVoltageData>(voltageSetpoint.getSegmentLevel(),voltageSetpoint));
    //this->data.at(voltageSetpoint.getSegmentLevel()) = voltageSetpoint;
}

} //end of namepsace DataParameter
