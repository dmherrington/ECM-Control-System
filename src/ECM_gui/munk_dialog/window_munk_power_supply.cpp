#include "window_munk_power_supply.h"
#include "ui_window_munk_power_supply.h"

Window_MunkPowerSupply::Window_MunkPowerSupply(MunkPowerSupply *obj, QWidget *parent) :
    GeneralDialogWindow(DialogWindowTypes::WINDOW_POWERSUPPLY,"MunkPS",parent),
    ui(new Ui::Window_MunkPowerSupply),
    windowHidden(true),
    munk(obj)
{
    //Required registration of MetaTyples from the Munk interface
    ui->setupUi(this);
    ui->widget_connection->setDiameter(5);
    ui->progressBar->setValue(0);

    ui->radioButton_singlePulse->setChecked(true);
    ui->spinBox_NumPulses->setValue(1);
    ui->spinBox_NumPulses->setDisabled(true);

    ui->widget_DeviceFault->hide();
    connect(ui->widget_DeviceFault, SIGNAL(signal_TransmitClearFault()), this, SLOT(slot_ClearFaultRequested()));
    connect(munk, SIGNAL(signal_FaultStateCleared()), this, SLOT(slot_FaultStateCleared()));

    connect(munk, SIGNAL(signal_MunkCommunicationUpdate(common::comms::CommunicationUpdate)), this, SLOT(on_connectionUpdated(common::comms::CommunicationUpdate)));
    connect(munk, SIGNAL(signal_SegmentWriteProgress(int,int)), this, SLOT(slot_ParameterTransmissionUpdate(int,int)));
    connect(munk, SIGNAL(signal_FaultCodeRecieved()), this, SLOT(slot_FaultCodeReceived()));

    connect(munk, SIGNAL(signal_SegmentException(std::string,std::string)), this, SLOT(slot_SegmentExceptionReceived(std::string,std::string)));

    connect(ui->segmentWidget, SIGNAL(signal_SegmentDataModified()), this, SLOT(slot_SegmentDataModified()));

    GeneralDialogWindow::readWindowSettings();

    openFromFile(GeneralDialogWindow::getPreviousSettingsPath());
}

Window_MunkPowerSupply::~Window_MunkPowerSupply()
{
    delete ui;
}

void Window_MunkPowerSupply::closeEvent(QCloseEvent *event)
{
    saveToFile(getPreviousSettingsPath());
    GeneralDialogWindow::closeEvent(event);
}

void Window_MunkPowerSupply::on_connectionUpdated(const common::comms::CommunicationUpdate &connection)
{
    if(connection.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::CONNECTED)
        ui->widget_connection->setColor(QColor(0,255,0));
    else if(connection.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::DISCONNECTED)
        ui->widget_connection->setColor(QColor(255,0,0));
}
void Window_MunkPowerSupply::on_pushButton_AddSegment_released()
{
    ui->segmentWidget->addNewSegment();
    ui->segmentWidget->cbiSegmentDataInterface_UpdatedData();
}


void Window_MunkPowerSupply::on_pushButton_transmit_released()
{
    //first allow us to get the pulse mode
    munk->writeRegisterPulseMode(this->getPulseMode());

    //next, send the segment data
    registers_Munk::SegmentTimeDetailed dataSegment = ui->segmentWidget->getRawData();
    munk->generateAndTransmitMessage(dataSegment);
}

void Window_MunkPowerSupply::slot_ParameterTransmissionUpdate(const int &transmitted, const int &required)
{
    double percentage = ((double)transmitted/(double)required) * 100.0;
    ui->progressBar->setValue(percentage);
}

void Window_MunkPowerSupply::slot_SegmentDataModified()
{
    ui->progressBar->setValue(0);
}


void Window_MunkPowerSupply::slot_FaultCodeReceived()
{
    std::vector<std::string> currentFaultCodes;
    if(munk->machineState->getCurrentFaultCodes(currentFaultCodes))
    {
        ui->widget_DeviceFault->receivedFaultMessage(currentFaultCodes);
        ui->widget_DeviceFault->show();
    }
    else
        ui->widget_DeviceFault->hide();
}

void Window_MunkPowerSupply::slot_ClearFaultRequested()
{
    munk->resetFaultState();
}

void Window_MunkPowerSupply::slot_FaultStateCleared()
{
    ui->widget_DeviceFault->clearFaultMessage();
    ui->widget_DeviceFault->hide();
}

void Window_MunkPowerSupply::slot_SegmentExceptionReceived(const std::string &RW, const std::string &meaning)
{
    std::string display = "An exception has been raised while " + RW + ": " + meaning;
    ui->statusbar->showMessage(QString::fromStdString(display),2000);
}

void Window_MunkPowerSupply::on_actionOpen_triggered()
{
    QString filePath = GeneralDialogWindow::onOpenAction();
    if(!filePath.isEmpty() && !filePath.isNull()){
        openFromFile(filePath);
    }
}

void Window_MunkPowerSupply::on_actionSave_triggered()
{
    QString settingsPath = GeneralDialogWindow::onSaveAction();
    saveToFile(settingsPath);
}

void Window_MunkPowerSupply::on_actionSave_As_triggered()
{
    QString settingsPath = GeneralDialogWindow::onSaveAsAction();
    saveToFile(settingsPath);
}

void Window_MunkPowerSupply::on_actionClose_triggered()
{
    GeneralDialogWindow::onCloseAction();
}

void Window_MunkPowerSupply::saveToFile(const QString &filePath)
{
    QFile saveFile(filePath);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        ui->statusbar->showMessage("Couldn't open file for saving.",2000);
        return;
    }
    QJsonObject saveObject;
    ui->segmentWidget->write(saveObject);
    QJsonDocument saveDoc(saveObject);
    saveFile.write(saveDoc.toJson());
    saveFile.close();
}

void Window_MunkPowerSupply::openFromFile(const QString &filePath)
{
    QFile openFile(filePath);

    if (!openFile.open(QIODevice::ReadOnly)) {
        ui->statusbar->showMessage("Couldn't open file for reading.",2000);
    }

    QByteArray loadData = openFile.readAll();
    openFile.close();

    QJsonDocument loadDoc(QJsonDocument::fromJson(loadData));
    ui->segmentWidget->read(loadDoc.object());
}

registers_Munk::Register_PulseMode Window_MunkPowerSupply::getPulseMode() const
{
    registers_Munk::Register_PulseMode pulseMode;
    pulseMode.setSlaveAddress(01);
    pulseMode.setPulseMode(data_Munk::TypePulseModes::ECMIntern);
    pulseMode.setTriggerCount(ui->spinBox_NumPulses->value());
    return pulseMode;
}

void Window_MunkPowerSupply::on_radioButton_singlePulse_clicked(bool checked)
{
    ui->progressBar->setValue(0);

    if(checked)
    {
        ui->spinBox_NumPulses->setValue(1);
        ui->spinBox_NumPulses->setDisabled(true);
    }
}

void Window_MunkPowerSupply::on_radioButton_continuousPulse_clicked(bool checked)
{
    ui->progressBar->setValue(0);

    if(checked)
    {
        ui->spinBox_NumPulses->setValue(255);
        ui->spinBox_NumPulses->setDisabled(true);
    }
}

void Window_MunkPowerSupply::on_radioButton_specifiedPulses_clicked(bool checked)
{
    ui->progressBar->setValue(0);

    if(checked)
    {
        ui->spinBox_NumPulses->setDisabled(false);
    }
}

void Window_MunkPowerSupply::on_spinBox_NumPulses_valueChanged(int arg1)
{

}