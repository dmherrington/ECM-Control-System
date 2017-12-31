#include "status_inputs.h"

StatusInputs::StatusInputs()
{

}

StatusInputs::StatusInputs(const std::vector<int> &pins)
{
    this->tellInputs = pins;
}

StatusInputs::StatusInputs(const StatusInputs &copy)
{
    this->tellInputs = copy.tellInputs;
    this->tellResults = copy.tellResults;
}

void StatusInputs::setInputs(const std::vector<int> &pins)
{
    this->tellInputs = pins;
}

void StatusInputs::setResult(const std::map<int, bool> &res)
{
    this->tellResults = res;
}

void StatusInputs::setResult(const int &pin, bool &res)
{
    this->tellResults[pin] = res;
}

std::map<int,bool> StatusInputs::getResults() const
{
    return this->tellResults;
}

bool StatusInputs::getResult(const int &pin, bool &exists) const
{
    if(this->tellResults.count(pin) > 0)
    {
        exists = true;
        return this->tellResults.at(pin);
    }
    return false;
}
