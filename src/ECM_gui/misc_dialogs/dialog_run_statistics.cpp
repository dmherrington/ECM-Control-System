#include "dialog_run_statistics.h"
#include "ui_dialog_run_statistics.h"

Dialog_RunStatistics::Dialog_RunStatistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_RunStatistics)
{
    ui->setupUi(this);
}

Dialog_RunStatistics::~Dialog_RunStatistics()
{
    delete ui;
}
