#ifndef COMMAND_SET_BIT_H
#define COMMAND_SET_BIT_H

#include <vector>
#include "common/class_forward.h"

#include "commands/abstract_command.h"

ECM_CLASS_FORWARD(CommandSetBit);

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
    std::string getCommandString() const override;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    CommandSetBit& operator = (const CommandSetBit &rhs)
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
    bool operator == (const CommandSetBit &rhs)
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
    bool operator != (const CommandSetBit &rhs) {
        return !(*this == rhs);
    }

private:
    std::vector<unsigned int> digitalAddr; /**< Value of the IO address to set high/low */
};

#endif // COMMAND_SET_BIT_H
