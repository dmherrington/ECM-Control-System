#ifndef TYPE_CURRENT_SET_H
#define TYPE_CURRENT_SET_H

#include <string>
#include <stdexcept>
#include <vector>

namespace Data
{

enum class SegmentParameter{
    SEGMENT1 = 4170,
    SEGMENT2 = 4171,
    SEGMENT3 = 4172,
    SEGMENT4 = 4173,
    SEGMENT5 = 4174,
    SEGMENT6 = 4175,
    SEGMENT7 = 4176,
    SEGMENT8 = 4178,
    SEGMENT9 = 4179,
    SEGMENT10 = 4180,
    SEGMENT11 = 4181,
    SEGMENT12 = 4182,
    SEGMENT13 = 4183,
    SEGMENT14 = 4184,
    SEGMENT15 = 4185,
    SEGMENT16 = 4186,
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

inline std::vector<std::string> getListOfReadWriteType()
{
    std::vector<std::string> str;
    str.push_back(Data::ReadWriteTypeToString(ReadWriteType::READ));
    str.push_back(Data::ReadWriteTypeToString(ReadWriteType::WRITE));
    return str;
}

} //end of namespace Data

#endif // TYPE_CURRENT_SET_H
