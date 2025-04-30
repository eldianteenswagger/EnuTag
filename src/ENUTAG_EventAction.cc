#include"ENUTAG_EventAction.hh"

ENUTAG_EventAction::ENUTAG_EventAction(ENUTAG_RunAction* runAction){/*nEvent = 0;*/}
ENUTAG_EventAction::~ENUTAG_EventAction(){}

void ENUTAG_EventAction::BeginOfEventAction(const G4Event* evt){

    nEvent = evt->GetEventID();

}

void ENUTAG_EventAction::EndOfEventAction(const G4Event* evt){

    G4cout << "Event # " << evt->GetEventID() << " done;" << G4endl;

}