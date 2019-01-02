#include <QCoreApplication>

#include "common/hsm.h"
#include "ECM_API/states/state_abstract_ecm_process.h"
#include "ECM_API/states/state_ecm_components.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ECM_API* newAPI = new ECM_API();
    hsm::StateMachine* stateMachine = new hsm::StateMachine();
    stateMachine->Initialize<ECM::API::ECMState_Idle>(newAPI);

    return a.exec();
}
