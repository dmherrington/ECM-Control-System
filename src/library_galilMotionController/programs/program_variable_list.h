#ifndef PROGRAM_VARIABLE_LIST_H
#define PROGRAM_VARIABLE_LIST_H

#include <map>
#include <string>

#include "common/class_forward.h"

class ProgramVariableList
{
public:
    ProgramVariableList();

    ProgramVariableList(const ProgramVariableList &copy);

    bool doesVariableExist(const std::string &name) const;

    void addVariable(const std::string &name, const int &lineNumber);

    void removeVariable(const std::string &name);

    void updateVariable(const std::string &name, const int &lineNumber);

    bool getVariableLine(const std::string &name, int &lineNumber) const;

    void clearVariableList();

    size_t sizeOfVariableList() const;

     std::map<std::string,int> getVariableMap() const;

public:
    ProgramVariableList& operator = (const ProgramVariableList &rhs)
    {
        this->variableMap = rhs.variableMap;
        return *this;
    }

    bool operator == (const ProgramVariableList &rhs) {
        if(this->variableMap != rhs.variableMap){
            return false;
        }
        return true;
    }

    bool operator != (const ProgramVariableList &rhs) {
        return !(*this == rhs);
    }

private:
    std::map<std::string,int> variableMap;
};



#endif // PROGRAM_VARIABLE_LIST_H
