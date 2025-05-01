#ifndef ENUTAG_RUNACTIONMESSENGER_HH
#define ENUTAG_RUNACTIONMESSENGER_HH

#include "G4UIdirectory.hh"
#include "G4UImessenger.hh"
#include "ENUTAG_RunAction.hh"
#include "G4UIcmdWithAString.hh"
#include <G4String.hh>

class G4UIdirectory;
class G4UIcmdWithABool;

class ENUTAG_RunActionMessenger : public G4UImessenger{
public:
    ENUTAG_RunActionMessenger(ENUTAG_RunAction*);
    virtual ~ENUTAG_RunActionMessenger();

    void SetNewValue(G4UIcommand*,G4String);

private:
    ENUTAG_RunAction* action;
    G4UIcmdWithAString* fileCmd;
    G4UIdirectory* ENUTAG_dir;
};

#endif