#include "request_list_labels.h"

RequestListLabels::RequestListLabels():
    AbstractRequest(RequestTypes::LIST_LABELS,500)
{

}

RequestListLabels::RequestListLabels(const RequestListLabels &copy):
    AbstractRequest(copy)
{

}

AbstractRequest* RequestListLabels::getClone() const
{
    return (new RequestListLabels(*this));
}

void RequestListLabels::getClone(AbstractRequest** state) const
{
    *state = new RequestListLabels(*this);
}

std::string RequestListLabels::getRequestString() const
{
    std::string str = "";
    str += RequestToString(this->getRequestType());
    return str;
}

std::vector<AbstractStatusPtr> RequestListLabels::getStatus() const
{
    std::vector<AbstractStatusPtr> rtn;
    Status_LabelListPtr statusLabelList = std::make_shared<Status_LabelList>();
    ProgramLabelList programLabelList;
    //as the galil only currently reports a single axis here, we will make the parse easy for now
    QString result = QString::fromStdString(buffer);
    QStringList list = result.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    for(int i = 0; i < list.size(); i++)
    {
        QStringList line = list.at(i).split(QRegExp("="),QString::SkipEmptyParts);
        if(line.size() == 2)
        {
            QString lblName = line.at(0).trimmed();
            QString lblLineNumber = line.at(1).trimmed();
            programLabelList.addLabel(lblName.toStdString(),lblLineNumber.toInt());
        }
    }
    statusLabelList->setLabelList(programLabelList);
    if(programLabelList.sizeOfLabelList() > 0)
        statusLabelList->setLabelList(programLabelList);

    rtn.push_back(statusLabelList);

    return rtn;
}
