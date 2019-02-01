#ifndef STATUS_INPUTS_H
#define STATUS_INPUTS_H

#include <stdint.h>
#include <string>
#include <map>

#include "requests/abstract_request.h"
#include "common/axis_definitions.h"
#include "status/abstract_status.h"

ECM_CLASS_FORWARD(StatusInputs);

enum class GalilPins{
    GALIL_PIN_ESTOP = 2,
    GALIL_PIN_TOUCHOFF = 3
};

class StatusInputs : public AbstractStatus
{
public:
    StatusInputs();

    StatusInputs(const StatusInputs &copy);

public:
    /**
      */
    virtual ~StatusInputs() = default;

public:
    void setInputCode(const int &code);

    int getInputCode() const;

public:
    std::map<int, bool> getResult() const;

    bool getResult(const GalilPins &pin) const;

private:
    void parseInt(const uint8_t &value);

public:
    StatusInputs& operator = (const StatusInputs &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->originalCode = rhs.originalCode;
        this->mapInputs = rhs.mapInputs;
        return *this;
    }

    bool operator == (const StatusInputs &rhs) {
        if(!AbstractStatus::operator ==(rhs)){
            return false;
        }
        if(this->originalCode != rhs.originalCode){
            return false;
        }
        if(this->mapInputs != rhs.mapInputs){
            return false;
        }
        return true;
    }

    bool operator != (const StatusInputs &rhs) {
        return !(*this == rhs);
    }


private:
    int originalCode = 0;
    std::map<int, bool> mapInputs; /**< Results of the request */

};
#endif // STATUS_INPUTS_H
