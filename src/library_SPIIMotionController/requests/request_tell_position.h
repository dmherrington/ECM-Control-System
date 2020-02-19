#ifndef REQUEST_TELL_POSITION_H
#define REQUEST_TELL_POSITION_H

#include <string>
#include <list>

#include "common/axis_definitions.h"
#include "common/class_forward.h"
#include "requests/abstract_axis_request.h"
#include "status/status_position.h"


ECM_CLASS_FORWARD(RequestTellPosition);

class RequestTellPosition : public AbstractAxisRequest
{
public:
    RequestTellPosition(const MotorAxis &axis = MotorAxis::Z);

    RequestTellPosition(const RequestTellPosition &copy);

    /**
      */
    virtual ~RequestTellPosition() override = default;

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

#endif // REQUEST_TELL_POSITION_H
