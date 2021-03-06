#ifndef TABLE_WIDGET_OPERATION_DESCRIPTOR_H
#define TABLE_WIDGET_OPERATION_DESCRIPTOR_H

#include <QWidget>

#include "widget_abstract_profile.h"
#include "widget_profile_parameters.h"

#include "ECM_API/commands/ecm_command_profile_configuration.h"

namespace Ui {
class TableWidget_OperationDescriptor;
}

class TableWidget_OperationDescriptor : public QWidget
{
    Q_OBJECT

public:
    explicit TableWidget_OperationDescriptor(Widget_AbstractProfile *operationalProfile, QWidget *parent = 0);
    ~TableWidget_OperationDescriptor();

public:

    void setOperationUsage(const bool &use);
    bool shouldOperationBeUsed() const;

    void setOperationIndex(const unsigned int &index);
    unsigned int getOperationIndex() const;

    void setOperationName(const std::string &name);
    std::string getOperationName() const;

    //void setShouldHomeIndicateAutomatically(const bool &indicate);

    Widget_AbstractProfile* getAccompanyingProfile();

    //void newlyAvailableProgramLabels(const ProgramLabelList &labels);

public:
    ECMCommand_AbstractProfileConfigPtr getCurrentProfileConfiguration() const;

    void loadFromProfileConfiguration(const ECMCommand_AbstractProfileConfigPtr config);

private slots:

    void on_pushButton_ExecuteExplicitOp_released();

    void on_checkBox_EnableOperation_toggled(bool checked);

    void on_lineEdit_OperationName_textChanged(const QString &arg1);

signals:
    void signal_OperationNameChanged(const std::string &name, const unsigned int &index);

    void signal_ExecuteExplicitProfileConfig(ECMCommand_AbstractProfileConfigPtr config);

private:
    Ui::TableWidget_OperationDescriptor *ui;

    Widget_AbstractProfile* m_AbstractOperation;

private:
    unsigned int operationIndex = 0;
    std::string operationName = "";
    bool useOperation = false;
    //bool indicateHome = false;
};

#endif // TABLE_WIDGET_OPERATION_DESCRIPTOR_H
