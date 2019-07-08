#include <QCoreApplication>
#include <iostream>

#include <conio.h>

#include "ACSC.h"

#include <cstring>

#include "library_SPIIMotionController/spii_motion_controller.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SPIIMotionController* newController = new SPIIMotionController();
    newController->ConnectToSimulation();

    return a.exec();
}
