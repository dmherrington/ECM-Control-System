#ifndef FAULT_CODES_REGISTER_TWO_H
#define FAULT_CODES_REGISTER_TWO_H

#include <string>
#include <stdexcept>
#include <vector>


namespace data_Munk{

//!
//! \brief The CurrentFactorType enum
//!
enum class FaultCodesRegister2{
    ERR_FR2_AMPHOURCHECKSUM = 1, /**<AmpHour variables are corrupt */
    ERR_FR2_INT_EEPROM = 2, /**<Internal eeprom data invalid */
    ERR_FR2_EXT_EEPROM = 4, /**<External eeprom data invalid */
    ERR_FR2_EEPROM_FORMAT = 8, /**<Eeprom has been formatted (Format operation=0010) */
    ERR_FR2_BATCH_READ = 16, /**<Crc check invaldid when reading batch from eeprom or BatchReadCommand (prm 4210) > 16 */
    ERR_FR2_BATCH_WRITE = 32, /**<Pattern No (prm 4200) zero when writing the batch to memory/eeporm or BatchWriteCommand (prm 4211) > 16. */
    ERR_FR2_PATTERN_READ = 64, /**<Crc check invalid when reading pattern from eeprom or PatReadCommand (prm 4190) > 16 */
    ERR_FR2_PATTERN_WRITE = 128, /**<Pattern set invalid when writing to memory/eeprom or BatchWriteCommand (prm 4191) > 16 */
    ERR_FR2_IDCLINK_IXT_TRIP1 = 256, /**<Tripped on primary DClink current Ixt */
    ERR_FR2_CONTROLSUPPLY = 512, /**<Control voltage timed out on threshold of CtrlVoltageThreshold parameter (9200) */
    ERR_FR2_DCLINK1 = 1024, /**<Primary Dclink voltage too low */
    ERR_FR2_PLD_1_5_SUPPLY = 2048, /**<DSP measured that the 1.5V supply of the PWM generators (PLD's) are too low */
    ERR_FR2_IDCLINK_IXT_TRIP2 = 4096, /**<Tripped on secundary DClink current Ixt */
    ERR_FR2_DCLINK2 = 8192, /**<Secundary Dclink voltage too low */
    ERR_FR2_RESERVED = 16384, /**< */
    ERR_FR2_SET_CURRENT_EXCEEDED = 32768 /**<Current set point value is too high */
};

inline std::string FaultCodesRegister2ToString(const FaultCodesRegister2 &type) {
    switch (type) {
    case FaultCodesRegister2::ERR_FR2_AMPHOURCHECKSUM:
        return "AmpHour variables are corrupt.";
    case FaultCodesRegister2::ERR_FR2_INT_EEPROM:
        return "Internal eeprom data invalid.";
    case FaultCodesRegister2::ERR_FR2_EXT_EEPROM:
        return "External eeprom data invalid.";
    case FaultCodesRegister2::ERR_FR2_EEPROM_FORMAT:
        return "Eeprom has been formatted (Format operation=0010).";
    case FaultCodesRegister2::ERR_FR2_BATCH_READ:
        return "Crc check invaldid when reading batch from eeprom or BatchReadCommand (prm 4210) > 16.";
    case FaultCodesRegister2::ERR_FR2_BATCH_WRITE:
        return "Pattern No (prm 4200) zero when writing the batch to memory/eeporm or BatchWriteCommand (prm 4211).";
    case FaultCodesRegister2::ERR_FR2_PATTERN_READ:
        return "Crc check invalid when reading pattern from eeprom or PatReadCommand (prm 4190) > 16.";
    case FaultCodesRegister2::ERR_FR2_PATTERN_WRITE:
        return "Pattern set invalid when writing to memory/eeprom or BatchWriteCommand (prm 4191) > 16.";
    case FaultCodesRegister2::ERR_FR2_IDCLINK_IXT_TRIP1:
        return "Tripped on primary DClink current Ixt.";
    case FaultCodesRegister2::ERR_FR2_CONTROLSUPPLY:
        return "Control voltage timed out on threshold of CtrlVoltageThreshold parameter (9200).";
    case FaultCodesRegister2::ERR_FR2_DCLINK1:
        return "Primary Dclink voltage too low.";
    case FaultCodesRegister2::ERR_FR2_PLD_1_5_SUPPLY:
        return "DSP measured that the 1.5V supply of the PWM generators (PLD's) are too low.";
    case FaultCodesRegister2::ERR_FR2_IDCLINK_IXT_TRIP2:
        return "Tripped on secundary DClink current Ixt.";
    case FaultCodesRegister2::ERR_FR2_DCLINK2:
        return "Secundary Dclink voltage too low.";
    case FaultCodesRegister2::ERR_FR2_RESERVED:
        return "";
    case FaultCodesRegister2::ERR_FR2_SET_CURRENT_EXCEEDED:
        return "Current set point value is too high.";
    default:
        throw std::runtime_error("Unknown fault code register 2 seen");
    }
}

} //end of namespace data_Munk


#endif // FAULT_CODES_REGISTER_TWO_H
