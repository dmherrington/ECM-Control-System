#ifndef DEVICE_INTERFACE_PUMP_H
#define DEVICE_INTERFACE_PUMP_H

#include <functional>
#include <memory>
#include <unordered_map>
#include <mutex>

#include "ecm_devices.h"

class DeviceInterface_Pump
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
        m_MutexFinishLambda.lock();
        m_FinishLambda.erase(ptr);
        m_MutexFinishLambda.unlock();

        m_MutexPumpInitializedLambda.lock();
        m_PumpInitializedLambda.erase(ptr);
        m_MutexPumpInitializedLambda.unlock();
    }

    void setLambda_FinishedUploadingParameters(const std::function<void(const bool completed, const FINISH_CODE finishCode)> &lambda){
        m_MutexFinishLambda.lock();

        if(m_FinishLambda.find(0) != m_FinishLambda.cend())
        {
            printf("Warning!!!! A finish procedure already exists, replacing old with new\n");
            m_FinishLambda.erase(0);
        }

        m_FinishLambda.insert({0, lambda});
        m_MutexFinishLambda.unlock();
    }

    void setLambda_FinishedPumpInitialization(const std::function<void(const bool completed)> &lambda){
        m_MutexPumpInitializedLambda.lock();

        if(m_PumpInitializedLambda.find(0) != m_PumpInitializedLambda.cend())
        {
            printf("Warning!!!! A finish procedure already exists, replacing old with new\n");
            m_PumpInitializedLambda.erase(0);
        }

        m_PumpInitializedLambda.insert({0, lambda});
        m_MutexPumpInitializedLambda.unlock();
    }

    //!
    //! \brief Add a behavior to do when the device is finished
    //!
    //! This behavior is tied to a "host", which can be removed
    //!
    //! \param host Pointer to host of behavior
    //! \param lambda Action to perform
    //!
    void AddLambda_FinishedUploadingParameters(void* host, const std::function<void(const bool completed, const FINISH_CODE finishCode)> &lambda){
        m_MutexFinishLambda.lock();
        m_FinishLambda.insert({host, lambda});
        m_MutexFinishLambda.unlock();
    }

    void AddLambda_FinishedPumpInitialization(void* host, const std::function<void(const bool completed)> &lambda){
        m_MutexPumpInitializedLambda.lock();
        m_PumpInitializedLambda.insert({host, lambda});
        m_MutexPumpInitializedLambda.unlock();
    }


protected:
    void onFinishedUploadingParameters(const bool completed, const FINISH_CODE finishCode = FINISH_CODE::UNKNOWN){

        m_MutexFinishLambda.lock();
        for(auto it = m_FinishLambda.cbegin() ; it != m_FinishLambda.cend() ; ++it)
        {
            it->second(completed, finishCode);
        }
        m_MutexFinishLambda.unlock();
    }

    void onFinishedInitializingPump(const bool completed){

        m_MutexPumpInitializedLambda.lock();
        for(auto it = m_PumpInitializedLambda.cbegin() ; it != m_PumpInitializedLambda.cend() ; ++it)
        {
            it->second(completed);
        }
        m_MutexPumpInitializedLambda.unlock();
    }
signals:
    void signal_DeviceConfigured(const ECMDevice &device);

protected:
    std::unordered_map<void*, std::function<void(const bool completed, const FINISH_CODE finishCode)>> m_FinishLambda;
    std::unordered_map<void*, std::function<void(const bool completed)>> m_PumpInitializedLambda;

    std::mutex m_MutexFinishLambda;
    std::mutex m_MutexPumpInitializedLambda;
};

#endif // DEVICE_INTERFACE_PUMP_H
