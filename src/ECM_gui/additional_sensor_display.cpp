#include "additional_sensor_display.h"
#include "ui_additional_sensor_display.h"

AdditionalSensorDisplay::AdditionalSensorDisplay(ECMPlotCollection *plotCollection, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdditionalSensorDisplay),
    m_PlotCollection(plotCollection),
    m_SensorDisplays(plotCollection),
    m_colorScheme(true)
{
    const char* rootDir = getenv("ECM_ROOT");
    std::string fullIcon = std::string(rootDir) + "/ECM_Icon.png";
    setWindowIcon(QIcon(fullIcon.c_str()));

    ui->setupUi(this);


    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(CustomContextMenuRequested(QPoint)));

    m_contextMenu = new QMenu(this);

    m_SensorDocksCreated = false;
}


//!
//! \brief Deconstructor
//!
AdditionalSensorDisplay::~AdditionalSensorDisplay()
{
    delete ui;
}


void AdditionalSensorDisplay::CustomContextMenuRequested(const QPoint &pos)
{
    m_contextMenu->addActions(ui->menuView->actions());
    m_contextMenu->popup(this->mapToGlobal(pos));
}


//!
//! \brief Slot to fire when a toggleble action was clicked to change show/hide a sensor
//!
void AdditionalSensorDisplay::DisplayActionTriggered()
{
    //find the dock that was selected to be changed
    QAction* SendingObject = (QAction*)sender();

    common::TupleSensorString key;
    bool found = false;
    for(int i = 0 ; i < m_SensorActionMap.size() ; i++)
    {
        if(m_SensorActionMap.values()[i] == SendingObject)
        {
            key = m_SensorActionMap.keys()[i];
            found = true;
            break;
        }
    }

    if(found == false)
        return;

    QDockWidget *dockChild = m_SensorDockMap[key];


    //determine if we are showing or hiding display
    bool show = !m_ShownSensors[key];

    // return if dockChild is set
    if (dockChild != NULL)
    {

        //if dock is currently hidden, show it.
        //if dock is currently shown, hide it.
        if(show == true)
            dockChild->show();
        else
            dockChild->hide();
    }

    m_ShownSensors[key] = show;

    emit SensorDisplayChanged(key, show);

}


//!
//! \brief Create a new dock with a sensor inside of it.
//! \param sensor Sensor to create
//! \param type Type of sensor to make
//!
void AdditionalSensorDisplay::NewDock(const common::TupleSensorString &sensor, const data::SensorTypes &type)
{
    if (this->thread() != QThread::currentThread())
    {
        QMetaObject::invokeMethod(this, "NewDock", Qt::BlockingQueuedConnection, Q_ARG(const common::TupleSensorString&, sensor), Q_ARG(data::SensorTypes, type));
        return;
    }

    //already in, so skip
    if(m_SensorDockMap.contains(sensor) && m_SensorDockMap[sensor] != NULL)
        return;

    QString sensorDispName = sensor.HumanName();

    //make sure sensor is known by this object
    AddUsableSensor(sensor);


    QDockWidget *dock = new QDockWidget(this);
    dock->setObjectName(sensorDispName);
    dock->setWindowTitle(sensorDispName);
    dock->setAllowedAreas(Qt::AllDockWidgetAreas);
    dock->setMinimumSize(400,400);
    dock->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    dock->setVisible(false);

    connect(dock , SIGNAL(visibilityChanged(bool)), this, SLOT(OnDockVisibilitiy(bool)));

    // if the number of widgets is even, add into the second column
    if(m_SensorDockMap.size() <= 1)
    {
        this->addDockWidget(Qt::LeftDockWidgetArea, dock);
    }
    else if(m_SensorDockMap.size() % 2 != 0) // odd number of widgets
    {
        this->addDockWidget(Qt::LeftDockWidgetArea, dock);
    }
    else // even number of widgets
    {
        this->addDockWidget(Qt::RightDockWidgetArea, dock);
    }

    //now create sensor display
    m_SensorDisplays.CreateSensor(sensor, type);

    // Insert the sensor tuple and corresponding dock pointer to the map
    m_SensorDockMap.insert(sensor, dock);

    //set widget of dock
    m_SensorDockMap.value(sensor)->setWidget(m_SensorDisplays.getWidget(sensor));


    // Emit color scheme signal
    emit SchemeChanged(m_colorScheme);
}


