#ifndef COMMAND_SET_BIT_H
#define COMMAND_SET_BIT_H

#include <vector>

#include "commands/abstract_command.h"

class CommandSetBit : public AbstractCommand
{
public:
    CommandSetBit();

public:
    void appendAddress(const unsigned int &address);

     std::vector<unsigned int> getDigitalAddress() const;
public:
    //!
    //! \brief getCommandString
    //! \return
    //!
    virtual std::string getCommandString() const override;

private:
    std::vector<unsigned int> digitalAddr; /**< Value of the IO address to set high/low */
};

#endif // COMMAND_SET_BIT_H
