#ifndef TIME_PLOT_H
#define TIME_PLOT_H

#include <QMutex>

#include "graphing_global.h"
#include "qcustomplot.h"

namespace graphing
{

//!
//! \brief Abstract base class for a plot based on time
//!
class GRAPHINGSHARED_EXPORT TimePlot : public QCustomPlot
{
Q_OBJECT
public:

    //!
    //! \brief Time dimensions that can be used
    //!
    enum TimeUnit
    {
        MILLISECONDS,
        SECONDS,
        MINUTES,
        HOURS,
        DAYS
    };


// //////////////////////////////////////////////////////////////
// ////////////// STATIC METHODS ////////////////////////////////
// //////////////////////////////////////////////////////////////

    //!
    //! \brief static method to convert a TimeUnit enum to a string
    //! \param unitType element in enumeration
    //! \return string
    //!
    static QString TimeUnitToString(const TimeUnit &unitType);


    //!
    //! \brief PlaybackUnitString_to_Enum
    //! \param unitString string
    //! \return element in enumeration
    //!
    static TimeUnit StringToTimeUnit(const QString &unitString);


    //!
    //! \brief Static method to determine number of milliseconds per TimeUnit value
    //! \param unit member of enumeration
    //! \return Number of milliseconds in unit
    //!
    static double MsInTimeUnit(const TimeUnit unit);


    //!
    //! \brief Constructor
    //! \param parent
    //!
    TimePlot(QWidget *parent = 0);


// //////////////////////////////////////////////////////////////
// ////////////// PUBLIC METHODS ////////////////////////////////
// //////////////////////////////////////////////////////////////

    //!
    //! \brief set the origin time of the plot
    //!
    //! The origin time is the time which will be plotted at zero.
    //! \param originTime time to shift x axis to zero
    //!
    virtual void setOriginTime(const QDateTime &originTime) = 0;


    //!
    //! \brief Change the unit graphed along playback window
    //! \param unit Unit to change to
    //!
    virtual void ChangeUnit(const TimeUnit &unit) = 0;


protected:


    //!
    //! \brief Marshal a replot on the GUI thread
    //! \param refresh priority to pass to the underlaying object
    //!
    Q_INVOKABLE void Replot(QCustomPlot::RefreshPriority refreshPriority = QCustomPlot::rpHint);

    //! boolean indicating if a replot has already been qued
    bool m_ReplotQued;

    QMutex m_RedrawMutex;

private:

    bool m_Locked;

};

} //end of namespace graphing

#endif // TIME_PLOT_H
