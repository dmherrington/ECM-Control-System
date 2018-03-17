#include "segment_current_data.h"


namespace registers_Munk {

SegmentCurrentData::SegmentCurrentData(const data_Munk::SegmentLevel &levelValue, const data_Munk::SegmentMode &levelMode)
{
    //let us update the stored values with those that created the object
    this->level = levelValue;
    this->mode = levelMode;
    //let us initialize some default values
    this->currentFactor = data_Munk::CurrentFactorType::AMPS;
    this->current = 0.0;
    this->prescale = data_Munk::SegmentVIPower::ONE;
}


QByteArray SegmentCurrentData::getDataArray() const
{
    QByteArray byteArray;
    uint32_t ba = 0;
    ba = updateAmpsBitArray(ba);
    ba = updatePrescaleBitArray(ba);
    ba = updateSetPointBitArray(ba);

    uint8_t HIGHBType = (uint8_t)((ba & 0xFF00) >> 8);
    uint8_t LOWBType = (uint8_t)(ba & 0x00FF);

    byteArray.append(HIGHBType);
    byteArray.append(LOWBType);

    return byteArray;

}

void SegmentCurrentData::updateCurrentFactor(const data_Munk::CurrentFactorType &value)
{
    this->currentFactor = value;
}

void SegmentCurrentData::updatePrescalePower(const data_Munk::SegmentVIPower &value)
{
    this->prescale = value;
}

data_Munk::DataFaultCodes SegmentCurrentData::updateCurrentSetpoint(const int &value)
{
    if(value > 4095)
    {
        this->current = 4095;
        return data_Munk::DataFaultCodes::DATA_VALUE_GREATER_THAN_MAX;
    }
    else if(value < 0)
    {
        this->current = 0;
        return data_Munk::DataFaultCodes::DATA_VALUE_LESS_THAN_MIN;
    }
    else
    {
        this->current = value;
        return data_Munk::DataFaultCodes::DATA_UPDATE_SUCCESSFUL;
    }
}

data_Munk::SegmentLevel SegmentCurrentData::getSegmentLevel() const
{
    return this->level;
}

data_Munk::SegmentMode SegmentCurrentData::getSegmentMode() const
{
    return this->mode;
}

data_Munk::CurrentFactorType SegmentCurrentData::getCurrentFactor() const
{
    return this->currentFactor;
}

data_Munk::SegmentVIPower SegmentCurrentData::getCurrentPrescale() const
{
    return this->prescale;
}

int SegmentCurrentData::getCurrent() const
{
    return this->current;
}


uint32_t SegmentCurrentData::updateAmpsBitArray(const uint32_t &bitArray) const
{
    uint32_t ba = 0;
    uint32_t mask = 1<<15;
    int tmpType = (int)currentFactor;

    ba = (bitArray & (~mask)) | (tmpType<<15);
    return ba;
}

uint32_t SegmentCurrentData::updatePrescaleBitArray(const uint32_t &bitArray) const
{
    uint32_t ba = 0;
    uint32_t mask = 7<<12;
    int tmpType = (int)prescale;

    ba = (bitArray & (~mask)) | (tmpType<<12);
    return ba;
}

uint32_t SegmentCurrentData::updateSetPointBitArray(const uint32_t &bitArray) const
{
    uint32_t ba = 0;
    uint32_t mask = 4095<<0;
    ba = (bitArray & (~mask)) | (this->current<<0);
    return ba;
}

} //end of namespace registers_Munk

