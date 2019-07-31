#ifndef REQUEST_PLC_CONDUCTIVITY_H
#define REQUEST_PLC_CONDUCTIVITY_H

#include "abstract_request.h"
#include "common/class_forward.h"

namespace requests_PLC {

ECM_CLASS_FORWARD(RequestPLC_Conductivity);

class RequestPLC_Conductivity : public AbstractRequest
{
public:
    RequestPLC_Conductivity();

    RequestPLC_Conductivity(const RequestPLC_Conductivity &copy);

    /**
      */
    virtual ~RequestPLC_PH() override = default;

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

private:

};

} //end of namespace requests_PLC

#endif // REQUEST_PLC_CONDUCTIVITY_H
