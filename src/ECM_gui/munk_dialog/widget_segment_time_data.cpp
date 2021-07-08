#include "widget_segment_time_data.h"
#include "ui_widget_segment_time_data.h"

WidgetSegmentTimeData::WidgetSegmentTimeData(const bool &expandedModes, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetSegmentTimeData),
    m_CB(nullptr), blockCallback(false)
{
    ui->setupUi(this);

    data = new registers_Munk::SegmentTimeDataDetailed();

    setExpandedMunkDriverModes(expandedModes,data_Munk::SegmentModeToString(data_Munk::SegmentMode::FORWARD));
}

WidgetSegmentTimeData::~WidgetSegmentTimeData()
{
    if(data)
    {
        delete data;
        data = nullptr;
    }

    delete ui;
}
void WidgetSegmentTimeData::setExpandedMunkDriverModes(const bool &expandedModes, const std::string &defaultSelection)
{
    const bool wasBlocked = ui->comboBox_Mode->blockSignals(true);

    QString currentSelection = QString::fromStdString(defaultSelection);

    std::vector<std::string> modeValues;

    if(expandedModes)
        modeValues = data_Munk::getExpandedListOfSegmentModes();
    else
        modeValues = data_Munk::getAbbreviatedListOfSegmentModes();

    if(currentSelection.isEmpty())
        currentSelection = this->ui->comboBox_Mode->currentText();

    this->ui->comboBox_Mode->clear();

    size_t size = modeValues.size();
    for(unsigned int i = 0; i < size; i++)
        this->ui->comboBox_Mode->addItem(QString::fromStdString(modeValues[i]));

    int index = this->ui->comboBox_Mode->findText(currentSelection);
    if(index == -1)
        this->ui->comboBox_Mode->setCurrentIndex(0);
    else
        this->ui->comboBox_Mode->setCurrentIndex(index);

    ui->comboBox_Mode->blockSignals(wasBlocked);
}

void WidgetSegmentTimeData::loadFromSegmentData(const registers_Munk::SegmentTimeDataDetailed &segmentData)
{
    this->data->updateData(segmentData);
    this->updateDisplayData();
}

void WidgetSegmentTimeData::updateDisplayData() const
{
    blockCallback = true;

    int modeIndex = ui->comboBox_Mode->findText(QString::fromStdString(data_Munk::SegmentModeToString(data->getSegmentMode())));
    ui->comboBox_Mode->setCurrentIndex(modeIndex);
    ui->doubleSpinBox_Current->setValue(data->getSegmentCurrent());
    ui->doubleSpinBox_Time->setValue(data->getTimeValue() / 1000.0);
    ui->doubleSpinBox_Voltage->setValue(data->getSegmentVoltage());

    blockCallback = false;
}

void WidgetSegmentTimeData::updateSegmentName(const int &segmentNumber)
{
    std::string segmentText = "Segment #" + std::to_string(segmentNumber);
    ui->label_SegmentName->setText(QString::fromStdString(segmentText));
}

void WidgetSegmentTimeData::on_comboBox_Mode_currentIndexChanged(const QString &arg1)
{
    data_Munk::SegmentMode selectedMode = data_Munk::SegmentModeFromString(arg1.toStdString());
    data->setSegmentMode(selectedMode);

    if((selectedMode == data_Munk::SegmentMode::HIZ) || (selectedMode == data_Munk::SegmentMode::DEAD))
    {
        ui->doubleSpinBox_Current->setValue(0.0);
        ui->doubleSpinBox_Current->setEnabled(false);
        ui->doubleSpinBox_Voltage->setValue(0.0);
        ui->doubleSpinBox_Voltage->setEnabled(false);
    }
    else{
        if(!ui->doubleSpinBox_Current->isEnabled())
        {
            ui->doubleSpinBox_Current->setEnabled(true);
        }
        if(!ui->doubleSpinBox_Voltage->isEnabled())
        {
            ui->doubleSpinBox_Voltage->setEnabled(true);
        }
    }

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
    data->setTimeValue(static_cast<uint32_t>(arg1 * 1000.0));
    emitCallback();
}

void WidgetSegmentTimeData::on_pushButton_released()
{
    if(m_CB)
    {
        m_CB->cbiSegmentDataInterface_RemoveData(this);
    }
}
