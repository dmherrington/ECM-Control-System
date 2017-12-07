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

#include "galil_parse_greturn.h"
#include "settings/galil_settings.h"

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

    ~galilMotionController() = default;

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

signals:
    void commsStatus(const bool &opened);

    void newProgramReceived(const std::string &programText);

    void currentErrorCode(const std::string &errorString);

private:
    QString settingsPath;
    QString programPath;
private:
    GCon mConnection;
    GalilSettings m_Settings;
};

#endif // GALIL_MOTION_CONTROLLER_H
