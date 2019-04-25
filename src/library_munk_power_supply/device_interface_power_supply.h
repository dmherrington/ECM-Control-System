#ifndef DEVICE_INTERFACE_POWER_SUPPLY_H
#define DEVICE_INTERFACE_POWER_SUPPLY_H

#include <functional>
#include <memory>
#include <unordered_map>
#include <mutex>

#include "ecm_devices.h"

class DeviceInterface_PowerSupply
{
public:
    enum class FINISH_CODE
    {
        UNKNOWN
    };

public:
    virtual void RemoveHost(void* ptr)
    {
        m_MutexFinishSegmentsLambda.lock();
        m_FinishedUploadingSegments.erase(ptr);
        m_MutexFinishSegmentsLambda.unlock();

        m_MutexFinishPulseModeLambda.lock();
        m_FinishedUploadingPulseMode.erase(ptr);
        m_MutexFinishPulseModeLambda.unlock();

        m_MutexAbortExecutionLambda.lock();
        m_AbortExecutionLambda.erase(ptr);
        m_MutexAbortExecutionLambda.unlock();
    }

    void setLambda_AbortExection(const std::function<void()> &lambda){
        if(m_AbortExecutionLambda.find(0) != m_AbortExecutionLambda.cend())
        {
            printf("Warning!!!! An abort execution already exists, replacing old with new\n");
            m_AbortExecutionLambda.erase(0);
        }

        m_AbortExecutionLambda.insert({0, lambda});
    }

    void setLambda_FinishedUploadingSegments(const std::function<void(const bool completed, const FINISH_CODE &finishCode)> &lambda){
        m_MutexFinishSegmentsLambda.lock();

        if(m_FinishedUploadingSegments.find(0) != m_FinishedUploadingSegments.cend())
        {
            printf("Warning!!!! A finish procedure already exists, replacing old with new\n");
            m_FinishedUploadingSegments.erase(0);
        }

        m_FinishedUploadingSegments.insert({0, lambda});
        m_MutexFinishSegmentsLambda.unlock();
    }

    void setLambda_FinishedUploadingPulseMode(const std::function<void(const bool completed, const FINISH_CODE &finishCode)> &lambda){
        m_MutexFinishPulseModeLambda.lock();

        if(m_FinishedUploadingPulseMode.find(0) != m_FinishedUploadingPulseMode.cend())
        {
            printf("Warning!!!! A finish procedure already exists, replacing old with new\n");
            m_FinishedUploadingPulseMode.erase(0);
        }

        m_FinishedUploadingPulseMode.insert({0, lambda});
        m_MutexFinishPulseModeLambda.unlock();
    }

    void AddLambda_AbortExecution(void* host, const std::function<void()> &lambda){
        m_MutexAbortExecutionLambda.lock();
        m_AbortExecutionLambda.insert({host, lambda});
        m_MutexAbortExecutionLambda.unlock();
    }

    void AddLambda_FinishedUploadingSegments(void* host, const std::function<void(const bool completed, const FINISH_CODE &finishCode)> &lambda){
        m_MutexFinishSegmentsLambda.lock();
        m_FinishedUploadingSegments.insert({host, lambda});
        m_MutexFinishSegmentsLambda.unlock();
    }

    void AddLambda_FinishedUploadingPulseMode(void* host, const std::function<void(const bool completed, const FINISH_CODE &finishCode)> &lambda){
        m_MutexFinishPulseModeLambda.lock();
        m_FinishedUploadingPulseMode.insert({host, lambda});
        m_MutexFinishPulseModeLambda.unlock();
    }

protected:

    void onAbortExecution(){
        m_MutexAbortExecutionLambda.lock();
        for(auto it = m_AbortExecutionLambda.cbegin() ; it != m_AbortExecutionLambda.cend() ; ++it)
        {
            it->second();
        }
        m_MutexAbortExecutionLambda.unlock();
    }

    void onFinishedUploadingSegments(const bool completed, const FINISH_CODE &finishCode = FINISH_CODE::UNKNOWN){

        m_MutexFinishSegmentsLambda.lock();
        for(auto it = m_FinishedUploadingSegments.cbegin() ; it != m_FinishedUploadingSegments.cend() ; ++it)
        {
            it->second(completed, finishCode);
        }
        m_MutexFinishSegmentsLambda.unlock();
    }

    void onFinishedUploadingPulseMode(const bool completed, const FINISH_CODE &finishCode = FINISH_CODE::UNKNOWN){

        m_MutexFinishPulseModeLambda.lock();
        for(auto it = m_FinishedUploadingPulseMode.cbegin() ; it != m_FinishedUploadingPulseMode.cend() ; ++it)
        {
            it->second(completed, finishCode);
        }
        m_MutexFinishPulseModeLambda.unlock();
    }

protected:
    std::unordered_map<void*, std::function<void(const bool completed, const FINISH_CODE finishCode)>> m_FinishedUploadingSegments;
    std::unordered_map<void*, std::function<void(const bool completed, const FINISH_CODE finishCode)>> m_FinishedUploadingPulseMode;
    std::unordered_map<void*, std::function<void()>> m_AbortExecutionLambda;

    std::mutex m_MutexFinishSegmentsLambda;
    std::mutex m_MutexFinishPulseModeLambda;
    std::mutex m_MutexAbortExecutionLambda;
};

#endif // DEVICE_INTERFACE_POWER_SUPPLY_H
