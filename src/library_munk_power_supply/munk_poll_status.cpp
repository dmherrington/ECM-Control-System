#include "munk_poll_status.h"

MunkPollStatus::MunkPollStatus(const int &msTimeout):
    m_CB(nullptr), timeout(msTimeout)
{

}

void MunkPollStatus::beginPolling()
{
    m_Timeout.start();
    this->start();
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
        double timeElapsed = m_Timeout.elapsedMilliseconds();

        if(timeElapsed > timeout)
        {
            //this means we should request the state of anything we desire from the munk
            if(m_CB)
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
            m_Timeout.reset();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
    }
}
