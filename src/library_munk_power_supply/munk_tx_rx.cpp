#include "munk_tx_rx.h"

MunkTXRX::MunkTXRX()
{

}

void MunkTXRX::transmitBytes(const std::vector<QByteArray> &byteVector)
{
    transArray.clear();
    transArray = byteVector;
    //begin transmitting each one of these individually to the munk unit
}

void MunkTXRX::receivedBytes(const QByteArray &array)
{
    m_LambdasToRun.push_back([this,array]{
        rxByteArray.append(array);
        //now parse the existing array to see if it matches the old one
    });
}

void MunkTXRX::clearPreviousTransmit()
{
    prevTxArray.clear();
}

void MunkTXRX::run()
{
    while(true)
    {
        if(mToExit == true) {
            clearPendingTasks();
            clearPreviousTransmit();
            mTimer.stop();
            break;
        }

        this->RunPendingTasks();

        //The current state we can find out how much time has passed.
        //If one of the lambda expressions has fired the clock shoud
        //be reset right at the end, thus making this value small and
        //improbable the next function will fire
        double timeElapsed = mTimer.elapsedMilliseconds();

        if(timeElapsed > responseTimeout)
        {
            currentRetry++;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}


