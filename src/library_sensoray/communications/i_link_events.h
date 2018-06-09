#ifndef I_LINK_EVENTS_SENSORAY_H
#define I_LINK_EVENTS_SENSORAY_H

#include <cstdlib>
#include <vector>
#include <string>

#include "common/comms/communication_update.h"
/**
\* @file  i_link_events.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is interact with the sensoray.
\*
\* @section DESCRIPTION
\*
\*
\*/

namespace comms_Sensoray{

class ILink;

class ILinkEvents
{
public:

    virtual void CommunicationUpdate(const common::comms::CommunicationUpdate &update) const = 0;

};

} //end of namespace comms

#endif // I_LINK_EVENTS_SENSORAY_H
