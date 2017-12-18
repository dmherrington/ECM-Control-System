#ifndef COMMAND_TYPES_H
#define COMMAND_TYPES_H

#include <string>
#include <vector>
#include <stdexcept>

/**
\* @file  command_types.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is to control the Galil Motion Controller.
\*
\* @section DESCRIPTION
\*
\*
\*/

enum class CommandType{
    MOTOR_OFF = 0,
    MOTOR_ON = 1,
    JOG_MOVE = 2,
    RELATIVE_MOVE = 3,
    ABSOLUTE_MOVE = 4,
    STOP = 5,
    SET_BIT = 6,
    CLEAR_BIT = 7,
    EXECUTE_PROGRAM = 8
};

//!
//! \brief CommandToString
//! \param type
//! \return
//!
inline std::string CommandToString(const CommandType &type) {
    switch (type) {
    case CommandType::MOTOR_OFF:
        return "MO";
    case CommandType::MOTOR_ON:
        return "SH";
    case CommandType::JOG_MOVE:
        return "JG";
    case CommandType::RELATIVE_MOVE:
        return "PR";
    case CommandType::ABSOLUTE_MOVE:
        return "PA";
    case CommandType::STOP:
        return "ST";
    case CommandType::SET_BIT:
        return "SB";
    case CommandType::CLEAR_BIT:
        return "CB";
    case CommandType::EXECUTE_PROGRAM:
        return "XQ";
    default:
        throw std::runtime_error("Unknown command type seen");
    }
}

//!
//! \brief CommandFromString
//! \param str
//! \return
//!
inline CommandType CommandFromString(const std::string &str) {
    if(str == "MO")
        return CommandType::MOTOR_OFF;
    if(str == "SH")
        return CommandType::MOTOR_ON;
    if(str == "JG")
        return CommandType::JOG_MOVE;
    if(str == "PR")
        return CommandType::RELATIVE_MOVE;
    if(str == "PA")
        return CommandType::ABSOLUTE_MOVE;
    if(str == "ST")
        return CommandType::STOP;
    if(str == "SB")
        return CommandType::SET_BIT;
    if(str == "CB")
        return CommandType::CLEAR_BIT;
    if(str == "XQ")
        return CommandType::EXECUTE_PROGRAM;
    throw std::runtime_error("Unknown command type seen");
}

//!
//! \brief getListOfCurrentFactor
//! \return
//!
inline std::vector<std::string> getListOfCurrentCommandTypes()
{
    std::vector<std::string> str;
    str.push_back(CommandToString(CommandType::JOG_MOVE));
    str.push_back(CommandToString(CommandType::RELATIVE_MOVE));
    str.push_back(CommandToString(CommandType::ABSOLUTE_MOVE));
    return str;
}

#endif // COMMAND_TYPES_H
