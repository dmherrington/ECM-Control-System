#ifndef COMMAND_STOP_H
#define COMMAND_STOP_H

#include <string>
#include "common/class_forward.h"

#include "commands/abstract_command.h"
#include "axis_definitions.h"

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
    MotorAxis stopAxis; /**< Value of the axis to be stop requested */

};

#endif // COMMAND_STOP_H
