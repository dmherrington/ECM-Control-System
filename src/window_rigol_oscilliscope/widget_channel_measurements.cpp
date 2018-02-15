#include "widget_channel_measurements.h"
#include "ui_widget_channel_measurements.h"

WidgetChannelMeasurements::WidgetChannelMeasurements(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetChannelMeasurements)
{
    ui->setupUi(this);
}

WidgetChannelMeasurements::~WidgetChannelMeasurements()
{
    delete ui;
}

void WidgetChannelMeasurements::setMeasurementChannel(const rigol::data::AvailableChannels &channel)
{
    this->ui->label_Channel->setText(QString::fromStdString(rigol::data::AvailableChannelsToDisplayString(channel)));
}

void WidgetChannelMeasurements::addMeasurement(const rigol::commands::MeasureCommand_Item* measurement)
{
    std::string str = rigol::data::MeasurementTypeEnumToString(measurement->getMeasurementType());
    this->ui->listWidget_Measurements->addItem(QString::fromStdString(str));
}

void WidgetChannelMeasurements::removeMeasurement(const std::string &key)
{

}
