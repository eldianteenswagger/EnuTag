#include "ENUTAG_SensitiveDetector.hh"
#include "ENUTAG_AnalysisManager.hh"

ENUTAG_SensitiveDetector::ENUTAG_SensitiveDetector(G4String name) : G4VSensitiveDetector(name) {
    //fTotalEnergyDeposited = 0.;
}

ENUTAG_SensitiveDetector::~ENUTAG_SensitiveDetector(){}

void ENUTAG_SensitiveDetector::Initialize(G4HCofThisEvent *){
    //fTotalEnergyDeposited = 0.;
}

void ENUTAG_SensitiveDetector::EndOfEvent(G4HCofThisEvent *){
    /*G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
    
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
    else{return;}

    if(!virtualDet){analysisManager->FillNtupleDColumn(idx,12,fTotalEnergyDeposited/MeV);}*/
    

}

G4bool ENUTAG_SensitiveDetector::ProcessHits(G4Step *step, G4TouchableHistory *touchHist){

    /*G4double fEnergyDeposited = step -> GetTotalEnergyDeposit();
    if (fEnergyDeposited > 0){fTotalEnergyDeposited += fEnergyDeposited;}*/
    
    return true;
}