#ifndef SENSOR_COLLECTION_H
#define SENSOR_COLLECTION_H

#include "Sensors/sensor.h"
#include "Sensors/sensor_voltage.h"

namespace data
{

class SensorCollection
{
public:

    static Sensor* ConstructSensor(const SensorTypes &type, std::string name);
};

} //END Data

#endif // SENSOR_COLLECTION_H
