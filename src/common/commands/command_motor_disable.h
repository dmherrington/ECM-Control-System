#ifndef COMMAND_MOTOR_DISABLE_H
#define COMMAND_MOTOR_DISABLE_H

#include <stdexcept>
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
    //!
    //! \brief CommandMotorDisable
    //!
    CommandMotorDisable();

    CommandMotorDisable(const CommandMotorDisable &copy);

    /**
      */
    virtual ~CommandMotorDisable() = default;

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
    void setDisableAxis(const MotorAxis &axis);

    //!
    //! \brief getDisableAxis
    //! \return
    //!
    MotorAxis getDisableAxis() const;

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
    CommandMotorDisable& operator = (const CommandMotorDisable &rhs)
    {
        AbstractCommand::operator =(rhs);
        this->disableAxis = rhs.disableAxis;
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
        if(this->disableAxis != rhs.disableAxis){
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
    std::vector<MotorAxis> disableAxis; /**< Value of the axis to be disabled */
};


#endif // COMMAND_MOTOR_DISABLE_H
