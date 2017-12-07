#ifndef COMMAND_EXECUTE_PROGRAM_H
#define COMMAND_EXECUTE_PROGRAM_H

#include "commands/abstract_command.h"

class CommandExecuteProgram : public AbstractCommand
{
public:
    CommandExecuteProgram();

public:
    //!
    //! \brief setScript
    //! \param name
    //!
    void setScript(const std::string &name);

    //!
    //! \brief getScript
    //! \return
    //!
    std::string getScriptName() const;

    //!
    //! \brief clearScriptName
    //!
    void clearScriptName();

public:
    //!
    //! \brief getCommandString
    //! \return
    //!
    virtual std::string getCommandString() const override;

private:
    std::string scriptName = ""; /**< Value of the script location to start */

};

#endif // COMMAND_EXECUTE_PROGRAM_H
