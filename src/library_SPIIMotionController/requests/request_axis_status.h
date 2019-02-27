#ifndef REQUEST_AXIS_STATUS_H
#define REQUEST_AXIS_STATUS_H

#include <string>
#include <list>

#include "common/axis_definitions.h"

#include "requests/abstract_request.h"
#include "common/class_forward.h"

ECM_CLASS_FORWARD(RequestAxisStatus);

class RequestAxisStatus : public AbstractRequest
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

private:
    std::list<MotorAxis> tellAxis; /**< Value of the axis to be position requested */

};

#endif // REQUEST_AXIS_STATUS_H
