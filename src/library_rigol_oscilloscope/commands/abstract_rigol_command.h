#ifndef ABSTRACT_RIGOL_COMMAND_H
#define ABSTRACT_RIGOL_COMMAND_H

/**
\* @file  abstract_acquire_command.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System.
\*
\* @section DESCRIPTION
\*
\*
\*/

#include <string>

#include "common/common.h"
#include "common/class_forward.h"
#include "data/type_available_commands.h"
#include "data/type_read_write.h"

#include "abstract_rigol_status.h"

namespace rigol {
namespace commands{

ECM_CLASS_FORWARD(AbstractRigolCommand);

class AbstractRigolCommand
{
public:
    AbstractRigolCommand(const data::CommandTypes &command, const data::ReadWriteType &rw = data::ReadWriteType::WRITE)
    {
        this->commandType = command;
        this->RWType = rw;
    }


    virtual ~AbstractRigolCommand() = default;

    /**
     *
     */
    template <class T>
    const T *as() const
    {
        //ensure that we are attempting to cast it to a type of state
        return static_cast<const T *>(this);
    }

    /**
     *
     */
    template <class T>
    T *as()
    {
        //ensure that we are attempting to cast it to a type of state
        return static_cast<T *>(this);
    }

    /**
     * @brief getClone
     * @return
     */
    virtual AbstractRigolCommand* getClone() const = 0;

    /**
     * @brief getClone
     * @param state
     */
    virtual void getClone(AbstractRigolCommand** state) const = 0;

public:
    virtual data::CommandTypes getCommandType() const
    {
        return commandType;
    }

    virtual void setReadOrWrite(const data::ReadWriteType &type)
    {
        this->RWType = type;
    }

    virtual data::ReadWriteType isReadorWrite() const
    {
        return RWType;
    }

    virtual std::string getCommandString() const = 0;

    virtual std::string getCommandKey() const = 0;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    AbstractRigolCommand& operator = (const AbstractRigolCommand &rhs)
    {
        this->commandType = rhs.commandType;
        this->RWType = rhs.RWType;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const AbstractRigolCommand &rhs)
    {
        if(this->commandType != rhs.commandType){
            return false;
        }
        if(this->RWType != rhs.RWType){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const AbstractRigolCommand &rhs) {
        return !(*this == rhs);
    }

protected:
    virtual std::string getPrefixCommand() const
    {
        std::string rtn = ":";
        rtn +=data::getRigolCommandString(this->commandType);
        rtn+=":";
        return rtn;
    }

    std::string getSuffixCommand() const
    {
        if(RWType == data::ReadWriteType::READ)
            return "?";
        else
            return "";
    }

protected:
    data::CommandTypes commandType;
    data::ReadWriteType RWType;

};

} //end of namespace commands
} //end of namespace rigol

#endif // ABSTRACT_RIGOL_COMMAND_H
