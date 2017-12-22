#ifndef COMMS_GALIL_H
#define COMMS_GALIL_H

#include <iostream>
#include <map>

#include "comms_galil_setup/comms_events.h"
#include "comms_galil_setup/comms_marshaler.h"

#include "comms_galil_global.h"

class COMMS_GALILSHARED_EXPORT CommsGalil : public Comms::CommsEvents
{

public:
    CommsGalil();

    virtual ~CommsGalil();

    virtual void ConfigureComms(const std::string &params);

    void StatusMessage(const std::string &linkName, const std::string &message) override;

protected:
    Comms::CommsMarshaler *m_LinkMarshaler;
    std::string m_LinkName;
};


#endif // COMMS_GALIL_H
