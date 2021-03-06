#ifndef SENSORAY_TCP_LINK_H
#define SENSORAY_TCP_LINK_H

#include <mutex>
#include <iostream>
#include <thread>

#include <QCoreApplication>
#include <QThread>
#include <QTimer>

#include "sensoray_tcp_configuration.h"
#include "sensoray_serial_configuration.h"
#include "i_link.h"

#include "s24xx.h"

#include "sensoray_session.h"

/**
\* @file  sensoray_link.h
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

namespace comms_Sensoray {

class SensorayLink : public ILink
{
public:

    SensorayLink();

    ~SensorayLink();

public:
    virtual void RequestReset();

    void _emitLinkError(const std::string& errorMsg) const;

public:
    void setTCPConfiguration(const SensorayTCPConfiguration &config) override;

    bool ConnectToDevice(void) override;

    bool DisconnectFromDevice (void) override;

    bool isConnected() const override;

    void updateCurrentSession(SensoraySession* session);


public:
    std::string getDeviceAddress() const;
    int getTelnetPortNumber() const;

    common::comms::LinkConfiguration getLinkConfiguration();

    virtual void MarshalOnThread(std::function<void()> func){
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
    SensoraySession* m_Session; /**< Member variable containing a pointer to the current sensoray API session*/
    QThread *m_ListenThread;
    SensorayTCPConfiguration _config;
};

} //end of namepsace comms

#endif // SENSORAY_TCP_LINK_H
