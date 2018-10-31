#include "window_munk_temperature_status.h"
#include "ui_window_munk_temperature_status.h"

Window_MunkTemperatureStatus::Window_MunkTemperatureStatus(const MunkPowerSupply *obj, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_MunkTemperatureStatus)
{
    qRegisterMetaType<response_Munk::State_TemperatureBoard>("MunkTemperatureState");

    ui->setupUi(this);
    m_PowerSupply = obj;

    connect(m_PowerSupply, SIGNAL(signal_NewTemperatureReceived(response_Munk::State_TemperatureBoard)), this, SLOT(updateTemperatureStatus(response_Munk::State_TemperatureBoard)));

}

Window_MunkTemperatureStatus::~Window_MunkTemperatureStatus()
{
    std::map<unsigned int, Widget_MunkTemperatureState*>::iterator itr = m_StateWidgets.begin();
    if (itr != m_StateWidgets.end())
    {
        // found it - delete it
        delete itr->second;
        m_StateWidgets.erase(itr);
    }

    delete ui;
}

void Window_MunkTemperatureStatus::updateBoardCount(const unsigned int &count)
{
    //First remove all of the old ones
    std::map<unsigned int, Widget_MunkTemperatureState*>::iterator itr = m_StateWidgets.begin();
    if (itr != m_StateWidgets.end())
    {
        // found it - delete it
        delete itr->second;
        m_StateWidgets.erase(itr);
    }

    //Next let us create a bunch of new ones
    for (size_t boardIndex = 1; boardIndex <= count; boardIndex++)
    {
        Widget_MunkTemperatureState* newBoardState = new Widget_MunkTemperatureState(boardIndex);
        m_StateWidgets.insert(std::pair<unsigned int,Widget_MunkTemperatureState*>(boardIndex,newBoardState));
        ui->verticalLayout->addWidget(newBoardState);
    }
}

void Window_MunkTemperatureStatus::updateTemperatureStatus(const response_Munk::State_TemperatureBoard &data)
{
    std::map<unsigned int, Widget_MunkTemperatureState*>::iterator itr;

    itr = m_StateWidgets.find(data.getBoardIndex());
    if (itr != m_StateWidgets.end())
    {
        Widget_MunkTemperatureState* widgetState = itr->second;
        widgetState->updateTemperatures(data.getTemperature_1(), data.getTemperature_2());
    }
}
