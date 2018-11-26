#ifndef WIDGET_SEGMENT_TIME_DISPLAY_H
#define WIDGET_SEGMENT_TIME_DISPLAY_H

#include <QWidget>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

#include <iostream>

#include "widget_segment_time_data.h"

#include "library_munk_power_supply/data_registers/segment_time_detailed.h"

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

    void cbiSegmentDataInterface_RemoveData(WidgetSegmentTimeData *obj) override;

public:
    void readFromJSON(const QJsonObject &json);

    void writeToJSON(QJsonObject &json) const;

    registers_Munk::SegmentTimeDetailed getRawData() const;

signals:
    void updatedData(const std::list<registers_Munk::SegmentTimeDataDetailed> &newData);

    void signal_SegmentDataModified();

protected:
        WidgetSegmentTimeData tempObject;
        QSize tempSize = tempObject.sizeHint();

        QSize sizeHint() const {
            int height = 0;
            if(m_dataList.size() > 0)
                height = tempSize.height();
            return QSize((tempSize.width() + 4) * m_dataList.size(), height);
        }

private:
        void removeWidgets();
private:
    Ui::WidgetSegmentTimeDisplay *ui;

    std::list<WidgetSegmentTimeData*> m_dataList;

};

#endif // WIDGET_SEGMENT_TIME_DISPLAY_H
