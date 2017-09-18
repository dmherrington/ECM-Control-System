#ifndef WIDGET_SEGMENT_TIME_DATA_H
#define WIDGET_SEGMENT_TIME_DATA_H

#include <QWidget>

namespace Ui {
class Widget_SegmentTimeData;
}

class Widget_SegmentTimeData : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_SegmentTimeData(QWidget *parent = 0);
    ~Widget_SegmentTimeData();

private:
    Ui::Widget_SegmentTimeData *ui;
};

#endif // WIDGET_SEGMENT_TIME_DATA_H
