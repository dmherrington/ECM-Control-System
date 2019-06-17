#ifndef SENSORAY_POLL_MACHINE_H
#define SENSORAY_POLL_MACHINE_H

#include <map>

#include <iostream>
#include <QDate>

#include "common/environment_time.h"
#include "common/publisher.h"
#include "common/threadmanager.h"
#include "common/timer.h"

#include "communications/sensoray_comms_marshaler.h"

class SensorayPollingEvents_Interface
{

public:
    SensorayPollingEvents_Interface() = default;
    virtual ~SensorayPollingEvents_Interface() = default;

public:
    virtual void SensorayPolling_TemperatureUpdate() = 0;
};

class SensorayPollMachine : public Publisher<SensorayPollingEvents_Interface>, public Thread
{
public:
    SensorayPollMachine(const unsigned int &msTimeout = 1000);

    ~SensorayPollMachine() {
        std::cout << "Destructor on the sensoary poll machine" << std::endl;
        mToExit = true;
    }

    void beginPolling();
    void pausePolling();

    void updateCommsProtocol(std::shared_ptr<comms_Sensoray::CommsMarshaler> commsLink);

    void run();

private:
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
    std::shared_ptr<comms_Sensoray::CommsMarshaler> m_SensorayDevice;

private:
    Timer m_Timeout;
    unsigned int timeout;

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


#endif // SENSORAY_POLL_MACHINE_H
