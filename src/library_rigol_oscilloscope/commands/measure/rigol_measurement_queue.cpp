#include "rigol_measurement_queue.h"

namespace rigol {
namespace commands{

RigolMeasurementQueue::RigolMeasurementQueue()
{

}

RigolMeasurementQueue::RigolMeasurementQueue(const RigolMeasurementQueue &copy)
{
    this->queue = copy.queue;
}

void RigolMeasurementQueue::read(const QJsonObject &json)
{
    QJsonArray measurementArray = json["Measurements At Channel"].toArray();

    for (int i = 0; i < measurementArray.size(); ++i) {
        QJsonObject measurementObject = measurementArray[i].toObject();
        MeasureCommand_Item newItem;
        newItem.read(measurementObject);
    }
}

void RigolMeasurementQueue::write(QJsonObject &json) const
{
    QJsonArray measurementArray;
    std::map<std::string,MeasureCommand_Item>::const_iterator it;
    for(it = queue.begin(); it != queue.end(); ++it)
    {
        QJsonObject measurementObject;
        it->second.write(measurementObject);
        measurementArray.append(measurementObject);
    }
    json["Measurements At Channel"] = measurementArray;
}

void RigolMeasurementQueue::insertIntoQueue(const MeasureCommand_Item &item)
{
    queue.insert(std::pair<std::string,MeasureCommand_Item>(item.getCommandKey(),item));
}

void RigolMeasurementQueue::removeFromQueue(const std::string &key)
{
    if(queue.count(key) > 0)
        queue.erase(key);
}

MeasureCommand_Item RigolMeasurementQueue::getAtKey(const std::string &key) const
{
    if(queue.count(key) > 0)
        return queue.at(key);
}

unsigned int RigolMeasurementQueue::getQueueSize() const
{
    return queue.size();
}

std::vector<MeasureCommand_Item> RigolMeasurementQueue::getMeasurementItems() const
{
    std::vector<MeasureCommand_Item> rtn;
    std::map<std::string,MeasureCommand_Item>::const_iterator it;
    for (it = queue.begin(); it != queue.end(); ++it)
        rtn.push_back(it->second);

    return rtn;
}

} //end of namespace commands
} //end of namespace rigol
