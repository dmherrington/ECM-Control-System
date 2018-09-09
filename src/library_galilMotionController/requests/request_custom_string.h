#ifndef REQUEST_CUSTOM_STRING_H
#define REQUEST_CUSTOM_STRING_H

#include <QStringList>

#include <iostream>
#include <map>

#include "common/class_forward.h"

#include "requests/abstract_request.h"

#include "status/status_custom_request.h"

ECM_CLASS_FORWARD(RequestCustomString);

class RequestCustomString : public AbstractRequest
{
public:
    RequestCustomString();

    RequestCustomString(const RequestCustomString &copy);

    /**
      */
    virtual ~RequestCustomString() = default;


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
    void setRequestString(const std::string &request);

public:
    //!
    //! \brief getCommandString
    //! \return
    //!
    std::string getRequestString() const override;

    std::vector<AbstractStatusPtr> getStatus() const;

private:
    std::string customRequestString = "";
};


#endif // REQUEST_CUSTOM_STRING_H
