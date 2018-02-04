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

namespace rigol {
namespace commands{

ECM_CLASS_FORWARD(AcquireCommand_Type);

class AcquireCommand_Type : public AbstractAcquireCommand
{
public:
    AcquireCommand_Type();

    AcquireCommand_Type(const AcquireCommand_Type &copy);

public:
    /**
     * @brief getClone
     * @return
     */
    AbstractAcquireCommand* getClone() const override;

    /**
     * @brief getClone
     * @param state
     */
    void getClone(AbstractAcquireCommand** state) const override;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    AcquireCommand_Type& operator = (const AcquireCommand_Type &rhs)
    {
        AbstractAcquireCommand::operator =(rhs);
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
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const AcquireCommand_Average &rhs) {
        return !(*this == rhs);
    }


};

} //end of namespace commands
} //end of namespace rigol

#endif // ACQUIRE_COMMAND_TYPE_H
