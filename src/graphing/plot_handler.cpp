#include "plot_handler.h"

#include <stdexcept>

#include <QMenu>

#include <QThread>
#include <QFileInfo>


namespace graphing {


// //////////////////////////////////////////////////////////////
// ////////////// PUBLIC METHODS ////////////////////////////////
// //////////////////////////////////////////////////////////////


//!
//! \brief Constructor
//! \param parent
//!
PlotHandler::PlotHandler(QWidget *parent) :
    TimePlot(parent),
    m_PlotMode(PLOT_ENTIRE_SEQUENCE)
{
    m_FigureProperties.grid = true;
    m_FigureProperties.grid_custom = false;
    m_FigureProperties.xGridSpacing = this->xAxis->tickStep();
    m_FigureProperties.yGridSpacing = this->yAxis->tickStep();

    //NULL origin time
    m_OriginTime.setMSecsSinceEpoch(0);
    m_OriginTime_msSinceEpoch = 0;

    m_FigureProperties.legend = false;

    m_FigureProperties.window_custom = false;
    m_FigureProperties.yWindow_max = 20.000;
    m_FigureProperties.yWindow_min = 0.000;


    m_TimeUnit = SECONDS;

    //connect user interface signals
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuRequest(QPoint)));
    connect(this, SIGNAL(selectionChangedByUser()),this,SLOT(SelectionChanged()));
    //connect(this, SIGNAL(mouseWheel(QWheelEvent*)),this,SLOT(WindowScrolled()));
    connect(this, SIGNAL(beforeReplot()),this,SLOT(CalculateCurrentTimeBar()));

    connect(this, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(RecalculatePlots()));
    connect(this, SIGNAL(mouseDoubleClick(QMouseEvent*)), this, SLOT(on_double_click(QMouseEvent*)));

    this->rescaleAxes(true);

    m_CurrTimeGraph = this->addGraph();
    m_CurrTimeGraph->setPen(QPen(Qt::red));
    m_CurrTimeGraph->setLineStyle(QCPGraph::lsLine);
    m_CurrTimeGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::red, Qt::red, 10));

    this->legend->clear();
    this->setContextMenuPolicy(Qt::CustomContextMenu);


    setInteractions(QCP::iRangeDrag | QCP::iSelectLegend | QCP::iRangeZoom | QCP::iSelectPlottables | QCP::iSelectAxes | QCP::iSelectOther);
    yAxis->setLabel("Response");

    connect(&m_RecalculateScheduler, SIGNAL(PerformWork()), this, SLOT(DoPlotRecalculate()), Qt::DirectConnection);

    addLayer("LayerEvents");

    // QtDefualt Color Scheme
    m_FigureProperties.background_color = Qt::white;
    m_FigureProperties.text_color = Qt::black;
    m_FigureProperties.grid_penColor = QPen(QColor(200,200,200), 0, Qt::DotLine);
    m_FigureProperties.grid_subPenColor = QPen(QColor(220,220,220), 0, Qt::DotLine);
    m_FigureProperties.grid_zeroLineColor = QPen(QColor(200,200,200), 0, Qt::SolidLine);
    setBackground(QBrush(m_FigureProperties.background_color, Qt::SolidPattern));


    //do not automatically add elements to legend, prevents event bars from displaying
    this->setAutoAddPlottableToLegend(false);

    Replot(rpHint);
}


//!
//! \brief Destructor
//!
PlotHandler::~PlotHandler()
{
    mReplotting.lock();
    for (int i=0 ; i < m_PlotParameters.count() ; i++)
    {
        for(int j = 0 ; j < m_PlotParameters[i].g.size() ; j++)
            MarshalRemoveGraph(m_PlotParameters[i].g.at(j));
    }
    m_PlotParameters.clear();
    mReplotting.unlock();
}


void PlotHandler::SupplyPlotCollection(const common_data::observation::ObservationCollection* collection)
{
    m_ObservationCollection = collection;
}


