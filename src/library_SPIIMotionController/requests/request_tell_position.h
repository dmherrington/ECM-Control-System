#ifndef REQUEST_TELL_POSITION_H
#define REQUEST_TELL_POSITION_H

#include <string>
#include <list>

#include "common/axis_definitions.h"

#include "requests/abstract_request.h"
#include "status/status_position.h"
#include "common/class_forward.h"

namespace SPII
{

ECM_CLASS_FORWARD(RequestTellPosition);

class RequestTellPosition : public AbstractRequest
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

#endif // REQUEST_TELL_POSITION_H
