#include "operation_label_list.h"

Operation_LabelList::Operation_LabelList()
{

}

Operation_LabelList::Operation_LabelList(const Operation_LabelList &copy)
{
    this->labelMap = copy.labelMap;
}

void Operation_LabelList::writeToJSON(QJsonObject &saveObject)
{
    QJsonArray MCLabelArray;

    std::map<std::string,int>::iterator it = labelMap.begin();

    QJsonObject labelObject;

    for(;it!=labelMap.end();++it)
    {
        std::string variableKey = it->first;
        labelObject[QString::fromStdString(variableKey)] = it->second;
    }

    MCLabelArray.append(labelObject);

    saveObject["labelData"] = MCLabelArray;
}

void Operation_LabelList::readFromJSON(const QJsonObject &openObject)
{
    QJsonArray MCLabelArray = openObject["labelData"].toArray();
    QJsonObject labelObject = MCLabelArray[0].toObject();

    for (int labelIndex = 0; labelIndex < labelObject.size(); ++labelIndex) {
        QString labelKey = labelObject.keys().at(labelIndex);
        int labelValue = labelObject.value(labelKey).toInt();
        addLabel(labelKey.toStdString(),labelValue);
    }
}

bool Operation_LabelList::doesLabelExist(const std::string &name) const
{
    if(this->labelMap.count(name) > 0)
        return true;
    return false;
}

void Operation_LabelList::addLabel(const std::string &name, const int &lineNumber)
{
    this->labelMap[name] = lineNumber;
}

void Operation_LabelList::removeLabel(const std::string &name)
{
    if(this->labelMap.count(name) > 0)
        this->labelMap.erase(name);
}

void Operation_LabelList::updateLabel(const std::string &name, const int &lineNumber)
{
    if(this->labelMap.count(name) > 0)
        this->labelMap.at(name) = lineNumber;
    else
        this->labelMap[name] = lineNumber;
}

bool Operation_LabelList::getLabelLine(const std::string &name, int &lineNumber) const
{
    if(this->labelMap.count(name) > 0)
    {
        lineNumber = this->labelMap.at(name);
        return true;
    }
    return false;
}

void Operation_LabelList::clearLabelList()
{
    labelMap.clear();
}

size_t Operation_LabelList::sizeOfLabelList() const
{
    return this->labelMap.size();
}

std::map<std::string,int> Operation_LabelList::getLabelMap() const
{
    return this->labelMap;
}

QStringList Operation_LabelList::getLabelList() const
{
    QStringList rtnList;

    std::map<std::string,int>::const_iterator it = this->labelMap.begin();

    for (; it != this->labelMap.end(); ++it)
    {
        rtnList.push_back(QString::fromStdString(it->first));
    }

    return rtnList;
}
