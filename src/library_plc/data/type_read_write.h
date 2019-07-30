#ifndef TYPE_PLC_READ_WRITE_H
#define TYPE_PLC_READ_WRITE_H

#include <string>
#include <stdexcept>
#include <vector>

namespace data_PLC {
//!
//! \brief The ReadWriteType enum
//!
enum class RWType{
    READ = 03, /**< */
    WRITE = 06, /**< */
    LOOP = 8 /**< */
};

//!
//! \brief ReadWriteTypeToString
//! \param type
//! \return
//!
inline std::string ReadWriteTypeToString(const RWType &type) {
    switch (type) {
    case RWType::READ:
        return "Read";
    case RWType::WRITE:
        return "Write";
    case RWType::LOOP:
        return "Loop";
    default:
        throw std::runtime_error("Unknown read or write type seen");
    }
}

//!
//! \brief ReadWriteTypeFromString
//! \param str
//! \return
//!
inline RWType ReadWriteTypeFromString(const std::string &str) {
    if(str == "Read")
        return RWType::READ;
    if(str == "Write")
        return RWType::WRITE;
    if(str == "Loop")
        return RWType::LOOP;
    throw std::runtime_error("Unknown read or write type seen");
}

//!
//! \brief getListOfReadWriteType
//! \return
//!
inline std::vector<std::string> getListOfReadWriteType()
{
    std::vector<std::string> str;
    str.push_back(ReadWriteTypeToString(RWType::READ));
    str.push_back(ReadWriteTypeToString(RWType::WRITE));
    str.push_back(ReadWriteTypeToString(RWType::LOOP));
    return str;
}

} //end of namespace data_PLCPump
#endif // TYPE_PLC_READ_WRITE_H
