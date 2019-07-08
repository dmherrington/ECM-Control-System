#ifndef COMMAND_EXECUTE_PROFILE_H
#define COMMAND_EXECUTE_PROFILE_H

#include "../class_forward.h"
#include "../axis_definitions.h"
#include "../motion_profile.h"

#include "abstract_command.h"

/**
\* @file  command_jog.h
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

ECM_CLASS_FORWARD(CommandExecuteProfile);

class CommandExecuteProfile : public AbstractCommand
{
public:
    CommandExecuteProfile(const MotionProfile::ProfileType &type, const std::string &name);

    CommandExecuteProfile(const CommandExecuteProfile &copy);

    /**
      */
    virtual ~CommandExecuteProfile() = default;

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
    //!
    //! \brief getCommandString
    //! \return
    //!
    std::string getCommandString() const override;

    //!
    //! \brief getProfileLabel
    //! \return
    //!
    MotionProfile::ProfileType getProfileType() const;

    //!
    //! \brief getProfileLabel
    //! \return
    //!
    std::string getProfileName() const;

private:
    MotionProfile::ProfileType profileType;
    std::string profileName;
};

#endif // COMMAND_EXECUTE_PROFILE_H
