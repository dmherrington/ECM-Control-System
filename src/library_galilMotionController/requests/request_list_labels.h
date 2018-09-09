#ifndef REQUEST_LIST_LABELS_H
#define REQUEST_LIST_LABELS_H

#include <QStringList>

#include <iostream>
#include <map>

#include "common/class_forward.h"

#include "requests/abstract_request.h"

#include "status/status_label_list.h"
ECM_CLASS_FORWARD(RequestListLabels);

class RequestListLabels : public AbstractRequest
{
public:
    RequestListLabels();

    RequestListLabels(const RequestListLabels &copy);

    /**
      */
    virtual ~RequestListLabels() = default;


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

#endif // REQUEST_LIST_LABELS_H
