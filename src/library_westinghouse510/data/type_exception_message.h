#ifndef TYPE_WESTINGHOUSE_EXCEPTION_H
#define TYPE_WESTINGHOUSE_EXCEPTION_H

#include <string>
#include <stdexcept>
#include <vector>

namespace data_WestinghousePump {
//!
//! \brief The ExceptionType enum
//!
enum class ExceptionType{
    EXCEPTION = 00, /**< */
    NO_EXCEPTION = 01 /**< */
};

} //end of namespace data_WestinghousePump

#endif // TYPE_WESTINGHOUSE_EXCEPTION_H
