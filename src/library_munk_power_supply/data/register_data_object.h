#ifndef REGISTER_DATA_OBJECT_H
#define REGISTER_DATA_OBJECT_H

#include <stdint.h>
#include <string>
#include <stdexcept>
#include <vector>

namespace Data
{

class RegisterDataObject
{
public:
    RegisterDataObject();
    RegisterDataObject(const int &voltage, const int &current);
    RegisterDataObject(const RegisterDataObject &obj);

public:
    void operator =(const RegisterDataObject &rhs);

    bool operator< (const RegisterDataObject &rhs) const;

    bool operator== (const RegisterDataObject &rhs) const;

    bool operator!= (const RegisterDataObject &rhs) const;

public:
    int voltage;
    int current;
};

} //end of namespace Data

#endif // REGISTER_DATA_OBJECT_H
