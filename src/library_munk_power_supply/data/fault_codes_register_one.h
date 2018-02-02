#ifndef FAULT_CODES_REGISTER_ONE_H
#define FAULT_CODES_REGISTER_ONE_H

#include <string>
#include <stdexcept>
#include <vector>

namespace Data
{

//!
//! \brief The FaultCodesRegister1 enum
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

inline std::string FaultCodesRegister1ToString(const FaultCodesRegister1 &type) {
    switch (type) {
    case FaultCodesRegister1::ERR_FR1_DCLINK_OFF:
        return "DClink off input was activated.";
    case FaultCodesRegister1::ERR_FR1_DSP_PWM1_GENERATOR:
        return "DSP did not find PWM generator #1.";
    case FaultCodesRegister1::ERR_FR1_DSP_PWM2_GENERATOR:
        return "DSP did not find PWM generator #2.";
    case FaultCodesRegister1::ERR_FR1_DSP_ERROR:
        return "DSP does not respond to run command or DSP not responding.";
    case FaultCodesRegister1::ERR_FR1_DSP_PIC_DEAD:
        return "DSP noticed that he IO controller does not respond";
    case FaultCodesRegister1::ERR_FR1_DSP_TICKCOUNT_ERROR:
        return "DSP tickcounter does not change (DSP does not run) Fatal not resettable.";
    case FaultCodesRegister1::ERR_FR1_INTERNAL_ERROR:
        return "An internal error occurred.";
    case FaultCodesRegister1::ERR_FR1_EXTCOMM2:
        return "No communication found to PC/PLC on control board com-port 2.";
    case FaultCodesRegister1::ERR_FR1_CHARGING:
        return "Error charging the DC-link.";
    case FaultCodesRegister1::ERR_FR1_TEMP_POWERBOARD:
        return "Overtemperature of Powerboard.";
    case FaultCodesRegister1::ERR_FR1_EXTCOMM1:
        return "No communication found to PC/PLC on control board com-port 1.";
    case FaultCodesRegister1::ERR_FR1_SYNCHRO:
        return "Synchronization lost. (Only supported when supply is in 'Slave' mode).";
    case FaultCodesRegister1::ERR_FR1_TEMP_MAINSCONTROLLER:
        return "Mains controller overtemperature";
    case FaultCodesRegister1::ERR_FR1_ZEROBATCH:
        return "Attempted to start a 'Zero Batch' or 'Zero Pattern'";
    case FaultCodesRegister1::ERR_FR1_GENERAL_OVERCURRENT:
        return "Active if any output has an over current or hardware overcurrent trip (All trips OR-ed).";
    case FaultCodesRegister1::ERR_FR1_GENERAL_OVERVOLTAGE:
        return "Active if any output has an over voltage trip (All trips OR-ed).";
    default:
        throw std::runtime_error("Unknown fault code from register 1 seen.");
    }
}


} //end of namespace Data
#endif // FAULT_CODES_REGISTER_ONE_H
