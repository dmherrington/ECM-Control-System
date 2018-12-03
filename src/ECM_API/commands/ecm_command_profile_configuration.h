#ifndef ECM_COMMAND_PROFILE_CONFIGURATION_H
#define ECM_COMMAND_PROFILE_CONFIGURATION_H

#include "common/class_forward.h"

#include "library_galilMotionController/programs/galil_current_operation.h"
#include "library_galilMotionController/motion_command_touchoff_config.h"

#include "library_munk_power_supply/power_supply_setup_config.h"

#include "library_westinghouse510/command_pump_properties.h"

#include "ecm_command_execution_properties.h"

ECM_CLASS_FORWARD(ECMCommand_ProfileConfiguration);

class ECMCommand_ProfileConfiguration
{
public:
    ECMCommand_ProfileConfiguration();

    ECMCommand_ProfileConfiguration(const ECMCommand_ProfileConfiguration &copy);

public:
    void writeToJSON(QJsonObject &obj);

    void readFromJSON(const QJsonObject &obj);

public:
    unsigned int getOperationIndex() const;

    std::string getOperationName() const;

    std::string getProfileName() const;


    bool shouldHomeBeIndicated() const;

    bool shouldProfileExecute() const;

    bool hasProfileCompleted() const;

public:
    void setOperationIndex(const unsigned int &index);

    void setOperationName(const std::string &name);

    void setHomeNeedsToBeIndicated(const bool &homeExecute);

    void setProfileExecution(const bool &varExecute);

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ECMCommand_ProfileConfiguration& operator = (const ECMCommand_ProfileConfiguration &rhs)
    {
        this->operationIndex = rhs.operationIndex;
        this->operationName = rhs.operationName;
        this->indicateHome = rhs.indicateHome;
        this->shouldExecute = rhs.shouldExecute;

        this->execProperties = rhs.execProperties;

        this->m_GalilOperation = rhs.m_GalilOperation;
        this->m_Touchoff = rhs.m_Touchoff;
        this->m_ConfigPowerSupply = rhs.m_ConfigPowerSupply;
        this->m_PumpParameters = rhs.m_PumpParameters;

        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const ECMCommand_ProfileConfiguration &rhs)
    {
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
        if(this->m_GalilOperation != rhs.m_GalilOperation){
            return false;
        }
        if(this->m_Touchoff != rhs.m_Touchoff){
            return false;
        }
        if(this->m_ConfigPowerSupply != rhs.m_ConfigPowerSupply){
            return false;
        }
        if(this->m_PumpParameters != rhs.m_PumpParameters){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const ECMCommand_ProfileConfiguration &rhs) {
        return !(*this == rhs);
    }

public:

    GalilCurrentOperation m_GalilOperation;

    MotionCommand_TouchoffConfig m_Touchoff;

    PowerSupply_SetupConfig m_ConfigPowerSupply;

    Command_PumpProperties m_PumpParameters;

private:
    unsigned int operationIndex = 0;
    std::string operationName = "";
    bool indicateHome = false;
    bool shouldExecute = false;

public:
    ECMCommand_ExecutionProperties execProperties;
};

#endif // ECM_COMMAND_PROFILE_CONFIGURATION_H
