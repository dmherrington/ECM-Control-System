#ifndef GALIL_STATE_MACHINE_H
#define GALIL_STATE_MACHINE_H

#include <iostream>
#include <QDate>

#include "common/threadmanager.h"
#include "common/timer.h"


class GalilSM_Interface
{
public:
    //virtual void cbiGuidedController_TransmitMissionItem(const mavlink_mission_item_t &item) = 0;

};

class GalilSM : public Thread
{
public:
    GalilSM(const int &targetSystem, const int &targetComp);

    void updateWaypointTarget(const CommandItem::SpatialWaypoint &target);

    void receivedMissionACK(const mavlink_mission_ack_t &missionACK);

    ~GalilSM() {
        std::cout << "Destructor on the mavlink guided controller" << std::endl;
        mToExit = true;
    }

    void run();

    void connectCallback(GalilSM_Interface *cb)
    {
        m_CB = cb;
    }

private:
    GalilSM_Interface *m_CB;

protected:
    std::list<std::function<void()>> m_LambdasToRun;

    void clearPendingTasks()
    {
        m_LambdasToRun.clear();
    }

    void RunPendingTasks() {
        while(m_LambdasToRun.size() > 0) {
            auto lambda = m_LambdasToRun.front();
            m_LambdasToRun.pop_front();
            lambda();
        }
    }
};

#endif // GALIL_STATE_MACHINE_H
