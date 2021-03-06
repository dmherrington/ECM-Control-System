#ifndef ABSTRACT_DEVICE_INTERFACE_H
#define ABSTRACT_DEVICE_INTERFACE_H

#include <functional>
#include <memory>
#include <unordered_map>
#include <mutex>

#include "ecm_devices.h"

class Abstract_DeviceInterface
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


protected:
    void onFinishedUploadingParameters(const bool completed, const FINISH_CODE finishCode = FINISH_CODE::UNKNOWN){

        m_MutexFinishLambda.lock();
        for(auto it = m_FinishLambda.cbegin() ; it != m_FinishLambda.cend() ; ++it)
        {
            it->second(completed, finishCode);
        }
        m_MutexFinishLambda.unlock();
    }

signals:
    void signal_DeviceConfigured(const ECMDevice &device);

protected:
    std::unordered_map<void*, std::function<void(const bool completed, const FINISH_CODE finishCode)>> m_FinishLambda;
    std::unordered_map<void*, std::function<void()>> m_ShutdownLambda;

    std::mutex m_MutexFinishLambda;
};

#endif // ABSTRACT_DEVICEINTERFACE_H
