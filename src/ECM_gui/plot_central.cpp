#include "plot_central.h"

//!
//! \brief Default Constructor
//! \param plotCollection Pointer to plot collection object
//!
PlotCentral::PlotCentral(QWidget *parent) :
    graphing::PlotHandler(parent),
    m_GraphSelected(false),
    m_PlotCollection(NULL)
{
//    connect(this, SIGNAL(PlotAdded(ExpressionEngine::MathExpression)), this, SLOT(OnPlotAdded(ExpressionEngine::MathExpression)));
//    connect(this, SIGNAL(PlotSelected(ExpressionEngine::MathExpression)), this, SLOT(OnPlotSelected(ExpressionEngine::MathExpression)));
//    connect(this, SIGNAL(PlotUnselected()), this, SLOT(OnPlotUnSelected()));
//    connect(this, SIGNAL(PlotDelete(ExpressionEngine::MathExpression)), this, SLOT(OnPlotDelete(ExpressionEngine::MathExpression)));
}


//!
//! \brief Destructor
//!
PlotCentral::~PlotCentral()
{

}


//!
//! \brief Supply plot collection to this object.
//!
//! Must be performed prior to displaying a plot
//! \param plotCollection Pointer to plot collection.
//!
void PlotCentral::SupplyPlotCollection(ECMPlotCollection *plotCollection)
{
    m_PlotCollection = plotCollection;
}


//!
//! \brief Provide a list of default expressions that are to be plotted when available.
//! \param list List of string expressions.
//!
void PlotCentral::DefaultExpressions(const QStringList &list)
{
    m_DefaultGraphs.append(list);
}


//!
//! \brief Check if any default expressions can be used
//!
void PlotCentral::CheckForDefaultExpressions()
{
#ifdef EXPRESSION_PARSER
    if(m_DefaultGraphs.count() == 0)
        return;

    int size = m_DefaultGraphs.size();
    for(int i = 0 ; i < size ; i++)
    {
        if(m_expressionDriver->Parse(m_DefaultGraphs.at(i).toStdString()) == 0)
        {
            NewExpression(m_DefaultGraphs.at(i));
            m_DefaultGraphs.removeAt(i);
            size = size - 1;
            i = i - 1;
        }
    }
#endif
}


//!
//! \brief Graph a new experssion in the underlying PlotHandler object
//! \param str String to plot
//!
void PlotCentral::NewExpression(const QString &str)
{
    //if a graph is selected, we are replacing
    if(m_GraphSelected == true)
        removeSelectedGraph();

#ifdef EXPRESSION_PARSER
    if(m_expressionDriver->Parse(str.toStdString()) == 0)
    {
        for(size_t i = 0 ; i < m_expressionDriver->result.size() ; i++)
        {
            ExpressionEngine::MathExpression newExpression = m_expressionDriver->result.at(i).expression;

            m_ActiveExpressions.insert(newExpression, str);
            AddPlot(newExpression);

            ChangeColor(newExpression, m_expressionDriver->result.at(i).color);
            ChangeName(newExpression, QString(m_expressionDriver->result.at(i).name.c_str()));
        }
    }
#endif
}


//!
//! \brief Determine if supplied string is a valid expression
//! \param str String to check
//! \return Error, empty string if valid
//!
QString PlotCentral::IsValidExpression(const QString &str)
{
#ifdef EXPRESSION_PARSER

    if(m_expressionDriver == NULL)
        throw new std::runtime_error("Expression driver not set");

    if(m_expressionDriver->Parse(str.toStdString()) == 0)
        return QString();
    else
        return QString(m_expressionDriver->parseError.c_str());
#endif
}


//!
//! \brief A plot has been selected in the PlotHandler.
//! \param expr Expression that has been selected.
//!
void PlotCentral::OnPlotAdded(QString expr)
{
//    QList<common::TupleECMData> componentList = m_PlotCollection->ISAACComponentInExpression(expr);

//    emit ComponentsAdded(componentList);

}


//!
//! \brief A plot has been selected in the PlotHandler.
//! \param expr Expression that has been selected.
//!
void PlotCentral::OnPlotSelected(QString expr)
{
//    if(m_ActiveExpressions.contains(expr))
//        emit SelectedExpressionString(true, m_ActiveExpressions[expr]);

//    m_GraphSelected = true;
//    m_SelectedExpression = expr;
}


//!
//! \brief No plots are selected in the PlotHandler.
//!
void PlotCentral::OnPlotUnSelected()
{
    m_GraphSelected = false;
    emit SelectedExpressionString(false, "");
}


//!
//! \brief A plot has been deleted from the PlotHandler.
//! \param expr Expression that has been deleted.
//!
void PlotCentral::OnPlotDelete(QString expr)
{
//    if(m_ActiveExpressions.contains(expr))
//        m_ActiveExpressions.remove(expr);

//    if(m_SelectedExpression == expr)
//        m_GraphSelected = false;

//    QList<common::TupleECMData> componentList = m_PlotCollection->ISAACComponentInExpression(expr);
//    emit ComponentsRemoved(componentList);
}
