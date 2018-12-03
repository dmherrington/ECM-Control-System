#ifndef ECM_LOGGING_H
#define ECM_LOGGING_H

#include <QFile>
#include <QDir>
#include <QMap>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "common/environment_time.h"
#include "common/tuple_sensor_string.h"
#include "common/tuple_profile_variable_string.h"
#include "common/tuple_positional_string.h"

#include "data/sensor_state.h"
#include "data/motion_profile_variable_state.h"
#include "data/machine_positional_state.h"

#include "data/profiles/profile_state_machining.h"

#include "commands/ecm_command_execute_collection.h"
#include "commands/ecm_command_profile_collection.h"

#include <iostream>

class ECMLogging
{
public:
    ECMLogging(const std::map<std::string, std::string> &softwareVersions);

    bool checkLoggingPath(const string &partNumber, const std::string &serialNumber) const;

    void writeExecutionCollection(const ECMCommand_ExecuteCollection &collection);

    void initializeLogging(const string &partNumber, const std::string &serialNumber, bool clearContents = true);

    void writeLoggingHeader(const std::string &partNumber, const std::string &serialNumber, const std::string &operationName,
                            const std::string &profileName, const std::string &operationalSettings, const std::string &descriptor,
                            const common::EnvironmentTime &time);


    void enableLogging(const bool &enable);

    std::string getLoggingPath() const;

    void setLoggingRelativeTime(const bool &value);

    bool isLoggingRelativeTime() const;

    void setLoggingStartTime(const common::EnvironmentTime &time);

    //!
    //! \brief WriteLogProfileVariableState
    //! \param key
    //! \param state
    //!
    void WriteLogMachinePositionalState(const common::TuplePositionalString &key, const common_data::MachinePositionalState &state);

    /*!
     * \brief WriteLogProfileVariableState
     * \param key
     * \param state
     */
    void WriteLogProfileVariableState(const common::TupleProfileVariableString &key, const common_data::MotionProfileVariableState &state);

    //!
    //! \brief Write data bout sensor state to log
    //! \param sensorKey Sensor component
    //! \param state Data on component
    //!
    void WriteLogSensorState(const common::TupleSensorString &key, const common_data::SensorState &state);

    void SetSensorLogFile(const common::TupleSensorString &key);


    void CloseMachiningLog(const common::EnvironmentTime &time, const ProfileState_Machining::MACHININGProfileCodes &completionCode);

private:
    void WriteLogSoftwareVersions(QTextStream &stringWriter);

    std::string WriteHeaderBreaker(const unsigned int &size);

private:
    bool isComponentLogging() const;

protected:

    QFile* masterLog;

    QFile* configurationFile;

    bool logReglativeTime = false;

    bool loggingInitialized = false;

    bool loggingEnabled = false;

    common::EnvironmentTime startLogTime;

    //! Map of sensors to log
    QMap<common::TupleProfileVariableString, QFile*> m_LogProfileVariableStates;

    //! Map of sensors to log
    QMap<common::TupleSensorString, QFile*> m_LogSensorStates;

    //! Map indicating if logging the sensor state is enabled
    QMap<common::TupleSensorString, bool> m_LogSensorStatesEnabled;

private:
    std::string loggingPath;

    std::map<std::string, std::string> softwareVersioningMap;

};

#endif // ECM_LOGGING_H
