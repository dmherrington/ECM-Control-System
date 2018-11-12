#include "observation_scalar.h"

#include <iostream>
#include <limits>
#include <exception>
#include <stdexcept>
#include <QVector>
#include <QDateTime>

#include "I_plot_comparable.h"

namespace common_data {
namespace observation {

    //!
    //! \brief Constructor
    //! \param dataKey key for Data
    //!
    ObservationScalar::ObservationScalar(const IPlotComparable &dataKey)
    {
        m_DataKey = dataKey.CreateSharedPtr();
    }

    ObservationScalar::~ObservationScalar()
    {

    }

    void ObservationScalar::setUnit(const std::string &unit)
    {
        m_UnitMutex.lock();
        m_Unit = unit;
        m_UnitMutex.unlock();
    }


    //!
    //! \brief Add vectors of data to graph being plotting in this object
    //! \param domain vector of times
    //! \param range vector of values to add
    //!
    void ObservationScalar::AddData(const QList<QDateTime> &domain, const QList<double> range)
    {
        if(domain.size() != range.size())
            throw new std::runtime_error("Passed vectors size do not match");

        m_DataMutex.lock();

        m_Domain.append(domain);
        m_Range.append(range);

        m_DataMutex.unlock();

    }


    //!
    //! \brief Add data to a graph being plotted in this object
    //! \param domain new time to add
    //! \param range value to add
    //!
    void ObservationScalar::AddData(const QDateTime &domain, const double range)
    {
        m_DataMutex.lock();

        m_Domain.append(domain);
        m_Range.append(range);
        m_DataMutex.unlock();
    }

    void ObservationScalar::ClearPreviousData()
    {
        m_DataMutex.lock();
        m_Domain.clear();
        m_Range.clear();
        m_DataMutex.unlock();

        AddData(m_CurrTime,m_CurrTimeRange);
    }

    void ObservationScalar::ClearData()
    {
        m_DataMutex.lock();
        m_Domain.clear();
        m_Range.clear();
        m_DataMutex.unlock();
    }



    //!
    //! \brief Prepare data contained in this object for display on a plot.
    //! \param [in] parameters Parameters for cartesian time conversion
    //! \return A time seires object that can be plotted
    //!
    CartesianData ObservationScalar::ConvertToScalarTime(const CartesianEvaluationParameters &parameters, const std::string &componentIndex)
    {
        UNUSED(componentIndex);

        qint64 MinTime_ms = parameters.minTime.toMSecsSinceEpoch();
        qint64 OriginTime_ms = parameters.originTime.toMSecsSinceEpoch();

        qint64 currTime_ms = m_CurrTime.toMSecsSinceEpoch();

        m_DataMutex.lock();
        int NumPoint = std::min(m_Domain.size(), m_Range.size());

        int MinPoint = 0;
        for(int j = NumPoint-1; j > 0 ; j--)
        {
            if(m_Domain.at(j).toMSecsSinceEpoch() < MinTime_ms)
            {
                MinPoint = j; //this isnt exactly correct as it will break at the first one that is less than minimum time
                break;
            }
        }

        m_DataMutex.unlock();

        double currentRangeTime = 0.0;
        qint64 min = std::numeric_limits<qint64>::max();

        CartesianData v(NumPoint - MinPoint, NumberSystems::SCALAR);
        m_DataMutex.lock();
        for(int j = 0 ; j < NumPoint - MinPoint ; j++)
        {
            qint64 domain_ms = m_Domain.at(j + MinPoint).toMSecsSinceEpoch();
            if(std::abs(currTime_ms - domain_ms) < min)
            {
                currentRangeTime = m_Range.at(j + MinPoint);
                min = std::abs(currTime_ms - domain_ms);
            }

            v.InsertData(j, (domain_ms - OriginTime_ms) / parameters.msInTimeUnit, m_Range.at(j + MinPoint));
        }
        m_DataMutex.unlock();

        m_UnitMutex.lock();
        v.setUnit(m_Unit);
        m_UnitMutex.unlock();

        m_CurrTimeRange = currentRangeTime;


        return v;
    }


    //!
    //! \brief The number system the container holds
    //! \return Number system
    //!
    NumberSystems::StorableDimensions ObservationScalar::NumberSystem() const
    {
        return NumberSystems::SCALAR;
    }


    //!
    //! \brief Produce a copy of the domains of this plot
    //! \return Vector of times
    //!
    QList<QDateTime> ObservationScalar::Domain() const
    {
        return m_Domain;
    }


    //!
    //! \brief Produce a copy of ranges in this plot
    //! \return Vector of scalers
    //!
    QList<double> ObservationScalar::Range() const
    {
        return m_Range;
    }


    //!
    //! \brief Determine if this plot is a constant value
    //! \return true if constant plot, false otherwise
    //!
    bool ObservationScalar::IsConstValuePlot() const
    {
        return false;
    }


    //!
    //! \brief Set the current time of the test event.
    //!
    //! This method will recompute the current instantaneous value
    //! \param time Current time of the test event.
    //!
    void ObservationScalar::setCurrentTime(const QDateTime &time)
    {
        m_CurrTime = time;

        double currentRangeTime;

        m_DataMutex.lock();
        int NumPoint = std::min(m_Domain.size(), m_Range.size());

        for(int j = NumPoint-1; j > 0 ; j--)
        {
            if(m_Domain.at(j) < m_CurrTime)
            {
                currentRangeTime = m_Range.at(j);
                break;
            }
        }

        m_DataMutex.unlock();
        m_CurrTimeRange = currentRangeTime;
    }


    //!
    //! \brief Get a key that can identify this observation in a feild among others
    //! \return std::shared_ptr to key interface
    //!
    std::shared_ptr<IPlotComparable> ObservationScalar::Key() const
    {
        return m_DataKey;
    }


    //!
    //! \brief Get a list of current values of the range for the current time.
    //!
    //! The size of returned list is based on the Number system of the observation
    //! \return List of values
    //!
    QList<double> ObservationScalar::getCurrentTimeRange() const
    {
        return QList<double> () << m_CurrTimeRange;
    }


    //!
    //! \brief Get quaternion associated with the current domain value
    //! \return Current quaternion
    //!
    double ObservationScalar::getCurrentScalarRange() const
    {
        return m_CurrTimeRange;
    }

} // END detail

} // END ExpressionEngine
