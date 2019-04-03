#ifndef COMMAND_RELATIVE_MOVE_H
#define COMMAND_RELATIVE_MOVE_H

#include <map>
#include <math.h>

#include "../class_forward.h"
#include "../axis_definitions.h"

#include "abstract_command.h"
#include "abstract_move_command.h"

/**
\* @file  command_relative_move.h
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


ECM_CLASS_FORWARD(CommandRelativeMove);

class CommandRelativeMove : public AbstractMoveCommand
{
public:
    CommandRelativeMove();

    CommandRelativeMove(const MotorAxis &axis, const int &distance);

    CommandRelativeMove(const CommandRelativeMove &copy);

    /**
      */
    ~CommandRelativeMove() override = default;

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
    void setRelativeDirection(const MotorAxis &axis, const Direction &direction);
    void setRelativeDistance(const MotorAxis &axis, const double &distance);

    double getRelativeDistance(const MotorAxis &axis) const;

    std::map<MotorAxis, double> getDirectedRelativeMove() const;

public:
    std::string getCommandString() const override;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    CommandRelativeMove& operator = (const CommandRelativeMove &rhs)
    {
        AbstractCommand::operator =(rhs);
        this->relativeMove = rhs.relativeMove;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const CommandRelativeMove &rhs)
    {
        if(!AbstractCommand::operator ==(rhs)){
            return false;
        }
        if(this->relativeMove != rhs.relativeMove){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const CommandRelativeMove &rhs) {
        return !(*this == rhs);
    }

private:
    std::map<MotorAxis, double> relativeMove; /**< Value of the relative move in micrometers */
};

#endif // COMMAND_RELATIVE_MOVE_H
