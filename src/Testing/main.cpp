#include <QCoreApplication>
#include <iostream>

#include <conio.h>
#include <cstring>

#include "common/modbus_register.h"
#include "library_plc/data_registers/register_ph.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    registers_PLC::Register_pH newRequest;
    QByteArray modbusArray = newRequest.getFullMessage();
    QByteArray tmpArray = newRequest.getByteArray();
    ModbusRegister modbusRequest = newRequest.getModbusRegister();
    unsigned int length = modbusRequest.readRegisterLength();
    std::cout<<"The length seen here is: "<<length<<std::endl;
    return a.exec();
}
