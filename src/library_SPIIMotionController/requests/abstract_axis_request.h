#ifndef ABSTRACT_AXIS_REQUEST_H
#define ABSTRACT_AXIS_REQUEST_H

#include <string>
#include <list>

#include "common/axis_definitions.h"
#include "common/class_forward.h"
#include "requests/abstract_request.h"

ECM_CLASS_FORWARD(AbstractAxisRequest);

class AbstractAxisRequest : public AbstractRequest
{
public:
    AbstractAxisRequest(const RequestTypes &type, const MotorAxis &axis, const unsigned int &respSize = 12):
        AbstractRequest(type,respSize)
    {
        addAxis(axis);
    }

    AbstractAxisRequest(const AbstractAxisRequest &copy):
        AbstractRequest(copy)
    {
        this->requestAllAxis = copy.requestAllAxis;
        this->tellAxis = copy.tellAxis;
    }

    /**
      */
    virtual ~AbstractAxisRequest() override = default;

public:
    //!
    //! \brief setAxis
    //! \param axis
    //!
    void addAxis(const MotorAxis &axis)
    {
        tellAxis.push_back(axis);
        tellAxis.unique();
        requestAllAxis = false;
    }

    //!
    //! \brief addAxes
    //! \param axes
    //!
    void addAxes(const std::vector<MotorAxis> &axes)
    {
        for(size_t i = 0; i < axes.size(); i++)
        {
            addAxis(axes.at(i));
        }
    }

    //!
    //! \brief getAxis
    //! \return
    //!
    std::list<MotorAxis> getAxis() const
    {
        return this->tellAxis;
    }

    void setRequestAllAxes(const bool &requestAll)
    {
        this->requestAllAxis = requestAll;
    }

    bool shouldRequestAllAxes() const
    {
        return requestAllAxis;
    }

private:
    bool requestAllAxis = true;

    std::list<MotorAxis> tellAxis; /**< Value of the axis to be queried */

};

#endif // ABSTRACT_AXIS_REQUEST_H
