#ifndef ECM_API_H
#define ECM_API_H

#include <QObject>

#include "ecm_api_global.h"
#include "common/ecm_devices.h"
#include "common/execution_properties.h"

#include "graphing/graphing_global.h"

#include "library_munk_power_supply/munk_power_supply.h"
#include "library_SPIIMotionController/spii_motion_controller.h"
#include "library_sensoray/sensoray.h"
#include "library_rigol_oscilloscope/rigol_oscilliscope.h"
#include "library_westinghouse510/westinghouse_510.h"
#include "library_qModBus/library_qmodbus.h"

#include "ecm_logging.h"

#include "commands/ecm_command_profile_pause.h"
#include "commands/ecm_command_execute_collection.h"
#include "commands/ecm_command_profile_collection.h"

#include "states/state_ecm_types.h"

#include "common/notification_update.h"

ECM_CLASS_FORWARD(ECM_API);

class ECM_APISHARED_EXPORT ECM_API: public QObject
{
    Q_OBJECT

public:
    ECM_API();

    ~ECM_API() = default;

public:
    void initializeProfileConfiguration(const ECMCommand_ProfileConfiguration &config);
    void onProfileCollectionInitialized(const bool &success, const ECMCommand_ProfileCollection &config);

public:
    void action_StopMachine();

    void action_EStopMachine();

public:

    bool checkLoggingPathValidity(const std::string &partNumber, const std::string &serialNumber) const;

    void initializeOperationalCollection(const ECMCommand_ExecuteCollectionPtr executionCollection, const bool &clearContents);

    void initializeLoggingOperation(const std::string &partNumber, const std::string &serialNumber,
                                 const ECMCommand_AbstractProfileConfigPtr configuration, const std::string &description = "");

    void logCurrentOperationalSettings();

    void writeToLogStartingPosition();

    void beginLoggingOperationalData(const ProfileOpType &type);

    void beginOperationalProfile(const ECMCommand_AbstractProfileConfigPtr profileConfig,
                                 const ExecutionProperties::ExecutionCondition &condition = ExecutionProperties::ExecutionCondition::BEGINNING);

    void executeExplicitProfile(const ECMCommand_ProfileConfigurationPtr profileConfig);

    void executePauseProfile(const ECMCommand_ProfilePausePtr profileConfig);

    void concludeExecutingCollection(const ECMCommand_ExecuteCollectionPtr executionCollection);

    void concludeExecutingOperation(const ECMCommand_AbstractProfileConfigPtr profileConfig);

    void notifyNewOuterState(const ECM::API::ECMState &state, const std::string &stateString);

    void notifyPausedEvent(const std::string notificationText);

private:
    void writeHeaderBreaker(std::string &logString, const unsigned int &size) const;

    std::map<std::string, std::string> getSoftwareVersions() const;

signals:
    void signal_NewOuterState(const ECM::API::ECMState &state, const std::string &stateString);
    void signal_InPauseEvent(const std::string notificationText);
    void signal_ExecutingCollection(const ExecutionProperties &props);
    void signal_ExecutingOperation(const ExecuteOperationProperties &props);

    void signal_APINotification(const NotificationUpdate &update);

private slots:
    void slot_NewSensorData(const common::TupleSensorString &sensorTuple, const common_data::SensorState &data);

public:

    RigolOscilliscope* m_Rigol;

    MunkPowerSupply* m_Munk;

    SPIIMotionController* m_MotionController;

    //GalilMotionController* m_Galil;

    Sensoray* m_Sensoray;

    Westinghouse510* m_Pump;

    ECMLogging* m_Log;

    Library_QModBus* m_Modbus485;

};

#endif // ECM_API_H
