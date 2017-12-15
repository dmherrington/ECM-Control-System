#ifndef COMMAND_SET_BIT_H
#define COMMAND_SET_BIT_H

#include <vector>

#include "commands/abstract_command.h"

class CommandSetBit : public AbstractCommand
{
public:
    CommandSetBit();

    CommandSetBit(const CommandSetBit &copy);

    /**
      */
    virtual ~CommandSetBit() = default;

public:
    /**
     * @brief getClone
     * @return
     */
    AbstractCommand* getClone() const override;

    /**
     * @brief getClone
     * @param state
     */
    void getClone(AbstractCommand** state) const override;

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
