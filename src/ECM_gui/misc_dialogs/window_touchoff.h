#ifndef WINDOW_TOUCHOFF_H
#define WINDOW_TOUCHOFF_H

#include <QMainWindow>

namespace Ui {
class Window_Touchoff;
}

class Window_Touchoff : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_Touchoff(QWidget *parent = 0);
    ~Window_Touchoff();

private:
    Ui::Window_Touchoff *ui;
};

#endif // WINDOW_TOUCHOFF_H
