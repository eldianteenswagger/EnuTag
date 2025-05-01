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

    G4UIExecutive *ui;
    G4UImanager *UImanager = G4UImanager::GetUIpointer();
    ui = new G4UIExecutive(argc, argv);

    //macro choice
    if(argv[1]==nullptr){
        UImanager->ApplyCommand("/control/execute vis.mac");
    } else {
        G4String command = "/control/execute ";
        G4String macro = argv[1];
        UImanager->ApplyCommand(command+macro);
    }

    G4long seed = time(nullptr);
    CLHEP::HepRandom::setTheSeed(seed);
    G4cout << "Random seed set to: " << seed << G4endl;

    ui->SessionStart();
    return 0;
}