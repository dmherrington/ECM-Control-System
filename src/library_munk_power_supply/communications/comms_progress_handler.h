#ifndef MUNK_COMMS_PROGRESS_HANDLER_H
#define MUNK_COMMS_PROGRESS_HANDLER_H

#include <map>
#include <vector>

#include "data_registers/type_definition.h"

namespace comms_Munk{

class CommsProgressHandler
{
public:
    CommsProgressHandler();

    void transmittingNewSegment(const std::vector<registers_Munk::ParameterType> &msgsRequired);

    void currentProgress(int &complete, int &needed);

    void receivedAckProgress(const registers_Munk::ParameterType &type, int &complete, int &needed);

    void clearCurrentProgress();

private:
    std::map<registers_Munk::ParameterType,bool> progressMap;
};

} //end of namespace comms_Munk


#endif // MUNK_COMMS_PROGRESS_HANDLER_H
