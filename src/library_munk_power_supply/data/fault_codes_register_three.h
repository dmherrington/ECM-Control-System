#ifndef FAULT_CODES_REGISTER_THREE_H
#define FAULT_CODES_REGISTER_THREE_H

#include <string>
#include <stdexcept>
#include <vector>

namespace Data
{

//!
//! \brief The CurrentFactorType enum
//!
enum class FaultCodesRegister3
{
    ERR_FR3_EXTERNAL_TRIP1 = 1, /**<External Trip #1 */
    ERR_FR3_EXTERNAL_TRIP2 = 2, /**<External Trip #2 */
    ERR_FR3_PLD_PWM_GENERATOR1 = 4, /**<IO controller did not find PWM generator #1, Fatal Error not resettable */
    ERR_FR3_PLD_PWM_GENERATOR2 = 8, /**<IO controller did not find PWM generator #2, Fatal Error not resettable */
    ERR_FR3_LOST_FIELDBUS = 16, /**<Lost communication with field bus */
    ERR_FR3_DYNAMIC_OVERCURRENT = 32, /**<A dynamic overcurrent occurred see prm 4600..4603 */
    ERR_FR3_RESERVED_7 = 64, /**< */
    ERR_FR3_RESERVED_8 = 128, /**< */
    ERR_FR3_RESERVED_9 = 256, /**< */
    ERR_FR3_RESERVED_10 = 512, /**< */
    ERR_FR3_RESERVED_11 = 1024, /**< */
    ERR_FR3_RESERVED_12 = 2048, /**< */
    ERR_FR3_RESERVED_13 = 4096, /**< */
    ERR_FR3_RESERVED_14 = 8192, /**< */
    ERR_FR3_RESERVED_15 = 16384, /**< */
    ERR_FR3_RESERVED_16 = 32768 /**< */

};

} //end of namespace Data

#endif // FAULT_CODES_REGISTER_THREE_H
