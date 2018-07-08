#include "rigol_poll_measurements.h"

RigolPollMeasurement::RigolPollMeasurement(const int &msTimeout):
   timeout(msTimeout), m_CB(nullptr)
{

}

void RigolPollMeasurement::beginPolling()
{
    m_Timeout.start();
    this->start();
}

void RigolPollMeasurement::pausePolling()
{
    if(isThreadActive())
        m_LambdasToRun.push_back([this]{
            m_Timeout.stop();
            clearPendingTasks();
            mToExit = true;
        });
}

void RigolPollMeasurement::addPollingMeasurement(const commands_Rigol::MeasureCommand_Item &command)
{
    if(isThreadActive())
        m_LambdasToRun.push_back([this,command]{
            this->measurementQueue.insertIntoQueue(command);
        });
    else
        this->measurementQueue.insertIntoQueue(command);
}

void RigolPollMeasurement::removePollingMeasurement(const std::string &key)
{
    if(isThreadActive())
        m_LambdasToRun.push_back([this,key]{
            this->measurementQueue.removeFromQueue(key);
        });
    else
        this->measurementQueue.removeFromQueue(key);
}

void RigolPollMeasurement::clearQueue()
{
    if(isThreadActive())
        m_LambdasToRun.push_back([this]{
            this->measurementQueue.clearQueue();
        });
    else
        this->measurementQueue.clearQueue();
}

commands_Rigol::RigolMeasurementQueue RigolPollMeasurement::getCurrentPollingMeasurements() const
{
    return this->measurementQueue;
}


void RigolPollMeasurement::run()
{
    while(true)
    {
        if(mToExit == true) {
            clearPendingTasks();
            m_Timeout.stop();
            break;
        }

        this->RunPendingTasks();

        //The current state we can find out how much time has passed.
        //If one of the lambda expressions has fired the clock should
        //be reset right at the end, thus making this value small and
        //improbable the next function will fire
        double timeElapsed = m_Timeout.elapsedMilliseconds();

        if(timeElapsed >= timeout)
        {
            //this means we should request measurements from the rigol that are in our queue
            if(m_CB)
            {
                std::vector<commands_Rigol::MeasureCommand_Item> vec = this->measurementQueue.getMeasurementItems();
                for (unsigned int i = 0; i < vec.size(); i++)
                {
                    m_CB->cbi_RigolMeasurementRequests(vec.at(i));
                }
            }
            m_Timeout.reset();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
    }
}
