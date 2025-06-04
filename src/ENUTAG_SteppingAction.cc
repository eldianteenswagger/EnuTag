#include "ENUTAG_SteppingAction.hh"

ENUTAG_SteppingAction::ENUTAG_SteppingAction(ENUTAG_EventAction* evtAct){
    fEvtAction = evtAct;
    Emin = 50. * MeV;

    /*G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();

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
    idx = 10;
    volumeName = "";
    fnuX = 0.;
    fnuY = 0.;
    fnuZ = 0.;
    neutrinoTrack = false;
    virtualDet = false;*/
}

ENUTAG_SteppingAction::~ENUTAG_SteppingAction(){}

void ENUTAG_SteppingAction::UserSteppingAction(const G4Step* step){

    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();

    G4Track* track = (G4Track*)(step->GetTrack());
    G4double Ekin = track -> GetKineticEnergy();
    if (Ekin < Emin) track -> SetTrackStatus(fStopAndKill);
    std::string pID = (track -> GetParticleDefinition() -> GetParticleName()).c_str();
    if (pID=="gamma" || pID=="neutron" || pID=="anti_neutron") track -> SetTrackStatus(fStopAndKill);

    //analysis
    //step stuff
    /*G4StepPoint *preStepPoint = step -> GetPreStepPoint();
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
            neutrinoTrack = true;
        }
    }

    //if exiting, register all
    if(preStepPoint->GetStepStatus() == fGeomBoundary){
        //index setting for ROOT file output
        if (volumeName=="physUSVD1"){idx = 0;virtualDet=true;}
        else if (volumeName=="physUSVD2"){idx = 1;virtualDet=true;}
        else if (volumeName=="physDetector1"){idx = 2;virtualDet = false;}
        else if (volumeName=="physDetector2"){idx = 3;virtualDet = false;}
        else if (volumeName=="physDetector3"){idx = 4;virtualDet = false;}
        else if (volumeName=="physDetector4"){idx = 5;virtualDet = false;}
        else if (volumeName=="physDetector5"){idx = 6;virtualDet = false;}
        else if (volumeName=="physDSVD1"){idx = 7;virtualDet=true;}
        else if (volumeName=="physDSVD2"){idx = 8;virtualDet=true;}
        else if (volumeName=="physFVD"){idx = 9;virtualDet=true;}
        else{return;}

        //energy
        analysisManager->FillNtupleDColumn(idx,0,fParticleEnergy/MeV);
        //position
        analysisManager->FillNtupleDColumn(idx,1,fX/mm);
        analysisManager->FillNtupleDColumn(idx,2,fY/mm);
        //absolute position
        analysisManager->FillNtupleDColumn(idx,3,fAbsX/mm);
        analysisManager->FillNtupleDColumn(idx,4,fAbsY/mm);
        analysisManager->FillNtupleDColumn(idx,5,fAbsZ/mm);
        //momentum
        analysisManager->FillNtupleDColumn(idx,6,fPX/MeV);
        analysisManager->FillNtupleDColumn(idx,7,fPY/MeV);
        analysisManager->FillNtupleDColumn(idx,8,fPZ/MeV);
        //time
        analysisManager->FillNtupleDColumn(idx,9,fTime/s);
        //pdg
        analysisManager->FillNtupleSColumn(idx,10,fPDG);
        //ids
        analysisManager->FillNtupleIColumn(idx,11,fID);
        //deposited energy
        if(!virtualDet && fEnergyDeposited>0){analysisManager->FillNtupleDColumn(idx,12,fEnergyDeposited/MeV);}
        //close row
        analysisManager->AddNtupleRow(idx);
        //neutrinos
        if(neutrinoTrack){
            analysisManager->FillNtupleDColumn(10,0,fnuX/m);
            analysisManager->FillNtupleDColumn(10,1,fnuY/m);
            analysisManager->FillNtupleDColumn(10,2,fnuZ/m);
            analysisManager->AddNtupleRow(10);
            neutrinoTrack = false;
        }
    }*/

    return;
}