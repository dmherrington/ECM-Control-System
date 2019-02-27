#ifndef COMMAND_COMPILE_BUFFER_H
#define COMMAND_COMPILE_BUFFER_H

#include <vector>

#include "../class_forward.h"

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

class CommandCompileBuffer : public AbstractCommand
{
public:
    CommandCompileBuffer();

    CommandCompileBuffer(const CommandCompileBuffer &copy);

    /**
      */
    virtual ~CommandCompileBuffer() = default;

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
    void addCompileBuffer(const unsigned int &bufferIndex);
    std::vector<unsigned int> getCompileBuffers() const;

    bool shouldCompileAllBuffers() const;


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
    CommandCompileBuffer& operator = (const CommandCompileBuffer &rhs)
    {
        AbstractCommand::operator =(rhs);
        this->compileAll = rhs.compileAll;
        this->compileBuffers = rhs.compileBuffers;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const CommandCompileBuffer &rhs)
    {
        if(!AbstractCommand::operator ==(rhs)){
            return false;
        }
        if(this->compileAll != rhs.compileAll){
            return false;
        }
        if(this->compileBuffers != rhs.compileBuffers){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const CommandCompileBuffer &rhs) {
        return !(*this == rhs);
    }

private:
    bool compileAll = true;

    std::vector<unsigned int> compileBuffers; /**< Value of the IO address to set high/low */
};


#endif // COMMAND_COMPILE_BUFFER_H
