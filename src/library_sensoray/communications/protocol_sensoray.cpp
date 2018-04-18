#include "protocol_sensoray.h"

namespace comms_Sensoray{

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

bool SensorayProtocol::openSerialPort(const common::comms::SerialConfiguration &config)
{
    S24XXERR errorCode = S24XXERR::ERR_NONE;
    s2426_ComportOpen(m_Session->handle, &errorCode,19200,PARITY_TYPE_NONE,NDATABITS_8,STOPBITS_1);
    //s2426_ComportOpen(m_Session->handle,&errorCode,config.baud(),getSensorayParity(config.parity()),getSensorayDataBits(config.dataBits()),getSensorayStopBits(config.stopBits()));
    if(errorCode == S24XXERR::ERR_NONE)
    {
        m_Session->setSerialPortConnected(true);
        common::comms::CommunicationConnection commsStatus;
        commsStatus.setSourceName("Sensoray");
        commsStatus.setConnection(true);
        Emit([&](const IProtocolSensorayEvents* ptr){ptr->SerialPortConnectionUpdate(commsStatus);});
        return true;
    }

    common::comms::CommunicationUpdate commsError("Senosoray",common::comms::CommunicationUpdate::UpdateTypes::ERROR,
                                                  std::string(s24xx_ErrorText(errorCode)));
    Emit([&](const IProtocolSensorayEvents* ptr){ptr->SerialPortStatusUpdate(commsError);});
    return false;
}

bool SensorayProtocol::closeSerialPort ()
{
    S24XXERR errorCode = S24XXERR::ERR_NONE;
    s2426_ComportClose(m_Session->handle,&errorCode);
    if(errorCode == S24XXERR::ERR_NONE)
    {
        m_Session->setSerialPortConnected(false);
        common::comms::CommunicationConnection commsStatus;
        commsStatus.setSourceName("Sensoray");
        commsStatus.setConnection(false);
        Emit([&](const IProtocolSensorayEvents* ptr){ptr->SerialPortConnectionUpdate(commsStatus);});
        return true;
    }

    common::comms::CommunicationUpdate commsError("Senosoray",common::comms::CommunicationUpdate::UpdateTypes::ERROR,
                                                  std::string(s24xx_ErrorText(errorCode)));
    Emit([&](const IProtocolSensorayEvents* ptr){ptr->SerialPortStatusUpdate(commsError);});

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
        std::cout<<"The size of the data being written to the port is: "<<dataCopy.length()<<std::endl;
        //first write the information to the serial port and wait until completed
        s2426_ComportWrite(m_Session->handle,&errorCode, dataCopy.data(), dataCopy.length(),true);
        if(errorCode != S24XXERR::ERR_NONE)
        {
            //if there was already an error writing there is no point to continue to read
            return;
        }

        //according to the westinghouse manual the pump needs approximatley 10ms to respond
        //therefore waiting >10ms should be sufficient for the entire message to be ready
        std::this_thread::sleep_for(std::chrono::milliseconds(12));
        //second read whatever information is available from the port
        char buf[256];
        int nchars = s2426_ComportRead(m_Session->handle, &errorCode, buf, sizeof(buf)-1, false);
        std::cout<<"The number of characters received is: "<<nchars<<std::endl;
        if(errorCode != S24XXERR::ERR_NONE)
        {

        }
//        response = QByteArray(reinterpret_cast<char*>(buf), nchars);
//        Emit([&](const IProtocolSensorayEvents* ptr){ptr->ResponseReceived(response);});
    }
}

} //end of namespace comms

