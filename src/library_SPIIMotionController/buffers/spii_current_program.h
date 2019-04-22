#ifndef SPII_CURRENT_PROGRAM_H
#define SPII_CURRENT_PROGRAM_H

#include "spii_buffer_manager.h"

class SPII_CurrentProgram : public BufferManager
{
public:
    SPII_CurrentProgram();

    SPII_CurrentProgram(const SPII_CurrentProgram &copy);

     ~SPII_CurrentProgram() = default;

public:
    void writeToJSON(QJsonObject &bufferDataObject, const bool &writeVariableData = true);

    void readFromJSON(const QJsonObject &bufferDataObject) override;

public:

    void updateOperationalLabels(const Operation_LabelList &labels);

    void updatePrivateVariables(const Operation_VariableList &vars);

    void updateUserVariables(const Operation_VariableList &vars);

    Operation_LabelList getCurrentOperationLabels() const;

    Operation_VariableList getCurrentUserVariables() const;

public:
    SPII_CurrentProgram& operator = (const SPII_CurrentProgram &rhs)
    {
        BufferManager::operator =(rhs);
        this->m_OperationalLabels = rhs.m_OperationalLabels;
        this->m_PrivateVariableList = rhs.m_PrivateVariableList;
        this->m_UserVariableList = rhs.m_UserVariableList;
        return *this;
    }

    bool operator == (const SPII_CurrentProgram &rhs) {
        if(!BufferManager::operator ==(rhs)){
            return false;
        }
        if(this->m_OperationalLabels != rhs.m_OperationalLabels){
            return false;
        }

        if(this->m_PrivateVariableList != rhs.m_PrivateVariableList){
            return false;
        }

        if(this->m_UserVariableList != rhs.m_UserVariableList){
            return false;
        }
        return true;
    }

    bool operator != (const SPII_CurrentProgram &rhs) {
        return !(*this == rhs);
    }

private:
    Operation_LabelList m_OperationalLabels;

    Operation_VariableList m_PrivateVariableList;

    Operation_VariableList m_UserVariableList;
};

#endif // SPII_CURRENT_PROGRAM_H
