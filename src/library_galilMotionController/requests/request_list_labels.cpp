#include "request_list_labels.h"

RequestListLabels::RequestListLabels():
    AbstractRequest(RequestTypes::LIST_LABELS)
{

}

RequestListLabels::RequestListLabels(const RequestListLabels &copy):
    AbstractRequest(RequestTypes::LIST_LABELS)
{
    this->mapLabels = copy.mapLabels;
}

void RequestListLabels::updateLabels(const std::string &labels)
{
    this->mapLabels.clear();

    QString newLabels = QString::fromStdString(labels);
    QStringList list = newLabels.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    for(int i =0; i < list.size(); i++)
    {
        QString value = list.at(i);
        QStringList sublist = value.split("=");
        this->mapLabels[sublist.at(0).toStdString()] = sublist.at(1).toInt();
    }
}

std::map<std::string, int> RequestListLabels::getLabels() const
{
    return this->mapLabels;
}

std::string RequestListLabels::getRequestString() const
{

}
