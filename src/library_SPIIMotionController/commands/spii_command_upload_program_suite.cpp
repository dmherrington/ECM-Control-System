#include "spii_command_upload_program_suite.h"

SPIICommand_UploadProgramSuite::SPIICommand_UploadProgramSuite():
    AbstractCommand(CommandType::UPLOAD_PROGRAM_SUITE)
{

}

SPIICommand_UploadProgramSuite::SPIICommand_UploadProgramSuite(const SPIICommand_UploadProgramSuite &copy):
    AbstractCommand(copy)
{

}

AbstractCommand* SPIICommand_UploadProgramSuite::getClone() const
{
    return (new SPIICommand_UploadProgramSuite(*this));
}

void SPIICommand_UploadProgramSuite::getClone(AbstractCommand** state) const
{
    *state = new SPIICommand_UploadProgramSuite(*this);
}


void SPIICommand_UploadProgramSuite::setProgram(const SPII_CurrentProgram &program)
{
    m_Program = program;
}

SPII_CurrentProgram SPIICommand_UploadProgramSuite::getProgram() const
{
    return m_Program;
}
