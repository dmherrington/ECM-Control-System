#ifndef ECM_COMMAND_ABSTRACT_PROFILE_CONFIG_H
#define ECM_COMMAND_ABSTRACT_PROFILE_CONFIG_H

#include "common/class_forward.h"
#include "ecm_command_execution_properties.h"

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
    unsigned int getOperationIndex() const
    {
        return this->operationIndex;
    }

    std::string getOperationName() const
    {
        return this->operationName;
    }

    std::string getProfileName() const
    {
        return this->m_GalilOperation.getProfileName();
    }

    bool shouldHomeBeIndicated() const
    {
        return this->indicateHome;
    }

    bool shouldProfileExecute() const
    {
        return this->shouldExecute;
    }

    bool hasProfileCompleted() const
    {
        return this->execProperties.hasProfileBeenCompleted();
    }

    void setOperationIndex(const unsigned int &index)
    {
        this->operationIndex = index;
    }

    void setOperationName(const std::string &name)
    {
        this->operationName = name;
    }

    void setIndicateHomeAutomatically(const bool &homeExecute)
    {
        this->indicateHome = homeExecute;
    }

    void setProfileExecution(const bool &varExecute)
    {
        this->shouldExecute = varExecute;
    }

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ECMCommand_AbstractProfileConfig& operator = (const ECMCommand_AbstractProfileConfig &rhs)
    {
        this->configType = rhs.configType;
        this->operationIndex = rhs.operationIndex;
        this->operationName = rhs.operationName;
        this->indicateHome = rhs.indicateHome;
        this->shouldExecute = rhs.shouldExecute;

        this->execProperties = rhs.execProperties;

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
        if(this->operationIndex != rhs.operationIndex){
            return false;
        }
        if(this->operationName != rhs.operationName){
            return false;
        }
        if(this->indicateHome != rhs.indicateHome){
            return false;
        }
        if(this->shouldExecute != rhs.shouldExecute){
            return false;
        }
        if(this->execProperties != rhs.execProperties)
        {
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



protected:
    ConfigType configType;
    unsigned int operationIndex = 0;
    std::string operationName = "";
    bool indicateHome = false;
    bool shouldExecute = false;

public:
    ECMCommand_ExecutionProperties execProperties;
};


#endif // ECM_COMMAND_ABSTRACT_PROFILE_CONFIG_H
