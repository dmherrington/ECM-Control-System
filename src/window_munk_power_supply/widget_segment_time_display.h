#ifndef WIDGET_SEGMENT_TIME_DISPLAY_H
#define WIDGET_SEGMENT_TIME_DISPLAY_H

#include <QWidget>
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

    void addNewSegment();

    void cbiSegmentDataInterface_UpdatedData(const DataParameter::SegmentTimeDataDetailed* obj) override;

private:
    Ui::WidgetSegmentTimeDisplay *ui;

    std::list<WidgetSegmentTimeData*> m_dataList;

};

#endif // WIDGET_SEGMENT_TIME_DISPLAY_H
