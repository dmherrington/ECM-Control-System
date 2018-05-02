#ifndef REQUEST_STOP_CODE_H
#define REQUEST_STOP_CODE_H

#include <string>

#include "requests/abstract_request.h"
#include "status/status_stop_code.h"
#include "common/axis_definitions.h"
#include "common/class_forward.h"

ECM_CLASS_FORWARD(RequestStopCode);

class RequestStopCode : public AbstractRequest
{
public:
    RequestStopCode(const MotorAxis &axis = MotorAxis::Z);

    RequestStopCode(const RequestStopCode &copy);

    /**
      */
    virtual ~RequestStopCode() = default;

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

    std::vector<AbstractStatusPtr> getStatus() const;

private:
    MotorAxis codeAxis; /**< Value of the axis stop code is requested for*/

};

#endif // REQUEST_STOP_CODE_H
