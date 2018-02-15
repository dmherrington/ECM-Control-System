#ifndef WIDGET_CHANNEL_MEASUREMENTS_H
#define WIDGET_CHANNEL_MEASUREMENTS_H

#include <QWidget>
#include "library_rigol_oscilloscope/commands/measure/measure_command_item.h"

namespace Ui {
class WidgetChannelMeasurements;
}

class WidgetChannelMeasurements : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetChannelMeasurements(QWidget *parent = 0);
    ~WidgetChannelMeasurements();

    void setMeasurementChannel(const rigol::data::AvailableChannels &channel);
    void addMeasurement(const rigol::commands::MeasureCommand_Item *measurement);
    void removeMeasurement(const std::string &key);

private:
    Ui::WidgetChannelMeasurements *ui;
};

#endif // WIDGET_CHANNEL_MEASUREMENTS_H
