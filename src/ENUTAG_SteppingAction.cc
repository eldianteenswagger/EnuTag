#include "ENUTAG_SteppingAction.hh"

ENUTAG_SteppingAction::ENUTAG_SteppingAction(ENUTAG_EventAction* evtAct){
    fEvtAction = evtAct;
    Emin = 50. * MeV;
}

ENUTAG_SteppingAction::~ENUTAG_SteppingAction(){}

void ENUTAG_SteppingAction::UserSteppingAction(const G4Step* step){

    G4Track* track = (G4Track*)(step->GetTrack());
    G4double Ekin = track->GetKineticEnergy();
    if (Ekin < Emin) track->SetTrackStatus(fStopAndKill);
    //G4cout << "Killed particle with energy of " << Ekin/MeV << " MeV" << G4endl;

    return;
}