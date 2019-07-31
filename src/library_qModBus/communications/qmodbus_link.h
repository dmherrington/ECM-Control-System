#ifndef QMODBUS_LINK_H
#define QMODBUS_LINK_H

#include <mutex>
#include <iostream>
#include <thread>
#include <memory>

#include <QCoreApplication>
#include <QThread>
#include <QTimer>

#include "common/comms/serial_configuration.h"

#include "i_link.h"
#include "modbus.h"
#include "qmodbus_session.h"

/**
\* @file  qmodbus_link.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is interact with the sensoray.
\*
\* @section DESCRIPTION
\*
\*
\*/

namespace comms_QModBus {

class QModBusLink : public ILink
{
public:

    QModBusLink();

    ~QModBusLink() override;

public:
    virtual void RequestReset() override;

    void _emitLinkError(const std::string& errorMsg) const;

public:
    void setSerialConfiguration(const common::comms::SerialConfiguration &config) override;

    void setTCPConfiguration(const common::comms::TCPConfiguration &config) override;

    bool ConnectToDevice(void) override;

    bool DisconnectFromDevice (void) override;

    bool isConnected() const override;

    void SetSlaveAddress(const unsigned int &slaveAddress) override;

    bool WriteSingleRegister(const unsigned long &dataRegister, const unsigned long &data) const override;

    bool ReadInputRegisters(const unsigned int &startingRegister, const size_t numRegisters, QByteArray &data) const override;
public:
    unsigned int GetSlaveAddress() const override;

public:
    virtual void MarshalOnThread(std::function<void()> func) override{
        ///////////////////
        /// Determine what thread to run function on
        QThread *threadToMashalOn = m_ListenThread;
        QThread *currentThread = QThread::currentThread();

        //the current thread is the thread that link operates on
        if(threadToMashalOn == currentThread)
        {
            func();
        }
        else {
            postToThread([func](){
                func();
            }, m_Session);
        }
    }

private:
    template <typename F>
    static void postToThread(F && fun, QObject * obj = qApp) {
      struct Event : public QEvent {
        F fun;
        Event(F && fun) : QEvent(QEvent::None), fun(std::move(fun)) {}
        ~Event() {
            fun();
        }
      };
      QCoreApplication::postEvent(obj, new Event(std::move(fun)));
    }

private:
    /// Performs the actual hardware port connection.
    ///     @param[out] error if failed
    ///     @param[out] error string if failed
    /// @return success/fail
    bool _hardwareConnect();


private:
    unsigned int slaveID;

    QModBusSession* m_Session; /**< Member variable containing a pointer to the current QModBus API session*/
    QThread *m_ListenThread;
};

} //end of namepsace comms_QModBus

#endif // QMODBUS_LINK_H
