#ifndef TEST_TIME_H
#define TEST_TIME_H

#include <iostream>
#include <map>

#include <QDate>

#include "common/environment_time.h"

#include "common/threadmanager.h"
#include "common/timer.h"

class TestTime : public Thread
{
public:
    TestTime(const int &msTimeout = 100);

    ~TestTime() {
        std::cout << "Destructor on the galil timeout state machine" << std::endl;
        mToExit = true;
    }

public:
    void beginPolling();

    void pausePolling();

    void run();


private:
    Timer m_Timeout;
    int timeout;

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

#endif // RIGOL_POLL_MEASUREMENTS_H
