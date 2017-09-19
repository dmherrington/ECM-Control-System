#include "widget_segment_time_data.h"
#include "ui_widget_segment_time_data.h"

Widget_SegmentTimeData::Widget_SegmentTimeData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_SegmentTimeData)
{
    ui->setupUi(this);

    data = new DataParameter::SegmentTimeDataDetailed();

    std::vector<std::string> modeValues = Data::getListOfSegmentMode();

    size_t size = modeValues.size();
    for(unsigned int i = 0; i < size; i++)
        this->ui->comboBox->addItem(QString::fromStdString(modeValues[i]));

    int index = this->ui->comboBox->findText(QString::fromStdString(Data::SegmentModeToString(data->getSegmentMode())));
    this->ui->comboBox->setCurrentIndex(index);
}

Widget_SegmentTimeData::~Widget_SegmentTimeData()
{
    delete ui;
}

void Widget_SegmentTimeData::on_doubleSpinBox_voltage_valueChanged(double arg1)
{
    data->setSegmentVoltage(arg1);
}

void Widget_SegmentTimeData::on_doubleSpinBox_current_valueChanged(double arg1)
{
    data->setSegmentCurrent(arg1);
}

void Widget_SegmentTimeData::on_doubleSpinBox_duration_valueChanged(double arg1)
{
    data->setTimeValue(arg1);
}

void Widget_SegmentTimeData::on_comboBox_currentIndexChanged(const QString &arg1)
{
    data->setSegmentMode(Data::SegmentModeFromString(arg1.toStdString()));
}
