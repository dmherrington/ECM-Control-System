#include "widget_segment_time_display.h"
#include "ui_widget_segment_time_display.h"

WidgetSegmentTimeDisplay::WidgetSegmentTimeDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetSegmentTimeDisplay)
{
    ui->setupUi(this);

    ui->horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
    ui->horizontalLayout->setAlignment(Qt::AlignLeft);

}

WidgetSegmentTimeDisplay::~WidgetSegmentTimeDisplay()
{
    delete ui;
}

void WidgetSegmentTimeDisplay::addNewSegment()
{
    WidgetSegmentTimeData* newData = new WidgetSegmentTimeData();
    m_dataList.push_back(newData);
    ui->horizontalLayout->addWidget(newData);
    newData->connectCallback(this);

    this->resize(sizeHint());
}

void WidgetSegmentTimeDisplay::cbiSegmentDataInterface_UpdatedData(const DataParameter::SegmentTimeDataDetailed *obj)
{
    std::cout<<"This callback has been initiated"<<std::endl;
}
