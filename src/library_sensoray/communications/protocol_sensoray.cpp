#include "protocol_sensoray.h"

namespace sensoray {
namespace comms{

SensorayProtocol::SensorayProtocol()
{

}

void SensorayProtocol::AddListner(const IProtocolSensorayEvents *listener)
{
    m_Listners.push_back(listener);
}

void SensorayProtocol::updateCurrentSession(SensoraySession *session)
{
    this->m_Session = session;
}

void SensorayProtocol::resetSensorayIO()
{
    S24XXERR errorCode = S24XXERR::ERR_NONE;
    u8	dioChan;

    // Set encoder mode.
    s2426_WriteEncoderMode( m_Session->handle, &errorCode, QUADRATURE_X4, ENC_PRELOAD_DISABLE );

    // Activate pwm mode for dout channels 12-15, using arbitrary timing values.
    for ( dioChan = 12; dioChan < 16; dioChan++ )
    {
        s2426_SetDoutMode( m_Session->handle, &errorCode, dioChan, DOUT2426_MODE_PWM );
        s2426_WritePwm( m_Session->handle, &errorCode, dioChan, (u16)( ( 23 * ( dioChan + 1 ) ) & 255 ), (u16)( ( 39 * ( dioChan + 1 ) ) & 511 ) );
    }
}

bool SensorayProtocol::openSerialPort(const SerialConfiguration &config)
{
    S24XXERR errorCode = S24XXERR::ERR_NONE;
    s2426_ComportOpen(m_Session->handle,&errorCode,config.baud(),config.getSensorayParity(),config.getSensorayDataBits(),config.getSensorayStopBits());
    if(errorCode == S24XXERR::ERR_NONE)
        return true;
}

bool SensorayProtocol::closeSerialPort ()
{
    S24XXERR errorCode = S24XXERR::ERR_NONE;
    s2426_ComportClose(m_Session->handle,&errorCode);
    if(errorCode == S24XXERR::ERR_NONE)
        return true;
    return false;
}

void SensorayProtocol::transmitDataToSerialPort(const QByteArray &msg)
{
    if(m_Session->isSerialPortConnected())
    {
        QByteArray response;
        //Since this serial port is only being used for the pump, we know we can
        //take advantage of that knowledge and read write after writing. This
        //will alleviate the headache of trying to coordiate TX/RX across libraries
        QByteArray dataCopy = msg;
        S24XXERR errorCode = S24XXERR::ERR_NONE;
        //first write the information to the serial port and wait until completed
        s2426_ComportWrite(m_Session->handle,&errorCode, dataCopy.data(), dataCopy.length(),true);
        if(errorCode != S24XXERR::ERR_NONE)
        {

        }
        //second read whatever information is available from the port
        char buf[256];
        int nchars = s2426_ComportRead(m_Session->handle, &errorCode, buf, sizeof(buf)-1, false);
        if(errorCode != S24XXERR::ERR_NONE)
        {

        }
        response = QByteArray(reinterpret_cast<char*>(buf), nchars);
        Emit([&](const IProtocolSensorayEvents* ptr){ptr->ResponseReceived(response);});
    }
}

} //end of namespace comms
} //end of namespace sensoray
