#ifndef REQUEST_AXIS_STATUS_H
#define REQUEST_AXIS_STATUS_H

#include <string>
#include <list>

#include "common/axis_definitions.h"
#include "common/class_forward.h"
#include "requests/abstract_axis_request.h"

ECM_CLASS_FORWARD(RequestAxisStatus);

class RequestAxisStatus : public AbstractAxisRequest
{
public:
    RequestAxisStatus(const MotorAxis &axis = MotorAxis::Z);

    RequestAxisStatus(const RequestAxisStatus &copy);

    /**
      */
    virtual ~RequestAxisStatus() override = default;

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

#endif // REQUEST_AXIS_STATUS_H
