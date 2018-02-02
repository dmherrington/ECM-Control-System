#ifndef COMMS_PROGRESS_HANDLER_H
#define COMMS_PROGRESS_HANDLER_H

#include <map>
#include <vector>

enum class MunkMessageType
{
    FWDVolt,
    REVVolt,
    FWDCur,
    REVCur,
    SEGTime,
    Mem
};

class CommsProgressHandler
{
public:
    CommsProgressHandler();

    void transmittingNewSegment(const std::vector<MunkMessageType> &msgsRequired);

    void currentProgress(int &complete, int &needed);

    void receivedAckProgress(const MunkMessageType &type, int &complete, int &needed);

    void clearCurrentProgress();

private:
    std::map<MunkMessageType,bool> progressMap;
};

#endif // COMMS_PROGRESS_HANDLER_H
