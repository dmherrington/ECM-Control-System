#ifndef ECM_PROCESS_H
#define ECM_PROCESS_H


class ECMProcess
{
public:
    ECMProcess();

protected:

    //!
    //! \brief Write data bout sensor state to log
    //! \param sensorKey Sensor component
    //! \param state Data on component
    //!
    void WriteLogMachineState(const ISAACCore::TupleSensorString sensorKey, const Data::SensorState &state);

    //!
    //! \brief Write data bout sensor state to log
    //! \param sensorKey Sensor component
    //! \param state Data on component
    //!
    void WriteLogSensorState(const ISAACCore::TupleSensorString sensorKey, const Data::SensorState &state);

    //!
    //! \brief Write data bout sensor state to log
    //! \param sensorKey Sensor component
    //! \param state Data on component
    //!
    void WriteLogMachingProfileState(const ISAACCore::TupleSensorString sensorKey, const Data::SensorState &state);

};

#endif // ECM_PROCESS_H
