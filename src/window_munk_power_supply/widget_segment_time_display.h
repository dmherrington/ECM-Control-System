#ifndef WIDGET_SEGMENT_TIME_DISPLAY_H
#define WIDGET_SEGMENT_TIME_DISPLAY_H

#include <QWidget>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

#include <iostream>

#include "widget_segment_time_data.h"


namespace Ui {
class WidgetSegmentTimeDisplay;
}

class WidgetSegmentTimeDisplay : public QWidget, public WidgetTimeDataInterface
{
    Q_OBJECT

public:
    explicit WidgetSegmentTimeDisplay(QWidget *parent = 0);
    ~WidgetSegmentTimeDisplay();

    WidgetSegmentTimeData* addNewSegment();

    void cbiSegmentDataInterface_UpdatedData() override;

public:
    void read(const QJsonObject &json);

    void write(QJsonObject &json) const;

signals:
    void updatedData(const std::list<DataParameter::SegmentTimeDataDetailed> &newData);

protected:
        QSize sizeHint() const { return QSize(120 * m_dataList.size(), 143); }
private:
    Ui::WidgetSegmentTimeDisplay *ui;

    std::list<WidgetSegmentTimeData*> m_dataList;

};

#endif // WIDGET_SEGMENT_TIME_DISPLAY_H
