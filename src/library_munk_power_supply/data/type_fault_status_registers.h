#ifndef TYPE_FAULT_STATUS_REGISTERS_H
#define TYPE_FAULT_STATUS_REGISTERS_H

#include <string>
#include <stdexcept>
#include <vector>


namespace data_Munk{

//!
//! \brief The ReadWriteType enum
//!
enum class FaultRegisterType{
    FAULT_REGISTER_1 = 300, /**< */
    FAULT_REGISTER_2 = 301, /**< */
    FAULT_REGISTER_3 = 302 /**< */
};

enum class StatusRegisterType{
    STATUS_REGISTER_1 = 310, /**< */
    STATUS_REGISTER_2 = 311, /**< */
    STATUS_REGISTER_3 = 312 /**< */
};

enum class FaultDetailedRegisterType{
    FAULT_DETAILED_1 = 320, /**< */
    FAULT_DETAILED_2 = 321, /**< */
    FAULT_DETAILED_3 = 322 /**< */
};

} //end of namespace data_Munk


#endif // TYPE_FAULT_STATUS_REGISTERS_H
