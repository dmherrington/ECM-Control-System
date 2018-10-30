#include "widget_munk_temperature_state.h"
#include "ui_widget_munk_temperature_state.h"

Widget_MunkTemperatureState::Widget_MunkTemperatureState(const unsigned int &boardNumber, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_MunkTemperatureState)
{
    ui->setupUi(this);
    ui->lineEdit_BoardNumber->setText(QString::number(boardNumber));
}

Widget_MunkTemperatureState::~Widget_MunkTemperatureState()
{
    delete ui;
}

void Widget_MunkTemperatureState::updateTemperatures(const double &temperature1, const double &temperature2)
{
    this->updateTemperature1(temperature1);
    this->updateTemperature2(temperature2);
}

void Widget_MunkTemperatureState::updateTemperature1(const double &temperature)
{
    ui->lineEdit_Temp1->setText(QString::number(temperature));
}

void Widget_MunkTemperatureState::updateTemperature2(const double &temperature)
{
    ui->lineEdit_Temp2->setText(QString::number(temperature));
}
