#include "window_munk_power_supply.h"
#include "ui_window_munk_power_supply.h"

Window_MunkPowerSupply::Window_MunkPowerSupply(MunkPowerSupply *obj, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_MunkPowerSupply),
    munk(obj)
{
    ui->setupUi(this);
    ui->widget_connection->setDiameter(6);

    connect(munk,SIGNAL(signal_MunkConnectionUpdate(common::comms::CommunicationConnection)),this,SLOT(on_connectionUpdated(common::comms::CommunicationConnection)));

    readSettings();
}

Window_MunkPowerSupply::~Window_MunkPowerSupply()
{
    delete ui;
}

bool Window_MunkPowerSupply::isWindowHidden() const
{
    return windowHidden;
}

void Window_MunkPowerSupply::readSettings()
{
    QSettings settings("Munk Window", "ECM Application");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();
    resize(size);
    move(pos);
}

void Window_MunkPowerSupply::closeEvent(QCloseEvent *event)
{
    QSettings settings("Munk Window", "ECM Application");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}

void Window_MunkPowerSupply::hideEvent(QHideEvent *event)
{
    windowHidden = true;
}

void Window_MunkPowerSupply::showEvent(QShowEvent *event)
{
    windowHidden = false;
}

void Window_MunkPowerSupply::on_connectionUpdated(const common::comms::CommunicationConnection &connection)
{
    if(connection.isConnected())
        ui->widget_connection->setColor(QColor(0,255,0));
    else
        ui->widget_connection->setColor(QColor(255,0,0));
}
void Window_MunkPowerSupply::on_pushButton_AddSegment_released()
{
    ui->segmentWidget->addNewSegment();
    ui->segmentWidget->cbiSegmentDataInterface_UpdatedData();
}

void Window_MunkPowerSupply::on_actionClose_triggered()
{
    this->hide();
}

void Window_MunkPowerSupply::on_pushButton_transmit_released()
{
    registers_Munk::SegmentTimeDetailed dataSegment = ui->segmentWidget->getRawData();
    munk->generateAndTransmitMessage(dataSegment);
}
