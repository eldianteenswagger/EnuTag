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
    
    virtual void Initialize(G4HCofThisEvent *) override;
    virtual void EndOfEvent(G4HCofThisEvent *) override;

    virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);

    //G4double fTotalEnergyDeposited;

};

#endif