#ifndef REQUEST_TELL_POSITION_H
#define REQUEST_TELL_POSITION_H
#include <string>

#include "common/axis_definitions.h"

#include "requests/abstract_request.h"
#include "status/status_position.h"
#include "common/class_forward.h"

ECM_CLASS_FORWARD(RequestTellPosition);

class RequestTellPosition : public AbstractRequest
{
public:
    RequestTellPosition(const MotorAxis &axis = MotorAxis::Z);

    RequestTellPosition(const RequestTellPosition &copy);

    /**
      */
    virtual ~RequestTellPosition() = default;

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
    void setAxis(const MotorAxis &axis);

    //!
    //! \brief getAxis
    //! \return
    //!
    MotorAxis getAxis() const;

public:
    //!
    //! \brief getCommandString
    //! \return
    //!
    std::string getRequestString() const override;


    std::vector<AbstractStatusPtr> getStatus() const override;

private:
    MotorAxis tellAxis; /**< Value of the axis to be position requested */

};

#endif // REQUEST_TELL_POSITION_H
