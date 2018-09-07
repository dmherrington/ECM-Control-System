#ifndef WIDGET_SEGMENT_TIME_DATA_H
#define WIDGET_SEGMENT_TIME_DATA_H

#include <QWidget>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

#include "library_munk_power_supply/data_registers/segment_time_data_detailed.h"

class WidgetSegmentTimeData; //this enables a forward declaration

class WidgetTimeDataInterface
{
public:
    virtual void cbiSegmentDataInterface_UpdatedData() = 0;

    virtual void cbiSegmentDataInterface_RemoveData(WidgetSegmentTimeData* obj) = 0;
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

    void updateDisplayData() const;

    registers_Munk::SegmentTimeDataDetailed* getData() const
    {
        return this->data;
    }

    void updateSegmentName(const int &segmentNumber);

public:
    void read(const QJsonObject &json)
    {
        data->read(json);
    }

    void write(QJsonObject &json) const
    {
        data->write(json);
    }

    QSize sizeHint() const { return QSize(185, 216); }

private slots:
    void on_comboBox_Mode_currentIndexChanged(const QString &arg1);

    void on_doubleSpinBox_Voltage_valueChanged(const double arg1);

    void on_doubleSpinBox_Current_valueChanged(const double arg1);

    void on_doubleSpinBox_Time_valueChanged(const double arg1);

    void on_pushButton_released();

private:
    void emitCallback()
    {
        if(m_CB && !blockCallback)
        {
            m_CB->cbiSegmentDataInterface_UpdatedData();
        }
    }

private:
    Ui::WidgetSegmentTimeData* ui;

    WidgetTimeDataInterface* m_CB;

    registers_Munk::SegmentTimeDataDetailed* data;

private:
    mutable bool blockCallback;
};

#endif // WIDGET_SEGMENT_TIME_DATA_H
