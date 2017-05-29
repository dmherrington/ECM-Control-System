#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int decimal = 4191;
    QByteArray B2;
    char test;
    test = static_cast<char>(01);
    B2.append(test);
    Buffer[0] = test;

    test = static_cast<char>(03);
    B2.append(test);
    Buffer[1] = test;

//    char HIGH = (char)((decimal & 0xFF00) >> 8);
//    char LOW = (char)(decimal & 0x00FF);
//    B2.append(HIGH);
//    B2.append(LOW);
//    Buffer[2] = HIGH;
//    Buffer[3] = LOW;

    test = static_cast<char>(00); //00
    B2.append(test);
    Buffer[2] = test;

    test = static_cast<char>(10);
    B2.append(test);
    Buffer[3] = test;

    test = static_cast<char>(0);
    B2.append(test);
    Buffer[4] = test;

    test = static_cast<char>(1);
    B2.append(test);
    Buffer[5] = test;

    test = static_cast<char>(0);
    B2.append(test);
    Buffer[8] = test;

    test = static_cast<char>(16);
    B2.append(test);
    Buffer[9] = test;

    test = static_cast<char>(178);
    B2.append(test);
    Buffer[10] = test;

    CRC16(6);
}

MainWindow::~MainWindow()
{
    delete ui;
}

WORD MainWindow::CRC16(const int &cnt)
{
    char c,j;
    unsigned int Temp = 0xFFFF;

    for (int i=0;i<cnt;i++){
        Temp ^= (WORD)Buffer[i];
        for (j=8;j!=0;j--){

            if ((Temp & 0x0001) != 0) {      // If the LSB is set
                Temp >>= 1;                    // Shift right and XOR 0xA001
                Temp ^= 0xA001;
            }
            else                            // Else LSB is not set
                Temp >>= 1;                    // Just shift right
        }
    }
    char HIGH = (char)((Temp & 0xFF00) >> 8);
    char LOW = (char)(Temp & 0x00FF);

    return Temp;
}
