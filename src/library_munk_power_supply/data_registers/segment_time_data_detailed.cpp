#include "segment_time_data_detailed.h"


namespace registers_Munk {

SegmentTimeDataDetailed::SegmentTimeDataDetailed():
    supplyOutput(data_Munk::TypeSupplyOutput::OUTPUT1),dataObject(0.0,0.0),segmentMode(data_Munk::SegmentMode::DEAD),timeValue(100)
{

}

SegmentTimeDataDetailed::SegmentTimeDataDetailed(const double &voltage, const double &current, const data_Munk::SegmentMode &mode, const uint32_t &time)
{
    setSupplyOutput(data_Munk::TypeSupplyOutput::OUTPUT1);
    setSegmentVoltage(voltage);
    setSegmentCurrent(current);
    setSegmentMode(mode);
    setTimeValue(time);
}

SegmentTimeDataDetailed::SegmentTimeDataDetailed(const SegmentTimeDataDetailed &copy)
{
    this->setSegmentCurrent(copy.getSegmentCurrent());
    this->setSegmentMode(copy.getSegmentMode());
    this->setSegmentVoltage(copy.getSegmentVoltage());
    this->setSupplyOutput(copy.getSupplyOutputNumber());
    this->setTimeValue(copy.getTimeValue());
}

void SegmentTimeDataDetailed::setSupplyOutput(const data_Munk::TypeSupplyOutput &outputNumber)
{
    this->supplyOutput = outputNumber;
}

void SegmentTimeDataDetailed::setSegmentVoltage(const double &voltage)
{
    this->dataObject.voltage = voltage;
}

void SegmentTimeDataDetailed::setSegmentCurrent(const double &current)
{
    this->dataObject.current = current;
}

void SegmentTimeDataDetailed::setSegmentMode(const data_Munk::SegmentMode &mode)
{
    this->segmentMode = mode;
}

void SegmentTimeDataDetailed::setTimeValue(const uint32_t &time)
{
    if(time > 1270000)
    {
        //we should throw an error as this is not allowed
        this->timeValue = 1270000;
    }else{
        this->timeValue = time;
    }

}

void SegmentTimeDataDetailed::resetData()
{
    setSegmentVoltage(0);
    setSegmentCurrent(0);
    setSegmentMode(data_Munk::SegmentMode::DEAD);
    setTimeValue(0);
}

void SegmentTimeDataDetailed::updateData(const SegmentTimeDataDetailed &data)
{
    this->operator =(data);
}

data_Munk::TypeSupplyOutput SegmentTimeDataDetailed::getSupplyOutputNumber() const
{
    return this->supplyOutput;
}

data_Munk::RegisterDataObject SegmentTimeDataDetailed::getRegisterDataObject() const
{
    return this->dataObject;
}

double SegmentTimeDataDetailed::getSegmentVoltage() const
{
    return this->dataObject.voltage;
}

double SegmentTimeDataDetailed::getGraphingVoltage() const
{
    if(segmentMode == data_Munk::SegmentMode::FORWARD)
        return this->dataObject.voltage;
    else if(segmentMode == data_Munk::SegmentMode::REVERSE)
        return (-1) * this->dataObject.voltage;
    else
        return 0.0;
}

double SegmentTimeDataDetailed::getSegmentCurrent() const
{
    return this->dataObject.current;
}

double SegmentTimeDataDetailed::getGraphingCurrent() const
{
    if(segmentMode == data_Munk::SegmentMode::FORWARD)
        return this->dataObject.current;
    else if(segmentMode == data_Munk::SegmentMode::REVERSE)
        return (-1) * this->dataObject.current;
    else
        return 0.0;
}

data_Munk::SegmentMode SegmentTimeDataDetailed::getSegmentMode() const
{
    return this->segmentMode;
}

uint32_t SegmentTimeDataDetailed::getTimeValue() const
{
    return this->timeValue;
}

} //end of namespace registers_Munk