//!
//! \brief Change mode of operation
//! \param mode Mode to change to
//!
void PlotHandler::ChangeMode(const PlotMode mode)
{
    m_PlotMode = mode;
}


//!
//! \brief Graph data on plot instance
//! \param dataKey Key to indentify data
//!
void PlotHandler::AddPlot(const common_data::observation::IPlotComparablePtr expression)
{
    bool found = false;
    for (int i = 0; i < m_PlotParameters.size(); i++)
    {
        if (m_PlotParameters.at(i).operation == expression)
        {
            found = true;
        }
    }

    //if we already have the plot added, don't do anything.
    if(found == true)
        return;

    plot_data_variables User_Data;
    User_Data.operation = expression;
    User_Data.observations = m_ObservationCollection;
    User_Data.GraphColor.setRgb(rand() % 255, rand() % 255, rand() % 255);
    User_Data.DisplayName = "";
    User_Data.unitVariable = m_TimeUnit;
    User_Data.GraphNumber = m_PlotParameters.size();
    User_Data.Redraw = true;
    User_Data.Selected = false;
    User_Data.g = QVector<QCPGraph*>();


    m_PlotParameters.append(User_Data);
    RecalculatePlots();

    //emit PlotAdded(expression);
}


//!
//! \brief Retreive a list of all active expressions
//! \return List of active expressions
//!
QList<std::shared_ptr<common_data::observation::IPlotComparable>> PlotHandler::ActiveExpressions() const
{
    QList<std::shared_ptr<common_data::observation::IPlotComparable>> list;
    for (int i = 0; i < m_PlotParameters.size(); i++)
    {
        list.append(m_PlotParameters.at(i).operation);
    }

    return list;
}


//!
//! \brief Change name of a plot to be displayed
//! \param dataKey Plot to change name of
//! \param displayName Name to change to
//!
void PlotHandler::ChangeName(const common::TupleECMData &tuple, const QString &displayName)
{
//    for (int i = 0; i < m_PlotParameters.size(); i++) {
//        if (m_PlotParameters.at(i).operation == tuple)
//        {
//            if(m_PlotParameters.at(i).DisplayName != displayName)
//            {
//                m_PlotParameters[i].DisplayName = displayName;
//                RecalculatePlots();
//            }
//            break;
//        }
//    }
}


//!
//! \brief Change the color of a plot to be displayed
//! \param dataKey Plot to change color of
//! \param color Colour to change to
//!
void PlotHandler::ChangeColor(const common::TupleECMData &tuple, const QColor &color)
{
//    for (int i = 0; i < m_PlotParameters.size(); i++) {
//        if (m_PlotParameters.at(i).operation == tuple)
//        {
//            if(m_PlotParameters.at(i).GraphColor != color)
//            {
//                m_PlotParameters[i].GraphColor = color;
//                m_PlotParameters[i].Redraw = true;
//                RecalculatePlots();
//            }
//            break;
//        }
//    }
}


//!
//! \brief Redraw all expressions that rely on the provided data sources
//! \param source Data sources to redraw
//!
void PlotHandler::RedrawDataSource(const QList<std::shared_ptr<common_data::observation::IPlotComparable> > &sources)
{
    for (int i = 0 ; i < m_PlotParameters.size() ; i++)
    {
        for(int j = 0 ; j < sources.size() ; j++)
        {

            if(m_PlotParameters.at(i).operation == sources.at(i)->CreateSharedPtr())
                m_PlotParameters[i].Redraw = true;
        }
    }

    RecalculatePlots();
}



