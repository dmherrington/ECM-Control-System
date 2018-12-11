#include "window_motion_profile.h"
#include "ui_window_motion_profile.h"

Window_MotionProfile::Window_MotionProfile(GalilMotionController *obj, QWidget *parent) :
    GeneralDialogWindow(DialogWindowTypes::WINDOW_MOTION_PROFILE,"Motion Profile",parent),
    m_MotionController(obj),
    ui(new Ui::Window_MotionProfile)
{
    ui->setupUi(this);
    ui->led_ProgramCurrent->setDiameter(5);
    ui->led_ProgramCurrent->setColor(QColor(255,0,0));

    GeneralDialogWindow::readWindowSettings();

    m_MotionController->AddLambda_FinishedUploadingScript(this,[this](const bool &completed, const GalilCurrentProgram &program){
        if(completed)
        {
            std::string loadPath = "";
            if(program.wasProgramLoaded(loadPath))
            {
                ui->lineEdit_motionScriptPath->setText(QString::fromStdString(loadPath));
            }

            ui->codeTextEdit->clear();
            ui->codeTextEdit->setPlainText(QString::fromStdString(program.getProgram()));
            ui->led_ProgramCurrent->setColor(QColor(0,255,0));
        }
    });

}

void Window_MotionProfile::setFilePath(const std::string &path)
{
    ui->lineEdit_motionScriptPath->setText(QString::fromStdString(path));
}

void Window_MotionProfile::setProgramText(const std::string &programText)
{
    ui->codeTextEdit->setPlainText(QString::fromStdString(programText));
}

void Window_MotionProfile::openGalilScript()
{
    this->on_actionOpen_triggered();
}

void Window_MotionProfile::uploadGalilScript()
{
    this->on_pushButton_UploadProgram_released();
}

void Window_MotionProfile::downloadGalilScript()
{
    this->on_pushButton_DownloadProgram_released();
}

std::string Window_MotionProfile::getCurrentGalilScript() const
{
    return ui->codeTextEdit->toPlainText().toStdString();
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


void Window_MotionProfile::on_actionOpen_triggered()
{
    std::string extensionFilter = "Open TXT Files (*.txt);; Open DMC Files (*.dmc);; Open JSON Files(*.json)";

    QString filePath = GeneralDialogWindow::onOpenAction(extensionFilter);
    if(!filePath.isEmpty() && !filePath.isNull()){
        openFromFile(filePath);
    }
}

void Window_MotionProfile::on_actionClose_triggered()
{
    GeneralDialogWindow::onCloseAction();
}

void Window_MotionProfile::on_actionSave_triggered()
{
    QString filePath = GeneralDialogWindow::onSaveAction("txt");
    if(!filePath.isEmpty())
        this->saveToFile(filePath);
}

void Window_MotionProfile::on_actionSave_As_triggered()
{
    QString filePath = GeneralDialogWindow::onSaveAsAction("txt");
    if(!filePath.isEmpty())
        this->saveToFile(filePath);
}

void Window_MotionProfile::saveToFile(const QString &filePath)
{
    QFile saveFile(filePath);

    if (!saveFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        ui->statusbar->showMessage("Couldn't open file for saving.",2000);
        return;
    }

    this->setFilePath(filePath.toStdString());
    QTextStream outStream(&saveFile);
    outStream << ui->codeTextEdit->toPlainText();
    saveFile.close();
}

void Window_MotionProfile::openFromFile(const QString &filePath)
{
    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    this->setFilePath(filePath.toStdString());

    QTextStream inStream(&file);
    QString programText = inStream.readAll();
    file.close();

    ui->lineEdit_motionScriptPath->setText(filePath);
    ui->codeTextEdit->setPlainText(programText);
}

void Window_MotionProfile::updateStatusLED(const QColor &color)
{
    ui->led_ProgramCurrent->setColor(color);
}

void Window_MotionProfile::on_codeTextEdit_textChanged()
{
    if(ui->lineEdit_motionScriptPath->text().toStdString() != m_MotionController->getCurrentMCProgram().getProgram())
    {
        updateStatusLED(QColor(255,0,0));
    }
    else{
        updateStatusLED(QColor(0,255,0));
    }
}

void Window_MotionProfile::on_pushButton_UploadProgram_released()
{
    std::string programString = ui->codeTextEdit->toPlainText().toStdString();

    CommandUploadProgramPtr commandUploadDefault = std::make_shared<CommandUploadProgram>();
    commandUploadDefault->setCurrentScript(programString);
    m_MotionController->executeCommand(commandUploadDefault);
}

void Window_MotionProfile::on_pushButton_DownloadProgram_released()
{
    CommandDownloadProgramPtr commandDownloadDefault = std::make_shared<CommandDownloadProgram>();
    m_MotionController->executeCommand(commandDownloadDefault);
}
