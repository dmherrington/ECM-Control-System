#include "dialog_pump_control.h"
#include "ui_dialog_pump_control.h"

Dialog_PumpControl::Dialog_PumpControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_PumpControl)
{
    ui->setupUi(this);
}

Dialog_PumpControl::~Dialog_PumpControl()
{
    delete ui;
}
