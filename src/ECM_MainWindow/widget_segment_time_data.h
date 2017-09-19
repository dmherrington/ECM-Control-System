#ifndef WIDGET_SEGMENT_TIME_DATA_H
#define WIDGET_SEGMENT_TIME_DATA_H

#include <QWidget>
#include "library_munk_power_supply/data_registers/segment_time_data_detailed.h"

namespace Ui {
class Widget_SegmentTimeData;
}

class Widget_SegmentTimeData : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_SegmentTimeData(QWidget *parent = 0);
    ~Widget_SegmentTimeData();

signals:
    void valueChanged_Voltage(const double &newValue);

private slots:
    void on_doubleSpinBox_voltage_valueChanged(double arg1);

    void on_doubleSpinBox_current_valueChanged(double arg1);

    void on_doubleSpinBox_duration_valueChanged(double arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::Widget_SegmentTimeData *ui;

    DataParameter::SegmentTimeDataDetailed* data;
};

#endif // WIDGET_SEGMENT_TIME_DATA_H
