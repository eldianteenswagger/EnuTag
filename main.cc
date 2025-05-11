#include<iostream>

#include"G4MTRunManager.hh"
#include"G4UImanager.hh"
#include"G4UIExecutive.hh"
#include"G4VisManager.hh"
#include"G4VisExecutive.hh"

#include "FTFP_BERT.hh"

#include "ENUTAG_Construction.hh"
#include "ENUTAG_ActionInitialization.hh"

#include"Randomize.hh"
#include<ctime>
#include<string>

//this is proof that I pushed on my online GitHub page

int main(int argc, char** argv){

    //Run manager
    #ifdef G4MULTITHREADED
        G4MTRunManager *runManager = new G4MTRunManager;
    #else
        G4RunManager *runManager = new G4RunManager;
    #endif

    //PhysicsList
    //runManager->SetUserInitialization(new ENUTAG_PhysicsList());
    G4VUserPhysicsList* physics = new FTFP_BERT();
    runManager-> SetUserInitialization(physics);
    //Detector construction
    runManager->SetUserInitialization(new ENUTAG_Construction());
    //Action initialization
    runManager->SetUserInitialization(new ENUTAG_ActionInitialization());
    //Visualization manager
    G4VisManager *visManager = new G4VisExecutive();
    visManager->Initialize();

    G4UImanager *UImanager = G4UImanager::GetUIpointer();

    G4long seed = time(nullptr);
    CLHEP::HepRandom::setTheSeed(seed);

    //macro choice
    if(argc==1){
        G4UIExecutive *ui = new G4UIExecutive(argc, argv);
        UImanager->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();
        delete ui;
    } else {
        std::string arg1(argv[1]);
        if (arg1=="run.mac"){
            UImanager->ApplyCommand("/control/execute run.mac");
        } else {
            G4String command = "/control/execute ";
            G4UIExecutive *ui = new G4UIExecutive(argc, argv);
            UImanager->ApplyCommand(command+arg1);
            ui->SessionStart();
            delete ui;
        }
    }

    G4cout << "Random seed set to: " << seed << G4endl;
    
    return 0;
}