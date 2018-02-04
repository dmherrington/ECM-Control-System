#ifndef ABSTRACT_ACQUIRE_COMMAND_H
#define ABSTRACT_ACQUIRE_COMMAND_H

#include <string>

#include "common/class_forward.h"
#include "data/type_acquire_commands.h"

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

namespace rigol {
namespace commands{

ECM_CLASS_FORWARD(AbstractAcquireCommand);

class AbstractAcquireCommand
{
public:
    AbstractAcquireCommand(const data::AcquireType &type)
    {
        this->commandType = type;
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

    /**
     * @brief getClone
     * @return
     */
    virtual AbstractAcquireCommand* getClone() const = 0;

    /**
     * @brief getClone
     * @param state
     */
    virtual void getClone(AbstractAcquireCommand** state) const = 0;

public:
    virtual data::AcquireType getCommandType() const
    {
        return commandType;
    }

    virtual std::string getCommandString() const
    {
        return "";
    }

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    AbstractAcquireCommand& operator = (const AbstractAcquireCommand &rhs)
    {
        this->commandType = rhs.commandType;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const AbstractAcquireCommand &rhs)
    {
        if(this->commandType != rhs.commandType){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const data::AcquireType &rhs) {
        return !(*this == rhs);
    }

protected:
    data::AcquireType commandType;

};

} //end of namespace commands
} //end of namespace rigol

#endif // ABSTRACT_ACQUIRE_COMMAND_H
