#ifndef RIGOL_POLL_MEASUREMENTS_H
#define RIGOL_POLL_MEASUREMENTS_H

#include <iostream>
#include <map>

#include <QDate>

#include "common/environment_time.h"
#include "common/threadmanager.h"
#include "common/timer.h"

#include "commands/measure/measure_command_item.h"
#include "commands/measure/rigol_measurement_queue.h"

class RigolMeasurementUpdates_Interface
{
public:
    virtual void cbi_RigolMeasurementRequests(const commands_Rigol::MeasureCommand_Item &request) = 0;
};


class RigolPollMeasurement : public Thread
{
public:
    RigolPollMeasurement(const int &msTimeout = 100);

    ~RigolPollMeasurement() {
        std::cout << "Destructor on the galil timeout state machine" << std::endl;
        mToExit = true;
    }
public:
    void addPollingMeasurement(const commands_Rigol::MeasureCommand_Item &command);

    void removePollingMeasurement(const std::string &key);

    void clearQueue();

    commands_Rigol::RigolMeasurementQueue getCurrentPollingMeasurements() const;

public:
    void beginPolling();

    void pausePolling();

    void run();

    void connectCallback(RigolMeasurementUpdates_Interface *cb)
    {
        m_CB = cb;
    }

private:
    Timer m_Timeout;
    int timeout;

private:
    RigolMeasurementUpdates_Interface *m_CB;

    commands_Rigol::RigolMeasurementQueue measurementQueue;

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
