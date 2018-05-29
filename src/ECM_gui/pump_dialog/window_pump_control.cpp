#include "window_pump_control.h"
#include "ui_window_pump_control.h"

Window_PumpControl::Window_PumpControl(Westinghouse510* obj, QWidget *parent) :
    GeneralDialogWindow(DialogWindowTypes::WINDOW_PUMP,"WestinghouseP",parent),
    ui(new Ui::Window_PumpControl),
    m_Pump(obj)
{
    ui->setupUi(this);

    connect(m_Pump,SIGNAL(signal_PumpConnectionUpdate(common::comms::CommunicationConnection)),this,SLOT(slot_PumpConnectionUpdate(common::comms::CommunicationConnection)));

    this->m_Pump->m_State->flowRate.AddNotifier(this,[this]
    {
        this->slot_updatedFlowRate(m_Pump->m_State->flowRate.get());
    });

    this->m_Pump->m_State->pumpON.AddNotifier(this,[this]
    {
        this->slot_updatedPumpOn(m_Pump->m_State->pumpON.get());
    });

    GeneralDialogWindow::readWindowSettings();

    openFromFile(GeneralDialogWindow::getPreviousSettingsPath());
}

Window_PumpControl::~Window_PumpControl()
{
    delete ui;
}

void Window_PumpControl::closeEvent(QCloseEvent *event)
{
    saveToFile(getPreviousSettingsPath());
    GeneralDialogWindow::closeEvent(event);
}

void Window_PumpControl::slot_PumpConnectionUpdate(const common::comms::CommunicationConnection &value)
{
    if(value.isConnected())
        ui->widget_PumpConnected->setColor(QColor(0,255,0));
    else
        ui->widget_PumpConnected->setColor(QColor(255,0,0));
}

void Window_PumpControl::slot_updatedPumpOn(const bool &value)
{
    if(value)
    {
        ui->widget_PumpRunning->setColor(QColor(0,255,0));
        ui->pushButton_PumpRunning->setText("OFF");
        statusBar()->showMessage(tr("The pump has been turned on."),2500);
    }
    else
    {
        ui->widget_PumpRunning->setColor(QColor(255,0,0));
        ui->pushButton_PumpRunning->setText("ON");
        statusBar()->showMessage(tr("The pump has been turned off."),2500);
    }
}

void Window_PumpControl::slot_updatedFlowRate(const double &value)
{
    ui->doubleSpinBox_flowRate->setValue(value);
    statusBar()->showMessage(tr("Flow rate has been updated."),2500);
}

void Window_PumpControl::slot_updatedDelayTime(const double &value)
{
    ui->doubleSpinBox_delayTime->setValue(value);
    statusBar()->showMessage(tr("Delay time has been updated."),2500);
}

void Window_PumpControl::slot_updatedStartTime()
{

}

void Window_PumpControl::on_pushButton_PumpRunning_released()
{
    bool run = !m_Pump->m_State->pumpON.get();
    registers_WestinghousePump::Register_OperationSignal newOps;
    newOps.shouldRun(run);
    m_Pump->setPumpOperations(newOps);
}

void Window_PumpControl::on_doubleSpinBox_flowRate_valueChanged(double arg1)
{
    //m_Pump->m_State->flowRate.set(flowRate); // I dont know if I should do it like this
    registers_WestinghousePump::Register_FlowRate newFlowRate;
    newFlowRate.setVolumetricFlow(arg1);
    m_Pump->setPumpFlowRate(newFlowRate);
}

void Window_PumpControl::on_doubleSpinBox_delayTime_valueChanged(double arg1)
{

}

void Window_PumpControl::on_actionOpen_triggered()
{
    QString filePath = GeneralDialogWindow::onOpenAction();
    if(!filePath.isEmpty() && !filePath.isNull()){
        openFromFile(filePath);
    }
}

void Window_PumpControl::on_actionSave_triggered()
{
    QString settingsPath = GeneralDialogWindow::onSaveAction();
    saveToFile(settingsPath);
}

void Window_PumpControl::on_actionSave_As_triggered()
{
    QString settingsPath = GeneralDialogWindow::onSaveAsAction();
    saveToFile(settingsPath);
}

void Window_PumpControl::on_actionClose_triggered()
{
    GeneralDialogWindow::onCloseAction();
}

void Window_PumpControl::saveToFile(const QString &filePath)
{
    QFile saveFile(filePath);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
    }
    QJsonObject saveObject;
//    ui->segmentWidget->write(saveObject);
    QJsonDocument saveDoc(saveObject);
    saveFile.write(saveDoc.toJson());
    saveFile.close();
}

void Window_PumpControl::openFromFile(const QString &filePath)
{
    QFile openFile(filePath);

    if (!openFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open read file.");
    }

    QByteArray loadData = openFile.readAll();
    openFile.close();

    QJsonDocument loadDoc(QJsonDocument::fromJson(loadData));
//    ui->segmentWidget->read(loadDoc.object());
}
