#include "ENUTAG_SensitiveDetector.hh"
#include "ENUTAG_AnalysisManager.hh"

std::vector<std::string> partSelect = {"nu_e","nu_mu","nu_tau","anti_nu_e","anti_nu_mu","anti_nu_tau"};

ENUTAG_SensitiveDetector::ENUTAG_SensitiveDetector(G4String name) : G4VSensitiveDetector(name) {
    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
    fParticleEnergy = 0.;
    fTotalEnergyDeposited = 0.;
    fX = 0.;
    fY = 0.;
    fPX = 0.;
    fPY = 0.;
    fPZ = 0.;
    fTime = 0.;
    fPDG = "";
    fID = 0;
    idx = 0;
    volumeName = "";
    fnuX = 0.;
    fnuY = 0.;
    fnuZ = 0.;
    neutrinoTrack = false;
    virtualDet = false;
}

ENUTAG_SensitiveDetector::~ENUTAG_SensitiveDetector(){}

void ENUTAG_SensitiveDetector::Initialize(G4HCofThisEvent *){
    fParticleEnergy = 0.;
    fTotalEnergyDeposited = 0.;
    fX = 0.;
    fY = 0.;
    fPX = 0.;
    fPY = 0.;
    fPZ = 0.;
    fTime = 0.;
    fPDG = "";
    fID = 0;
    idx = 0;
    volumeName = "";
    fnuX = 0.;
    fnuY = 0.;
    fnuZ = 0.;
    neutrinoTrack = false;
    virtualDet = false;
}

void ENUTAG_SensitiveDetector::EndOfEvent(G4HCofThisEvent *){
    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
    
    //G4cout << "Total energy: " << fTotalEnergyDeposited << G4endl;
    //index setting for ROOT file output
    if (volumeName=="physUSVD"){idx = 0;virtualDet=true;}
    else if(volumeName=="physDetector1"){idx = 1;virtualDet = false;}
    else if (volumeName=="physDetector2"){idx = 2;virtualDet = false;}
    else if (volumeName=="physDetector3"){idx = 3;virtualDet = false;}
    else if (volumeName=="physDetector4"){idx = 4;virtualDet = false;}
    else if (volumeName=="physDetector5"){idx = 5;virtualDet = false;}
    else if (volumeName=="physDSVD1"){idx = 6;virtualDet=true;}
    else if (volumeName=="physDSVD2"){idx = 7;virtualDet=true;}
    else if (volumeName=="physFVD"){idx = 8;virtualDet=true;}

    //G4cout << volumeName << " " << idx << G4endl;

    //ROOT file filling
    //refresh: when in USDV (1st detector) start new ntuple row
    /*int lastNtuple = 6;
    if(refresh){
        for(int i=0;i<=lastNtuple;i++){
            analysisManager->AddNtupleRow(i);
        }
        refresh=false;
    }*/
    //energy
    analysisManager->FillNtupleDColumn(idx,0,fParticleEnergy/MeV);
    
    //position
    analysisManager->FillNtupleDColumn(idx,1,fX/mm); //x is z
    analysisManager->FillNtupleDColumn(idx,2,fY/mm);
    //momentum
    analysisManager->FillNtupleDColumn(idx,3,fPX/MeV);
    analysisManager->FillNtupleDColumn(idx,4,fPY/MeV);
    analysisManager->FillNtupleDColumn(idx,5,fPZ/MeV);
    //time
    analysisManager->FillNtupleDColumn(idx,6,fTime/s);
    //pdg
    analysisManager->FillNtupleSColumn(idx,7,fPDG);
    //ids
    analysisManager->FillNtupleIColumn(idx,8,fID);
    //deposited energy (only for real detectors)
    if(!virtualDet){analysisManager->FillNtupleDColumn(idx,9,fTotalEnergyDeposited/MeV);}
    //else{analysisManager->FillNtupleDColumn(idx,9,0.);}
    //if(fTotalEnergyDeposited==0.){G4cout << fPDG << G4endl;}}
    //close row
    analysisManager->AddNtupleRow(idx);
    if(neutrinoTrack){
        analysisManager->FillNtupleDColumn(9,0,fnuX);
        analysisManager->FillNtupleDColumn(9,1,fnuY);
        analysisManager->FillNtupleDColumn(9,2,fnuZ);
        analysisManager->AddNtupleRow(9);
        neutrinoTrack = false;
    }

}

G4bool ENUTAG_SensitiveDetector::ProcessHits(G4Step *step, G4TouchableHistory *touchHist){
    //step stuff
    G4Track *track = step -> GetTrack();
    G4StepPoint *preStepPoint = step -> GetPreStepPoint();
    G4StepPoint *postStepPoint = step -> GetPostStepPoint();
    const G4VTouchable *touchable = step -> GetPreStepPoint() -> GetTouchable();
        
    //position
    G4ThreeVector posParticle = preStepPoint->GetPosition();
    G4ThreeVector posDet = touchable->GetVolume()->GetTranslation();
    fX = posParticle.getZ()-posDet.getZ();
    fY = posParticle.getY()-posDet.getY();

    //deposited energy
    G4double fEnergyDeposited = step -> GetTotalEnergyDeposit();
    if (fEnergyDeposited > 0){fTotalEnergyDeposited += fEnergyDeposited;}

    fParticleEnergy = track -> GetTotalEnergy();

    //momentum
    G4ThreeVector particleMomentum = preStepPoint->GetMomentum();
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
    volumeName = touchable->GetVolume()->GetName();
    //stuff for neutrinos
    if (volumeName=="physFVD") {
        if ( std::find(partSelect.begin(), partSelect.end(), fPDG)!= partSelect.end() ){
            fnuX = track->GetVertexPosition().x()/m;
            fnuY = track->GetVertexPosition().y()/m;
            fnuZ = track->GetVertexPosition().z()/m;
            neutrinoTrack = true;
        }
    }
    
    return true;
}