#ifndef STATUS_INPUTS_H
#define STATUS_INPUTS_H


class StatusInputs
{
public:
    StatusInputs();
};


#include <stdint.h>
#include <string>
#include <map>

#include "requests/abstract_request.h"
#include "axis_definitions.h"

class StatusInputs
{
public:
    StatusInputs();

    StatusInputs(const std::vector<int> &pins);

    StatusInputs(const StatusInputs &copy);

public:
    /**
      */
    virtual ~StatusInputs() = default;

public:
    void setInputs(const std::vector<int> &pins);

    void setResult(const std::map<int, bool> &res);

    void setResult(const int &pin, bool &res);


public:
    std::map<int, bool> getResults() const;

    bool getResult(const int &pin, bool &exists) const;

private:
    std::vector<int> tellInputs; /**< Value of the pins to be requested */
    std::map<int, bool> tellResults; /**< Results of the request */

};
#endif // STATUS_INPUTS_H
