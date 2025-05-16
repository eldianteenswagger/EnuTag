#include "ENUTAG_PrimaryGenerator.hh"
#include "ENUTAG_PrimaryGeneratorMessenger.hh"
#include "Randomize.hh"

G4double p = 8.5*GeV;

ENUTAG_PrimaryGenerator::ENUTAG_PrimaryGenerator(){

    fParticleGun = new G4ParticleGun(1);
    fMessenger = new ENUTAG_PrimaryGeneratorMessenger(this);

}

ENUTAG_PrimaryGenerator::~ENUTAG_PrimaryGenerator(){
    delete fParticleGun;
    delete fMessenger;
}

void ENUTAG_PrimaryGenerator::GeneratePrimaries(G4Event *anEvent){
    //create vertex
    fParticleGun->GeneratePrimaryVertex(anEvent);
}

void ENUTAG_PrimaryGenerator::TestMode(G4bool test){
    G4cout << "Test variable: " << test << G4endl;
    if(test){

        G4cout << "TEST MODE ON" << G4endl; 

        G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
        fParticleGun -> SetParticlePosition(G4ThreeVector(0.65*m,0.,0.));
        ranAngle = 2.*(G4UniformRand()-0.5)*deg;
        fParticleGun -> SetParticleMomentum(G4ThreeVector(cos(ranAngle)*p,0.,sin(ranAngle)*p));
        fParticleGun -> SetParticleDefinition(particleTable -> FindParticle("pi+"));

    }
    else{

        G4cout << "TEST MODE OFF" << G4endl; 

        G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
        fParticleGun -> SetParticlePosition(G4ThreeVector(-0.65*m,0.,0.));
        fParticleGun -> SetParticleMomentum(G4ThreeVector(400.*GeV,0.,0.));
        fParticleGun -> SetParticleDefinition(particleTable -> FindParticle("proton"));
    }
}