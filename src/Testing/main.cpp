#include <QCoreApplication>
#include <iostream>
#include "hsm.h"

using namespace hsm;

class AbstractCommand{
public:
    AbstractCommand()
    {
        mTest = 1.0;
    }

    double getValue()
    {
        return mTest;
    }

protected:
    double mTest;
};

class RealCommand : public AbstractCommand{
public:
    RealCommand():
        AbstractCommand()
    {
       mTest = 2.0;
    }

};

class State2 : public State {
public:
    State2()
    {
    }
    virtual Transition GetTransition()
    {
        return NoTransition();
    }
    void OnEnter(const double value) {
        mTest = value + 1;
        std::cout<<"The value here is "<<mTest<<std::endl;
    }

    void OnEnter(AbstractCommand* cmd)
    {
        std::cout<<"I am in the right one"<<std::endl;
        std::cout<<cmd->getValue()<<std::endl;
    }
private:
    double mTest;
};

class State1 : public State {
public:
    State1()
    {
        mTest = 0.0;
    }
    void updateValue(const double &test)
    {
        std::cout<<"We are here 3.1"<<std::endl;
        mTest = test + 1;
        std::cout<<"We are here 3.2"<<std::endl;
        std::cout<<"The value of test"<<mTest<<std::endl;
    }
    virtual Transition GetTransition()
    {
        if(mTest <= 1)
            return NoTransition();
        else
        {
            RealCommand* newCMD = new RealCommand();
            return SiblingTransition<State2>(newCMD);
        }
    }
private:
    double mTest;
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

       StateMachine stateMachine;
       stateMachine.Initialize<State1>();
       std::cout<<"We are here 1"<<std::endl;
       stateMachine.SetDebugInfo("TestHsm", TraceLevel::Basic);
       std::cout<<"We are here 2"<<std::endl;
       stateMachine.ProcessStateTransitions();
       stateMachine.UpdateStates();

       if(stateMachine.IsStarted())
       {
           std::cout<<"The state machine is moving"<<std::endl;
       }

       State1* currentState = static_cast<State1*>(stateMachine.getCurrentState());
       std::cout<<"We are here 3"<<std::endl;
       currentState->updateValue(3);
       std::cout<<"We are here 4"<<std::endl;

       stateMachine.ProcessStateTransitions();
       stateMachine.UpdateStates();

    return a.exec();
}
