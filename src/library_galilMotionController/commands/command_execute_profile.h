#ifndef COMMAND_EXECUTE_PROFILE_H
#define COMMAND_EXECUTE_PROFILE_H

#include "common/class_forward.h"
#include "commands/abstract_command.h"

#include "programs/program_generic.h"

ECM_CLASS_FORWARD(CommandExecuteProfile);

class CommandExecuteProfile : public AbstractCommand
{
public:
    enum class ProfileType
    {
        HOMING,
        TOUCHOFF,
        PROFILE
    };

public:
    CommandExecuteProfile(const ProfileType &type, const std::string &name);

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
    ProfileType getProfileType() const;

    //!
    //! \brief getProfileLabel
    //! \return
    //!
    std::string getProfileName() const;

private:
    ProfileType profileType;
    std::string profileName;
};

#endif // COMMAND_EXECUTE_PROFILE_H
