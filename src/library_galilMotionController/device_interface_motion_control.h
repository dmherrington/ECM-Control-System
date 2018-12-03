#ifndef DEVICE_INTERFACE_MOTION_CONTOL_H
#define DEVICE_INTERFACE_MOTION_CONTOL_H

#include <functional>
#include <memory>
#include <unordered_map>
#include <mutex>

#include "data/motion_profile_state.h"

#include "ecm_devices.h"

#include "programs/galil_current_program.h"

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
        m_MutexFinishScriptLambda.unlock();

        m_MutexFinishVariablesLambda.lock();
        m_FinishVariablesLambda.erase(ptr);
        m_MutexFinishVariablesLambda.unlock();

        m_MutexNewMotionProfileStateLambda.lock();
        m_NewMotionProfileStateLambda.erase(ptr);
        m_MutexNewMotionProfileStateLambda.unlock();
    }

    void setLambda_FinishedUploadingScript(const std::function<void(const bool &success, const GalilCurrentProgram &program)> &lambda){
        m_MutexFinishScriptLambda.lock();

        if(m_FinishScriptLambda.find(0) != m_FinishScriptLambda.cend())
        {
            printf("Warning!!!! A finish procedure already exists, replacing old with new\n");
            m_FinishScriptLambda.erase(0);
        }

        m_FinishScriptLambda.insert({0, lambda});
        m_MutexFinishScriptLambda.unlock();
    }


    void setLambda_FinishedUploadingVariables(const std::function<void(const bool success, const ProgramVariableList &variableList)> &lambda){
        m_MutexFinishVariablesLambda.lock();

        if(m_FinishVariablesLambda.find(0) != m_FinishVariablesLambda.cend())
        {
            printf("Warning!!!! A finish procedure already exists, replacing old with new\n");
            m_FinishVariablesLambda.erase(0);
        }

        m_FinishVariablesLambda.insert({0, lambda});
        m_MutexFinishVariablesLambda.unlock();
    }


    void setLambda_NewMotionProfileState(const std::function<void(const MotionProfileState &profileState)> &lambda){
        m_MutexNewMotionProfileStateLambda.lock();

        if(m_NewMotionProfileStateLambda.find(0) != m_NewMotionProfileStateLambda.cend())
        {
            printf("Warning!!!! A finish procedure already exists, replacing old with new\n");
            m_NewMotionProfileStateLambda.erase(0);
        }

        m_NewMotionProfileStateLambda.insert({0, lambda});
        m_MutexNewMotionProfileStateLambda.unlock();
    }

    void AddLambda_FinishedUploadingScript(void* host, const std::function<void(const bool &success, const GalilCurrentProgram &program)> &lambda){
        m_MutexFinishScriptLambda.lock();
        m_FinishScriptLambda.insert({host, lambda});
        m_MutexFinishScriptLambda.unlock();
    }

    void AddLambda_FinishedUploadingVariables(void* host, const std::function<void(const bool success, const ProgramVariableList &variableList)> &lambda){
        m_MutexFinishVariablesLambda.lock();
        m_FinishVariablesLambda.insert({host, lambda});
        m_MutexFinishVariablesLambda.unlock();
    }

    void AddLambda_NewMotionProfileState(void* host, const std::function<void(const MotionProfileState &profileState)> &lambda){
        m_MutexNewMotionProfileStateLambda.lock();
        m_NewMotionProfileStateLambda.insert({host, lambda});
        m_MutexNewMotionProfileStateLambda.unlock();
    }

protected:
    void onFinishedUploadingScript(const bool &success, const GalilCurrentProgram &program){

        m_MutexFinishScriptLambda.lock();
        for(auto it = m_FinishScriptLambda.cbegin() ; it != m_FinishScriptLambda.cend() ; ++it)
        {
            it->second(success, program);
        }
        m_MutexFinishScriptLambda.unlock();
    }

    void onFinishedUploadingVariables(const bool success, const ProgramVariableList &variableList){

        m_MutexFinishVariablesLambda.lock();
        for(auto it = m_FinishVariablesLambda.cbegin() ; it != m_FinishVariablesLambda.cend() ; ++it)
        {
            it->second(success, variableList);
        }
        m_MutexFinishVariablesLambda.unlock();
    }

    void onNewMotionProfileState(const MotionProfileState &profileState){

        m_MutexNewMotionProfileStateLambda.lock();
        for(auto it = m_NewMotionProfileStateLambda.cbegin() ; it != m_NewMotionProfileStateLambda.cend() ; ++it)
        {
            it->second(profileState);
        }
        m_MutexNewMotionProfileStateLambda.unlock();
    }

signals:
    void signal_DeviceConfigured(const ECMDevice &device);

protected:
    std::unordered_map<void*, std::function<void(const bool &success, const GalilCurrentProgram &program)>> m_FinishScriptLambda;
    std::unordered_map<void*, std::function<void(const bool success, const ProgramVariableList &variableList)>> m_FinishVariablesLambda;
    std::unordered_map<void*, std::function<void(const MotionProfileState &profileState)>> m_NewMotionProfileStateLambda;

    std::mutex m_MutexFinishScriptLambda;
    std::mutex m_MutexFinishVariablesLambda;
    std::mutex m_MutexNewMotionProfileStateLambda;

};

#endif // DEVICE_INTERFACE_MOTION_CONTOL_H