//!
//! \brief Add an event indicator to ploting instance
//! \param time time to put event
//! \param name name of event
//! \param msg message about event
//! \param color color to draw event indicator
//! \param style Style to draw line
//!
void PlotHandler::AddEvent(const QDateTime &time, const QString &name, const QString &msg, const QColor &color, const Qt::PenStyle &style)
{
    //todo - set style
    UNUSED(style);

    QPen eventPen;
    //eventPen.setWidth(0.7);
    eventPen.setColor(color);
    eventPen.setStyle(Qt::DashLine);

    QCPCurve *newBar = new QCPCurve(xAxis, yAxis);
    newBar->setVisible(true);
    newBar->setName(name);
    newBar->setPen(eventPen);
    newBar->setLayer("LayerEvents");
    addPlottable(newBar);

    Event newEvent;
    newEvent.PlotBar = newBar;
    newEvent.t = time;
    newEvent.title = name;
    newEvent.msg = msg;

    m_EventBarList.append(newEvent);

    RecalculatePlots();
}


//!
//! \brief Remove a graph from plot
//! \param dataKey Key of data to remove
//!
void PlotHandler::RemoveGraphData(const common::TupleECMData &tuple)
{
//    for (int i = 0; i < m_PlotParameters.size(); i++)
//    {
//        if (m_PlotParameters.at(i).operation == operation)
//        {
//            for(int j = 0 ; j < m_PlotParameters[i].g.size() ; j++)
//                MarshalRemoveGraph(m_PlotParameters[i].g.at(j));
//            m_PlotParameters.removeAt(i);
//            Draw();
//            break;
//        }
//    }
}


//!
//! \brief set the origin time of the plot
//!
//! The origin time is the time which will be plotted at zero.
//! \param originTime time to shift x axis to zero
//!
void PlotHandler::setOriginTime(const QDateTime &originTime)
{
    m_OriginTime = originTime;
    m_OriginTime_msSinceEpoch = m_OriginTime.toMSecsSinceEpoch();
    RecalculatePlots();
}


//!
//! \brief Set the unit this plot represents time
//! \param unitType Unit to represent time
//!
void PlotHandler::ChangeUnit(const TimeUnit &unitType)
{
    double OldMsInTimeUnit = MsInTimeUnit(m_TimeUnit);

    m_TimeUnit = unitType;
    QString SelectedString;
    SelectedString = TimeUnitToString(m_TimeUnit);
    this->xAxis->setLabel(SelectedString);

    //re-determine axis range
    double msInTimeUnit = MsInTimeUnit(m_TimeUnit);
    this->xAxis->setRange(xAxis->range().lower / (msInTimeUnit/OldMsInTimeUnit), xAxis->range().upper * OldMsInTimeUnit/msInTimeUnit);

    //move current indicator graph
    QCPData currentIndicatorPos1 = m_CurrTimeGraph->data()->begin().value();
    QCPData currentIndicatorPos2 = m_CurrTimeGraph->data()->end().value();
    m_CurrTimeGraph->clearData();
    QVector<double> xdata; xdata.append(currentIndicatorPos1.key/ (msInTimeUnit/OldMsInTimeUnit)); xdata.append(currentIndicatorPos2.key/ (msInTimeUnit/OldMsInTimeUnit));
    QVector<double> ydata; ydata.append(currentIndicatorPos1.value); ydata.append(currentIndicatorPos2.value);
    m_CurrTimeGraph->setData(xdata, ydata);

    //redraw each plot
    for (int i = 0 ; i < m_PlotParameters.count() ; i++)
    {
        m_PlotParameters[i].Redraw = true;
    }

    RecalculatePlots();
}

