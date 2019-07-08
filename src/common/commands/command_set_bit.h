#ifndef COMMAND_SET_BIT_H
#define COMMAND_SET_BIT_H

#include <vector>

#include "../class_forward.h"
#include "../axis_definitions.h"

#include "abstract_command.h"

/**
\* @file  command_jog.h
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
    void setValue(const unsigned int &port, const unsigned int &bit, const bool &value);

    void getValue(unsigned int &port, unsigned int &bit, bool &value) const;

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
        this->digitalPort = rhs.digitalPort;
        this->digitalBit = rhs.digitalBit;
        this->value = rhs.value;
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
        if(this->digitalPort != rhs.digitalPort){
            return false;
        }
        if(this->digitalBit != rhs.digitalBit){
            return false;
        }
        if(this->value != rhs.value){
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
    unsigned int digitalPort; /**< Value of the IO address to set high/low */
    unsigned int digitalBit; /**< Value of the IO address to set high/low */
    bool value; /**< Value of the IO address to set high/low */

};

#endif // COMMAND_SET_BIT_H
