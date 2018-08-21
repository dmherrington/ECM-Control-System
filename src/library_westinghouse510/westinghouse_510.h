#ifndef WESTINGHOUSE_510_H
#define WESTINGHOUSE_510_H

#include <QTextStream>
#include <QSerialPort>
#include <QSerialPortInfo>

#include <QObject>
#include <QTimer>
#include <QFile>

#include <iostream>

#include "library_westinghouse510_global.h"

#include "common/comms/abstract_communication.h"

#include "data_registers/register_components.h"
#include "data/type_read_write.h"

#include "communications/westinghouse_510_data_framing.h"
#include "westinghouse_510_state.h"

class LIBRARY_WESTINGHOUSE510SHARED_EXPORT Westinghouse510 : public QObject
{
    Q_OBJECT
public:

    //!
    //! \brief Westinghouse510 constructor of the westinghouse library object. This class has no way of explicitly
    //! \param commsObject the abstract communication object that handles/marshals commands/objects that communicate
    //! the commands/data from this class to the pump. Also, this class receives updates from this object reflecting
    //! the current status/state of the pump.
    //! \param pumpAddress numeric address of the pump
    //! \param name class name used when communicating out objects reflected in the tuple state
    //!
    Westinghouse510(const common::comms::ICommunication* commsObject, const int &pumpAddress, const std::string &name = "Westinghouse Pump");

    //! \brief ~Wetsinghouse510 default destructor of the westinghouse library object
    ~Westinghouse510()
    {
        delete initializationTimer;
        initializationTimer = nullptr;
    }

public:
    //!
    //! \brief setPumpFlowRate function transmitting the desired flow rate to the communication object.
    //! It is the role of the communication object to then transmit the desired flow rate to the appropriate
    //! device.
    //! \param desRate object reflecting the desired flow rate of the pump
    //!
    void setPumpFlowRate(const registers_WestinghousePump::Register_FlowRate &desRate);

    //!
    //! \brief setPumpOperations function transmitting the desired operational procedures of the pump.
    //! Controls operations such as run/reverse/fault/reset.
    //! \param desOps object reflecting the desired operations of the pump
    //!
    void setPumpOperations(const registers_WestinghousePump::Register_OperationSignal &desOps);


    //!
    //! \brief ceasePumpOperations
    //!
    void ceasePumpOperations();

    //!
    //! \brief setInitializationTime
    //! \param period
    //!
    void setInitializationTime(const unsigned int &interval);

    //!
    //! \brief isPumpConnected
    //! \return
    //!
    bool isPumpConnected() const;

    //!
    //! \brief openPumpConnection
    //!
    void openPumpConnection();


public:

    void logOperationalSettings(QFile* filePath) const;

    void saveToFile(const QString &filePath);

    void openFromFile(const QString &filePath);

private:

    //!
    //! \brief parseReceivedMessage function that shall parse the msg object to determine what feedback
    //! was received from the pump.
    //! \param msg generic message data type containing the byte array of the received data from the pump
    //!
    void parseReceivedMessage(const comms_WestinghousePump::WestinghouseMessage &msg);

signals:
    //!
    //! \brief signal_PumpConnectionUpdate signal emitted when something about the connection has changed and/or been modified
    //! \param obj generic data type containing the status of the resulting connection update
    //!
    void signal_PumpCommunicationUpdate(const common::comms::CommunicationUpdate &obj);

    //!
    //! \brief signal_PumpFlowUpdated signal emitted when the pump has acknowledged that the pump flow rate has been changed
    //! \param value the explicit flow rate of the pump
    //!
    void signal_PumpFlowUpdated(const double &value);

    //!
    //! \brief signal_PumpOperating signal emitted when the pump has acknowledged that the pump is in operation
    //! \param value explicit condition acknowledging true when the pump is running
    //!
    void signal_PumpOperating(const bool &value);

    //!
    //! \brief signal_PumpInitialized signal emitted indicating the pump has initialized past the establised period
    //!
    void signal_PumpInitialized();


private slots:
    //!
    //! \brief slot_SerialPortReadyToConnect slot that catches the ICommunication callback denoting when the device is ready to
    //! accept requests to open connections to the pump.
    //!
    void slot_SerialPortReadyToConnect();

    //!
    //! \brief slot_SerialPortUpdate
    //! \param update
    //!
    void slot_SerialPortUpdate(const common::comms::CommunicationUpdate &update);

    //!
    //! \brief slot_SerialPortReceivedData
    //! \param data
    //!
    void slot_SerialPortReceivedData(const QByteArray &data);

    //!
    //! \brief slot_PumpInitializationComplete slot that catches the initialization timeout
    //! signal to indicate there has been sufficient time passed since the pump has turned on
    //! to pass fluids and begin operation.
    //!
    void slot_PumpInitializationComplete();

public:
    Westinghouse510_State* m_State;

private:
    const common::comms::ICommunication* m_Comms;
    comms_WestinghousePump::WestinghouseDataFraming* m_DataFraming;
    std::string deviceName;

    QTimer* initializationTimer;
};

#endif // WESTINGHOUSE_510_H