//!
//! \brief Change the color scheme between Qt Default and Dark
//! \param true if Qt Default, false if Dark
//!
void PlotHandler::ChangeColorScheme(bool scheme)
{
    if(scheme == true) //true = Qt Default
    {
        // QtDefualt Color Scheme
        m_FigureProperties.background_color = Qt::white;
        m_FigureProperties.text_color = Qt::black;
        m_FigureProperties.grid_penColor = QPen(QColor(200,200,200), 0, Qt::DotLine);
        m_FigureProperties.grid_subPenColor = QPen(QColor(220,220,220), 0, Qt::DotLine);
        m_FigureProperties.grid_zeroLineColor = QPen(QColor(200,200,200), 0, Qt::SolidLine);
    }
    else if(scheme == false) //false = Dark
    {
        //Dark Color Scheme:
        m_FigureProperties.background_color = QColor(125,125,125);
        m_FigureProperties.text_color = Qt::white;
        m_FigureProperties.grid_penColor = QPen(QColor(50,50,50), 0, Qt::DotLine);
        m_FigureProperties.grid_subPenColor = QPen(QColor(70,70,70), 0, Qt::DotLine);
        m_FigureProperties.grid_zeroLineColor = QPen(QColor(50,50,50), 0, Qt::SolidLine);
    }


    // Background and Tick/Label colors
    setBackground(m_FigureProperties.background_color);
    xAxis->setTickLabelColor(m_FigureProperties.text_color);
    xAxis->setLabelColor(m_FigureProperties.text_color);
    yAxis->setTickLabelColor(m_FigureProperties.text_color);
    yAxis->setLabelColor(m_FigureProperties.text_color);


    // X-Axis Grid colors/properties
    xAxis->grid()->setPen(m_FigureProperties.grid_penColor);
    xAxis->grid()->setSubGridPen(m_FigureProperties.grid_subPenColor);
    xAxis->grid()->setZeroLinePen(m_FigureProperties.grid_zeroLineColor);
    xAxis->grid()->setSubGridVisible(false);
    xAxis->grid()->setAntialiased(false);
    xAxis->grid()->setAntialiasedSubGrid(false);
    xAxis->grid()->setAntialiasedZeroLine(false);

    // Y-Axis Grid colors/properties
    yAxis->grid()->setPen(m_FigureProperties.grid_penColor);
    yAxis->grid()->setSubGridPen(m_FigureProperties.grid_subPenColor);
    yAxis->grid()->setZeroLinePen(m_FigureProperties.grid_zeroLineColor);
    yAxis->grid()->setSubGridVisible(false);
    yAxis->grid()->setAntialiased(false);
    yAxis->grid()->setAntialiasedSubGrid(false);
    yAxis->grid()->setAntialiasedZeroLine(false);


    // Replot so colors take effect
    Replot(rpHint);
}


//!
//! \brief Update the spacing tic marks on plot
//! \param xSpacing x tick marks
//! \param ySpacing y tick marks
//! \return true if allowing custom spacing
//!
bool PlotHandler::UpdateGrid(const double xSpacing, const double ySpacing)
{
    m_FigureProperties.grid_custom = !m_FigureProperties.grid_custom;

    if(m_FigureProperties.grid_custom == true)
    {
        this->xAxis->setAutoTickStep(false);
        this->yAxis->setAutoTickStep(false);

        this->xAxis->setTickStep(xSpacing);
        this->yAxis->setTickStep(ySpacing);

        Replot(rpHint);
    }
    else
    {
        this->xAxis->setAutoTickStep(true);
        this->yAxis->setAutoTickStep(true);

        Replot(rpHint);
    }

    return(m_FigureProperties.grid_custom);
}


//!
//! \brief set the ranges of the Y axis
//! \param lowWindow min value on Y axis
//! \param highWindow max value on Y axis
//! \return true if allowing custom y axis ranges
//!
bool PlotHandler::YAxisRange(double lowWindow, double highWindow)
{

    m_FigureProperties.window_custom = !m_FigureProperties.window_custom;

    if(m_FigureProperties.window_custom == true)
    {
        this->yAxis->rescale(false);
        this->yAxis->setRange(lowWindow,highWindow);

        Replot(rpHint);
    }
    else
    {
        this->graph(0)->clearData();
        this->yAxis->rescale(true);
        Replot(rpHint);
    }

    return(m_FigureProperties.window_custom);
}

//!
//! \brief Toggle the legend on or off
//! \return true if legend is now on
//!
bool PlotHandler::ToggleGrid()
{
    m_FigureProperties.grid = !m_FigureProperties.grid;
    this->xAxis->grid()->setVisible(m_FigureProperties.grid);
    this->yAxis->grid()->setVisible(m_FigureProperties.grid);
    Replot(rpHint);
    return(m_FigureProperties.grid);
}

