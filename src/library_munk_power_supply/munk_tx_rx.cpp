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

bool MunkTXRX::searchForStartingIndex(const QByteArray &array, int &index)
{
    unsigned int size = rxByteArray.size();

    if(size > 4)
    {
        //let us try parsing the data in here
        //first look for the slave address
        for(unsigned int i = 0; i < size; i++)
        {
            if(rxByteArray.at(i) == 01)
            {
                index = i;
                return true;
            }
        }
        //next look for the read or write paramter
        //next look for either an exception code or parameter
        //if exception code
    }
    return false;
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

        QByteArray potentialArray;
        int startingIndex = 0;
        bool found = searchForStartingIndex(rxByteArray, startingIndex);
        if(found)
        {
            rxByteArray.remove(0,startingIndex);
        }

        if(rxByteArray.size() < 5)
            continue; //this should jump the remaining stuff


        //The current state we can find out how much time has passed.
        //If one of the lambda expressions has fired the clock shoud
        //be reset right at the end, thus making this value small and
        //improbable the next function will fire
//        double timeElapsed = mTimer.elapsedMilliseconds();

//        if(timeElapsed > responseTimeout)
//        {
//            currentRetry++;
//        }

        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}


