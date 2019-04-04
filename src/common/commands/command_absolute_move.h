#ifndef COMMAND_ABSOLUTE_MOVE_H
#define COMMAND_ABSOLUTE_MOVE_H

#include <map>
#include <math.h>

#include "../class_forward.h"
#include "../axis_definitions.h"

#include "abstract_command.h"
#include "abstract_move_command.h"


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

ECM_CLASS_FORWARD(CommandAbsoluteMove);

class CommandAbsoluteMove : public AbstractMoveCommand
{
public:
    CommandAbsoluteMove();

    CommandAbsoluteMove(const CommandAbsoluteMove &copy);

    /**
      */
    virtual ~CommandAbsoluteMove() = default;

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
    void addAbsoluteMovePosition(const MotorAxis &axis, const double &position, const Direction &direction);

public:
    std::map<MotorAxis, double> getAbsoluteMovePosition() const;

public:
    std::string getCommandString() const override;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    CommandAbsoluteMove& operator = (const CommandAbsoluteMove &rhs)
    {
        AbstractMoveCommand::operator =(rhs);
        this->absoluteMove = rhs.absoluteMove;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const CommandAbsoluteMove &rhs)
    {
        if(!AbstractMoveCommand::operator ==(rhs)){
            return false;
        }
        if(this->absoluteMove != rhs.absoluteMove){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const CommandAbsoluteMove &rhs) {
        return !(*this == rhs);
    }

private:
    std::map<MotorAxis, double> absoluteMove; /**< Value of the relative move */
};

#endif // COMMAND_ABSOLUTE_MOVE_H