//!
//! \brief Toggle the grid on or off
//! \return true if grid is now on
//!
bool PlotHandler::ToggleLegend()
{
    m_FigureProperties.legend = !m_FigureProperties.legend;
    this->legend->setVisible(m_FigureProperties.legend);
    Replot(rpHint);
    return(m_FigureProperties.legend);
}


//!
//! \brief Export the current graph to an image file
//!
//! Will check the provided file suffix for either .png, .jpg/.jpeg, .png, or .bmp
//! Events and current time indicators are turned off when plotting
//! \param File to save to
//! \return false if given faulty suffix
//!
bool PlotHandler::ExportToImage(const QString &fileToExportTo)
{
    m_CurrTimeGraph->setVisible(false);
    for(int i = 0 ; i < m_EventBarList.count() ; i++)
    {
        m_EventBarList.at(i).PlotBar->setVisible(false);
    }
    replot();

    QFileInfo file(fileToExportTo);

    QString suffix = file.completeSuffix();


    bool success = false;
    if(suffix == "pdf")
    {
        savePdf(fileToExportTo);
        success = true;
    }

    if(suffix == "jpg" || suffix == "jpeg")
    {
        saveJpg(fileToExportTo, 0,0,4,100);
        success = true;
    }

    if(suffix == "png")
    {
        savePng(fileToExportTo,0, 0, 4, 100);
        success = true;
    }

    if(suffix == "bmp")
    {
        saveBmp(fileToExportTo, 0, 0, 4);
        success = true;
    }

    m_CurrTimeGraph->setVisible(true);
    for(int i = 0 ; i < m_EventBarList.count() ; i++)
    {
        m_EventBarList.at(i).PlotBar->setVisible(true);
    }
    replot();

    return success;
}





// ///////////////////////////////////////////////////////////////
// ////////////// USER INTERFACE SLOTS ///////////////////////////
// ///////////////////////////////////////////////////////////////


//!
//! \brief slot to fire when user request a context menue on the plot
//! \param pos Point where user requested context menu
//!
void PlotHandler::contextMenuRequest(QPoint pos)
{
    QMenu *menu = new QMenu(this);
    menu->setAttribute(Qt::WA_DeleteOnClose);

    if (this->legend->selectTest(pos, false) >= 0) // context menu on legend requested
    {
        menu->addAction("Move to top left", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignLeft));
        menu->addAction("Move to top center", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignHCenter));
        menu->addAction("Move to top right", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignRight));
        menu->addAction("Move to bottom right", this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom|Qt::AlignRight));
        menu->addAction("Move to bottom left", this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom|Qt::AlignLeft));
    }
    else  // general context menu on graphs requested
    {
        if (this->selectedGraphs().size() > 0)
            menu->addAction("Remove selected graph", this, SLOT(removeSelectedGraph()));
        if (this->graphCount() > 0)
        {
            menu->addAction("Remove all graphs", this, SLOT(removeAllGraphs()));
            menu->addAction("Display all graphs", this, SLOT(RecalculateAllGraphs()));
        }
    }
    menu->popup(this->mapToGlobal(pos));
}


