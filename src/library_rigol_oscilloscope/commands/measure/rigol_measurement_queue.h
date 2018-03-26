#ifndef RIGOL_MEASUREMENT_QUEUE_H
#define RIGOL_MEASUREMENT_QUEUE_H

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

#include <string>
#include <map>

#include "measure_command_item.h"
#include "data/type_read_write.h"


namespace commands_Rigol{

class RigolMeasurementQueue
{
public:
    RigolMeasurementQueue();

    RigolMeasurementQueue(const RigolMeasurementQueue &copy);

    ~RigolMeasurementQueue() = default;

    void read(const QJsonObject &json);

    void write(QJsonObject &json) const;

    void clearQueue();

public:
    //!
    //! \brief insertIntoQueue
    //! \param item
    //!
    bool insertIntoQueue(const MeasureCommand_Item &item);

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

    std::vector<data_Rigol::MeasurementTypes> getMeasurementItemsPerChannel(const data_Rigol::AvailableChannels &channel) const;

private:
    std::map<std::string,MeasureCommand_Item> queue;
};

} //end of namespace commands


#endif // RIGOL_MEASUREMENT_QUEUE_H
