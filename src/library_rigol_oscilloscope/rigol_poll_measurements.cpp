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
    m_LambdasToRun.push_back([this]{
        m_Timeout.stop();
        clearPendingTasks();
        mToExit = true;
    });
}

void RigolPollMeasurement::addPollingMeasurement(const rigol::commands::AbstractMeasureCommandPtr command)
{
    m_LambdasToRun.push_back([this,command]{
        this->currentRequests[command->getCommandKey()] = command;
    });
}

void RigolPollMeasurement::removePollingMeasurement(const std::string &key)
{
    m_LambdasToRun.push_back([this,key]{
        this->currentRequests.erase(key);
    });
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

        if(timeElapsed > timeout)
        {
            //this means we should request measurements from the rigol that are in our queue
            if(m_CB)
            {
                std::map<std::string, rigol::commands::AbstractMeasureCommandPtr>::iterator it;
                for (it = currentRequests.begin(); it != currentRequests.end(); it++)
                {
                    m_CB->cbi_RigolMeasurementRequests(it->second);
                    //std::cout << it->first << ' ' << it->second << '\n';
                }
            }
            m_Timeout.reset();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
    }
}
