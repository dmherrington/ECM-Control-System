#ifndef RIGOL_OSCILLISCOPE_H
#define RIGOL_OSCILLISCOPE_H

#include <QDir>
#include <QObject>

#include <iostream>

#include "library_rigol_oscilloscope_global.h"

#include "common/tuple_sensor_string.h"
#include "common/comms/communication_update.h"
#include "common/comms/communication_connection.h"

#include "data/type_read_write.h"

#include "data/sensor_state.h"
#include "data/sensors/sensor_voltage.h"

#include "commands/acquire/acquire_components.h"
#include "commands/measure/measure_components.h"

#include "communications/rigol_comms_marshaler.h"
#include "rigol_poll_measurements.h"

//channe 1 is area channel 2 is vtop
using namespace commands_Rigol;
using namespace comms_Rigol;
using namespace data_Rigol;

class LIBRARY_RIGOL_OSCILLOSCOPESHARED_EXPORT RigolOscilliscope : public QObject, public RigolMeasurementUpdates_Interface,
        public comms_Rigol::CommsEvents
{
    Q_OBJECT

public:
    explicit RigolOscilliscope(const std::string &name = "Rigol_Oscilloscope", QObject *parent = nullptr);

    ~RigolOscilliscope();

public:
    void openConnection(const std::string &ipAddress, const int &port);
    void closeConnection();
    bool isDeviceConnected() const;

    void initializeRigol();

    void loadFromQueue(const commands_Rigol::RigolMeasurementQueue &updatedQueue);

    bool addPollingMeasurement(const MeasureCommand_Item &command);
    void removePollingMeasurement(const MeasureCommand_Item &command);
    commands_Rigol::RigolMeasurementQueue getCurrentPollingMeasurements() const;

    void executeMeasurementPolling(const bool &execute);

private:
    void cbi_RigolMeasurementRequests(const commands_Rigol::MeasureCommand_Item &request) override;

    //////////////////////////////////////////////////////////////
    /// Virtual methods allowed from comms::CommsEvents
    //////////////////////////////////////////////////////////////
    void LinkConnectionUpdate(const common::comms::CommunicationUpdate &update) override;
    void ConnectionOpened() override;
    void ConnectionClosed() const override;
    void NewDataReceived(const std::vector<uint8_t> &buffer) const override;
    void NewMeaurementReceived(const commands_Rigol::RigolMeasurementStatus &status) const override;

signals:

    void signal_RigolCommunicationUpdate(const common::comms::CommunicationUpdate &value) const;
    void signal_RigolPlottable(const common::TupleSensorString &sensorTuple, const bool &on_off);
    void signal_RigolNewSensorValue(const common::TupleSensorString &sensorTuple, const common_data::SensorState &data) const;
    void signal_RigolLoadComplete();

private:
    std::string deviceName;
    comms_Rigol::RigolCommsMarshaler* commsMarshaler;
    RigolPollMeasurement* pollStatus;
    commands_Rigol::RigolMeasurementQueue queue;
    QString previousSettingsPath;

};

#endif // RIGOL_OSCILLISCOPE_H
