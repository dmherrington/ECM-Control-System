#ifndef ECM_COMMAND_EXECUTION_PROPERTIES_H
#define ECM_COMMAND_EXECUTION_PROPERTIES_H

#include "common/environment_time.h"
#include "common/class_forward.h"

#include "data/profiles/profile_state_machining.h"

ECM_CLASS_FORWARD(ECMCommand_ExecutionProperties);

using namespace common;

class ExecutionTimeProperties
{
public:
    ExecutionTimeProperties() = default;

    ExecutionTimeProperties(const ExecutionTimeProperties &copy);

public:
    void establishStartTime();
    void establishEndTime();
    void setStartTime(const EnvironmentTime &start);
    void setEndTime(const EnvironmentTime &end);

public:
    EnvironmentTime getStartTime() const;
    EnvironmentTime getEndTime() const;
    double getElapsedTime() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ExecutionTimeProperties& operator = (const ExecutionTimeProperties &rhs)
    {
        this->m_startTime = rhs.m_startTime;
        this->m_endTime = rhs.m_endTime;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const ExecutionTimeProperties &rhs)
    {
        if(this->m_startTime != rhs.m_startTime){
            return false;
        }
        if(this->m_endTime != rhs.m_endTime){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const ExecutionTimeProperties &rhs) {
        return !(*this == rhs);
    }

protected:
    EnvironmentTime m_startTime;
    EnvironmentTime m_endTime;
};

class ECMCommand_ExecutionProperties : public ExecutionTimeProperties
{
public:
    ECMCommand_ExecutionProperties();

    ECMCommand_ExecutionProperties(const ECMCommand_ExecutionProperties &copy);

public:
    void initializeExecution();
    void completeExecution();
    void setHasProfileExecuted(const bool &executed);
    void setProfileCode(const ProfileState_Machining::MACHININGProfileCodes &code);

public:
    bool hasProfileBeenExecuted() const;
    bool hasProfileBeenCompleted() const;
    ProfileState_Machining::MACHININGProfileCodes getProfileCode() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ECMCommand_ExecutionProperties& operator = (const ECMCommand_ExecutionProperties &rhs)
    {
        ExecutionTimeProperties::operator =(rhs);
        this->executed = rhs.executed;
        this->profileCode = rhs.profileCode;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const ECMCommand_ExecutionProperties &rhs)
    {
        if(!ExecutionTimeProperties::operator ==(rhs)){
            return false;
        }
        if(this->executed != rhs.executed){
            return false;
        }
        if(this->profileCode != rhs.profileCode){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const ECMCommand_ExecutionProperties &rhs) {
        return !(*this == rhs);
    }

private:
    bool executed = false;
    ProfileState_Machining::MACHININGProfileCodes profileCode = ProfileState_Machining::MACHININGProfileCodes::INCOMPLETE;
};

#endif // ECM_COMMAND_EXECUTION_PROPERTIES_H
