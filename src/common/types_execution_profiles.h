#ifndef TYPES_EXECUTION_PROFILES_H
#define TYPES_EXECUTION_PROFILES_H

enum class ProfileType
{
    HOMING,
    TOUCHOFF,
    PROFILE
};

enum class HOMINGProfileCodes
{

};

enum class TOUCHOFFProfileCodes
{
    SEARCHING = 0,
    FINISHED = 1,
    ERROR_INCONSISTENT = 2,
    ERROR_TOUCHING = 3
};

#endif // TYPES_EXECUTION_PROFILES_H
