#ifndef COMMAND_UPLOAD_PROGRAM_H
#define COMMAND_UPLOAD_PROGRAM_H

#include "../class_forward.h"
#include "../axis_definitions.h"

#include "abstract_command.h"

/**
\* @file  command_upload_program.h
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
    virtual AbstractCommand* getClone() const override;

    /**
     * @brief getClone
     * @param state
     */
    virtual void getClone(AbstractCommand** state) const override;

public:
    void setCurrentScript(const std::string &text);

    std::string getCurrentScript() const;

public:
    //!
    //! \brief getCommandString
    //! \return
    //!
    virtual std::string getCommandString() const override;


public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    CommandUploadProgram& operator = (const CommandUploadProgram &rhs)
    {
        AbstractCommand::operator =(rhs);
        this->programText = rhs.programText;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const CommandUploadProgram &rhs)
    {
        if(!AbstractCommand::operator ==(rhs)){
            return false;
        }
        if(this->programText != rhs.programText){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const CommandUploadProgram &rhs) {
        return !(*this == rhs);
    }

private:
    std::string programText = "";
};

#endif // COMMAND_UPLOAD_PROGRAM_H
