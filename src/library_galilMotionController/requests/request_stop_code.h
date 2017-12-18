#ifndef REQUEST_STOP_CODE_H
#define REQUEST_STOP_CODE_H

#include <string>

#include "commands/abstract_command.h"
#include "axis_definitions.h"

class RequestStopCode : public AbstractCommand
{
public:
    RequestStopCode(const MotorAxis &axis = MotorAxis::Z);

    RequestStopCode(const RequestStopCode &copy);

    /**
      */
    virtual ~RequestStopCode() = default;

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
    virtual std::string getCommandString() const override;

private:
    MotorAxis stopAxis; /**< Value of the axis to be stop requested */

};

#endif // REQUEST_STOP_CODE_H
