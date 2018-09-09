#ifndef REQUEST_LIST_VARIABLES_H
#define REQUEST_LIST_VARIABLES_H

#include <string>

#include "requests/abstract_request.h"
#include "status/status_variable_value.h"
#include "status/status_variable_list.h"

#include "common/class_forward.h"

ECM_CLASS_FORWARD(RequestListVariables);

class RequestListVariables : public AbstractRequest
{
public:
    RequestListVariables();

    RequestListVariables(const RequestListVariables &copy);

    /**
      */
    virtual ~RequestListVariables() = default;

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
    //! \brief getCommandString
    //! \return
    //!
    std::string getRequestString() const override;

    std::vector<AbstractStatusPtr> getStatus() const;
};


#endif // REQUEST_LIST_VARIABLES_H
