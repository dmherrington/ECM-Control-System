#ifndef ABSTRACT_COMMAND_H
#define ABSTRACT_COMMAND_H

#include <string>

#include "command_types.h"

class AbstractCommand
{
public:
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
