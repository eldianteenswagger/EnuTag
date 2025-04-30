#include "ENUTAG_PrimaryGenerator.hh"
#include "ENUTAG_PrimaryGeneratorMessenger.hh"

ENUTAG_PrimaryGenerator::ENUTAG_PrimaryGenerator(){
    //messenger
    //particle stuff
    fParticleGun = new G4ParticleGun(1);
    fMessenger = new ENUTAG_PrimaryGeneratorMessenger(this);
    
    //TestMode(true);
    /* x = -0.65*m;
    y = 0. * m;
    z = 0. * m;

    px = 400.*GeV;
    py = 0.;
    pz = 0.;    

    particleType = "proton";
    
    G4cout << "PARTICLE TYPE: " << particleType << G4endl; 

    G4ThreeVector pos(x,y,z);
    G4ThreeVector mom(px,py,pz);

    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition *particle = particleTable -> FindParticle(particleType);
    fParticleGun -> SetParticlePosition(pos);
    fParticleGun -> SetParticleMomentum(mom);
    fParticleGun -> SetParticleDefinition(particle); */
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
        fParticleGun -> SetParticleMomentum(G4ThreeVector(8.5*GeV,0.,0.));
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