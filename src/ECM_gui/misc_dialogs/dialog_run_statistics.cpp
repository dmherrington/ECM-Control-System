#include "dialog_run_statistics.h"
#include "ui_dialog_run_statistics.h"

Dialog_RunStatistics::Dialog_RunStatistics(const common::SimplifiedTime &globalRuntime, const common::SimplifiedTime &dailyRuntime, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_RunStatistics)
{
    ui->setupUi(this);
    ui->label_totalTime->setText(globalRuntime.getQString());
    ui->label_dailyTime->setText(dailyRuntime.getQString());
}

Dialog_RunStatistics::~Dialog_RunStatistics()
{
    delete ui;
}
