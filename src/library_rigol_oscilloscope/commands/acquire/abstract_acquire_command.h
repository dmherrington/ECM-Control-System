#ifndef ABSTRACT_ACQUIRE_COMMAND_H
#define ABSTRACT_ACQUIRE_COMMAND_H

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

#include "common/class_forward.h"
#include "commands/abstract_rigol_command.h"

#include "data/type_acquire_commands.h"
#include "data/type_read_write.h"


namespace commands_Rigol{

ECM_CLASS_FORWARD(AbstractAcquireCommand);

class AbstractAcquireCommand : public AbstractRigolCommand
{
public:
    AbstractAcquireCommand(const data_Rigol::AcquireType &acquire, const data_Rigol::ReadWriteType &rw = data_Rigol::ReadWriteType::WRITE):
        AbstractRigolCommand(data_Rigol::CommandTypes::COMMAND_ACQUIRE,rw)
    {
        this->acquireType = acquire;
    }

    AbstractAcquireCommand(const AbstractAcquireCommand& copy):
        AbstractRigolCommand(copy)
    {
        this->acquireType = copy.acquireType;
    }


    virtual ~AbstractAcquireCommand() = default;

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

    std::string getCommandString() const override
    {
        std::string str = "";
        str+=getPrefixCommand();
        str+= data_Rigol::AcquireTypeToString(this->getAcquisitionType());
        str+=getSuffixCommand();
        str+=this->getAcquireCommandString();
        str+="\n";
        return str;
    }

    std::string getCommandKey() const override
    {
        return "";
    }


public:
    virtual data_Rigol::AcquireType getAcquisitionType() const
    {
        return acquireType;
    }

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    AbstractAcquireCommand& operator = (const AbstractAcquireCommand &rhs)
    {
        AbstractRigolCommand::operator =(rhs);
        this->acquireType = rhs.acquireType;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const AbstractAcquireCommand &rhs)
    {
        if(!AbstractRigolCommand::operator ==(rhs)){
            return false;
        }
        if(this->acquireType != rhs.acquireType){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const AbstractAcquireCommand &rhs) {
        return !(*this == rhs);
    }

protected:
    virtual std::string getAcquireCommandString() const = 0;

protected:
    data_Rigol::AcquireType acquireType;
};

} //end of namespace commands


#endif // ABSTRACT_ACQUIRE_COMMAND_H
