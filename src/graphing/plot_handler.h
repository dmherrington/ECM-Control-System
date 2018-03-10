#ifndef PLOT_HANDLER_H
#define PLOT_HANDLER_H

#include <vector>
#include <string>
#include "graphing_global.h"

#include "qcustomplot.h"
#include "common/environment_time.h"
#include "data/Observation/I_plot_comparable.h"
#include "data/Observation/I_observation.h"

#include "time_plot.h"

#include "common/common.h"
#include "common/threaded_scheduler.h"

namespace graphing {

//!
//! \brief A TimePlot object that is to hold and display measurments based on time
//!
//! Generated expressions to be plotted are provided to this object by the AddPlot method.
//! Added expressions can be removed from the plot with the RemoveGraphData method.
//! A list of active std::string in the plot can be retrived via the ActiveExpressions method.
//!
class GRAPHINGSHARED_EXPORT PlotHandler : public TimePlot
{
    Q_OBJECT
public:

    //! Mode of plotting operation
    enum PlotMode
    {
        //!
        //! \brief Plot entire sequence when asked.
        //!
        //! Used when the data is loaded or refreshed slower than user interaction with the window
        //! May cause unessessary calculations on data that is not displayed
        //!
        PLOT_ENTIRE_SEQUENCE,


        //!
        //! \brief Plot only the window currently being drawn.
        //!
        //! Used when the data is refreshed faster than user interaction with the view window.
        //! Reduces the unessessary calculations on data this isn't being displayed
        //!
        PLOT_WINDOW_ONLY
    };

// //////////////////////////////////////////////////////////////
// ////////////// PUBLIC METHODS ////////////////////////////////
// //////////////////////////////////////////////////////////////


    //!
    //! \brief Constructor
    //! \param parent
    //!
    PlotHandler(QWidget *parent = 0);


    //!
    //! \brief Destructor
    //!
    ~PlotHandler();


    //!
    //! \brief Change mode of operation
    //! \param mode Mode to change to
    //!
    void ChangeMode(const PlotMode mode);


    //!
    //! \brief Adds a plot to the handler object
    //! \param dataKey Key to indentify data
    //!
    void AddPlot(const std::string &Expression);


    //!
    //! \brief Retreive a list of all active expressions
    //! \return List of active expressions
    //!
    QList<std::string> ActiveExpressions() const;


    //!
    //! \brief Change name of a plot to be displayed
    //! \param dataKey Plot to change name of
    //! \param displayName Name to change to
    //!
    void ChangeName(const std::string &dataKey, const QString &displayName);


    //!
    //! \brief Change the color of a plot to be displayed
    //! \param dataKey Plot to change color of
    //! \param color Colour to change to
    //!
    void ChangeColor(const std::string &operation, const QColor &color);


    //!
    //! \brief Add an event indicator to ploting instance
    //! \param time time to put event
    //! \param name name of event
    //! \param msg message about event
    //! \param color color to draw event indicator
    //!
    void AddEvent(const QDateTime &time, const QString &name, const QString &msg, const QColor &color = Qt::black, const Qt::PenStyle &style = Qt::SolidLine);


    //!
    //! \brief Remove a graph from plot
    //! \param dataKey Key of data to remove
    //!
    void RemoveGraphData(const std::string &operation);


    //!
    //! \brief set the origin time of the plot
    //!
    //! The origin time is the time which will be plotted at zero.
    //! \param originTime time to shift x axis to zero
    //!
    virtual void setOriginTime(const QDateTime &originTime);


    //!
    //! \brief Set the unit this plot represents time
    //! \param unitType Unit to represent time
    //!
    virtual void ChangeUnit(const TimeUnit &unitType);


    //!
    //! \brief Change the color scheme between Qt Default and Dark
    //! \param true if Qt Default, false if Dark
    //!
    void ChangeColorScheme(bool color);


    //!
    //! \brief Update the spacing tic marks on plot
    //! \param xSpacing x tick marks
    //! \param ySpacing y tick marks
    //! \return true if allowing custom spacing
    //!
    bool UpdateGrid(const double xSpacing, const double ySpacing);


    //!
    //! \brief set the ranges of the Y axis
    //! \param lowWindow min value on Y axis
    //! \param highWindow max value on Y axis
    //! \return true if allowing custom y axis ranges
    //!
    bool YAxisRange(double lowWindow, double highWindow);


    //!
    //! \brief Toggle the grid on or off
    //! \return true if grid is now on
    //!
    bool ToggleGrid();


    //!
    //! \brief Toggle the legend on or off
    //! \return true if legend is now on
    //!
    bool ToggleLegend();


    //!
    //! \brief Export the current graph to an image file
    //!
    //! Will check the provided file suffix for either .png, .jpg/.jpeg, .png, or .bmp
    //! Events and current time indicators are turned off when plotting
    //! \param File to save to
    //! \return false if given faulty suffix
    //!
    bool ExportToImage(const QString &fileToExportTo);


public slots:

    //!
    //! \brief Redraw all expressions that rely on the provided data sources
    //! \param source Data sources to redraw
    //!
    //void RedrawDataSource(const QList<std::shared_ptr<ExpressionEngine::IPlotComparable> > &sources);



// ///////////////////////////////////////////////////////////////
// ////////////// USER INTERFACE SLOTS ///////////////////////////
// ///////////////////////////////////////////////////////////////
public slots:

    //!
    //! \brief slot to fire when user request a context menue on the plot
    //! \param pos Point where user requested context menu
    //!
    void contextMenuRequest(QPoint pos);


