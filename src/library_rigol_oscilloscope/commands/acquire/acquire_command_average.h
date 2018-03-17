#ifndef ACQUIRE_COMMAND_AVERAGE_H
#define ACQUIRE_COMMAND_AVERAGE_H

/**
\* @file  abstract_command_average.h
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

#include <math.h>

#include "abstract_acquire_command.h"


namespace commands_Rigol{

ECM_CLASS_FORWARD(AcquireCommand_Average);

class AcquireCommand_Average : public AbstractAcquireCommand
{
public:
    AcquireCommand_Average();

    AcquireCommand_Average(const AcquireCommand_Average &copy);

public:

    void setSampleNumbers(const unsigned int &samples);

    unsigned int getSampleNumber() const;

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
    AcquireCommand_Average& operator = (const AcquireCommand_Average &rhs)
    {
        AbstractAcquireCommand::operator =(rhs);
        this->queryNumber = rhs.queryNumber;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const AcquireCommand_Average &rhs)
    {
        if(!AbstractAcquireCommand::operator ==(rhs)){
            return false;
        }
        if(this->queryNumber != rhs.queryNumber){
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

private:
    unsigned int queryNumber = 8;

};

} //end of namespace commands


#endif // ACQUIRE_COMMAND_AVERAGE_H
