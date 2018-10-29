#include "widget_munk_temperature_state.h"
#include "ui_widget_munk_temperature_state.h"

Widget_MunkTemperatureState::Widget_MunkTemperatureState(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_MunkTemperatureState)
{
    ui->setupUi(this);
}

Widget_MunkTemperatureState::~Widget_MunkTemperatureState()
{
    delete ui;
}
