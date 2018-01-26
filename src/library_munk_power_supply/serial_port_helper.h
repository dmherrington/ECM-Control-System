#ifndef MUNK_TX_RX_H
#define MUNK_TX_RX_H

#include <QDebug>
#include <QByteArray>
#include <list>
#include <functional>

#include "data_registers/abstract_parameter.h"

#include "common/threadmanager.h"
#include "common/timer.h"

class SerialPortHelper : public QObject, public Thread
{
    Q_OBJECT

public:
    SerialPortHelper();

    ~SerialPortHelper() {
        std::cout << "Destructor on the serial port helper" << std::endl;
        mToExit = true;
    }

    void run();

    void transmitParameters(const std::vector<DataParameter::AbstractParameter*> &byteVector);

    void receivedBytes(const QByteArray &array);

signals:
    void bytesReceived(const QByteArray &data);
    void transmitByteArray(const QByteArray &array);

private:
    bool searchForStartingIndex(const QByteArray &array, int &index);

private:
    Timer mTimer;
    int currentRetry;
    int maxRetries;
    int responseTimeout;

private:
    std::vector<DataParameter::AbstractParameter*> transArray;
    DataParameter::AbstractParameter* prevParameter;

    QByteArray rxByteArray;

protected:
    std::list<std::function<void()>> m_LambdasToRun;

    void clearPendingTasks()
    {
        m_LambdasToRun.clear();
    }

    void RunPendingTasks() {
        while(m_LambdasToRun.size() > 0) {
            auto lambda = m_LambdasToRun.front();
            m_LambdasToRun.pop_front();
            lambda();
        }
    }
};


#endif // MUNK_TX_RX_H
