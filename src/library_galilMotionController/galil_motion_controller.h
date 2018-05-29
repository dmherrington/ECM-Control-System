#ifndef GALIL_MOTION_CONTROLLER_H
#define GALIL_MOTION_CONTROLLER_H

#include <QObject>
#include <QDir>
#include <QString>
#include <QTextStream>
#include <iostream>

#include <string>

#include "gclib.h"
#include "gclibo.h"

#include "library_galilmotioncontroller_global.h"

#include "common/tuple_profile_variable_string.h"
#include "common/tuple_positional_string.h"
#include "common/comms/communication_connection.h"

#include "data/motion_profile_variable_state.h"
#include "data/machine_positional_state.h"


#include "commands/command_components.h"
#include "requests/request_components.h"
#include "states/state_components.h"

#include "galil_parse_greturn.h"

#include "settings/galil_settings.h"

#include "galil_poll_status.h"
#include "galil_state_interface.h"

#include "programs/program_generic.h"

#include "communications/comms_marshaler.h"

/**
\* @file  galil_motion_controller.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is to control the Galil Motion Controller.
\*
\* @section DESCRIPTION
\*
\*
\*/

class GMC_SHARED_EXPORT GalilMotionController : public QObject, public GalilStatusUpdate_Interface, public GalilCallback_StateInterface, private Comms::CommsEvents
{
    Q_OBJECT

public:
    GalilMotionController(const std::string &name = "Galil Motion Controller");

    ~GalilMotionController();

public:
    void openConnection(const std::string &address);

    void closeConnection();

    std::string getCurrentMCState() const;

private:
    //////////////////////////////////////////////////////////////
    /// Virtual methods imposed via Comms::CommsEvents
    //////////////////////////////////////////////////////////////
    void LinkConnected() const override;
    void LinkDisconnected() const override;
    void ErrorBadCommand(const std::string &commandType, const std::string &description) override;
    void NewProgramUploaded(const ProgramGeneric &program) override;
    void NewProgramDownloaded(const ProgramGeneric &program) override;
    void NewStatusInputs(const StatusInputs &status) override;
    void NewStatusPosition(const Status_Position &status) override;
    void NewStatusMotorEnabled(const Status_MotorEnabled &status) override;
    void NewStatusMotorInMotion(const Status_AxisInMotion &status) override;
    void NewStatusMotorStopCode(const Status_StopCode &status) override;
    void NewStatusVariableList(const Status_VariableList &status) override;
    void NewStatusVariableValue(const Status_VariableValue &status) override;

public:
    void getSettingsPath(std::string &settingsPath) const;
    bool saveSettings();
    bool saveSettingsAs(const std::string &filePath);
    bool loadSettings(const std::string &filePath);

    void getProgramPath(std::string &filePath) const;
    bool saveProgram(const std::string &text);
    bool saveProgramAs(const std::string &filePath, const std::string &text);
    bool loadProgram(const std::string &filePath, std::string &programText);

    void executeCommand(const AbstractCommand* command);

    void executeStringCommand(const std::string &stringCommand);

    ///////////////////////////////////////////////////////////////////////////////////////////////
    /// Callback Interfafce as required from inheritance of GalilStatusUpdate_Interface
    ///////////////////////////////////////////////////////////////////////////////////////////////
private:
    void cbi_GalilStatusRequest(const AbstractRequestPtr request) override;

    ///////////////////////////////////////////////////////////////////////////////////////////////
    /// Callback Interfafce as required from inheritance of GalilCallback_StateInterface
    ///////////////////////////////////////////////////////////////////////////////////////////////
private:
    void cbi_AbstractGalilCommand(const AbstractCommandPtr command) override;
    void cbi_AbstractGalilMotionCommand(const AbstractCommandPtr command) override;
    void cbi_AbstractGalilRequest(const AbstractRequestPtr request) override;
    void cbi_AbstractGalilAddPolled(const AbstractRequestPtr request) override;
    void cbi_AbstractGalilRemovePolled(const std::string &name) override;
    void cbi_GalilControllerGains(const CommandControllerGain &gains) override;
    void cbi_GalilHomeIndicated(const bool &indicated) override;
    void cbi_NewMotionProfileState(const MotionProfileState &state) override;
    void cbi_GalilNewMachineState(const std::string &state) override;
    void cbi_GalilUploadProgram(const AbstractCommandPtr command) override;
    void cbi_GalilDownloadProgram(const AbstractCommandPtr command) override;

signals:
    /**<
     * The following signals are pertinent to handling events that may have interest in logging.
     */

    //!
    //! \brief signal_MCNewPoition
    //! \param tuple
    //! \param data
    //!
    void signal_MCNewPoition(const common::TuplePositionalString &tuple, const common_data::MachinePositionalState &data) const;

    //!
    //! \brief signal_MCNewProfileVariableValue
    //! \param variableTuple
    //! \param data
    //!
    void signal_MCNewProfileVariableValue(const common::TupleProfileVariableString &variableTuple, const common_data::MotionProfileVariableState &data) const;


    void signal_MotionControllerConnectionUpdate(const common::comms::CommunicationConnection &connection) const;


    void signal_MCNewMotionState(const std::string &state) const;

    void signal_GalilHomeIndicated(const bool &indicated) const;

    void signal_GalilUpdatedProfileState(const MotionProfileState &state) const;


    void newProgramReceived(const std::string &programText);

    void currentErrorCode(const std::string &errorString);


private:
    QString profilesPath;
    QString programPath;
    QString settingsPath;

public:
    Comms::CommsMarshaler* commsMarshaler; /**< Member variable handling the communications with the
actual Galil unit. This parent class will be subscribing to published events from the marshaller. This
should drive the event driven structure required to exceite the state machine.*/

    GalilStateInterface* stateInterface; /**< Member variable containing the current state
information, settings, and callback information for the states within the HSM.*/

private:
    GCon galil; /**< Member variable containing a pointer to the Galil interface */

    hsm::StateMachine* stateMachine; /**< Member variable containing a pointer to the state
 machine. This state machine evolves the state per event updates and user commands either via
the GUI or information updates from the polled status of the galil. */

    GalilPollState* galilPolling; /**< Member variable that contains a threaded object consistently
 assessing and querying the state of the galil based on a timeout. This state should be paused when
uploading and/or downloading from the galil. */

private:
    GalilSettings m_Settings; /**< Value of the axis to be disabled */

    std::string deviceName;
};

#endif // GALIL_MOTION_CONTROLLER_H
