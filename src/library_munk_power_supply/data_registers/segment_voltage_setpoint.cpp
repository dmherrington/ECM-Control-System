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

void SegmentVoltageSetpoint::appendData(const SegmentVoltageData &voltageSetpoint)
{
    this->data.at(voltageSetpoint.getSegmentLevel()) = voltageSetpoint;
}

} //end of namepsace DataParameter