//!
//! \brief slot to fire when the graph the user has selected has changed
//!
//! This method emits a PlotSelected signal when a plot is selected
//!
void PlotHandler::SelectionChanged()
{
    //unselect all
    for (int i = 0; i < m_PlotParameters.size(); i++)
    {
            m_PlotParameters[i].Selected = false;
    }

    //find selected plot and select
    bool selectionMade = false;
    for (int i=0; i < this->m_PlotParameters.count(); i++)
    {
        for(int j = 0 ; j < m_PlotParameters.at(i).g.size() ; j++)
        {
            QCPGraph *graph = m_PlotParameters.at(i).g.at(j);
            QCPPlottableLegendItem *item = this->legend->itemWithPlottable(graph);
            if ((item != NULL && item->selected()) || (graph != NULL && graph->selected()))
            {
                m_PlotParameters[i].Selected = true;
                selectionMade = true;

            }
        }

        if(selectionMade == true)
        {
            //emit PlotSelected(m_PlotParameters.at(i).operation);
            break;
        }
    }

    for (int i=0; i < this->m_PlotParameters.count(); i++)
    {
        for(int j = 0 ; j < m_PlotParameters.at(i).g.size() ; j++)
        {
            if(m_PlotParameters.at(i).Selected == true)
            {
                QCPGraph *graph = m_PlotParameters.at(i).g.at(j);
                QCPPlottableLegendItem *item = this->legend->itemWithPlottable(graph);
                item->setSelected(true);
                graph->setSelected(true);
            }
        }
    }


    if(selectionMade == false)
        emit PlotUnselected();
}



//!
//! \brief slot to fire when the use scrolls the window
//!
void PlotHandler::WindowScrolled()
{
    CurrentTime(m_CurrTime);
}


//!
//! \brief slot to fire when user double click the plot
//! \param event mouse event parameters
//!
void PlotHandler::on_double_click(QMouseEvent *event)
{
    double x = this->xAxis->pixelToCoord(event->pos().x());

    double msInTime = MsInTimeUnit(m_TimeUnit);

    QDateTime timeClick;
    timeClick.setMSecsSinceEpoch(x*msInTime + m_OriginTime_msSinceEpoch);
    emit DoubleClick(timeClick);
}


void PlotHandler::moveLegend()
{
  if (QAction* contextAction = qobject_cast<QAction*>(sender())) // make sure this slot is really called by a context menu action, so it carries the data we need
  {
    bool ok;
    int dataInt = contextAction->data().toInt(&ok);
    if (ok)
    {
      this->axisRect()->insetLayout()->setInsetAlignment(0, (Qt::Alignment)dataInt);
      Replot(rpHint);
    }
  }
}


// ///////////////////////////////////////////////////////////////
// ////////////// PLOT MANIPULATION SLOTS ////////////////////////
// ///////////////////////////////////////////////////////////////


//!
//! \brief Display all graphs from the plot instance
//!
void PlotHandler::RecalculateAllGraphs()
{
    for (int i=0 ; i < m_PlotParameters.count() ; i++)
    {
        m_PlotParameters[i].Redraw = true;
    }
    RecalculatePlots();
}

//!
//! \brief Remove the selected graph from the plot
//!
void PlotHandler::removeSelectedGraph()
{
//    bool selected = false;
//    std::string deletedExpr;
//    //loop through all graphs
//    for (int i=0 ; i < m_PlotParameters.count() ; i++)
//    {
//        if(m_PlotParameters.at(i).Selected == false)
//            continue;

//        m_PlotParametersMutex.lock();


//        for(int j = 0 ; j < m_PlotParameters.at(i).g.size() ; j++)
//        {
//            //if a graph is selected and has a corresponding plot remove it
//            //if (m_PlotParameters.at(i).g != NULL && m_PlotParameters[i].Selected == true)
//            if (m_PlotParameters.at(i).g.at(j) != NULL)
//                MarshalRemoveGraph(m_PlotParameters[i].g.at(j));
//        }

//        deletedExpr = m_PlotParameters[i].operation;
//        selected = true;
//        m_PlotParameters.removeAt(i);
//        Draw();

//        m_PlotParametersMutex.unlock();
//        break;
//    }

//    if(selected)
//        emit PlotDelete(deletedExpr);
}


