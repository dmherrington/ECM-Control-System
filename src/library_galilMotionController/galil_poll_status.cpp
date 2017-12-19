#include "galil_poll_status.h"

GalilPollState::GalilPollState(const int &msTimeout):
    m_CB(nullptr), timeout(msTimeout)
{

}

void GalilPollState::beginPolling()
{
    m_Timeout.start();
    this->start();
}

void GalilPollState::pausePolling()
{
    m_LambdasToRun.push_back([this]{
        m_Timeout.stop();
        clearPendingTasks();
        mToExit = true;
    });
}

void GalilPollState::run()
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
            std::cout<<"This should have executed a request for galil info"<<std::endl;
            // 1: Request the position of the galil unit
            RequestTellPosition requestTP;
            m_CB->cbi_GalilStatusRequestCommand(requestTP.getRequestString());
            // 2: Request the stop codes
            RequestStopCode requestSC;

            // 3: Request the tell switches
            RequestTellSwitches requestTS;

            //4: Update states and call update state transitions

            m_Timeout.reset();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
    }
}
