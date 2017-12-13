#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int currentIndex = ui->toolBox->currentIndex();
    std::string boxName = ui->toolBox->itemText(currentIndex).toStdString();
    ui->toolBox->removeItem(currentIndex);


    char* ECMPath = getenv("ECM_ROOT");
    if(ECMPath){
        std::string rootPath(ECMPath);
        QDir settingsDirectory(QString::fromStdString(rootPath + "/Galil/settings"));
        settingsDirectory.mkpath(QString::fromStdString(rootPath + "/Galil/settings"));
        settingsPath = settingsDirectory.absolutePath() + "/generalSettings.json";
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_AddMotionProfile_clicked()
{
    WidgetVariableDataDisplay* newWidget = new WidgetVariableDataDisplay();
    std::pair<std::map<std::string,WidgetVariableDataDisplay*>::iterator,bool> ret;

    ret = mapData.insert(std::make_pair(newWidget->getProfileName(),newWidget));
    if(ret.second == false)
    {
        //the element already existed
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Test");
        std::string text = "The profile labeled '";
        text+=newWidget->getProfileName();
        text+="' already exists. ";
        msgBox.setText(QString::fromStdString(text));
        msgBox.setInformativeText("Please consider changing/removing the conflicting profile.");
        msgBox.exec();
    }
    else{
        mapData[newWidget->getProfileName()] = newWidget;
        connect(newWidget,SIGNAL(signal_updatedProfileName(std::string&)),
                this,SLOT(slot_updatedProfileName(std::string&)));

        ui->toolBox->addItem(newWidget,QString::fromStdString(newWidget->getProfileName()));
        int pageCount = ui->toolBox->count();
        ui->toolBox->setCurrentIndex(pageCount - 1);
    }
}

void MainWindow::on_pushButton_RemoveMotionProfile_clicked()
{
    int currentIndex = ui->toolBox->currentIndex();
    std::string boxName = ui->toolBox->itemText(currentIndex).toStdString();
    ui->toolBox->removeItem(currentIndex);
    if(mapData.count(boxName))
    {
        WidgetVariableDataDisplay* destroyWidget = mapData.at(boxName);
        delete destroyWidget;
        destroyWidget = nullptr;
        mapData.erase(boxName);
    }
    else{
        //for some reason it was not in the map
    }
}

void MainWindow::slot_updatedProfileName(std::string &name)
{
    if(mapData.count(name) == 0)
    {
        int currentIndex = ui->toolBox->currentIndex();
        std::string currentBoxName = ui->toolBox->itemText(currentIndex).toStdString();

        WidgetVariableDataDisplay* changedWidget = mapData.at(currentBoxName);
        mapData.insert(std::make_pair(name,changedWidget));
        ui->toolBox->setItemText(currentIndex,QString::fromStdString(name));
        mapData.erase(currentBoxName);
    }
    else{
        //the element already existed
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Test");
        std::string text = "The profile labeled '";
        text+=name;
        text+="' already exists. ";
        msgBox.setText(QString::fromStdString(text));
        msgBox.setInformativeText("Please consider changing/removing the conflicting profile.");
        msgBox.exec();
    }
}

void MainWindow::on_actionSave_triggered()
{
    this->saveSettings(this->settingsPath);
}

void MainWindow::on_actionSave_As_triggered()
{
    QString fullFile = saveAsFileDialog(this->getSettingsPath().toStdString(),"json");
    if(!fullFile.isEmpty()&& !fullFile.isNull()){
        this->settingsPath = fullFile;
        this->saveSettings(this->settingsPath);
    }
}

void MainWindow::on_actionLoad_triggered()
{
    QString fullFile = loadFileDialog(this->getSettingsPath().toStdString(),"json");
    if(!fullFile.isEmpty()&& !fullFile.isNull()){
        this->loadSettings(fullFile);
    }
}

void MainWindow::on_actionExit_triggered()
{
    std::map<std::string,WidgetVariableDataDisplay*>::iterator it;
    for(it = mapData.begin(); it != mapData.end(); ++it)
    {
        WidgetVariableDataDisplay* data = it->second;
        if(data->hasDataChanged())
        {
            //This would imply that we have unsaved changes
            std::cout<<"We have unsaved changes"<<std::endl;
            break;
        }
    }

    qApp->quit();
}


QString MainWindow::saveAsFileDialog(const std::string &filePath, const std::string &suffix)
{
    QFileDialog fileDialog(this, "Save profile as:");
    QDir galilProgramDirectory(QString::fromStdString(filePath));
    fileDialog.setDirectory(galilProgramDirectory);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    QString nameFilter = "Open Files (*.";
    nameFilter += QString::fromStdString(suffix) + ")";
    fileDialog.setNameFilter(nameFilter);
    fileDialog.setDefaultSuffix(QString::fromStdString(suffix));
    fileDialog.exec();
    QString fullFilePath = fileDialog.selectedFiles().first();
    return fullFilePath;
}

QString MainWindow::loadFileDialog(const std::string &filePath, const std::string &suffix)
{
    QFileDialog fileDialog(this, "Choose profile to open");
    QDir galilProgramDirectory(QString::fromStdString(filePath));
    fileDialog.setDirectory(galilProgramDirectory);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    QString nameFilter = "Open Files (*.";
    nameFilter += QString::fromStdString(suffix) + ")";
    fileDialog.setNameFilter(nameFilter);
    fileDialog.setDefaultSuffix(QString::fromStdString(suffix));
    fileDialog.exec();
    QString fullFilePath = fileDialog.selectedFiles().first();
    return fullFilePath;
}

QString MainWindow::getSettingsPath()
{
    QFile file(settingsPath);
    QFileInfo fileInfo(file);
    return fileInfo.absolutePath();
}

void MainWindow::saveSettings(const QString &path)
{
    QFile saveFile(path);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
    }

    QJsonObject saveObject;
    std::map<std::string,WidgetVariableDataDisplay*>::iterator it;
    for(it = mapData.begin(); it != mapData.end(); ++it)
    {
        WidgetVariableDataDisplay* data = it->second;
        data->write(saveObject);
    }

    QJsonDocument saveDoc(saveObject);

    qint64 rtnValue = saveFile.write(saveDoc.toJson());
    if(rtnValue != -1)
    {
        for(it = mapData.begin(); it != mapData.end(); ++it)
        {
            WidgetVariableDataDisplay* data = it->second;
            data->setDataChanged(false);
        }
    }
}

void MainWindow::loadSettings(const QString &path)
{
    QFile settingsFile(path);

    if (!settingsFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
    }

    QByteArray loadData = settingsFile.readAll();
    QJsonDocument loadDoc = QJsonDocument::fromJson(loadData);
    QJsonObject jsonObj = loadDoc.object();
    foreach(const QString& key, jsonObj.keys()) {
        QJsonArray jsonArray = jsonObj[key].toArray();

        WidgetVariableDataDisplay* newWidget = new WidgetVariableDataDisplay();
        newWidget->setProfileName(key.toStdString());
        newWidget->read(jsonArray);
        mapData[newWidget->getProfileName()] = newWidget;
        connect(newWidget,SIGNAL(signal_updatedProfileName(std::string&)),
                this,SLOT(slot_updatedProfileName(std::string&)));

        ui->toolBox->addItem(newWidget,QString::fromStdString(newWidget->getProfileName()));

    }
}

void MainWindow::on_actionAppClosing()
{

}


