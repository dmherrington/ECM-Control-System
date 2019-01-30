#ifndef WIDGET_VARIABLE_EDIT_H
#define WIDGET_VARIABLE_EDIT_H

#include <QWidget>

namespace Ui {
class Widget_VariableEdit;
}

class Widget_VariableEdit : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_VariableEdit(QWidget *parent = 0);
    ~Widget_VariableEdit();

private:
    Ui::Widget_VariableEdit *ui;
};

#endif // WIDGET_VARIABLE_EDIT_H
