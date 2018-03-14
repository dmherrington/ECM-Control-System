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
        HOME,
        PROFILE,
        TOUCHOFF
    };

public:
    CommandExecuteProfile(const std::string &name, const ProgramGeneric &program);

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

private:
    std::string getProfileLabel() const;

private:
    std::string profileName;
    ProgramGeneric executeProgram;

};

#endif // COMMAND_EXECUTE_PROFILE_H
