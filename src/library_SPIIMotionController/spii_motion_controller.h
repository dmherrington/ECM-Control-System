#ifndef SPII_MOTION_CONTROLLER_H
#define SPII_MOTION_CONTROLLER_H

#include <QObject>

#include <mutex>

#include "ACSC.h"

#include "library_spiimotioncontroller_global.h"

#include "common/hsm.h"
#include "common/commands/command_components.h"

#include "communications/comms_marshaler.h"

#include "spii_poll_machine.h"
#include "spii_state_interface.h"
#include "data/motion_profile_state.h"


#include "states/state_components.h"

class LIBRARY_SPIIMOTIONCONTROLLERSHARED_EXPORT SPIIMotionController : public QObject,
        private Comms::CommsEvents, private SPIIPollingEvents_Interface
{
    Q_OBJECT

public:
    SPIIMotionController();

    ~SPIIMotionController() override;

    std::vector<common::TupleECMData> getPlottables() const;

public:
    void executeCommand(const AbstractCommandPtr command);

public:
    void ConnectToSimulation();
    void ConnectToSerialPort(const common::comms::SerialConfiguration &linkConfig);
    void ConnectToEthernetPort(const common::comms::TCPConfiguration &linkConfig);
    void ConnectToPCIPort(const ACSC_PCI_SLOT &linkConfig);

    void closeConnection();

    bool isDeviceConnected() const;

    void LinkConnectionUpdate(const common::comms::CommunicationUpdate &update) override;

private:
    void initializeMotionController();

    private:

    void SPIIPolling_PositionUpdate(const std::vector<SPII::Status_PositionPerAxis> &position) override;

    void SPIIPolling_AxisUpdate(const std::vector<SPII::Status_PerAxis> &axis) override;

    void SPIIPolling_MotorUpdate(const std::vector<SPII::Status_MotorPerAxis> &motor) override;

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
