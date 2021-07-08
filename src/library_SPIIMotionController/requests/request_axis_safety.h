#ifndef REQUEST_AXIS_SAFETY_H
#define REQUEST_AXIS_SAFETY_H

#include <string>
#include <list>

#include "common/axis_definitions.h"

#include "requests/abstract_request.h"
#include "common/class_forward.h"

ECM_CLASS_FORWARD(Request_AxisSafety);

class Request_AxisSafety : public AbstractRequest
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

#endif // REQUEST_AXIS_SAFETY_H
