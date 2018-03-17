#ifndef ACQUIRE_COMMAND_SRATE_H
#define ACQUIRE_COMMAND_SRATE_H

/**
\* @file  abstract_command_srate.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System.
\*
\* @section DESCRIPTION
\*
\*
\*/

#include "abstract_acquire_command.h"


namespace commands_Rigol{

ECM_CLASS_FORWARD(AcquireCommand_Srate);

class AcquireCommand_Srate : public AbstractAcquireCommand
{
public:
    AcquireCommand_Srate();

    AcquireCommand_Srate(const AcquireCommand_Srate &copy);

public:

    void setReadOrWrite(const data_Rigol::RigolRWType &type) override
    {
        //This type of
        UNUSED(type);
        this->RWType = data_Rigol::RigolRWType::READ;
    }

protected:
    std::string getAcquireCommandString() const override;

public:
    /**
     * @brief getClone
     * @return
     */
    AbstractRigolCommand* getClone() const override;

    /**
     * @brief getClone
     * @param state
     */
    void getClone(AbstractRigolCommand** state) const override;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    AcquireCommand_Srate& operator = (const AcquireCommand_Srate &rhs)
    {
        AbstractAcquireCommand::operator =(rhs);
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const AcquireCommand_Srate &rhs)
    {
        if(!AbstractAcquireCommand::operator ==(rhs)){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const AcquireCommand_Srate &rhs) {
        return !(*this == rhs);
    }

private:
    std::string sampleRate = "";
};

} //end of namespace commands


#endif // ACQUIRE_COMMAND_SRATE_H
