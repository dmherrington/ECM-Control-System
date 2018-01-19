#ifndef REQUEST_TELL_SWITCHES_H
#define REQUEST_TELL_SWITCHES_H

#include <stdint.h>
#include <string>
#include <map>

#include "requests/abstract_request.h"
#include "axis_definitions.h"

class RequestTellSwitches : public AbstractRequest
{
public:
    RequestTellSwitches(const MotorAxis &axis = MotorAxis::Z);

    RequestTellSwitches(const RequestTellSwitches &copy);

private:
    void initializeStatusMap();

public:
    /**
      */
    virtual ~RequestTellSwitches() = default;

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
    MotorAxis tellAxis; /**< Value of the axis to be position requested */

};


#endif // REQUEST_TELL_SWITCHES_H
