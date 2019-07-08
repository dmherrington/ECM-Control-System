#ifndef SPII_COMMAND_UPLOAD_PROGRAM_BUFFER_H
#define SPII_COMMAND_UPLOAD_PROGRAM_BUFFER_H

#include "common/commands/command_upload_program.h"

ECM_CLASS_FORWARD(SPIICommand_UploadProgramBuffer);

class SPIICommand_UploadProgramBuffer : public CommandUploadProgram
{
public:
    SPIICommand_UploadProgramBuffer();

    SPIICommand_UploadProgramBuffer(const SPIICommand_UploadProgramBuffer &copy);

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
    void setBufferIndex(const unsigned int &index);
    unsigned int getBufferIndex() const;

    void setShouldCompile(const bool &compile);
    bool shouldCompileImmediately() const;

public:
    SPIICommand_UploadProgramBuffer& operator = (const SPIICommand_UploadProgramBuffer &rhs)
    {
        CommandUploadProgram::operator =(rhs);
        this->bufferIndex = rhs.bufferIndex;
        this->compileImmediately = rhs.compileImmediately;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const SPIICommand_UploadProgramBuffer &rhs)
    {
        if(!CommandUploadProgram::operator ==(rhs)){
            return false;
        }
        if(this->bufferIndex != rhs.bufferIndex){
            return false;
        }
        if(this->compileImmediately != rhs.compileImmediately){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const SPIICommand_UploadProgramBuffer &rhs) {
        return !(*this == rhs);
    }


private:
    unsigned int bufferIndex = 0;

    bool compileImmediately = true;
};

#endif // SPII_COMMAND_UPLOAD_PROGRAM_BUFFER_H
