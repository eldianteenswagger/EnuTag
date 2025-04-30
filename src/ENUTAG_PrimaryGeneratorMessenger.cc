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

    //SetNewValue(test,test->GetParameter("testBool"));
    //G4cout <<"TESTING STUFF: " << test->GetParameter(0) << G4endl;
}

ENUTAG_PrimaryGeneratorMessenger::~ENUTAG_PrimaryGeneratorMessenger() = default;

void ENUTAG_PrimaryGeneratorMessenger::SetNewValue(G4UIcommand* command,G4String newValue){
    if(command==testCmd){
        G4bool boolean = testCmd->GetNewBoolValue(newValue);
        G4cout << "TEST MODE ENABLED: " << newValue << G4endl;
        action->TestMode(boolean);
        
    }
}

// void ENUTAG_PrimaryGeneratorMessenger::SetNewValue(G4UIcommand* command, G4String string){
//     if(command==test){
//         G4cout << "TEST MODE ENABLED: " << string << G4endl;
//         action->TestMode(test->GetNewBoolValue(string));
//     }
// }