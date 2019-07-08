#include "sensoray_poll_machine.h"

SensorayPollMachine::SensorayPollMachine(const unsigned int &msTimeout ):
    timeout(msTimeout)
{

}

void SensorayPollMachine::updateCommsProtocol(std::shared_ptr<comms_Sensoray::CommsMarshaler> commsLink)
{
    m_SensorayDevice = commsLink;
}

void SensorayPollMachine::beginPolling()
{
    m_Timeout.start();
    this->start();
}


void SensorayPollMachine::pausePolling()
{
    m_LambdasToRun.push_back([this]{
        m_Timeout.stop();
        clearPendingTasks();
        mToExit = true;
    });
}

void SensorayPollMachine::run()
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

            m_SensorayDevice->readSensoaryADC();

            m_Timeout.reset();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
    }
}
