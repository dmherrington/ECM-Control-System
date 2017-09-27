#ifndef MUNK_TX_RX_H
#define MUNK_TX_RX_H

#include <QByteArray>
#include <list>
#include <functional>

#include "common/threadmanager.h"
#include "common/timer.h"

class MunkTXRX_Interface
{
public:

};

class MunkTXRX : public Thread
{
public:
    MunkTXRX();

    ~MunkTXRX() {
        std::cout << "Destructor on the munk txrx controller" << std::endl;
        mToExit = true;
    }

    void run();

    void connectCallback(MunkTXRX_Interface *cb)
    {
        m_CB = cb;
    }

    void transmitBytes(const std::vector<QByteArray> &byteVector);

    void receivedBytes(const QByteArray &array);

private:
    void clearPreviousTransmit();
    bool searchForStartingIndex(const QByteArray &array, int &index);

private:
    MunkTXRX_Interface* m_CB;

    Timer mTimer;
    int currentRetry;
    int maxRetries;
    int responseTimeout;

private:
    std::vector<QByteArray> transArray;
    QByteArray prevTxArray;
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
