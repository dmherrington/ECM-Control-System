#ifndef RIGOL_MEASUREMENT_QUEUE_H
#define RIGOL_MEASUREMENT_QUEUE_H

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

#include <string>
#include <map>

#include "measure_command_item.h"

namespace rigol {
namespace commands{

class RigolMeasurementQueue
{
public:
    RigolMeasurementQueue();

    RigolMeasurementQueue(const RigolMeasurementQueue &copy);

    ~RigolMeasurementQueue() = default;

    void read(const QJsonObject &json);

    void write(QJsonObject &json) const;

public:
    //!
    //! \brief insertIntoQueue
    //! \param item
    //!
    void insertIntoQueue(const MeasureCommand_Item &item);

    //!
    //! \brief removeFromQueue
    //! \param key
    //!
    void removeFromQueue(const std::string &key);

    //!
    //! \brief getAtIndex
    //! \param index
    //! \return
    //!
    MeasureCommand_Item getAtKey(const std::string &key) const;

    //!
    //! \brief getQueueSize
    //! \return
    //!
    unsigned int getQueueSize() const;

    std::vector<MeasureCommand_Item> getMeasurementItems() const;

private:
    std::map<std::string,MeasureCommand_Item> queue;
};

} //end of namespace commands
} //end of namespace rigol

#endif // RIGOL_MEASUREMENT_QUEUE_H
