#ifndef GALIL_STATE_MACHINE_H
#define GALIL_STATE_MACHINE_H

#include <iostream>
#include <QDate>

#include "common/environment_time.h"
#include "common/threadmanager.h"
#include "common/timer.h"


class GalilSM_Interface
{
public:
    virtual void cbiGalilSM_newPosition(const Data::EnvironmentTime &time, const double &pos) = 0;
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

    void connectCallback(GalilSM_Interface *cb)
    {
        m_CB = cb;
    }

private:
    Timer m_Timeout;
    int timeout;

private:
    GalilSM_Interface *m_CB;

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
