#ifndef PLOT_HANDLER_H
#define PLOT_HANDLER_H

#include "graphing_global.h"

#include "time_plot.h"

namespace graphing{

class GRAPHINGSHARED_EXPORT PlotHandler : public TimePlot
{
    Q_OBJECT
public:
    //!
    //! \brief Constructor
    //! \param parent
    //!
    PlotHandler(QWidget *parent = 0);

    //!
    //! \brief Destructor
    //!
    ~PlotHandler();
};

} //end of namespace graphing
#endif // PLOT_HANDLER_H
