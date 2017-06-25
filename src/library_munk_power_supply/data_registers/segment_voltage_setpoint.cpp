#include "segment_voltage_setpoint.h"

namespace DataParameter
{

//!
//! \brief SegmentVoltageSetpoint::SegmentVoltageSetpoint
//! \param levelValue
//! \param levelMode
//!
SegmentVoltageSetpoint::SegmentVoltageSetpoint(const Data::TypeSupplyOutput &outputNum, const Data::SegmentMode &levelMode)
{
    //let us update the stored values with those that created the object
    this->supplyOutput = outputNum;
    this->mode = levelMode;
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

    byteArray.append(ba);
    return byteArray;
}

void SegmentVoltageSetpoint::appendData(const SegmentVoltageData &voltageSetpoint)
{
    this->data.at(voltageSetpoint.getSegmentLevel()) = voltageSetpoint;
}

} //end of namepsace DataParameter
