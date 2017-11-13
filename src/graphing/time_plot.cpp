#include "time_plot.h"

namespace graphing {

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

}


} //end of namespace graphing
