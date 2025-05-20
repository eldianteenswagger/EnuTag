#ifndef ENUTAG_STEPPINGACTION_HH
#define ENUTAG_STEPPINGACTION_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "ENUTAG_Construction.hh"
#include "ENUTAG_EventAction.hh"

class ENUTAG_SteppingAction : public G4UserSteppingAction {
public:
    ENUTAG_SteppingAction(ENUTAG_EventAction*);
    ~ENUTAG_SteppingAction();

    void UserSteppingAction(const G4Step*);

private:
    ENUTAG_EventAction* fEvtAction;
    G4double Emin;
    G4double fEnergyDeposited;
    G4double fParticleEnergy;
    G4double fX;
    G4double fY;
    G4double fAbsX;
    G4double fAbsY;
    G4double fAbsZ;
    G4double fPX;
    G4double fPY;
    G4double fPZ;
    G4double fTime;
    G4String fPDG;
    G4int fID;
    G4bool neutrinoTrack;
    G4double fnuX;
    G4double fnuY;
    G4double fnuZ;
    G4bool virtualDet;
    G4int idx;
    G4String volumeName;

    std::vector<std::string> partSelect = {"nu_e","nu_mu","nu_tau","anti_nu_e","anti_nu_mu","anti_nu_tau"};
    
};

#endif