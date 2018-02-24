#include "rigol_measurement_status.h"

namespace rigol {
namespace commands{

RigolMeasurementStatus::RigolMeasurementStatus(const AvailableChannels &measureChannel, const MeasurementTypes &type):
    AbstractRigolStatus(CommandTypes::COMMAND_MEASURE)
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

data::AvailableChannels RigolMeasurementStatus::getChannel() const
{
    return this->channel;
}

data::MeasurementTypes RigolMeasurementStatus::getMeasurementType() const
{
    return this->measureType;
}

double RigolMeasurementStatus::getMeasurementValue() const
{
    return this->value;
}

} //end of namespace commands
} //end of namespace rigol
