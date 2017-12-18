#ifndef REQUEST_TELL_POSITION_H
#define REQUEST_TELL_POSITION_H


#include <string>

#include "requests/abstract_request.h"
#include "axis_definitions.h"

class RequestTellPosition : public AbstractRequest
{
public:
    RequestTellPosition(const MotorAxis &axis = MotorAxis::Z);

    RequestTellPosition(const RequestTellPosition &copy);

    /**
      */
    virtual ~CommandTellPosition() = default;

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
    virtual std::string getCommandString() const override;

private:
    MotorAxis tellAxis; /**< Value of the axis to be position requested */

};

#endif // REQUEST_TELL_POSITION_H
