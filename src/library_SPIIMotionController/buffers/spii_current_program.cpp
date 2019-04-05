#include "spii_current_program.h"

SPII_CurrentProgram::SPII_CurrentProgram():
    BufferManager()
{

}

SPII_CurrentProgram::SPII_CurrentProgram(const SPII_CurrentProgram &copy):
    BufferManager(copy)
{
    this->m_UserVariableList = copy.m_UserVariableList;
    this->m_OperationalLabels = copy.m_OperationalLabels;
}


void SPII_CurrentProgram::updateOperationalLabels(const Operation_LabelList &labels)
{
    this->m_OperationalLabels = labels;
}

void SPII_CurrentProgram::updateUserVariables(const Operation_VariableList &vars)
{
    this->m_UserVariableList = vars;
}

Operation_LabelList SPII_CurrentProgram::getCurrentOperationLabels() const
{
    return m_OperationalLabels;
}

Operation_VariableList SPII_CurrentProgram::getCurrentUserVariables() const
{
    return m_UserVariableList;
}
