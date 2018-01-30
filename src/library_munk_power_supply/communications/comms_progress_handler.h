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

    void currentProgress(int &needed, int &complete);

    void receivedAckProgress(const MunkMessageType &type, int &needed, int &complete);

    void clearCurrentProgress();

private:
    std::map<MunkMessageType,bool> progressMap;
};

#endif // COMMS_PROGRESS_HANDLER_H
