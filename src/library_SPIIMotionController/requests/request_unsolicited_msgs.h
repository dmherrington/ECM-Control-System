#ifndef REQUEST_UNSOLICITED_MSGS_H
#define REQUEST_UNSOLICITED_MSGS_H

#include <string>
#include <list>

#include "common/axis_definitions.h"

#include "requests/abstract_request.h"
#include "common/class_forward.h"

ECM_CLASS_FORWARD(Request_UnsolicitedMsgs);

class Request_UnsolicitedMsgs : public AbstractRequest
{
public:
    Request_UnsolicitedMsgs();

    Request_UnsolicitedMsgs(const Request_UnsolicitedMsgs &copy);

    /**
      */
    virtual ~Request_UnsolicitedMsgs() override = default;

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

};

#endif // REQUEST_UNSOLICITED_MSGS_H
