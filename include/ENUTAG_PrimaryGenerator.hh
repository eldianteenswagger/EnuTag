#ifndef ENUTAG_PRIMARYGENERATOR_HH
#define ENUTAG_PRIMARYGENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"

class ENUTAG_PrimaryGeneratorMessenger;

class ENUTAG_PrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
public:
    ENUTAG_PrimaryGenerator();
    ~ENUTAG_PrimaryGenerator();

    virtual void GeneratePrimaries(G4Event *);
    void TestMode(G4bool);

private:
    G4ParticleGun *fParticleGun;
    ENUTAG_PrimaryGeneratorMessenger* fMessenger;

    G4double x;
    G4double y;
    G4double z;

    G4double px;
    G4double py;
    G4double pz;

    G4double ranAngle;

    G4String particleType;
};

#endif