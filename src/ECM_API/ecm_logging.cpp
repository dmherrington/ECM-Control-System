#include "ecm_logging.h"

ECMLogging::ECMLogging()
{

}

void ECMLogging::setLoggingRelativeTime(const bool &value)
{
    this->logReglativeTime = value;
}

bool ECMLogging::isLoggingRelativeTime() const
{
    return this->logReglativeTime;
}

void ECMLogging::setLoggingStartTime(const common::EnvironmentTime &time)
{
    this->startLogTime = time;
}


void ECMLogging::WriteLogSensorState(const common::TupleSensorString &key, const common_data::SensorState &state)
{
//    if(m_LogSensorStates.contains(key) == false || m_LogSensorStates[key] == NULL || m_LogSensorStatesEnabled[key] == false )
//        return;

// common::EnvironmentTime measurementTime = state.getObservationTime();

    QString str;
    QTextStream stringWriter(&str, QIODevice::WriteOnly);
    stringWriter << "S|";
    stringWriter << state.getObservationTime().ToString() << "\t" << state.getObservationTime().ToString() << "\t" << key.sourceName << "\t" << key.sensorName << "\t" << key.measurementName << "|";
    stringWriter << state;
    stringWriter.flush();

    QTextStream out(m_LogSensorStates[key]);
    out << str;
}
