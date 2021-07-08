#ifndef PLC_POLL_MACHINE_H
#define PLC_POLL_MACHINE_H

#include <map>

#include <iostream>
#include <QDate>

#include "common/environment_time.h"
#include "common/publisher.h"
#include "common/threadmanager.h"
#include "common/timer.h"
#include "common/tuple_ecm_data.h"

#include "data_registers/abstract_register.h"

class PLCPollingEvents_Interface
{

public:
    PLCPollingEvents_Interface() = default;
    virtual ~PLCPollingEvents_Interface() = default;

public:
    virtual void PLCPolling_NewReadRequest(const registers_PLC::AbstractPLCRegisterPtr req) = 0;
};

class PLCPollMachine : public Publisher<PLCPollingEvents_Interface>, public Thread
{
public:
    PLCPollMachine(const unsigned int &msTimeout = 1000);

    ~PLCPollMachine() {
        std::cout << "Destructor on the plc timeout state machine" << std::endl;
        mToExit = true;
    }

    void beginPolling();
    void pausePolling();

    void addReadRegister(const registers_PLC::AbstractPLCRegisterPtr request, const int &period = 1000);

    void run();

private:
    void addReadRegisterToQueue(const registers_PLC::AbstractPLCRegisterPtr request, const int &period = 1000);

    int greatestCommonDenominator(int a,int b) {
        int temp;
        while(b > 0) {
            temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

private:
    typedef std::pair<double, double> pollingTimeout;

private:
    Timer m_Timeout;
    unsigned int timeout;

private:
    std::map<registers_PLC::PLCRegisterTypes,registers_PLC::AbstractPLCRegisterPtr> requestMap;
    std::map<registers_PLC::PLCRegisterTypes,pollingTimeout> timeoutMap;

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

#endif // PLC_POLL_MACHINE_H
