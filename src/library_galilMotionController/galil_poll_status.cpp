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
            //these functions will update the actual stored information of the galil unit in the state
            //interface class contained at the callback location
            std::cout<<"This should have executed a request for galil info"<<std::endl;
            // 1: Request the position of the galil unit
            if(m_CB)
            {
                RequestTellPosition requestTP;
                m_CB->cbi_GalilStatusRequestCommand(&requestTP);
                // 2: Request the stop codes
                RequestStopCode requestSC;
                m_CB->cbi_GalilStatusRequestCommand(&requestSC);
                // 3: Request the tell switches
                RequestTellSwitches requestTS;
                m_CB->cbi_GalilStatusRequestCommand(&requestTS);
            }
            m_Timeout.reset();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
    }
}
