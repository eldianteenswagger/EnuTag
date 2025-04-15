#include "ENUTAG_PrimaryGenerator.hh"

ENUTAG_PrimaryGenerator::ENUTAG_PrimaryGenerator(){
    fParticleGun = new G4ParticleGun(1);
    //particle position
    G4double x = -1.5 * m;
    G4double y = 0. * m;
    G4double z = 0. * m;
    G4ThreeVector pos(x,y,z);
    //particle momentum
    //G4double px = 8.5 * GeV;
    G4double px = 400. * GeV;
    G4double py = 0.;
    G4double pz = 0.;
    G4ThreeVector mom(px,py,pz);
    //particle type
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition *particle = particleTable -> FindParticle("proton");
    fParticleGun -> SetParticlePosition(pos);
    fParticleGun -> SetParticleMomentum(mom);
    fParticleGun -> SetParticleDefinition(particle);
}

ENUTAG_PrimaryGenerator::~ENUTAG_PrimaryGenerator(){
    delete fParticleGun;
}

void ENUTAG_PrimaryGenerator::GeneratePrimaries(G4Event *anEvent){
    //create vertex
    fParticleGun->GeneratePrimaryVertex(anEvent);
}