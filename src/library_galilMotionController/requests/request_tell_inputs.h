#ifndef REQUEST_TELL_INPUTS_H
#define REQUEST_TELL_INPUTS_H

#include <stdint.h>
#include <string>
#include <map>

#include "requests/abstract_request.h"
#include "status/status_inputs.h"
#include "common/axis_definitions.h"

ECM_CLASS_FORWARD(RequestTellInputs);

class RequestTellInputs : public AbstractRequest
{
public:
    RequestTellInputs();

    RequestTellInputs(const std::vector<int> &pins);

    RequestTellInputs(const RequestTellInputs &copy);

public:
    /**
      */
    virtual ~RequestTellInputs() = default;

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
    void getClone(AbstractRequest** req) const override;

public:
    //!
    //! \brief getCommandString
    //! \return
    //!
    std::string getRequestString() const override;

    std::vector<AbstractStatusPtr> getStatus() const override;

};
#endif // REQUEST_TELL_INPUTS_H
