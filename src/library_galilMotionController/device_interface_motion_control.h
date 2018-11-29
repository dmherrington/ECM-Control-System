#ifndef DEVICE_INTERFACE_MOTION_CONTOL_H
#define DEVICE_INTERFACE_MOTION_CONTOL_H

#include <functional>
#include <memory>
#include <unordered_map>
#include <mutex>

#include "ecm_devices.h"

class DeviceInterface_MotionControl
{
public:
    enum class FINISH_CODE
    {
        UNKNOWN
    };

public:
    //!
    //! \brief Remove all action tied to the given host
    //! \param ptr Pointer to host that actions attributed to are to be removed
    //!
    virtual void RemoveHost(void* ptr)
    {
        m_MutexFinishScriptLambda.lock();
        m_FinishScriptLambda.erase(ptr);
        m_FinishVariablesLambda.erase(ptr);
        m_MutexFinishScriptLambda.unlock();
    }

    void setLambda_FinishedUploadingScript(const std::function<void(const bool completed, const FINISH_CODE finishCode)> &lambda){
        m_MutexFinishScriptLambda.lock();

        if(m_FinishScriptLambda.find(0) != m_FinishScriptLambda.cend())
        {
            printf("Warning!!!! A finish procedure already exists, replacing old with new\n");
            m_FinishScriptLambda.erase(0);
        }

        m_FinishScriptLambda.insert({0, lambda});
        m_MutexFinishScriptLambda.unlock();
    }


    void setLambda_FinishedUploadingVariables(const std::function<void(const bool completed, const FINISH_CODE finishCode)> &lambda){
        m_MutexFinishVariablesLambda.lock();

        if(m_FinishVariablesLambda.find(0) != m_FinishVariablesLambda.cend())
        {
            printf("Warning!!!! A finish procedure already exists, replacing old with new\n");
            m_FinishVariablesLambda.erase(0);
        }

        m_FinishVariablesLambda.insert({0, lambda});
        m_MutexFinishVariablesLambda.unlock();
    }


    void AddLambda_FinishedUploadingScript(void* host, const std::function<void(const bool completed, const FINISH_CODE finishCode)> &lambda){
        m_MutexFinishScriptLambda.lock();
        m_FinishScriptLambda.insert({host, lambda});
        m_MutexFinishScriptLambda.unlock();
    }

    void AddLambda_FinishedUploadingVariables(void* host, const std::function<void(const bool completed, const FINISH_CODE finishCode)> &lambda){
        m_MutexFinishVariablesLambda.lock();
        m_FinishVariablesLambda.insert({host, lambda});
        m_MutexFinishVariablesLambda.unlock();
    }


protected:
    void onFinishedUploadingScript(const bool completed, const FINISH_CODE finishCode = FINISH_CODE::UNKNOWN){

        m_MutexFinishScriptLambda.lock();
        for(auto it = m_FinishScriptLambda.cbegin() ; it != m_FinishScriptLambda.cend() ; ++it)
        {
            it->second(completed, finishCode);
        }
        m_MutexFinishScriptLambda.unlock();
    }

    void onFinishedUploadingVariables(const bool completed, const FINISH_CODE finishCode = FINISH_CODE::UNKNOWN){

        m_MutexFinishVariablesLambda.lock();
        for(auto it = m_FinishVariablesLambda.cbegin() ; it != m_FinishVariablesLambda.cend() ; ++it)
        {
            it->second(completed, finishCode);
        }
        m_MutexFinishVariablesLambda.unlock();
    }

signals:
    void signal_DeviceConfigured(const ECMDevice &device);

protected:
    std::unordered_map<void*, std::function<void(const bool completed, const FINISH_CODE finishCode)>> m_FinishScriptLambda;
    std::unordered_map<void*, std::function<void(const bool completed, const FINISH_CODE finishCode)>> m_FinishVariablesLambda;
    std::unordered_map<void*, std::function<void()>> m_ShutdownLambda;

    std::mutex m_MutexFinishScriptLambda;
    std::mutex m_MutexFinishVariablesLambda;
};

#endif // DEVICE_INTERFACE_MOTION_CONTOL_H
