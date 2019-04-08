#include "spii_command_upload_program_buffer.h"

SPIICommand_UploadProgramBuffer::SPIICommand_UploadProgramBuffer():
    CommandUploadProgram()
{

}

SPIICommand_UploadProgramBuffer::SPIICommand_UploadProgramBuffer(const SPIICommand_UploadProgramBuffer &copy):
    CommandUploadProgram(copy)
{

}

AbstractCommand* SPIICommand_UploadProgramBuffer::getClone() const
{
    return (new SPIICommand_UploadProgramBuffer(*this));
}

void SPIICommand_UploadProgramBuffer::getClone(AbstractCommand** state) const
{
    *state = new SPIICommand_UploadProgramBuffer(*this);
}


void SPIICommand_UploadProgramBuffer::setBufferIndex(const unsigned int &index)
{
    this->bufferIndex = index;
}
unsigned int SPIICommand_UploadProgramBuffer::getBufferIndex() const
{
    return this->bufferIndex;
}


void SPIICommand_UploadProgramBuffer::setShouldCompile(const bool &compile)
{
    this->compileImmediately = compile;
}
bool SPIICommand_UploadProgramBuffer::shouldCompileImmediately() const
{
    return this->compileImmediately;
}
