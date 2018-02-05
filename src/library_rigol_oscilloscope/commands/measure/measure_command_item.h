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

#include "abstract_measure_command.h"

#include "data/type_available_channels.h"
#include "data/type_available_measurements.h"

namespace rigol {
namespace commands{

ECM_CLASS_FORWARD(MeasureCommand_Item);

class MeasureCommand_Item : public AbstractMeasureCommand
{
public:
    MeasureCommand_Item();

    MeasureCommand_Item(const data::AvailableChannels &channel, const data::MeasurementTypes &type);

    MeasureCommand_Item(const MeasureCommand_Item &copy);

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
    void setChannel(const data::AvailableChannels &measureChannel);

    void setMeasurementType(const data::MeasurementTypes &type);

    data::AvailableChannels getChannel() const;

    data::MeasurementTypes getMeasurementType() const;

public:
    std::string getCommandString() const override
    {
        std::string rtn = getPrefixCommand();
        rtn+= data::MeasurementCommandToString(this->measurementCommand);
        rtn+= getSuffixCommand();
        rtn+= data::MeasurementTypeToString(this->measureType);
        rtn+= ",";
        rtn+=data::AvailableChannelsToString(this->channel);
        return rtn;
    }

    std::string getCommandKey() const override
    {
        std::string rtn;
        rtn+= data::MeasurementTypeToString(this->measureType);
        rtn+= "_";
        rtn+=data::AvailableChannelsToString(this->channel);
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
    data::MeasurementTypes measureType;
    data::AvailableChannels channel = data::AvailableChannels::CHANNEL_1;

};

} //end of namespace commands
} //end of namespace rigol

#endif // MEASURE_COMMAND_ITEM_H
