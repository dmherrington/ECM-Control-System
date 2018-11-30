#ifndef COMMAND_PUMP_PROPERTIES_H
#define COMMAND_PUMP_PROPERTIES_H

#include <QJsonArray>
#include <QJsonObject>

#include "data_registers/register_flow_rate.h"
#include "data_registers/register_operation_signal.h"

class Command_PumpProperties
{
public:

    Command_PumpProperties() = default;

    Command_PumpProperties(const Command_PumpProperties &copy)
    {
        this->flowRate = copy.flowRate;
        this->waitForDelay = copy.waitForDelay;
        this->initTime = copy.initTime;
    }

public:
    void writeToJSON(QJsonObject &saveObject)
    {
        QJsonArray segmentDataArray;

        QJsonObject segmentObject;
        segmentObject["pumpDelayTime"] = (int)this->getInitializationTime();
        segmentObject["pumpFlowRate"] = this->getPumpFlowRate();
        segmentObject["pumpWaitForDelay"] = this->shouldWaitForInitializationDelay();
        segmentDataArray.append(segmentObject);

        saveObject["pumpData"] = segmentDataArray;
    }

    void readFromJSON(const QJsonObject &openObject)
    {
        QJsonArray pumpDataArray = openObject["pumpData"].toArray();
        QJsonObject segmentObject = pumpDataArray[0].toObject();

        setPumpInitializationTime(segmentObject["pumpDelayTime"].toDouble());
        setPumpFlowRate(segmentObject["pumpFlowRate"].toDouble());
        setWaitForInitializationDelay(segmentObject["pumpWaitForDelay"].toBool());
    }

public:
    void setPumpFlowRate(const double &desRate)
    {
        this->flowRate = desRate;
    }

    void setWaitForInitializationDelay(const bool &wait)
    {
        this->waitForDelay = wait;
    }

    void setPumpInitializationTime(const unsigned int &initializationTime)
    {
        this->initTime = initializationTime;
    }

public:
    double getPumpFlowRate() const
    {
        return this->flowRate;
    }

    bool shouldWaitForInitializationDelay() const
    {
        return this->waitForDelay;
    }
    unsigned int getInitializationTime() const
    {
        return this->initTime;
    }

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    Command_PumpProperties& operator = (const Command_PumpProperties &rhs)
    {
        this->flowRate = rhs.flowRate;
        this->waitForDelay = rhs.waitForDelay;
        this->initTime = rhs.initTime;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const Command_PumpProperties &rhs)
    {
        if(this->flowRate != rhs.flowRate){
            return false;
        }
        if(this->waitForDelay != rhs.waitForDelay){
            return false;
        }
        if(this->initTime != rhs.initTime){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const Command_PumpProperties &rhs) {
        return !(*this == rhs);
    }

private:
    double flowRate = 0.0;
    bool waitForDelay = false;
    unsigned int initTime = 0;
};

#endif // COMMAND_PUMP_PROPERTIES_H
