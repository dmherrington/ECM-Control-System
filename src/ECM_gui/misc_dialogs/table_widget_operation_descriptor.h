#ifndef TABLE_WIDGET_OPERATION_DESCRIPTOR_H
#define TABLE_WIDGET_OPERATION_DESCRIPTOR_H

#include <QWidget>

#include "widget_profile_parameters.h"

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
    void setOperationIndex(const unsigned int &index);
    unsigned int getOperationIndex() const;

    void setOperationName(const std::string &name);
    std::string getOperationName() const;

    Widget_ProfileParameters* getAccompanyingProfile();


private slots:
    void on_lineEdit_ProfileName_textChanged(const QString &arg1);

signals:
    void signal_OperationNameChanged(const std::string &name, const int &index);

private:
    Ui::TableWidget_OperationDescriptor *ui;

    Widget_ProfileParameters* m_OperationParamters;

private:
    unsigned int operationIndex = 0;
    std::string operationName = "";
};

#endif // TABLE_WIDGET_OPERATION_DESCRIPTOR_H
