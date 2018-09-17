#ifndef ECM_MODULES_H
#define ECM_MODULES_H

#include "library_galilMotionController/galil_motion_controller.h"
#include "library_munk_power_supply/munk_power_supply.h"
#include "library_westinghouse510/westinghouse_510.h"

class ECM_Modules
{
public:
    ECM_Modules(GalilMotionController* objGalil,
                MunkPowerSupply* objMunk,
                Westinghouse510* objPump);


private:
    GalilMotionController* m_Galil;

    MunkPowerSupply* m_Munk;

    Westinghouse510* m_Pump;
};

#endif // ECM_MODULES_H
