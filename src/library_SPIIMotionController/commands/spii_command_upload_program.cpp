#include "spii_command_upload_program.h"

SPIICommand_UploadProgram::SPIICommand_UploadProgram():
    CommandUploadProgram()
{

}

SPIICommand_UploadProgram::SPIICommand_UploadProgram(const SPIICommand_UploadProgram &copy):
    CommandUploadProgram(copy)
{

}

AbstractCommand* SPIICommand_UploadProgram::getClone() const
{
    return (new SPIICommand_UploadProgram(*this));
}

void SPIICommand_UploadProgram::getClone(AbstractCommand** state) const
{
    *state = new SPIICommand_UploadProgram(*this);
}


void SPIICommand_UploadProgram::setBufferIndex(const unsigned int &index)
{
    this->bufferIndex = index;
}
unsigned int SPIICommand_UploadProgram::getBufferIndex() const
{
    return this->bufferIndex;
}


void SPIICommand_UploadProgram::setShouldCompile(const bool &compile)
{
    this->compileImmediately = compile;
}
bool SPIICommand_UploadProgram::shouldCompileImmediately() const
{
    return this->compileImmediately;
}
