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

WidgetSegmentTimeData* WidgetSegmentTimeDisplay::addNewSegment()
{
    WidgetSegmentTimeData* newData = new WidgetSegmentTimeData();
    m_dataList.push_back(newData);
    newData->updateSegmentName(m_dataList.size());
    ui->horizontalLayout->addWidget(newData);
    newData->connectCallback(this);

    QSize currentSize = this->size();
    QSize size = newData->sizeHint();
    this->setMinimumHeight(size.height());
    this->resize(currentSize.width(), size.height());
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

void WidgetSegmentTimeDisplay::cbiSegmentDataInterface_RemoveData(WidgetSegmentTimeData* obj)
{
    m_dataList.remove(obj);
    ui->horizontalLayout->removeWidget(obj);
    delete obj;
    obj = NULL;

    int counter = 1;
    std::list<WidgetSegmentTimeData*>::iterator iterator;
    for (iterator = m_dataList.begin(); iterator != m_dataList.end(); ++iterator) {
        WidgetSegmentTimeData* data = *iterator;
        data->updateSegmentName(counter);
        counter++;
    }

    cbiSegmentDataInterface_UpdatedData();
}

void WidgetSegmentTimeDisplay::read(const QJsonObject &json)
{

    removeWidgets();

    QJsonArray segmentDataArray = json["segmentData"].toArray();
    for (int segmentIndex = 0; segmentIndex < segmentDataArray.size(); ++segmentIndex) {
        QJsonObject segmentObject = segmentDataArray[segmentIndex].toObject();
        WidgetSegmentTimeData* newData = this->addNewSegment();
        newData->read(segmentObject);
        newData->updateDisplayData();
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

DataParameter::SegmentTimeDetailed WidgetSegmentTimeDisplay::getRawData() const
{
    DataParameter::SegmentTimeDetailed detailedData(1);

    std::list<WidgetSegmentTimeData*>::const_iterator iterator;
    for (iterator = m_dataList.begin(); iterator != m_dataList.end(); ++iterator) {
        WidgetSegmentTimeData* data = *iterator;
        detailedData.appendRegisterData(*data->getData());
    }
    return detailedData;
}

void WidgetSegmentTimeDisplay::removeWidgets()
{
    std::list<WidgetSegmentTimeData*>::const_iterator iterator;
    for (iterator = m_dataList.begin(); iterator != m_dataList.end(); ++iterator) {
        ui->horizontalLayout->removeWidget(*iterator);
        delete *iterator;
    }
    m_dataList.clear();
}
