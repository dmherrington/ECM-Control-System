#ifndef COMMAND_STOP_H
#define COMMAND_STOP_H

#include <map>

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

ECM_CLASS_FORWARD(CommandStop);

class CommandStop : public AbstractCommand
{
public:
    CommandStop(const MotorAxis &axis = MotorAxis::Z);

    CommandStop(const CommandStop &copy);

    /**
      */
    virtual ~CommandStop() = default;

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
    //! \brief setAxis
    //! \param axis
    //!
    void setAxis(const MotorAxis &axis);

    //!
    //! \brief getAxis
    //! \return
    //!
    MotorAxis getAxis() const;

public:
    bool shouldStopAllMotion() const;

    std::map<MotorAxis, bool> getStopAction() const;

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
    CommandStop& operator = (const CommandStop &rhs)
    {
        AbstractCommand::operator =(rhs);
        this->stopAll = rhs.stopAll;
        this->stopAxis = rhs.stopAxis;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const CommandStop &rhs)
    {
        if(!AbstractCommand::operator ==(rhs)){
            return false;
        }
        if(this->stopAll != rhs.stopAll){
            return false;
        }
        if(this->stopAxis != rhs.stopAxis){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const CommandStop &rhs) {
        return !(*this == rhs);
    }

private:
    bool stopAll = true;
    std::map<MotorAxis,bool> stopAxis; /**< Value of the axis to begin motion */
};

#endif // COMMAND_STOP_H
