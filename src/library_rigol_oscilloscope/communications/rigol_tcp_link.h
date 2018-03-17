#ifndef RIGOL_TCP_LINK_H
#define RIGOL_TCP_LINK_H

#include "library_rigol_oscilloscope_global.h"

#include <mutex>
#include <iostream>
#include <thread>

#include <QCoreApplication>
#include <QThread>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTimer>

#include "tcp_configuration.h"

#include "i_link.h"

namespace comms_Rigol {

class RigolTCPLink : public ILink
{
public:

    RigolTCPLink();

    ~RigolTCPLink();

public:
    virtual void RequestReset();

    void WriteBytes(const QByteArray &data_Rigol) const override;
    std::vector<uint8_t> WriteBytesRequest(const QByteArray &data_Rigol) const override;

    void _emitLinkError(const std::string& errorMsg) const;

public:
    void setTCPConfiguration(const TCPConfiguration &config) override;

    bool Connect(void) override;

    bool Disconnect(void) override;

    bool isConnected() const override;

public:
    std::string getListenAddress() const;
    int getListenPortNumber() const;
    std::string getSenderAddress() const;
    int getSenderPortNumber() const;

    LinkConfiguration getLinkConfiguration();

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
            }, m_socket);
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
    bool _hardwareConnect(QAbstractSocket::SocketError& error, QString& errorString);

private:
    std::vector<uint8_t> ProcessResponse() const;
    void linkError(QTcpSocket::SocketError error);

private:
    QTcpSocket* m_socket;
    quint64 m_bytesRead;
    int     m_timeout;
    std::thread *m_CommsThread;
    QThread *m_ListenThread;
    std::mutex  m_dataMutex;       // Mutex for reading data from _port
    std::mutex  m_writeMutex;      // Mutex for accessing the _transmitBuffer.


    volatile bool        m_stopp;
    volatile bool        m_reqReset;
    std::mutex           m_stoppMutex;      // Mutex for accessing _stopp
    TCPConfiguration _config;
};

} //end of namepsace comms_Rigol


#endif // RIGOL_TCP_LINK_H
