#ifndef GALIL_STATE_MACHINE_H
#define GALIL_STATE_MACHINE_H

#include <iostream>
#include <QDate>

#include "common/environment_time.h"
#include "common/threadmanager.h"
#include "common/timer.h"

#include "requests/request_components.h"

class GalilStatusUpdate_Interface
{
public:
    virtual void cbi_GalilStatusRequestPosition() = 0;
    virtual void cbi_GalilStatusRequestSwitches() = 0;
    virtual void cbi_GalilStatusRequestStopCodes() = 0;
};

class GalilPollState : public Thread
{
public:
    GalilPollState(const int &msTimeout = 20);

    ~GalilPollState() {
        std::cout << "Destructor on the galil timeout state machine" << std::endl;
        mToExit = true;
    }

    void beginPolling();
    void pausePolling();

    void run();

    void connectCallback(GalilPolling_Interface *cb)
    {
        m_CB = cb;
    }

private:
    Timer m_Timeout;
    int timeout;

private:
    GalilStatusUpdate_Interface *m_CB;

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
