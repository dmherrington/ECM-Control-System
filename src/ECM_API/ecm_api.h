#ifndef ECM_API_H
#define ECM_API_H

#include <QObject>

#include "ecm_api_global.h"
#include "common/ecm_devices.h"
#include "graphing/graphing_global.h"

#include "library_munk_power_supply/munk_power_supply.h"
#include "library_galilMotionController/galil_motion_controller.h"
#include "library_sensoray/sensoray.h"
#include "library_rigol_oscilloscope/rigol_oscilliscope.h"
#include "library_westinghouse510/westinghouse_510.h"
#include "library_qModBus/library_qmodbus.h"

#include "ecm_logging.h"
#include "ecm_modules.h"

#include "commands/ecm_command_execute_collection.h"
#include "commands/ecm_command_profile_collection.h"

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

public:

    bool checkLoggingPathValidity(const std::string &partNumber, const std::string &serialNumber) const;

    void initializeECMLogs(const ECMCommand_ExecuteCollection &executionCollection, const bool &clearContents,
                           const std::string &descriptor = "");

    void executeMachiningProcess(const ECMCommand_ProfileConfiguration &profileConfig);

    void concludeMachiningProcess(const ECMCommand_ProfileConfiguration &profileConfig);

private:
    void writeHeaderBreaker(std::string &logString, const unsigned int &size) const;

    std::map<std::string, std::string> getSoftwareVersions() const;

signals:
    void signal_ExecutingProfile(const std::string operationName, const common::EnvironmentTime &time);

    void signal_MCNewMotionState(const std::string &stateString);

private slots:

    //!
    //! \brief slot_MotionControllerCommunicationUpdate
    //! \param update
    //!
    void slot_MotionControllerCommunicationUpdate(const common::comms::CommunicationUpdate &update);

    //!
    //! \brief slot_UpdateMotionProfileState
    //! \param state
    //!
    void slot_UpdateMotionProfileState(const MotionProfileState &state);


public:

    RigolOscilliscope* m_Rigol;

    MunkPowerSupply* m_Munk;

    GalilMotionController* m_Galil;

    Sensoray* m_Sensoray;

    Westinghouse510* m_Pump;

    ECMLogging* m_Log;

    Library_QModBus* m_Modbus485;

};

#endif // ECM_API_H
