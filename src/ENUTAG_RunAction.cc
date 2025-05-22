#include "ENUTAG_RunAction.hh"
#include "ENUTAG_RunActionMessenger.hh"
#include "ENUTAG_AnalysisManager.hh"

ENUTAG_RunAction::ENUTAG_RunAction(){
    analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetVerboseLevel(1);
    analysisManager->SetNtupleMerging(true);

    fMessenger = new ENUTAG_RunActionMessenger(this);
    
    DefineFile();

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

void ENUTAG_RunAction::DefineFile(){
    NTupleCreate("USVD_1");//0
    NTupleCreate("USVD_2");//1
    NTupleCreate("Middle_1");//2
    NTupleCreate("Middle_2");//3
    NTupleCreate("Middle_3");//4
    NTupleCreate("Middle_4");//5
    NTupleCreate("Middle_5");//6
    NTupleCreate("Det_1");//7
    NTupleCreate("Det_2");//8
    NTupleCreate("Det_3");//9
    NTupleCreate("Det_4");//10
    NTupleCreate("Det_5");//11
    NTupleCreate("DSVD_1");//12
    NTupleCreate("DSVD_2");//13
    NTupleCreate("FVD");//14

    //for neutrinos
    analysisManager->CreateNtuple("neutrinos", "neutrinos");//15
    analysisManager->CreateNtupleDColumn("nu_x");
    analysisManager->CreateNtupleDColumn("nu_y");
    analysisManager->CreateNtupleDColumn("nu_z");
    analysisManager->FinishNtuple();
}

void ENUTAG_RunAction::NTupleCreate(G4String ntupleName){
    analysisManager->CreateNtuple(ntupleName,ntupleName);
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
}
/*    analysisManager->CreateNtuple("USVD_1", "USVD_1");//0
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

    analysisManager->CreateNtuple("USVD_2", "USVD_2");//1
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

    analysisManager->CreateNtuple("Middle_1", "Middle_1");//2
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

    analysisManager->CreateNtuple("Det_1", "Det_1");//3
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

    analysisManager->CreateNtuple("Det_2", "Det_2");//4
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

    analysisManager->CreateNtuple("Det_3", "Det_3");//5
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

    analysisManager->CreateNtuple("Det_4", "Det_4");//6
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

    analysisManager->CreateNtuple("Det_5", "Det_5");//7
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

    analysisManager->CreateNtuple("DSVD_1", "DSVD_1");//8
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

    analysisManager->CreateNtuple("DSVD_2", "DSVD_2");//9
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

    analysisManager->CreateNtuple("FVD", "FVD");//10
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


}*/