//!
//! \brief Remove all graphs from the plot instance
//!
void PlotHandler::removeAllGraphs()
{
//    QList<std::shared_ptr<common_data::observation::IPlotComparable>> removedExpressions;
//    m_PlotParametersMutex.lock();
//    for (int i=0 ; i < m_PlotParameters.count() ; i++)
//    {
//        for(int j = 0 ; j < m_PlotParameters[i].g.size() ; j++)
//        {
//            MarshalRemoveGraph(m_PlotParameters[i].g.at(j));
//        }
//        removedExpressions.append(m_PlotParameters[i].operation);
//    }
//    m_PlotParameters.clear();
//    m_PlotParametersMutex.unlock();
//    Draw();


//    //emit signal that we deleted
//    for (int i = 0 ; i < removedExpressions.size() ; i++)
//    {
//        emit PlotDelete(removedExpressions.at(i));
//    }
}


//!
//! \brief Modify the window the xAxis is currently viewing
//! \param leftWindow left edge of window
//! \param rightWindow right edge of window
//!
void PlotHandler::ViewWindow(const QDateTime &leftWindow, const QDateTime &rightWindow)
{
    m_LeftWindow = leftWindow;
    double msInTimeUnit = MsInTimeUnit(m_TimeUnit);
    double lower = (double)((leftWindow.toMSecsSinceEpoch() - m_OriginTime_msSinceEpoch) / msInTimeUnit);
    double higher = (double)((rightWindow.toMSecsSinceEpoch() - m_OriginTime_msSinceEpoch) / msInTimeUnit);

    this->xAxis->setRange(lower, higher);
}


//!
//! \brief Slot to fire when current time of test changes
//! \param new current time
//!
void PlotHandler::CurrentTime(const QDateTime &currentTime)
{
    if(m_CurrTimeGraph == NULL)
        return;

    m_CurrTime = currentTime;

}

void PlotHandler::CalculateCurrentTimeBar()
{
    double upper = this->yAxis->range().upper;
    double lower = this->yAxis->range().lower;

    double range_scale = (upper - lower) * 0.0075;

    double scale = PlotHandler::MsInTimeUnit(m_TimeUnit);
    double plotTime = (m_CurrTime.toMSecsSinceEpoch() - m_OriginTime_msSinceEpoch) / scale;

    QVector<double> xData;
    QVector<double> yData;

    xData.append(plotTime);
    yData.append(upper - range_scale);

    xData.append(plotTime);
    yData.append(lower + range_scale);


    m_CurrTimeGraph->clearData();
    m_CurrTimeGraph->setData(xData,yData);

}


//!
//! \brief update the plots contained in this instance
//!
//! The PlotHandle object does not update itself to help prevent unessessery repetitive replots
//! This method is provided such that the external user to update the plots after all has changed
//!
void PlotHandler::Draw()
{
    Replot(rpQueued);
}


//!
//! \brief Schedule a recalculation of data displayed in plot
//!
void PlotHandler::RecalculatePlots()
{
    m_RecalculateScheduler.Schedule();
}


