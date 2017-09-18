#include "plot_handler.h"

namespace graphing {

PlotHandler::PlotHandler(QWidget *parent) :
    TimePlot(parent)
{
    this->addGraph();

}

//!
//! \brief Destructor
//!
PlotHandler::~PlotHandler()
{

}

} //end of namespace graphing
