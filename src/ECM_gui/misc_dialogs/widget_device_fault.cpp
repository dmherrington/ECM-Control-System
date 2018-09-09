#include "widget_device_fault.h"
#include "ui_widget_device_fault.h"

Widget_DeviceFault::Widget_DeviceFault(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_DeviceFault)
{
    ui->setupUi(this);
}

Widget_DeviceFault::~Widget_DeviceFault()
{
    delete ui;
}

void Widget_DeviceFault::on_pushButton_ClearFault_released()
{
    emit signal_TransmitClearFault();
}

void Widget_DeviceFault::clearFaultMessage()
{
    ui->plainTextEdit_ErrorMessage->clear();
}

void Widget_DeviceFault::receivedFaultMessage(const std::vector<std::string> &msg)
{
    ui->plainTextEdit_ErrorMessage->clear();
    //We will need a better way to do this
    for(size_t i = 0; i < msg.size(); i++)
    {
        ui->plainTextEdit_ErrorMessage->appendPlainText(QString::fromStdString(msg.at(0)));
    }
}
