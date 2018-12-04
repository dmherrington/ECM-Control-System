#ifndef WINDOW_PROFILE_CONFIGURATION_H
#define WINDOW_PROFILE_CONFIGURATION_H

#include <QMainWindow>
#include <QListWidgetItem>

#include "ECM_API/ecm_api.h"
#include "../general_dialog_window.h"

#include "widget_profile_parameters.h"
#include "table_widget_operation_descriptor.h"

#include "ECM_API/commands/ecm_command_execute_collection.h"
#include "ECM_API/commands/ecm_command_profile_collection.h"

namespace Ui {
class Window_ProfileConfiguration;
}

class Window_ProfileConfiguration : public GeneralDialogWindow
{
    Q_OBJECT

public:
    explicit Window_ProfileConfiguration(ECM_API* apiObject, QWidget *parent = 0);
    ~Window_ProfileConfiguration();

private:
    void closeEvent(QCloseEvent *event) override;

public:
    void updateConfigurationPath(const std::string &path);

    void executingProfileIndex(const unsigned int &index);

private:
    TableWidget_OperationDescriptor* addOperation(const unsigned int &index);

    void clearExistingOperations();

signals:
    void signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes &type, const bool &visibility) override;

    void signal_LoadMotionProfile(const std::string &filePath);

    void signal_ExecuteProfileCollection(const ECMCommand_ExecuteCollection &collection);

private slots:
    void on_pushButton_AddOperation_released();

    void on_pushButton_RemoveOperation_released();

    void slot_OperationNameChanged(const std::string &name, const unsigned int &index);

    void on_ListWidgetRowMoved();

    void on_pushButton_OpenMotionScript_released();

    void on_listWidget_customContextMenuRequested(const QPoint &pos);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void slot_MCNewProgramLabels(const ProgramLabelList &labels);

private slots:
    void slot_OnExecuteExplicitProfileConfig(const ECMCommand_ProfileConfiguration &config);
private:
    void saveToFile(const QString &filePath);

    void openFromFile(const QString &filePath);

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionClose_triggered();

private:
    Ui::Window_ProfileConfiguration *ui;
    ECM_API* m_API;

private:
    std::map<QListWidgetItem*,TableWidget_OperationDescriptor*> m_MapOperations;
};

#endif // WINDOW_PROFILE_CONFIGURATION_H