#ifndef ABSTRACT_REQUEST_H
#define ABSTRACT_REQUEST_H


#include <string>

#include "requests/request_types.h"

/**
\* @file  abstract_request.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is to control the Galil Motion Controller.
\*
\* @section DESCRIPTION
\*
\*
\*/

class AbstractRequest
{
public:
    AbstractRequest(const RequestTypes &type)
    {
        this->requestType = type;
    }


    virtual ~AbstractCommand() = default;

    /**
     *
     */
    template <class T>
    const T *as() const
    {
        //ensure that we are attempting to cast it to a type of state
        return static_cast<const T *>(this);
    }

    /**
     *
     */
    template <class T>
    T *as()
    {
        //ensure that we are attempting to cast it to a type of state
        return static_cast<T *>(this);
    }

    /**
     * @brief getClone
     * @return
     */
    virtual AbstractRequest* getClone() const = 0;

    /**
     * @brief getClone
     * @param state
     */
    virtual void getClone(AbstractRequest** state) const = 0;

public:
    virtual RequestTypes getRequestType() const
    {
        return requestType;
    }

    virtual std::string getRequestString() const = 0;

protected:
    RequestTypes requestType;

};

#endif // ABSTRACT_REQUEST_H