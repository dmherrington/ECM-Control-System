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

class GMC_SHARED_EXPORT galilMotionController : public QObject, public GalilStatusUpdate_Interface, public GalilCallback_StateInterface, public Comms::CommsEvents
{
    Q_OBJECT

public:
    galilMotionController();

    ~galilMotionController();

public:
    void openConnection(const std::string &address);
    void closeConnection();

public:
    //////////////////////////////////////////////////////////////
    /// Virtual methods allowed from Comms::CommsEvents
    //////////////////////////////////////////////////////////////
    void LinkConnected() const override;
    void LinkDisconnected() const override;
    void NewStatusInputs(const StatusInputs &status) override;
    void NewStatusPosition(const Status_Position &status) override;
    void NewStatusMotorEnabled(const Status_MotorEnabled &status) override;
    void NewStatusMotorInMotion(const Status_AxisInMotion &status) override;
    void NewStatusMotorStopCode(const Status_StopCode &status) override;

public:

    void getSettingsPath(std::string &settingsPath) const;
    bool saveSettings();
    bool saveSettingsAs(const std::string &filePath);
    bool loadSettings(const std::string &filePath);

    void getProgramPath(std::string &filePath) const;
    bool saveProgram(const std::string &text);
    bool saveProgramAs(const std::string &filePath, const std::string &text);
    bool loadProgram(const std::string &filePath, std::string &programText);

    void uploadProgram(const ProgramGeneric &program) const;

    void downloadProgram() const;

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
    void cbi_AbstractGalilRequest(const AbstractRequestPtr request) override;
    void cbi_GalilControllerGains(const CommandControllerGain &gains) override;

signals:
    void commsStatus(const bool &opened);

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

private:
    GCon galil; /**< Member variable containing a pointer to the Galil interface */

    GalilStateInterface* stateInterface; /**< Member variable containing the current state
information, settings, and callback information for the states within the HSM.*/

    hsm::StateMachine* stateMachine; /**< Member variable containing a pointer to the state
 machine. This state machine evolves the state per event updates and user commands either via
the GUI or information updates from the polled status of the galil. */

    GalilPollState* galilPolling; /**< Member variable that contains a threaded object consistently
 assessing and querying the state of the galil based on a timeout. This state should be paused when
uploading and/or downloading from the galil. */

private:
    GalilSettings m_Settings; /**< Value of the axis to be disabled */
};

#endif // GALIL_MOTION_CONTROLLER_H
