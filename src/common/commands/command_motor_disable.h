#ifndef COMMAND_MOTOR_DISABLE_H
#define COMMAND_MOTOR_DISABLE_H

#include <stdexcept>
#include <map>

#include "../class_forward.h"

#include "abstract_command.h"
#include "../axis_definitions.h"

/**
\* @file  command_motor_disable.h
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

ECM_CLASS_FORWARD(CommandMotorDisable);

class CommandMotorDisable : public AbstractCommand
{
public:
    enum DisableValue{
        NO_CHANGE,
        CHANGE
    };

public:
    //!
    //! \brief CommandMotorDisable
    //!
    CommandMotorDisable();

    CommandMotorDisable(const CommandMotorDisable &copy);

    /**
      */
    ~CommandMotorDisable() override = default;

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
    //! \brief setDisableAxis
    //! \param axis
    //!
    void addAxis(const MotorAxis &axis);

    void setDisableAll(const bool &value);


    //!
    //! \brief getDisableAxis
    //! \return
    //!
    std::map<MotorAxis,CommandMotorDisable::DisableValue> getDisableAction() const;

    bool shouldDisableAll() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    CommandMotorDisable& operator = (const CommandMotorDisable &rhs)
    {
        AbstractCommand::operator =(rhs);
        this->disableAll = rhs.disableAll;
        this->m_AxisValue = rhs.m_AxisValue;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const CommandMotorDisable &rhs)
    {
        if(!AbstractCommand::operator ==(rhs)){
            return false;
        }
        if(this->disableAll != rhs.disableAll){
            return false;
        }
        if(this->m_AxisValue != rhs.m_AxisValue){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const CommandMotorDisable &rhs) {
        return !(*this == rhs);
    }

private:
    bool disableAll = true;
    std::map<MotorAxis,DisableValue> m_AxisValue; /**< Value of the axis to begin motion */
};


#endif // COMMAND_MOTOR_DISABLE_H
