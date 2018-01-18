#ifndef ABSTRACT_COMMAND_H
#define ABSTRACT_COMMAND_H

#include <string>

#include "common/class_forward.h"

#include "command_types.h"

/**
\* @file  abstract_command.h
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

ECM_CLASS_FORWARD(AbstractCommand);

class AbstractCommand
{
public:
    AbstractCommand(const CommandType &type)
    {
        this->commandType = type;
    }


    virtual ~AbstractCommand() = default;

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
    virtual AbstractCommand* getClone() const = 0;

    /**
     * @brief getClone
     * @param state
     */
    virtual void getClone(AbstractCommand** state) const = 0;

public:
    virtual CommandType getCommandType() const
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
    AbstractCommand& operator = (const AbstractCommand &rhs)
    {
        this->commandType = rhs.commandType;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const AbstractCommand &rhs)
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
    bool operator != (const AbstractCommand &rhs) {
        return !(*this == rhs);
    }

protected:
    CommandType commandType;

};

#endif // ABSTRACT_COMMAND_H
