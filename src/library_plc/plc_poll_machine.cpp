#include "plc_poll_machine.h"

PLCPollMachine::PLCPollMachine(const unsigned int &msTimeout ):
    timeout(msTimeout)
{

}


void PLCPollMachine::beginPolling()
{
    m_Timeout.start();
    this->start();
}

void PLCPollMachine::addRequestToQueue(const PLC::AbstractRequestPtr request, const int &period)
{
    std::pair<std::map<common::TupleECMData,PLC::AbstractRequestPtr>::iterator,bool> ret;
    auto dataPair = std::make_pair(0.0,period);
    requestMap[request->getTupleDescription()] = request;
    timeoutMap[request->getTupleDescription()] = dataPair;

    std::map<common::TupleECMData,pollingTimeout>::iterator it = timeoutMap.begin();
    int currentTimeout = static_cast<int>(it->second.second);
    std::advance(it,1);
    for (; it!=timeoutMap.end(); ++it)
    {
        currentTimeout = greatestCommonDenominator(currentTimeout, it->second.second);
    }
    timeout = static_cast<unsigned int>(currentTimeout);

}

void PLCPollMachine::addRequest(const PLC::AbstractRequestPtr request, const int &period)
{
    if(isThreadActive())
    {
        m_LambdasToRun.push_back([this,request,period]{
            addRequestToQueue(request,period);
        });
    }
    else
    {
        addRequestToQueue(request,period);
    }
}

void PLCPollMachine::pausePolling()
{
    m_LambdasToRun.push_back([this]{
        m_Timeout.stop();
        clearPendingTasks();
        mToExit = true;
    });
}

void PLCPollMachine::run()
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
        unsigned int timeElapsed = static_cast<unsigned int>(m_Timeout.elapsedMilliseconds());
        if(timeElapsed >= timeout)
        {
            //this means we should request the state of all the standard IO/Errors/Pos of the galil unit
            //these functions will update the actual stored information of the galil unit in the state
            //interface class contained at the callback location

            //Iterate through the requests
            std::map<common::TupleECMData,pollingTimeout>::iterator it;
            for (it=timeoutMap.begin(); it!=timeoutMap.end(); ++it)
            {
                it->second.first += timeElapsed;
                if(it->second.first >= it->second.second)
                {
                    //we have therefore timed out
                    //1. Let us reset the current timer associated with this request
                    it->second.first = 0;
                    requestMap.at(it->first)->updateTime();
                }
            }
            m_Timeout.reset();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
    }
}

