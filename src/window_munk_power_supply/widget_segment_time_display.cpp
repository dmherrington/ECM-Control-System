#include "widget_segment_time_display.h"
#include "ui_widget_segment_time_display.h"

WidgetSegmentTimeDisplay::WidgetSegmentTimeDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetSegmentTimeDisplay)
{
    ui->setupUi(this);

    QSize currentSize = this->size();

    ui->horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
    ui->horizontalLayout->setAlignment(Qt::AlignLeft);

    this->resize(currentSize.width(), 0);
}

WidgetSegmentTimeDisplay::~WidgetSegmentTimeDisplay()
{
    delete ui;
}

WidgetSegmentTimeData* WidgetSegmentTimeDisplay::addNewSegment()
{
    WidgetSegmentTimeData* newData = new WidgetSegmentTimeData();
    m_dataList.push_back(newData);
    ui->horizontalLayout->addWidget(newData);
    newData->connectCallback(this);
    this->resize(sizeHint());
    return newData;
}

void WidgetSegmentTimeDisplay::cbiSegmentDataInterface_UpdatedData()
{
    std::list<DataParameter::SegmentTimeDataDetailed> dataList;

    std::list<WidgetSegmentTimeData*>::iterator iterator;
    for (iterator = m_dataList.begin(); iterator != m_dataList.end(); ++iterator) {
        WidgetSegmentTimeData* newData = *iterator;
        dataList.push_back(DataParameter::SegmentTimeDataDetailed(*newData->getData()));
    }
    updatedData(dataList);
}

void WidgetSegmentTimeDisplay::read(const QJsonObject &json)
{
    m_dataList.clear();

    QJsonArray segmentDataArray = json["segmentData"].toArray();
    for (int segmentIndex = 0; segmentIndex < segmentDataArray.size(); ++segmentIndex) {
        QJsonObject segmentObject = segmentDataArray[segmentIndex].toObject();
        WidgetSegmentTimeData* newData = this->addNewSegment();
        newData->read(segmentObject);
        newData->updateDisplayData();
        m_dataList.push_back(newData);
    }
    cbiSegmentDataInterface_UpdatedData();
}

void WidgetSegmentTimeDisplay::write(QJsonObject &json) const
{
    QJsonArray segmentDataArray;
    foreach (const WidgetSegmentTimeData* data, m_dataList) {
        QJsonObject segmentObject;
        data->write(segmentObject);
        segmentDataArray.append(segmentObject);
    }
    json["segmentData"] = segmentDataArray;
}
