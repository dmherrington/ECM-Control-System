#ifndef ABSTRACT_COMMAND_H
#define ABSTRACT_COMMAND_H

#include <string>

#include "command_types.h"

/**
\* @file  abstract_command.h
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

class AbstractCommand
{
public:
    AbstractCommand(const CommandType &type)
    {
        this->commandType = type;
    }

    virtual ~AbstractCommand() = default;

public:
    virtual CommandType getCommandType() const
    {
        return commandType;
    }

    virtual std::string getCommandString() const = 0;

protected:
    CommandType commandType;

};

#endif // ABSTRACT_COMMAND_H
