#include "widget_munk_power_supply.h"
#include "ui_widget_munk_power_supply.h"

Widget_MunkPowerSupply::Widget_MunkPowerSupply(MunkPowerSupply *obj, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_MunkPowerSupply),
    munk(obj)
{
    //Required registration of MetaTyples from the Munk interface
    ui->setupUi(this);

    ui->radioButton_singlePulse->setChecked(true);
    ui->spinBox_NumPulses->setValue(1);
    ui->spinBox_NumPulses->setDisabled(true);

    connect(munk, SIGNAL(signal_SegmentWriteProgress(int,int)), this, SLOT(slot_ParameterTransmissionUpdate(int,int)));

    connect(munk, SIGNAL(signal_SegmentException(std::string,std::string)), this, SLOT(slot_SegmentExceptionReceived(std::string,std::string)));

    connect(ui->segmentWidget, SIGNAL(signal_SegmentDataModified()), this, SLOT(slot_SegmentDataModified()));


    ui->segmentWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->segmentWidget, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(slot_onCustomContextMenu(const QPoint &)));

}

Widget_MunkPowerSupply::~Widget_MunkPowerSupply()
{
    delete ui;
}

void Widget_MunkPowerSupply::loadFromConfig(const PowerSupply_SetupConfig &config)
{
    this->updatePulseMode(config.m_MunkPulseMode.getTriggerCount());
    this->ui->segmentWidget->loadNewRegisters(config.m_MunkSegment);
}

registers_Munk::Register_PulseMode  Widget_MunkPowerSupply::getPulseModeRegister() const
{
    registers_Munk::Register_PulseMode pulseMode;
    pulseMode.setSlaveAddress(01);
    pulseMode.setPulseMode(data_Munk::TypePulseModes::ECMIntern);
    pulseMode.setTriggerCount(ui->spinBox_NumPulses->value());
    return pulseMode;
}

registers_Munk::SegmentTimeDetailed  Widget_MunkPowerSupply::getSegmentRegister() const
{
    registers_Munk::SegmentTimeDetailed dataSegment = ui->segmentWidget->getRawData();
    return dataSegment;
}

void Widget_MunkPowerSupply::slot_onCustomContextMenu(const QPoint &point)
{
    QMenu contextMenu(tr("Context menu"), this);

    QAction action1("Add Segment", this);
    connect(&action1, SIGNAL(triggered()), this, SLOT(contextMenu_AddSegment_released()));
    contextMenu.addAction(&action1);

    contextMenu.exec(mapToGlobal(point));
}

void Widget_MunkPowerSupply::contextMenu_AddSegment_released()
{
    this->addNewSegment();
}

void Widget_MunkPowerSupply::addNewSegment()
{
    ui->segmentWidget->addNewSegment();
    ui->segmentWidget->cbiSegmentDataInterface_UpdatedData();
}


//void Widget_MunkPowerSupply::on_pushButton_transmit_released()
//{
//    //first allow us to get the pulse mode
//    munk->writeRegisterPulseMode(this->getPulseMode());

//    //next, send the segment data
//    registers_Munk::SegmentTimeDetailed dataSegment = ui->segmentWidget->getRawData();
//    munk->generateAndTransmitMessage(dataSegment);
//}

void Widget_MunkPowerSupply::slot_ParameterTransmissionUpdate(const int &transmitted, const int &required)
{
    double percentage = ((double)transmitted/(double)required) * 100.0;
    //ui->progressBar->setValue(percentage);
}

void Widget_MunkPowerSupply::slot_SegmentDataModified()
{
    //ui->progressBar->setValue(0);
}


void Widget_MunkPowerSupply::slot_FaultCodeReceived()
{
//    std::vector<std::string> currentFaultCodes;
//    if(munk->machineState->getCurrentFaultCodes(currentFaultCodes))
//    {
//        ui->widget_DeviceFault->receivedFaultMessage(currentFaultCodes);
//        ui->widget_DeviceFault->show();
//    }
//    else
//        ui->widget_DeviceFault->hide();
}

void Widget_MunkPowerSupply::slot_ClearFaultRequested()
{
    munk->resetFaultState();
}

void Widget_MunkPowerSupply::slot_FaultStateCleared()
{
//    ui->widget_DeviceFault->clearFaultMessage();
//    ui->widget_DeviceFault->hide();
}

void Widget_MunkPowerSupply::slot_SegmentExceptionReceived(const std::string &RW, const std::string &meaning)
{
//    std::string display = "An exception has been raised while " + RW + ": " + meaning;
//    ui->statusbar->showMessage(QString::fromStdString(display),2000);
}

void Widget_MunkPowerSupply::writeToJSON(QJsonObject &saveObject)
{
    QJsonArray segmentDataArray;

    QJsonObject segmentObject;

    segmentObject["pulseMode"] = (int)ui->spinBox_NumPulses->value();

    ui->segmentWidget->writeToJSON(segmentObject);
    segmentDataArray.append(segmentObject);

    saveObject["MunkSettings"] = segmentDataArray;
}

void Widget_MunkPowerSupply::readFromJSON(const QJsonObject &openObject)
{
    QJsonArray powerSupplyDataArray = openObject["MunkSettings"].toArray();
    QJsonObject PSObject = powerSupplyDataArray[0].toObject();

    int numPulses = PSObject["pulseMode"].toInt();

    ui->segmentWidget->readFromJSON(PSObject);
}

registers_Munk::Register_PulseMode Widget_MunkPowerSupply::getPulseMode() const
{
    registers_Munk::Register_PulseMode pulseMode;
    pulseMode.setSlaveAddress(01);
    pulseMode.setPulseMode(data_Munk::TypePulseModes::ECMIntern);
    pulseMode.setTriggerCount(ui->spinBox_NumPulses->value());
    return pulseMode;
}

void Widget_MunkPowerSupply::updatePulseMode(const int &numPulses)
{
    ui->spinBox_NumPulses->setValue(numPulses);

    switch (numPulses) {
    case 1:
        ui->radioButton_singlePulse->setChecked(true);
        ui->spinBox_NumPulses->setDisabled(true);
        break;
    case 255:
        ui->radioButton_continuousPulse->setChecked(true);
        ui->spinBox_NumPulses->setDisabled(true);
        break;
    default:
        ui->radioButton_specifiedPulses->setChecked(true);
        ui->spinBox_NumPulses->setDisabled(false);
        break;
    }
}

void Widget_MunkPowerSupply::on_radioButton_singlePulse_clicked(bool checked)
{
    if(checked)
    {
        ui->spinBox_NumPulses->setValue(1);
        ui->spinBox_NumPulses->setDisabled(true);
    }
}

void Widget_MunkPowerSupply::on_radioButton_continuousPulse_clicked(bool checked)
{
    if(checked)
    {
        ui->spinBox_NumPulses->setValue(255);
        ui->spinBox_NumPulses->setDisabled(true);
    }
}

void Widget_MunkPowerSupply::on_radioButton_specifiedPulses_clicked(bool checked)
{
    if(checked)
    {
        ui->spinBox_NumPulses->setDisabled(false);
    }
}

void Widget_MunkPowerSupply::on_spinBox_NumPulses_valueChanged(int arg1)
{

}

