#include "measure_command_item.h"


namespace commands_Rigol{

MeasureCommand_Item::MeasureCommand_Item(const std::string &name, const data_Rigol::AvailableChannels &channel, const data_Rigol::MeasurementTypes &type):
    AbstractMeasureCommand(data_Rigol::MeasurementCommands::MEASURE_ITEM)
{
    this->deviceName = name;
    this->channel = channel;
    this->measureType = type;
}

MeasureCommand_Item::MeasureCommand_Item(const MeasureCommand_Item &copy):
    AbstractMeasureCommand(copy)
{
    this->deviceName = copy.deviceName;
    this->channel = copy.channel;
    this->measureType = copy.measureType;
}

void MeasureCommand_Item::read(const QJsonObject &json)
{
    setDeviceName(json["device"].toString().toStdString());
    setChannel(data_Rigol::AvailableChannelsDisplayToEnum((json["channel"].toString().toStdString())));
    setMeasurementType(data_Rigol::AvailableMeasurementTypeStringToEnum(json["measurement"].toString().toStdString()));
    setReadOrWrite(data_Rigol::ReadWriteTypeFromString(json["r_w"].toString().toStdString()));
}

void MeasureCommand_Item::write(QJsonObject &json) const
{
    json["device"] = QString::fromStdString(this->deviceName);
    json["channel"] = QString::fromStdString(data_Rigol::AvailableChannelsToDisplayString(this->channel));
    json["measurement"] = QString::fromStdString(data_Rigol::MeasurementTypeEnumToString(this->measureType));
    json["r_w"] = QString::fromStdString(data_Rigol::ReadWriteTypeToString(this->isReadorWrite()));
}

AbstractRigolStatus* MeasureCommand_Item::getExpectedResponse() const
{
    return new RigolMeasurementStatus(this->deviceName,this->channel,this->measureType);
}

AbstractRigolCommand* MeasureCommand_Item::getClone() const
{
    return (new MeasureCommand_Item(*this));
}

void MeasureCommand_Item::getClone(AbstractRigolCommand** state) const
{
    *state = new MeasureCommand_Item(*this);
}

void MeasureCommand_Item::setDeviceName(const std::string &name)
{
    this->deviceName = name;
}

void MeasureCommand_Item::setChannel(const data_Rigol::AvailableChannels &measureChannel)
{
    this->channel = measureChannel;
}

void MeasureCommand_Item::setMeasurementType(const data_Rigol::MeasurementTypes &type)
{
    this->measureType = type;
}

std::string MeasureCommand_Item::getDeviceName() const
{
    return this->deviceName;
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

