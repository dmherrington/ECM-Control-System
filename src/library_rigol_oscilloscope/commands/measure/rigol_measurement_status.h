#ifndef RIGOL_MEASUREMENT_STATUS_H
#define RIGOL_MEASUREMENT_STATUS_H

#include "commands/abstract_rigol_status.h"

#include "data/type_available_channels.h"
#include "data/type_available_measurements.h"

namespace rigol {
namespace commands{

class RigolMeasurementStatus : public AbstractRigolStatus
{

public:
    RigolMeasurementStatus(const data::AvailableChannels &measureChannel, const data::MeasurementTypes &type);

    RigolMeasurementStatus(const RigolMeasurementStatus &copy);

public:
    void setMeasurementValue(const double &measurement);

public:
    data::AvailableChannels getChannel() const;

    data::MeasurementTypes getMeasurementType() const;

    double getMeasurementValue() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    RigolMeasurementStatus& operator = (const RigolMeasurementStatus &rhs)
    {
        AbstractRigolStatus::operator =(rhs);
        this->channel = rhs.channel;
        this->measureType = rhs.measureType;
        this->value = rhs.value;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const RigolMeasurementStatus &rhs)
    {
        if(!AbstractRigolStatus::operator ==(rhs)){
            return false;
        }
        if(this->channel != rhs.channel){
            return false;
        }
        if(this->measureType != rhs.measureType){
            return false;
        }
        if(this->value != rhs.value){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const RigolMeasurementStatus &rhs) {
        return !(*this == rhs);
    }

private:
    data::AvailableChannels channel = data::AvailableChannels::CHANNEL_1;
    data::MeasurementTypes measureType = data::MeasurementTypes::MEASURE_VRMS;
    double value = 0.0;
};

} //end of namespace commands
} //end of namespace rigol

#endif // RIGOL_MEASUREMENT_STATUS_H
