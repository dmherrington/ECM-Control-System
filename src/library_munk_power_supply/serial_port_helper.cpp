#include "serial_port_helper.h"

SerialPortHelper::SerialPortHelper()
{

}


void SerialPortHelper::transmitParameters(const std::vector<DataParameter::AbstractParameter*> &byteVector)
{
    transArray.clear();
    transArray = byteVector;
    if(transArray.size() > 0)
    {
        emit transmitByteArray(transArray[0]->getFullMessage());
    }

    mTimer.start(); //this initializes when we should reattempt transmitting on the timeout
    this->start(); //this starts the thread if it already isnt currently running

    //begin transmitting each one of these individually to the munk unit
}

void SerialPortHelper::receivedBytes(const QByteArray &array)
{
    m_LambdasToRun.push_back([this,array]{
        //this function is pushed into the lambda expression to be evaluated once the
        //timer on the thread expires
        rxByteArray.append(array);
        qDebug()<<rxByteArray.toHex();
    });
}

bool SerialPortHelper::searchForStartingIndex(const QByteArray &array, int &index)
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

void SerialPortHelper::run()
{
    while(true)
    {
        if(mToExit == true) {
            clearPendingTasks();
            mTimer.stop();
            break;
        }

        this->RunPendingTasks();

        int prevIndex = rxByteArray.indexOf(transArray[0]->getFullExpectedResonse());
        //let us check our buffer to see if it matches what we sent
        if(prevIndex >= 0)
        {
            std::cout<<"I have found the expected message"<<std::endl;
            rxByteArray.remove(prevIndex,transArray[0]->getFullExpectedResonse().size());
            transArray.erase(transArray.begin());
            if(transArray.size() > 0)
            {
                emit transmitByteArray(transArray[0]->getFullMessage());
            }
        }

//        QByteArray potentialArray;
//        int startingIndex = 0;
//        bool found = searchForStartingIndex(rxByteArray, startingIndex);
//        if(found)
//        {
//            rxByteArray.remove(0,startingIndex);
//        }

//        if(rxByteArray.size() < 5)
//            continue; //this should jump the remaining stuff


        //The current state we can find out how much time has passed.
        //If one of the lambda expressions has fired the clock shoud
        //be reset right at the end, thus making this value small and
        //improbable the next function will fire
//        double timeElapsed = mTimer.elapsedMilliseconds();

//        if(timeElapsed > responseTimeout)
//        {
//            currentRetry++;
//        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}


