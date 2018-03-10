#include "time_plot.h"

#include <stdexcept>
#include <QThread>

namespace graphing {

// //////////////////////////////////////////////////////////////
// ////////////// STATIC METHODS ////////////////////////////////
// //////////////////////////////////////////////////////////////

//!
//! \brief static method to convert a TimeUnit enum to a string
//! \param unitType element in enumeration
//! \return string
//!
TimePlot::TimeUnit TimePlot::StringToTimeUnit(const QString &unitString)
{
    TimeUnit unitEnum;
    if(unitString == "Days")
        unitEnum = DAYS;
    else if(unitString == "Hours")
        unitEnum = HOURS;
    else if(unitString == "Minutes")
        unitEnum = MINUTES;
    else if(unitString == "Seconds")
        unitEnum = SECONDS;
    else if(unitString == "Milliseconds")
        unitEnum = MILLISECONDS;
    else
        throw new std::runtime_error("Unknown String seen");

    return unitEnum;
}


//!
//! \brief PlaybackUnitString_to_Enum
//! \param unitString string
//! \return element in enumeration
//!
QString TimePlot::TimeUnitToString(const TimeUnit &unitType)
{
    QString returnString;
    switch(unitType)
    {
    case DAYS:
        returnString = "Days";
        break;
    case HOURS:
        returnString = "Hours";
        break;
    case MINUTES:
        returnString = "Minutes";
        break;
    case SECONDS:
        returnString = "Seconds";
        break;
    case MILLISECONDS:
        returnString = "Milliseconds";
        break;
    default:
        throw new std::runtime_error("Unknown enumeration seen");
    }

    return returnString;
}


//!
//! \brief Static method to determine number of milliseconds per TimeUnit value
//! \param unit member of enumeration
//! \return Number of milliseconds in unit
//!
double TimePlot::MsInTimeUnit(const TimeUnit unit)
{
    double msInTimeUnit;
    switch(unit)
    {
    case MILLISECONDS:
        msInTimeUnit = 1.0;
        break;
    case SECONDS:
        msInTimeUnit = 1000.0;
        break;
    case MINUTES:
        msInTimeUnit = 1000.0*60.0;
        break;
    case HOURS:
        msInTimeUnit = 1000.0*60.0*60.0;
        break;
    case DAYS:
        msInTimeUnit = 1000.0*60.0*60.0*24.0;
        break;
    default:
        throw new std::runtime_error("Unknown time unit specified");
    }

    return msInTimeUnit;
}

//!
//! \brief Constructor
//! \param parent
//!
TimePlot::TimePlot(QWidget *parent) :
    QCustomPlot(parent),
    m_ReplotQued(false),
    m_Locked(false)
{
    this->axisRect()->setRangeZoomFactor(1, this->axisRect()->rangeZoomFactor(Qt::Vertical));
}


//!
//! \brief Marshal a replot on the GUI thread
//! \param refresh priority to pass to the underlaying object
//!
void TimePlot::Replot(QCustomPlot::RefreshPriority refreshPriority)
{

    if (this->thread() != QThread::currentThread())
    {
        //if already qued, just skip
        if(m_ReplotQued == true)
            return;

        m_ReplotQued = true;
        QMetaObject::invokeMethod(this, "Replot", Qt::QueuedConnection, Q_ARG(QCustomPlot::RefreshPriority, refreshPriority));
        return;
    }

    this->replot(refreshPriority);
    m_ReplotQued = false;

}

}  //end of namespace graphing
