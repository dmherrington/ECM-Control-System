#ifndef TYPE_MUNK_READ_WRITE_H
#define TYPE_MUNK_READ_WRITE_H

#include <string>
#include <stdexcept>
#include <vector>


namespace data_Munk {

//!
//! \brief The ReadWriteType enum
//!
enum class MunkRWType{
    READ = 03, /**< */
    WRITE = 16 /**< */
};

//!
//! \brief ReadWriteTypeToString
//! \param type
//! \return
//!
inline std::string ReadWriteTypeToString(const MunkRWType &type) {
    switch (type) {
    case MunkRWType::READ:
        return "Read";
    case MunkRWType::WRITE:
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
inline MunkRWType ReadWriteTypeFromString(const std::string &str) {
    if(str == "Read")
        return MunkRWType::READ;
    if(str == "Write")
        return MunkRWType::WRITE;
    throw std::runtime_error("Unknown read or write type seen");
}

//!
//! \brief getListOfReadWriteType
//! \return
//!
inline std::vector<std::string> getListOfReadWriteType()
{
    std::vector<std::string> str;
    str.push_back(data_Munk::ReadWriteTypeToString(MunkRWType::READ));
    str.push_back(data_Munk::ReadWriteTypeToString(MunkRWType::WRITE));
    return str;
}

} //end of namespace data_Munk


#endif // TYPE_MUNK_READ_WRITE_H
