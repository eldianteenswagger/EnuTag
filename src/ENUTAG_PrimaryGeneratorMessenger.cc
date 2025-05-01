#include "ENUTAG_PrimaryGeneratorMessenger.hh"
#include "ENUTAG_PrimaryGenerator.hh"

ENUTAG_PrimaryGeneratorMessenger::ENUTAG_PrimaryGeneratorMessenger(ENUTAG_PrimaryGenerator* gun) : action(gun){
    ENUTAG_dir = new G4UIdirectory("/ENUTAG/");
    ENUTAG_dir->SetGuidance("Custom commands for ENUTAG.");
    testCmd = new G4UIcmdWithABool("/ENUTAG/testMode", this);
    testCmd->SetGuidance("Set particle gun in pion mode for testing.");
    testCmd->SetGuidance("Default value is FALSE.");
    testCmd->SetParameterName("testBool", false);
    testCmd->SetDefaultValue(false);
}

ENUTAG_PrimaryGeneratorMessenger::~ENUTAG_PrimaryGeneratorMessenger() = default;

void ENUTAG_PrimaryGeneratorMessenger::SetNewValue(G4UIcommand* command,G4String newValue){
    if(command==testCmd){
        G4bool boolean = testCmd->GetNewBoolValue(newValue);
        G4cout << "/ENUTAG/testMode, TEST MODE ENABLED: " << newValue << G4endl;
        action->TestMode(boolean);
    }
}