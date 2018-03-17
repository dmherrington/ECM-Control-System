#include "dialog_connections.h"
#include "ui_dialog_connections.h"

Dialog_Connections::Dialog_Connections(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Connections)
{
    ui->setupUi(this);
}

Dialog_Connections::~Dialog_Connections()
{
    delete ui;
}
