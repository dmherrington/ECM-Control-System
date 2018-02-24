#ifndef PLOT_DATA_H
#define PLOT_DATA_H

#include <QVector>
#include "graphing_global.h"

#include "dimensional_expression.h"

#include "vector.h"
#include "quaternion.h"

#include "number_systems.h"

#include "expression_engine_global.h"

namespace graphing
{

//!
//! \brief Object to hold data for plotting an arbitrary amount of dimensions on a cartesian 2D real(ℝ) axis plot.
//! This object is intended to be a temporary object to pass data from the long-term storage to the plotting mechanism.
//!
class GRAPHINGSHARED_EXPORT PlotData
{
public:


    //!
    //! \brief Empty constructor
    //!
    PlotData() :
        m_NumberSystem(NumberSystems::SCALAR)
    {

    }


    //!
    //! \brief Constructor for a single observation
    //!
    PlotData(const NumberSystems::StorableDimensions numberSystem) :
        m_Time(1),
        m_Value(1),
        m_IsConstValue(true),
        m_NumberSystem(numberSystem)
    {
    }


    //!
    //! \brief Constructor
    //! \param length Length of data (number of observations)
    //! \param numberSystem Number system
    //!
    PlotData(const int length, const NumberSystems::StorableDimensions numberSystem) :
        m_Time(length),
        m_Value(length),
        m_NumberSystem(numberSystem)
    {
        m_IsConstValue = false;
    }


    //!
    //! \brief Copy constructor
    //! \param that Object to copy
    //!
    PlotData(const CartesianData& that)
    {
        *(this) = that;
    }


    //!
    //! \brief Assignment operator
    //! \param rhs assignment
    //!
    void operator =(const PlotData& rhs)
    {
        m_Time = rhs.m_Time;
        m_Value = rhs.m_Value;
        m_IsConstValue = rhs.m_IsConstValue;
        m_Unit = rhs.m_Unit;

        m_NumberSystem = rhs.m_NumberSystem;
    }


    //!
    //! \brief request if constant
    //! \return true if constant
    //!
    bool isConst() const
    {
        return m_IsConstValue;
    }


    //!
    //! \brief The length (number of elements) of the data
    //! \return Length of data
    //!
    int Length() const
    {
        return m_Time.size();
    }


    //!
    //! \brief The dimension of the data
    //! \return Dimenion
    //!
    NumberSystems::StorableDimensions NumberSystem() const
    {
        return m_NumberSystem;
    }


    //!
    //! \brief Insert a scalar data point into the storage
    //! \param index Location in array to put data
    //! \param time range of data
    //! \param data domain of data
    //!
    void InsertData(const int index, const double time, const double &data)
    {
        if(m_NumberSystem != NumberSystems::SCALAR)
            throw new std::runtime_error("Scalar InsertData method called on non-scalar object");

        m_Time[index] = time;
        m_Value[index] = QVector<double>() << data;
    }


    //!
    //! \brief Get the range value for a specific index
    //! \param index Index to retrieve
    //! \return Range value
    //!
    double getRange(const int index) const
    {
        return m_Time[index];
    }


    //!
    //! \brief Retreive the last element of the range
    //! \return Last element of range
    //!
    double LastRangeElement() const
    {
        return m_Time.last();
    }


    //!
    //! \brief Get the domain value for a specific index and dimension
    //!
    //! Returned vector's length can be determined by NumberSystem method
    //! \param seriesIndex Index to retreive observation from
    //! \param dimIndex Index of dimension to grab
    //! \return Domain value
    //!
    double getDomain(const int seriesIndex, const int dimIndex) const
    {
        return m_Value.at(seriesIndex).at(dimIndex);
    }


    //!
    //! \brief Set the unit of the domain of this container
    //! \param unit Unit
    //!
    void setUnit(const DimensionalAnalysis::DimensionalExpression &unit)
    {
        m_Unit = unit;
    }


    //!
    //! \brief Get the unit of the domain of this container
    //! \return Unit
    //!
    DimensionalAnalysis::DimensionalExpression getUnit() const
    {
        return m_Unit;
    }


    //!
    //! \brief place constant value in double
    //! \param v Value to set to
    //! \exception std::runtime_error thrown if data isn't constant or missmatched unit
    //!
    void getConstValue(double &v) const
    {
        if(isConst() == false)
            throw new std::runtime_error("Not constant, check before calling");

        if(m_NumberSystem != NumberSystems::SCALAR)
            throw new std::runtime_error("Missmatched unit");

        v = m_Value.at(0).at(0);
    }

private:

    //! Time data, only valid if m_IsConstValue is false
    QVector<double> m_Time;

    //! Range data, only valid if m_IsConstValue is false
    QVector<QVector<double> > m_Value;

    //! Constant value of plot, only valid if m_IsConstValue is true
    double m_ConstValue;

    //! Unit of the domain
    DimensionalAnalysis::DimensionalExpression m_Unit;

    //! True if the plot is of a constant value
    bool m_IsConstValue;

    //! Number system the object is of
    NumberSystems::StorableDimensions m_NumberSystem;

};

} //end of namespace graphing


#endif // PLOT_DATA_H
