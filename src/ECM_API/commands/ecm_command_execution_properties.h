#ifndef ECM_COMMAND_EXECUTION_PROPERTIES_H
#define ECM_COMMAND_EXECUTION_PROPERTIES_H


#include "common/environment_time.h"
#include "common/class_forward.h"

#include "data/profiles/profile_state_machining.h"

ECM_CLASS_FORWARD(ECMCommand_ExecutionProperties);

using namespace common;

class ECMCommand_ExecutionProperties
{
public:
    ECMCommand_ExecutionProperties();

    ECMCommand_ExecutionProperties(const ECMCommand_ExecutionProperties &copy);

public:
    void initializeExecution();
    void completeExecution();
    void establishStartTime();
    void establishEndTime();
    void setHasProfileExecuted(const bool &executed);
    void setHasProfileBeenCompleted(const bool &completed);
    void setStartTime(const EnvironmentTime &start);
    void setEndTime(const EnvironmentTime &end);
    void setProfileCode(const ProfileState_Machining::MACHININGProfileCodes &code);

public:
    bool hasProfileBeenExecuted() const;
    bool hasProfileBeenCompleted() const;
    EnvironmentTime getStartTime() const;
    EnvironmentTime getEndTime() const;
    double getElapsedTime();
    ProfileState_Machining::MACHININGProfileCodes getProfileCode() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ECMCommand_ExecutionProperties& operator = (const ECMCommand_ExecutionProperties &rhs)
    {
        this->executed = rhs.executed;
        this->completed = rhs.completed;
        this->m_startTime = rhs.m_startTime;
        this->m_endTime = rhs.m_endTime;
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
        if(this->executed != rhs.executed){
            return false;
        }
        if(this->completed != rhs.completed){
            return false;
        }
        if(this->m_startTime != rhs.m_startTime){
            return false;
        }
        if(this->m_endTime != rhs.m_endTime){
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
    bool completed = false;
    EnvironmentTime m_startTime;
    EnvironmentTime m_endTime;

    ProfileState_Machining::MACHININGProfileCodes profileCode;
};

#endif // ECM_COMMAND_EXECUTION_PROPERTIES_H
