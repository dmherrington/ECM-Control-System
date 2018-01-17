#ifndef REQUEST_LIST_LABELS_H
#define REQUEST_LIST_LABELS_H

#include <QStringList>

#include <iostream>
#include <map>

#include "requests/abstract_request.h"

class RequestListLabels : public AbstractRequest
{
public:
    RequestListLabels();

    RequestListLabels(const RequestListLabels &copy);

    /**
      */
    virtual ~RequestListLabels() = default;


public:
    void updateLabels(const std::string &labels);

    std::map<std::string, int> getLabels() const;


public:
    //!
    //! \brief getCommandString
    //! \return
    //!
    std::string getRequestString() const override;


private:
    std::map<std::string, int> mapLabels; /**< Value of the axis stop code is requested for*/

};

#endif // REQUEST_LIST_LABELS_H
