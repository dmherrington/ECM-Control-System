#include "rigol_measurement_status.h"


namespace commands_Rigol{

RigolMeasurementStatus::RigolMeasurementStatus(const std::string &name, const AvailableChannels &measureChannel, const MeasurementTypes &type):
    AbstractRigolStatus(name, CommandTypes::COMMAND_MEASURE)
{
    this->channel = measureChannel;
    this->measureType = type;
}

RigolMeasurementStatus::RigolMeasurementStatus(const RigolMeasurementStatus &copy):
    AbstractRigolStatus(copy)
{
    this->channel = copy.channel;
    this->measureType = copy.measureType;
    this->value = copy.value;
    this->str = copy.str;
}

void RigolMeasurementStatus::setMeasurementValue(const double &measurement)
{
    this->value = measurement;
}

data_Rigol::AvailableChannels RigolMeasurementStatus::getChannel() const
{
    return this->channel;
}

data_Rigol::MeasurementTypes RigolMeasurementStatus::getMeasurementType() const
{
    return this->measureType;
}

double RigolMeasurementStatus::getMeasurementValue() const
{
    return this->value;
}

} //end of namespace commands

