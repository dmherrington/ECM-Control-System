#ifndef SERIAL_CONFIGURATION_H
#define SERIAL_CONFIGURATION_H

#include <QSerialPort>
#include <QStringList>
#include <string>

#include "../common.h"
#include "link_configuration.h"

namespace common {
namespace comms{

class SerialConfiguration : public LinkConfiguration
{
public:
    SerialConfiguration(const std::string& name = "");
    SerialConfiguration(SerialConfiguration* copy);


    QSerialPort::BaudRate  baud() const         { return _baud; }
    QSerialPort::DataBits  dataBits() const     { return _dataBits; }
    QSerialPort::FlowControl  flowControl() const  { return _flowControl; }    ///< QSerialPort Enums
    QSerialPort::StopBits  stopBits() const     { return _stopBits; }
    QSerialPort::Parity  parity() const       { return _parity; }         ///< QSerialPort Enums
    bool usbDirect() const    { return _usbDirect; }

    const std::string portName          () const { return _portName; }
    const std::string portDisplayName   () { return _portDisplayName; }

    void setBaud            (QSerialPort::BaudRate baud);
    void setDataBits        (QSerialPort::DataBits databits);
    void setFlowControl     (QSerialPort::FlowControl flowControl);          ///< QSerialPort Enums
    void setStopBits        (QSerialPort::StopBits stopBits);
    void setParity          (QSerialPort::Parity parity);               ///< QSerialPort Enums
    void setPortName        (const std::string& portName);
    void setUsbDirect       (bool usbDirect);

    static QStringList supportedBaudRates();
    static std::string cleanPortDisplayname(const std::string &name);

    /// From LinkConfiguration
    void        copyFrom        (LinkConfiguration* source);
    //void        loadSettings    (Settings& settings, const QString& root);
    //void        saveSettings    (Settings& settings, const QString& root);
    //void        updateSettings  ();
    //QString     settingsURL     () { return "SerialSettings.qml"; }

    static void _initBaudRates();

private:
    QSerialPort::BaudRate _baud ;
    QSerialPort::DataBits _dataBits;
    QSerialPort::FlowControl _flowControl;
    QSerialPort::StopBits _stopBits;
    QSerialPort::Parity _parity;
    std::string _portName;
    std::string _portDisplayName;
    bool _usbDirect;
};

} //end of namespace comms
} //end of namespace common

#endif // SERIAL_CONFIGURATION_H
