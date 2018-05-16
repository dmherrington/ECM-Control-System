#ifndef ABSTRACT_MOVE_COMMAND_H
#define ABSTRACT_MOVE_COMMAND_H

#include <map>

#include "abstract_command.h"
#include "common/axis_definitions.h"

#include "type_direction.h"

/**
\* @file  abstract_move_command.h
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

class AbstractMoveCommand : public AbstractCommand
{

public:
    AbstractMoveCommand(const CommandType &type, const MotorAxis &axis):
        AbstractCommand(type)
    {
        this->moveType = type;
        this->moveAxis = axis;
        moveDirection[MotorAxis::X] = Direction::DIRECTION_UP;
        moveDirection[MotorAxis::Y] = Direction::DIRECTION_UP;
        moveDirection[MotorAxis::Z] = Direction::DIRECTION_UP;
    }

    virtual ~AbstractMoveCommand() = default;

    AbstractMoveCommand(const AbstractMoveCommand &copy):
        AbstractCommand(copy.getMoveType())
    {
        this->moveType = copy.moveType;
        this->moveAxis = copy.moveAxis;
        this->moveDirection = copy.moveDirection;
    }

public:
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

public:
    virtual CommandType getMoveType() const
    {
        return moveType;
    }

    virtual MotorAxis getMoveAxis() const
    {
        return moveAxis;
    }

    virtual std::map<MotorAxis, Direction> getMoveDirection() const
    {
        return moveDirection;
    }

    virtual void setMoveAxis(const MotorAxis &axis)
    {
        this->moveAxis = axis;
    }

    virtual void setMoveDirection(const MotorAxis &axis, const Direction &direction)
    {
        if(axis == MotorAxis::ALL)
        {
            moveDirection[MotorAxis::X] = direction;
            moveDirection[MotorAxis::Y] = direction;
            moveDirection[MotorAxis::Z] = direction;
        }
        this->moveDirection[axis] = direction;
    }

public:
    AbstractMoveCommand& operator = (const AbstractMoveCommand &rhs)
    {
        AbstractCommand::operator =(rhs);
        this->moveType = rhs.moveType;
        this->moveAxis = rhs.moveAxis;
        this->moveDirection = rhs.moveDirection;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const AbstractMoveCommand &rhs)
    {
        if(!AbstractCommand::operator ==(rhs)){
            return false;
        }
        if(this->moveType != rhs.moveType){
            return false;
        }
        if(this->moveAxis != rhs.moveAxis){
            return false;
        }
        if(this->moveDirection != rhs.moveDirection){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const AbstractMoveCommand &rhs) {
        return !(*this == rhs);
    }


protected:
    CommandType moveType;
    MotorAxis moveAxis;
    std::map<MotorAxis, Direction> moveDirection;
};

#endif // ABSTRACT_MOVE_COMMAND_H
