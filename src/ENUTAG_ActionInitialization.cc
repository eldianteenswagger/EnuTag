#include "ENUTAG_ActionInitialization.hh"

ENUTAG_ActionInitialization::ENUTAG_ActionInitialization(){}

ENUTAG_ActionInitialization::~ENUTAG_ActionInitialization(){}

void ENUTAG_ActionInitialization::BuildForMaster() const {
    ENUTAG_RunAction *action = new ENUTAG_RunAction();
    SetUserAction(action);
}

void ENUTAG_ActionInitialization::Build() const {
    ENUTAG_PrimaryGenerator *generator = new ENUTAG_PrimaryGenerator();
    SetUserAction(generator);
    ENUTAG_RunAction *run_action = new ENUTAG_RunAction();
    SetUserAction(run_action);
    ENUTAG_EventAction *evt_action = new ENUTAG_EventAction(run_action);
    SetUserAction(evt_action);
}