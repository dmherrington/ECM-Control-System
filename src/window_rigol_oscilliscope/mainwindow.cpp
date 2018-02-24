#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    rigolInterface(new RigolOscilliscope)
{
    ui->setupUi(this);
    std::vector<AvailableChannels> avaialableChannels = rigol::data::getListOfAvailableChannelsEnum();

    for(size_t i = 0; i < avaialableChannels.size(); i++)
    {
        std::string channelString = rigol::data::AvailableChannelsToDisplayString(avaialableChannels.at(i));
        ui->comboBox_MeasurementChannels->insertItem(i,QString::fromStdString(channelString));

        WidgetChannelMeasurements* newChannel = new WidgetChannelMeasurements();
        newChannel->setMeasurementChannel(avaialableChannels.at(i));
        mapWidgets.insert(std::pair<AvailableChannels,WidgetChannelMeasurements*>(avaialableChannels.at(i),newChannel));
        ui->verticalLayout_ChannelMeasurements->addWidget(newChannel);
    }

    std::vector<std::string> availableMeasurements = rigol::data::getListOfAvailableMeasurements();
    for(size_t i = 0; i < availableMeasurements.size(); i++)
    {
        ui->comboBox_MeasurementType->insertItem(i,QString::fromStdString(availableMeasurements.at(i)));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_AddMeasurement_released()
{
    rigolInterface->openConnection("192.168.1.17",5555);

    rigol::commands::MeasureCommand_Item measureArea;
    measureArea.setChannel(rigol::data::AvailableChannels::CHANNEL_1);
    measureArea.setMeasurementType(rigol::data::MeasurementTypes::MEASURE_MAREA);
    rigolInterface->addPollingMeasurement(measureArea);

    rigol::commands::MeasureCommand_Item measureVtop;
    measureVtop.setChannel(rigol::data::AvailableChannels::CHANNEL_2);
    measureVtop.setMeasurementType(rigol::data::MeasurementTypes::MEASURE_VTOP);
    rigolInterface->addPollingMeasurement(measureVtop);

    rigolInterface->executeMeasurementPolling(true);

//    std::string channel = this->ui->comboBox_MeasurementChannels->currentText().toStdString();
//    AvailableChannels desiredChannel = AvailableChannelsDisplayToEnum(channel);

//    std::string measurement = this->ui->comboBox_MeasurementType->currentText().toStdString();
//    MeasurementTypes desiredMeasurement = AvailableMeasurementTypeStringToEnum(measurement);

//    rigol::commands::MeasureCommand_Item* newMeasurement = new rigol::commands::MeasureCommand_Item(desiredChannel,desiredMeasurement);
//    rigolInterface->addPollingMeasurement(*newMeasurement);

//    mapWidgets.at(desiredChannel)->addMeasurement(newMeasurement);
//    queue.insertIntoQueue(*newMeasurement);
//    if(queue.getQueueSize() > 3)
//    {
//        rigolInterface->saveMeasurements();
//    }
}
