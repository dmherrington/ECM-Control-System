#ifndef PLC_H
#define PLC_H

#include <QTextStream>
#include <QJsonObject>
#include <QJsonDocument>

#include <QObject>
#include <QTimer>
#include <QFile>

#include <iostream>

#include "library_plc_global.h"

#include "common/comms/communication_connection.h"
#include "common/comms/communication_update.h"
#include "common/comms/tcp_configuration.h"

#include "library_qModBus/library_qmodbus.h"

#include "data_registers/register_components.h"
#include "data/type_read_write.h"

#include "communications/plc_data_framing.h"

#include "plc_poll_machine.h"


class LIBRARY_PLCSHARED_EXPORT PLC : public QObject, public PLCPollingEvents_Interface
{
    Q_OBJECT
public:

    //!
    //! \brief PLC constructor of the westinghouse library object. This class has no way of explicitly
    //! \param commsObject the abstract communication object that handles/marshals commands/objects that communicate
    //! the commands/data from this class to the pump. Also, this class receives updates from this object reflecting
    //! the current status/state of the pump.
    //! \param pumpAddress numeric address of the pump
    //! \param name class name used when communicating out objects reflected in the tuple state
    //!
    PLC(const int &plcAddress, const std::string &name = "PLC Controller");

    //! \brief ~PLC default destructor of the westinghouse library object
    ~PLC()
    {
        delete m_Comms; m_Comms = nullptr;
    }

public:
    //!
    //! \brief isPumpConnected
    //! \return
    //!
    bool isPLCConnected() const;

    //!
    //! \brief openPLCConnection
    //! \param linkConfig
    //!
    void openPLCConnection(const common::comms::TCPConfiguration &linkConfig);

    //!
    //! \brief closePumpConnection
    //!
    void closePLCConnection();


public:
    void PLCPolling_NewRequest(const requests_PLC::AbstractRequestPtr req) override;

private:

    //!
    //! \brief parseReceivedMessage function that shall parse the msg object to determine what feedback
    //! was received from the plc.
    //! \param msg generic message data type containing the byte array of the received data from the plc
    //!
    void parseReceivedMessage(const comms_PLC::PLCMessage &msg);

signals:

    //!
    //! \brief signal_PumpConnectionUpdate signal emitted when something about the connection has changed and/or been modified
    //! \param obj generic data type containing the status of the resulting connection update
    //!
    void signal_CommunicationUpdate(const common::comms::CommunicationUpdate &obj);


private slots:
    //!
    //! \brief slot_SerialPortUpdate
    //! \param update
    //!
    void slot_PortUpdate(const common::comms::CommunicationUpdate &update);

    //!
    //! \brief slot_SerialPortReceivedData
    //! \param data
    //!
    void slot_PortReceivedData(const QByteArray &data);

private:
    Library_QModBus* m_Comms;

    comms_PLC::PLCDataFraming* m_DataFraming;

    PLCPollMachine* m_PollMachine;

    std::string deviceName;

};

#endif // PLC_H
