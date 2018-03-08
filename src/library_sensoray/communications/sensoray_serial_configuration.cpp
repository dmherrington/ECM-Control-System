#include "sensoray_serial_configuration.h"

namespace sensoray {
namespace comms{

static QStringList kSupportedBaudRates;

SerialConfiguration::SerialConfiguration(const std::string& name)
{
    _baud       = 19200;
    _flowControl= QSerialPort::NoFlowControl;
    _parity     = SerialParity::NoParity;
    _dataBits   = 8;
    _stopBits   = 1;
}

SerialConfiguration::SerialConfiguration(SerialConfiguration* copy)
{
    _baud               = copy->baud();
    _flowControl        = copy->flowControl();
    _parity             = copy->parity();
    _dataBits           = copy->dataBits();
    _stopBits           = copy->stopBits();
}

void SerialConfiguration::copyFrom(LinkConfiguration* source)
{
    LinkConfiguration::copyFrom(source);
    SerialConfiguration* ssource = dynamic_cast<SerialConfiguration*>(source);
    Q_ASSERT(ssource != NULL);
    _baud               = ssource->baud();
    _flowControl        = ssource->flowControl();
    _parity             = ssource->parity();
    _dataBits           = ssource->dataBits();
    _stopBits           = ssource->stopBits();
}

void SerialConfiguration::setBaud(const int &baud)
{
    _baud = baud;
}

void SerialConfiguration::setDataBits(const int &databits)
{
    _dataBits = databits;
}

void SerialConfiguration::setFlowControl(const int &flowControl)
{
    _flowControl = flowControl;
}

void SerialConfiguration::setStopBits(const int &stopBits)
{
    _stopBits = stopBits;
}

void SerialConfiguration::setParity(const SerialParity &parity)
{
    _parity = parity;
}

S2426_DATABITS SerialConfiguration::getSensorayDataBits() const
{
    S2426_DATABITS rtn = NDATABITS_5;

    switch (_dataBits) {
    case 5:
        rtn = NDATABITS_5;
        break;
    case 6:
        rtn = NDATABITS_6;
        break;
    case 7:
        rtn = NDATABITS_7;
        break;
    case 8:
        rtn = NDATABITS_8;
        break;
    default:
        break;
    }

    return rtn;
}

S2426_STOPBITS SerialConfiguration::getSensorayStopBits() const
{
    S2426_STOPBITS rtn = STOPBITS_0;

    switch (_stopBits) {
    case 0:
        rtn = STOPBITS_0;
        break;
    case 1:
        rtn = STOPBITS_1;
        break;
    default:
        break;
    }

    return rtn;
}

S2426_PARITY SerialConfiguration::getSensorayParity() const
{
    S2426_PARITY rtn = PARITY_TYPE_NONE;

    switch (_parity) {
    case SerialParity::EvenParity:
        rtn = PARITY_TYPE_EVEN;
        break;
    case SerialParity::OddParity:
        rtn = PARITY_TYPE_ODD;
        break;
    case SerialParity::NoParity:
        rtn = PARITY_TYPE_NONE;
        break;
    default:
        break;
    }

    return rtn;
}


} //end of namespace comms
} //end of namespace munk
