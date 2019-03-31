#ifndef OPERATION_LABEL_LIST_H
#define OPERATION_LABEL_LIST_H

#include <QStringList>
#include <QJsonArray>
#include <QJsonObject>

#include <map>
#include <string>

#include "../class_forward.h"

class Operation_LabelList
{
public:
    Operation_LabelList();

    Operation_LabelList(const Operation_LabelList &copy);

public:
    void writeToJSON(QJsonObject &saveObject);

    void readFromJSON(const QJsonObject &openObject);

public:
    bool doesLabelExist(const std::string &name) const;

    void addLabel(const std::string &name, const int &lineNumber);

    void removeLabel(const std::string &name);

    void updateLabel(const std::string &name, const int &lineNumber);

    bool getLabelLine(const std::string &name, int &lineNumber) const;

    void clearLabelList();

    size_t sizeOfLabelList() const;

    std::map<std::string,int> getLabelMap() const;

    QStringList getLabelList() const;


public:
    Operation_LabelList& operator = (const Operation_LabelList &rhs)
    {
        this->labelMap = rhs.labelMap;
        return *this;
    }

    bool operator == (const Operation_LabelList &rhs) {
        if(this->labelMap != rhs.labelMap){
            return false;
        }
        return true;
    }

    bool operator != (const Operation_LabelList &rhs) {
        return !(*this == rhs);
    }

private:
    std::map<std::string,int> labelMap;

};

#endif // OPERATION_LABEL_LIST_H
