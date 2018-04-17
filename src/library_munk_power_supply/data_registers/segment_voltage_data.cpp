#include "segment_voltage_data.h"


namespace registers_Munk {

//!
//! \brief SegmentVoltageData::SegmentVoltageData
//! \param levelValue
//! \param levelMode
//!
SegmentVoltageData::SegmentVoltageData(const data_Munk::SegmentLevel &levelValue, const data_Munk::SegmentMode &levelMode)
{
    //let us update the stored values with those that created the object
    this->level = levelValue;
    this->mode = levelMode;
    //let us initialize some default values
    this->voltage = 0.0;
    this->prescale = data_Munk::SegmentVIPower::ONE;
}


QByteArray SegmentVoltageData::getDataArray() const
{
    QByteArray byteArray;
    uint32_t ba = 0;
    ba = updatePrescaleBitArray(ba);
    ba = updateSetPointBitArray(ba);

    uint8_t HIGHBType = (uint8_t)((ba & 0xFF00) >> 8);
    uint8_t LOWBType = (uint8_t)(ba & 0x00FF);

    byteArray.append(HIGHBType);
    byteArray.append(LOWBType);

    return byteArray;
}

void SegmentVoltageData::updatePrescalePower(const data_Munk::SegmentVIPower &value)
{
    this->prescale = value;
}

data_Munk::DataFaultCodes SegmentVoltageData::updateVoltageSetpoint(const double &value)
{
    int newValue = value * 100;
    this->updatePrescalePower(data_Munk::SegmentVIPower::ONE);

    if(newValue > 4095)
    {
        this->voltage = 4095;
        return data_Munk::DataFaultCodes::DATA_VALUE_GREATER_THAN_MAX;
    }
    else if(newValue < 0)
    {
        this->voltage = 0;
        return data_Munk::DataFaultCodes::DATA_VALUE_LESS_THAN_MIN;
    }
    else
    {
        this->voltage = newValue;
        return data_Munk::DataFaultCodes::DATA_UPDATE_SUCCESSFUL;
    }
}

data_Munk::SegmentLevel SegmentVoltageData::getSegmentLevel() const
{
    return this->level;
}

data_Munk::SegmentMode SegmentVoltageData::getSegmentMode() const
{
    return this->mode;
}

data_Munk::SegmentVIPower SegmentVoltageData::getVoltagePrescale() const
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

} //end of namespace registers_Munk

