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

#include "requests/abstract_request.h"

class PLCPollingEvents_Interface
{

public:
    PLCPollingEvents_Interface() = default;
    virtual ~PLCPollingEvents_Interface() = default;

public:
    virtual void PLCPolling_NewRequest(const requests_PLC::AbstractRequestPtr req) = 0;
};

class PLCPollMachine : public Publisher<PLCPollingEvents_Interface>, public Thread
{
public:
    PLCPollMachine(const unsigned int &msTimeout = 50);

    ~PLCPollMachine() {
        std::cout << "Destructor on the plc timeout state machine" << std::endl;
        mToExit = true;
    }

    void beginPolling();
    void pausePolling();

    void addRequest(const requests_PLC::AbstractRequestPtr request, const int &period = 100);

    void run();

private:
    void addRequestToQueue(const requests_PLC::AbstractRequestPtr request, const int &period = 100);

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
    std::map<common::TupleECMData,requests_PLC::AbstractRequestPtr> requestMap;
    std::map<common::TupleECMData,pollingTimeout> timeoutMap;

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
