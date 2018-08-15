#include "window_pump_control.h"
#include "ui_window_pump_control.h"

Window_PumpControl::Window_PumpControl(Westinghouse510* obj, QWidget *parent) :
    GeneralDialogWindow(DialogWindowTypes::WINDOW_PUMP,"WestinghousePump",parent),
    ui(new Ui::Window_PumpControl),
    m_Pump(obj)
{
    ui->setupUi(this);
    ui->widget_PumpConnected->setDiameter(6);
    ui->widget_PumpInitialized->setDiameter(6);
    ui->widget_PumpRunning->setDiameter(6);

    connect(m_Pump,SIGNAL(signal_PumpCommunicationUpdate(common::comms::CommunicationUpdate)),this,SLOT(slot_PumpConnectionUpdate(common::comms::CommunicationUpdate)));

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

void Window_PumpControl::setPumpFlowRate(const double &rate)
{
    ui->doubleSpinBox_flowRate->setStyleSheet("background-color: red");
    ui->doubleSpinBox_flowRate->setValue(rate);
}

void Window_PumpControl::setPumpDelayTime(const double &time)
{
    ui->doubleSpinBox_delayTime->setValue(time);
}

void Window_PumpControl::slot_PumpConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    using namespace common::comms;
    switch (update.getUpdateType()) {
    case CommunicationUpdate::UpdateTypes::ALERT:
        ui->statusbar->showMessage(QString::fromStdString(update.getPeripheralMessage()),2000);
        break;
    case CommunicationUpdate::UpdateTypes::CONNECTED:
        ui->widget_PumpConnected->setColor(QColor(0,255,0));
        ui->statusbar->showMessage(QString::fromStdString(update.getPeripheralMessage()),2000);
        break;
    case CommunicationUpdate::UpdateTypes::DISCONNECTED:
        ui->widget_PumpConnected->setColor(QColor(255,0,0));
        ui->statusbar->showMessage(QString::fromStdString(update.getPeripheralMessage()),2000);
        break;
    default:
        break;
    }
}

void Window_PumpControl::slot_updatedPumpOn(const bool &value)
{
    if(value)
    {
        ui->widget_PumpRunning->setColor(QColor(0,255,0));
        ui->pushButton_PumpRunning->setText("OFF");

        common::EnvironmentTime startTime;
        common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,startTime);
        ui->lineEdit_OnTime->setText(QString::fromStdString(startTime.timeString()));
        statusBar()->showMessage(tr("The pump has been turned on."),2500);

        QTimer::singleShot(ui->doubleSpinBox_delayTime->value() * 1000, [=] {
            ui->widget_PumpInitialized->setColor(QColor(0,255,0));
        });    }
    else
    {
        ui->widget_PumpRunning->setColor(QColor(255,0,0));
        ui->widget_PumpInitialized->setColor(QColor(255,0,0));
        ui->doubleSpinBox_flowRate->setStyleSheet("background-color: red");
        ui->pushButton_PumpRunning->setText("ON");
        ui->lineEdit_OnTime->setText("");
        ui->lineEdit_OnTime->clear();
        statusBar()->showMessage(tr("The pump has been turned off."),2500);
    }
}

void Window_PumpControl::slot_updatedFlowRate(const double &value)
{
    if(abs(value - ui->doubleSpinBox_flowRate->value()) < 0.05)
    {
        ui->doubleSpinBox_flowRate->setStyleSheet("background-color: green");
    }
    else{
        ui->doubleSpinBox_flowRate->setStyleSheet("background-color: red");
    }
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
    ui->doubleSpinBox_flowRate->setStyleSheet("background-color: red");
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
    this->write(saveObject);
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
    this->read(loadDoc.object());
}

void Window_PumpControl::read(const QJsonObject &json)
{
    setPumpDelayTime(json["pumpDelayTime"].toDouble());
    setPumpFlowRate(json["pumpFlowRate"].toDouble());
}

void Window_PumpControl::write(QJsonObject &json) const
{
    json["pumpDelayTime"] = this->ui->doubleSpinBox_delayTime->value();
    json["pumpFlowRate"] = this->ui->doubleSpinBox_flowRate->value();
}
