#include "window_munk_power_supply.h"
#include "ui_window_munk_power_supply.h"

Window_MunkPowerSupply::Window_MunkPowerSupply(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_MunkPowerSupply)
{
    ui->setupUi(this);
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
    QSettings settings("MUNKTech", "Application Example");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();
    resize(size);
    move(pos);
}

void Window_MunkPowerSupply::closeEvent(QCloseEvent *event)
{
    QSettings settings("MUNKTech", "Application Example");
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

void Window_MunkPowerSupply::on_pushButton_AddSegment_released()
{
    ui->segmentWidget->addNewSegment();
    ui->segmentWidget->cbiSegmentDataInterface_UpdatedData();
}
