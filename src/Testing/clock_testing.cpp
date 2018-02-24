#include "clock_testing.h"

TestTime::TestTime(const int &msTimeout):
   timeout(msTimeout)
{

}

void TestTime::beginPolling()
{
    m_Timeout.start();
    this->start();
}

void TestTime::pausePolling()
{
    m_LambdasToRun.push_back([this]{
        m_Timeout.stop();
        clearPendingTasks();
        mToExit = true;
    });
}


void TestTime::run()
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

        if(timeElapsed >= timeout)
        {
            rigol::EnvironmentTime newTime;
            newTime.CurrentTime(rigol::Devices::SYSTEMCLOCK,newTime);
            std::cout<<"The current time is:"<<std::endl;
            std::cout<<newTime.ToString().toStdString()<<std::endl;
            std::cout<<"The elapsed time seen here is"<<std::to_string(timeElapsed)<<std::endl;
            m_Timeout.reset();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
