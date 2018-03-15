#ifndef CARTESIANEVALUATIONPARAMETERS_H
#define CARTESIANEVALUATIONPARAMETERS_H

#include <QDateTime>

//!
//! \brief Structure containing parameters to to convert a list of observations times into a list of scalar values
struct CartesianEvaluationParameters
{

    CartesianEvaluationParameters(const QDateTime &minTime, const QDateTime &originTime, const double msInTimeUnit) :
        minTime(minTime),
        originTime(originTime),
        msInTimeUnit(msInTimeUnit)
    {

    }

    //! Minimum time to consider, can be used to constrain the conversion
    QDateTime minTime;

    //! Origin time which would produce a real value of zero
    QDateTime originTime;

    //! Number of ms in unit of real-value
    double msInTimeUnit;
};

#endif // CARTESIANEVALUATIONPARAMETERS_H
