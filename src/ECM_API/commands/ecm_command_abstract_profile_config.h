#ifndef ECM_COMMAND_ABSTRACT_PROFILE_CONFIG_H
#define ECM_COMMAND_ABSTRACT_PROFILE_CONFIG_H

#include "common/class_forward.h"

ECM_CLASS_FORWARD(ECMCommand_AbstractProfileConfig);

class ECMCommand_AbstractProfileConfig
{
public:
    enum class ConfigType
    {
      OPERATION,
      POSITION_MOVE,
      PAUSE,
      UNKNOWN
    };

public:
    ECMCommand_AbstractProfileConfig(const ConfigType &configType)
    {
        this->configType = configType;
    }

    ECMCommand_AbstractProfileConfig(const ECMCommand_AbstractProfileConfig &copy)
    {
        this->configType = copy.configType;
    }

    ConfigType getConfigType() const
    {
        return this->configType;
    }

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ECMCommand_AbstractProfileConfig& operator = (const ECMCommand_AbstractProfileConfig &rhs)
    {
        this->configType = rhs.configType;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const ECMCommand_AbstractProfileConfig &rhs)
    {
        if(this->configType != rhs.configType){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const ECMCommand_AbstractProfileConfig &rhs) {
        return !(*this == rhs);
    }



private:
    ConfigType configType;
};


#endif // ECM_COMMAND_ABSTRACT_PROFILE_CONFIG_H
