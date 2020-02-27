#ifndef COMMAND_VARIABLE_INTEGER_H
#define COMMAND_VARIABLE_INTEGER_H

#include "../class_forward.h"
#include "../axis_definitions.h"

#include "abstract_command.h"

/**
\* @file  command_variable_integer.h
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

ECM_CLASS_FORWARD(Command_VariableInteger);

class Command_VariableInteger : public AbstractCommand
{
public:
    Command_VariableInteger(const std::string &name, const int &value = 0);

    Command_VariableInteger(const Command_VariableInteger &copy);

    /**
      */
    virtual ~Command_VariableInteger() = default;

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
    void setVariableValue(const int &value);

public:
    std::string getVariableName() const;
    int getVariableValue() const;

public:
    std::string getCommandString() const override;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    Command_VariableInteger& operator = (const Command_VariableInteger &rhs)
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
    bool operator == (const Command_VariableInteger &rhs)
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
    bool operator != (const Command_VariableInteger &rhs) {
        return !(*this == rhs);
    }


private:
    std::string variableName;
    int variableValue;
};

#endif // COMMAND_VARIABLE_INTEGER_H
