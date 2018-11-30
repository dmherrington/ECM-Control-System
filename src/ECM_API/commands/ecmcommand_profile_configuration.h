#ifndef ECMCOMMAND_PROFILE_CONFIGURATION_H
#define ECMCOMMAND_PROFILE_CONFIGURATION_H

#include "common/class_forward.h"

#include "library_galilMotionController/programs/galil_current_operation.h"
#include "library_galilMotionController/motion_command_touchoff_config.h"

#include "library_munk_power_supply/data_registers/segment_time_detailed.h"
#include "library_munk_power_supply/data_registers/register_pulse_mode.h"

#include "library_westinghouse510/command_pump_properties.h"

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
    bool shouldProfileExecute() const;

    void setProfileExecution(const bool &varExecute);

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ECMCommand_ProfileConfiguration& operator = (const ECMCommand_ProfileConfiguration &rhs)
    {
        this->m_GalilOperation = rhs.m_GalilOperation;
        this->m_Touchoff = rhs.m_Touchoff;
        this->m_MunkSegment = rhs.m_MunkSegment;
        this->m_MunkPulseMode = rhs.m_MunkPulseMode;
        this->m_PumpParameters = rhs.m_PumpParameters;

        this->operationIndex = rhs.operationIndex;
        this->operationName = rhs.operationName;
        this->execute = rhs.execute;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const ECMCommand_ProfileConfiguration &rhs)
    {
        if(this->m_GalilOperation != rhs.m_GalilOperation){
            return false;
        }
        if(this->m_Touchoff != rhs.m_Touchoff){
            return false;
        }
        if(this->m_MunkSegment != rhs.m_MunkSegment){
            return false;
        }
        if(this->m_MunkPulseMode != rhs.m_MunkPulseMode){
            return false;
        }
        if(this->m_PumpParameters != rhs.m_PumpParameters){
            return false;
        }
        if(this->operationIndex != rhs.operationIndex){
            return false;
        }
        if(this->operationName != rhs.operationName){
            return false;
        }
        if(this->execute != rhs.execute){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const GalilCurrentOperation &rhs) {
        return !(*this == rhs);
    }

public:

    GalilCurrentOperation m_GalilOperation;

    MotionCommand_TouchoffConfig m_Touchoff;

    registers_Munk::SegmentTimeDetailed m_MunkSegment;

    registers_Munk::Register_PulseMode m_MunkPulseMode;

    Command_PumpProperties m_PumpParameters;

private:
    unsigned int operationIndex = 0;
    std::string operationName = "";
    bool execute = false;
};

#endif // ECMCOMMAND_PROFILE_CONFIGURATION_H
