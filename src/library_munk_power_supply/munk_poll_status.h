#ifndef MUNK_POLL_STATUS_H
#define MUNK_POLL_STATUS_H


#include <iostream>
#include <QDate>

#include "common/environment_time.h"
#include "common/threadmanager.h"
#include "common/timer.h"

#include "data_registers/register_fault_state.h"

class MunkStatusCallback_Interface
{
public:
    virtual void cbi_MunkFaultStateRequest(const registers_Munk::RegisterFaultState &request) const = 0;
};

class MunkPollStatus : public Thread
{
public:
    MunkPollStatus(const int &msTimeout = 1000);

    ~MunkPollStatus() {
        std::cout << "Destructor on the munk poll status object" << std::endl;
        mToExit = true;
    }

    void beginPolling();
    void pausePolling();

    void run();

    void connectCallback(MunkStatusCallback_Interface *cb)
    {
        m_CB = cb;
    }

private:
    Timer m_Timeout;
    int timeout;

private:
    MunkStatusCallback_Interface *m_CB;

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

#endif // MUNK_POLL_STATUS_H
