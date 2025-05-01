#ifndef ENUTAG_PRIMARYGENERATORMESSENGER_HH
#define ENUTAG_PRIMARYGENERATORMESSENGER_HH

#include "G4UIdirectory.hh"
#include "G4UImessenger.hh"
#include "ENUTAG_PrimaryGenerator.hh"
#include "G4UIcmdWithABool.hh"
#include <G4String.hh>

class G4UIdirectory;
class G4UIcmdWithABool;

class ENUTAG_PrimaryGeneratorMessenger : public G4UImessenger{
public:
    ENUTAG_PrimaryGeneratorMessenger(ENUTAG_PrimaryGenerator*);
    virtual ~ENUTAG_PrimaryGeneratorMessenger();

    void SetNewValue(G4UIcommand*,G4String);

private:
    ENUTAG_PrimaryGenerator* action;
    G4UIcmdWithABool* testCmd;
    G4UIdirectory* ENUTAG_dir;
};

#endif