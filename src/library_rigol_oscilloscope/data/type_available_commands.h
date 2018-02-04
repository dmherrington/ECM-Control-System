#ifndef TYPE_AVAILABLE_COMMANDS_H
#define TYPE_AVAILABLE_COMMANDS_H

#include <string>
#include <stdexcept>

namespace rigol {
namespace data{

enum class CommandTypes
{
    COMMAND_ACQUIRE,
    COMMAND_MEASURE
};

//!
//! \brief SegmentModeToString
//! \param type
//! \return
//!
inline std::string getRigolCommandString(const CommandTypes &command) {
    switch (command) {
    case CommandTypes::COMMAND_ACQUIRE:
        return "ACQuire";
    case CommandTypes::COMMAND_MEASURE:
        return "MEASure";
    default:
        throw std::runtime_error("Unknown command type seen");
    }
}

} //end of namespace data
} //end of namespace rigol

#endif // TYPE_AVAILABLE_COMMANDS_H
