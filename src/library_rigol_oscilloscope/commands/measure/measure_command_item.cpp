#include "measure_command_item.h"


namespace commands_Rigol{

MeasureCommand_Item::MeasureCommand_Item():
    AbstractMeasureCommand(data_Rigol::MeasurementCommands::MEASURE_ITEM)
{

}

MeasureCommand_Item::MeasureCommand_Item(const data_Rigol::AvailableChannels &channel, const data_Rigol::MeasurementTypes &type):
    AbstractMeasureCommand(data_Rigol::MeasurementCommands::MEASURE_ITEM)
{
    this->channel = channel;
    this->measureType = type;
}

MeasureCommand_Item::MeasureCommand_Item(const MeasureCommand_Item &copy):
    AbstractMeasureCommand(copy)
{
    this->channel = copy.channel;
    this->measureType = copy.measureType;
}

void MeasureCommand_Item::read(const QJsonObject &json)
{
    setChannel(data_Rigol::AvailableChannelsDisplayToEnum((json["channel"].toString().toStdString())));
    setMeasurementType(data_Rigol::AvailableMeasurementTypeStringToEnum(json["measurement"].toString().toStdString()));
    setReadOrWrite(data_Rigol::ReadWriteTypeFromString(json["r_w"].toString().toStdString()));
}

void MeasureCommand_Item::write(QJsonObject &json) const
{
    json["channel"] = QString::fromStdString(data_Rigol::AvailableChannelsToDisplayString(this->channel));
    json["measurement"] = QString::fromStdString(data_Rigol::MeasurementTypeEnumToString(this->measureType));
    json["r_w"] = QString::fromStdString(data_Rigol::ReadWriteTypeToString(this->isReadorWrite()));
}

AbstractRigolStatus* MeasureCommand_Item::getExpectedResponse() const
{
    return new RigolMeasurementStatus(this->channel,this->measureType);
}

AbstractRigolCommand* MeasureCommand_Item::getClone() const
{
    return (new MeasureCommand_Item(*this));
}

void MeasureCommand_Item::getClone(AbstractRigolCommand** state) const
{
    *state = new MeasureCommand_Item(*this);
}

void MeasureCommand_Item::setChannel(const data_Rigol::AvailableChannels &measureChannel)
{
    this->channel = measureChannel;
}

void MeasureCommand_Item::setMeasurementType(const data_Rigol::MeasurementTypes &type)
{
    this->measureType = type;
}

data_Rigol::AvailableChannels MeasureCommand_Item::getChannel() const
{
    return this->channel;
}

data_Rigol::MeasurementTypes MeasureCommand_Item::getMeasurementType() const
{
    return this->measureType;
}

} //end of namespace commands

