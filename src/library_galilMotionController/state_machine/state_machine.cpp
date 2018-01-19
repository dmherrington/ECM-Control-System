#include "state_machine.h"


//----------------------------------------------------------------------------
// StateMachine
//----------------------------------------------------------------------------
StateMachine::StateMachine(BYTE maxStates, BYTE initialState) :
    MAX_STATES(maxStates),
    m_currentState(initialState),
    m_newState(false),
    m_eventGenerated(false),
    m_pEventData(nullptr)
{
    ASSERT_TRUE(MAX_STATES < EVENT_IGNORED);
}

//----------------------------------------------------------------------------
// ExternalEvent
//----------------------------------------------------------------------------
void StateMachine::ExternalEvent(BYTE newState, const EventData* pData)
{
    // If we are supposed to ignore this event
    if (newState == EVENT_IGNORED)
    {
#ifndef EXTERNAL_EVENT_NO_HEAP_DATA
        // Just delete the event data, if any
        if (pData != nullptr)
            delete pData;
#endif
    }
    else
    {
        // TODO - capture software lock here for thread-safety if necessary

#ifdef EXTERNAL_EVENT_NO_HEAP_DATA
        EventData data;
        if (pData == nullptr)
            pData = &data;
#endif
        // Generate the event
        InternalEvent(newState, pData);

        // Execute the state engine. This function call will only return
        // when all state machine events are processed.
        StateEngine();

        // TODO - release software lock here
    }
}

//----------------------------------------------------------------------------
// InternalEvent
//----------------------------------------------------------------------------
void StateMachine::InternalEvent(BYTE newState, const EventData* pData)
{
    if (pData == nullptr)
        pData = new NoEventData();

    m_pEventData = pData;
    m_eventGenerated = true;
    m_newState = newState;
}

//----------------------------------------------------------------------------
// StateEngine
//----------------------------------------------------------------------------
void StateMachine::StateEngine(void)
{
    const StateMapRow* pStateMap = GetStateMap();
    if (pStateMap != nullptr)
        StateEngine(pStateMap);
    else
    {
        const StateMapRowEx* pStateMapEx = GetStateMapEx();
        if (pStateMapEx != nullptr)
            StateEngine(pStateMapEx);
        else
            ASSERT();
    }
}

//----------------------------------------------------------------------------
// StateEngine
//----------------------------------------------------------------------------
void StateMachine::StateEngine(const StateMapRow* const pStateMap)
{
#if EXTERNAL_EVENT_NO_HEAP_DATA
    bool externalEvent = TRUE;
#endif
    const EventData* pDataTemp = nullptr;

    // While events are being generated keep executing states
    while (m_eventGenerated)
    {
        // Error check that the new state is valid before proceeding
        ASSERT_TRUE(m_newState < MAX_STATES);

        // Get the pointer from the state map
        const StateBase* state = pStateMap[m_newState].State;

        // Copy of event data pointer
        pDataTemp = m_pEventData;

        // Event data used up, reset the pointer
        m_pEventData = nullptr;

        // Event used up, reset the flag
        m_eventGenerated = false;

        // Switch to the new current state
        SetCurrentState(m_newState);

        // Execute the state action passing in event data
        ASSERT_TRUE(state != nullptr);
        state->InvokeStateAction(this, pDataTemp);

        // If event data was used, then delete it
#if EXTERNAL_EVENT_NO_HEAP_DATA
        if (pDataTemp)
        {
            if (!externalEvent)
                delete pDataTemp;
            pDataTemp = nullptr;
        }
        externalEvent = FALSE;
#else
        if (pDataTemp)
        {
            delete pDataTemp;
            pDataTemp = nullptr;
        }
#endif
    }
}

//----------------------------------------------------------------------------
// StateEngine
//----------------------------------------------------------------------------
void StateMachine::StateEngine(const StateMapRowEx* const pStateMapEx)
{
#if EXTERNAL_EVENT_NO_HEAP_DATA
    bool externalEvent = TRUE;
#endif
    const EventData* pDataTemp = nullptr;

    // While events are being generated keep executing states
    while (m_eventGenerated)
    {
        // Error check that the new state is valid before proceeding
        ASSERT_TRUE(m_newState < MAX_STATES);

        // Get the pointers from the state map
        const StateBase* state = pStateMapEx[m_newState].State;
        const GuardBase* guard = pStateMapEx[m_newState].Guard;
        const EntryBase* entry = pStateMapEx[m_newState].Entry;
        const ExitBase* exit = pStateMapEx[m_currentState].Exit;

        // Copy of event data pointer
        pDataTemp = m_pEventData;

        // Event data used up, reset the pointer
        m_pEventData = nullptr;

        // Event used up, reset the flag
        m_eventGenerated = false;

        // Execute the guard condition
        bool guardResult = true;
        if (guard != nullptr)
            guardResult = guard->InvokeGuardCondition(this, pDataTemp);

        // If the guard condition succeeds
        if (guardResult == true)
        {
            // Transitioning to a new state?
            if (m_newState != m_currentState)
            {
                // Execute the state exit action on current state before switching to new state
                if (exit != nullptr)
                    exit->InvokeExitAction(this);

                // Execute the state entry action on the new state
                if (entry != nullptr)
                    entry->InvokeEntryAction(this, pDataTemp);

                // Ensure exit/entry actions didn't call InternalEvent by accident
                ASSERT_TRUE(m_eventGenerated == false);
            }

            // Switch to the new current state
            SetCurrentState(m_newState);

            // Execute the state action passing in event data
            ASSERT_TRUE(state != nullptr);
            state->InvokeStateAction(this, pDataTemp);
        }

        // If event data was used, then delete it
#if EXTERNAL_EVENT_NO_HEAP_DATA
        if (pDataTemp)
        {
            if (!externalEvent)
                delete pDataTemp;
            pDataTemp = nullptr;
        }
        externalEvent = FALSE;
#else
        if (pDataTemp)
        {
            delete pDataTemp;
            pDataTemp = nullptr;
        }
#endif
    }
}
