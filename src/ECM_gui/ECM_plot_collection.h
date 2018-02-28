#ifndef ECM_PLOT_COLLECTION_H
#define ECM_PLOT_COLLECTION_H

#include <QHash>
#include <QList>

#include "ECM_gui_global.h"

#include "model_state.h"
#include "sensor_state.h"

#include "common/threaded_scheduler.h"
#include "common/tuple_ecm_data.h"
#include "ECM_plot_identifier.h"

#include "observation_scalar.h"

#include "math_expression.h"

#include <QStringList>

#include "observation_collection.h"

//!
//! \brief This object serves as a centeral organizer for all time series data that is to be used by the ECM Gui.
//!
//!
//! When a new ECM dynamic state is introduced UpdateDynamicPlots is called to update all assosiated underlaying plots.
//! Similarly UpdateSensorPlots method will update any time series data contained in supported sensors.
//!
//! Both of thoese methods will call the MakePlot method to create the ExpressionEngine::PlotTimeData when first needed.
//!
//! This object has logic that is aimed to mitigate communication thread latency.
//! When data arrives to be inserted into some time-series, it will instead be inserted into m_DynamicsTempData data structure.
//! It is then scheduled to be inserted into the respective ExpressionEngine::PlotTimeData object on a seperate thread.
//! This means that the insertion into temporary list is rather short, while insertion into main data store is performed in a seperate thread.
//!
class ECMPlotCollection : public ExpressionEngine::ObservationCollection
{
Q_OBJECT
public:

    //!
    //! \brief Constructor
    //!
    ECMPlotCollection();


    //!
    //! \brief Destructor
    //!
    ~ECMPlotCollection();


    //!
    //! \brief Method to notify the plot collection about exo dynamic data present in an ISAAC component.
    //! \param component ISAAC component that contains data
    //! \param dataName Name of ExoDynamic data
    //! \param dim Dimension of data
    //!
    void NotifyExoDynamicInformation(const ECMCore::TupleECMData &component, const QString &dataName, const DimensionalAnalysis::DimensionalExpression &dim);


    //!
    //! \brief Update dynamic plots with an observed state, including ExoDynamic data
    //! \param element ISAAC component to update
    //! \param state Observed state
    //!
    void UpdateDynamicPlots(const ECMCore::TupleECMData &element, const Data::ModelState &state, const double &ms_delay);


    //!
    //! \brief Update dynamic plots with an observed state, including ExoDynamic data
    //! \param element ISAAC component to update
    //! \param state List of observed state
    //!
    void UpdateDynamicPlots(const ECMCore::TupleECMData &element, const QList<Data::ModelState> &stateList, const QList<double> &ms_delay = QList<double>());


    //!
    //! \brief Update dynamic plots with a list of observed sensor state
    //! \param element ISAAC component to update
    //! \param state Observed sensor state
    //!
    void UpdateDynamicPlots(const ECMCore::TupleECMData &element, const QList<Data::SensorState> &stateList, const QList<double> &ms_delay = QList<double>());


    //!
    //! \brief Update Plots containing exodynamic data
    //! \param element Component containing exodynamic data
    //! \param time Time data is valid at
    //! \param names Name of ExoDynamic data
    //! \param values Value
    //!
    void UpdateExoDynamicPlots(const ECMCore::TupleECMData &element, const QDateTime time, QList<QString> &names, QList<HSI_FLOAT64> &values);


    //!
    //! \brief Update any plots for an observed sensor state
    //! \param sensor ISAAC sensor component to update
    //! \param state Observed sensor state
    //!
    void UpdateSensorPlots(const ECMCore::TupleECMData sensor, const Data::SensorState &state);


    //!
    //! \brief Get list of plotted data that corrispond to specific ISAAC component
    //! \param element ISAAC components
    //! \return List of pointers to plot data
    //!
    QList<std::shared_ptr<ExpressionEngine::IPlotComparable> > getPlots(const ECMCore::TupleECMData &element) const;


    //!
    //! \brief Retreive a list of all ISAAC components contained in a single math expressions
    //! \param expr Math expression
    //! \return List of ISAAC components
    //!
    QList<ECMCore::TupleECMData> ECMComponentInExpression(const ExpressionEngine::MathExpression &expr);


    //!
    //! \brief Assist in compleating a string
    //! \param partialString Partial string to compleate
    //! \return List of strings that can be used
    //!
    QStringList CompleteAssist(const QString &partialString);


    //!
    //! \brief Set current time of the plots
    //! \param currTime Time to set to
    //!
    void CurrentTime(const QDateTime &currTime);


    //!
    //! \brief Retreive all sub plots of a component
    //! \param component Component querying
    //! \return List of all subplots
    //!
    QList<ECMPlotIdentifier> AllSubPlots(const ECMCore::TupleECMData &component) const;


private slots:

    //!
    //! \brief Slot to asyncronously tell each ExpressionEngine::PlotTimeData object of the current time.
    //!
    void DoDistributeCurrentTime();


private:


    //!
    //! \brief Make plot in the collection, if already made this method does nothing
    //! \param ID ID to make
    //!
    bool MakePlot(const ECMPlotIdentifier &ID, const DimensionalAnalysis::DimensionalExpression &unit);


private:

    //! Current time of the test event
    QDateTime m_CurrTime;


    //! Information about TupleECMData data
    QHash<ECMCore::TupleECMData, QList<QPair<QString, DimensionalAnalysis::DimensionalExpression> > > m_ExoDynamicDataInformation;


    //! A hash to map a component to the sources it contains
    QHash<ECMCore::TupleECMData, QList<ECMPlotIdentifier> > m_ComponentToIDsHash;

    QList<QString> m_PlotReferenceString;

    QHash<ECMCore::TupleECMData, bool> m_PlotsCreated;



    //! Scheduler to distribute current time to all plots
    ThreadedScheduler m_DistributeCurrentTimeScheduler;
};



#endif // ECM_PLOT_COLLECTION_H
