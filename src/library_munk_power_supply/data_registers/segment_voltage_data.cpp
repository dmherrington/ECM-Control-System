#include "segment_voltage_data.h"

namespace DataParameter
{

//!
//! \brief SegmentVoltageData::SegmentVoltageData
//! \param levelValue
//! \param levelMode
//!
SegmentVoltageData::SegmentVoltageData(const Data::SegmentLevel &levelValue, const Data::SegmentMode &levelMode)
{
    //let us update the stored values with those that created the object
    this->level = levelValue;
    this->mode = levelMode;
    //let us initialize some default values
    this->voltage = 0.0;
    this->prescale = Data::SegmentVIPower::ONE;
}


QByteArray SegmentVoltageData::getDataArray() const
{
    QByteArray byteArray;
    uint32_t ba = 0;
    ba = updatePrescaleBitArray(ba);
    ba = updateSetPointBitArray(ba);
    byteArray.append(ba);
    return byteArray;
}

void SegmentVoltageData::updatePrescalePower(const Data::SegmentVIPower &value)
{
    this->prescale = value;
}

void SegmentVoltageData::updateVoltageSetpoint(const int &value)
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

Data::SegmentLevel SegmentVoltageData::getSegmentLevel() const
{
    return this->level;
}

Data::SegmentMode SegmentVoltageData::getSegmentMode() const
{
    return this->mode;
}

Data::SegmentVIPower SegmentVoltageData::getVoltagePrescale() const
{
    return this->prescale;
}

int SegmentVoltageData::getVoltage() const
{
    return this->voltage;
}

uint32_t SegmentVoltageData::updatePrescaleBitArray(const uint32_t &bitArray) const
{
    uint32_t ba = 0;
    uint32_t mask = 7<<12;
    int tmpType = (int)prescale;

    ba = (bitArray & (~mask)) | (tmpType<<12);
    return ba;
}

uint32_t SegmentVoltageData::updateSetPointBitArray(const uint32_t &bitArray) const
{
    uint32_t ba = 0;
    uint32_t mask = 4095<<0;
    ba = (bitArray & (~mask)) | (this->voltage<<0);
    return ba;
}

} //end of namepsace DataParameter
