#include "window_motion_profile.h"
#include "ui_window_motion_profile.h"

Window_MotionProfile::Window_MotionProfile(GalilMotionController *obj, QWidget *parent) :
    GeneralDialogWindow(DialogWindowTypes::WINDOW_MOTION_PROFILE,"Touchoff",parent),
    m_MotionController(obj),
    ui(new Ui::Window_MotionProfile)
{
    ui->setupUi(this);
    ui->led_ProgramCurrent->setDiameter(5);

    GeneralDialogWindow::readWindowSettings();

    connect(m_MotionController,SIGNAL(signal_MCNewProgramReceived(ProgramGeneric)),this,SLOT(slot_MCNewProgramAvailable(ProgramGeneric)));
}

Window_MotionProfile::~Window_MotionProfile()
{
    delete ui;
}

void Window_MotionProfile::closeEvent(QCloseEvent *event)
{
    saveToFile(getPreviousSettingsPath());
    GeneralDialogWindow::closeEvent(event);
}

void Window_MotionProfile::on_actionClose_triggered()
{
    GeneralDialogWindow::onCloseAction();
}

void Window_MotionProfile::saveToFile(const QString &filePath)
{
    UNUSED(filePath);
}

void Window_MotionProfile::openFromFile(const QString &filePath)
{
    UNUSED(filePath);
}

void Window_MotionProfile::slot_MCNewProgramAvailable(const ProgramGeneric &program)
{
    ui->codeTextEdit->clear();
    ui->codeTextEdit->setPlainText(QString::fromStdString(program.getProgramString()));
    ui->led_ProgramCurrent->setColor(QColor(0,255,0));
}

void Window_MotionProfile::on_codeTextEdit_textChanged()
{
    ui->led_ProgramCurrent->setColor(QColor(255,0,0));
}

void Window_MotionProfile::on_pushButton_UploadProgram_released()
{
    std::string programString = ui->codeTextEdit->toPlainText().toStdString();

    ProgramGeneric newProgram;
    newProgram.setProgramString(programString);

    CommandUploadProgramPtr commandUploadDefault = std::make_shared<CommandUploadProgram>();
    commandUploadDefault->setProgram(newProgram);
    m_MotionController->executeCommand(commandUploadDefault.get());
}

void Window_MotionProfile::on_pushButton_DownloadProgram_released()
{
    CommandDownloadProgramPtr commandDownloadDefault = std::make_shared<CommandDownloadProgram>();
    m_MotionController->executeCommand(commandDownloadDefault.get());
}
