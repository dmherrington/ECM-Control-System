#include "sensor_collection.h"

namespace common_data
{

Sensor* SensorCollection::ConstructSensor(const SensorTypes &type, std::string name)
{
    {
        switch(type)
        {
        case (SENSOR_PH):
            return new Sensor_pH(name);
        case (SENSOR_CONDUCTIVITY):
            return new Sensor_Conductivity(name);
        case(SENSOR_VOLTAGE):
            return new SensorVoltage(name);
        case(SENSOR_MAREA):
            return new SensorMAREA(name);
        case(SENSOR_TEMPERATURE):
            return new SensorTemperature(name);
        default:
            throw std::runtime_error("Unknown Sensor type seen when constructing sensor");
        }
    }
}

} //END Data
