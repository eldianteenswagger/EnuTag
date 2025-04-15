#include "ENUTAG_RunAction.hh"
#include "ENUTAG_AnalysisManager.hh"

ENUTAG_RunAction::ENUTAG_RunAction(){
    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetVerboseLevel(1);
    analysisManager->SetNtupleMerging(true);
    
    //NEW NTUPLES
    analysisManager->CreateNtuple("USVD", "USVD");
    analysisManager->CreateNtupleDColumn("E");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("px");
    analysisManager->CreateNtupleDColumn("py");
    analysisManager->CreateNtupleDColumn("pz");
    analysisManager->CreateNtupleDColumn("t");
    analysisManager->CreateNtupleSColumn("PDG");
    analysisManager->CreateNtupleIColumn("ID");
    analysisManager->FinishNtuple();

    analysisManager->CreateNtuple("Det_1", "Det_1");
    analysisManager->CreateNtupleDColumn("E");//0
    analysisManager->CreateNtupleDColumn("x");//1
    analysisManager->CreateNtupleDColumn("y");//2
    analysisManager->CreateNtupleDColumn("px");//3
    analysisManager->CreateNtupleDColumn("py");//4
    analysisManager->CreateNtupleDColumn("pz");//5
    analysisManager->CreateNtupleDColumn("t");//6
    analysisManager->CreateNtupleSColumn("PDG");//7
    analysisManager->CreateNtupleIColumn("ID");//8
    analysisManager->CreateNtupleDColumn("dE");//9
    analysisManager->FinishNtuple();

    analysisManager->CreateNtuple("Det_2", "Det_2");
    analysisManager->CreateNtupleDColumn("E");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("px");
    analysisManager->CreateNtupleDColumn("py");
    analysisManager->CreateNtupleDColumn("pz");
    analysisManager->CreateNtupleDColumn("t");
    analysisManager->CreateNtupleSColumn("PDG");
    analysisManager->CreateNtupleIColumn("ID");
    analysisManager->CreateNtupleIColumn("dE");
    analysisManager->FinishNtuple();

    analysisManager->CreateNtuple("Det_3", "Det_3");
    analysisManager->CreateNtupleDColumn("E");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("px");
    analysisManager->CreateNtupleDColumn("py");
    analysisManager->CreateNtupleDColumn("pz");
    analysisManager->CreateNtupleDColumn("t");
    analysisManager->CreateNtupleSColumn("PDG");
    analysisManager->CreateNtupleIColumn("ID");
    analysisManager->CreateNtupleDColumn("dE");
    analysisManager->FinishNtuple();

    analysisManager->CreateNtuple("Det_4", "Det_4");
    analysisManager->CreateNtupleDColumn("E");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("px");
    analysisManager->CreateNtupleDColumn("py");
    analysisManager->CreateNtupleDColumn("pz");
    analysisManager->CreateNtupleDColumn("t");
    analysisManager->CreateNtupleSColumn("PDG");
    analysisManager->CreateNtupleIColumn("ID");
    analysisManager->CreateNtupleDColumn("dE");
    analysisManager->FinishNtuple();

    analysisManager->CreateNtuple("Det_5", "Det_5");
    analysisManager->CreateNtupleDColumn("E");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("px");
    analysisManager->CreateNtupleDColumn("py");
    analysisManager->CreateNtupleDColumn("pz");
    analysisManager->CreateNtupleDColumn("t");
    analysisManager->CreateNtupleSColumn("PDG");
    analysisManager->CreateNtupleIColumn("ID");
    analysisManager->CreateNtupleDColumn("dE");
    analysisManager->FinishNtuple();

    analysisManager->CreateNtuple("DSVD_1", "DSVD_1");
    analysisManager->CreateNtupleDColumn("E");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("px");
    analysisManager->CreateNtupleDColumn("py");
    analysisManager->CreateNtupleDColumn("pz");
    analysisManager->CreateNtupleDColumn("t");
    analysisManager->CreateNtupleSColumn("PDG");
    analysisManager->CreateNtupleIColumn("ID");
    analysisManager->FinishNtuple();

    analysisManager->CreateNtuple("DSVD_2", "DSVD_2");
    analysisManager->CreateNtupleDColumn("E");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("px");
    analysisManager->CreateNtupleDColumn("py");
    analysisManager->CreateNtupleDColumn("pz");
    analysisManager->CreateNtupleDColumn("t");
    analysisManager->CreateNtupleSColumn("PDG");
    analysisManager->CreateNtupleIColumn("ID");
    analysisManager->FinishNtuple();

}

ENUTAG_RunAction::~ENUTAG_RunAction(){

}

void ENUTAG_RunAction::BeginOfRunAction(const G4Run *run) {
    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
    G4int runID = run->GetRunID();
    G4String fileName = "out.root";
    analysisManager->OpenFile(fileName);
}

void ENUTAG_RunAction::EndOfRunAction(const G4Run *run) {
    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
    G4int runID = run->GetRunID();
    G4cout << "Finished run " << runID << G4endl;
}