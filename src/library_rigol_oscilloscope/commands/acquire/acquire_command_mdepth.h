#ifndef ACQUIRE_COMMAND_MDEPTH_H
#define ACQUIRE_COMMAND_MDEPTH_H

/**
\* @file  abstract_command_mdepth.h
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
#include "data/type_memory_depth.h"


namespace commands_Rigol{

ECM_CLASS_FORWARD(AcquireCommand_Mdepth);

class AcquireCommand_Mdepth : public AbstractAcquireCommand
{
public:
    AcquireCommand_Mdepth();

    AcquireCommand_Mdepth(const AcquireCommand_Mdepth &copy);

public:

    void setSingleChannelDepth(const data_Rigol::DepthSingleChannel &depth);

    void setDualChannelDepth(const data_Rigol::DepthDualChannel &depth);

    void setQuadratureChannelDepth(const data_Rigol::DepthQuadratureChannel &depth);

    std::string getChannelDepth() const;

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
    AcquireCommand_Mdepth& operator = (const AcquireCommand_Mdepth &rhs)
    {
        AbstractAcquireCommand::operator =(rhs);
        this->memDepth = rhs.memDepth;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const AcquireCommand_Mdepth &rhs)
    {
        if(!AbstractAcquireCommand::operator ==(rhs)){
            return false;
        }
        if(this->memDepth != rhs.memDepth){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const AcquireCommand_Mdepth &rhs) {
        return !(*this == rhs);
    }

private:
    std::string memDepth;
};

} //end of namespace commands


#endif // ACQUIRE_COMMAND_MDEPTH_H
