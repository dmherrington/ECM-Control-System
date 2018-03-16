#ifndef TYPE_RESPONSE_EXCEPTION_H
#define TYPE_RESPONSE_EXCEPTION_H

#include <string>
#include <stdexcept>
#include <vector>


namespace data_Munk{

//!
//! \brief The TypeResponseException enum
//!
enum class TypeResponseException{
    ILLEGAL_FUNCTION = 0, /**<The function code received in the query is not an allowable action for the slave. */
    ILLEGAL_DATA_ADDRESS = 1, /**<The data address received in the query is not an allowable address for the slave. */
    ILLEGAL_DATA_VALUE = 2 /**<A value contained in the query data field is not an allowable value for the slave. */
};

//!
//! \brief TypeResponseExceptionToString
//! \param type
//! \return
//!
inline std::string TypeResponseExceptionToString(const TypeResponseException &type) {
    switch (type) {
    case TypeResponseException::ILLEGAL_FUNCTION:
        return "ILLEGAL_FUNCTION";
    case TypeResponseException::ILLEGAL_DATA_ADDRESS:
        return "ILLEGAL_DATA_ADDRESS";
    case TypeResponseException::ILLEGAL_DATA_VALUE:
        return "ILLEGAL_DATA_VALUE";
    default:
        throw std::runtime_error("Unknown exception response seen");
    }
}

//!
//! \brief TypeResponseExceptionFromString
//! \param str
//! \return
//!
inline TypeResponseException TypeResponseExceptionFromString(const std::string &str) {
    if(str == "ILLEGAL_FUNCTION")
        return TypeResponseException::ILLEGAL_FUNCTION;
    if(str == "ILLEGAL_DATA_ADDRESS")
        return TypeResponseException::ILLEGAL_DATA_ADDRESS;
    if(str == "ILLEGAL_DATA_VALUE")
        return TypeResponseException::ILLEGAL_DATA_VALUE;
    throw std::runtime_error("Unknown exception response string seen");
}

//!
//! \brief getListOfTypeResponseException
//! \return
//!
inline std::vector<std::string> getListOfTypeResponseException()
{
    std::vector<std::string> str;
    str.push_back(data_Munk::TypeResponseExceptionToString(TypeResponseException::LEVEL1));
    str.push_back(data_Munk::TypeResponseExceptionToString(TypeResponseException::LEVEL2));
    str.push_back(data_Munk::TypeResponseExceptionToString(TypeResponseException::LEVEL3));
    return str;
}

} //end of namespace data_Munk


#endif // TYPE_RESPONSE_EXCEPTION_H
