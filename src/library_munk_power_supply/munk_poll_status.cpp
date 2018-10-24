#include "munk_poll_status.h"

//MunkPollStatus::MunkPollStatus(const int &msTimeout):
//    m_CB(nullptr), timeout(msTimeout)
//{

//}

//void MunkPollStatus::beginPolling()
//{
//    m_Timeout.start();
//    this->start();
//}

//void MunkPollStatus::pausePolling()
//{
//    m_LambdasToRun.push_back([this]{
//        m_Timeout.stop();
//        clearPendingTasks();
//        mToExit = true;
//    });
//}

//void MunkPollStatus::run()
//{
//    while(true)
//    {
//        if(mToExit == true) {
//            clearPendingTasks();
//            m_Timeout.stop();
//            break;
//        }

//        this->RunPendingTasks();

//        //The current state we can find out how much time has passed.
//        //If one of the lambda expressions has fired the clock should
//        //be reset right at the end, thus making this value small and
//        //improbable the next function will fire
//        double timeElapsed = m_Timeout.elapsedMilliseconds();

//        if(timeElapsed > timeout)
//        {
//            //this means we should request the state of anything we desire from the munk
//            if(m_CB)
//            {
//                registers_Munk::RegisterFaultState requestRegister1(data_Munk::FaultRegisterType::FAULT_REGISTER_1);
//                requestRegister1.setSlaveAddress(01);
//                registers_Munk::RegisterFaultState requestRegister2(data_Munk::FaultRegisterType::FAULT_REGISTER_2);
//                requestRegister2.setSlaveAddress(01);
//                registers_Munk::RegisterFaultState requestRegister3(data_Munk::FaultRegisterType::FAULT_REGISTER_3);
//                requestRegister3.setSlaveAddress(01);

//                m_CB->cbi_MunkFaultStateRequest(requestRegister1);
//                m_CB->cbi_MunkFaultStateRequest(requestRegister2);
//                m_CB->cbi_MunkFaultStateRequest(requestRegister3);
//            }
//            m_Timeout.reset();
//        }

//        std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
//    }
//}


MunkPollStatus::MunkPollStatus(const int &msTimeout):
    m_CB(nullptr), timeout(msTimeout)
{

}

void MunkPollStatus::beginPolling()
{
    m_Timeout.start();
    this->start();
}

void MunkPollStatus::addRequestToQueue(const registers_Munk::AbstractParameterPtr request, const int &period)
{
    std::pair<std::map<registers_Munk::ParameterType,registers_Munk::AbstractParameterPtr>::iterator,bool> ret;
    auto dataPair = std::make_pair(0.0,period);
    requestMap[request->getParameterType()] = request;
    timeoutMap[request->getParameterType()] = dataPair;

    std::map<registers_Munk::ParameterType,pollingTimeout>::iterator it = timeoutMap.begin();
    int currentTimeout = it->second.second;
    std::advance(it,1);
    for (; it!=timeoutMap.end(); ++it)
    {
        currentTimeout = greatestCommonDenominator(currentTimeout, it->second.second);
    }
    timeout = currentTimeout;

}

void MunkPollStatus::addRequest(const registers_Munk::AbstractParameterPtr request, const int &period)
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

void MunkPollStatus::removeRequest(const registers_Munk::ParameterType &registerType)
{
    if(isThreadActive())
    {
        m_LambdasToRun.push_back([this,registerType]
        {
            if(requestMap.count(registerType) > 0)
            {
                requestMap.erase(registerType);
                timeoutMap.erase(registerType);
            }
        });
    }
    else
    {
        if(requestMap.count(registerType) > 0)
        {
            requestMap.erase(registerType);
            timeoutMap.erase(registerType);
        }
    }
}

void MunkPollStatus::pausePolling()
{
    m_LambdasToRun.push_back([this]{
        m_Timeout.stop();
        clearPendingTasks();
        mToExit = true;
    });
}

void MunkPollStatus::run()
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
        unsigned int timeElapsed = m_Timeout.elapsedMilliseconds();
        if(timeElapsed >= timeout)
        {
            //this means we should request the state of all the standard IO/Errors/Pos of the galil unit
            //these functions will update the actual stored information of the galil unit in the state
            //interface class contained at the callback location

            if(m_CB)
            {
                //Iterate through the requests
                std::map<registers_Munk::ParameterType,pollingTimeout>::iterator it;
                for (it=timeoutMap.begin(); it!=timeoutMap.end(); ++it)
                {
                    it->second.first += timeElapsed;
                    if(it->second.first >= it->second.second)
                    {
                        //we have therefore timed out
                        //1. Let us reset the current timer associated with this request
                        it->second.first = 0;
                        requestMap.at(it->first)->updateTime();
                        //Check the request
                        if(it->first == registers_Munk::ParameterType::FAULT_STATE)
                        {
                            registers_Munk::RegisterFaultState requestRegister1(data_Munk::FaultRegisterType::FAULT_REGISTER_1);
                            requestRegister1.setSlaveAddress(01);
                            registers_Munk::RegisterFaultState requestRegister2(data_Munk::FaultRegisterType::FAULT_REGISTER_2);
                            requestRegister2.setSlaveAddress(01);
                            registers_Munk::RegisterFaultState requestRegister3(data_Munk::FaultRegisterType::FAULT_REGISTER_3);
                            requestRegister3.setSlaveAddress(01);

                            m_CB->cbi_MunkFaultStateRequest(requestRegister1);
                            m_CB->cbi_MunkFaultStateRequest(requestRegister2);
                            m_CB->cbi_MunkFaultStateRequest(requestRegister3);
                        }
                    }
                }
            }
            m_Timeout.reset();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
    }
}

