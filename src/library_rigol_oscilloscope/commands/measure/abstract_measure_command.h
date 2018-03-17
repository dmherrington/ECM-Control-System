#ifndef ABSTRACT_MEASURE_COMMAND_H
#define ABSTRACT_MEASURE_COMMAND_H

/**
\* @file  abstract_acquire_command.h
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

#include <string>

#include "common/class_forward.h"
#include "commands/abstract_rigol_command.h"

#include "data/type_measure_commands.h"
#include "data/type_read_write.h"


namespace commands_Rigol{

ECM_CLASS_FORWARD(AbstractMeasureCommand);

class AbstractMeasureCommand : public AbstractRigolCommand
{
public:
    AbstractMeasureCommand(const data_Rigol::MeasurementCommands &measure, const data_Rigol::RigolRWType &rw = data_Rigol::RigolRWType::WRITE):
        AbstractRigolCommand(data_Rigol::CommandTypes::COMMAND_MEASURE,rw)
    {
        this->measurementCommand = measure;
    }

    AbstractMeasureCommand(const AbstractMeasureCommand& copy):
        AbstractRigolCommand(copy)
    {
        this->measurementCommand = copy.measurementCommand;
    }


    virtual ~AbstractMeasureCommand() = default;

    /**
     *
     */
    template <class T>
    const T *as() const
    {
        //ensure that we are attempting to cast it to a type of state
        return static_cast<const T *>(this);
    }

    /**
     *
     */
    template <class T>
    T *as()
    {
        //ensure that we are attempting to cast it to a type of state
        return static_cast<T *>(this);
    }

public:
    virtual AbstractRigolStatus* getExpectedResponse() const = 0;

public:
    virtual data_Rigol::MeasurementCommands getMeasurementCommand() const
    {
        return measurementCommand;
    }

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    AbstractMeasureCommand& operator = (const AbstractMeasureCommand &rhs)
    {
        AbstractRigolCommand::operator =(rhs);
        this->measurementCommand = rhs.measurementCommand;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const AbstractMeasureCommand &rhs)
    {
        if(!AbstractRigolCommand::operator ==(rhs)){
            return false;
        }
        if(this->measurementCommand != rhs.measurementCommand){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const AbstractMeasureCommand &rhs) {
        return !(*this == rhs);
    }

protected:
    data_Rigol::MeasurementCommands measurementCommand;

};

} //end of namespace commands


#endif // ABSTRACT_MEASURE_COMMAND_H
