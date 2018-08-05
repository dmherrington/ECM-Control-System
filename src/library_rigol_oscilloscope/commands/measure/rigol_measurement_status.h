#ifndef RIGOL_MEASUREMENT_STATUS_H
#define RIGOL_MEASUREMENT_STATUS_H

#include "commands/abstract_rigol_status.h"

#include "data/type_available_channels.h"
#include "data/type_available_measurements.h"


namespace commands_Rigol{

class RigolMeasurementStatus : public AbstractRigolStatus
{

public:
    RigolMeasurementStatus(const std::string &name, const data_Rigol::AvailableChannels &measureChannel, const data_Rigol::MeasurementTypes &type);

    RigolMeasurementStatus(const RigolMeasurementStatus &copy);

public:
    void setMeasurementValue(const double &measurement);
    void setMeasurementString(const std::string &newString)
    {
        this->str = newString;
        this->setMeasurementValue(std::stof(newString));
    }

public:
    data_Rigol::AvailableChannels getChannel() const;

    data_Rigol::MeasurementTypes getMeasurementType() const;

    double getMeasurementValue() const;

    std::string getMeasurementString() const
    {
        return this->str;
    }

    bool isStatusValid() const override;

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
        this->str = rhs.str;
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
        if(this->str != rhs.str){
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
    data_Rigol::AvailableChannels channel = data_Rigol::AvailableChannels::CHANNEL_1;
    data_Rigol::MeasurementTypes measureType = data_Rigol::MeasurementTypes::MEASURE_VRMS;
    double value = 0.0;
    std::string str = "";
};

} //end of namespace commands


#endif // RIGOL_MEASUREMENT_STATUS_H
