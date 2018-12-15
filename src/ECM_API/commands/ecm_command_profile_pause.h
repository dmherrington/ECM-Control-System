#ifndef ECM_COMMAND_PROFILE_PAUSE_H
#define ECM_COMMAND_PROFILE_PAUSE_H

#include "ecm_command_abstract_profile_config.h"

class ECMCommand_ProfilePause : public ECMCommand_AbstractProfileConfig
{
public:
    enum class WaitType
    {
        INFINITE,
        TIMED
    };

public:
    ECMCommand_ProfilePause();

    ECMCommand_ProfilePause(const ECMCommand_ProfilePause &copy);

public:
    unsigned int waitTime;
    WaitType durationType;
};

#endif // ECM_COMMAND_PROFILE_PAUSE_H
