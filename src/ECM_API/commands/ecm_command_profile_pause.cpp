#include "ecm_command_profile_pause.h"

ECMCommand_ProfilePause::ECMCommand_ProfilePause():
    ECMCommand_AbstractProfileConfig(ConfigType::PAUSE)
{

}

ECMCommand_ProfilePause::ECMCommand_ProfilePause(const ECMCommand_ProfilePause &copy):
    ECMCommand_AbstractProfileConfig(copy)
{

}