bool AdditionalSensorDisplay::isSensorDisplayed(const common::TupleSensorString &sensor)
{
    return m_ShownSensors[sensor];
}


//!
//! \brief Notify about a sensor that can be used by this object
//! \param sensor Sensor that can be used
//!
void AdditionalSensorDisplay::AddUsableSensor(const common::TupleSensorString &sensor)
{
    //if already inserted, do nothing
    if(m_ShownSensors.contains(sensor))
        return;

    m_ShownSensors.insert(sensor, false);

    // View menu actions
    QAction *newAction = ui->menuView->addAction(sensor.HumanName(),this, SLOT(DisplayActionTriggered()));
    newAction->setObjectName(sensor.HumanName());
    newAction->setText(sensor.HumanName());
    newAction->setCheckable(true);
    newAction->setChecked(false);

    m_SensorActionMap.insert(sensor, newAction);
}


//!
//! \brief Slot fired when a dock becomes visible or invisible
//! \param visible true if dock is now visible, false otherwise
//!
void AdditionalSensorDisplay::OnDockVisibilitiy(bool visible)
{
    QDockWidget *dock = (QDockWidget*)sender();

    common::TupleSensorString sensor;
    bool sensorFound = false;
    for(int i = 0 ; i < m_SensorDockMap.size() ; i++)
    {
        if(m_SensorDockMap.values()[i] == dock)
        {
            sensorFound = true;
            sensor = m_SensorDockMap.keys()[i];
            break;
        }
    }

    UNUSED(sensorFound);

    m_SensorActionMap[sensor]->setChecked(visible);
    m_ShownSensors[sensor] = visible;
}


//!
//! \brief Change plot mode for displays in this dock window
//! \param mode Mode to change to
//!
void AdditionalSensorDisplay::ChangePlotMode(const graphing::PlotHandler::PlotMode &mode)
{
    m_SensorDisplays.SetPlotMode(mode);
}


//!
//! \brief Set the origin time for displays in this window
//! \param time Time to set to
//!
void AdditionalSensorDisplay::SetOriginTime(const QDateTime &time)
{
    m_SensorDisplays.DistributeOriginTime(time);
}


//!
//! \brief Updated the non-plotted data of a plot in the additional window
//! \param sensor Sensor to update
//! \param state State to give
//!
void AdditionalSensorDisplay::UpdateNonPlottedData(const common::TupleSensorString &sensor, const data::SensorState &state)
{
    m_SensorDisplays.UpdateNonPlottedData(sensor, state);
}


//!
//! \brief update plotted data in displays kept by the dock window
//!
void AdditionalSensorDisplay::UpdatePlottedData(const common::TupleSensorString &sensor)
{
    m_SensorDisplays.PlottedDataUpdated(sensor);
}


//!
//! \brief set the current time in all the displays kept by this dock window
//! \param dateTime Current date time
//!
void AdditionalSensorDisplay::CurrentTime(const QDateTime &dateTime)
{
    m_SensorDisplays.DistributeCurrentTime(dateTime);
}


void AdditionalSensorDisplay::AxisChanged(QDateTime lower, QDateTime upper)
{
    m_SensorDisplays.DistributeUpdateAxis(lower, upper);
}


//!
//! \brief Change the color scheme between Qt Default and Dark
//! \param True indicates Qt Default and False indicates Dark
//!
void AdditionalSensorDisplay::ChangeColorScheme(bool scheme)
{
    if(scheme == true) //true = Qt Default
    {
        this->setStyleSheet("");
        m_colorScheme = true;
    }
    else if(scheme == false) //false = Dark
    {
        m_colorScheme = false;

        // Setting style sheet
        QFile f(":qdarkstyle/style.qss");
        if(!f.exists())
        {
            printf("Unable to set stylesheet, file not found\n");
        }
        else
        {
            f.open(QFile::ReadOnly | QFile::Text);
            QTextStream ts(&f);
            this->setStyleSheet(ts.readAll());
        }
    }

    m_SensorDisplays.DistributeChangeColorScheme(scheme);
}
