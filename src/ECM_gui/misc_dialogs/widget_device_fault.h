#ifndef WIDGET_DEVICE_FAULT_H
#define WIDGET_DEVICE_FAULT_H

#include <QWidget>

namespace Ui {
class Widget_DeviceFault;
}

class Widget_DeviceFault : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_DeviceFault(QWidget *parent = 0);
    ~Widget_DeviceFault();

public:
    void clearFaultMessage();

    void receivedFaultMessage(const std::vector<std::string> &msg);

signals:
    void signal_TransmitClearFault();

private slots:
    void on_pushButton_ClearFault_released();

private:
    Ui::Widget_DeviceFault *ui;
};

#endif // WIDGET_DEVICE_FAULT_H
