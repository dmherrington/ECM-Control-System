#include "comms_galil.h"

CommsGalil::CommsGalil() :
    m_LinkMarshaler(new Comms::CommsMarshaler), m_LinkName("")
{
    m_LinkMarshaler->AddSubscriber(this);
    m_LinkMarshaler->SendGalilMessage<double>(3.5);
}

CommsGalil::~CommsGalil()
{

}

void CommsGalil::StatusMessage(const std::string &message)
{
    UNUSED(message);
    std::cout<<"I am in the comms_mavlink library MavlinkMessage callback."<<std::endl;
}

//!
//! \brief Provides object contains parameters values to configure module with
//! \param params Parameters to configure
//!
void CommsGalil::ConfigureComms(const std::string &params)
{
//    m_LinkMarshaler->AddProtocol(*mavlinkConfig);
//    m_LinkName = "link_" + portName;
//    m_LinkMarshaler->AddLink(m_LinkName, config);
//    m_LinkMarshaler->ConnectToLink(m_LinkName);
}
