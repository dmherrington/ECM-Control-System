#ifndef REQUEST_MOTOR_FAULT_H
#define REQUEST_MOTOR_FAULT_H

#include <string>
#include <list>

#include "common/axis_definitions.h"

#include "requests/abstract_request.h"
#include "common/class_forward.h"

ECM_CLASS_FORWARD(Request_MotorFault);

class Request_MotorFault : public AbstractRequest
{
public:
    Request_MotorFault(const MotorAxis &axis = MotorAxis::Z);

    Request_MotorFault(const Request_MotorFault &copy);

    /**
      */
    virtual ~Request_MotorFault() override = default;

public:

    /**
     * @brief getClone
     * @return
     */
    AbstractRequest* getClone() const override;

    /**
     * @brief getClone
     * @param state
     */
    void getClone(AbstractRequest** state) const override;

public:
    //!
    //! \brief setAxis
    //! \param axis
    //!
    void addAxis(const MotorAxis &axis);

    //!
    //! \brief getAxis
    //! \return
    //!
    std::list<MotorAxis> getAxis() const;

    void setRequestAllAxes(const bool &requestAll);

    bool shouldRequestAllAxes() const;

private:
    bool requestAllAxis = true;
    std::list<MotorAxis> tellAxis; /**< Value of the axis to be queried */

};

#endif // REQUEST_MOTOR_FAULT_H
