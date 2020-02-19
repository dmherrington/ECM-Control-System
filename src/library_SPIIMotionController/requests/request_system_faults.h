#ifndef REQUEST_SYSTEM_FAULTS_H
#define REQUEST_SYSTEM_FAULTS_H

#include <string>
#include <list>

#include "common/axis_definitions.h"
#include "common/class_forward.h"
#include "requests/abstract_axis_request.h"

ECM_CLASS_FORWARD(Request_SystemFaults);

class Request_SystemFaults : public AbstractRequest
{
public:
    Request_SystemFaults();

    Request_SystemFaults(const Request_SystemFaults &copy);

    /**
      */
    virtual ~Request_SystemFaults() override = default;

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


#endif // REQUEST_SYSTEM_FAULTS_H
