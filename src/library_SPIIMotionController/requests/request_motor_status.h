#ifndef REQUEST_MOTOR_STATUS_H
#define REQUEST_MOTOR_STATUS_H

#include <string>
#include <list>

#include "common/axis_definitions.h"

#include "requests/abstract_request.h"
#include "common/class_forward.h"

namespace SPII
{

ECM_CLASS_FORWARD(RequestMotorStatus);

class RequestMotorStatus : public AbstractRequest
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
    SPII::AbstractRequest* getClone() const override;

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

} //end of namespace SPII


#endif // REQUEST_MOTOR_STATUS_H
