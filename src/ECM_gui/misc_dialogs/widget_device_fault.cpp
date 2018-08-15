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
    //We will need a better way to do this
    ui->plainTextEdit_ErrorMessage->document()->setPlainText(QString::fromStdString(msg.at(0)));
}
