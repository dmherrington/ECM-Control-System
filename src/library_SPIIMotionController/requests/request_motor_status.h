#ifndef REQUEST_MOTOR_STATUS_H
#define REQUEST_MOTOR_STATUS_H

#include <string>
#include <list>

#include "common/axis_definitions.h"
#include "common/class_forward.h"
#include "requests/abstract_axis_request.h"

ECM_CLASS_FORWARD(RequestMotorStatus);

class RequestMotorStatus : public AbstractAxisRequest
{
public:
    RequestMotorStatus(const MotorAxis &axis = MotorAxis::Z);

    RequestMotorStatus(const RequestMotorStatus &copy);

    /**
      */
    virtual ~RequestMotorStatus() override = default;

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
};

#endif // REQUEST_MOTOR_STATUS_H
