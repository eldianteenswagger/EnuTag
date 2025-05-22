#ifndef ENUTAG_SENSITIVEDETECTOR_HH
#define ENUTAG_SENSITIVEDETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

class ENUTAG_SensitiveDetector : public G4VSensitiveDetector{
public:
    ENUTAG_SensitiveDetector(G4String,G4int);
    ~ENUTAG_SensitiveDetector();

private:
    
    virtual void Initialize(G4HCofThisEvent *) override;
    virtual void EndOfEvent(G4HCofThisEvent *) override;

    virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);

    G4int fDetID;
    //ENUTAG_EventAction* fEvtAction;
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
    G4String volumeName;

    std::vector<std::string> partSelect = {"nu_e","nu_mu","nu_tau","anti_nu_e","anti_nu_mu","anti_nu_tau"};
    std::vector<G4bool> virtualDet = {true,true,true,true,true,true,true,false,false,false,false,false,true,true,true};

};

#endif