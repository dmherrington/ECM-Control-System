#ifndef COMMAND_JOG_H
#define COMMAND_JOG_H

#include <map>
#include <math.h>

#include "../common.h"

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

ECM_CLASS_FORWARD(CommandJog);

class CommandJog : public AbstractMoveCommand
{
public:
    CommandJog();

    CommandJog(const MotorAxis &axis, const double &speed);

    CommandJog(const double &resolution, const double &speed);

    CommandJog(const MotorAxis &axis, const double &resolution, const double &speed);

    CommandJog(const CommandJog &copy);

    /**
      */
    virtual ~CommandJog() = default;

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
    void setJogDirection(const MotorAxis &axis, const Direction &direction);
    void setJogResolution(const double &resolution);
    void setJogSpeed(const MotorAxis &axis, const double &speed);

    std::map<MotorAxis, double> getJogAction() const;

public:
    std::string getCommandString() const override;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    CommandJog& operator = (const CommandJog &rhs)
    {
        AbstractMoveCommand::operator =(rhs);
        this->jogResolution = rhs.jogResolution;
        this->jogSpeed = rhs.jogSpeed;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const CommandJog &rhs)
    {
        if(!AbstractMoveCommand::operator ==(rhs)){
            return false;
        }
        if(this->jogResolution != rhs.jogResolution){
            return false;
        }
        if(this->jogSpeed != rhs.jogSpeed){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const CommandJog &rhs) {
        return !(*this == rhs);
    }


private:
    double jogResolution = 1000; /**< Value of the jog resolution as related to the TM command */
    std::map<MotorAxis, double> jogSpeed; /**< Value of the jog speed in cnts/second */
};

#endif // COMMAND_JOG_H
