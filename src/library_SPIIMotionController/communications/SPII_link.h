#ifndef SPIILINK_H
#define SPIILINK_H

#include <chrono>
#include <mutex>
#include <iostream>
#include <thread>

#include <QString>
#include <QCoreApplication>
#include <QThread>

#include "ACSC.h"

#include "i_link.h"

namespace Comms
{

class SPIILink : public ILink
{
public:

    SPIILink();

    ~SPIILink();

public:

    //!
    //! \brief Determine the connection status
    //! \return True if the connection is established, false otherwise
    //!
    bool isConnected() const override;

    void Connect(void) override;

    void Disconnect(void) override;

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
    QThread *m_ListenThread;
    HANDLE m_SPII; /**< Member variable containing a pointer to the Galil interface */

    bool connected;
};

} //end of namespace Comms

#endif // GALILLINK_H
