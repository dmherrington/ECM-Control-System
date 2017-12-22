#include "comms_galil.h"

CommsGalil::CommsGalil() :
    m_LinkMarshaler(new Comms::CommsMarshaler), m_LinkName("")
{
    m_LinkMarshaler->AddSubscriber(this);
}

CommsGalil::~CommsGalil()
{

}

void CommsGalil::StatusMessage(const std::string &linkName, const std::string &message)
{
    UNUSED(linkName);
    UNUSED(message);
    std::cout<<"I am in the comms_mavlink library MavlinkMessage callback."<<std::endl;
}

//!
//! \brief Provides object contains parameters values to configure module with
//! \param params Parameters to configure
//!
void CommsGalil::ConfigureComms(const std::string &params)
{
    m_LinkMarshaler->AddProtocol(*mavlinkConfig);
    m_LinkName = "link_" + portName;
    m_LinkMarshaler->AddLink(m_LinkName, config);
    m_LinkMarshaler->ConnectToLink(m_LinkName);
}
