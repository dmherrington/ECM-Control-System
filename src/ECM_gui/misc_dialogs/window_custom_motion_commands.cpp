#include "window_custom_motion_commands.h"
#include "ui_window_custom_motion_commands.h"

Window_CustomMotionCommands::Window_CustomMotionCommands(SPIIMotionController *obj, QWidget *parent) :
    GeneralDialogWindow(DialogWindowTypes::WINDOW_CUSTOM_MOTION_COMMANDS,"Motion Commands",parent),
    m_MotionController(obj),
    ui(new Ui::Window_CustomMotionCommands)
{
    ui->setupUi(this);

    GeneralDialogWindow::readWindowSettings();

    connect(ui->plainTextEdit_MotionResponse, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slot_ShowRepsonseTextEditContextMenu(const QPoint &)));

    connect(m_MotionController, SIGNAL(signal_CustomUserRequestReceived(std::string,std::string)), this, SLOT(slot_onMotionResponseReceived(std::string,std::string)));

    connect(ui->lineEdit_MotionCommand, SIGNAL(returnPressed()), this, SLOT(on_pushButton_TransmitMotionCommand_released()));
}

Window_CustomMotionCommands::~Window_CustomMotionCommands()
{
    delete ui;
}

void Window_CustomMotionCommands::closeEvent(QCloseEvent *event)
{
    //saveToFile(getPreviousSettingsPath()); Is there anything to save to the file in this sense
    GeneralDialogWindow::closeEvent(event);
}

void Window_CustomMotionCommands::on_actionClose_triggered()
{
    GeneralDialogWindow::onCloseAction();
}

void Window_CustomMotionCommands::on_pushButton_TransmitMotionCommand_released()
{
    QString commandText = ui->lineEdit_MotionCommand->text();
    QRegExp rx("[;]");// match a semi-colon
    QStringList list = commandText.split(rx, QString::SkipEmptyParts);

    std::vector<std::string> commands;
    for(int i = 0; i < list.size(); i++)
    {
        commands.push_back(list.at(i).toStdString());
    }
    if(commands.size() > 0)
    {
        ui->lineEdit_MotionCommand->clear();
        m_MotionController->executeCustomCommands(commands);
    }
}

void Window_CustomMotionCommands::slot_onMotionResponseReceived(const string &commandText, const string &text)
{
    std::string displayCommand = "Command: " + commandText + "\r\n";
    std::string displayResponse = "Response: " + text;
    ui->plainTextEdit_MotionResponse->appendPlainText(QString::fromStdString(displayCommand + displayResponse));
}

void Window_CustomMotionCommands::slot_ShowRepsonseTextEditContextMenu(const QPoint &pos)
{
    QMenu contextMenu(tr("Context menu"), this);

    QAction action1("Clear Text Field", this);
    connect(&action1, SIGNAL(triggered()), this, SLOT(slot_ClearResponseTextEdit()));
    contextMenu.addAction(&action1);

    contextMenu.exec(mapToGlobal(pos));
}

void Window_CustomMotionCommands::slot_ClearResponseTextEdit()
{
    ui->plainTextEdit_MotionResponse->clear();
}
