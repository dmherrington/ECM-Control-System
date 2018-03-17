#ifndef ACQUIRE_COMMAND_TYPE_H
#define ACQUIRE_COMMAND_TYPE_H

/**
\* @file  abstract_command_type.h
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
#include "acquire_command_type_options.h"


namespace commands_Rigol{

ECM_CLASS_FORWARD(AcquireCommand_Type);

class AcquireCommand_Type : public AbstractAcquireCommand
{
public:
    AcquireCommand_Type();

    AcquireCommand_Type(const AcquireCommand_Type &copy);

public:

    void setAcquisitionMode(const data_Rigol::AcquireCommand_TypeMode &mode);

    data_Rigol::AcquireCommand_TypeMode getAcquisitionMode() const;

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
    AcquireCommand_Type& operator = (const AcquireCommand_Type &rhs)
    {
        AbstractAcquireCommand::operator =(rhs);
        this->option = rhs.option;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const AcquireCommand_Type &rhs)
    {
        if(!AbstractAcquireCommand::operator ==(rhs)){
            return false;
        }
        if(this->option != rhs.option){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const AcquireCommand_Type &rhs) {
        return !(*this == rhs);
    }

private:
    data_Rigol::AcquireCommand_TypeMode option = data_Rigol::AcquireCommand_TypeMode::AVERAGE;

};

} //end of namespace commands


#endif // ACQUIRE_COMMAND_TYPE_H
