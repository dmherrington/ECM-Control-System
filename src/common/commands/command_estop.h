#ifndef COMMAND_ESTOP_H
#define COMMAND_ESTOP_H

#include <string>
#include "../class_forward.h"
#include "../axis_definitions.h"

#include "abstract_command.h"

/**
\* @file  command_jog.h
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

ECM_CLASS_FORWARD(CommandEStop);

class CommandEStop : public AbstractCommand
{
public:
    CommandEStop();

    CommandEStop(const CommandEStop &copy);

    /**
      */
    virtual ~CommandEStop() = default;

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
    CommandEStop& operator = (const CommandEStop &rhs)
    {
        AbstractCommand::operator =(rhs);
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const CommandEStop &rhs)
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
    bool operator != (const CommandEStop &rhs) {
        return !(*this == rhs);
    }
};


#endif // COMMAND_ESTOP_H
