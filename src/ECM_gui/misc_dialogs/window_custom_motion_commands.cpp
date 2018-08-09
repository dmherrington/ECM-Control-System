#include "window_custom_motion_commands.h"
#include "ui_window_custom_motion_commands.h"

Window_CustomMotionCommands::Window_CustomMotionCommands(GalilMotionController *obj, QWidget *parent) :
    GeneralDialogWindow(DialogWindowTypes::WINDOW_CUSTOM_MOTION_COMMANDS,"Motion Commands",parent),
    m_MotionController(obj),
    ui(new Ui::Window_CustomMotionCommands)
{
    ui->setupUi(this);

    GeneralDialogWindow::readWindowSettings();
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

    ui->lineEdit_MotionCommand->clear();

    m_MotionController->executeStringCommand(commandText);
}

void Window_CustomMotionCommands::slot_onMotionResponseReceived(const string &commandText, const string &text)
{
    std::string displayCommand = "Command: " + commandText + "\r\n";
    std::string displayResponse = "Response: " + text;
    ui->plainTextEdit_MotionResponse->document()->setPlainText(QString::fromStdString(displayCommand + displayResponse));
}
