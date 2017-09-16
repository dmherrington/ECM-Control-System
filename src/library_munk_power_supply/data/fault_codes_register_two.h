#ifndef FAULT_CODES_REGISTER_TWO_H
#define FAULT_CODES_REGISTER_TWO_H

#include <string>
#include <stdexcept>
#include <vector>

namespace Data
{

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

} //end of namespace Data

#endif // FAULT_CODES_REGISTER_TWO_H
