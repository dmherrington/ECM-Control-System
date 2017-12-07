#ifndef COMMAND_JOG_H
#define COMMAND_JOG_H

#include <map>
#include <math.h>

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

class CommandJog : public AbstractMoveCommand
{
public:
    CommandJog();

    CommandJog(const MotorAxis &axis, const double &speed);

    CommandJog(const double &resolution, const double &speed);

    CommandJog(const MotorAxis &axis, const double &resolution, const double &speed);

public:
    void setJogDirection(const MotorAxis &axis, const Direction &direction);
    void setJogResolution(const double &resolution);
    void setJogSpeed(const MotorAxis &axis, const double &speed);

public:
    std::string getCommandString() const override;

private:
    double jogResolution = 1000; /**< Value of the jog resolution as related to the TM command */
    std::map<MotorAxis, double> jogSpeed; /**< Value of the jog speed in cnts/second */
};

//! \remark
//! JGm=n Arguements specified with a single axis mask and an assignment operator (=)
//! JG n ... Arguements specified with an implicit, comma-separated order
//! _JGM Operand contains the absolute value of the jog speed for the specified axis.

//! \remark
//!When jogging, the motion controller profiles a continuous move at the commanded speed.
//!To stop the motion, use the ST command.
//!JG 2 is the minimum non-zero speed
//!The JG command will set the SP register with the absolute value of the 'n' value.

#endif // COMMAND_JOG_H