//!
//! \brief Recaculate data to display in plot window
//!
void PlotHandler::DoPlotRecalculate()
{
    m_PlotParametersMutex.lock();

    //Determine our scale
    double msInTimeUnit = MsInTimeUnit(m_TimeUnit);

    //loop through all plots, scale their times, and plot
    for(int plotIndex = 0 ; plotIndex < m_PlotParameters.size() ; plotIndex++)
    {
        //if no need to redraw plot skip
        if(m_PlotParameters.at(plotIndex).Redraw == false)
            continue;

        m_PlotParameters[plotIndex].Redraw = false;

        common_data::observation::CartesianData dr;

        if(m_PlotMode == PLOT_ENTIRE_SEQUENCE)
        {
            bool valid = m_PlotParameters[plotIndex].observations->Evaluate(*m_PlotParameters[plotIndex].operation.get(),dr,CartesianEvaluationParameters(m_OriginTime, m_OriginTime, msInTimeUnit));
            //Ken Fix: This needs to determine how long the vector of data should be
            //dr = m_PlotParameters[plotIndex].operation.Evaluate(QDateTime(), m_OriginTime, msInTimeUnit);
        }
        if(m_PlotMode == PlotHandler::PLOT_WINDOW_ONLY)
        {
            //Ken Fix: This needs to determine how long the vector of data should be
            //dr = m_PlotParameters[plotIndex].operation.Evaluate(m_LeftWindow, m_OriginTime, msInTimeUnit);
        }

        for(int i = 0 ; i < common_data::observation::NumberSystems::NumElements(dr.NumberSystem()) ; i++)
        {

            //add plot and set parameters
            if(m_PlotParameters.at(plotIndex).g.size() <= i ||  m_PlotParameters.at(plotIndex).g.at(i) == NULL)
            {
                m_PlotParameters[plotIndex].g.insert(i, MarshalAddGraph());
                QCPGraph *g = m_PlotParameters[plotIndex].g.at(i);
                g->setAntialiasedFill(false);
                this->plotLayout()->updateLayout();
            }

            QVector<double> d(dr.Length());
            QVector<double> r(dr.Length());
            for(int j = 0 ; j < dr.Length() ; j++)
            {
                d[j] = dr.getRange(j);
                r[j] = dr.getDomain(j, i);
            }

            mReplotting.lock();
            QCPGraph *g = m_PlotParameters[plotIndex].g.at(i);

            //Ken Fix Unit Name
            QString UnitName;// = QString::fromUtf8(dr.getUnit().ToShortHandString().c_str());
            if(UnitName == "")
                UnitName = "Unitless";
            g->setName(m_PlotParameters.at(plotIndex).DisplayName + " : " + UnitName);
            g->setPen(QPen(m_PlotParameters.at(plotIndex).GraphColor));

            QPen SelectedPen = g->selectedPen();
            SelectedPen.setColor(m_PlotParameters.at(plotIndex).GraphColor);
            g->setSelectedPen(SelectedPen);

            //set data in graph
            g->clearData();
            g->setData(d, r);
            g->rescaleAxes(false);
            if(m_PlotParameters.at(plotIndex).Selected == true)
            {
                QCPPlottableLegendItem *item = this->legend->itemWithPlottable(g);
                item->setSelected(true);
                g->setSelected(true);

            }

            mReplotting.unlock();
        }
    }

    //place event bars in appropriate locations
    for(int i = 0 ; i < m_EventBarList.size() ; i++)
    {
        mReplotting.lock();

        m_EventBarList.at(i).PlotBar->clearData();
        m_EventBarList.at(i).PlotBar->addData((m_EventBarList.at(i).t.toMSecsSinceEpoch() - m_OriginTime_msSinceEpoch) / msInTimeUnit, 1000);
        m_EventBarList.at(i).PlotBar->addData((m_EventBarList.at(i).t.toMSecsSinceEpoch() - m_OriginTime_msSinceEpoch) / msInTimeUnit, -1000);

        mReplotting.unlock();
    }

    m_PlotParametersMutex.unlock();

    Draw();

    m_RecalculateScheduler.Called();
}


//!
//! \brief Marshals removing a graph from QCustomPlot object to the main thread
//! \param g graph to remove
//!
void PlotHandler::MarshalRemoveGraph(QCPGraph *g)
{
    //invoke this method on the thread that owns this object.
    if (this->thread() != QThread::currentThread())
    {
        QMetaObject::invokeMethod(this, "MarshalRemoveGraph", Qt::BlockingQueuedConnection, Q_ARG(QCPGraph*, g));
        return;
    }

    this->removeGraph(g);
}


//!
//! \brief Marshals adding a graph to QCustomPlot object to the main thread
//! \return Graph added
//!
QCPGraph* PlotHandler::MarshalAddGraph()
{
    //invoke this method on the thread that owns this object.
    if (this->thread() != QThread::currentThread())
    {
        QCPGraph* result;
        QMetaObject::invokeMethod(this, "MarshalAddGraph", Qt::BlockingQueuedConnection, Q_RETURN_ARG(QCPGraph*, result));
        return result;
    }

    QCPGraph* g = this->addGraph();
    g->addToLegend();
    return g;
}


} // Graphing
