#ifndef GALIL_MOTION_CONTROLLER_H
#define GALIL_MOTION_CONTROLLER_H

#include <QDir>
#include <QString>
#include <QTextStream>
#include <string>

#include "library_galilmotioncontroller_global.h"

#include "gclib.h"


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

class GMC_SHARED_EXPORT galilMotionController
{

public:
    galilMotionController();

    ~galilMotionController() = default;

public:
    void openConnection(const std::string &address);

    void closeConnection();

public:
    bool saveProgram(const std::string &text);

    bool saveProgramAs(const std::string &filePath, const std::string &text);

    bool loadProgram(const std::string &filePath, std::string &programText);

    void uploadProgram(const std::string &programText);

    void downloadProgram(std::string &programText);

signals:
    void newProgramReceived(const std::string &programText);


private:
    GCon mConnection;
};

#endif // GALIL_MOTION_CONTROLLER_H
