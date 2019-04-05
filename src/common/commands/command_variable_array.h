#ifndef COMMAND_VARIABLE_ARRAY_H
#define COMMAND_VARIABLE_ARRAY_H

#include "../class_forward.h"
#include "../axis_definitions.h"

#include "abstract_command.h"

/**
\* @file  command_variable_array.h
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

class Command_VariableArray : public AbstractCommand
{
public:
    Command_VariableArray(const std::string &name, const std::vector<double> &value);

    Command_VariableArray(const Command_VariableArray &copy);

    /**
      */
    virtual ~Command_VariableArray() = default;

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
    void setVariableValue(const std::vector<double> &value);

public:
    std::string getVariableName() const;
    std::vector<double> getVariableValue() const;

public:
    std::string getCommandString() const override;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    Command_VariableArray& operator = (const Command_VariableArray &rhs)
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
    bool operator == (const Command_VariableArray &rhs)
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
    bool operator != (const Command_VariableArray &rhs) {
        return !(*this == rhs);
    }


private:
    std::string variableName;
    std::vector<double> variableValue;
};

#endif // COMMAND_VARIABLE_ARRAY_H
