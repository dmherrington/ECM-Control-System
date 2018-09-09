#include "comms_progress_handler.h"


namespace comms_Munk{

CommsProgressHandler::CommsProgressHandler()
{

}


void CommsProgressHandler::transmittingNewSegment(const std::vector<registers_Munk::ParameterType> &msgsRequired)
{
    this->clearCurrentProgress();

    for(int i = 0; i<msgsRequired.size(); i++)
        this->progressMap[msgsRequired.at(i)] = false;
}

void CommsProgressHandler::receivedAckProgress(const registers_Munk::ParameterType &type, int &complete, int &needed)
{
    this->progressMap[type] = true;
    this->currentProgress(complete,needed);
}

void CommsProgressHandler::currentProgress(int &complete, int &needed)
{
    needed = this->progressMap.size();
    std::map<registers_Munk::ParameterType,bool>::iterator it;
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

} //end of namespace comms_Munk

