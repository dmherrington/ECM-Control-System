#ifndef REQUEST_PLC_PH_H
#define REQUEST_PLC_PH_H

#include "abstract_request.h"
#include "common/class_forward.h"

namespace requests_PLC {

ECM_CLASS_FORWARD(RequestPLC_PH);

class RequestPLC_PH : public AbstractRequest
{
public:
    RequestPLC_PH();

    RequestPLC_PH(const RequestPLC_PH &copy);

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

#endif // REQUEST_PLC_PH_H
