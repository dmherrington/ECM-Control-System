#ifndef WIDGET_CHANNEL_MEASUREMENTS_H
#define WIDGET_CHANNEL_MEASUREMENTS_H

#include <QWidget>
#include <QMenu>
#include <iostream>

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

    void setMeasurementChannel(const data_Rigol::AvailableChannels &channel);
    void addMeasurement(const commands_Rigol::MeasureCommand_Item *measurement);
    void removeMeasurement(const std::string &key);

private slots:
    void showListContextMenu(const QPoint &pos);
    void eraseItem();

private:
    Ui::WidgetChannelMeasurements *ui;
};

#endif // WIDGET_CHANNEL_MEASUREMENTS_H
