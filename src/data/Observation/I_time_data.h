#ifndef I_TIME_DATA_H
#define I_TIME_DATA_H

#include "stdlib.h"
#include <memory>

#include <QDateTime>
#include <QList>
#include <QVector>
#include <QList>
#include <QString>
#include <QMutex>
#include <typeinfo>

#include "I_plot_comparable.h"

#include "data_global.h"

#include "cartesian_data.h"
#include "cartesian_evaluation_parameters.h"

#include "number_systems.h"

namespace data {
namespace observation {

//!
//! \brief Abstract class defining interface for time series data storage of arbitrary dimensions.
//! Time series data is data data whoose range is time.
//!
class ITimeData
{
public:

    //!
    //! \brief Destructor
    //!
    virtual ~ITimeData(){ }

    //!
    //! \brief Prepare data contained in this object for display on a plot.
    //! \param [in] parameters Parameters for cartesian time conversion
    //! \return A CartesianData object that can be plotted
    //!
    virtual CartesianData ConvertToScalarTime(const CartesianEvaluationParameters &parameters, const std::string &componentIndex = "") = 0;

    //!
    //! \brief Determine if this plot is a constant value
    //! \return true if constant plot, false otherwise
    //!
    virtual bool IsConstValuePlot() const = 0;

    //!
    //! \brief The number system the container holds
    //! \return Number system
    //!
    virtual NumberSystems::StorableDimensions NumberSystem() const = 0;

};

} //end of namespace observation
} //end of namespace data

#endif // I_TIME_DATA_H
