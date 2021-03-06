#ifndef PROGRAM_LABEL_LIST_H
#define PROGRAM_LABEL_LIST_H

#include <QStringList>
#include <QJsonArray>
#include <QJsonObject>

#include <map>
#include <string>

#include "common/class_forward.h"

class ProgramLabelList
{
public:
    ProgramLabelList();

    ProgramLabelList(const ProgramLabelList &copy);

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
    ProgramLabelList& operator = (const ProgramLabelList &rhs)
    {
        this->labelMap = rhs.labelMap;
        return *this;
    }

    bool operator == (const ProgramLabelList &rhs) {
        if(this->labelMap != rhs.labelMap){
            return false;
        }
        return true;
    }

    bool operator != (const ProgramLabelList &rhs) {
        return !(*this == rhs);
    }

private:
    std::map<std::string,int> labelMap;
};
#endif // PROGRAM_LABEL_LIST_H
