#ifndef PROFILE_OPERATION_TYPE_H
#define PROFILE_OPERATION_TYPE_H

enum class ProfileOpType
{
    OPERATION = 0,
    POSITION_MOVE = 1,
    PAUSE = 2,
    UNKNOWN = 10
};

inline ProfileOpType ProfileOpTypeFromString(const std::string &str)
{
    if(str == "OPERATION")
        return ProfileOpType::OPERATION;
    else if(str == "POSITION MOVE")
        return ProfileOpType::POSITION_MOVE;
    else if(str == "PAUSE")
        return ProfileOpType::PAUSE;
    else
        throw std::runtime_error("Unknown ProfileOpType string seen");
}


#endif // PROFILE_OPERATION_TYPE_H
