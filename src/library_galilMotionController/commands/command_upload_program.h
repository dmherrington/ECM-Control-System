#ifndef COMMAND_UPLOAD_PROGRAM_H
#define COMMAND_UPLOAD_PROGRAM_H

#include "common/class_forward.h"
#include "commands/abstract_command.h"
#include "programs/program_generic.h"

ECM_CLASS_FORWARD(CommandUploadProgram);
class CommandUploadProgram : public AbstractCommand
{
public:
    CommandUploadProgram();

    CommandUploadProgram(const CommandUploadProgram &copy);

    /**
      */
    virtual ~CommandUploadProgram() = default;

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
    void setProgram(const ProgramGeneric &desiredProgram);

    ProgramGeneric getProgram() const;
public:
    //!
    //! \brief getCommandString
    //! \return
    //!
    virtual std::string getCommandString() const override;

private:
    ProgramGeneric program;
};

#endif // COMMAND_UPLOAD_PROGRAM_H
