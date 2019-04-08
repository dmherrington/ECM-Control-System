#include "spii_current_program.h"

SPII_CurrentProgram::SPII_CurrentProgram():
    BufferManager()
{

}

SPII_CurrentProgram::SPII_CurrentProgram(const SPII_CurrentProgram &copy):
    BufferManager(copy)
{
    this->m_OperationalLabels = copy.m_OperationalLabels;
    this->m_PrivateVariableList = copy.m_PrivateVariableList;
    this->m_UserVariableList = copy.m_UserVariableList;
}

void SPII_CurrentProgram::writeToJSON(QJsonObject &bufferDataObject)
{
    m_UserVariableList.writeToJSON(bufferDataObject);
    m_OperationalLabels.writeToJSON(bufferDataObject);

    BufferManager::writeToJSON(bufferDataObject);
}

void SPII_CurrentProgram::readFromJSON(const QJsonObject &bufferDataObject)
{
    m_UserVariableList.readFromJSON(bufferDataObject);
    m_OperationalLabels.readFromJSON(bufferDataObject);

    BufferManager::readFromJSON(bufferDataObject);
}

void SPII_CurrentProgram::updateOperationalLabels(const Operation_LabelList &labels)
{
    this->m_OperationalLabels = labels;
}

void SPII_CurrentProgram::updatePrivateVariables(const Operation_VariableList &vars)
{
    this->m_PrivateVariableList = vars;
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
