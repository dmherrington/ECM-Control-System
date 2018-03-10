#include "display_base_plot_instantaneous.h"
#include "ui_display_base_plot_instantaneous.h"

DisplayBasePlotInstantaneous::DisplayBasePlotInstantaneous(const common::TupleSensorString &measurementType, const ECMPlotCollection *sourceCollection, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayBasePlotInstantaneous),
    m_sourceCollection(sourceCollection)
{
    ui->setupUi(this);
    this->m_Measurement = measurementType;
    ui->instantReadings->setColumnCount(2);
}

DisplayBasePlotInstantaneous::~DisplayBasePlotInstantaneous()
{
    delete ui;
}


//!
//! \brief Add a row to the instantaneous reading table
//! \param key Key of addition to make future lookup's quicker
//! \param name Name of reading
//!
void DisplayBasePlotInstantaneous::AddInstantaneousRow(const int key, const QString &name)
{
    ui->instantReadings->insertRow(ui->instantReadings->rowCount());

    QTableWidgetItem *item1 = new QTableWidgetItem(name);
    QTableWidgetItem *item2 = new QTableWidgetItem("-");

    ui->instantReadings->setItem(ui->instantReadings->rowCount()-1, 0, item1);
    ui->instantReadings->setItem(ui->instantReadings->rowCount()-1, 1, item2);

    if(m_InstantNameCellHash.contains(key))
        throw new std::runtime_error("Key already is inserted into table");
    if(m_InstantValueCellHash.contains(key))
        throw new std::runtime_error("Key already is inserted into table");

    m_InstantNameCellHash.insert(key, item1);
    m_InstantValueCellHash.insert(key, item2);
}


//!
//! \brief Change the name of an instantanoues reading
//! \param key Key of row to changed
//! \param value Value to change to
//!
void DisplayBasePlotInstantaneous::ChangeInstantaniousName(const int key, const QString &name)
{
    if(!m_InstantNameCellHash.contains(key))
        return;
    m_InstantNameCellHash[key]->setText(name);
}


//!
//! \brief Change the value of an instantanoues reading
//! \param key Key of row to changed
//! \param value Value to change to
//!
void DisplayBasePlotInstantaneous::ChangeInstantaniousReading(const int key, const QString &value)
{
    if(!m_InstantValueCellHash.contains(key))
        return;
    m_InstantValueCellHash[key]->setText(value);
}

//!
//! \brief Method to update any information that is not contained in a plot for the sensor
//! \param sensor Tuple describing the sensor
//! \param sensorData Sensor data to update
//!
void DisplayBasePlotInstantaneous::UpdateNonPlottedData(const common::TupleSensorString &sensor, const data::SensorState &sensorData)
{
    UNUSED(sensor);
    UNUSED(sensorData);
}

/**
 * @brief setOriginTime Set the "zero" time of the plot
 * @param originTime Desired origin time of the plot
 */
void DisplayBasePlotInstantaneous::setOriginTime(const QDateTime &originTime)
{
    m_OriginTime = originTime;
    ui->customPlot->setOriginTime(originTime);
}


//!
//! \brief Change the mode of any plot in the sensor display
//!
//! Does nothing if no plot is present
//! \param newMode New mode to change to
//!
void DisplayBasePlotInstantaneous::ChangePlotMode(const graphing::PlotHandler::PlotMode newMode)
{
    ui->customPlot->ChangeMode(newMode);
}


//!
//! \brief Set the plots of dimensions to be displayed by this object
//!
//! \param plotList List of plot objects
//!
void DisplayBasePlotInstantaneous::setPlotData(const QList<std::shared_ptr<data::observation::IPlotComparable> > &plotList)
{
    m_PlotData = plotList;

    int plotCount = 0;
    for(int i = 0 ; i < plotList.size() ; i++)
    {
//        ExpressionEngine::NumberSystems::StorableDimensions numSystem = m_sourceCollection->getNumberSystem(*plotList.at(i));
//        size_t numDimensions = ExpressionEngine::NumberSystems::NumElements(numSystem);
//        std::vector<std::string> dimStrings = ExpressionEngine::NumberSystems::ElementNames(numSystem);
//        for(int j = 0 ; j < numDimensions ; j++)
//        {
//            if(numDimensions == 1)
//                AddInstantaneousRow(plotCount, "V");
//            else
//            {
//                AddInstantaneousRow(plotCount, QString(dimStrings.at(j).c_str()));
//            }
//            plotCount++;
//        }

    }

    ui->customPlot->ChangeMode(graphing::PlotHandler::PLOT_WINDOW_ONLY);
}

