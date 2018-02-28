#ifndef THREADED_SCHEDULER_H
#define THREADED_SCHEDULER_H

#include <QThread>
#include <QTimer>
#include <QMutex>

#include "common_global.h"

//!
//! \brief This class impliments a scheduler that can be used to mashal methods on their own thread.
//!
//! To perform work in thread, user of this class is to connect their slot to the PerformWork signal using Qt::DirectConnection.
//!
//! This class automatically throttles work according to the speed of the thread.
//! The user of this class is to call Called() when the scheduler can schedule again.
//! This is to prevent the working thread here to become bogged with requests.
//!
class COMMONSHARED_EXPORT ThreadedScheduler : public QObject
{
    Q_OBJECT

public:

    //!
    //! \brief Constructor
    //! \param parent
    //!
    inline ThreadedScheduler(QObject *parent = 0) :
        QObject(parent),
        m_Thread(this),
        m_Scheduled(false)
    {
        this->moveToThread(&m_Thread);
        m_Thread.start();
    }


    //!
    //! \brief Destructor
    //!
    //! Close out the thread and wait for exit.
    //!
    inline ~ThreadedScheduler()
    {
        m_Thread.exit(0);
        m_Thread.wait();
    }


    //!
    //! \brief Schedule work to be performed, the PerformWork will be called when thread is ready.
    //!
    //! Will do nothing if already scheduled and not been called yet
    //!
    inline void Schedule()
    {
        //if already scehduled don't do nothing
        m_ScheduleLocker.lock();
        if(m_Scheduled == true)
        {
            m_ScheduleLocker.unlock();
            return;
        }
        m_Scheduled = true;
        m_ScheduleLocker.unlock();

        //invoke work method on the work thread.
        if (this->thread() != QThread::currentThread())
        {
            QMetaObject::invokeMethod(this, "CallWork", Qt::QueuedConnection);
            return;
        }
    }


    //!
    //! \brief Method to be called when work has been performed or is to be allowed to schedule again.
    //!
    inline void Called()
    {
        m_Scheduled = false;
    }

private:


    //!
    //! \brief Work method, emits signal
    //!
    Q_INVOKABLE inline void CallWork()
    {
        emit PerformWork();
    }

signals:

    //!
    //! \brief Signal to indicate work to be done
    //!
    //! This signal will be called in its own thread context
    //!
    void PerformWork();

private:

    //! Thread work is to be performed on.
    QThread m_Thread;

    //! boolean indicating if the work is already scheduled
    bool m_Scheduled;

    QMutex m_ScheduleLocker;

};

#endif /* THREADED_SCHEDULER_H */
