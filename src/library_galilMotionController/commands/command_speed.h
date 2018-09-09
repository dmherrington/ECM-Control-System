#ifndef COMMAND_SPEED_H
#define COMMAND_SPEED_H

#include <map>

#include "common/class_forward.h"

#include "abstract_command.h"
#include "common/axis_definitions.h"

/**
\* @file  command_speed.h
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

ECM_CLASS_FORWARD(CommandSpeed);

class CommandSpeed : public AbstractCommand
{
public:
    CommandSpeed();

    CommandSpeed(const CommandSpeed &copy);

    CommandSpeed(const MotorAxis &axis, const unsigned int &speed);


    /**
      */
    virtual ~CommandSpeed() = default;

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
    void setAxisSpeed(const MotorAxis &axis, const unsigned int &speed);

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
    CommandSpeed& operator = (const CommandSpeed &rhs)
    {
        AbstractCommand::operator =(rhs);
        this->axisSpeed = rhs.axisSpeed;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const CommandSpeed &rhs)
    {
        if(!AbstractCommand::operator ==(rhs)){
            return false;
        }
        if(this->axisSpeed != rhs.axisSpeed){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const CommandSpeed &rhs) {
        return !(*this == rhs);
    }


private:
    std::map<MotorAxis, unsigned int> axisSpeed; /**< Value of the speed per axis in micrometers */

};

//! \remark
//! Negative values will be interpreted as the absolute value.

//! \remark
//! The resolution of the SP command is dependent upon the update rate setting (TM).
//! With the default rate of TM 1000 the resolution is 2 cnts/second.
//! The equation to calculate the resolution of the SP command is: resolution = 2*(1000/TM)

#endif // COMMAND_SPEED_H
