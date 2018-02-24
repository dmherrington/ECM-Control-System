#ifndef RIGOL_OSCILLISCOPE_H
#define RIGOL_OSCILLISCOPE_H
#include <QDir>
#include <QObject>

#include <iostream>

#include "library_rigol_oscilloscope_global.h"

#include "commands/acquire/acquire_components.h"

#include "communications/rigol_comms_marshaler.h"

#include "rigol_poll_measurements.h"

using namespace rigol;

class LIBRARY_RIGOL_OSCILLOSCOPESHARED_EXPORT RigolOscilliscope : public QObject, public RigolMeasurementUpdates_Interface,
        public comms::CommsEvents
{
    Q_OBJECT

public:
    explicit RigolOscilliscope(QObject *parent = nullptr);

    ~RigolOscilliscope();

public:
    void openConnection(const std::string &ipAddress, const int &port);
    void closeConnection();

    void addPollingMeasurement(const commands::MeasureCommand_Item &command);
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

private:
    void initializeRigol() const;


signals:

public slots:

private:
    comms::RigolCommsMarshaler* commsMarshaler;
    RigolPollMeasurement* pollStatus;
    QString previousSettingsPath;


};

#endif // RIGOL_OSCILLISCOPE_H
