#include "status_inputs.h"

StatusInputs::StatusInputs():
    AbstractStatus(StatusTypes::STATUS_TELLINPUTS)
{
    for(int i=1;i<9;i++)
        this->mapInputs[i] = false;
}

StatusInputs::StatusInputs(const StatusInputs &copy):
    AbstractStatus(copy)
{
    this->mapInputs = copy.mapInputs;
}

bool StatusInputs::getResult(const GalilPins &pin) const
{
    int pinNumber = static_cast<int>(pin);
    if(this->mapInputs.count(pinNumber) > 0)
        return this->mapInputs.at(pinNumber);
    return true;
}

void StatusInputs::setInputCode(const int &code)
{
    this->originalCode = code;
    this->parseInt(this->originalCode);
}

int StatusInputs::getInputCode() const
{
    return this->originalCode;
}

void StatusInputs::parseInt(const uint8_t &value)
{
    unsigned int mask = 1 << (sizeof(uint8_t) * 8 - 1);

    std::map<int,bool>::reverse_iterator it;
    for(it = mapInputs.rbegin(); it!=mapInputs.rend(); ++it)
    {
        if( (value & mask) == 0 )
            mapInputs.at(it->first) = false;
        else
           mapInputs.at(it->first) = true;
        mask  >>= 1;
    }
}
