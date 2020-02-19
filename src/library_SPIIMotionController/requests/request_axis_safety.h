#ifndef REQUEST_AXIS_SAFETY_H
#define REQUEST_AXIS_SAFETY_H

#include <string>
#include <list>

#include "common/axis_definitions.h"
#include "common/class_forward.h"
#include "requests/abstract_axis_request.h"

ECM_CLASS_FORWARD(Request_AxisSafety);

class Request_AxisSafety : public AbstractAxisRequest
{
public:
    Request_AxisSafety(const MotorAxis &axis = MotorAxis::Z);

    Request_AxisSafety(const Request_AxisSafety &copy);

    /**
      */
    virtual ~Request_AxisSafety() override = default;

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

#endif // REQUEST_AXIS_SAFETY_H