    //!
    //! \brief slot to fire when the graph the user has selected has changed
    //!
    //! This method emits a PlotSelected signal when a plot is selected
    //!
    void SelectionChanged();


    //!
    //! \brief slot to fire when the use scrolls the window
    //!
    void WindowScrolled();



    //!
    //! \brief slot to fire when user double click the plot
    //! \param event mouse event parameters
    //!
    void on_double_click(QMouseEvent *event);


    void moveLegend();




// ///////////////////////////////////////////////////////////////
// ////////////// PLOT MANIPULATION SLOTS ////////////////////////
// ///////////////////////////////////////////////////////////////

    //!
    //! \brief Remove the selected graph from the plot
    //!
    void removeSelectedGraph();


    //!
    //! \brief Remove all graphs from the plot instance
    //!
    void removeAllGraphs();

    //!
    //! \brief Force all graphs to be replotted
    //!
    void RecalculateAllGraphs();


    //!
    //! \brief Modify the window the xAxis is currently viewing
    //! \param leftWindow left edge of window
    //! \param rightWindow right edge of window
    //!
    void ViewWindow(const QDateTime &leftWindow, const QDateTime &rightWindow);


    //!
    //! \brief Slot to fire when current time of test changes
    //! \param new current time
    //!
    void CurrentTime(const QDateTime &currentTime);


    //!
    //! \brief call a draw on the underlying object
    //!
    //! The PlotHandle object does not update itself to help prevent unessessery repetitive replots
    //! This method is provided such that the external user to update the plots after all has changed
    //!
    void Draw();



// ///////////////////////////////////////////////////////////////
// ////////////// SIGNALS ////////////////////////////////////////
// ///////////////////////////////////////////////////////////////
signals:


    //!
    //! \brief Signal to emit when a plot as been added.
    //! \param newPlot Expression for the new plot.
    //!
    void PlotAdded(std::string newPlot);


    //!
    //! \brief Signal to alert that a plot has been selected.
    //! \param dataID shared_ptr identifiying the plot
    //!
    void PlotSelected(std::string dataID);


    //!
    //! \brief Signal to alert that no plot has been selected
    //!
    void PlotUnselected();


    //!
    //! \brief Signal to emit when a plot has been deleted
    //! \param plot Expression for plot that was removed
    //!
    void PlotDelete(std::string plot);


    //!
    //! \brief Signal to plot when a time has been double-clicked
    //! \param time The time double click occured at
    //!
    void DoubleClick(QDateTime time);


// ///////////////////////////////////////////////////////////////
// ////////////// PRIVATE METHODS ////////////////////////////////
// ///////////////////////////////////////////////////////////////
private slots:


    void CalculateCurrentTimeBar();


    //!
    //! \brief Schedule a recalculation of data displayed in plot
    //!
    void RecalculatePlots();


    //!
    //! \brief Recaculate data to display in plot window
    //!
    void DoPlotRecalculate();


private:

    //!
    //! \brief Marshals removing a graph from QCustomPlot object to the main thread
    //! \param g graph to remove
    //!
    Q_INVOKABLE void MarshalRemoveGraph(QCPGraph *g);


    //!
    //! \brief Marshals adding a graph to QCustomPlot object to the main thread
    //! \return Graph added
    //!
    Q_INVOKABLE QCPGraph* MarshalAddGraph();


private:

    //! A graph to indicate the current time
    QCPGraph *m_CurrTimeGraph;

    //! Current time of graph. Nessessary if redrawing without changing time (i.e. zoom in)
    QDateTime m_CurrTime;


    //!
    //! \brief The plot_data_variables struct
    //!
    struct plot_data_variables{

        //! shared_ptr to a comparable object being plotted
        //! See SelectionChanged code for why this is a shared_ptr
        std::string operation;
        QString DisplayName;
        QVector<double> xgraph_data;
        QVector<double> ygraph_data;
        TimeUnit unitVariable;
        QColor GraphColor;
        QString Line_Type;
        int GraphNumber;
        bool Redraw;
        bool Selected;

        //! Graph to display plot
        QVector<QCPGraph *> g;
    };


    //!
    //! \brief List of plots contained in this plotting object
    //!
    QList<plot_data_variables> m_PlotParameters;


    //!
    //! \brief Parameters about the figure
    //!
    struct figure_parameters{
        bool legend;

        bool grid;
        bool grid_custom;
        double xGridSpacing;
        double yGridSpacing;

        bool window_custom;
        double yWindow_min;
        double yWindow_max;

        QColor background_color;
        QColor text_color;
        QPen grid_penColor;
        QPen grid_subPenColor;
        QPen grid_zeroLineColor;
    } m_FigureProperties;


    //! Origin time on the plot
    QDateTime m_OriginTime;

    //! ms since epoch. Only provided as convience in calculations.
    qint64 m_OriginTime_msSinceEpoch;

    //! Unit time is held in.
    TimeUnit m_TimeUnit;


    //! Private structure to contain an event on playback
    struct Event
    {
        //! bar to display event
        QCPCurve* PlotBar;

        //! time to place event at
        QDateTime t;

        //! title of event
        QString title;

        //! further message about event
        QString msg;

        //! color of event
        QColor colour;
    };

    //! vector of events to draw on playback
    QVector<Event> m_EventBarList;

    QDateTime m_LeftWindow;

    PlotMode m_PlotMode;

    ThreadedScheduler m_RecalculateScheduler;

    QMutex m_PlotParametersMutex;

    QVector<double> m_TempXData;
    QVector<double> m_TempYData;
    QMutex m_TempDataMutex;
};

} //end of namespace graphing

#endif // PLOT_HANDLER_H
