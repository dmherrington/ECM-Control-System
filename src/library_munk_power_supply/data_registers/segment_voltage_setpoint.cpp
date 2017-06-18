#include "segment_voltage_setpoint.h"

namespace DataParameter
{

//!
//! \brief SegmentVoltageSetpoint::SegmentVoltageSetpoint
//! \param levelValue
//! \param levelMode
//!
SegmentVoltageSetpoint::SegmentVoltageSetpoint(const Data::SegmentLevel &levelValue, const Data::SegmentMode &levelMode)
{
    //let us update the stored values with those that created the object
    this->level = levelValue;
    this->mode = levelMode;
    //let us initialize some default values
    this->voltage = 0.0;
    this->prescale = Data::SegmentVIPower::ONE;

    //now we have to determine the correct parameter ID and update the object held by the AbstractParameter class
    switch (levelMode) {
    case Data::SegmentMode::FORWARD:
    {
        Data::VoltageSetFWDType paramType = Data::getFWDVoltageIndex((int)levelValue);
        this->parameterCode = (int)paramType;
        break;
    }
    case Data::SegmentMode::REVERSE:
    {
        Data::VoltageSetREVType paramType = Data::getREVVoltageIndex((int)levelValue);
        this->parameterCode = (int)paramType;
        break;
    }
    default:
        break;
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
    QByteArray byteArray;
    uint32_t ba = 0;
    ba = updatePrescaleBitArray(ba);
    ba = updateSetPointBitArray(ba);
    byteArray.append(ba);
    return byteArray;
}

void SegmentVoltageSetpoint::updatePrescalePower(const Data::SegmentVIPower &value)
{
    this->prescale = value;
}

void SegmentVoltageSetpoint::updateVoltageSetpoint(const int &value)
{
    if(value > 4095)
    {
        this->voltage = 4095;
    }
    else if(value < 0)
    {
        this->voltage = 0;
    }
    else
    {
        this->voltage = value;
    }
}


uint32_t SegmentVoltageSetpoint::updatePrescaleBitArray(const uint32_t &bitArray) const
{
    uint32_t ba = 0;
    uint32_t mask = 7<<12;
    int tmpType = (int)prescale;

    ba = (bitArray & (~mask)) | (tmpType<<12);
    return ba;
}

uint32_t SegmentVoltageSetpoint::updateSetPointBitArray(const uint32_t &bitArray) const
{
    uint32_t ba = 0;
    uint32_t mask = 4095<<0;
    ba = (bitArray & (~mask)) | (this->voltage<<0);
    return ba;
}

} //end of namepsace DataParameter
