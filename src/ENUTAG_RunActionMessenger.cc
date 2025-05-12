#include "ENUTAG_RunActionMessenger.hh"
#include "ENUTAG_RunAction.hh"

ENUTAG_RunActionMessenger::ENUTAG_RunActionMessenger(ENUTAG_RunAction* run) : action(run){
    ENUTAG_dir = new G4UIdirectory("/ENUTAG/");
    ENUTAG_dir->SetGuidance("Custom commands for ENUTAG.");
    fileCmd = new G4UIcmdWithAString("/ENUTAG/outName", this);
    fileCmd->SetGuidance("Set output file name.");
    fileCmd->SetGuidance("Default value is 'out.root'.");
    fileCmd->SetParameterName("outName", false);
    fileCmd->SetDefaultValue("out.root");
}

ENUTAG_RunActionMessenger::~ENUTAG_RunActionMessenger() = default;

void ENUTAG_RunActionMessenger::SetNewValue(G4UIcommand* command,G4String newValue){
    if(command==fileCmd){
        G4cout << "/ENUTAG/outName called, NEW FILE NAME: " << newValue << G4endl;
        action->DefineFileName(newValue);
    }
}