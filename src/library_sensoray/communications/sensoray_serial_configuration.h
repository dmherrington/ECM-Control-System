#ifndef SENSORAY_SERIAL_CONFIGURATION_H
#define SENSORAY_SERIAL_CONFIGURATION_H

#include <QSerialPort>
#include <QStringList>
#include <string>

#include "common/common.h"
#include "link_configuration.h"

#include "s24xx.h"

namespace sensoray {
namespace comms{

class SerialConfiguration : public LinkConfiguration
{

public:
    enum SerialParity {
        NoParity = 0,
        EvenParity = 1,
        OddParity = 2
    };

public:
    SerialConfiguration(const std::string& name = "");
    SerialConfiguration(SerialConfiguration* copy);


    int  baud() const         { return _baud; }
    int  dataBits() const     { return _dataBits; }
    int  flowControl() const  { return _flowControl; }
    int  stopBits() const     { return _stopBits; }
    SerialParity  parity() const       { return _parity; }

    void setBaud            (const int &baud);
    void setDataBits        (const int &databits);
    void setFlowControl     (const int &flowControl);
    void setStopBits        (const int &stopBits);
    void setParity          (const SerialParity &parity);

    /// From LinkConfiguration
    void        copyFrom        (LinkConfiguration* source);

    S2426_DATABITS getSensorayDataBits() const;
    S2426_STOPBITS getSensorayStopBits() const;
    S2426_PARITY getSensorayParity() const;

private:
    int _baud ;
    int _dataBits;
    int _flowControl;
    int _stopBits;
    SerialParity _parity;
};

} //end of namespace comms
} //end of namespace sensoray

#endif // SENSORAY_SERIAL_CONFIGURATION_H