QWidget* DisplayBasePlotInstantaneous::getWidget()
{
    return this;
}


//!
//! \brief Add an expression to plot in the graph
//! \param expr Expression to plot
//! \param color Color to plot
//!
void DisplayBasePlotInstantaneous::AddExpressionPlot(const  std::string &expr, const QColor &color)
{
    ui->customPlot->AddPlot(expr);
    ui->customPlot->ChangeColor(expr, color);
}


void DisplayBasePlotInstantaneous::UpdateAxis(QDateTime leftWindow, QDateTime rightWindow)
{
    ui->customPlot->ViewWindow(leftWindow, rightWindow);
}

//!
//! \brief Slot to fire when current time of test changes
//! \param new current time
//!
void DisplayBasePlotInstantaneous::CurrentTime(const QDateTime &currentTime)
{
    ui->customPlot->CurrentTime(currentTime);

//    int plotCount = 0;
//    for(int i = 0 ; i < m_PlotData.size() ; i++)
//    {
//        ExpressionEngine::NumberSystems::StorableDimensions numSystem = m_sourceCollection->getNumberSystem(*m_PlotData.at(i));

//        switch (numSystem) {
//        case ExpressionEngine::NumberSystems::SCALAR:
//        {
//            double value;
//            m_sourceCollection->getInstantaniousValue(*m_PlotData[i], value);
//            ChangeInstantaniousReading(plotCount + 0, QString::number(value));
//            plotCount += 1;
//            break;
//        }
//        default:
//            throw new std::runtime_error("unknown number system");
//            break;
//        }
//    }
}


//!
//! \brief The data container this object pulls its plotted data from has been updated
//!
void DisplayBasePlotInstantaneous::PlottedDataUpdated()
{
    ui->customPlot->RecalculateAllGraphs();
    ui->customPlot->Draw();
}


//!
//! \brief Changes color scheme between Qt Default and Dark
//! \param True indicates Qt Default and False indicates Dark
//!
void DisplayBasePlotInstantaneous::ChangeColorScheme(bool scheme)
{
    ui->customPlot->ChangeColorScheme(scheme);
}


void DisplayBasePlotInstantaneous::on_pushButton_Grid_clicked()
{
    bool return_boolean = ui->customPlot->ToggleGrid();
    if(return_boolean == true)
        ui->pushButton_Grid->setText("GRID OFF");
    else
        ui->pushButton_Grid->setText("GRID ON");
}

void DisplayBasePlotInstantaneous::on_pushButton_Legend_clicked()
{
    bool return_boolean = ui->customPlot->ToggleLegend();
    if(return_boolean == true)
        ui->pushButton_Legend->setText("LEGEND OFF");
    else
        ui->pushButton_Legend->setText("LEGEND ON");
}

void DisplayBasePlotInstantaneous::on_pushButton_GridSpacing_clicked()
{
    double xGrid = ui->doubleSpinBox_gridX->value();
    double yGrid = ui->doubleSpinBox_gridY->value();

    bool return_boolean = ui->customPlot->UpdateGrid(xGrid,yGrid);

    if(return_boolean == true)
        ui->pushButton_GridSpacing->setText("GRID AUTO");
    else
        ui->pushButton_GridSpacing->setText("GRID MAN");

}


void DisplayBasePlotInstantaneous::on_pushButton_yWindow_clicked()
{
    double y_low = ui->doubleSpinBox_windowLow->value();
    double y_high = ui->doubleSpinBox_windowHigh->value();
    bool return_boolean = false;
    if(y_high > y_low)
    {
        return_boolean = ui->customPlot->YAxisRange(y_low,y_high);

        if(return_boolean == true)
            ui->pushButton_yWindow->setText("Y-Window Auto");
        else
            ui->pushButton_yWindow->setText("Y-Window Custom");
    }
}
