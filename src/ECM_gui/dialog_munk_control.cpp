#include "dialog_munk_control.h"
#include "ui_dialog_munk_control.h"

Dialog_MunkControl::Dialog_MunkControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_MunkControl)
{
    ui->setupUi(this);
}

Dialog_MunkControl::~Dialog_MunkControl()
{
    delete ui;
}
