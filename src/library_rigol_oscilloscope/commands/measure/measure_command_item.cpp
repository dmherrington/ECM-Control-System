#include "measure_command_item.h"

namespace rigol {
namespace commands{

MeasureCommand_Item::MeasureCommand_Item():
    AbstractMeasureCommand(data::MeasurementCommands::MEASURE_ITEM)
{

}

MeasureCommand_Item::MeasureCommand_Item(const data::AvailableChannels &channel, const data::MeasurementTypes &type):
    AbstractMeasureCommand(data::MeasurementCommands::MEASURE_ITEM)
{
    this->channel = channel;
    this->measureType = type;
}

MeasureCommand_Item::MeasureCommand_Item(const MeasureCommand_Item &copy):
    AbstractMeasureCommand(copy)
{

}

AbstractRigolCommand* MeasureCommand_Item::getClone() const
{
    return (new MeasureCommand_Item(*this));
}

void MeasureCommand_Item::getClone(AbstractRigolCommand** state) const
{
    *state = new MeasureCommand_Item(*this);
}

void MeasureCommand_Item::setChannel(const data::AvailableChannels &measureChannel)
{
    this->channel = measureChannel;
}

void MeasureCommand_Item::setMeasurementType(const data::MeasurementTypes &type)
{
    this->measureType = type;
}

data::AvailableChannels MeasureCommand_Item::getChannel() const
{
    return this->channel;
}

data::MeasurementTypes MeasureCommand_Item::getMeasurementType() const
{
    return this->measureType;
}

} //end of namespace commands
} //end of namespace rigol
