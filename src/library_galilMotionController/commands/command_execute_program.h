#ifndef COMMAND_EXECUTE_PROGRAM_H
#define COMMAND_EXECUTE_PROGRAM_H

#include "commands/abstract_command.h"

class CommandExecuteProgram : public AbstractCommand
{
public:
    CommandExecuteProgram();

    CommandExecuteProgram(const CommandExecuteProgram &copy);

    /**
      */
    virtual ~CommandExecuteProgram() = default;

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
