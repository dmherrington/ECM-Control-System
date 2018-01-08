#ifndef SERIALLINK_H
#define SERIALLINK_H

#include <chrono>
#include <mutex>
#include <iostream>
#include <thread>

#include <QCoreApplication>
#include <QThread>

#include "gclib.h"
#include "gclibo.h"

#include "i_link.h"
#include "requests/abstract_request.h"
#include "commands/abstract_command.h"

namespace Comms
{

class GalilLink : public ILink
{
public:

    GalilLink();

    ~GalilLink();

public:

    GReturn UploadProgram(const std::string &programText) const override;

    GReturn WriteRequest(AbstractRequest* request) const override;

    GReturn WriteCommand(AbstractCommand *command) const override;

    GReturn WriteTellErrorCode(char* errorDescription) const override;

    //!
    //! \brief Determine the connection status
    //! \return True if the connection is established, false otherwise
    //!
    bool isConnected() const override;

    bool Connect(void) override;

    bool Disconnect(void) override;

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
    GCon galil; /**< Member variable containing a pointer to the Galil interface */
    std::string galilAddress; /**< Member variable containing information about the address to the Galil unit. */

    bool connected;
};

} //END MAVLINKComms

#endif // SERIALLINK_H
