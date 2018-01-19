#ifndef COMMAND_DOWNLOAD_PROGRAM_H
#define COMMAND_DOWNLOAD_PROGRAM_H

#include "common/class_forward.h"
#include "commands/abstract_command.h"

ECM_CLASS_FORWARD(CommandDownloadProgram);
class CommandDownloadProgram : public AbstractCommand
{
public:
    CommandDownloadProgram();

    CommandDownloadProgram(const CommandDownloadProgram &copy);

    /**
      */
    virtual ~CommandDownloadProgram() = default;

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

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    CommandDownloadProgram& operator = (const CommandDownloadProgram &rhs)
    {
        AbstractCommand::operator =(rhs);
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const CommandDownloadProgram &rhs)
    {
        if(!AbstractCommand::operator ==(rhs)){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const CommandDownloadProgram &rhs) {
        return !(*this == rhs);
    }
};

#endif // COMMAND_DOWNLOAD_PROGRAM_H
