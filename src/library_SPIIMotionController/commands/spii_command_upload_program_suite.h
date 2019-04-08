#ifndef SPII_COMMAND_UPLOAD_PROGRAM_SUITE_H
#define SPII_COMMAND_UPLOAD_PROGRAM_SUITE_H

#include "common/class_forward.h"

#include "common/commands/abstract_command.h"

#include "../buffers/spii_current_program.h"

ECM_CLASS_FORWARD(SPIICommand_UploadProgramSuite);
class SPIICommand_UploadProgramSuite : public AbstractCommand
{

public:
    SPIICommand_UploadProgramSuite();

    SPIICommand_UploadProgramSuite(const SPIICommand_UploadProgramSuite &copy);

    /**
      */
    virtual ~SPIICommand_UploadProgramSuite() = default;

public:
    /**
     * @brief getClone
     * @return
     */
    virtual AbstractCommand* getClone() const override;

    /**
     * @brief getClone
     * @param state
     */
    virtual void getClone(AbstractCommand** state) const override;

public:

    void setProgram(const SPII_CurrentProgram &program);

    SPII_CurrentProgram getProgram() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    SPIICommand_UploadProgramSuite& operator = (const SPIICommand_UploadProgramSuite &rhs)
    {
        AbstractCommand::operator =(rhs);
        this->m_Program = rhs.m_Program;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const SPIICommand_UploadProgramSuite &rhs)
    {
        if(!AbstractCommand::operator ==(rhs)){
            return false;
        }
        if(this->m_Program != rhs.m_Program){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const SPIICommand_UploadProgramSuite &rhs) {
        return !(*this == rhs);
    }

private:
    SPII_CurrentProgram m_Program;
};

#endif // SPII_COMMAND_UPLOAD_PROGRAM_SUITE_H
