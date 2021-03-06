#ifndef COMMAND_CLEAR_BIT_H
#define COMMAND_CLEAR_BIT_H

#include <vector>

#include "commands/abstract_command.h"

class CommandClearBit : public AbstractCommand
{
public:
    CommandClearBit();

    CommandClearBit(const CommandClearBit &copy);

    /**
      */
    virtual ~CommandClearBit() = default;

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
    std::string getCommandString() const override;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    CommandClearBit& operator = (const CommandClearBit &rhs)
    {
        AbstractCommand::operator =(rhs);
        this->digitalAddr = rhs.digitalAddr;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const CommandClearBit &rhs)
    {
        if(!AbstractCommand::operator ==(rhs)){
            return false;
        }
        if(this->digitalAddr != rhs.digitalAddr){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const CommandClearBit &rhs) {
        return !(*this == rhs);
    }

private:
    std::vector<unsigned int> digitalAddr; /**< Value of the IO address to set high/low */
};

#endif // COMMAND_CLEAR_BIT_H
