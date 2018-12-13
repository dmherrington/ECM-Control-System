#ifndef ECM_COMMAND_ABSTRACT_PROFILE_CONFIG_H
#define ECM_COMMAND_ABSTRACT_PROFILE_CONFIG_H

#include "common/class_forward.h"

ECM_CLASS_FORWARD(ECMCommand_AbstractProfileConfig);

class ECMCommand_AbstractProfileConfig
{
public:
    enum class Type
    {
      OPERATION,
      POSITION_MOVE,
      PAUSE
    };

public:
    ECMCommand_AbstractProfileConfig()
    {

    }

private:
    Type configType;
};


#endif // ECM_COMMAND_ABSTRACT_PROFILE_CONFIG_H
