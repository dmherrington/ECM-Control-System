#include "widget_channel_measurements.h"
#include "ui_widget_channel_measurements.h"

WidgetChannelMeasurements::WidgetChannelMeasurements(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetChannelMeasurements)
{
    ui->setupUi(this);
    ui->listWidget_Measurements->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget_Measurements,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(showListContextMenu(QPoint)));
}

WidgetChannelMeasurements::~WidgetChannelMeasurements()
{
    delete ui;
}

void WidgetChannelMeasurements::showListContextMenu(const QPoint &pos)
{
    //Handle the global position selected
    QPoint globalPos = ui->listWidget_Measurements->mapToGlobal(pos);
    QMenu listMenu;
    listMenu.addAction("Erase",this,SLOT(eraseItem()));
    listMenu.exec(globalPos);
}

void WidgetChannelMeasurements::eraseItem()
{
    std::cout<<"We are going to try and delete an item"<<std::endl;
    // If multiple selection is on, we need to erase all selected items
    int listSelectionSize = ui->listWidget_Measurements->selectedItems().size();
    for (int i = 0; i < listSelectionSize; ++i) {
        // Get curent item on selected row
        QListWidgetItem *item = ui->listWidget_Measurements->takeItem(ui->listWidget_Measurements->currentRow());
        // And remove it
        delete item;
    }
}

void WidgetChannelMeasurements::setMeasurementChannel(const rigol::data_Rigol::AvailableChannels &channel)
{
    this->ui->label_Channel->setText(QString::fromStdString(rigol::data_Rigol::AvailableChannelsToDisplayString(channel)));
}

void WidgetChannelMeasurements::addMeasurement(const commands_Rigol::MeasureCommand_Item* measurement)
{
    std::string str = rigol::data_Rigol::MeasurementTypeEnumToString(measurement->getMeasurementType());
    this->ui->listWidget_Measurements->addItem(QString::fromStdString(str));
}

void WidgetChannelMeasurements::removeMeasurement(const std::string &key)
{

}
