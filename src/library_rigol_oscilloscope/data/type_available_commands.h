#ifndef TYPE_AVAILABLE_COMMANDS_H
#define TYPE_AVAILABLE_COMMANDS_H

#include <string>
#include <stdexcept>


namespace data_Rigol{

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

} //end of namespace data_Rigol


#endif // TYPE_AVAILABLE_COMMANDS_H
