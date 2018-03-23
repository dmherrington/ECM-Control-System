#ifndef MEASURE_COMMAND_ITEM_H
#define MEASURE_COMMAND_ITEM_H

/**
\* @file  measure_command_item.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System.
\*
\* @section DESCRIPTION
\*
\*
\*/

#include <QJsonObject>

#include "abstract_measure_command.h"

#include "data/type_available_channels.h"
#include "data/type_available_measurements.h"

#include "rigol_measurement_status.h"


namespace commands_Rigol{

ECM_CLASS_FORWARD(MeasureCommand_Item);

class MeasureCommand_Item : public AbstractMeasureCommand
{
public:
    MeasureCommand_Item(const std::string &name = "Rigol", const data_Rigol::AvailableChannels &channel = AvailableChannels::CHANNEL_1, const data_Rigol::MeasurementTypes &type = MeasurementTypes::MEASURE_VRMS);

    MeasureCommand_Item(const MeasureCommand_Item &copy);

    void read(const QJsonObject &json);

    void write(QJsonObject &json) const;

public:
    AbstractRigolStatus* getExpectedResponse() const override;

public:
    /**
     * @brief getClone
     * @return
     */
    AbstractRigolCommand* getClone() const override;

    /**
     * @brief getClone
     * @param state
     */
    void getClone(AbstractRigolCommand** state) const override;

public:
    void setDeviceName(const std::string &name);

    void setChannel(const data_Rigol::AvailableChannels &measureChannel);

    void setMeasurementType(const data_Rigol::MeasurementTypes &type);

    std::string getDeviceName() const;

    data_Rigol::AvailableChannels getChannel() const;

    data_Rigol::MeasurementTypes getMeasurementType() const;

public:
    std::string getCommandString() const override
    {
        std::string rtn = getPrefixCommand();
        rtn+= data_Rigol::MeasurementCommandToString(this->measurementCommand);
        rtn+= getSuffixCommand();
        rtn+= data_Rigol::MeasurementTypeEnumToString(this->measureType);
        rtn+= ",";
        rtn+=data_Rigol::AvailableChannelsToString(this->channel);
        return rtn;
    }

    std::string getCommandKey() const override
    {
        std::string rtn;
        rtn+=data_Rigol::AvailableChannelsToString(this->channel);
        rtn+= "_";
        rtn+= data_Rigol::MeasurementTypeEnumToString(this->measureType);
        return rtn;
    }

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    MeasureCommand_Item& operator = (const MeasureCommand_Item &rhs)
    {
        AbstractMeasureCommand::operator =(rhs);
        this->channel = rhs.channel;
        this->measureType = rhs.measureType;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const MeasureCommand_Item &rhs)
    {
        if(!AbstractMeasureCommand::operator ==(rhs)){
            return false;
        }
        if(this->channel != rhs.channel){
            return false;
        }
        if(this->measureType != rhs.measureType){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const MeasureCommand_Item &rhs) {
        return !(*this == rhs);
    }

private:
    std::string deviceName = "Rigol";
    data_Rigol::AvailableChannels channel = data_Rigol::AvailableChannels::CHANNEL_1;
    data_Rigol::MeasurementTypes measureType = data_Rigol::MeasurementTypes::MEASURE_VRMS;

};

} //end of namespace commands


#endif // MEASURE_COMMAND_ITEM_H
