#ifndef SERIALCONFIGURATION_MUNK_H
#define SERIALCONFIGURATION_MUNK_H

#include <QSerialPort>
#include <QStringList>
#include <string>

#include "common/common.h"
#include "common/comms/link_configuration.h"



namespace comms_Munk{

class SerialConfiguration : public common::comms::LinkConfiguration
{
public:
    SerialConfiguration(const std::string& name = "");
    SerialConfiguration(SerialConfiguration* copy);


    int  baud() const         { return _baud; }
    int  dataBits() const     { return _dataBits; }
    int  flowControl() const  { return _flowControl; }    ///< QSerialPort Enums
    int  stopBits() const     { return _stopBits; }
    int  parity() const       { return _parity; }         ///< QSerialPort Enums
    bool usbDirect() const    { return _usbDirect; }

    const std::string portName          () const { return _portName; }
    const std::string portDisplayName   () { return _portDisplayName; }

    void setBaud            (int baud);
    void setDataBits        (int databits);
    void setFlowControl     (int flowControl);          ///< QSerialPort Enums
    void setStopBits        (int stopBits);
    void setParity          (int parity);               ///< QSerialPort Enums
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
    int _baud ;
    int _dataBits;
    int _flowControl;
    int _stopBits;
    int _parity;
    std::string _portName;
    std::string _portDisplayName;
    bool _usbDirect;
};

} //end of namespace comms_Munk


#endif // SERIALCONFIGURATION_MUNK_H
