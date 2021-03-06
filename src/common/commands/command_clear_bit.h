#ifndef COMMAND_CLEAR_BIT_H
#define COMMAND_CLEAR_BIT_H

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
