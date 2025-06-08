#include "ENUTAG_SensitiveDetector.hh"
#include "ENUTAG_AnalysisManager.hh"

ENUTAG_SensitiveDetector::ENUTAG_SensitiveDetector(G4String name,G4int id) : G4VSensitiveDetector(name), fDetID(id) {
    fParticleEnergy = 0.;
    fEnergyDeposited = 0;
    fX = 0.;
    fY = 0.;
    fAbsX = 0.;
    fAbsY = 0.;
    fAbsZ = 0.;
    fPX = 0.;
    fPY = 0.;
    fPZ = 0.;
    fTime = 0.;
    fPDG = "";
    fID = 0;
    volumeName = "";
    fnuX = 0.;
    fnuY = 0.;
    fnuZ = 0.;
    fnuIX = 0.;
    fnuIY = 0.;
    fnuE = 0.;
    fnuPDG = "";
    neutrinoTrack = false;
}

ENUTAG_SensitiveDetector::~ENUTAG_SensitiveDetector(){}

void ENUTAG_SensitiveDetector::Initialize(G4HCofThisEvent *){
    fParticleEnergy = 0.;
    fEnergyDeposited = 0;
    fX = 0.;
    fY = 0.;
    fAbsX = 0.;
    fAbsY = 0.;
    fAbsZ = 0.;
    fPX = 0.;
    fPY = 0.;
    fPZ = 0.;
    fTime = 0.;
    fPDG = "";
    fID = 0;
    volumeName = "";
    fnuX = 0.;
    fnuY = 0.;
    fnuZ = 0.;
    fnuIX = 0.;
    fnuIY = 0.;
    fnuE = 0.;
    fnuPDG = "";
    neutrinoTrack = false;
}

void ENUTAG_SensitiveDetector::EndOfEvent(G4HCofThisEvent *){}

G4bool ENUTAG_SensitiveDetector::ProcessHits(G4Step *step, G4TouchableHistory *touchHist){

    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();

    G4Track* track = (G4Track*)(step->GetTrack());
    G4StepPoint *preStepPoint = step -> GetPreStepPoint();
    G4StepPoint *postStepPoint = step -> GetPostStepPoint();
    const G4VTouchable *touchable = step -> GetPreStepPoint() -> GetTouchable();

    //position
    G4ThreeVector posParticle = preStepPoint->GetPosition();
    G4ThreeVector posDet = touchable->GetVolume()->GetTranslation();
    fX = posParticle.getZ()-posDet.getZ();
    fY = posParticle.getY()-posDet.getY();
    //absolute position
    fAbsX = posParticle.getX();
    fAbsY = posParticle.getY();
    fAbsZ = posParticle.getZ();
    //total energy
    fParticleEnergy = track -> GetTotalEnergy();
    //deposited energy
    fEnergyDeposited = step -> GetTotalEnergyDeposit();
    //momentum
    G4ThreeVector particleMomentum = preStepPoint -> GetMomentum();
    fPX = particleMomentum.getX();
    fPY = particleMomentum.getY();
    fPZ = particleMomentum.getZ();
    //time
    fTime = track -> GetLocalTime();
    //pdg
    fPDG = track -> GetParticleDefinition() -> GetParticleName();
    //ID
    fID = track -> GetTrackID();
    //get volume name
    volumeName = touchable -> GetVolume() -> GetName();
    //stuff for neutrinos
    if (volumeName=="physFVD") {
        if ( std::find(partSelect.begin(), partSelect.end(), fPDG)!= partSelect.end() ){
            fnuX = track->GetVertexPosition().x();
            fnuY = track->GetVertexPosition().y();
            fnuZ = track->GetVertexPosition().z();
            fnuIX = -1.*fX/std::cos(9.09*3.141592/90);
            fnuIY = fY;
            fnuE =  fParticleEnergy;
            fnuPDG = fPDG;
            neutrinoTrack = true;
        }
    }

    //register
    /*if (volumeName=="physUSVD1"){idx = 0;virtualDet=true;}
    else if (volumeName=="physUSVD2"){idx = 1;virtualDet=true;}
    else if (volumeName=="physMiddle1"){idx = 2;virtualDet=true;}
    else if (volumeName=="physDetector1"){idx = 3;virtualDet = false;}
    else if (volumeName=="physDetector2"){idx = 4;virtualDet = false;}
    else if (volumeName=="physDetector3"){idx = 5;virtualDet = false;}
    else if (volumeName=="physDetector4"){idx = 6;virtualDet = false;}
    else if (volumeName=="physDetector5"){idx = 7;virtualDet = false;}
    else if (volumeName=="physDSVD1"){idx = 8;virtualDet=true;}
    else if (volumeName=="physDSVD2"){idx = 9;virtualDet=true;}
    else if (volumeName=="physFVD"){idx = 10;virtualDet=true;}*/
    //energy
    analysisManager->FillNtupleDColumn(fDetID,0,fParticleEnergy/MeV);
    //position
    analysisManager->FillNtupleDColumn(fDetID,1,fX/mm);
    analysisManager->FillNtupleDColumn(fDetID,2,fY/mm);
    //absolute position
    analysisManager->FillNtupleDColumn(fDetID,3,fAbsX/mm);
    analysisManager->FillNtupleDColumn(fDetID,4,fAbsY/mm);
    analysisManager->FillNtupleDColumn(fDetID,5,fAbsZ/mm);
    //momentum
    analysisManager->FillNtupleDColumn(fDetID,6,fPX/MeV);
    analysisManager->FillNtupleDColumn(fDetID,7,fPY/MeV);
    analysisManager->FillNtupleDColumn(fDetID,8,fPZ/MeV);
    //time
    analysisManager->FillNtupleDColumn(fDetID,9,fTime/s);
    //pdg
    analysisManager->FillNtupleSColumn(fDetID,10,fPDG);
    //ids
    analysisManager->FillNtupleIColumn(fDetID,11,fID);
    //deposited energy
    if(!virtualDet[fDetID] && fEnergyDeposited>0){analysisManager->FillNtupleDColumn(fDetID,12,fEnergyDeposited/MeV);}
    //close row
    analysisManager->AddNtupleRow(fDetID);
    //neutrinos
    if(neutrinoTrack){
        analysisManager->FillNtupleDColumn(14,0,fnuX/m);
        analysisManager->FillNtupleDColumn(14,1,fnuY/m);
        analysisManager->FillNtupleDColumn(14,2,fnuZ/m);
        analysisManager->FillNtupleDColumn(14,3,fnuIX/mm);
        analysisManager->FillNtupleDColumn(14,4,fnuIY/mm);
        analysisManager->FillNtupleDColumn(14,5,fnuE/MeV);
        analysisManager->FillNtupleSColumn(14,6,fnuPDG);
        analysisManager->AddNtupleRow(14);
        neutrinoTrack = false;
    }

    return true;
}