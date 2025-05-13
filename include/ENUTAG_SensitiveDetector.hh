#ifndef ENUTAG_SENSITIVEDETECTOR_HH
#define ENUTAG_SENSITIVEDETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

class ENUTAG_SensitiveDetector : public G4VSensitiveDetector{
public:
    ENUTAG_SensitiveDetector(G4String);
    ~ENUTAG_SensitiveDetector();

private:
    G4double fTotalEnergyDeposited;
    G4double fParticleEnergy;
    G4double fX;
    G4double fY;
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
    
    virtual void Initialize(G4HCofThisEvent *) override;
    virtual void EndOfEvent(G4HCofThisEvent *) override;

    virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);

};

#endif