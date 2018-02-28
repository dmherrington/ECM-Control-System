#ifndef I_SENSOR_DISPLAY_H
#define I_SENSOR_DISPLAY_H

#include <QWidget>

#include "plot_handler.h"

class ISensorDisplay
{
public:


    //!
    //! \brief set the origin time of the plot
    //!
    //! The origin time is the time which will be plotted at zero.
    //! \param originTime time to shift x axis to zero
    //!
    virtual void setOriginTime(const QDateTime &originTime) = 0;


    //!
    //! \brief Change the mode of any plot in the sensor display
    //!
    //! Does nothing if no plot is present
    //! \param newMode New mode to change to
    //!
    virtual void ChangePlotMode(const graphing::PlotHandler::PlotMode newMode) = 0;


    virtual QWidget* getWidget() = 0;

public slots:
    virtual void UpdateAxis(QDateTime lowerBound, QDateTime upperBound) = 0;


    //!
    //! \brief Slot to fire when current time of test changes
    //! \param new current time
    //!
    virtual void CurrentTime(const QDateTime &currentTime) = 0;


    //!
    //! \brief The data container this object pulls its plotted data from has been updated
    //!
    virtual void PlottedDataUpdated() = 0;


    //!
    //! \brief Changes color scheme between Qt Default and Dark
    //! \param True indicates Qt Default and False indicates Dark
    //!
    virtual void ChangeColorScheme(bool scheme) = 0;
};

#endif // I_SENSOR_DISPLAY_H
