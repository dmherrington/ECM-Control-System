#ifndef RIGOL_OSCILLISCOPE_H
#define RIGOL_OSCILLISCOPE_H
#include <QDir>
#include <QObject>

#include "library_rigol_oscilloscope_global.h"

#include "communications/rigol_comms_marshaler.h"

#include "rigol_poll_measurements.h"

using namespace rigol;

class LIBRARY_RIGOL_OSCILLOSCOPESHARED_EXPORT RigolOscilliscope : public QObject, public RigolMeasurementUpdates_Interface,
        public comms::CommsEvents
{
    Q_OBJECT

public:
    explicit RigolOscilliscope(QObject *parent = nullptr);

    void addPollingMeasurement(const commands::MeasureCommand_Item &command);
    void removePollingMeasurement(const std::string &key);
    commands::RigolMeasurementQueue getCurrentPollingMeasurements() const;

public:
    //////////////////////////////////////////////////////////////
    /// Virtual methods allowed from comms::CommsEvents
    //////////////////////////////////////////////////////////////
    void ConnectionOpened() const override;
    void ConnectionClosed() const override;

public:
    void cbi_RigolMeasurementRequests(const rigol::commands::MeasureCommand_Item &request) override;

    void saveMeasurements();

signals:

public slots:

private:
    comms::RigolCommsMarshaler* commsMarshaler;
    RigolPollMeasurement* pollStatus;
    QString measurementPath;


};

#endif // RIGOL_OSCILLISCOPE_H
