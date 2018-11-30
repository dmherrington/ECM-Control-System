#ifndef PROGRAM_VARIABLE_LIST_H
#define PROGRAM_VARIABLE_LIST_H

#include <QTextStream>
#include <QJsonArray>
#include <QJsonObject>

#include <map>
#include <string>

#include "common/class_forward.h"

class ProgramVariableList
{
public:
    ProgramVariableList();

    ProgramVariableList(const ProgramVariableList &copy);

public:
    void writeToJSON(QJsonObject &saveObject);

    void readFromJSON(const QJsonObject &openObject);

public:

    bool doesVariableExist(const std::string &name) const;

    void addVariable(const std::string &name, const double &value);

    void removeVariable(const std::string &name);

    void updateVariable(const std::string &name, const double &value);

    bool getVariableValue(const std::string &name, double &value) const;

    void clearVariableList();

    size_t sizeOfVariableList() const;

     std::map<std::string,double> getVariableMap() const;

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

public:
    std::string getLoggingString() const;

public:
    friend QTextStream& operator <<(QTextStream &outStream, const ProgramVariableList &data)
    {
        return outStream<<QString::fromStdString(data.getLoggingString());
    }

    friend std::ostream& operator<< (std::ostream &stream, const ProgramVariableList &data)
    {
        return stream<<data.getLoggingString();
    }

private:
    std::map<std::string,double> variableMap;
};



#endif // PROGRAM_VARIABLE_LIST_H
