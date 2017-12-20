#ifndef REQUEST_TELL_INPUTS_H
#define REQUEST_TELL_INPUTS_H

#include <stdint.h>
#include <string>
#include <map>

#include "requests/abstract_request.h"
#include "axis_definitions.h"

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
    void setInputs(const std::vector<int> &pins);

    void setResult(const std::string &res);

    void setResult(const std::map<int, bool> &res);

public:
    std::map<int, bool> getResults() const;

    bool getResult(const int &pin, bool &exists) const;

public:
    //!
    //! \brief getCommandString
    //! \return
    //!
    std::string getRequestString() const override;


private:
    std::vector<int> tellInputs; /**< Value of the pins to be requested */
    std::map<int, bool> tellResults; /**< Results of the request */

};
#endif // REQUEST_TELL_INPUTS_H
