#ifndef TABLE_WIDGET_OPERATION_DESCRIPTOR_H
#define TABLE_WIDGET_OPERATION_DESCRIPTOR_H

#include <QWidget>

#include "widget_profile_parameters.h"

#include "ECM_API/commands/ecm_command_profile_configuration.h"

namespace Ui {
class TableWidget_OperationDescriptor;
}

class TableWidget_OperationDescriptor : public QWidget
{
    Q_OBJECT

public:
    explicit TableWidget_OperationDescriptor(Widget_ProfileParameters* operationParameters, QWidget *parent = 0);
    ~TableWidget_OperationDescriptor();

public:

    void setOperationUsage(const bool &use);
    bool shouldOperationBeUsed() const;

    void setOperationIndex(const unsigned int &index);
    unsigned int getOperationIndex() const;

    void setOperationName(const std::string &name);
    std::string getOperationName() const;

    Widget_ProfileParameters* getAccompanyingProfile();

    void newlyAvailableProgramLabels(const ProgramLabelList &labels);

public:
    ECMCommand_ProfileConfiguration getCurrentProfileConfiguration() const;

    void loadFromProfileConfiguration(const ECMCommand_ProfileConfiguration &config);

private slots:
    void on_lineEdit_ProfileName_textChanged(const QString &arg1);

    void on_pushButton_ExecuteExplicitOp_released();

    void on_checkBox_EnableOperation_toggled(bool checked);

signals:
    void signal_OperationNameChanged(const std::string &name, const int &index);

    void signal_ExecuteExplicitProfileConfig(const ECMCommand_ProfileConfiguration &config);

private:
    Ui::TableWidget_OperationDescriptor *ui;

    Widget_ProfileParameters* m_OperationParameters;

private:
    unsigned int operationIndex = 0;
    std::string operationName = "";
    bool useOperation = false;
};

#endif // TABLE_WIDGET_OPERATION_DESCRIPTOR_H
