#ifndef ECM_COMMAND_PROFILE_CONFIGURATION_H
#define ECM_COMMAND_PROFILE_CONFIGURATION_H

#include "ecm_command_abstract_profile_config.h"

#include "library_galilMotionController/programs/galil_current_operation.h"
#include "library_galilMotionController/motion_command_touchoff_config.h"

#include "library_munk_power_supply/power_supply_setup_config.h"

#include "library_westinghouse510/command_pump_properties.h"

#include "ecm_command_execution_properties.h"

ECM_CLASS_FORWARD(ECMCommand_ProfileConfiguration);

class ECMCommand_ProfileConfiguration : public ECMCommand_AbstractProfileConfig
{
public:
    ECMCommand_ProfileConfiguration();

    ECMCommand_ProfileConfiguration(const ECMCommand_ProfileConfiguration &copy);

public:
    void writeToJSON(QJsonObject &obj) override;

    void readFromJSON(const QJsonObject &obj) override;

public:
    std::string getProfileName() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ECMCommand_ProfileConfiguration& operator = (const ECMCommand_ProfileConfiguration &rhs)
    {
        ECMCommand_AbstractProfileConfig::operator =(rhs);
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
        if(!ECMCommand_AbstractProfileConfig::operator ==(rhs)){
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
};

#endif // ECM_COMMAND_PROFILE_CONFIGURATION_H
