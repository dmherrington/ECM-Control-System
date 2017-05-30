#ifndef ABSTRACT_PARAMETER_H
#define ABSTRACT_PARAMETER_H

#include <QByteArray>
#include <QBitArray>
#include <string>

#include "type_definition.h"

namespace DataParameter{

class AbstractParameter
{
public:
    AbstractParameter();

public:
    virtual DataParameter::ParameterType getParamterType() const = 0;

    virtual QByteArray getByteArray() const = 0;

    virtual QByteArray getCompletedMessage() const = 0;

    virtual std::string getDescription() const  = 0;

public:
    void operator = (const AbstractParameter &rhs)
    {

    }

    bool operator == (const AbstractParameter &rhs) {

        return true;
    }

    bool operator != (const AbstractParameter &rhs) {
        return !(*this == rhs);
    }

protected:

};

} //end of namespace DataParameter
#endif // ABSTRACT_PARAMETER_H
