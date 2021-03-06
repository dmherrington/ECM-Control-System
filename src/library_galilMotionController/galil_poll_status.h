#ifndef GALIL_POLL_STATUS_H
#define GALIL_POLL_STATUS_H

#include <map>

#include <iostream>
#include <QDate>

#include "common/environment_time.h"
#include "common/threadmanager.h"
#include "common/timer.h"

#include "requests/request_components.h"

class GalilStatusUpdate_Interface
{
public:
    virtual void cbi_GalilStatusRequest(const AbstractRequestPtr request) = 0;
};

class GalilPollState : public Thread
{
public:
    GalilPollState(const int &msTimeout = 50);

    ~GalilPollState() {
        std::cout << "Destructor on the galil timeout state machine" << std::endl;
        mToExit = true;
    }

    void beginPolling();
    void pausePolling();

    void addRequest(const AbstractRequestPtr request, const int &period = 100);
    void removeRequest(const common::TupleECMData &tuple);

    void run();

    void connectCallback(GalilStatusUpdate_Interface *cb)
    {
        m_CB = cb;
    }

private:
    void addRequestToQueue(const AbstractRequestPtr request, const int &period = 100);

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
    typedef pair<double, double> pollingTimeout;

private:
    Timer m_Timeout;
    int timeout;

private:
    GalilStatusUpdate_Interface *m_CB;
    std::map<common::TupleECMData,AbstractRequestPtr> requestMap;
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

#endif // GALIL_STATE_MACHINE_H
