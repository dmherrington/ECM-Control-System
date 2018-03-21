#ifndef SENSOR_COLLECTION_H
#define SENSOR_COLLECTION_H

#include "sensors/sensor.h"
#include "sensors/sensor_voltage.h"
#include "sensors/sensor_marea.h"

namespace common_data{

class SensorCollection
{
public:

    static Sensor* ConstructSensor(const SensorTypes &type, std::string name);
};

} //END Data

#endif // SENSOR_COLLECTION_H
