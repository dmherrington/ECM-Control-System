#ifndef ECM_PLOT_COLLECTION_H
#define ECM_PLOT_COLLECTION_H

#include <QStringList>
#include <QHash>
#include <QList>

#include "data/sensor_state.h"
#include "data/motion_profile_variable_state.h"
#include "data/machine_positional_state.h"

#include "common/hash_keys.h"
#include "common/threaded_scheduler.h"
#include "common/tuple_ecm_data.h"

#include "data/observation/observation_scalar.h"
#include "data/observation/observation_collection.h"

#include "data/sensors/sensor.h"
#include "data/sensors/sensor_voltage.h"

#include "ECM_plot_identifier.h"



//!
//! \brief This object serves as a central organizer for all time series data that is to be used by the ECM Gui.
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
class ECMPlotCollection : public common_data::observation::ObservationCollection
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

    void UpdatePositionalStatePlots(const common::TuplePositionalString &position, const common_data::MachinePositionalState &state);

    void UpdateProfileVariablePlots(const common::TupleProfileVariableString &variable, const common_data::MotionProfileVariableState &state);

    //!
    //! \brief Update any plots for an observed sensor state
    //! \param sensor ECM sensor component to update
    //! \param state Observed sensor state
    //!
    void UpdateSensorPlots(const common::TupleSensorString &sensor, const common_data::SensorState &state);


    //!
    //! \brief Get list of plotted data that correspond to specific ECM component
    //! \param element ECM components
    //! \return List of pointers to plot data
    //!
    QList<std::shared_ptr<common_data::observation::IPlotComparable> > getPlots(const common::TupleECMData &element) const;

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
    QList<ECMPlotIdentifier> AllSubPlots(const common::TupleECMData &component) const;


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
    bool MakePlot(const ECMPlotIdentifier &ID, const std::string &unit);


private:

    //! Current time of the test event
    QDateTime m_CurrTime;


    //! Information about TupleECMData data
    QHash<common::TupleECMData, QList<QPair<QString, std::string>>> m_ExoDynamicDataInformation;


    //! A hash to map a component to the sources it contains
    QHash<common::TupleECMData, QList<ECMPlotIdentifier>> m_ComponentToIDsHash;

    QList<QString> m_PlotReferenceString;


    //! Scheduler to distribute current time to all plots
    ThreadedScheduler m_DistributeCurrentTimeScheduler;
};



#endif // ECM_PLOT_COLLECTION_H
