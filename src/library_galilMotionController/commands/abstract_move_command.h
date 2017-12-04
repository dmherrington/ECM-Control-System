#ifndef ABSTRACT_MOVE_COMMAND_H
#define ABSTRACT_MOVE_COMMAND_H

#include <map>

#include "abstract_command.h"
#include "axis_definitions.h"

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
    AbstractMoveCommand(const CommandType &type, const MotorAxis &axis)
    {
        this->moveType = type;
        this->moveAxis = axis;
        moveDirection[MotorAxis::X] = Direction::DIRECTION_UP;
        moveDirection[MotorAxis::Y] = Direction::DIRECTION_UP;
        moveDirection[MotorAxis::Z] = Direction::DIRECTION_UP;
    }

    virtual ~AbstractMoveCommand() = default;

    AbstractMoveCommand(const AbstractMoveCommand &copy)
    {
        this->moveType = copy.getMoveType();
        this->moveAxis = copy.getMoveAxis();
        this->moveDirection = copy.getMoveDirection();
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
    AbstractMoveCommand& operator = (const AbstractMoveCommand &assign)
    {
        this->moveType = assign.moveType;
        this->moveAxis = assign.moveAxis;
        this->moveDirection = assign.moveDirection;
        return *this;
    }

protected:
    CommandType moveType;
    MotorAxis moveAxis;
    std::map<MotorAxis, Direction> moveDirection;
};

#endif // ABSTRACT_MOVE_COMMAND_H
