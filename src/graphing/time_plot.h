#ifndef TIME_PLOT_H
#define TIME_PLOT_H

#include "graphing_global.h"

#include "qcustomplot.h"

namespace graphing{

class GRAPHINGSHARED_EXPORT TimePlot : public QCustomPlot
{
    Q_OBJECT
public:
    //!
    //! \brief Constructor
    //! \param parent
    //!
    TimePlot(QWidget *parent = 0);

protected:
    //!
    //! \brief Marshal a replot on the GUI thread
    //! \param refresh priority to pass to the underlaying object
    //!
    Q_INVOKABLE void Replot(QCustomPlot::RefreshPriority refreshPriority = QCustomPlot::rpRefreshHint);

    //! boolean indicating if a replot has already been qued
    bool m_ReplotQued;

    QMutex m_RedrawMutex;

private:
    bool m_Locked;
};

} //end of namespace graphing

#endif // TIME_PLOT_H
