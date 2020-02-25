#ifndef SPII_MOTION_CONTROLLER_H
#define SPII_MOTION_CONTROLLER_H

#include <QObject>

#include <mutex>

#include "ACSC.h"

#include "library_spiimotioncontroller_global.h"

#include "common/axis_settings.h"
#include "common/hsm.h"
#include "common/commands/command_components.h"

#include "communications/comms_marshaler.h"

#include "spii_poll_machine.h"
#include "spii_state_interface.h"
#include "data/motion_profile_state.h"

#include "buffers/spii_buffer_manager.h"

#include "states/state_components.h"
#include "status/status_components.h"

#include "data/machine_positional_state.h"

#include "spii_state_interface.h"
#include "spii_device_interface_motion_control.h"

#include "common/notification_update.h"

class LIBRARY_SPIIMOTIONCONTROLLERSHARED_EXPORT SPIIMotionController : public QObject,
        private Comms::CommsEvents, private SPIIPollingEvents_Interface, public SPIIDeviceInterface_MotionControl,
        public SPIICallback_StateInterface
{
    Q_OBJECT

public:
    SPIIMotionController(const AxisSettings &settings);

    ~SPIIMotionController() override;

    BufferData retrieveBufferData(const unsigned int &bufferIndex);

public:
    ECM::SPII::SPIIState getCurrentMCState() const;

    std::vector<common::TupleECMData> getPlottables() const;

public:
    void executeCommand(const AbstractCommandPtr command);
    void executeCustomCommands(const std::vector<std::string> &stringCommands);
    void executeSynchronizationRequest();

    void setAxesSettings(const AxisSettings &settings);
    void enableAvailableAxes();
    void disableAvailableAxes();

public:
    void ConnectToSimulation();
    void ConnectToSerialPort(const common::comms::SerialConfiguration &linkConfig);
    void ConnectToEthernetPort(const common::comms::TCPConfiguration &linkConfig);
    void ConnectToPCIPort(const ACSC_PCI_SLOT &linkConfig);
    void closeConnection();

    bool isDeviceConnected() const;
    void getSPIIProperties(unsigned int &numAxis, unsigned int &numBuffers, unsigned int &dBufferIndex) const;

    void LinkConnectionUpdate(const common::comms::CommunicationUpdate &update) override;

public:
    void cbi_AbstractSPIICommand(const AbstractCommandPtr command) override;
    void cbi_AbstractSPIIMotionCommand(const AbstractCommandPtr command) override;
    void cbi_AbstractSPIIRequest(const AbstractRequestPtr request) override;
    void cbi_AbstractSPIIAddPolled(const AbstractRequestPtr request, const int &period) override;
    void cbi_AbstractSPIIRemovePolled(const common::TupleECMData &tuple) override;
    void cbi_SPIIControllerGains(const CommandControllerGain &gains) override;

    void cbi_SPIIHomeIndicated(const bool &indicated) override;
    void cbi_SPIITouchoffIndicated(const bool &indicated) override;
    void cbi_SPIIMotionProfileState(const MotionProfileState &state, const bool &processTransitions) override;
    void cbi_SPIINewMachineState(const ECM::SPII::SPIIState &state) override;
    void cbi_SPIINotificationUpdate(const common::NotificationUpdate &update) override;

    void cbi_SPIIUploadProgram(const AbstractCommandPtr command) override;
    void cbi_SPIIDownloadProgram(const AbstractCommandPtr command) override;


    //////////////////////////////////////////////////////////////
    /// Virtual methods overriden from Comms::CommsEvents
    //////////////////////////////////////////////////////////////
private:
    void NewBufferState(const Status_BufferState &state) override;
    void NewBuffer_ProgramSuite(const bool &success, const SPII_CurrentProgram &program) override;
    void NewBuffer_AvailableData(const BufferData &bufferData) override;
    void NewStatus_OperationalLabels(const Operation_LabelList &labelList) override;
    void NewStatus_PrivateOperationalVariables(const bool &success, const Operation_VariableList &variableList) override;
    void NewStatus_UploadedOperationalVariables(const bool &success, const Operation_VariableList &variableList) override;
    void NewStatus_UserOperationalVariables(const bool &success, const Operation_VariableList &variableList) override;
    void NewStatus_CustomCommandReceived(const std::string &command, const std::string &response) override;


private:
    void initializeMotionController();

    void setupRequestQueue(const std::vector<MotorAxis> &currentAxes);

private:

    void SPIIPolling_PositionUpdate(const std::vector<Status_PositionPerAxis> &position) override;

    void SPIIPolling_AxisUpdate(const std::vector<Status_PerAxis> &axis) override;

    void SPIIPolling_AxisSafetyUpdate(const std::vector<Status_AxisSafety> &axis) override;

    void SPIIPolling_MotorUpdate(const std::vector<Status_MotorPerAxis> &motor) override;

    void SPIIPolling_VariableUpdate(const std::vector<Status_VariableValue> &variable) override;

    void SPIIPolling_MotorFaultUpdate(const std::vector<Status_MotorAxisFault> &motor) override;

    void SPIIPolling_SystemFaultUpdate(const Status_SystemFault &status) override;

    void SPIIPolling_UnsolicitedMsgs(const std::vector<std::string> &msgs) override;


signals:

    //!
    //! \brief signal_MotionControllerCommunicationUpdate
    //! \param connection
    //!
    void signal_MCCommunicationUpdate(const common::comms::CommunicationUpdate &connection) const;


    //!
    //! \brief signal_MCNewMotionState signal emitted when the state machine has progressed to a new state
    //! \param state string descriptor describing the state the galil motion controller is in
    //!
    void signal_MCNewMotionState(const ECM::SPII::SPIIState &state, const QString &stateString) const;

    //!
    //! \brief signal_MCBufferUpdate
    //! \param state
    //!
    void signal_MCBufferUpdate(const Status_BufferState &state);

signals:
    void signal_MCNewProgramLabelList(const Operation_LabelList &labelList);

    void signal_MCNewProgramVariableList(const Operation_VariableList &variableList);

    void signal_MCNewUserVariableList(const Operation_VariableList &variableList);


    //!
    //! \brief signal_MCNewPoition
    //! \param tuple
    //! \param data
    //!
    void signal_MCNewPosition(const common::TuplePositionalString &tuple, const common_data::MachinePositionalState &data, const bool &valueChanged) const;


signals:

    //!
    //! \brief signal_GalilHomeIndicated
    //! \param indicated
    //!
    void signal_MCHomeIndicated(const bool &indicated) const;

    //!
    //! \brief signal_GalilTouchoffIndicated
    //! \param indicated
    //!
    void signal_MCTouchoffIndicated(const bool &indicated) const;

    //!
    //! \brief signal_MCNewPositionalPlottable
    //! \param variableTuple
    //! \param on_off
    //!
    void signal_MCNewPositionalPlottable(const common::TuplePositionalString &variableTuple, const bool &on_off);

    //!
    //! \brief signal_MCNewVariablePlottable
    //! \param variableTuple
    //! \param on_off
    //!
    void signal_MCNewVariablePlottable(const common::TupleProfileVariableString &variableTuple, const bool &on_off);

    //!
    //! \brief signal_MCNewProfileVariableValue
    //! \param variableTuple
    //! \param data
    //!
    void signal_MCNewProfileVariableValue(const common::TupleProfileVariableString &variableTuple, const common_data::MotionProfileVariableState &data) const;

    void signal_MCUpdatedProfileState(const MotionProfileState &state) const;

    void signal_ErrorCommandCode(const CommandType &type, const std::string &errorString);

    void signal_ErrorRequestCode(const RequestTypes &type, const std::string &errorString);

    void signal_CustomUserRequestReceived(const std::string &request, const std::string &response);

    void signal_MCNotification(const common::NotificationUpdate &update);

    void signal_ESTOPTriggered(const bool &isTriggered);

public:
    std::shared_ptr<Comms::CommsMarshaler> m_CommsMarshaler; /**< Member variable handling the communications with the
actual Galil unit. This parent class will be subscribing to published events from the marshaller. This
should drive the event driven structure required to exceite the state machine.*/

    SPIIStateInterface* m_StateInterface; /**< Member variable containing the current state
information, settings, and callback information for the states within the HSM.*/

private:
    SPII_Settings m_SPIIDevice; /**< Member variable containing a pointer to the Galil interface */

    SPIIPollMachine* m_DevicePolling; /**< Member variable that contains a threaded object consistently
 assessing and querying the state of the galil based on a timeout. This state should be paused when
uploading and/or downloading from the galil. */


private:
    void ProgressStateMachineStates();
    std::mutex m_Mutex_StateMachine;
    hsm::StateMachine* stateMachine; /**< Member variable containing a pointer to the state
 machine. This state machine evolves the state per event updates and user commands either via
the GUI or information updates from the polled status of the galil. */

    MotionProfileState newState;
};

#endif // SPII_MOTION_CONTROLLER_H
