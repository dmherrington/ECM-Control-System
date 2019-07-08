#ifndef COMMAND_UPLOAD_OPERATIONAL_VARIABLES_H
#define COMMAND_UPLOAD_OPERATIONAL_VARIABLES_H

#include "../class_forward.h"

#include "abstract_command.h"

#include "../operation/operation_variable_list.h"

/**
\* @file  command_upload_operational_variables.h
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

ECM_CLASS_FORWARD(Command_UploadOperationalVariables);
class Command_UploadOperationalVariables : public AbstractCommand
{
public:
    Command_UploadOperationalVariables();

    Command_UploadOperationalVariables(const Command_UploadOperationalVariables &copy);

    /**
      */
    virtual ~Command_UploadOperationalVariables() = default;

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
    void setOperationalVariables(const Operation_VariableList &variableList);

    Operation_VariableList getOperationalVariables() const;


public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    Command_UploadOperationalVariables& operator = (const Command_UploadOperationalVariables &rhs)
    {
        AbstractCommand::operator =(rhs);
        this->m_VariableList = rhs.m_VariableList;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const Command_UploadOperationalVariables &rhs)
    {
        if(!AbstractCommand::operator ==(rhs)){
            return false;
        }
        if(this->m_VariableList != rhs.m_VariableList){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const Command_UploadOperationalVariables &rhs) {
        return !(*this == rhs);
    }

private:
    Operation_VariableList m_VariableList;
};

#endif // COMMAND_UPLOAD_OPERATIONAL_VARIABLES_H
