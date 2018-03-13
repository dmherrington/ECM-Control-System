#ifndef PLOT_CENTRAL_H
#define PLOT_CENTRAL_H

#include "plot_handler.h"

#include "tuple_ecm_data.h"

#include "ECM_plot_collection.h"

//!
//! \brief This object acts as a middleware between strings describing plots
//! and the actual plot handler object
//!
//! Before operating this object must be supplied a pointer to the plot collection via the SupplyPlotCollection method.
//!
//! A list of default expressions can be given to this plot that will be plotted when available.
//!
class PlotCentral : public graphing::PlotHandler
{
    Q_OBJECT
public:


    //!
    //! \brief Default Constructor
    //! \param plotCollection Pointer to plot collection object
    //!
    PlotCentral(QWidget *parent = 0);


    //!
    //! \brief Destructor
    //!
    ~PlotCentral();


    //!
    //! \brief Supply plot collection to this object.
    //!
    //! Must be performed prior to displaying a plot
    //! \param plotCollection Pointer to plot collection.
    //!
    //void SupplyPlotCollection(ECMPlotCollection *plotCollection);


    //!
    //! \brief Provide a list of default expressions that are to be plotted when available.
    //! \param list List of string expressions.
    //!
    void DefaultExpressions(const QStringList &list);


    //!
    //! \brief Check if any default expressions can be used
    //!
    void CheckForDefaultExpressions();


    //!
    //! \brief Graph a new experssion in the underlying PlotHandler object
    //! \param str String to plot
    //!
    void NewExpression(const QString &str);


    //!
    //! \brief Determine if supplied string is a valid expression
    //! \param str String to check
    //! \return Error, empty string if valid
    //!
    QString IsValidExpression(const QString &str);


signals:


    //!
    //! \brief Signal to emit when components have been added to the plot.
    //!
    //! Usefull such that the overarching ISAAC process knows to issue interest in the components.
    //! \param componentList List of components added
    //!
    void ComponentsAdded(QList<common::TupleECMData> componentList);


    //!
    //! \brief Signal that is emitted when a plot has been selected, or unselected
    //!
    //! Gives the string used to generate the selected object, usefull for editing a previously instered expression.
    //! \param selected True is something is selected.
    //! \param string String used to generate selection. If selected is false this is invalid.
    //!
    void SelectedExpressionString(bool selected, QString string);


    //!
    //! \brief Signal to emit when components have been deleted to the plot.
    //!
    //! Usefull such that the overarching ISAAC process knows to potentially remove interest in the components.
    //! \param componentList List of components removed
    //!
    void ComponentsRemoved(QList<common::TupleECMData> componentList);


private slots:

    //!
    //! \brief A plot has been selected in the PlotHandler.
    //! \param expr Expression that has been selected.
    //!
    void OnPlotAdded(QString expr);


    //!
    //! \brief A plot has been selected in the PlotHandler.
    //! \param expr Expression that has been selected.
    //!
    void OnPlotSelected(QString expr);


    //!
    //! \brief No plots are selected in the PlotHandler.
    //!
    void OnPlotUnSelected();


    //!
    //! \brief A plot has been deleted from the PlotHandler.
    //! \param expr Expression that has been deleted.
    //!
    void OnPlotDelete(QString expr);

private:

    //! Bool indicating if a plot is selected by the plot
    bool m_GraphSelected;

    //! List of default graphs to attempt to plot on main graphing window
    QStringList m_DefaultGraphs;

    //! Pointer to the ISAAC plot collection
    ECMPlotCollection *m_PlotCollection;

};

#endif // PLOT_CENTRAL_H
