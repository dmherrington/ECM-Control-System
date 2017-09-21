#ifndef WIDGET_SEGMENT_TIME_DATA_H
#define WIDGET_SEGMENT_TIME_DATA_H

#include <QWidget>

#include "library_munk_power_supply/data_registers/segment_time_data_detailed.h"

namespace Ui {
class WidgetSegmentTimeData;
}

class WidgetSegmentTimeData : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetSegmentTimeData(QWidget *parent = 0);
    ~WidgetSegmentTimeData();

private slots:
    void on_comboBox_Mode_currentIndexChanged(const QString &arg1);

    void on_doubleSpinBox_Voltage_valueChanged(double arg1);

    void on_doubleSpinBox_Current_valueChanged(double arg1);

    void on_doubleSpinBox_Time_valueChanged(double arg1);

private:
    Ui::WidgetSegmentTimeData *ui;

    DataParameter::SegmentTimeDataDetailed* data;
};

#endif // WIDGET_SEGMENT_TIME_DATA_H
