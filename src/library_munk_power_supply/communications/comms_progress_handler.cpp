#include "comms_progress_handler.h"

CommsProgressHandler::CommsProgressHandler()
{

}


void CommsProgressHandler::transmittingNewSegment(const std::vector<MunkMessageType> &msgsRequired)
{
    this->clearCurrentProgress();
    for(int i = 0; i<msgsRequired.size(); i++)
        this->progressMap[msgsRequired.at(i)] = false;
}

void CommsProgressHandler::receivedAckProgress(const MunkMessageType &type, int &needed, int &complete)
{
    this->progressMap[type] = true;
    this->currentProgress(needed,complete);
}

void CommsProgressHandler::currentProgress(int &needed, int &complete)
{
    needed = this->progressMap.size();
    std::map<MunkMessageType,bool>::iterator it;
    complete = 0;

    for(it = this->progressMap.begin(); it != this->progressMap.end(); it++)
    {
        if(it->second)
            complete++;
    }
}

void CommsProgressHandler::clearCurrentProgress()
{
    this->progressMap.clear();
}
