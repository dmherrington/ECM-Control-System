#ifndef COMMAND_EXECUTE_TOUCHOFF_H
#define COMMAND_EXECUTE_TOUCHOFF_H

#include "command_execute_profile.h"

/**
\* @file  command_execute_touchoff.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is to control the Galil Motion Controller.
\*
\* @section DESCRIPTION
\*
\*
\*/

ECM_CLASS_FORWARD(CommandExecuteTouchoff);

class CommandExecuteTouchoff : public CommandExecuteProfile
{
public:
    CommandExecuteTouchoff(const MotionProfile::ProfileType &type, const std::string &name, const MotorAxis &axis);

    CommandExecuteTouchoff(const CommandExecuteTouchoff &copy);

    /**
      */
    virtual ~CommandExecuteTouchoff() = default;

public:
    /**
     * @brief getClone
     * @return
     */
    AbstractCommand* getClone() const override;

    /**
     * @brief getClone
     * @param state
     */
    void getClone(AbstractCommand** state) const override;

public:
    void setExecutionAxis(const MotorAxis &axis);

    MotorAxis getExecutionAxis() const;

private:
    MotorAxis executeOnAxis;
};

#endif // COMMAND_EXECUTE_TOUCHOFF_H
