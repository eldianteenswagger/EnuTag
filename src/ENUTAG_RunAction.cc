#include "ENUTAG_RunAction.hh"
#include "ENUTAG_RunActionMessenger.hh"
#include "ENUTAG_AnalysisManager.hh"

ENUTAG_RunAction::ENUTAG_RunAction(){
    analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetVerboseLevel(1);
    analysisManager->SetNtupleMerging(true);

    fMessenger = new ENUTAG_RunActionMessenger(this);
    
    NTuplesCreate();

}

ENUTAG_RunAction::~ENUTAG_RunAction(){}

void ENUTAG_RunAction::BeginOfRunAction(const G4Run *run) {
    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
    G4int runID = run->GetRunID();
    analysisManager->OpenFile(fileName);
}

void ENUTAG_RunAction::EndOfRunAction(const G4Run *run) {
    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
    G4int runID = run->GetRunID();
    G4cout << "Finished run " << runID << G4endl;
}

void ENUTAG_RunAction::DefineFileName(G4String newFileName){
    fileName = newFileName;
}

void ENUTAG_RunAction::NTuplesCreate(){
    analysisManager->CreateNtuple("USVD", "USVD");//0
    analysisManager->CreateNtupleDColumn("E");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("absx");
    analysisManager->CreateNtupleDColumn("absy");
    analysisManager->CreateNtupleDColumn("absz");
    analysisManager->CreateNtupleDColumn("px");
    analysisManager->CreateNtupleDColumn("py");
    analysisManager->CreateNtupleDColumn("pz");
    analysisManager->CreateNtupleDColumn("t");
    analysisManager->CreateNtupleSColumn("PDG");
    analysisManager->CreateNtupleIColumn("ID");
    analysisManager->CreateNtupleDColumn("dE");
    analysisManager->FinishNtuple();

    analysisManager->CreateNtuple("Det_1", "Det_1");//1
    analysisManager->CreateNtupleDColumn("E");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("absx");
    analysisManager->CreateNtupleDColumn("absy");
    analysisManager->CreateNtupleDColumn("absz");
    analysisManager->CreateNtupleDColumn("px");
    analysisManager->CreateNtupleDColumn("py");
    analysisManager->CreateNtupleDColumn("pz");
    analysisManager->CreateNtupleDColumn("t");
    analysisManager->CreateNtupleSColumn("PDG");
    analysisManager->CreateNtupleIColumn("ID");
    analysisManager->CreateNtupleDColumn("dE");
    analysisManager->FinishNtuple();

    analysisManager->CreateNtuple("Det_2", "Det_2");//2
    analysisManager->CreateNtupleDColumn("E");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("absx");
    analysisManager->CreateNtupleDColumn("absy");
    analysisManager->CreateNtupleDColumn("absz");
    analysisManager->CreateNtupleDColumn("px");
    analysisManager->CreateNtupleDColumn("py");
    analysisManager->CreateNtupleDColumn("pz");
    analysisManager->CreateNtupleDColumn("t");
    analysisManager->CreateNtupleSColumn("PDG");
    analysisManager->CreateNtupleIColumn("ID");
    analysisManager->CreateNtupleDColumn("dE");
    analysisManager->FinishNtuple();

    analysisManager->CreateNtuple("Det_3", "Det_3");//3
    analysisManager->CreateNtupleDColumn("E");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("absx");
    analysisManager->CreateNtupleDColumn("absy");
    analysisManager->CreateNtupleDColumn("absz");
    analysisManager->CreateNtupleDColumn("px");
    analysisManager->CreateNtupleDColumn("py");
    analysisManager->CreateNtupleDColumn("pz");
    analysisManager->CreateNtupleDColumn("t");
    analysisManager->CreateNtupleSColumn("PDG");
    analysisManager->CreateNtupleIColumn("ID");
    analysisManager->CreateNtupleDColumn("dE");
    analysisManager->FinishNtuple();

    analysisManager->CreateNtuple("Det_4", "Det_4");//4
    analysisManager->CreateNtupleDColumn("E");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("absx");
    analysisManager->CreateNtupleDColumn("absy");
    analysisManager->CreateNtupleDColumn("absz");
    analysisManager->CreateNtupleDColumn("px");
    analysisManager->CreateNtupleDColumn("py");
    analysisManager->CreateNtupleDColumn("pz");
    analysisManager->CreateNtupleDColumn("t");
    analysisManager->CreateNtupleSColumn("PDG");
    analysisManager->CreateNtupleIColumn("ID");
    analysisManager->CreateNtupleDColumn("dE");
    analysisManager->FinishNtuple();

    analysisManager->CreateNtuple("Det_5", "Det_5");//5
    analysisManager->CreateNtupleDColumn("E");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("absx");
    analysisManager->CreateNtupleDColumn("absy");
    analysisManager->CreateNtupleDColumn("absz");
    analysisManager->CreateNtupleDColumn("px");
    analysisManager->CreateNtupleDColumn("py");
    analysisManager->CreateNtupleDColumn("pz");
    analysisManager->CreateNtupleDColumn("t");
    analysisManager->CreateNtupleSColumn("PDG");
    analysisManager->CreateNtupleIColumn("ID");
    analysisManager->CreateNtupleDColumn("dE");
    analysisManager->FinishNtuple();

    analysisManager->CreateNtuple("DSVD_1", "DSVD_1");//6
    analysisManager->CreateNtupleDColumn("E");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("absx");
    analysisManager->CreateNtupleDColumn("absy");
    analysisManager->CreateNtupleDColumn("absz");
    analysisManager->CreateNtupleDColumn("px");
    analysisManager->CreateNtupleDColumn("py");
    analysisManager->CreateNtupleDColumn("pz");
    analysisManager->CreateNtupleDColumn("t");
    analysisManager->CreateNtupleSColumn("PDG");
    analysisManager->CreateNtupleIColumn("ID");
    analysisManager->CreateNtupleDColumn("dE");
    analysisManager->FinishNtuple();

    analysisManager->CreateNtuple("DSVD_2", "DSVD_2");//7
    analysisManager->CreateNtupleDColumn("E");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("absx");
    analysisManager->CreateNtupleDColumn("absy");
    analysisManager->CreateNtupleDColumn("absz");
    analysisManager->CreateNtupleDColumn("px");
    analysisManager->CreateNtupleDColumn("py");
    analysisManager->CreateNtupleDColumn("pz");
    analysisManager->CreateNtupleDColumn("t");
    analysisManager->CreateNtupleSColumn("PDG");
    analysisManager->CreateNtupleIColumn("ID");
    analysisManager->CreateNtupleDColumn("dE");
    analysisManager->FinishNtuple();

    analysisManager->CreateNtuple("FVD", "FVD");//8
    analysisManager->CreateNtupleDColumn("E");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("absx");
    analysisManager->CreateNtupleDColumn("absy");
    analysisManager->CreateNtupleDColumn("absz");
    analysisManager->CreateNtupleDColumn("px");
    analysisManager->CreateNtupleDColumn("py");
    analysisManager->CreateNtupleDColumn("pz");
    analysisManager->CreateNtupleDColumn("t");
    analysisManager->CreateNtupleSColumn("PDG");
    analysisManager->CreateNtupleIColumn("ID");
    analysisManager->CreateNtupleDColumn("dE");
    analysisManager->FinishNtuple();

    analysisManager->CreateNtuple("neutrinos", "neutrinos");//9
    analysisManager->CreateNtupleDColumn("nu_x");
    analysisManager->CreateNtupleDColumn("nu_y");
    analysisManager->CreateNtupleDColumn("nu_z");
    analysisManager->FinishNtuple();
}