#ifndef TYPE_READ_WRITE_H
#define TYPE_READ_WRITE_H

#include <string>
#include <stdexcept>
#include <bitset>

namespace Data
{

enum class ReadWriteType{
    READ = 0,
    WRITE = 1
};

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

inline ReadWriteType ReadWriteTypeFromString(const std::string &str) {
    if(str == "Read")
        return ReadWriteType::READ;
    if(str == "Write")
        return ReadWriteType::WRITE;
    throw std::runtime_error("Unknown read or write type seen");
}

} //end of namespace Data

#endif // TYPE_READ_WRITE_H
