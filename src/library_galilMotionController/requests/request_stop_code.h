#ifndef REQUEST_STOP_CODE_H
#define REQUEST_STOP_CODE_H

#include <string>

#include "requests/abstract_request.h"
#include "axis_definitions.h"

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

private:
    MotorAxis stopAxis; /**< Value of the axis to be stop requested */

};

#endif // REQUEST_STOP_CODE_H
