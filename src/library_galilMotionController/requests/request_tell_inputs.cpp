#include "request_tell_inputs.h"

RequestTellInputs::RequestTellInputs():
    AbstractRequest(RequestTypes::TELL_INPUTS,16)
{

}

RequestTellInputs::RequestTellInputs(const std::vector<int> &pins):
    AbstractRequest(RequestTypes::TELL_INPUTS,16)
{
    this->tellInputs = pins;
}

RequestTellInputs::RequestTellInputs(const RequestTellInputs &copy):
    AbstractRequest(RequestTypes::TELL_INPUTS,16)
{
    this->tellInputs = copy.tellInputs;
    this->tellResults = copy.tellResults;
}

AbstractRequest* RequestTellInputs::getClone() const
{
    return (new RequestTellInputs(*this));
}

void RequestTellInputs::getClone(AbstractRequest** req) const
{
    *req = new RequestTellInputs(*this);
}

void RequestTellInputs::setInputs(const std::vector<int> &pins)
{
    this->tellInputs = pins;
}

void RequestTellInputs::setResult(const std::string &res)
{
    //parse a comma separated string
}

void RequestTellInputs::setResult(const std::map<int, bool> &res)
{
    this->tellResults = res;
}

std::map<int,bool> RequestTellInputs::getResults() const
{
    return this->tellResults;
}

bool RequestTellInputs::getResult(const int &pin, bool &exists) const
{
    if(this->tellResults.count(pin) > 0)
    {
        exists = true;
        return this->tellResults.at(pin);
    }
    return false;
}

std::string RequestTellInputs::getRequestString() const
{
    std::string str = "";

    str.append(RequestToString(this->getRequestType()));
    str.append(" ");
    for(unsigned int i = 0; i < tellInputs.size(); i++)
    {
        str.append(std::to_string(tellInputs[i]));
        if(i < (tellInputs.size() - 1))
            str.append(",");
    }
    return str;
}


