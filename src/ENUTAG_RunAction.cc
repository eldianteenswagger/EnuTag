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
    //NTupleCreate("USVD_1");
    NTupleCreate("USVD");
    NTupleCreate("Middle_1");
    NTupleCreate("Middle_2");
    NTupleCreate("Middle_3");
    NTupleCreate("Middle_4");
    NTupleCreate("Middle_5");
    NTupleCreate("Det_1");
    NTupleCreate("Det_2");
    NTupleCreate("Det_3");
    NTupleCreate("Det_4");
    NTupleCreate("Det_5");
    NTupleCreate("DSVD_1");
    NTupleCreate("DSVD_2");
    NTupleCreate("FVD");

    //for neutrinos
    analysisManager->CreateNtuple("neutrinos", "neutrinos");
    analysisManager->CreateNtupleDColumn("nu_x");
    analysisManager->CreateNtupleDColumn("nu_y");
    analysisManager->CreateNtupleDColumn("nu_z");
    analysisManager->CreateNtupleDColumn("nu_ix");
    analysisManager->CreateNtupleDColumn("nu_iy");
    analysisManager->CreateNtupleDColumn("nu_E");
    analysisManager->CreateNtupleSColumn("nu_PDG");
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