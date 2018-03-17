#ifndef RIGOL_TYPE_READ_WRITE_H
#define RIGOL_TYPE_READ_WRITE_H

#include <string>
#include <stdexcept>
#include <vector>

namespace data_Rigol{

//!
//! \brief The ReadWriteType enum
//!
enum class RigolRWType{
    READ = 0, /**< */
    WRITE = 1 /**< */
};

//!
//! \brief ReadWriteTypeToString
//! \param type
//! \return
//!
inline std::string ReadWriteTypeToString(const RigolRWType &type) {
    switch (type) {
    case RigolRWType::READ:
        return "Read";
    case RigolRWType::WRITE:
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
inline RigolRWType ReadWriteTypeFromString(const std::string &str) {
    if(str == "Read")
        return RigolRWType::READ;
    if(str == "Write")
        return RigolRWType::WRITE;
    throw std::runtime_error("Unknown read or write type seen");
}

//!
//! \brief getListOfReadWriteType
//! \return
//!
inline std::vector<std::string> getListOfReadWriteType()
{
    std::vector<std::string> str;
    str.push_back(ReadWriteTypeToString(RigolRWType::READ));
    str.push_back(ReadWriteTypeToString(RigolRWType::WRITE));
    return str;
}

} //end of namespace data_Rigol


#endif // RIGOL_TYPE_READ_WRITE_H
