#include "widget_segment_time_data.h"
#include "ui_widgetsegmenttimedata.h"

WidgetSegmentTimeData::WidgetSegmentTimeData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetSegmentTimeData),
    m_CB(NULL)
{
    ui->setupUi(this);

    data = new DataParameter::SegmentTimeDataDetailed();

    std::vector<std::string> modeValues = Data::getListOfSegmentMode();

    size_t size = modeValues.size();
    for(unsigned int i = 0; i < size; i++)
        this->ui->comboBox_Mode->addItem(QString::fromStdString(modeValues[i]));

    int index = this->ui->comboBox_Mode->findText(QString::fromStdString(Data::SegmentModeToString(data->getSegmentMode())));
    this->ui->comboBox_Mode->setCurrentIndex(index);

}

WidgetSegmentTimeData::~WidgetSegmentTimeData()
{
    delete ui;
}

void WidgetSegmentTimeData::on_comboBox_Mode_currentIndexChanged(const QString &arg1)
{
    data->setSegmentMode(Data::SegmentModeFromString(arg1.toStdString()));
    emitCallback();
}

void WidgetSegmentTimeData::on_doubleSpinBox_Voltage_valueChanged(const double arg1)
{
    data->setSegmentVoltage(arg1);
    emitCallback();
}

void WidgetSegmentTimeData::on_doubleSpinBox_Current_valueChanged(const double arg1)
{
    data->setSegmentCurrent(arg1);
    emitCallback();
}

void WidgetSegmentTimeData::on_doubleSpinBox_Time_valueChanged(const double arg1)
{
    data->setTimeValue(arg1);
    emitCallback();
}
