#ifndef WINDOW_DEVICE_CONNECTIONS_H
#define WINDOW_DEVICE_CONNECTIONS_H

#include <QMainWindow>

#include "../general_dialog_window.h"

#include "ECM_API/ecm_api.h"

#include "common/ecm_devices.h"
#include "common/comms/communication_connection.h"

#include "../LED.h"

namespace Ui {
class Window_DeviceConnections;
}

class Window_DeviceConnections : public GeneralDialogWindow
{
    Q_OBJECT

public:
    explicit Window_DeviceConnections(ECM_API* obj, QWidget *parent = 0);
    ~Window_DeviceConnections();

    void connectToAllDevices();

private:
    void closeEvent(QCloseEvent *event) override;

signals:
    void signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes &type, const bool &visibility);


public slots:
    void slot_SensorayConnectionUpdate(const common::comms::CommunicationUpdate &update);
    void slot_PumpConnectionUpdate(const common::comms::CommunicationUpdate &update);
    void slot_RigolConnectionUpdate(const common::comms::CommunicationUpdate &update);
    void slot_MunkConnectionUpdate(const common::comms::CommunicationUpdate &update);
    void slot_GalilConnectionUpdate(const common::comms::CommunicationUpdate &update);

private slots:

    void on_actionClose_triggered();

    void on_pushButton_connectSensoray_released();

    void on_pushButton_connectPump_released();

    void on_pushButton_connect_Rigol_released();

    void on_pushButton_connectMunk_released();

    void on_pushButton_connectGalil_released();

    void on_pushButton_Close_released();

    void on_pushButton_ConnectAll_released();

private:
    void updateLEDConnectionColor(LED* ledWidget, const common::comms::CommunicationUpdate &connected);

    void saveCommunicationSettings();

    void readCommunicationSettings();

private:
    Ui::Window_DeviceConnections *ui;
    ECM_API* m_API;
};

#endif // WINDOW_DEVICE_CONNECTIONS_H
