#ifndef TYPE_EXCEPTION_MESSAGE_H
#define TYPE_EXCEPTION_MESSAGE_H

#include <string>
#include <stdexcept>
#include <vector>


namespace data_Munk{

//!
//! \brief The ExceptionType enum
//!
enum class MunkExceptionType{
    EXCEPTION = 00, /**< */
    NO_EXCEPTION = 01 /**< */
};

enum class ExceptionCode{
    ILLEGAL_FUNCTION = 01, /**< */
    ILLEGAL_DATA_ADDRESS = 02, /**< */
    ILLEGAL_DATA_VALUE = 03
};

inline ExceptionCode ExceptionCodeFromInt(const uint8_t &code) {
    switch (code) {
    case 1:
        return ExceptionCode::ILLEGAL_FUNCTION;
        break;
    case 2:
        return ExceptionCode::ILLEGAL_DATA_ADDRESS;
        break;
    case 3:
        return ExceptionCode::ILLEGAL_DATA_VALUE;
        break;

    default:
        break;
    }
}

inline std::string ExceptionCodeToString(const ExceptionCode &code) {
    switch (code) {
    case ExceptionCode::ILLEGAL_FUNCTION:
        return "The function code received in the query is not an allowable action for the slave.";
    case ExceptionCode::ILLEGAL_DATA_ADDRESS:
        return "The data address received in the query is not an allowable address for the slave.";
    case ExceptionCode::ILLEGAL_DATA_VALUE:
        return "A value contained in the query data field is not an allowable value for the slave.";
    default:
        throw std::runtime_error("Unknown exception code seen");
    }
}

} //end of namespace data_Munk


#endif // TYPE_EXCEPTION_MESSAGE_H
