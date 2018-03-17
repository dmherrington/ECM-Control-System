#ifndef TYPE_FAULT_CODES_GENERAL_H
#define TYPE_FAULT_CODES_GENERAL_H

#include <string>
#include <stdexcept>
#include <vector>


namespace data_Munk{

//!
//! \brief The CurrentFactorType enum
//!
enum class DataFaultCodes{
    DATA_UPDATE_SUCCESSFUL, /**< */
    DATA_VALUE_GREATER_THAN_MAX, /**< */
    DATA_VALUE_LESS_THAN_MIN, /**< */
    DATA_GENERATION_PASSED, /**< */
    DATA_VOLTAGE_SATURATION, /**< */
    DATA_CURRENT_SATURATION, /**< */
    DATA_FAULT_TOO_MANY_VI_COMBOS, /**< */
    DATA_FAULT_OUTPUT_SUPPLY_MISMATCH /**< */
};

} //end of namespace data_Munk


#endif // TYPE_FAULT_CODES_GENERAL_H
