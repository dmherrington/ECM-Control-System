#ifndef WIDGET_SEGMENT_TIME_DATA_H
#define WIDGET_SEGMENT_TIME_DATA_H

#include <QWidget>

#include "library_munk_power_supply/data_registers/segment_time_data_detailed.h"

class WidgetTimeDataInterface
{
public:
    virtual void cbiSegmentDataInterface_UpdatedData(const DataParameter::SegmentTimeDataDetailed* obj) = 0;
};

namespace Ui {
class WidgetSegmentTimeData;
}

class WidgetSegmentTimeData : public QWidget
{
    Q_OBJECT


public:
    explicit WidgetSegmentTimeData(QWidget *parent = 0);
    ~WidgetSegmentTimeData();

    void connectCallback(WidgetTimeDataInterface *cb)
    {
        m_CB = cb;
    }

    DataParameter::SegmentTimeDataDetailed* getData() const
    {
        return this->data;
    }

protected:
        QSize sizeHint() const { return QSize(120, 143); }

signals:
    void updatedSegmentData(const DataParameter::SegmentTimeDataDetailed &newData);

private slots:
    void on_comboBox_Mode_currentIndexChanged(const QString &arg1);

    void on_doubleSpinBox_Voltage_valueChanged(const double arg1);

    void on_doubleSpinBox_Current_valueChanged(const double arg1);

    void on_doubleSpinBox_Time_valueChanged(const double arg1);

private:
    void emitCallback()
    {
        if(m_CB)
        {
            m_CB->cbiSegmentDataInterface_UpdatedData(data);
        }
    }

private:
    WidgetTimeDataInterface* m_CB;

    Ui::WidgetSegmentTimeData* ui;

    DataParameter::SegmentTimeDataDetailed* data;
};

#endif // WIDGET_SEGMENT_TIME_DATA_H
