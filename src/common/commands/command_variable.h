#ifndef COMMAND_VARIABLE_H
#define COMMAND_VARIABLE_H

#include "../class_forward.h"
#include "../axis_definitions.h"

#include "abstract_command.h"

/**
\* @file  command_jog.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is to control the Galil Motion Controller.
\*
\* @section DESCRIPTION
\*
\*
\*/

ECM_CLASS_FORWARD(Command_Variable);

class Command_Variable : public AbstractCommand
{
public:
    Command_Variable(const std::string &name, const double &value);

    Command_Variable(const Command_Variable &copy);

    /**
      */
    virtual ~Command_Variable() = default;

public:
    /**
     * @brief getClone
     * @return
     */
    AbstractCommand* getClone() const override;

    /**
     * @brief getClone
     * @param state
     */
    void getClone(AbstractCommand** state) const override;

public:
    void setVariableName(const std::string &name);
    void setVariableValue(const double &value);

public:
    std::string getVariableName() const;
    double getVariableValue() const;

public:
    std::string getCommandString() const override;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    Command_Variable& operator = (const Command_Variable &rhs)
    {
        AbstractCommand::operator =(rhs);
        this->variableName = rhs.variableName;
        this->variableValue = rhs.variableValue;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const Command_Variable &rhs)
    {
        if(!AbstractCommand::operator ==(rhs)){
            return false;
        }
        if(this->variableName != rhs.variableName){
            return false;
        }
        if(this->variableValue != rhs.variableValue){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const Command_Variable &rhs) {
        return !(*this == rhs);
    }


private:
    std::string variableName;
    double variableValue;
};

#endif // COMMAND_VARIABLE_H
