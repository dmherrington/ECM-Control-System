#ifndef TYPE_READ_WRITE_H
#define TYPE_READ_WRITE_H

#include <string>
#include <stdexcept>
#include <vector>

namespace westinghousePump{
namespace data{

//!
//! \brief The ReadWriteType enum
//!
enum class ReadWriteType{
    READ = 03, /**< */
    WRITE = 06 /**< */
};

//!
//! \brief ReadWriteTypeToString
//! \param type
//! \return
//!
inline std::string ReadWriteTypeToString(const ReadWriteType &type) {
    switch (type) {
    case ReadWriteType::READ:
        return "Read";
    case ReadWriteType::WRITE:
        return "Write";
    default:
        throw std::runtime_error("Unknown read or write type seen");
    }
}

//!
//! \brief ReadWriteTypeFromString
//! \param str
//! \return
//!
inline ReadWriteType ReadWriteTypeFromString(const std::string &str) {
    if(str == "Read")
        return ReadWriteType::READ;
    if(str == "Write")
        return ReadWriteType::WRITE;
    throw std::runtime_error("Unknown read or write type seen");
}

//!
//! \brief getListOfReadWriteType
//! \return
//!
inline std::vector<std::string> getListOfReadWriteType()
{
    std::vector<std::string> str;
    str.push_back(ReadWriteTypeToString(ReadWriteType::READ));
    str.push_back(ReadWriteTypeToString(ReadWriteType::WRITE));
    return str;
}

} //end of namespace data
} //end of namespace westinghousePump

#endif // TYPE_READ_WRITE_H
