#ifndef SERIALLINK_H
#define SERIALLINK_H

#include <chrono>
#include <mutex>
#include <iostream>
#include <thread>

#include <QCoreApplication>
#include <QThread>

#include "i_link.h"

namespace Comms
{



class GalilLink : public ILink
{
public:

    GalilLink();

    ~GalilLink();

    virtual void RequestReset();

    virtual void WriteBytes(const char *bytes, int length) const;

    //!
    //! \brief Determine the connection status
    //! \return True if the connection is established, false otherwise
    //!
    virtual bool isConnected() const;

    virtual bool Connect(void);

    virtual void Disconnect(void);

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


    void _readBytes(void);

private:

    void PortEventLoop();


private:
    QThread *m_ListenThread;

    volatile bool        m_stop;
    volatile bool        m_reqReset;
    std::mutex           m_stopMutex;      // Mutex for accessing _stopp
};

} //END MAVLINKComms

#endif // SERIALLINK_H
