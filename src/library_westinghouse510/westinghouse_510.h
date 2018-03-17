#ifndef WESTINGHOUSE_510_H
#define WESTINGHOUSE_510_H

#include <QObject>
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
    Westinghouse510(const common::comms::ICommunication* commsObject, const int &pumpAddress);

    ~Westinghouse510() = default;

    void setPumpFlowRate(const registers_WestinghousePump::Register_FlowRate &desRate);
    void setPumpOperations(const registers_WestinghousePump::Register_OperationSignal &desOps);

private:
    void parseReceivedMessage(const comms_WestinghousePump::WestinghouseMessage &msg);

signals:
    void signal_PumpFlowUpdated(const double &value);
    void signal_PumpOperating(const bool &value);

private slots:
    void slot_SerialPortConnection(const common::comms::CommunicationConnection &update);
    void slot_SerialPortUpdate(const common::comms::CommunicationUpdate &connection);
public slots:
    void slot_SerialPortReceivedData(const QByteArray &data);


public:
    Westinghouse510_State* m_State;

private:
    const common::comms::ICommunication* m_Comms;
    comms_WestinghousePump::WestinghouseDataFraming* m_DataFraming;
};

#endif // WESTINGHOUSE_510_H
