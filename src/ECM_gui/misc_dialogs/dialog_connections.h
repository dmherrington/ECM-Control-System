#ifndef DIALOG_CONNECTIONS_H
#define DIALOG_CONNECTIONS_H

#include <QDialog>

#include "ECM_API/ecm_api.h"

#include "common/ecm_devices.h"
#include "common/comms/communication_connection.h"

#include "../LED.h"

namespace Ui {
class Dialog_Connections;
}

class Dialog_Connections : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Connections(ECM_API* obj, QWidget *parent = 0);
    ~Dialog_Connections();

public slots:
    void slot_SensorayConnectionUpdate(const common::comms::CommunicationConnection &update);
    void slot_PumpConnectionUpdate(const common::comms::CommunicationConnection &update);
    void slot_RigolConnectionUpdate(const common::comms::CommunicationConnection &update);
    void slot_MunkConnectionUpdate(const common::comms::CommunicationConnection &update);
    void slot_GalilConnectionUpdate(const common::comms::CommunicationConnection &update);

private slots:

    void on_pushButton_connectSensoray_released();

    void on_pushButton_connectPump_released();

    void on_pushButton_connect_Rigol_released();

    void on_pushButton_connectMunk_released();

    void on_pushButton_connectGalil_released();

    void on_pushButton_Close_released();

private:
    void updateLEDConnectionColor(LED* ledWidget, const bool &connected);

private:
    Ui::Dialog_Connections *ui;
    ECM_API* m_API;
};

#endif // DIALOG_CONNECTIONS_H
