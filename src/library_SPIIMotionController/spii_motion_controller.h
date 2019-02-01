#ifndef SPII_MOTION_CONTROLLER_H
#define SPII_MOTION_CONTROLLER_H

#include "ACSC.h"

#include "library_spiimotioncontroller_global.h"

class LIBRARY_SPIIMOTIONCONTROLLERSHARED_EXPORT SPIIMotionController
{

public:
    SPIIMotionController();


public:
    void ConnectToSimulation();
    void ConnectToSerialPort(const common::comms::SerialConfiguration &linkConfig);
    void ConnectToEthernetPort(const common::comms::TCPConfiguration &linkConfig);
    void ConnectToPCIPort(const ACSC_PCI_SLOT &linkConfig);

};

#endif // SPII_MOTION_CONTROLLER_H
