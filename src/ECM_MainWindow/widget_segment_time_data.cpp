#include "widget_segment_time_data.h"
#include "ui_widget_segment_time_data.h"

Widget_SegmentTimeData::Widget_SegmentTimeData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_SegmentTimeData)
{
    ui->setupUi(this);
}

Widget_SegmentTimeData::~Widget_SegmentTimeData()
{
    delete ui;
}
