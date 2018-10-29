#include "window_munk_temperature_status.h"
#include "ui_window_munk_temperature_status.h"

Window_MunkTemperatureStatus::Window_MunkTemperatureStatus(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_MunkTemperatureStatus)
{
    ui->setupUi(this);
    Widget_MunkTemperatureState* state1 = new Widget_MunkTemperatureState();
    ui->verticalLayout->addWidget(state1);
}

Window_MunkTemperatureStatus::~Window_MunkTemperatureStatus()
{
    delete ui;
}
