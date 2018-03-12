#include "sensor_collection.h"

namespace data
{

Sensor* SensorCollection::ConstructSensor(const SensorTypes &type, std::string name)
{
    {
        switch(type)
        {
        case(SENSOR_VOLTAGE):
            return new SensorVoltage(name);
        default:
            throw std::runtime_error("Unknown Sensor type seen when constructing sensor");
        }
    }
}

} //END Data
