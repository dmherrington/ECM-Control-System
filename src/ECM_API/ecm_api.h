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

class ECM_APISHARED_EXPORT ECM_API: public QObject
{
    Q_OBJECT

public:
    ECM_API();

    ~ECM_API() = default;

public:
    void action_StopMachine();

public:
    void initializeECMLogs(const string &partNumber, const string &serialNumber, const common::EnvironmentTime &time, bool clearContents = true);

signals:
    void signal_LockMotionButtons(const bool &lock);

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

    //!
    //! \brief slot_MCNewMotionState
    //! \param state
    //! \param stateString
    //!
    void slot_MCNewMotionState(const ECM::Galil::GalilState &state, const std::string &stateString);

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
