#ifndef SPII_MOTION_CONTROLLER_H
#define SPII_MOTION_CONTROLLER_H

#include <mutex>

#include "ACSC.h"

#include "library_spiimotioncontroller_global.h"

#include "common/hsm.h"

#include "communications/comms_marshaler.h"

class LIBRARY_SPIIMOTIONCONTROLLERSHARED_EXPORT SPIIMotionController
{

public:
    SPIIMotionController();

    ~SPIIMotionController();

    std::vector<common::TupleECMData> getPlottables() const;

    void initializeMotionController();

public:
    void openConnection(const std::string &address);

public:
    void ConnectToSimulation();
    void ConnectToSerialPort(const common::comms::SerialConfiguration &linkConfig);
    void ConnectToEthernetPort(const common::comms::TCPConfiguration &linkConfig);
    void ConnectToPCIPort(const ACSC_PCI_SLOT &linkConfig);

    void closeConnection();

    bool isDeviceConnected() const;

public:
    Comms::CommsMarshaler* commsMarshaler; /**< Member variable handling the communications with the
actual Galil unit. This parent class will be subscribing to published events from the marshaller. This
should drive the event driven structure required to exceite the state machine.*/

    SPIIStateInterface* stateInterface; /**< Member variable containing the current state
information, settings, and callback information for the states within the HSM.*/

private:
    HANDLE SPIIDevice; /**< Member variable containing a pointer to the Galil interface */

    SPIIPollMachine* galilPolling; /**< Member variable that contains a threaded object consistently
 assessing and querying the state of the galil based on a timeout. This state should be paused when
uploading and/or downloading from the galil. */


private:
    void ProgressStateMachineStates();
    std::mutex m_Mutex_StateMachine;
    hsm::StateMachine* stateMachine; /**< Member variable containing a pointer to the state
 machine. This state machine evolves the state per event updates and user commands either via
the GUI or information updates from the polled status of the galil. */


};

#endif // SPII_MOTION_CONTROLLER_H
