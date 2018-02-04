#ifndef RIGOL_POLL_MEASUREMENTS_H
#define RIGOL_POLL_MEASUREMENTS_H

#include <iostream>
#include <QDate>

#include "common/environment_time.h"
#include "common/threadmanager.h"
#include "common/timer.h"

#include "commands/measure/abstract_measure_command.h"

class GalilStatusUpdate_Interface
{
public:
    virtual void cbi_GalilStatusRequest() = 0;
};


class RigolPollMeasurement : public Thread
{
public:
    RigolPollMeasurement(const int &msTimeout = 50);

    ~RigolPollMeasurement() {
        std::cout << "Destructor on the galil timeout state machine" << std::endl;
        mToExit = true;
    }
public:
    void addPollingMeasurement(const rigol::commands::AbstractMeasureCommand* command);

public:

    void beginPolling();

    void pausePolling();

    void run();

    void connectCallback(GalilStatusUpdate_Interface *cb)
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

#endif // RIGOL_POLL_MEASUREMENTS_H
