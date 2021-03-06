#include "register_data_object.h"

namespace data_Munk{

RegisterDataObject::RegisterDataObject():
    voltage(0),current(0)
{

}

RegisterDataObject::RegisterDataObject(const double &newVoltage, const double &newCurrent):
    voltage(newVoltage),current(newCurrent)
{

}

RegisterDataObject::RegisterDataObject(const RegisterDataObject &obj)
{
    this->voltage = obj.voltage;
    this->current =obj.current;
}

RegisterDataObject& RegisterDataObject::operator =(const RegisterDataObject &rhs)
{
    this->voltage = rhs.voltage;
    this->current =rhs.current;
    return *this;
}

bool RegisterDataObject::operator <(const RegisterDataObject &rhs) const
{
    if(*this == rhs)
        return false;

    if(this->voltage > rhs.voltage)
        return false;
    else if(this->voltage < rhs.voltage)
        return true;
    else{ //this implies that voltage was equal
        if(this->current > rhs.current)
            return false;
        else if(this->current < rhs.current)
            return true;
        else{ //this implies that the current was equal
            return false;
        }
    }
}

bool RegisterDataObject::operator ==(const RegisterDataObject &rhs) const
{
    if(this->voltage != rhs.voltage)
        return false;
    if(this->current != rhs.current)
        return false;
    return true;
}

bool RegisterDataObject::operator !=(const RegisterDataObject &rhs) const
{
    return !((*this) == rhs);
}

} //end of namespace data_Munk

