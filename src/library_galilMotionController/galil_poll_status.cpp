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

void GalilPollState::addRequest(const AbstractRequestPtr request)
{
    m_LambdasToRun.push_back([this,request]{
        std::pair<std::map<common::TupleECMData,AbstractRequestPtr>::iterator,bool> ret;
        ret = requests.insert ( std::pair<common::TupleECMData,AbstractRequestPtr>(request->getTupleDescription(),request));
        if (ret.second==false) {
            requests[request->getTupleDescription()] = request;
        }
    });
}

void GalilPollState::removeRequest(const common::TupleECMData &tuple)
{
    m_LambdasToRun.push_back([this,tuple]
    {
        if(requests.count(tuple) > 0)
            requests.erase(tuple);
    });
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

            // 1: Request the position of the galil unit
            if(m_CB)
            {
//                RequestTellPositionPtr requestTP = std::make_shared<RequestTellPosition>();
//                m_CB->cbi_GalilStatusRequest(requestTP);
                // 2: Request the stop codes
//                RequestStopCodePtr requestSC = std::make_shared<RequestStopCode>();
//                m_CB->cbi_GalilStatusRequest(requestSC);
                // 3: Request the tell switches
                RequestTellSwitchesPtr requestTS = std::make_shared<RequestTellSwitches>();;
                m_CB->cbi_GalilStatusRequest(requestTS);
                // 4: Request the current inputs
                RequestTellInputsPtr requestTI = std::make_shared<RequestTellInputs>();
                m_CB->cbi_GalilStatusRequest(requestTI);

                //Iterate through any remaining requests
                std::map<common::TupleECMData,AbstractRequestPtr>::iterator it;
                for (it=requests.begin(); it!=requests.end(); ++it)
                    m_CB->cbi_GalilStatusRequest(it->second);
            }
            m_Timeout.reset();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
    }
}
