#include "window_munk_power_supply.h"
#include "ui_window_munk_power_supply.h"

Window_MunkPowerSupply::Window_MunkPowerSupply(MunkPowerSupply *obj, QWidget *parent) :
    GeneralDialogWindow(DialogWindowTypes::WINDOW_POWERSUPPLY,"MunkPS",parent),
    ui(new Ui::Window_MunkPowerSupply),
    windowHidden(true),
    munk(obj)
{
    ui->setupUi(this);
    ui->widget_connection->setDiameter(6);

    connect(munk,SIGNAL(signal_MunkConnectionUpdate(common::comms::CommunicationConnection)),this,SLOT(on_connectionUpdated(common::comms::CommunicationConnection)));

    GeneralDialogWindow::readWindowSettings();

    openFromFile(GeneralDialogWindow::getPreviousSettingsPath());
}

Window_MunkPowerSupply::~Window_MunkPowerSupply()
{
    delete ui;
}

void Window_MunkPowerSupply::closeEvent(QCloseEvent *event)
{
    saveToFile(getPreviousSettingsPath());
    GeneralDialogWindow::closeEvent(event);
}

void Window_MunkPowerSupply::on_connectionUpdated(const common::comms::CommunicationConnection &connection)
{
    if(connection.isConnected())
        ui->widget_connection->setColor(QColor(0,255,0));
    else
        ui->widget_connection->setColor(QColor(255,0,0));
}
void Window_MunkPowerSupply::on_pushButton_AddSegment_released()
{
    ui->segmentWidget->addNewSegment();
    ui->segmentWidget->cbiSegmentDataInterface_UpdatedData();
}


void Window_MunkPowerSupply::on_pushButton_transmit_released()
{
    registers_Munk::SegmentTimeDetailed dataSegment = ui->segmentWidget->getRawData();
    munk->generateAndTransmitMessage(dataSegment);
}

void Window_MunkPowerSupply::on_actionOpen_triggered()
{
    QString filePath = GeneralDialogWindow::onOpenAction();
    if(!filePath.isEmpty() && !filePath.isNull()){
        openFromFile(filePath);
    }
}

void Window_MunkPowerSupply::on_actionSave_triggered()
{
    QString settingsPath = GeneralDialogWindow::onSaveAction();
    saveToFile(settingsPath);
}

void Window_MunkPowerSupply::on_actionSave_As_triggered()
{
    QString settingsPath = GeneralDialogWindow::onSaveAsAction();
    saveToFile(settingsPath);
}

void Window_MunkPowerSupply::on_actionClose_triggered()
{
    GeneralDialogWindow::onCloseAction();
}

void Window_MunkPowerSupply::saveToFile(const QString &filePath)
{
    QFile saveFile(filePath);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
    }
    QJsonObject saveObject;
    ui->segmentWidget->write(saveObject);
    QJsonDocument saveDoc(saveObject);
    saveFile.write(saveDoc.toJson());
    saveFile.close();
}

void Window_MunkPowerSupply::openFromFile(const QString &filePath)
{
    QFile openFile(filePath);

    if (!openFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open read file.");
    }

    QByteArray loadData = openFile.readAll();
    openFile.close();

    QJsonDocument loadDoc(QJsonDocument::fromJson(loadData));
    ui->segmentWidget->read(loadDoc.object());
}
