#include "ENUTAG_RunAction.hh"
#include "ENUTAG_AnalysisManager.hh"

ENUTAG_RunAction::ENUTAG_RunAction(){
    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetVerboseLevel(1);
    analysisManager->SetNtupleMerging(true);
    
    /*analysisManager->CreateH1("Det1_energy","Det1_energy",95,0.05,1.);
    analysisManager->CreateH1("Det2_energy","Det2_energy",95,0.05,1.);
    analysisManager->CreateH1("Det3_energy","Det3_energy",95,0.05,1.);
    analysisManager->CreateH1("Det4_energy","Det4_energy",95,0.05,1.);
    analysisManager->CreateH1("Det5_energy","Det5_energy",95,0.05,1.);

    analysisManager->CreateH1("USVD_energy","USVD_energy",100,8400.,8600.);
    analysisManager->CreateH1("DSVD1_energy","DSVD1_energy",100,8400.,8600.);
    analysisManager->CreateH1("DSVD2_energy","DSVD2_energy",100,8400.,8600.);*/

    //NTUPLES

    //energies
    /*analysisManager->CreateNtuple("ENERGIES", "ENERGIES"); //0
    analysisManager->CreateNtupleDColumn("1_E");
    analysisManager->CreateNtupleDColumn("2_E");
    analysisManager->CreateNtupleDColumn("3_E");
    analysisManager->CreateNtupleDColumn("4_E");
    analysisManager->CreateNtupleDColumn("5_E");
    analysisManager->CreateNtupleDColumn("USVD_E");
    analysisManager->CreateNtupleDColumn("DSVD1_E");
    analysisManager->CreateNtupleDColumn("DSVD2_E");
    analysisManager->FinishNtuple();

    //deposited energies
    analysisManager->CreateNtuple("DEP_ENERGIES", "DEP_ENERGIES"); //1
    analysisManager->CreateNtupleDColumn("1_dE");
    analysisManager->CreateNtupleDColumn("2_dE");
    analysisManager->CreateNtupleDColumn("3_dE");
    analysisManager->CreateNtupleDColumn("4_dE");
    analysisManager->CreateNtupleDColumn("5_dE");
    analysisManager->FinishNtuple();

    //positions
    analysisManager->CreateNtuple("POSITIONS", "POSITIONS"); //2

    analysisManager->CreateNtupleDColumn("1_x");
    analysisManager->CreateNtupleDColumn("1_y");

    analysisManager->CreateNtupleDColumn("2_x");
    analysisManager->CreateNtupleDColumn("2_y");

    analysisManager->CreateNtupleDColumn("3_x");
    analysisManager->CreateNtupleDColumn("3_y");

    analysisManager->CreateNtupleDColumn("4_x");
    analysisManager->CreateNtupleDColumn("4_y");

    analysisManager->CreateNtupleDColumn("5_x");
    analysisManager->CreateNtupleDColumn("5_y");

    analysisManager->CreateNtupleDColumn("USVD_x");
    analysisManager->CreateNtupleDColumn("USVD_y");

    analysisManager->CreateNtupleDColumn("DSVD1_x");
    analysisManager->CreateNtupleDColumn("DSVD1_y");

    analysisManager->CreateNtupleDColumn("DSVD2_x");
    analysisManager->CreateNtupleDColumn("DSVD2_y");

    analysisManager->FinishNtuple();

    //momentum
    analysisManager->CreateNtuple("MOMENTUM", "MOMENTUM"); //3

    analysisManager->CreateNtupleDColumn("1_px");
    analysisManager->CreateNtupleDColumn("1_py");
    analysisManager->CreateNtupleDColumn("1_pz");

    analysisManager->CreateNtupleDColumn("2_px");
    analysisManager->CreateNtupleDColumn("2_py");
    analysisManager->CreateNtupleDColumn("2_pz");

    analysisManager->CreateNtupleDColumn("3_px");
    analysisManager->CreateNtupleDColumn("3_py");
    analysisManager->CreateNtupleDColumn("3_pz");

    analysisManager->CreateNtupleDColumn("4_px");
    analysisManager->CreateNtupleDColumn("4_py");
    analysisManager->CreateNtupleDColumn("4_pz");

    analysisManager->CreateNtupleDColumn("5_px");
    analysisManager->CreateNtupleDColumn("5_py");
    analysisManager->CreateNtupleDColumn("5_pz");
    
    analysisManager->CreateNtupleDColumn("USVD_px");
    analysisManager->CreateNtupleDColumn("USVD_py");
    analysisManager->CreateNtupleDColumn("USVD_pz");

    analysisManager->CreateNtupleDColumn("DSVD1_px");
    analysisManager->CreateNtupleDColumn("DSVD1_py");
    analysisManager->CreateNtupleDColumn("DSVD1_pz");

    analysisManager->CreateNtupleDColumn("DSVD2_px");
    analysisManager->CreateNtupleDColumn("DSVD2_py");
    analysisManager->CreateNtupleDColumn("DSVD2_pz");

    analysisManager->FinishNtuple();

    //time
    analysisManager->CreateNtuple("TIME", "TIME"); //4
    analysisManager->CreateNtupleDColumn("1_t");
    analysisManager->CreateNtupleDColumn("2_t");
    analysisManager->CreateNtupleDColumn("3_t");
    analysisManager->CreateNtupleDColumn("4_t");
    analysisManager->CreateNtupleDColumn("5_t");
    analysisManager->CreateNtupleDColumn("USVD_t");
    analysisManager->CreateNtupleDColumn("DSVD1_t");
    analysisManager->CreateNtupleDColumn("DSVD2_t");
    analysisManager->FinishNtuple();

    //pdg
    analysisManager->CreateNtuple("PDG", "PDG"); //5
    analysisManager->CreateNtupleDColumn("1_PDG");
    analysisManager->CreateNtupleDColumn("2_PDG");
    analysisManager->CreateNtupleDColumn("3_PDG");
    analysisManager->CreateNtupleDColumn("4_PDG");
    analysisManager->CreateNtupleDColumn("5_PDG");
    analysisManager->CreateNtupleDColumn("USVD_PDG");
    analysisManager->CreateNtupleDColumn("DSVD1_PDG");
    analysisManager->CreateNtupleDColumn("DSVD2_PDG");
    analysisManager->FinishNtuple();

    //track_id
    analysisManager->CreateNtuple("ID", "ID"); //6
    analysisManager->CreateNtupleDColumn("1_ID");
    analysisManager->CreateNtupleDColumn("2_ID");
    analysisManager->CreateNtupleDColumn("3_ID");
    analysisManager->CreateNtupleDColumn("4_ID");
    analysisManager->CreateNtupleDColumn("5_ID");
    analysisManager->CreateNtupleDColumn("USVD_ID");
    analysisManager->CreateNtupleDColumn("DSVD1_ID");
    analysisManager->CreateNtupleDColumn("DSVD2_ID");
    analysisManager->FinishNtuple();*/

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