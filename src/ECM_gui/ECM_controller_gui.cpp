#include "ECM_controller_gui.h"
#include "ui_ECM_controller_gui.h"

ECMControllerGUI::ECMControllerGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ECMControllerGUI)
{
    ui->setupUi(this);
    m_additionalSensorDisplay = new AdditionalSensorDisplay(&m_PlotCollection);
    m_additionalSensorDisplay->setWindowTitle("ECM Sensors");
}

ECMControllerGUI::~ECMControllerGUI()
{
    delete ui;
}
