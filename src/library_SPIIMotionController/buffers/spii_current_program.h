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

    void updateOperationalLabels(const Operation_LabelList &labels);

    void updateUserVariables(const Operation_VariableList &vars);

    Operation_LabelList getCurrentOperationLabels() const;

    Operation_VariableList getCurrentUserVariables() const;

private:
    Operation_LabelList m_OperationalLabels;

    Operation_VariableList m_UserVariableList;
};

#endif // SPII_CURRENT_PROGRAM_H
