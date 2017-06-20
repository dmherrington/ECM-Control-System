#ifndef FAULT_CODES_REGISTER_ONE_H
#define FAULT_CODES_REGISTER_ONE_H


#include <string>
#include <stdexcept>
#include <vector>

namespace Data
{

//!
//! \brief The CurrentFactorType enum
//!
enum class FaultCodesRegister1{
    ERR_FR1_DCLINK_OFF = 1, /**< */
    ERR_FR1_DSP_PWM1_GENERATOR = 2, /**< */
    ERR_FR1_DSP_PWM2_GENERATOR = 4, /**< */
    ERR_FR1_DSP_ERROR = 8, /**< */
    ERR_FR1_DSP_PIC_DEAD = 16, /**< */
    ERR_FR1_DSP_TICKCOUNT_ERROR = 32, /**< */
    ERR_FR1_INTERNAL_ERROR = 64, /**< */
    ERR_FR1_EXTCOMM2 = 128, /**< */
    ERR_FR1_CHARGING = 256, /**< */
    ERR_FR1_TEMP_POWERBOARD = 512, /**< */
    ERR_FR1_EXTCOMM1 = 1024, /**< */
    ERR_FR1_SYNCHRO = 2048, /**< */
    ERR_FR1_TEMP_MAINSCONTROLLER = 4096, /**< */
    ERR_FR1_ZEROBATCH = 8192, /**< */
    ERR_FR1_GENERAL_OVERCURRENT = 16384, /**< */
    ERR_FR1_GENERAL_OVERVOLTAGE = 32768 /**< */

};

} //end of namespace Data
#endif // FAULT_CODES_REGISTER_ONE_H
