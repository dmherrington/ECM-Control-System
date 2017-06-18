#include "segment_current_setpoint.h"

namespace DataParameter
{

SegmentCurrentSetpoint::SegmentCurrentSetpoint(const Data::SegmentLevel &levelValue, const Data::SegmentMode &levelMode)
{
    //let us update the stored values with those that created the object
    this->level = levelValue;
    this->mode = levelMode;
    //let us initialize some default values
    this->currentFactor = Data::CurrentFactorType::AMPS;
    this->current = 0.0;
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
    QByteArray byteArray;
    uint32_t ba = 0;
    ba = updateAmpsBitArray(ba);
    ba = updatePrescaleBitArray(ba);
    ba = updateSetPointBitArray(ba);
    byteArray.append(ba);
    return byteArray;
}

void SegmentCurrentSetpoint::updateCurrentFactor(const Data::CurrentFactorType &value)
{
    this->currentFactor = value;
}

void SegmentCurrentSetpoint::updatePrescalePower(const Data::SegmentVIPower &value)
{
    this->prescale = value;
}

void SegmentCurrentSetpoint::updateCurrentSetpoint(const int &value)
{
    if(value > 4095)
    {
        this->current = 4095;
    }
    else if(value < 0)
    {
        this->current = 0;
    }
    else
    {
        this->current = value;
    }
}


uint32_t SegmentCurrentSetpoint::updateAmpsBitArray(const uint32_t &bitArray) const
{
    uint32_t ba = 0;
    uint32_t mask = 1<<15;
    int tmpType = (int)currentFactor;

    ba = (bitArray & (~mask)) | (tmpType<<15);
    return ba;
}

uint32_t SegmentCurrentSetpoint::updatePrescaleBitArray(const uint32_t &bitArray) const
{
    uint32_t ba = 0;
    uint32_t mask = 7<<12;
    int tmpType = (int)prescale;

    ba = (bitArray & (~mask)) | (tmpType<<12);
    return ba;
}

uint32_t SegmentCurrentSetpoint::updateSetPointBitArray(const uint32_t &bitArray) const
{
    uint32_t ba = 0;
    uint32_t mask = 4095<<0;
    ba = (bitArray & (~mask)) | (this->current<<0);
    return ba;
}
} //end of namespace DataParameter
