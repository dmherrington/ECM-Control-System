#ifndef SENSORAY_SERIAL_CONFIGURATION_H
#define SENSORAY_SERIAL_CONFIGURATION_H

#include <QSerialPort>

#include "s24xx.h"


namespace comms_Sensoray{

static inline S2426_DATABITS getSensorayDataBits(const QSerialPort::DataBits &dataBits)
{
    S2426_DATABITS rtn = NDATABITS_5;

    switch (dataBits) {
    case QSerialPort::Data5:
        rtn = NDATABITS_5;
        break;
    case QSerialPort::Data6:
        rtn = NDATABITS_6;
        break;
    case QSerialPort::Data7:
        rtn = NDATABITS_7;
        break;
    case QSerialPort::Data8:
        rtn = NDATABITS_8;
        break;
    default:
        break;
    }

    return rtn;
}
static inline S2426_STOPBITS getSensorayStopBits(const QSerialPort::StopBits &stopBits)
{
    S2426_STOPBITS rtn = STOPBITS_0;

    switch (stopBits) {
    case QSerialPort::OneStop:
    case QSerialPort::OneAndHalfStop:
    case QSerialPort::TwoStop:
        rtn = STOPBITS_1;
    break;

    default:
        break;
    }

    return rtn;
}
static inline S2426_PARITY getSensorayParity(const QSerialPort::Parity &parity)
{
    S2426_PARITY rtn = PARITY_TYPE_NONE;

    switch (parity) {
    case QSerialPort::EvenParity:
        rtn = PARITY_TYPE_EVEN;
        break;
    case QSerialPort::OddParity:
        rtn = PARITY_TYPE_ODD;
        break;
    case QSerialPort::NoParity:
        rtn = PARITY_TYPE_NONE;
        break;
    default:
        break;
    }

    return rtn;
}

} //end of namespace comms


#endif // SENSORAY_SERIAL_CONFIGURATION_H
