#ifndef OPERATION_VARIABLE_LIST_H
#define OPERATION_VARIABLE_LIST_H

#include <QTextStream>
#include <QJsonArray>
#include <QJsonObject>

#include <map>
#include <string>

#include "../class_forward.h"

class Operation_VariableList
{
public:
    Operation_VariableList();

    Operation_VariableList(const Operation_VariableList &copy);

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
    Operation_VariableList& operator = (const Operation_VariableList &rhs)
    {
        this->variableMap = rhs.variableMap;
        return *this;
    }

    bool operator == (const Operation_VariableList &rhs) {
        if(this->variableMap != rhs.variableMap){
            return false;
        }
        return true;
    }

    bool operator != (const Operation_VariableList &rhs) {
        return !(*this == rhs);
    }

public:
    std::string getLoggingString() const;

public:
    friend QTextStream& operator <<(QTextStream &outStream, const Operation_VariableList &data)
    {
        return outStream<<QString::fromStdString(data.getLoggingString());
    }

    friend std::ostream& operator<< (std::ostream &stream, const Operation_VariableList &data)
    {
        return stream<<data.getLoggingString();
    }

private:
    std::map<std::string,double> variableMap;
};


#endif // OPERATION_VARIABLE_LIST_H
