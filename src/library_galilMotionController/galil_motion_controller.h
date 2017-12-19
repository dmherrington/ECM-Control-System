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

class GMC_SHARED_EXPORT galilMotionController : public QObject
{
    Q_OBJECT

public:
    galilMotionController();

    ~galilMotionController();

public:
    void openConnection(const std::string &address);

    void closeConnection();

public:

    void getSettingsPath(std::string &settingsPath) const;
    bool saveSettings();
    bool saveSettingsAs(const std::string &filePath);
    bool loadSettings(const std::string &filePath);

    void getProgramPath(std::string &filePath) const;
    bool saveProgram(const std::string &text);
    bool saveProgramAs(const std::string &filePath, const std::string &text);
    bool loadProgram(const std::string &filePath, std::string &programText);

    void uploadProgram(const std::string &programText);

    void downloadProgram(std::string &programText);

    void executeCommand(const AbstractCommand* command);

    void executeStringCommand(const std::string &stringCommand);

    void handleRequests(const AbstractRequest* request);

signals:
    void commsStatus(const bool &opened);

    void newProgramReceived(const std::string &programText);

    void currentErrorCode(const std::string &errorString);


private:
    QString settingsPath;
    QString programPath;

private:
    GCon galil; /**< Member variable containing a pointer to the Galil interface */

    GalilStateInterface* stateInterface; /**< Member variable containing the current state
information, settings, and callback information for the states within the HSM.*/

    hsm::StateMachine* stateMachine; /**< Member variable containing a pointer to the state
 machine. This state machine evolves the state per event updates and user commands either via
the GUI or information updates from the polled status of the galil. */

    GalilPollState* galilPolling; /**< Member variable that contains a threaded object consistently
 assessing and querying the state of the galil based on a timeout.*/

private:
    GalilSettings m_Settings; /**< Value of the axis to be disabled */
};

#endif // GALIL_MOTION_CONTROLLER_H
