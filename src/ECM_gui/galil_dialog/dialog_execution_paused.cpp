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

void Dialog_ExecutionPaused::setText(const std::string &fieldText)
{
    ui->textBrowser->setText(QString::fromStdString(fieldText));
}

void Dialog_ExecutionPaused::on_pushButton_Ok_released()
{
    emit signal_HandleExecution(true);
    this->close();
}

void Dialog_ExecutionPaused::on_pushButton_Cancel_released()
{
    emit signal_HandleExecution(false);
    this->close();
}
