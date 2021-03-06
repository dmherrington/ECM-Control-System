#ifndef COMMAND_MOTION_START_H
#define COMMAND_MOTION_START_H

#include <string>
#include "common/class_forward.h"

#include "commands/abstract_command.h"
#include "common/axis_definitions.h"

ECM_CLASS_FORWARD(CommandMotionStart);

class CommandMotionStart : public AbstractCommand
{
public:
    CommandMotionStart(const MotorAxis &axis = MotorAxis::Z);

    CommandMotionStart(const CommandMotionStart &copy);

    /**
      */
    virtual ~CommandMotionStart() = default;

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
    CommandMotionStart& operator = (const CommandMotionStart &rhs)
    {
        AbstractCommand::operator =(rhs);
        this->startAxis = rhs.startAxis;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const CommandMotionStart &rhs)
    {
        if(!AbstractCommand::operator ==(rhs)){
            return false;
        }
        if(this->startAxis != rhs.startAxis){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const CommandMotionStart &rhs) {
        return !(*this == rhs);
    }

private:
    MotorAxis startAxis; /**< Value of the axis to begin motion */

};

#endif // COMMAND_MOTION_START_H
