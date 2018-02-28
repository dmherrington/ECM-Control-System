#ifndef RIGOL_OSCILLISCOPE_H
#define RIGOL_OSCILLISCOPE_H
#include <QDir>
#include <QObject>

#include <iostream>

#include "library_rigol_oscilloscope_global.h"

#include "commands/acquire/acquire_components.h"
#include "commands/measure/measure_components.h"

#include "communications/rigol_comms_marshaler.h"

#include "rigol_poll_measurements.h"

using namespace rigol;

class LIBRARY_RIGOL_OSCILLOSCOPESHARED_EXPORT RigolOscilliscope : public QObject, public RigolMeasurementUpdates_Interface,
        public comms::CommsEvents
{
    Q_OBJECT

public:
    explicit RigolOscilliscope(const std::string &name = "Rigol_Oscilloscope", QObject *parent = nullptr);

    ~RigolOscilliscope();

public:
    void openConnection(const std::string &ipAddress, const int &port);
    void closeConnection();

    bool addPollingMeasurement(const commands::MeasureCommand_Item &command);
    void removePollingMeasurement(const std::string &key);
    void executeMeasurementPolling(const bool &execute);
    commands::RigolMeasurementQueue getCurrentPollingMeasurements() const;

public:
    //////////////////////////////////////////////////////////////
    /// Virtual methods allowed from comms::CommsEvents
    //////////////////////////////////////////////////////////////
    void ConnectionOpened() const override;
    void ConnectionClosed() const override;
    void NewDataReceived(const std::vector<uint8_t> &buffer) const override;
    void NewMeaurementReceived(const rigol::commands::RigolMeasurementStatus &status) const override;

public:
    void cbi_RigolMeasurementRequests(const rigol::commands::MeasureCommand_Item &request) override;

    void saveMeasurements();
    void loadMeaurements(const std::string &path);

private:
    void initializeRigol() const;
    void loadFromQueue(const rigol::commands::RigolMeasurementQueue &updatedQueue);


signals:

public slots:

private:
    std::string sensorName;
    comms::RigolCommsMarshaler* commsMarshaler;
    RigolPollMeasurement* pollStatus;
    rigol::commands::RigolMeasurementQueue queue;
    QString previousSettingsPath;


};

#endif // RIGOL_OSCILLISCOPE_H
