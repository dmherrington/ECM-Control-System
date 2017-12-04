#include "galil_state_machine.h"

GalilSM::GalilSM(const int &msTimeout):
    m_CB(nullptr), timeout(msTimeout)
{
    m_Timeout.start();
}


void GalilSM::run()
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
        //If one of the lambda expressions has fired the clock shoud
        //be reset right at the end, thus making this value small and
        //improbable the next function will fire
        double timeElapsed = m_Timeout.elapsedMilliseconds();

        if(timeElapsed > timeout)
        {
            //this means we should request the state of all the standard IO/Errors/Pos of the galil unit

        }

        std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
    }
}
