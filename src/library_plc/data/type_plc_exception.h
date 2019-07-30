#ifndef TYPE_PLC_EXCEPTION_H
#define TYPE_PLC_EXCEPTION_H

#include <string>
#include <stdexcept>
#include <vector>

namespace data_PLC {
//!
//! \brief The ExceptionType enum
//!
enum class PLCExceptionTypes{
    EXCEPTION = 00, /**< */
    NO_EXCEPTION = 01 /**< */
};

} //end of namespace data_PLC

#endif // TYPE_PLC_EXCEPTION_H
