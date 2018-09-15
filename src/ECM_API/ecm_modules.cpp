#include "ecm_modules.h"

ECM_Modules::ECM_Modules(GalilMotionController* objGalil,
                         MunkPowerSupply* objMunk,
                         Westinghouse510* objPump):
    m_Galil(objGalil), m_Munk(objMunk), m_Pump(objPump)
{

}
