#ifndef MUNK_SERIAL_LINK_H
#define MUNK_SERIAL_LINK_H

#include <chrono>
#include <mutex>
#include <iostream>
#include <thread>

#include <QCoreApplication>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QThread>

#include "i_link.h"
#include "serial_configuration.h"

namespace munk {
namespace comms{

class MunkSerialLink : public ILink
{
public:

    MunkSerialLink();

    ~MunkSerialLink();

public:
    virtual void RequestReset();

    virtual void WriteBytes(const QByteArray &data) const;

    void _emitLinkError(const std::string& errorMsg) const;

public:
    void setSerialConfiguration(const SerialConfiguration &config) override;

    bool Connect(void) override;

    bool Disconnect(void) override;

    bool isConnected() const override;

    std::string getPortName() const;

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
            });
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
    bool _hardwareConnect(QSerialPort::SerialPortError& error, QString& errorString);

private:
    void _readBytes(void);
    void linkError(QSerialPort::SerialPortError error);

private:
    void PortEventLoop();

private:
    QThread* m_ListenThread;
    QSerialPort* m_port;

    quint64 m_bytesRead;
    int     m_timeout;
    std::mutex  m_dataMutex;       // Mutex for reading data from _port
    std::mutex  m_writeMutex;      // Mutex for accessing the _transmitBuffer.


    bool connected;
    volatile bool        m_stopp;
    volatile bool        m_reqReset;
    std::mutex           m_stoppMutex;      // Mutex for accessing _stopp
    SerialConfiguration _config;

};

} //end of namespace comms
} //end of namespace munk

#endif // MUNK_SERIAL_LINK_H
