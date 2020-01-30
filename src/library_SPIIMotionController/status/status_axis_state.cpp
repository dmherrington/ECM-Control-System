#include "status_axis_state.h"

Status_AxisState::Status_AxisState(const MotorAxis &axis)
{
    currentAxis = axis;
}

Status_AxisState::Status_AxisState(const Status_AxisState &copy)
{
    this->currentAxis = copy.getCurrentAxis();

    m_AxisPosition.set(copy.m_AxisPosition.get());
    m_AxisStatus.set(copy.m_AxisStatus.get());
    m_MotorStatus.set(copy.m_MotorStatus.get());
    m_MotorFault.set(copy.m_MotorFault.get());
    m_AxisSafety.set(copy.m_AxisSafety.get());

}
