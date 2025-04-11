#ifndef ENUTAG_PRIMARYGENERATOR_HH
#define ENUTAG_PRIMARYGENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"

class ENUTAG_PrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
public:
    ENUTAG_PrimaryGenerator();
    ~ENUTAG_PrimaryGenerator();

    virtual void GeneratePrimaries(G4Event *);

private:
    G4ParticleGun *fParticleGun;
};

#endif