#ifndef ECM_MODULES_H
#define ECM_MODULES_H

#include "library_galilMotionController/galil_motion_controller.h"

class ECM_Modules
{
public:
    ECM_Modules(GalilMotionController* objGalil);


private:
    GalilMotionController* m_Galil;

};

#endif // ECM_MODULES_H
