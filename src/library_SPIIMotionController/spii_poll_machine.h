#ifndef SPII_POLL_STATUS_H
#define SPII_POLL_STATUS_H

#include <map>

#include <iostream>
#include <QDate>

#include "ACSC.h"

#include "common/environment_time.h"
#include "common/threadmanager.h"
#include "common/timer.h"

#include "requests/request_components.h"

class SPIIStatusUpdate_Interface
{
public:
    SPIIStatusUpdate_Interface() = default;

    virtual ~SPIIStatusUpdate_Interface() = default;

    virtual void cbi_SPIIStatusRequest() = 0;

};

class SPIIPollMachine : public Thread
{
public:
    SPIIPollMachine(const unsigned int &msTimeout = 50);

    ~SPIIPollMachine() {
        std::cout << "Destructor on the galil timeout state machine" << std::endl;
        mToExit = true;
    }

    void beginPolling();
    void pausePolling();

    void updateCommsHandle(std::shared_ptr<HANDLE> commsLink);

    void addRequest(const SPII::AbstractRequestPtr request, const int &period = 100);
    void removeRequest(const common::TupleECMData &tuple);

    void run();

    void connectCallback(SPIIStatusUpdate_Interface *cb)
    {
        m_CB = cb;
    }

private:
    void processRequest(const SPII::AbstractRequestPtr request);

private:
    void addRequestToQueue(const SPII::AbstractRequestPtr request, const int &period = 100);

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
    std::shared_ptr<HANDLE> m_SPIIDevice;

private:
    typedef pair<double, double> pollingTimeout;

private:
    Timer m_Timeout;
    unsigned int timeout;

private:
    SPIIStatusUpdate_Interface *m_CB;
    std::map<common::TupleECMData,SPII::AbstractRequestPtr> requestMap;
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

#endif // SPII_POLL_STATUS_H
