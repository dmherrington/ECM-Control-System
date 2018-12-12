#include "dialog_execution_paused.h"
#include "ui_dialog_execution_paused.h"

Dialog_ExecutionPaused::Dialog_ExecutionPaused(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_ExecutionPaused)
{
    ui->setupUi(this);
}

Dialog_ExecutionPaused::~Dialog_ExecutionPaused()
{
    delete ui;
}

void Dialog_ExecutionPaused::on_buttonBox_accepted()
{
    emit signal_HandleExecution(true);
}

void Dialog_ExecutionPaused::on_buttonBox_rejected()
{
    emit signal_HandleExecution(false);
}
