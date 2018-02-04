#include "rigol_poll_measurements.h"

RigolPollMeasurement::RigolPollMeasurement(const int &msTimeout):
    m_CB(nullptr), timeout(msTimeout)
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

void RigolPollMeasurement::addPollingMeasurement(const rigol::commands::AbstractMeasureCommand *command)
{

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
            //this means we should request the state of all the standard IO/Errors/Pos of the galil unit
            //these functions will update the actual stored information of the galil unit in the state
            //interface class contained at the callback location

            if(m_CB)
            {

            }
            m_Timeout.reset();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
    }
}
