#include "ecm_api.h"

ECM_API::ECM_API()
{
    m_Rigol = new RigolOscilliscope();

    m_Munk = new MunkPowerSupply();

    m_Galil = new GalilMotionController();

    m_Sensoray = new Sensoray();
    m_Pump = new Westinghouse510(m_Sensoray,01);
}
