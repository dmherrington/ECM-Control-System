#ifndef REQUEST_MOTOR_FAULT_H
#define REQUEST_MOTOR_FAULT_H

#include <string>
#include <list>

#include "common/axis_definitions.h"
#include "common/class_forward.h"
#include "requests/abstract_axis_request.h"

ECM_CLASS_FORWARD(Request_MotorFault);

class Request_MotorFault : public AbstractAxisRequest
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
};

#endif // REQUEST_MOTOR_FAULT_H
