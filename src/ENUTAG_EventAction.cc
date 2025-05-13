#include"ENUTAG_EventAction.hh"

ENUTAG_EventAction::ENUTAG_EventAction(ENUTAG_RunAction* runAction){
    lastEvent=0;
}
ENUTAG_EventAction::~ENUTAG_EventAction(){}

void ENUTAG_EventAction::BeginOfEventAction(const G4Event* evt){

    nEvent = evt->GetEventID();

}

void ENUTAG_EventAction::EndOfEventAction(const G4Event* evt){

    if(lastEvent<nEvent){
        G4cout << "Event # " << nEvent << " done;" << G4endl;
        lastEvent = nEvent;
    }
    

}