#ifndef SPII_POLL_STATUS_H
#define SPII_POLL_STATUS_H

#include <map>

#include <iostream>
#include <QDate>

#include "ACSC.h"

#include "common/environment_time.h"
#include "common/publisher.h"
#include "common/threadmanager.h"
#include "common/timer.h"

#include "requests/request_components.h"

#include "communications/comms_marshaler.h"

class SPIIPollingEvents_Interface
{

public:
    SPIIPollingEvents_Interface() = default;
    virtual ~SPIIPollingEvents_Interface() = default;

public:
    virtual void SPIIPolling_PositionUpdate(const std::vector<Status_PositionPerAxis> &position) = 0;
    virtual void SPIIPolling_AxisUpdate(const std::vector<Status_PerAxis> &axis) = 0;
    virtual void SPIIPolling_AxisSafetyUpdate(const std::vector<Status_AxisSafety> &axis) = 0;
    virtual void SPIIPolling_MotorUpdate(const std::vector<Status_MotorPerAxis> &motor) = 0;
    virtual void SPIIPolling_MotorFaultUpdate(const std::vector<Status_MotorAxisFault> &motor) = 0;
    virtual void SPIIPolling_SystemFaultUpdate(const Status_SystemFault &status) = 0;
    virtual void SPIIPolling_VariableUpdate(const std::vector<Status_VariableValue> &variable) = 0;
    virtual void SPIIPolling_UnsolicitedMsgs(const std::vector<std::string> &msgs) = 0;

};

class SPIIPollMachine : public Publisher<SPIIPollingEvents_Interface>, public Thread
{
public:
    SPIIPollMachine(const unsigned int &msTimeout = 50);

    ~SPIIPollMachine() {
        std::cout << "Destructor on the galil timeout state machine" << std::endl;
        mToExit = true;
    }

    void beginPolling();
    void pausePolling();

    void updateCommsProtocol(std::shared_ptr<Comms::CommsMarshaler> commsLink);

    void addRequest(const AbstractRequestPtr request, const int &period = 100);
    void removeRequest(const common::TupleECMData &tuple);

    void run();

private:
    void processRequest(AbstractRequestPtr request);

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
    std::shared_ptr<Comms::CommsMarshaler> m_SPIIDevice;

private:
    typedef pair<double, double> pollingTimeout;

private:
    Timer m_Timeout;
    unsigned int timeout;

private:
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

#endif // SPII_POLL_STATUS_H
